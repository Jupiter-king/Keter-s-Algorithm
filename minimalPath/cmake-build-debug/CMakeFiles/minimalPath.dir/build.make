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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/keter/Documents/arithmeticCodes/minimalPath

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/keter/Documents/arithmeticCodes/minimalPath/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/minimalPath.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/minimalPath.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minimalPath.dir/flags.make

CMakeFiles/minimalPath.dir/main.c.o: CMakeFiles/minimalPath.dir/flags.make
CMakeFiles/minimalPath.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/keter/Documents/arithmeticCodes/minimalPath/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/minimalPath.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minimalPath.dir/main.c.o   -c /Users/keter/Documents/arithmeticCodes/minimalPath/main.c

CMakeFiles/minimalPath.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minimalPath.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/keter/Documents/arithmeticCodes/minimalPath/main.c > CMakeFiles/minimalPath.dir/main.c.i

CMakeFiles/minimalPath.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minimalPath.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/keter/Documents/arithmeticCodes/minimalPath/main.c -o CMakeFiles/minimalPath.dir/main.c.s

# Object files for target minimalPath
minimalPath_OBJECTS = \
"CMakeFiles/minimalPath.dir/main.c.o"

# External object files for target minimalPath
minimalPath_EXTERNAL_OBJECTS =

minimalPath: CMakeFiles/minimalPath.dir/main.c.o
minimalPath: CMakeFiles/minimalPath.dir/build.make
minimalPath: CMakeFiles/minimalPath.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/keter/Documents/arithmeticCodes/minimalPath/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable minimalPath"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minimalPath.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minimalPath.dir/build: minimalPath

.PHONY : CMakeFiles/minimalPath.dir/build

CMakeFiles/minimalPath.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/minimalPath.dir/cmake_clean.cmake
.PHONY : CMakeFiles/minimalPath.dir/clean

CMakeFiles/minimalPath.dir/depend:
	cd /Users/keter/Documents/arithmeticCodes/minimalPath/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/keter/Documents/arithmeticCodes/minimalPath /Users/keter/Documents/arithmeticCodes/minimalPath /Users/keter/Documents/arithmeticCodes/minimalPath/cmake-build-debug /Users/keter/Documents/arithmeticCodes/minimalPath/cmake-build-debug /Users/keter/Documents/arithmeticCodes/minimalPath/cmake-build-debug/CMakeFiles/minimalPath.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/minimalPath.dir/depend
