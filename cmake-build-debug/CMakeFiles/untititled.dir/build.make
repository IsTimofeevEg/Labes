# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\User\CLionProjects\untitled

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\CLionProjects\untitled\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untititled.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/untititled.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/untititled.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untititled.dir/flags.make

CMakeFiles/untititled.dir/libs/data_structures/tests_for_pushBack_Vector.c.obj: CMakeFiles/untititled.dir/flags.make
CMakeFiles/untititled.dir/libs/data_structures/tests_for_pushBack_Vector.c.obj: C:/Users/User/CLionProjects/untitled/libs/data_structures/tests_for_pushBack_Vector.c
CMakeFiles/untititled.dir/libs/data_structures/tests_for_pushBack_Vector.c.obj: CMakeFiles/untititled.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\CLionProjects\untitled\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/untititled.dir/libs/data_structures/tests_for_pushBack_Vector.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/untititled.dir/libs/data_structures/tests_for_pushBack_Vector.c.obj -MF CMakeFiles\untititled.dir\libs\data_structures\tests_for_pushBack_Vector.c.obj.d -o CMakeFiles\untititled.dir\libs\data_structures\tests_for_pushBack_Vector.c.obj -c C:\Users\User\CLionProjects\untitled\libs\data_structures\tests_for_pushBack_Vector.c

CMakeFiles/untititled.dir/libs/data_structures/tests_for_pushBack_Vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untititled.dir/libs/data_structures/tests_for_pushBack_Vector.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\User\CLionProjects\untitled\libs\data_structures\tests_for_pushBack_Vector.c > CMakeFiles\untititled.dir\libs\data_structures\tests_for_pushBack_Vector.c.i

CMakeFiles/untititled.dir/libs/data_structures/tests_for_pushBack_Vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untititled.dir/libs/data_structures/tests_for_pushBack_Vector.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\User\CLionProjects\untitled\libs\data_structures\tests_for_pushBack_Vector.c -o CMakeFiles\untititled.dir\libs\data_structures\tests_for_pushBack_Vector.c.s

# Object files for target untititled
untititled_OBJECTS = \
"CMakeFiles/untititled.dir/libs/data_structures/tests_for_pushBack_Vector.c.obj"

# External object files for target untititled
untititled_EXTERNAL_OBJECTS =

untititled.exe: CMakeFiles/untititled.dir/libs/data_structures/tests_for_pushBack_Vector.c.obj
untititled.exe: CMakeFiles/untititled.dir/build.make
untititled.exe: CMakeFiles/untititled.dir/linkLibs.rsp
untititled.exe: CMakeFiles/untititled.dir/objects1.rsp
untititled.exe: CMakeFiles/untititled.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\CLionProjects\untitled\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable untititled.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\untititled.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untititled.dir/build: untititled.exe
.PHONY : CMakeFiles/untititled.dir/build

CMakeFiles/untititled.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\untititled.dir\cmake_clean.cmake
.PHONY : CMakeFiles/untititled.dir/clean

CMakeFiles/untititled.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\CLionProjects\untitled C:\Users\User\CLionProjects\untitled C:\Users\User\CLionProjects\untitled\cmake-build-debug C:\Users\User\CLionProjects\untitled\cmake-build-debug C:\Users\User\CLionProjects\untitled\cmake-build-debug\CMakeFiles\untititled.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untititled.dir/depend

