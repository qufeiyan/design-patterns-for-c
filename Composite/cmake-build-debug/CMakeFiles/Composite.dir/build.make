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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Elena\Desktop\design-patterns-for-c\Composite

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Elena\Desktop\design-patterns-for-c\Composite\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Composite.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Composite.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Composite.dir/flags.make

CMakeFiles/Composite.dir/main.c.obj: CMakeFiles/Composite.dir/flags.make
CMakeFiles/Composite.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elena\Desktop\design-patterns-for-c\Composite\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Composite.dir/main.c.obj"
	D:\Qt\Qt5.11.1\Tools\mingw530_32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Composite.dir\main.c.obj   -c C:\Users\Elena\Desktop\design-patterns-for-c\Composite\main.c

CMakeFiles/Composite.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Composite.dir/main.c.i"
	D:\Qt\Qt5.11.1\Tools\mingw530_32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elena\Desktop\design-patterns-for-c\Composite\main.c > CMakeFiles\Composite.dir\main.c.i

CMakeFiles/Composite.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Composite.dir/main.c.s"
	D:\Qt\Qt5.11.1\Tools\mingw530_32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elena\Desktop\design-patterns-for-c\Composite\main.c -o CMakeFiles\Composite.dir\main.c.s

CMakeFiles/Composite.dir/src/ArrayList.c.obj: CMakeFiles/Composite.dir/flags.make
CMakeFiles/Composite.dir/src/ArrayList.c.obj: ../src/ArrayList.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elena\Desktop\design-patterns-for-c\Composite\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Composite.dir/src/ArrayList.c.obj"
	D:\Qt\Qt5.11.1\Tools\mingw530_32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Composite.dir\src\ArrayList.c.obj   -c C:\Users\Elena\Desktop\design-patterns-for-c\Composite\src\ArrayList.c

CMakeFiles/Composite.dir/src/ArrayList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Composite.dir/src/ArrayList.c.i"
	D:\Qt\Qt5.11.1\Tools\mingw530_32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elena\Desktop\design-patterns-for-c\Composite\src\ArrayList.c > CMakeFiles\Composite.dir\src\ArrayList.c.i

CMakeFiles/Composite.dir/src/ArrayList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Composite.dir/src/ArrayList.c.s"
	D:\Qt\Qt5.11.1\Tools\mingw530_32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elena\Desktop\design-patterns-for-c\Composite\src\ArrayList.c -o CMakeFiles\Composite.dir\src\ArrayList.c.s

CMakeFiles/Composite.dir/src/Composite.c.obj: CMakeFiles/Composite.dir/flags.make
CMakeFiles/Composite.dir/src/Composite.c.obj: ../src/Composite.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Elena\Desktop\design-patterns-for-c\Composite\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Composite.dir/src/Composite.c.obj"
	D:\Qt\Qt5.11.1\Tools\mingw530_32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Composite.dir\src\Composite.c.obj   -c C:\Users\Elena\Desktop\design-patterns-for-c\Composite\src\Composite.c

CMakeFiles/Composite.dir/src/Composite.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Composite.dir/src/Composite.c.i"
	D:\Qt\Qt5.11.1\Tools\mingw530_32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Elena\Desktop\design-patterns-for-c\Composite\src\Composite.c > CMakeFiles\Composite.dir\src\Composite.c.i

CMakeFiles/Composite.dir/src/Composite.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Composite.dir/src/Composite.c.s"
	D:\Qt\Qt5.11.1\Tools\mingw530_32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Elena\Desktop\design-patterns-for-c\Composite\src\Composite.c -o CMakeFiles\Composite.dir\src\Composite.c.s

# Object files for target Composite
Composite_OBJECTS = \
"CMakeFiles/Composite.dir/main.c.obj" \
"CMakeFiles/Composite.dir/src/ArrayList.c.obj" \
"CMakeFiles/Composite.dir/src/Composite.c.obj"

# External object files for target Composite
Composite_EXTERNAL_OBJECTS =

Composite.exe: CMakeFiles/Composite.dir/main.c.obj
Composite.exe: CMakeFiles/Composite.dir/src/ArrayList.c.obj
Composite.exe: CMakeFiles/Composite.dir/src/Composite.c.obj
Composite.exe: CMakeFiles/Composite.dir/build.make
Composite.exe: CMakeFiles/Composite.dir/linklibs.rsp
Composite.exe: CMakeFiles/Composite.dir/objects1.rsp
Composite.exe: CMakeFiles/Composite.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Elena\Desktop\design-patterns-for-c\Composite\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Composite.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Composite.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Composite.dir/build: Composite.exe

.PHONY : CMakeFiles/Composite.dir/build

CMakeFiles/Composite.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Composite.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Composite.dir/clean

CMakeFiles/Composite.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Elena\Desktop\design-patterns-for-c\Composite C:\Users\Elena\Desktop\design-patterns-for-c\Composite C:\Users\Elena\Desktop\design-patterns-for-c\Composite\cmake-build-debug C:\Users\Elena\Desktop\design-patterns-for-c\Composite\cmake-build-debug C:\Users\Elena\Desktop\design-patterns-for-c\Composite\cmake-build-debug\CMakeFiles\Composite.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Composite.dir/depend
