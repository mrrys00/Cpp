# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/zawawa

# Utility rule file for valgrind_tests.

# Include any custom commands dependencies for this target.
include tests/CMakeFiles/valgrind_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/valgrind_tests.dir/progress.make

tests/CMakeFiles/valgrind_tests: bin/tests
	cd /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/zawawa/bin && valgrind --leak-check=full /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/zawawa/bin/tests

valgrind_tests: tests/CMakeFiles/valgrind_tests
valgrind_tests: tests/CMakeFiles/valgrind_tests.dir/build.make
.PHONY : valgrind_tests

# Rule to build all files generated by this target.
tests/CMakeFiles/valgrind_tests.dir/build: valgrind_tests
.PHONY : tests/CMakeFiles/valgrind_tests.dir/build

tests/CMakeFiles/valgrind_tests.dir/clean:
	cd /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/zawawa/tests && $(CMAKE_COMMAND) -P CMakeFiles/valgrind_tests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/valgrind_tests.dir/clean

tests/CMakeFiles/valgrind_tests.dir/depend:
	cd /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/zawawa && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/tests /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/zawawa /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/zawawa/tests /home/agh/Nextcloud/STUDENCI/c++2022/zaj1Fraction_dlaStudentow/zawawa/tests/CMakeFiles/valgrind_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/valgrind_tests.dir/depend

