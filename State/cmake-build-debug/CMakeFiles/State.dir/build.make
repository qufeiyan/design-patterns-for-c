# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Softwares\JetBrains\CLion\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\Softwares\JetBrains\CLion\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\ClionProjects\design-patterns-for-c\State

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\ClionProjects\design-patterns-for-c\State\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/State.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/State.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/State.dir/flags.make

CMakeFiles/State.dir/main.c.obj: CMakeFiles/State.dir/flags.make
CMakeFiles/State.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\ClionProjects\design-patterns-for-c\State\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/State.dir/main.c.obj"
	D:\Softwares\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\State.dir\main.c.obj   -c E:\ClionProjects\design-patterns-for-c\State\main.c

CMakeFiles/State.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/State.dir/main.c.i"
	D:\Softwares\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\ClionProjects\design-patterns-for-c\State\main.c > CMakeFiles\State.dir\main.c.i

CMakeFiles/State.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/State.dir/main.c.s"
	D:\Softwares\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\ClionProjects\design-patterns-for-c\State\main.c -o CMakeFiles\State.dir\main.c.s

CMakeFiles/State.dir/src/State.c.obj: CMakeFiles/State.dir/flags.make
CMakeFiles/State.dir/src/State.c.obj: ../src/State.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\ClionProjects\design-patterns-for-c\State\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/State.dir/src/State.c.obj"
	D:\Softwares\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\State.dir\src\State.c.obj   -c E:\ClionProjects\design-patterns-for-c\State\src\State.c

CMakeFiles/State.dir/src/State.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/State.dir/src/State.c.i"
	D:\Softwares\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\ClionProjects\design-patterns-for-c\State\src\State.c > CMakeFiles\State.dir\src\State.c.i

CMakeFiles/State.dir/src/State.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/State.dir/src/State.c.s"
	D:\Softwares\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\ClionProjects\design-patterns-for-c\State\src\State.c -o CMakeFiles\State.dir\src\State.c.s

# Object files for target State
State_OBJECTS = \
"CMakeFiles/State.dir/main.c.obj" \
"CMakeFiles/State.dir/src/State.c.obj"

# External object files for target State
State_EXTERNAL_OBJECTS =

State.exe: CMakeFiles/State.dir/main.c.obj
State.exe: CMakeFiles/State.dir/src/State.c.obj
State.exe: CMakeFiles/State.dir/build.make
State.exe: CMakeFiles/State.dir/linklibs.rsp
State.exe: CMakeFiles/State.dir/objects1.rsp
State.exe: CMakeFiles/State.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\ClionProjects\design-patterns-for-c\State\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable State.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\State.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/State.dir/build: State.exe

.PHONY : CMakeFiles/State.dir/build

CMakeFiles/State.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\State.dir\cmake_clean.cmake
.PHONY : CMakeFiles/State.dir/clean

CMakeFiles/State.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\ClionProjects\design-patterns-for-c\State E:\ClionProjects\design-patterns-for-c\State E:\ClionProjects\design-patterns-for-c\State\cmake-build-debug E:\ClionProjects\design-patterns-for-c\State\cmake-build-debug E:\ClionProjects\design-patterns-for-c\State\cmake-build-debug\CMakeFiles\State.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/State.dir/depend
