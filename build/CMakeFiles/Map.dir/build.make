# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wm/Programs/Battleship

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wm/Programs/Battleship/build

# Include any dependencies generated for this target.
include CMakeFiles/Map.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Map.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Map.dir/flags.make

CMakeFiles/Map.dir/src/Map.cpp.o: CMakeFiles/Map.dir/flags.make
CMakeFiles/Map.dir/src/Map.cpp.o: ../src/Map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wm/Programs/Battleship/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Map.dir/src/Map.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Map.dir/src/Map.cpp.o -c /home/wm/Programs/Battleship/src/Map.cpp

CMakeFiles/Map.dir/src/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Map.dir/src/Map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wm/Programs/Battleship/src/Map.cpp > CMakeFiles/Map.dir/src/Map.cpp.i

CMakeFiles/Map.dir/src/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Map.dir/src/Map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wm/Programs/Battleship/src/Map.cpp -o CMakeFiles/Map.dir/src/Map.cpp.s

# Object files for target Map
Map_OBJECTS = \
"CMakeFiles/Map.dir/src/Map.cpp.o"

# External object files for target Map
Map_EXTERNAL_OBJECTS =

libMap.a: CMakeFiles/Map.dir/src/Map.cpp.o
libMap.a: CMakeFiles/Map.dir/build.make
libMap.a: CMakeFiles/Map.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wm/Programs/Battleship/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libMap.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Map.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Map.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Map.dir/build: libMap.a

.PHONY : CMakeFiles/Map.dir/build

CMakeFiles/Map.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Map.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Map.dir/clean

CMakeFiles/Map.dir/depend:
	cd /home/wm/Programs/Battleship/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wm/Programs/Battleship /home/wm/Programs/Battleship /home/wm/Programs/Battleship/build /home/wm/Programs/Battleship/build /home/wm/Programs/Battleship/build/CMakeFiles/Map.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Map.dir/depend

