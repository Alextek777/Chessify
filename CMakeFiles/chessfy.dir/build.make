# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/kalex/golang/src/Chessify

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kalex/golang/src/Chessify

# Include any dependencies generated for this target.
include CMakeFiles/chessfy.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/chessfy.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/chessfy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chessfy.dir/flags.make

CMakeFiles/chessfy.dir/availableactionsfinder.cpp.o: CMakeFiles/chessfy.dir/flags.make
CMakeFiles/chessfy.dir/availableactionsfinder.cpp.o: availableactionsfinder.cpp
CMakeFiles/chessfy.dir/availableactionsfinder.cpp.o: CMakeFiles/chessfy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kalex/golang/src/Chessify/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chessfy.dir/availableactionsfinder.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chessfy.dir/availableactionsfinder.cpp.o -MF CMakeFiles/chessfy.dir/availableactionsfinder.cpp.o.d -o CMakeFiles/chessfy.dir/availableactionsfinder.cpp.o -c /home/kalex/golang/src/Chessify/availableactionsfinder.cpp

CMakeFiles/chessfy.dir/availableactionsfinder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessfy.dir/availableactionsfinder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kalex/golang/src/Chessify/availableactionsfinder.cpp > CMakeFiles/chessfy.dir/availableactionsfinder.cpp.i

CMakeFiles/chessfy.dir/availableactionsfinder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessfy.dir/availableactionsfinder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kalex/golang/src/Chessify/availableactionsfinder.cpp -o CMakeFiles/chessfy.dir/availableactionsfinder.cpp.s

CMakeFiles/chessfy.dir/boardwidget.cpp.o: CMakeFiles/chessfy.dir/flags.make
CMakeFiles/chessfy.dir/boardwidget.cpp.o: boardwidget.cpp
CMakeFiles/chessfy.dir/boardwidget.cpp.o: CMakeFiles/chessfy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kalex/golang/src/Chessify/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/chessfy.dir/boardwidget.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chessfy.dir/boardwidget.cpp.o -MF CMakeFiles/chessfy.dir/boardwidget.cpp.o.d -o CMakeFiles/chessfy.dir/boardwidget.cpp.o -c /home/kalex/golang/src/Chessify/boardwidget.cpp

CMakeFiles/chessfy.dir/boardwidget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessfy.dir/boardwidget.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kalex/golang/src/Chessify/boardwidget.cpp > CMakeFiles/chessfy.dir/boardwidget.cpp.i

CMakeFiles/chessfy.dir/boardwidget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessfy.dir/boardwidget.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kalex/golang/src/Chessify/boardwidget.cpp -o CMakeFiles/chessfy.dir/boardwidget.cpp.s

CMakeFiles/chessfy.dir/core.cpp.o: CMakeFiles/chessfy.dir/flags.make
CMakeFiles/chessfy.dir/core.cpp.o: core.cpp
CMakeFiles/chessfy.dir/core.cpp.o: CMakeFiles/chessfy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kalex/golang/src/Chessify/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/chessfy.dir/core.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chessfy.dir/core.cpp.o -MF CMakeFiles/chessfy.dir/core.cpp.o.d -o CMakeFiles/chessfy.dir/core.cpp.o -c /home/kalex/golang/src/Chessify/core.cpp

CMakeFiles/chessfy.dir/core.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessfy.dir/core.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kalex/golang/src/Chessify/core.cpp > CMakeFiles/chessfy.dir/core.cpp.i

CMakeFiles/chessfy.dir/core.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessfy.dir/core.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kalex/golang/src/Chessify/core.cpp -o CMakeFiles/chessfy.dir/core.cpp.s

CMakeFiles/chessfy.dir/Definitions.cpp.o: CMakeFiles/chessfy.dir/flags.make
CMakeFiles/chessfy.dir/Definitions.cpp.o: Definitions.cpp
CMakeFiles/chessfy.dir/Definitions.cpp.o: CMakeFiles/chessfy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kalex/golang/src/Chessify/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/chessfy.dir/Definitions.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chessfy.dir/Definitions.cpp.o -MF CMakeFiles/chessfy.dir/Definitions.cpp.o.d -o CMakeFiles/chessfy.dir/Definitions.cpp.o -c /home/kalex/golang/src/Chessify/Definitions.cpp

CMakeFiles/chessfy.dir/Definitions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessfy.dir/Definitions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kalex/golang/src/Chessify/Definitions.cpp > CMakeFiles/chessfy.dir/Definitions.cpp.i

CMakeFiles/chessfy.dir/Definitions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessfy.dir/Definitions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kalex/golang/src/Chessify/Definitions.cpp -o CMakeFiles/chessfy.dir/Definitions.cpp.s

CMakeFiles/chessfy.dir/main.cpp.o: CMakeFiles/chessfy.dir/flags.make
CMakeFiles/chessfy.dir/main.cpp.o: main.cpp
CMakeFiles/chessfy.dir/main.cpp.o: CMakeFiles/chessfy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kalex/golang/src/Chessify/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/chessfy.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chessfy.dir/main.cpp.o -MF CMakeFiles/chessfy.dir/main.cpp.o.d -o CMakeFiles/chessfy.dir/main.cpp.o -c /home/kalex/golang/src/Chessify/main.cpp

CMakeFiles/chessfy.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessfy.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kalex/golang/src/Chessify/main.cpp > CMakeFiles/chessfy.dir/main.cpp.i

CMakeFiles/chessfy.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessfy.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kalex/golang/src/Chessify/main.cpp -o CMakeFiles/chessfy.dir/main.cpp.s

CMakeFiles/chessfy.dir/mainwindow.cpp.o: CMakeFiles/chessfy.dir/flags.make
CMakeFiles/chessfy.dir/mainwindow.cpp.o: mainwindow.cpp
CMakeFiles/chessfy.dir/mainwindow.cpp.o: CMakeFiles/chessfy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kalex/golang/src/Chessify/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/chessfy.dir/mainwindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chessfy.dir/mainwindow.cpp.o -MF CMakeFiles/chessfy.dir/mainwindow.cpp.o.d -o CMakeFiles/chessfy.dir/mainwindow.cpp.o -c /home/kalex/golang/src/Chessify/mainwindow.cpp

CMakeFiles/chessfy.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessfy.dir/mainwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kalex/golang/src/Chessify/mainwindow.cpp > CMakeFiles/chessfy.dir/mainwindow.cpp.i

CMakeFiles/chessfy.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessfy.dir/mainwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kalex/golang/src/Chessify/mainwindow.cpp -o CMakeFiles/chessfy.dir/mainwindow.cpp.s

CMakeFiles/chessfy.dir/player.cpp.o: CMakeFiles/chessfy.dir/flags.make
CMakeFiles/chessfy.dir/player.cpp.o: player.cpp
CMakeFiles/chessfy.dir/player.cpp.o: CMakeFiles/chessfy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kalex/golang/src/Chessify/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/chessfy.dir/player.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chessfy.dir/player.cpp.o -MF CMakeFiles/chessfy.dir/player.cpp.o.d -o CMakeFiles/chessfy.dir/player.cpp.o -c /home/kalex/golang/src/Chessify/player.cpp

CMakeFiles/chessfy.dir/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chessfy.dir/player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kalex/golang/src/Chessify/player.cpp > CMakeFiles/chessfy.dir/player.cpp.i

CMakeFiles/chessfy.dir/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chessfy.dir/player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kalex/golang/src/Chessify/player.cpp -o CMakeFiles/chessfy.dir/player.cpp.s

# Object files for target chessfy
chessfy_OBJECTS = \
"CMakeFiles/chessfy.dir/availableactionsfinder.cpp.o" \
"CMakeFiles/chessfy.dir/boardwidget.cpp.o" \
"CMakeFiles/chessfy.dir/core.cpp.o" \
"CMakeFiles/chessfy.dir/Definitions.cpp.o" \
"CMakeFiles/chessfy.dir/main.cpp.o" \
"CMakeFiles/chessfy.dir/mainwindow.cpp.o" \
"CMakeFiles/chessfy.dir/player.cpp.o"

# External object files for target chessfy
chessfy_EXTERNAL_OBJECTS =

chessfy: CMakeFiles/chessfy.dir/availableactionsfinder.cpp.o
chessfy: CMakeFiles/chessfy.dir/boardwidget.cpp.o
chessfy: CMakeFiles/chessfy.dir/core.cpp.o
chessfy: CMakeFiles/chessfy.dir/Definitions.cpp.o
chessfy: CMakeFiles/chessfy.dir/main.cpp.o
chessfy: CMakeFiles/chessfy.dir/mainwindow.cpp.o
chessfy: CMakeFiles/chessfy.dir/player.cpp.o
chessfy: CMakeFiles/chessfy.dir/build.make
chessfy: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.8
chessfy: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.8
chessfy: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.8
chessfy: CMakeFiles/chessfy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kalex/golang/src/Chessify/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable chessfy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chessfy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chessfy.dir/build: chessfy
.PHONY : CMakeFiles/chessfy.dir/build

CMakeFiles/chessfy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chessfy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chessfy.dir/clean

CMakeFiles/chessfy.dir/depend:
	cd /home/kalex/golang/src/Chessify && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kalex/golang/src/Chessify /home/kalex/golang/src/Chessify /home/kalex/golang/src/Chessify /home/kalex/golang/src/Chessify /home/kalex/golang/src/Chessify/CMakeFiles/chessfy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chessfy.dir/depend

