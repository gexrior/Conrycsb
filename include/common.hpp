#ifndef COMMON_HEADER
#define COMMON_HEADER
#include <stdint.h>
#include <time.h>

typedef int nrfs;
typedef char* nrfsFile;

#define MAX_MESSAGE_BLOCK_COUNT 10      /* Max count of block index in a message. */
#define SCAN_LENGTH 163

typedef struct 
{
	uint16_t node_id;
	uint64_t offset;
	uint64_t size;
} file_pos_tuple;

struct file_pos_info
{
	uint32_t len;
	file_pos_tuple tuple[MAX_MESSAGE_BLOCK_COUNT];
};

/* getattr */
struct nrfsfileattr
{
	uint32_t mode;	/* 0 - file, 1 - directory */
	uint64_t size;
	uint32_t time;
};



/** Definitions. **/
#define MAX_PATH_LENGTH 255             /* Max length of path. */
//add by dhc :s
#define KEY_LENGTH 64             /* Length of key. */
#define DEFAULTMALLOCSIZE  10     /* Default size of malloc. */
#define MAX_ADDR_LENGTH 10      /* Max length of addr. */
#define MAX_RANGE_LENGTH 10      /* Max length of range. */
#define ERROR 1
#define SUCCESS 0
#define INSUFFICIENT_SPACE 2
#define DISCONTINUOUS_RANGE 3
//add by dhc:e
// add by weixing [20190325]:b
#define MAX_ADDR_NUM 64
// add e

// add by weixing [20190330]:b
#define GET_BIT0(x) ((x&0x01)==0x01?1:0)
#define GET_BIT1(x) ((x&0x02)==0x02?1:0)
#define GET_BIT2(x) ((x&0x04)==0x04?1:0)
#define GET_BIT3(x) ((x&0x08)==0x08?1:0)
#define GET_BIT4(x) ((x&0x10)==0x10?1:0)
#define GET_BIT5(x) ((x&0x20)==0x20?1:0)
#define GET_BIT6(x) ((x&0x40)==0x40?1:0)
#define GET_BIT7(x) ((x&0x80)==0x80?1:0)
// add e

/** Definitions. **/
#define MAX_FILE_EXTENT_COUNT 20        /* Max extent count in meta of a file. */
//#define BLOCK_SIZE (1 * 1024 * 1024)  /* Current block size in bytes. */
#define BLOCK_SIZE (32 * 1024)
#define MAX_FILE_NAME_LENGTH 50         /* Max file name length. */
#define MAX_DIRECTORY_COUNT 60          /* Max directory count. */
#define BLOCK_ROW_NUM BLOCK_SIZE/100

#define THREAD_CNT					4
#define PART_CNT					1
// each transaction only accesses 1 virtual partition. But the lock/ts manager and index are not aware of such partitioning. VIRTUAL_PART_CNT describes the request distribution and is only used to generate queries. For HSTORE, VIRTUAL_PART_CNT should be the same as PART_CNT.
#define VIRTUAL_PART_CNT			1
#define PAGE_SIZE					4096
#define CL_SIZE						64
// CPU_FREQ is used to get accurate timing info
#define CPU_FREQ 					2 	// in GHz/s

// # of transactions to run for warmup
#define WARMUP						0
// YCSB or TPCC
#define WORKLOAD 					YCSB
// print the transaction latency distribution
#define PRT_LAT_DISTR				false
#define STATS_ENABLE				true
#define TIME_ENABLE					true

#define MEM_ALLIGN					8

// [THREAD_ALLOC]
#define THREAD_ALLOC				false
#define THREAD_ARENA_SIZE			(1UL << 22)
#define MEM_PAD 					true

// [PART_ALLOC]
#define PART_ALLOC 					false
#define MEM_SIZE					(1UL << 30)
#define NO_FREE						false

/***********************************************/
// Concurrency Control
/***********************************************/
// WAIT_DIE, NO_WAIT, DL_DETECT, TIMESTAMP, MVCC, HEKATON, HSTORE, OCC, VLL, TICTOC, SILO
// TODO TIMESTAMP does not work at this moment
#define CC_ALG 						TICTOC
#define ISOLATION_LEVEL 			SERIALIZABLE

// all transactions acquire tuples according to the primary key order.
#define KEY_ORDER					false
// transaction roll back changes after abort
#define ROLL_BACK					true
// per-row lock/ts management or central lock/ts management
#define CENTRAL_MAN					false
#define BUCKET_CNT					31
#define ABORT_PENALTY 				100000
#define ABORT_BUFFER_SIZE			10
#define ABORT_BUFFER_ENABLE			true
// [ INDEX ]
#define ENABLE_LATCH				false
#define CENTRAL_INDEX				false
#define CENTRAL_MANAGER 			false
#define INDEX_STRUCT				IDX_HASH
#define BTREE_ORDER 				16

// [DL_DETECT]
#define DL_LOOP_DETECT				1000 	// 100 us
#define DL_LOOP_TRIAL				100	// 1 us
#define NO_DL						KEY_ORDER
#define TIMEOUT						1000000 // 1ms
// [TIMESTAMP]
#define TS_TWR						false
#define TS_ALLOC					TS_CAS
#define TS_BATCH_ALLOC				false
#define TS_BATCH_NUM				1
// [MVCC]
// when read/write history is longer than HIS_RECYCLE_LEN
// the history should be recycled.
//#define HIS_RECYCLE_LEN				10
//#define MAX_PRE_REQ					1024
//#define MAX_READ_REQ				1024
#define MIN_TS_INTVL				5000000 //5 ms. In nanoseconds
// [OCC]
#define MAX_WRITE_SET				10
#define PER_ROW_VALID				true
// [TICTOC]
#define WRITE_COPY_FORM				"data" // ptr or data
#define TICTOC_MV					false
#define WR_VALIDATION_SEPARATE		true
#define WRITE_PERMISSION_LOCK		false
#define ATOMIC_TIMESTAMP			"false"
// [TICTOC, SILO]
#define VALIDATION_LOCK				"no-wait" // no-wait or waiting
#define PRE_ABORT					"true"
#define ATOMIC_WORD					true
// [HSTORE]
// when set to true, hstore will not access the global timestamp.
// This is fine for single partition transactions.
#define HSTORE_LOCAL_TS				false
// [VLL]
#define TXN_QUEUE_SIZE_LIMIT		THREAD_CNT

/***********************************************/
// Logging
/***********************************************/
#define LOG_COMMAND					false
#define LOG_REDO					false
#define LOG_BATCH_TIME				10 // in ms

/***********************************************/
// Benchmark
/***********************************************/
// max number of rows touched per transaction
#define MAX_ROW_PER_TXN				64
#define QUERY_INTVL 				1UL
#define MAX_TXN_PER_PART 			100000
#define FIRST_PART_LOCAL 			true
#define MAX_TUPLE_SIZE				1024 // in bytes
// ==== [YCSB] ====
#define INIT_PARALLELISM			40
#define SYNTH_TABLE_SIZE 			(1024*1024*10.24)
#define ZIPF_THETA 					0.6
#define READ_PERC 					0.9
#define WRITE_PERC 					0.1
#define SCAN_PERC 					0
#define SCAN_LEN					20
#define PART_PER_TXN 				1
#define PERC_MULTI_PART				1
#define REQ_PER_QUERY				16
#define FIELD_PER_TUPLE				10
// ==== [TPCC] ====
// For large warehouse count, the tables do not fit in memory
// small tpcc schemas shrink the table size.
#define TPCC_SMALL					false
// Some of the transactions read the data but never use them.
// If TPCC_ACCESS_ALL == fales, then these parts of the transactions
// are not modeled.
#define TPCC_ACCESS_ALL 			false
#define WH_UPDATE					true
#define NUM_WH 						1
//
enum TPCCTxnType {TPCC_ALL,
                TPCC_PAYMENT,
                TPCC_NEW_ORDER,
                TPCC_ORDER_STATUS,
                TPCC_DELIVERY,
                TPCC_STOCK_LEVEL};
extern TPCCTxnType 					g_tpcc_txn_type;

//#define TXN_TYPE					TPCC_ALL
#define PERC_PAYMENT 				0.5
#define FIRSTNAME_MINLEN 			8
#define FIRSTNAME_LEN 				16
#define LASTNAME_LEN 				16

#define DIST_PER_WARE				10

/***********************************************/
// TODO centralized CC management.
/***********************************************/
#define MAX_LOCK_CNT				(20 * THREAD_CNT)
#define TSTAB_SIZE                  50 * THREAD_CNT
#define TSTAB_FREE                  TSTAB_SIZE
#define TSREQ_FREE                  4 * TSTAB_FREE
#define MVHIS_FREE                  4 * TSTAB_FREE
#define SPIN                        false

/***********************************************/
// Test cases
/***********************************************/
#define TEST_ALL					true
enum TestCases {
    READ_WRITE,
    CONFLICT
};
extern TestCases					g_test_case;
/***********************************************/
// DEBUG info
/***********************************************/
#define WL_VERB						true
#define IDX_VERB					false
#define VERB_ALLOC					true

#define DEBUG_LOCK					false
#define DEBUG_TIMESTAMP				false
#define DEBUG_SYNTH					false
#define DEBUG_ASSERT				false
#define DEBUG_CC					false //true

/***********************************************/
// Constant
/***********************************************/
// INDEX_STRUCT
#define IDX_HASH 					1
#define IDX_BTREE					2
// WORKLOAD
#define YCSB						1
#define TPCC						2
#define TEST						3
// Concurrency Control Algorithm
#define NO_WAIT						1
#define WAIT_DIE					2
#define DL_DETECT					3
#define TIMESTAMP					4
#define MVCC						5
#define HSTORE						6
#define OCC							7
#define TICTOC						8
#define SILO						9
#define VLL							10
#define HEKATON 					11
//Isolation Levels
#define SERIALIZABLE				1
#define SNAPSHOT					2
#define REPEATABLE_READ				3
// TIMESTAMP allocation method.
#define TS_MUTEX					1
#define TS_CAS						2
#define TS_HW						3
#define TS_CLOCK					4

/** Classes and structures. **/
typedef uint64_t NodeHash;              /* Node hash. */

// add by weixing [20190325]:b
typedef uint64_t GAddr;
typedef long Align;     /* alignment boundary */

typedef struct
{
    int num;    /* record the number of allocated blocks*/
    GAddr addr[MAX_ADDR_NUM];   /* the array of returned addresses*/
} ResponseAddrList;
// add e

// add by weixing [20190328]:b
union defHeader{
    struct info{
        char* const addrBlock_;
        uint64_t size_;
    };
    Align X; /*force the memory alignment*/
};

typedef union defHeader BlockHeader;
// add e

typedef struct 
{
	NodeHash hashNode; /* Node hash array of extent. */
    uint32_t indexExtentStartBlock; /* Index array of start block in an extent. */
    uint32_t countExtentBlock; /* Count array of blocks in an extent. */
} FileMetaTuple;

typedef struct                          /* File meta structure. */
{
    time_t timeLastModified;        /* Last modified time. */
    uint64_t count;                 /* Count of extents. (not required and might have consistency problem with size) */
    uint64_t size;                  /* Size of extents. */
    FileMetaTuple tuple[MAX_FILE_EXTENT_COUNT];
} FileMeta;

typedef struct {
    char names[MAX_FILE_NAME_LENGTH];
} DirectoryMetaTuple;

typedef struct                          /* Directory meta structure. */
{
    uint64_t count;                 /* Count of names. */
    DirectoryMetaTuple tuple[MAX_DIRECTORY_COUNT];
} DirectoryMeta;

typedef DirectoryMeta nrfsfilelist;


static inline void NanosecondSleep(struct timespec *preTime, uint64_t diff) {
	struct timespec now;
	uint64_t temp;
	temp = 0;
	while (temp < diff) {
		clock_gettime(CLOCK_MONOTONIC, &now);
		temp = (now.tv_sec - preTime->tv_sec) * 1000000000 + now.tv_nsec - preTime->tv_nsec;
		temp = temp / 1000;
	}
}

#endif
