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
include TPgarbage/CMakeFiles/TPgarbage_foo.dir/depend.make

# Include the progress variables for this target.
include TPgarbage/CMakeFiles/TPgarbage_foo.dir/progress.make

# Include the compile flags for this target's objects.
include TPgarbage/CMakeFiles/TPgarbage_foo.dir/flags.make

TPgarbage/CMakeFiles/TPgarbage_foo.dir/foo.cpp.o: TPgarbage/CMakeFiles/TPgarbage_foo.dir/flags.make
TPgarbage/CMakeFiles/TPgarbage_foo.dir/foo.cpp.o: /home/margaux/Documents/S3_OPENGL/GLImac-Template/TPgarbage/foo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/margaux/Documents/S3_OPENGL/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TPgarbage/CMakeFiles/TPgarbage_foo.dir/foo.cpp.o"
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TPgarbage && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TPgarbage_foo.dir/foo.cpp.o -c /home/margaux/Documents/S3_OPENGL/GLImac-Template/TPgarbage/foo.cpp

TPgarbage/CMakeFiles/TPgarbage_foo.dir/foo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TPgarbage_foo.dir/foo.cpp.i"
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TPgarbage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/margaux/Documents/S3_OPENGL/GLImac-Template/TPgarbage/foo.cpp > CMakeFiles/TPgarbage_foo.dir/foo.cpp.i

TPgarbage/CMakeFiles/TPgarbage_foo.dir/foo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TPgarbage_foo.dir/foo.cpp.s"
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TPgarbage && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/margaux/Documents/S3_OPENGL/GLImac-Template/TPgarbage/foo.cpp -o CMakeFiles/TPgarbage_foo.dir/foo.cpp.s

# Object files for target TPgarbage_foo
TPgarbage_foo_OBJECTS = \
"CMakeFiles/TPgarbage_foo.dir/foo.cpp.o"

# External object files for target TPgarbage_foo
TPgarbage_foo_EXTERNAL_OBJECTS =

TPgarbage/TPgarbage_foo: TPgarbage/CMakeFiles/TPgarbage_foo.dir/foo.cpp.o
TPgarbage/TPgarbage_foo: TPgarbage/CMakeFiles/TPgarbage_foo.dir/build.make
TPgarbage/TPgarbage_foo: glimac/libglimac.a
TPgarbage/TPgarbage_foo: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TPgarbage/TPgarbage_foo: /usr/lib/x86_64-linux-gnu/libSDL.so
TPgarbage/TPgarbage_foo: /usr/lib/x86_64-linux-gnu/libGL.so.1
TPgarbage/TPgarbage_foo: /usr/lib/x86_64-linux-gnu/libGLEW.so
TPgarbage/TPgarbage_foo: TPgarbage/CMakeFiles/TPgarbage_foo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/margaux/Documents/S3_OPENGL/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TPgarbage_foo"
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TPgarbage && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TPgarbage_foo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TPgarbage/CMakeFiles/TPgarbage_foo.dir/build: TPgarbage/TPgarbage_foo

.PHONY : TPgarbage/CMakeFiles/TPgarbage_foo.dir/build

TPgarbage/CMakeFiles/TPgarbage_foo.dir/clean:
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TPgarbage && $(CMAKE_COMMAND) -P CMakeFiles/TPgarbage_foo.dir/cmake_clean.cmake
.PHONY : TPgarbage/CMakeFiles/TPgarbage_foo.dir/clean

TPgarbage/CMakeFiles/TPgarbage_foo.dir/depend:
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/margaux/Documents/S3_OPENGL/GLImac-Template /home/margaux/Documents/S3_OPENGL/GLImac-Template/TPgarbage /home/margaux/Documents/S3_OPENGL/GLImac-Template-build /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TPgarbage /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TPgarbage/CMakeFiles/TPgarbage_foo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TPgarbage/CMakeFiles/TPgarbage_foo.dir/depend

