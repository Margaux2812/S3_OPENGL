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
include TP1/CMakeFiles/TP1_exo6_buffer_index.dir/depend.make

# Include the progress variables for this target.
include TP1/CMakeFiles/TP1_exo6_buffer_index.dir/progress.make

# Include the compile flags for this target's objects.
include TP1/CMakeFiles/TP1_exo6_buffer_index.dir/flags.make

TP1/CMakeFiles/TP1_exo6_buffer_index.dir/exo6_buffer_index.cpp.o: TP1/CMakeFiles/TP1_exo6_buffer_index.dir/flags.make
TP1/CMakeFiles/TP1_exo6_buffer_index.dir/exo6_buffer_index.cpp.o: /home/margaux/Documents/S3_OPENGL/GLImac-Template/TP1/exo6_buffer_index.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/margaux/Documents/S3_OPENGL/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TP1/CMakeFiles/TP1_exo6_buffer_index.dir/exo6_buffer_index.cpp.o"
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP1 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP1_exo6_buffer_index.dir/exo6_buffer_index.cpp.o -c /home/margaux/Documents/S3_OPENGL/GLImac-Template/TP1/exo6_buffer_index.cpp

TP1/CMakeFiles/TP1_exo6_buffer_index.dir/exo6_buffer_index.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1_exo6_buffer_index.dir/exo6_buffer_index.cpp.i"
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP1 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/margaux/Documents/S3_OPENGL/GLImac-Template/TP1/exo6_buffer_index.cpp > CMakeFiles/TP1_exo6_buffer_index.dir/exo6_buffer_index.cpp.i

TP1/CMakeFiles/TP1_exo6_buffer_index.dir/exo6_buffer_index.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1_exo6_buffer_index.dir/exo6_buffer_index.cpp.s"
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP1 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/margaux/Documents/S3_OPENGL/GLImac-Template/TP1/exo6_buffer_index.cpp -o CMakeFiles/TP1_exo6_buffer_index.dir/exo6_buffer_index.cpp.s

# Object files for target TP1_exo6_buffer_index
TP1_exo6_buffer_index_OBJECTS = \
"CMakeFiles/TP1_exo6_buffer_index.dir/exo6_buffer_index.cpp.o"

# External object files for target TP1_exo6_buffer_index
TP1_exo6_buffer_index_EXTERNAL_OBJECTS =

TP1/TP1_exo6_buffer_index: TP1/CMakeFiles/TP1_exo6_buffer_index.dir/exo6_buffer_index.cpp.o
TP1/TP1_exo6_buffer_index: TP1/CMakeFiles/TP1_exo6_buffer_index.dir/build.make
TP1/TP1_exo6_buffer_index: glimac/libglimac.a
TP1/TP1_exo6_buffer_index: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TP1/TP1_exo6_buffer_index: /usr/lib/x86_64-linux-gnu/libSDL.so
TP1/TP1_exo6_buffer_index: /usr/lib/x86_64-linux-gnu/libGL.so.1
TP1/TP1_exo6_buffer_index: /usr/lib/x86_64-linux-gnu/libGLEW.so
TP1/TP1_exo6_buffer_index: TP1/CMakeFiles/TP1_exo6_buffer_index.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/margaux/Documents/S3_OPENGL/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP1_exo6_buffer_index"
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP1_exo6_buffer_index.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TP1/CMakeFiles/TP1_exo6_buffer_index.dir/build: TP1/TP1_exo6_buffer_index

.PHONY : TP1/CMakeFiles/TP1_exo6_buffer_index.dir/build

TP1/CMakeFiles/TP1_exo6_buffer_index.dir/clean:
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP1 && $(CMAKE_COMMAND) -P CMakeFiles/TP1_exo6_buffer_index.dir/cmake_clean.cmake
.PHONY : TP1/CMakeFiles/TP1_exo6_buffer_index.dir/clean

TP1/CMakeFiles/TP1_exo6_buffer_index.dir/depend:
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/margaux/Documents/S3_OPENGL/GLImac-Template /home/margaux/Documents/S3_OPENGL/GLImac-Template/TP1 /home/margaux/Documents/S3_OPENGL/GLImac-Template-build /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP1 /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP1/CMakeFiles/TP1_exo6_buffer_index.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TP1/CMakeFiles/TP1_exo6_buffer_index.dir/depend

