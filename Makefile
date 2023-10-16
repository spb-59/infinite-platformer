# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/spb/oop-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/spb/oop-project

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/spb/oop-project/CMakeFiles /home/spb/oop-project//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/spb/oop-project/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named program

# Build rule for target.
program: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 program
.PHONY : program

# fast build rule for target.
program/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/build
.PHONY : program/fast

src/Animation.o: src/Animation.cpp.o
.PHONY : src/Animation.o

# target to build an object file
src/Animation.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Animation.cpp.o
.PHONY : src/Animation.cpp.o

src/Animation.i: src/Animation.cpp.i
.PHONY : src/Animation.i

# target to preprocess a source file
src/Animation.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Animation.cpp.i
.PHONY : src/Animation.cpp.i

src/Animation.s: src/Animation.cpp.s
.PHONY : src/Animation.s

# target to generate assembly for a file
src/Animation.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Animation.cpp.s
.PHONY : src/Animation.cpp.s

src/Button.o: src/Button.cpp.o
.PHONY : src/Button.o

# target to build an object file
src/Button.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Button.cpp.o
.PHONY : src/Button.cpp.o

src/Button.i: src/Button.cpp.i
.PHONY : src/Button.i

# target to preprocess a source file
src/Button.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Button.cpp.i
.PHONY : src/Button.cpp.i

src/Button.s: src/Button.cpp.s
.PHONY : src/Button.s

# target to generate assembly for a file
src/Button.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Button.cpp.s
.PHONY : src/Button.cpp.s

src/Colision.o: src/Colision.cpp.o
.PHONY : src/Colision.o

# target to build an object file
src/Colision.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Colision.cpp.o
.PHONY : src/Colision.cpp.o

src/Colision.i: src/Colision.cpp.i
.PHONY : src/Colision.i

# target to preprocess a source file
src/Colision.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Colision.cpp.i
.PHONY : src/Colision.cpp.i

src/Colision.s: src/Colision.cpp.s
.PHONY : src/Colision.s

# target to generate assembly for a file
src/Colision.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Colision.cpp.s
.PHONY : src/Colision.cpp.s

src/Entity.o: src/Entity.cpp.o
.PHONY : src/Entity.o

# target to build an object file
src/Entity.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Entity.cpp.o
.PHONY : src/Entity.cpp.o

src/Entity.i: src/Entity.cpp.i
.PHONY : src/Entity.i

# target to preprocess a source file
src/Entity.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Entity.cpp.i
.PHONY : src/Entity.cpp.i

src/Entity.s: src/Entity.cpp.s
.PHONY : src/Entity.s

# target to generate assembly for a file
src/Entity.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Entity.cpp.s
.PHONY : src/Entity.cpp.s

src/Game.o: src/Game.cpp.o
.PHONY : src/Game.o

# target to build an object file
src/Game.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Game.cpp.o
.PHONY : src/Game.cpp.o

src/Game.i: src/Game.cpp.i
.PHONY : src/Game.i

# target to preprocess a source file
src/Game.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Game.cpp.i
.PHONY : src/Game.cpp.i

src/Game.s: src/Game.cpp.s
.PHONY : src/Game.s

# target to generate assembly for a file
src/Game.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Game.cpp.s
.PHONY : src/Game.cpp.s

src/Gamestate.o: src/Gamestate.cpp.o
.PHONY : src/Gamestate.o

# target to build an object file
src/Gamestate.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Gamestate.cpp.o
.PHONY : src/Gamestate.cpp.o

src/Gamestate.i: src/Gamestate.cpp.i
.PHONY : src/Gamestate.i

# target to preprocess a source file
src/Gamestate.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Gamestate.cpp.i
.PHONY : src/Gamestate.cpp.i

src/Gamestate.s: src/Gamestate.cpp.s
.PHONY : src/Gamestate.s

# target to generate assembly for a file
src/Gamestate.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Gamestate.cpp.s
.PHONY : src/Gamestate.cpp.s

src/Generation.o: src/Generation.cpp.o
.PHONY : src/Generation.o

# target to build an object file
src/Generation.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Generation.cpp.o
.PHONY : src/Generation.cpp.o

src/Generation.i: src/Generation.cpp.i
.PHONY : src/Generation.i

# target to preprocess a source file
src/Generation.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Generation.cpp.i
.PHONY : src/Generation.cpp.i

src/Generation.s: src/Generation.cpp.s
.PHONY : src/Generation.s

# target to generate assembly for a file
src/Generation.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Generation.cpp.s
.PHONY : src/Generation.cpp.s

src/LavaPit.o: src/LavaPit.cpp.o
.PHONY : src/LavaPit.o

# target to build an object file
src/LavaPit.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/LavaPit.cpp.o
.PHONY : src/LavaPit.cpp.o

src/LavaPit.i: src/LavaPit.cpp.i
.PHONY : src/LavaPit.i

# target to preprocess a source file
src/LavaPit.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/LavaPit.cpp.i
.PHONY : src/LavaPit.cpp.i

src/LavaPit.s: src/LavaPit.cpp.s
.PHONY : src/LavaPit.s

# target to generate assembly for a file
src/LavaPit.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/LavaPit.cpp.s
.PHONY : src/LavaPit.cpp.s

src/LavaWall.o: src/LavaWall.cpp.o
.PHONY : src/LavaWall.o

# target to build an object file
src/LavaWall.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/LavaWall.cpp.o
.PHONY : src/LavaWall.cpp.o

src/LavaWall.i: src/LavaWall.cpp.i
.PHONY : src/LavaWall.i

# target to preprocess a source file
src/LavaWall.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/LavaWall.cpp.i
.PHONY : src/LavaWall.cpp.i

src/LavaWall.s: src/LavaWall.cpp.s
.PHONY : src/LavaWall.s

# target to generate assembly for a file
src/LavaWall.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/LavaWall.cpp.s
.PHONY : src/LavaWall.cpp.s

src/Menu.o: src/Menu.cpp.o
.PHONY : src/Menu.o

# target to build an object file
src/Menu.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Menu.cpp.o
.PHONY : src/Menu.cpp.o

src/Menu.i: src/Menu.cpp.i
.PHONY : src/Menu.i

# target to preprocess a source file
src/Menu.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Menu.cpp.i
.PHONY : src/Menu.cpp.i

src/Menu.s: src/Menu.cpp.s
.PHONY : src/Menu.s

# target to generate assembly for a file
src/Menu.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Menu.cpp.s
.PHONY : src/Menu.cpp.s

src/Object.o: src/Object.cpp.o
.PHONY : src/Object.o

# target to build an object file
src/Object.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Object.cpp.o
.PHONY : src/Object.cpp.o

src/Object.i: src/Object.cpp.i
.PHONY : src/Object.i

# target to preprocess a source file
src/Object.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Object.cpp.i
.PHONY : src/Object.cpp.i

src/Object.s: src/Object.cpp.s
.PHONY : src/Object.s

# target to generate assembly for a file
src/Object.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Object.cpp.s
.PHONY : src/Object.cpp.s

src/Obstacle.o: src/Obstacle.cpp.o
.PHONY : src/Obstacle.o

# target to build an object file
src/Obstacle.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Obstacle.cpp.o
.PHONY : src/Obstacle.cpp.o

src/Obstacle.i: src/Obstacle.cpp.i
.PHONY : src/Obstacle.i

# target to preprocess a source file
src/Obstacle.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Obstacle.cpp.i
.PHONY : src/Obstacle.cpp.i

src/Obstacle.s: src/Obstacle.cpp.s
.PHONY : src/Obstacle.s

# target to generate assembly for a file
src/Obstacle.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Obstacle.cpp.s
.PHONY : src/Obstacle.cpp.s

src/Physics.o: src/Physics.cpp.o
.PHONY : src/Physics.o

# target to build an object file
src/Physics.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Physics.cpp.o
.PHONY : src/Physics.cpp.o

src/Physics.i: src/Physics.cpp.i
.PHONY : src/Physics.i

# target to preprocess a source file
src/Physics.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Physics.cpp.i
.PHONY : src/Physics.cpp.i

src/Physics.s: src/Physics.cpp.s
.PHONY : src/Physics.s

# target to generate assembly for a file
src/Physics.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Physics.cpp.s
.PHONY : src/Physics.cpp.s

src/Platform.o: src/Platform.cpp.o
.PHONY : src/Platform.o

# target to build an object file
src/Platform.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Platform.cpp.o
.PHONY : src/Platform.cpp.o

src/Platform.i: src/Platform.cpp.i
.PHONY : src/Platform.i

# target to preprocess a source file
src/Platform.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Platform.cpp.i
.PHONY : src/Platform.cpp.i

src/Platform.s: src/Platform.cpp.s
.PHONY : src/Platform.s

# target to generate assembly for a file
src/Platform.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Platform.cpp.s
.PHONY : src/Platform.cpp.s

src/Player.o: src/Player.cpp.o
.PHONY : src/Player.o

# target to build an object file
src/Player.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Player.cpp.o
.PHONY : src/Player.cpp.o

src/Player.i: src/Player.cpp.i
.PHONY : src/Player.i

# target to preprocess a source file
src/Player.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Player.cpp.i
.PHONY : src/Player.cpp.i

src/Player.s: src/Player.cpp.s
.PHONY : src/Player.s

# target to generate assembly for a file
src/Player.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Player.cpp.s
.PHONY : src/Player.cpp.s

src/Rock.o: src/Rock.cpp.o
.PHONY : src/Rock.o

# target to build an object file
src/Rock.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Rock.cpp.o
.PHONY : src/Rock.cpp.o

src/Rock.i: src/Rock.cpp.i
.PHONY : src/Rock.i

# target to preprocess a source file
src/Rock.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Rock.cpp.i
.PHONY : src/Rock.cpp.i

src/Rock.s: src/Rock.cpp.s
.PHONY : src/Rock.s

# target to generate assembly for a file
src/Rock.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Rock.cpp.s
.PHONY : src/Rock.cpp.s

src/RockPlatform.o: src/RockPlatform.cpp.o
.PHONY : src/RockPlatform.o

# target to build an object file
src/RockPlatform.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/RockPlatform.cpp.o
.PHONY : src/RockPlatform.cpp.o

src/RockPlatform.i: src/RockPlatform.cpp.i
.PHONY : src/RockPlatform.i

# target to preprocess a source file
src/RockPlatform.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/RockPlatform.cpp.i
.PHONY : src/RockPlatform.cpp.i

src/RockPlatform.s: src/RockPlatform.cpp.s
.PHONY : src/RockPlatform.s

# target to generate assembly for a file
src/RockPlatform.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/RockPlatform.cpp.s
.PHONY : src/RockPlatform.cpp.s

src/Spikes.o: src/Spikes.cpp.o
.PHONY : src/Spikes.o

# target to build an object file
src/Spikes.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Spikes.cpp.o
.PHONY : src/Spikes.cpp.o

src/Spikes.i: src/Spikes.cpp.i
.PHONY : src/Spikes.i

# target to preprocess a source file
src/Spikes.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Spikes.cpp.i
.PHONY : src/Spikes.cpp.i

src/Spikes.s: src/Spikes.cpp.s
.PHONY : src/Spikes.s

# target to generate assembly for a file
src/Spikes.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Spikes.cpp.s
.PHONY : src/Spikes.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... program"
	@echo "... src/Animation.o"
	@echo "... src/Animation.i"
	@echo "... src/Animation.s"
	@echo "... src/Button.o"
	@echo "... src/Button.i"
	@echo "... src/Button.s"
	@echo "... src/Colision.o"
	@echo "... src/Colision.i"
	@echo "... src/Colision.s"
	@echo "... src/Entity.o"
	@echo "... src/Entity.i"
	@echo "... src/Entity.s"
	@echo "... src/Game.o"
	@echo "... src/Game.i"
	@echo "... src/Game.s"
	@echo "... src/Gamestate.o"
	@echo "... src/Gamestate.i"
	@echo "... src/Gamestate.s"
	@echo "... src/Generation.o"
	@echo "... src/Generation.i"
	@echo "... src/Generation.s"
	@echo "... src/LavaPit.o"
	@echo "... src/LavaPit.i"
	@echo "... src/LavaPit.s"
	@echo "... src/LavaWall.o"
	@echo "... src/LavaWall.i"
	@echo "... src/LavaWall.s"
	@echo "... src/Menu.o"
	@echo "... src/Menu.i"
	@echo "... src/Menu.s"
	@echo "... src/Object.o"
	@echo "... src/Object.i"
	@echo "... src/Object.s"
	@echo "... src/Obstacle.o"
	@echo "... src/Obstacle.i"
	@echo "... src/Obstacle.s"
	@echo "... src/Physics.o"
	@echo "... src/Physics.i"
	@echo "... src/Physics.s"
	@echo "... src/Platform.o"
	@echo "... src/Platform.i"
	@echo "... src/Platform.s"
	@echo "... src/Player.o"
	@echo "... src/Player.i"
	@echo "... src/Player.s"
	@echo "... src/Rock.o"
	@echo "... src/Rock.i"
	@echo "... src/Rock.s"
	@echo "... src/RockPlatform.o"
	@echo "... src/RockPlatform.i"
	@echo "... src/RockPlatform.s"
	@echo "... src/Spikes.o"
	@echo "... src/Spikes.i"
	@echo "... src/Spikes.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

