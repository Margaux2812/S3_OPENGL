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
include TP2/CMakeFiles/TP2_exo5.dir/depend.make

# Include the progress variables for this target.
include TP2/CMakeFiles/TP2_exo5.dir/progress.make

# Include the compile flags for this target's objects.
include TP2/CMakeFiles/TP2_exo5.dir/flags.make

TP2/CMakeFiles/TP2_exo5.dir/exo5.cpp.o: TP2/CMakeFiles/TP2_exo5.dir/flags.make
TP2/CMakeFiles/TP2_exo5.dir/exo5.cpp.o: /home/margaux/Documents/S3_OPENGL/GLImac-Template/TP2/exo5.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/margaux/Documents/S3_OPENGL/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TP2/CMakeFiles/TP2_exo5.dir/exo5.cpp.o"
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP2 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP2_exo5.dir/exo5.cpp.o -c /home/margaux/Documents/S3_OPENGL/GLImac-Template/TP2/exo5.cpp

TP2/CMakeFiles/TP2_exo5.dir/exo5.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP2_exo5.dir/exo5.cpp.i"
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/margaux/Documents/S3_OPENGL/GLImac-Template/TP2/exo5.cpp > CMakeFiles/TP2_exo5.dir/exo5.cpp.i

TP2/CMakeFiles/TP2_exo5.dir/exo5.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP2_exo5.dir/exo5.cpp.s"
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP2 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/margaux/Documents/S3_OPENGL/GLImac-Template/TP2/exo5.cpp -o CMakeFiles/TP2_exo5.dir/exo5.cpp.s

# Object files for target TP2_exo5
TP2_exo5_OBJECTS = \
"CMakeFiles/TP2_exo5.dir/exo5.cpp.o"

# External object files for target TP2_exo5
TP2_exo5_EXTERNAL_OBJECTS =

TP2/TP2_exo5: TP2/CMakeFiles/TP2_exo5.dir/exo5.cpp.o
TP2/TP2_exo5: TP2/CMakeFiles/TP2_exo5.dir/build.make
TP2/TP2_exo5: glimac/libglimac.a
TP2/TP2_exo5: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TP2/TP2_exo5: /usr/lib/x86_64-linux-gnu/libSDL.so
TP2/TP2_exo5: /usr/lib/x86_64-linux-gnu/libGL.so.1
TP2/TP2_exo5: /usr/lib/x86_64-linux-gnu/libGLEW.so
TP2/TP2_exo5: TP2/CMakeFiles/TP2_exo5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/margaux/Documents/S3_OPENGL/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP2_exo5"
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP2_exo5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TP2/CMakeFiles/TP2_exo5.dir/build: TP2/TP2_exo5

.PHONY : TP2/CMakeFiles/TP2_exo5.dir/build

TP2/CMakeFiles/TP2_exo5.dir/clean:
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP2 && $(CMAKE_COMMAND) -P CMakeFiles/TP2_exo5.dir/cmake_clean.cmake
.PHONY : TP2/CMakeFiles/TP2_exo5.dir/clean

TP2/CMakeFiles/TP2_exo5.dir/depend:
	cd /home/margaux/Documents/S3_OPENGL/GLImac-Template-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/margaux/Documents/S3_OPENGL/GLImac-Template /home/margaux/Documents/S3_OPENGL/GLImac-Template/TP2 /home/margaux/Documents/S3_OPENGL/GLImac-Template-build /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP2 /home/margaux/Documents/S3_OPENGL/GLImac-Template-build/TP2/CMakeFiles/TP2_exo5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TP2/CMakeFiles/TP2_exo5.dir/depend

