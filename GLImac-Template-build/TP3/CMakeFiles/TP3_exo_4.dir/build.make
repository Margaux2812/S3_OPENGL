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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/margaux/Documents/S3_OPENGL/GLImac-Template

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/margaux/Documents/S3_OPENGL/GLImac-Template-build

# Include any dependencies generated for this target.
include TP3/CMakeFiles/TP3_exo_4.dir/depend.make

# Include the progress variables for this target.
include TP3/CMakeFiles/TP3_exo_4.dir/progress.make

# Include the compile flags for this target's objects.
include TP3/CMakeFiles/TP3_exo_4.dir/flags.make

TP3/CMakeFiles/TP3_exo_4.dir/exo_4.cpp.o: TP3/CMakeFiles/TP3_exo_4.dir/flags.make
TP3/CMakeFiles/TP3_exo_4.dir/exo_4.cpp.o: /home/margaux/Documents/S3_OPENGL/GLImac-Template/TP3/exo_4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/margaux/Documents/S3_OPENGL/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TP3/CMakeFiles/TP3_exo_4.dir/exo_4.cpp.o"
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP3 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP3_exo_4.dir/exo_4.cpp.o -c /home/margaux/Documents/S3_OPENGL/GLImac-Template/TP3/exo_4.cpp

TP3/CMakeFiles/TP3_exo_4.dir/exo_4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP3_exo_4.dir/exo_4.cpp.i"
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/margaux/Documents/S3_OPENGL/GLImac-Template/TP3/exo_4.cpp > CMakeFiles/TP3_exo_4.dir/exo_4.cpp.i

TP3/CMakeFiles/TP3_exo_4.dir/exo_4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP3_exo_4.dir/exo_4.cpp.s"
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/margaux/Documents/S3_OPENGL/GLImac-Template/TP3/exo_4.cpp -o CMakeFiles/TP3_exo_4.dir/exo_4.cpp.s

# Object files for target TP3_exo_4
TP3_exo_4_OBJECTS = \
"CMakeFiles/TP3_exo_4.dir/exo_4.cpp.o"

# External object files for target TP3_exo_4
TP3_exo_4_EXTERNAL_OBJECTS =

TP3/TP3_exo_4: TP3/CMakeFiles/TP3_exo_4.dir/exo_4.cpp.o
TP3/TP3_exo_4: TP3/CMakeFiles/TP3_exo_4.dir/build.make
TP3/TP3_exo_4: glimac/libglimac.a
TP3/TP3_exo_4: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TP3/TP3_exo_4: /usr/lib/x86_64-linux-gnu/libSDL.so
TP3/TP3_exo_4: /usr/lib/x86_64-linux-gnu/libGL.so.1
TP3/TP3_exo_4: /usr/lib/x86_64-linux-gnu/libGLEW.so
TP3/TP3_exo_4: TP3/CMakeFiles/TP3_exo_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/margaux/Documents/S3_OPENGL/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP3_exo_4"
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP3 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP3_exo_4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TP3/CMakeFiles/TP3_exo_4.dir/build: TP3/TP3_exo_4

.PHONY : TP3/CMakeFiles/TP3_exo_4.dir/build

TP3/CMakeFiles/TP3_exo_4.dir/clean:
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP3 && $(CMAKE_COMMAND) -P CMakeFiles/TP3_exo_4.dir/cmake_clean.cmake
.PHONY : TP3/CMakeFiles/TP3_exo_4.dir/clean

TP3/CMakeFiles/TP3_exo_4.dir/depend:
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/margaux/Documents/S3_OPENGL/GLImac-Template /home/margaux/Documents/S3_OPENGL/GLImac-Template/TP3 /home/margaux/Documents/S3_OPENGL/GLImac-Template-build /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP3 /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP3/CMakeFiles/TP3_exo_4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TP3/CMakeFiles/TP3_exo_4.dir/depend

