# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/huangcc/cmake/bin/cmake

# The command to remove a file.
RM = /home/huangcc/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/huangcc/huangcc/RDMA-Unified-Shared-Memory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/huangcc/huangcc/RDMA-Unified-Shared-Memory

# Include any dependencies generated for this target.
include CMakeFiles/benchmark.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/benchmark.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/benchmark.dir/flags.make

CMakeFiles/benchmark.dir/src/benchmark/catalog.cpp.o: CMakeFiles/benchmark.dir/flags.make
CMakeFiles/benchmark.dir/src/benchmark/catalog.cpp.o: src/benchmark/catalog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huangcc/huangcc/RDMA-Unified-Shared-Memory/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/benchmark.dir/src/benchmark/catalog.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/benchmark.dir/src/benchmark/catalog.cpp.o -c /home/huangcc/huangcc/RDMA-Unified-Shared-Memory/src/benchmark/catalog.cpp

CMakeFiles/benchmark.dir/src/benchmark/catalog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/benchmark.dir/src/benchmark/catalog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huangcc/huangcc/RDMA-Unified-Shared-Memory/src/benchmark/catalog.cpp > CMakeFiles/benchmark.dir/src/benchmark/catalog.cpp.i

CMakeFiles/benchmark.dir/src/benchmark/catalog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/benchmark.dir/src/benchmark/catalog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huangcc/huangcc/RDMA-Unified-Shared-Memory/src/benchmark/catalog.cpp -o CMakeFiles/benchmark.dir/src/benchmark/catalog.cpp.s

CMakeFiles/benchmark.dir/src/benchmark/helper.cpp.o: CMakeFiles/benchmark.dir/flags.make
CMakeFiles/benchmark.dir/src/benchmark/helper.cpp.o: src/benchmark/helper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huangcc/huangcc/RDMA-Unified-Shared-Memory/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/benchmark.dir/src/benchmark/helper.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/benchmark.dir/src/benchmark/helper.cpp.o -c /home/huangcc/huangcc/RDMA-Unified-Shared-Memory/src/benchmark/helper.cpp

CMakeFiles/benchmark.dir/src/benchmark/helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/benchmark.dir/src/benchmark/helper.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huangcc/huangcc/RDMA-Unified-Shared-Memory/src/benchmark/helper.cpp > CMakeFiles/benchmark.dir/src/benchmark/helper.cpp.i

CMakeFiles/benchmark.dir/src/benchmark/helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/benchmark.dir/src/benchmark/helper.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huangcc/huangcc/RDMA-Unified-Shared-Memory/src/benchmark/helper.cpp -o CMakeFiles/benchmark.dir/src/benchmark/helper.cpp.s

CMakeFiles/benchmark.dir/src/benchmark/row.cpp.o: CMakeFiles/benchmark.dir/flags.make
CMakeFiles/benchmark.dir/src/benchmark/row.cpp.o: src/benchmark/row.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huangcc/huangcc/RDMA-Unified-Shared-Memory/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/benchmark.dir/src/benchmark/row.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/benchmark.dir/src/benchmark/row.cpp.o -c /home/huangcc/huangcc/RDMA-Unified-Shared-Memory/src/benchmark/row.cpp

CMakeFiles/benchmark.dir/src/benchmark/row.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/benchmark.dir/src/benchmark/row.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huangcc/huangcc/RDMA-Unified-Shared-Memory/src/benchmark/row.cpp > CMakeFiles/benchmark.dir/src/benchmark/row.cpp.i

CMakeFiles/benchmark.dir/src/benchmark/row.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/benchmark.dir/src/benchmark/row.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huangcc/huangcc/RDMA-Unified-Shared-Memory/src/benchmark/row.cpp -o CMakeFiles/benchmark.dir/src/benchmark/row.cpp.s

CMakeFiles/benchmark.dir/src/benchmark/table.cpp.o: CMakeFiles/benchmark.dir/flags.make
CMakeFiles/benchmark.dir/src/benchmark/table.cpp.o: src/benchmark/table.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huangcc/huangcc/RDMA-Unified-Shared-Memory/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/benchmark.dir/src/benchmark/table.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/benchmark.dir/src/benchmark/table.cpp.o -c /home/huangcc/huangcc/RDMA-Unified-Shared-Memory/src/benchmark/table.cpp

CMakeFiles/benchmark.dir/src/benchmark/table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/benchmark.dir/src/benchmark/table.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huangcc/huangcc/RDMA-Unified-Shared-Memory/src/benchmark/table.cpp > CMakeFiles/benchmark.dir/src/benchmark/table.cpp.i

CMakeFiles/benchmark.dir/src/benchmark/table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/benchmark.dir/src/benchmark/table.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huangcc/huangcc/RDMA-Unified-Shared-Memory/src/benchmark/table.cpp -o CMakeFiles/benchmark.dir/src/benchmark/table.cpp.s

CMakeFiles/benchmark.dir/src/benchmark/ycsb_global.cpp.o: CMakeFiles/benchmark.dir/flags.make
CMakeFiles/benchmark.dir/src/benchmark/ycsb_global.cpp.o: src/benchmark/ycsb_global.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huangcc/huangcc/RDMA-Unified-Shared-Memory/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/benchmark.dir/src/benchmark/ycsb_global.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/benchmark.dir/src/benchmark/ycsb_global.cpp.o -c /home/huangcc/huangcc/RDMA-Unified-Shared-Memory/src/benchmark/ycsb_global.cpp

CMakeFiles/benchmark.dir/src/benchmark/ycsb_global.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/benchmark.dir/src/benchmark/ycsb_global.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huangcc/huangcc/RDMA-Unified-Shared-Memory/src/benchmark/ycsb_global.cpp > CMakeFiles/benchmark.dir/src/benchmark/ycsb_global.cpp.i

CMakeFiles/benchmark.dir/src/benchmark/ycsb_global.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/benchmark.dir/src/benchmark/ycsb_global.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huangcc/huangcc/RDMA-Unified-Shared-Memory/src/benchmark/ycsb_global.cpp -o CMakeFiles/benchmark.dir/src/benchmark/ycsb_global.cpp.s

# Object files for target benchmark
benchmark_OBJECTS = \
"CMakeFiles/benchmark.dir/src/benchmark/catalog.cpp.o" \
"CMakeFiles/benchmark.dir/src/benchmark/helper.cpp.o" \
"CMakeFiles/benchmark.dir/src/benchmark/row.cpp.o" \
"CMakeFiles/benchmark.dir/src/benchmark/table.cpp.o" \
"CMakeFiles/benchmark.dir/src/benchmark/ycsb_global.cpp.o"

# External object files for target benchmark
benchmark_EXTERNAL_OBJECTS =

libbenchmark.so: CMakeFiles/benchmark.dir/src/benchmark/catalog.cpp.o
libbenchmark.so: CMakeFiles/benchmark.dir/src/benchmark/helper.cpp.o
libbenchmark.so: CMakeFiles/benchmark.dir/src/benchmark/row.cpp.o
libbenchmark.so: CMakeFiles/benchmark.dir/src/benchmark/table.cpp.o
libbenchmark.so: CMakeFiles/benchmark.dir/src/benchmark/ycsb_global.cpp.o
libbenchmark.so: CMakeFiles/benchmark.dir/build.make
libbenchmark.so: libnet.so
libbenchmark.so: CMakeFiles/benchmark.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/huangcc/huangcc/RDMA-Unified-Shared-Memory/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library libbenchmark.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/benchmark.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/benchmark.dir/build: libbenchmark.so

.PHONY : CMakeFiles/benchmark.dir/build

CMakeFiles/benchmark.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/benchmark.dir/cmake_clean.cmake
.PHONY : CMakeFiles/benchmark.dir/clean

CMakeFiles/benchmark.dir/depend:
	cd /home/huangcc/huangcc/RDMA-Unified-Shared-Memory && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangcc/huangcc/RDMA-Unified-Shared-Memory /home/huangcc/huangcc/RDMA-Unified-Shared-Memory /home/huangcc/huangcc/RDMA-Unified-Shared-Memory /home/huangcc/huangcc/RDMA-Unified-Shared-Memory /home/huangcc/huangcc/RDMA-Unified-Shared-Memory/CMakeFiles/benchmark.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/benchmark.dir/depend

