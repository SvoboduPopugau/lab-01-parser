# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /home/vladislav/clion-2020.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/vladislav/clion-2020.2.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vladislav/CLionProjects/lab-01-parser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vladislav/CLionProjects/lab-01-parser/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab-01-parser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab-01-parser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab-01-parser.dir/flags.make

CMakeFiles/lab-01-parser.dir/sources/source.cpp.o: CMakeFiles/lab-01-parser.dir/flags.make
CMakeFiles/lab-01-parser.dir/sources/source.cpp.o: ../sources/source.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vladislav/CLionProjects/lab-01-parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab-01-parser.dir/sources/source.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab-01-parser.dir/sources/source.cpp.o -c /home/vladislav/CLionProjects/lab-01-parser/sources/source.cpp

CMakeFiles/lab-01-parser.dir/sources/source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab-01-parser.dir/sources/source.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vladislav/CLionProjects/lab-01-parser/sources/source.cpp > CMakeFiles/lab-01-parser.dir/sources/source.cpp.i

CMakeFiles/lab-01-parser.dir/sources/source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab-01-parser.dir/sources/source.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vladislav/CLionProjects/lab-01-parser/sources/source.cpp -o CMakeFiles/lab-01-parser.dir/sources/source.cpp.s

CMakeFiles/lab-01-parser.dir/sources/main.cpp.o: CMakeFiles/lab-01-parser.dir/flags.make
CMakeFiles/lab-01-parser.dir/sources/main.cpp.o: ../sources/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vladislav/CLionProjects/lab-01-parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab-01-parser.dir/sources/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab-01-parser.dir/sources/main.cpp.o -c /home/vladislav/CLionProjects/lab-01-parser/sources/main.cpp

CMakeFiles/lab-01-parser.dir/sources/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab-01-parser.dir/sources/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vladislav/CLionProjects/lab-01-parser/sources/main.cpp > CMakeFiles/lab-01-parser.dir/sources/main.cpp.i

CMakeFiles/lab-01-parser.dir/sources/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab-01-parser.dir/sources/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vladislav/CLionProjects/lab-01-parser/sources/main.cpp -o CMakeFiles/lab-01-parser.dir/sources/main.cpp.s

# Object files for target lab-01-parser
lab__01__parser_OBJECTS = \
"CMakeFiles/lab-01-parser.dir/sources/source.cpp.o" \
"CMakeFiles/lab-01-parser.dir/sources/main.cpp.o"

# External object files for target lab-01-parser
lab__01__parser_EXTERNAL_OBJECTS =

liblab-01-parserd.a: CMakeFiles/lab-01-parser.dir/sources/source.cpp.o
liblab-01-parserd.a: CMakeFiles/lab-01-parser.dir/sources/main.cpp.o
liblab-01-parserd.a: CMakeFiles/lab-01-parser.dir/build.make
liblab-01-parserd.a: CMakeFiles/lab-01-parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vladislav/CLionProjects/lab-01-parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library liblab-01-parserd.a"
	$(CMAKE_COMMAND) -P CMakeFiles/lab-01-parser.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab-01-parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab-01-parser.dir/build: liblab-01-parserd.a

.PHONY : CMakeFiles/lab-01-parser.dir/build

CMakeFiles/lab-01-parser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab-01-parser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab-01-parser.dir/clean

CMakeFiles/lab-01-parser.dir/depend:
	cd /home/vladislav/CLionProjects/lab-01-parser/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vladislav/CLionProjects/lab-01-parser /home/vladislav/CLionProjects/lab-01-parser /home/vladislav/CLionProjects/lab-01-parser/cmake-build-debug /home/vladislav/CLionProjects/lab-01-parser/cmake-build-debug /home/vladislav/CLionProjects/lab-01-parser/cmake-build-debug/CMakeFiles/lab-01-parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab-01-parser.dir/depend
