# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/saragaya/CLionProjects/SFMLDemo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/saragaya/CLionProjects/SFMLDemo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SFMLDemo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SFMLDemo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SFMLDemo.dir/flags.make

CMakeFiles/SFMLDemo.dir/main.cpp.o: CMakeFiles/SFMLDemo.dir/flags.make
CMakeFiles/SFMLDemo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/saragaya/CLionProjects/SFMLDemo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SFMLDemo.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFMLDemo.dir/main.cpp.o -c /Users/saragaya/CLionProjects/SFMLDemo/main.cpp

CMakeFiles/SFMLDemo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLDemo.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/saragaya/CLionProjects/SFMLDemo/main.cpp > CMakeFiles/SFMLDemo.dir/main.cpp.i

CMakeFiles/SFMLDemo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLDemo.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/saragaya/CLionProjects/SFMLDemo/main.cpp -o CMakeFiles/SFMLDemo.dir/main.cpp.s

CMakeFiles/SFMLDemo.dir/Board.cpp.o: CMakeFiles/SFMLDemo.dir/flags.make
CMakeFiles/SFMLDemo.dir/Board.cpp.o: ../Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/saragaya/CLionProjects/SFMLDemo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SFMLDemo.dir/Board.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFMLDemo.dir/Board.cpp.o -c /Users/saragaya/CLionProjects/SFMLDemo/Board.cpp

CMakeFiles/SFMLDemo.dir/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLDemo.dir/Board.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/saragaya/CLionProjects/SFMLDemo/Board.cpp > CMakeFiles/SFMLDemo.dir/Board.cpp.i

CMakeFiles/SFMLDemo.dir/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLDemo.dir/Board.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/saragaya/CLionProjects/SFMLDemo/Board.cpp -o CMakeFiles/SFMLDemo.dir/Board.cpp.s

CMakeFiles/SFMLDemo.dir/Tile.cpp.o: CMakeFiles/SFMLDemo.dir/flags.make
CMakeFiles/SFMLDemo.dir/Tile.cpp.o: ../Tile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/saragaya/CLionProjects/SFMLDemo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SFMLDemo.dir/Tile.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFMLDemo.dir/Tile.cpp.o -c /Users/saragaya/CLionProjects/SFMLDemo/Tile.cpp

CMakeFiles/SFMLDemo.dir/Tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLDemo.dir/Tile.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/saragaya/CLionProjects/SFMLDemo/Tile.cpp > CMakeFiles/SFMLDemo.dir/Tile.cpp.i

CMakeFiles/SFMLDemo.dir/Tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLDemo.dir/Tile.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/saragaya/CLionProjects/SFMLDemo/Tile.cpp -o CMakeFiles/SFMLDemo.dir/Tile.cpp.s

# Object files for target SFMLDemo
SFMLDemo_OBJECTS = \
"CMakeFiles/SFMLDemo.dir/main.cpp.o" \
"CMakeFiles/SFMLDemo.dir/Board.cpp.o" \
"CMakeFiles/SFMLDemo.dir/Tile.cpp.o"

# External object files for target SFMLDemo
SFMLDemo_EXTERNAL_OBJECTS =

SFMLDemo: CMakeFiles/SFMLDemo.dir/main.cpp.o
SFMLDemo: CMakeFiles/SFMLDemo.dir/Board.cpp.o
SFMLDemo: CMakeFiles/SFMLDemo.dir/Tile.cpp.o
SFMLDemo: CMakeFiles/SFMLDemo.dir/build.make
SFMLDemo: CMakeFiles/SFMLDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/saragaya/CLionProjects/SFMLDemo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable SFMLDemo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SFMLDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SFMLDemo.dir/build: SFMLDemo

.PHONY : CMakeFiles/SFMLDemo.dir/build

CMakeFiles/SFMLDemo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SFMLDemo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SFMLDemo.dir/clean

CMakeFiles/SFMLDemo.dir/depend:
	cd /Users/saragaya/CLionProjects/SFMLDemo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/saragaya/CLionProjects/SFMLDemo /Users/saragaya/CLionProjects/SFMLDemo /Users/saragaya/CLionProjects/SFMLDemo/cmake-build-debug /Users/saragaya/CLionProjects/SFMLDemo/cmake-build-debug /Users/saragaya/CLionProjects/SFMLDemo/cmake-build-debug/CMakeFiles/SFMLDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SFMLDemo.dir/depend

