# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02/build"

# Include any dependencies generated for this target.
include CMakeFiles/mini_project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mini_project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mini_project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mini_project.dir/flags.make

CMakeFiles/mini_project.dir/codegen:
.PHONY : CMakeFiles/mini_project.dir/codegen

CMakeFiles/mini_project.dir/src/main.cpp.o: CMakeFiles/mini_project.dir/flags.make
CMakeFiles/mini_project.dir/src/main.cpp.o: /Users/spartan/Downloads/275\ minis/mini\ 1/test-mini/phase-02/src/main.cpp
CMakeFiles/mini_project.dir/src/main.cpp.o: CMakeFiles/mini_project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mini_project.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mini_project.dir/src/main.cpp.o -MF CMakeFiles/mini_project.dir/src/main.cpp.o.d -o CMakeFiles/mini_project.dir/src/main.cpp.o -c "/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02/src/main.cpp"

CMakeFiles/mini_project.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mini_project.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02/src/main.cpp" > CMakeFiles/mini_project.dir/src/main.cpp.i

CMakeFiles/mini_project.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mini_project.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02/src/main.cpp" -o CMakeFiles/mini_project.dir/src/main.cpp.s

CMakeFiles/mini_project.dir/src/DataParser.cpp.o: CMakeFiles/mini_project.dir/flags.make
CMakeFiles/mini_project.dir/src/DataParser.cpp.o: /Users/spartan/Downloads/275\ minis/mini\ 1/test-mini/phase-02/src/DataParser.cpp
CMakeFiles/mini_project.dir/src/DataParser.cpp.o: CMakeFiles/mini_project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mini_project.dir/src/DataParser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mini_project.dir/src/DataParser.cpp.o -MF CMakeFiles/mini_project.dir/src/DataParser.cpp.o.d -o CMakeFiles/mini_project.dir/src/DataParser.cpp.o -c "/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02/src/DataParser.cpp"

CMakeFiles/mini_project.dir/src/DataParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mini_project.dir/src/DataParser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02/src/DataParser.cpp" > CMakeFiles/mini_project.dir/src/DataParser.cpp.i

CMakeFiles/mini_project.dir/src/DataParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mini_project.dir/src/DataParser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02/src/DataParser.cpp" -o CMakeFiles/mini_project.dir/src/DataParser.cpp.s

CMakeFiles/mini_project.dir/src/CollisionRecord.cpp.o: CMakeFiles/mini_project.dir/flags.make
CMakeFiles/mini_project.dir/src/CollisionRecord.cpp.o: /Users/spartan/Downloads/275\ minis/mini\ 1/test-mini/phase-02/src/CollisionRecord.cpp
CMakeFiles/mini_project.dir/src/CollisionRecord.cpp.o: CMakeFiles/mini_project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mini_project.dir/src/CollisionRecord.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mini_project.dir/src/CollisionRecord.cpp.o -MF CMakeFiles/mini_project.dir/src/CollisionRecord.cpp.o.d -o CMakeFiles/mini_project.dir/src/CollisionRecord.cpp.o -c "/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02/src/CollisionRecord.cpp"

CMakeFiles/mini_project.dir/src/CollisionRecord.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mini_project.dir/src/CollisionRecord.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02/src/CollisionRecord.cpp" > CMakeFiles/mini_project.dir/src/CollisionRecord.cpp.i

CMakeFiles/mini_project.dir/src/CollisionRecord.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mini_project.dir/src/CollisionRecord.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02/src/CollisionRecord.cpp" -o CMakeFiles/mini_project.dir/src/CollisionRecord.cpp.s

# Object files for target mini_project
mini_project_OBJECTS = \
"CMakeFiles/mini_project.dir/src/main.cpp.o" \
"CMakeFiles/mini_project.dir/src/DataParser.cpp.o" \
"CMakeFiles/mini_project.dir/src/CollisionRecord.cpp.o"

# External object files for target mini_project
mini_project_EXTERNAL_OBJECTS =

mini_project: CMakeFiles/mini_project.dir/src/main.cpp.o
mini_project: CMakeFiles/mini_project.dir/src/DataParser.cpp.o
mini_project: CMakeFiles/mini_project.dir/src/CollisionRecord.cpp.o
mini_project: CMakeFiles/mini_project.dir/build.make
mini_project: /opt/homebrew/opt/libomp/lib/libomp.dylib
mini_project: CMakeFiles/mini_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable mini_project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mini_project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mini_project.dir/build: mini_project
.PHONY : CMakeFiles/mini_project.dir/build

CMakeFiles/mini_project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mini_project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mini_project.dir/clean

CMakeFiles/mini_project.dir/depend:
	cd "/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02" "/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02" "/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02/build" "/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02/build" "/Users/spartan/Downloads/275 minis/mini 1/test-mini/phase-02/build/CMakeFiles/mini_project.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/mini_project.dir/depend

