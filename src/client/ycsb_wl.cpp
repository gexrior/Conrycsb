#include <sched.h>
#include "ycsb_global.h"
#include "helper.h"
#include "ycsb.h"
//#include "wl.h"
//#include "thread.h"
#include "table.h"
#include "row.h"
//#include "index_hash.h"
//#include "index_btree.h"
#include "catalog.h"
//#include "manager.h"
//#include "row_lock.h"
//#include "row_ts.h"
//#include "row_mvcc.h"
#include "mem_alloc.h"
//#include "query.h"

int ycsb_wl::next_tid;

RC ycsb_wl::init(Client* client) {
	next_tid = 0;
    string path = "./YCSB_schema.txt";
	init_schema( path );
	
//	init_table_parallel();
    init_table(client);
	return RCOK;
}

//RC ycsb_wl::init_schema(string schema_file) {
//	workload::init_schema(schema_file);
//	the_table = tables["MAIN_TABLE"];
////	the_index = indexes["MAIN_INDEX"];
//	return RCOK;
//}

RC ycsb_wl::init_schema(string schema_file) {
    assert(sizeof(uint64_t) == 8);
    assert(sizeof(double) == 8);
    string line;
    ifstream fin(schema_file);
    if(!fin)
    {
        printf("error!\n");
    }
    Catalog * schema;
    printf("test1!\n");
    while (getline(fin, line)) {
        printf("line:%s\n",line.c_str());
        if (line.compare(0, 6, "TABLE=") == 0) {
            string tname;
            tname = &line[6];
            schema = (Catalog *) _mm_malloc(sizeof(Catalog), CL_SIZE);
            getline(fin, line);
            int col_count = 0;
            // Read all fields for this table.
            vector<string> lines;
            while (line.length() > 1) {
                lines.push_back(line);
                getline(fin, line);
            }
            schema->init( tname.c_str(), lines.size() );
            for (UInt32 i = 0; i < lines.size(); i++) {
                string line = lines[i];
                size_t pos = 0;
                string token;
                int elem_num = 0;
                int size = 0;
                string type;
                string name;
                while (line.length() != 0) {
                    pos = line.find(",");
                    if (pos == string::npos)
                        pos = line.length();
                    token = line.substr(0, pos);
                    line.erase(0, pos + 1);
                    switch (elem_num) {
                    case 0: size = atoi(token.c_str()); break;
                    case 1: type = token; break;
                    case 2: name = token; break;
                    default: assert(false);
                    }
                    elem_num ++;
                }
                assert(elem_num == 3);
                schema->add_col((char *)name.c_str(), size, (char *)type.c_str());
                col_count ++;
            }
            table_t * cur_tab = (table_t *) _mm_malloc(sizeof(table_t), CL_SIZE);
            cur_tab->init(schema);
            tables[tname] = cur_tab;
            the_table = tables[tname];
            if(tables[tname]!= NULL)
            {
                printf("ok!\n");
            }
            printf("tname:%s\n",tname.c_str());
        } else if (!line.compare(0, 6, "INDEX=")) {
            string iname;
            iname = &line[6];
            getline(fin, line);

            vector<string> items;
            string token;
            size_t pos;
            while (line.length() != 0) {
                pos = line.find(",");
                if (pos == string::npos)
                    pos = line.length();
                token = line.substr(0, pos);
                items.push_back(token);
                line.erase(0, pos + 1);
            }

//			string tname(items[0]);
//			INDEX * index = (INDEX *) _mm_malloc(sizeof(INDEX), 64);
//			new(index) INDEX();
//			int part_cnt = (CENTRAL_INDEX)? 1 : g_part_cnt;
//			if (tname == "ITEM")
//				part_cnt = 1;
//#if INDEX_STRUCT == IDX_HASH
//	#if WORKLOAD == YCSB
//			index->init(part_cnt, tables[tname], g_synth_table_size * 2);
//	#elif WORKLOAD == TPCC
//			assert(tables[tname] != NULL);
//			index->init(part_cnt, tables[tname], stoi( items[1] ) * part_cnt);
//	#endif
//#else
//			index->init(part_cnt, tables[tname]);
//#endif
//			indexes[iname] = index;
        }
    }
    fin.close();
//    the_table = tables["MAIN_TABLE"];
//    if(the_table!= NULL)
//    {
//        printf("ok!\n");
//    }
    return RCOK;
}
	
//int
//ycsb_wl::key_to_part(uint64_t key) {
//	uint64_t rows_per_part = g_synth_table_size / g_part_cnt;
//	return key / rows_per_part;
//}

RC ycsb_wl::init_table(Client* client) {
	RC rc;
//    int64_t total_row = 0;
    int64_t total_row = (client->getRdmaSocketInstance()->getNodeID())*(BLOCK_SIZE*100);
    int64_t end_row = (client->getRdmaSocketInstance()->getNodeID()+1)*(BLOCK_SIZE*100);
    char alphavalue[BLOCK_SIZE];
    char* data_buffer = alphavalue;
    char start_key[KEY_LENGTH];
    char end_key[KEY_LENGTH];
    int64_t* start = (int64_t*)(start_key);
    int64_t* end = (int64_t*)(end_key);
    *start = 1;
    timeval start_time, end_time;
    int64_t total_sec=0;
    int64_t total_usec=0;
    int count = 0;
    while (true) {
    	for (UInt32 part_id = 0; part_id < g_part_cnt; part_id ++) {
//            if (total_row > g_synth_table_size)
//            if (total_row > end_row)
            if(count>10000)
                goto ins_done;
            row_t * new_row = NULL;
			uint64_t row_id;
            rc = the_table->get_new_row(new_row, part_id, row_id); 
            // TODO insertion of last row may fail after the table_size
            // is updated. So never access the last record in a table
			assert(rc == RCOK);
			uint64_t primary_key = total_row;
			new_row->set_primary_key(primary_key);
            new_row->set_value(0, &primary_key);
			Catalog * schema = the_table->get_schema();
			for (UInt32 fid = 0; fid < schema->get_field_cnt(); fid ++) {
				int field_size = schema->get_field_size(fid);
				char value[field_size];
				for (int i = 0; i < field_size; i++) 
					value[i] = (char)rand() % (1<<8) ;
				new_row->set_value(fid, value);
			}
//            itemid_t * m_item =
//                (itemid_t *) mem_allocator.alloc( sizeof(itemid_t), part_id );
//			assert(m_item != NULL);
//            m_item->type = DT_row;
//            m_item->location = new_row;
//            m_item->valid = true;
//            uint64_t idx_key = primary_key;
//            rc = the_index->index_insert(idx_key, m_item, part_id);
//            assert(rc == RCOK);
            total_row ++;

            memcpy(data_buffer,new_row->data,new_row->get_tuple_size());
            if(BLOCK_SIZE-(data_buffer + new_row->get_tuple_size()-alphavalue)> new_row->get_tuple_size())
            {
               data_buffer += new_row->get_tuple_size();
            }
            else
            {
//               printf("Read:%s!\n",alphavalue);
               *end = total_row;
//               printf("start_key:%lu,start_key:%lu",*start,*end);

               gettimeofday(&start_time,NULL);
               client->Write((uint64_t)alphavalue,BLOCK_SIZE,start_key,end_key);
               gettimeofday(&end_time,NULL);
               total_sec += end_time.tv_sec-start_time.tv_sec;
               total_usec += end_time.tv_usec-start_time.tv_usec;


               data_buffer = alphavalue;
               *start = total_row+1;
               count++;
            }

            //printf("Read:%s, tuple_size:%lu, block_row_num:%lu\n",new_row->data,new_row->get_tuple_size(),BLOCK_ROW_NUM);
        }
    }

ins_done:
    cout<<total_sec<<"s,"<<total_usec<<"us"<<endl;
    cout<<"count:"<<count<<endl;
    printf("[YCSB] Table \"MAIN_TABLE\" initialized.\n");
    return RCOK;

}

// init table in parallel
//void ycsb_wl::init_table_parallel() {
//	enable_thread_mem_pool = true;
//	pthread_t p_thds[g_init_parallelism - 1];
//	for (UInt32 i = 0; i < g_init_parallelism - 1; i++)
//		pthread_create(&p_thds[i], NULL, threadInitTable, this);
//	threadInitTable(this);

//	for (uint32_t i = 0; i < g_init_parallelism - 1; i++) {
//		int rc = pthread_join(p_thds[i], NULL);
//		if (rc) {
//			printf("ERROR; return code from pthread_join() is %d\n", rc);
//			exit(-1);
//		}
//	}
//	enable_thread_mem_pool = false;
//	mem_allocator.unregister();
//}

//void * ycsb_wl::init_table_slice() {
//	UInt32 tid = ATOM_FETCH_ADD(next_tid, 1);
//	// set cpu affinity
//	set_affinity(tid);

//	mem_allocator.register_thread(tid);
//	RC rc;
//	assert(g_synth_table_size % g_init_parallelism == 0);
//	assert(tid < g_init_parallelism);
//	while ((UInt32)ATOM_FETCH_ADD(next_tid, 0) < g_init_parallelism) {}
//	assert((UInt32)ATOM_FETCH_ADD(next_tid, 0) == g_init_parallelism);
//	uint64_t slice_size = g_synth_table_size / g_init_parallelism;
//	for (uint64_t key = slice_size * tid;
//			key < slice_size * (tid + 1);
//			key ++
//	) {
//		row_t * new_row = NULL;
//		uint64_t row_id;
//		int part_id = key_to_part(key);
//		rc = the_table->get_new_row(new_row, part_id, row_id);
//		assert(rc == RCOK);
//		uint64_t primary_key = key;
//		new_row->set_primary_key(primary_key);
//		new_row->set_value(0, &primary_key);
//		Catalog * schema = the_table->get_schema();
		
//		for (UInt32 fid = 0; fid < schema->get_field_cnt(); fid ++) {
//			char value[6] = "hello";
//			new_row->set_value(fid, value);
//		}

//		itemid_t * m_item =
//			(itemid_t *) mem_allocator.alloc( sizeof(itemid_t), part_id );
//		assert(m_item != NULL);
//		m_item->type = DT_row;
//		m_item->location = new_row;
//		m_item->valid = true;
//		uint64_t idx_key = primary_key;
		
//		rc = the_index->index_insert(idx_key, m_item, part_id);
//		assert(rc == RCOK);
//	}
//	return NULL;
//}

//RC ycsb_wl::get_txn_man(txn_man *& txn_manager, thread_t * h_thd){
//	txn_manager = (ycsb_txn_man *)
//		_mm_malloc( sizeof(ycsb_txn_man), 64 );
//	new(txn_manager) ycsb_txn_man();
//	txn_manager->init(h_thd, this, h_thd->get_thd_id());
//	return RCOK;
//}


