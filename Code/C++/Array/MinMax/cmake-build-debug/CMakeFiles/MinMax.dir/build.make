# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/debarshighosh/Desktop/Google_univ/google-interview-university/Code/C++/Array/MinMax

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/debarshighosh/Desktop/Google_univ/google-interview-university/Code/C++/Array/MinMax/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MinMax.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MinMax.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MinMax.dir/flags.make

CMakeFiles/MinMax.dir/main.cpp.o: CMakeFiles/MinMax.dir/flags.make
CMakeFiles/MinMax.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/debarshighosh/Desktop/Google_univ/google-interview-university/Code/C++/Array/MinMax/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MinMax.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MinMax.dir/main.cpp.o -c /Users/debarshighosh/Desktop/Google_univ/google-interview-university/Code/C++/Array/MinMax/main.cpp

CMakeFiles/MinMax.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MinMax.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/debarshighosh/Desktop/Google_univ/google-interview-university/Code/C++/Array/MinMax/main.cpp > CMakeFiles/MinMax.dir/main.cpp.i

CMakeFiles/MinMax.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MinMax.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/debarshighosh/Desktop/Google_univ/google-interview-university/Code/C++/Array/MinMax/main.cpp -o CMakeFiles/MinMax.dir/main.cpp.s

CMakeFiles/MinMax.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/MinMax.dir/main.cpp.o.requires

CMakeFiles/MinMax.dir/main.cpp.o.provides: CMakeFiles/MinMax.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MinMax.dir/build.make CMakeFiles/MinMax.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/MinMax.dir/main.cpp.o.provides

CMakeFiles/MinMax.dir/main.cpp.o.provides.build: CMakeFiles/MinMax.dir/main.cpp.o


# Object files for target MinMax
MinMax_OBJECTS = \
"CMakeFiles/MinMax.dir/main.cpp.o"

# External object files for target MinMax
MinMax_EXTERNAL_OBJECTS =

MinMax: CMakeFiles/MinMax.dir/main.cpp.o
MinMax: CMakeFiles/MinMax.dir/build.make
MinMax: CMakeFiles/MinMax.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/debarshighosh/Desktop/Google_univ/google-interview-university/Code/C++/Array/MinMax/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MinMax"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MinMax.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MinMax.dir/build: MinMax

.PHONY : CMakeFiles/MinMax.dir/build

CMakeFiles/MinMax.dir/requires: CMakeFiles/MinMax.dir/main.cpp.o.requires

.PHONY : CMakeFiles/MinMax.dir/requires

CMakeFiles/MinMax.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MinMax.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MinMax.dir/clean

CMakeFiles/MinMax.dir/depend:
	cd /Users/debarshighosh/Desktop/Google_univ/google-interview-university/Code/C++/Array/MinMax/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/debarshighosh/Desktop/Google_univ/google-interview-university/Code/C++/Array/MinMax /Users/debarshighosh/Desktop/Google_univ/google-interview-university/Code/C++/Array/MinMax /Users/debarshighosh/Desktop/Google_univ/google-interview-university/Code/C++/Array/MinMax/cmake-build-debug /Users/debarshighosh/Desktop/Google_univ/google-interview-university/Code/C++/Array/MinMax/cmake-build-debug /Users/debarshighosh/Desktop/Google_univ/google-interview-university/Code/C++/Array/MinMax/cmake-build-debug/CMakeFiles/MinMax.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MinMax.dir/depend

