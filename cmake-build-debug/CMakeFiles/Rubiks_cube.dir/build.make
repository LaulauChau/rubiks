# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Laurent\Documents\GitHub\rubiks

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Laurent\Documents\GitHub\rubiks\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Rubiks_cube.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Rubiks_cube.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Rubiks_cube.dir/flags.make

CMakeFiles/Rubiks_cube.dir/main.c.obj: CMakeFiles/Rubiks_cube.dir/flags.make
CMakeFiles/Rubiks_cube.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Laurent\Documents\GitHub\rubiks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Rubiks_cube.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Rubiks_cube.dir\main.c.obj   -c C:\Users\Laurent\Documents\GitHub\rubiks\main.c

CMakeFiles/Rubiks_cube.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Rubiks_cube.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Laurent\Documents\GitHub\rubiks\main.c > CMakeFiles\Rubiks_cube.dir\main.c.i

CMakeFiles/Rubiks_cube.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Rubiks_cube.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Laurent\Documents\GitHub\rubiks\main.c -o CMakeFiles\Rubiks_cube.dir\main.c.s

CMakeFiles/Rubiks_cube.dir/rubiks.c.obj: CMakeFiles/Rubiks_cube.dir/flags.make
CMakeFiles/Rubiks_cube.dir/rubiks.c.obj: ../rubiks.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Laurent\Documents\GitHub\rubiks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Rubiks_cube.dir/rubiks.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Rubiks_cube.dir\rubiks.c.obj   -c C:\Users\Laurent\Documents\GitHub\rubiks\rubiks.c

CMakeFiles/Rubiks_cube.dir/rubiks.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Rubiks_cube.dir/rubiks.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Laurent\Documents\GitHub\rubiks\rubiks.c > CMakeFiles\Rubiks_cube.dir\rubiks.c.i

CMakeFiles/Rubiks_cube.dir/rubiks.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Rubiks_cube.dir/rubiks.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Laurent\Documents\GitHub\rubiks\rubiks.c -o CMakeFiles\Rubiks_cube.dir\rubiks.c.s

CMakeFiles/Rubiks_cube.dir/conio.c.obj: CMakeFiles/Rubiks_cube.dir/flags.make
CMakeFiles/Rubiks_cube.dir/conio.c.obj: ../conio.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Laurent\Documents\GitHub\rubiks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Rubiks_cube.dir/conio.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Rubiks_cube.dir\conio.c.obj   -c C:\Users\Laurent\Documents\GitHub\rubiks\conio.c

CMakeFiles/Rubiks_cube.dir/conio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Rubiks_cube.dir/conio.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Laurent\Documents\GitHub\rubiks\conio.c > CMakeFiles\Rubiks_cube.dir\conio.c.i

CMakeFiles/Rubiks_cube.dir/conio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Rubiks_cube.dir/conio.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Laurent\Documents\GitHub\rubiks\conio.c -o CMakeFiles\Rubiks_cube.dir\conio.c.s

# Object files for target Rubiks_cube
Rubiks_cube_OBJECTS = \
"CMakeFiles/Rubiks_cube.dir/main.c.obj" \
"CMakeFiles/Rubiks_cube.dir/rubiks.c.obj" \
"CMakeFiles/Rubiks_cube.dir/conio.c.obj"

# External object files for target Rubiks_cube
Rubiks_cube_EXTERNAL_OBJECTS =

Rubiks_cube.exe: CMakeFiles/Rubiks_cube.dir/main.c.obj
Rubiks_cube.exe: CMakeFiles/Rubiks_cube.dir/rubiks.c.obj
Rubiks_cube.exe: CMakeFiles/Rubiks_cube.dir/conio.c.obj
Rubiks_cube.exe: CMakeFiles/Rubiks_cube.dir/build.make
Rubiks_cube.exe: CMakeFiles/Rubiks_cube.dir/linklibs.rsp
Rubiks_cube.exe: CMakeFiles/Rubiks_cube.dir/objects1.rsp
Rubiks_cube.exe: CMakeFiles/Rubiks_cube.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Laurent\Documents\GitHub\rubiks\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Rubiks_cube.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Rubiks_cube.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Rubiks_cube.dir/build: Rubiks_cube.exe

.PHONY : CMakeFiles/Rubiks_cube.dir/build

CMakeFiles/Rubiks_cube.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Rubiks_cube.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Rubiks_cube.dir/clean

CMakeFiles/Rubiks_cube.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Laurent\Documents\GitHub\rubiks C:\Users\Laurent\Documents\GitHub\rubiks C:\Users\Laurent\Documents\GitHub\rubiks\cmake-build-debug C:\Users\Laurent\Documents\GitHub\rubiks\cmake-build-debug C:\Users\Laurent\Documents\GitHub\rubiks\cmake-build-debug\CMakeFiles\Rubiks_cube.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Rubiks_cube.dir/depend

