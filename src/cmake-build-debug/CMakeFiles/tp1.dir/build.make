# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /usr/share/clion-2016.3.4/bin/cmake/bin/cmake

# The command to remove a file.
RM = /usr/share/clion-2016.3.4/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tg/FIUBA/taller/tp1/tp1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tg/FIUBA/taller/tp1/tp1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tp1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tp1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tp1.dir/flags.make

CMakeFiles/tp1.dir/main.c.o: CMakeFiles/tp1.dir/flags.make
CMakeFiles/tp1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tg/FIUBA/taller/tp1/tp1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/tp1.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tp1.dir/main.c.o   -c /home/tg/FIUBA/taller/tp1/tp1/main.c

CMakeFiles/tp1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tp1.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tg/FIUBA/taller/tp1/tp1/main.c > CMakeFiles/tp1.dir/main.c.i

CMakeFiles/tp1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tp1.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tg/FIUBA/taller/tp1/tp1/main.c -o CMakeFiles/tp1.dir/main.c.s

CMakeFiles/tp1.dir/main.c.o.requires:

.PHONY : CMakeFiles/tp1.dir/main.c.o.requires

CMakeFiles/tp1.dir/main.c.o.provides: CMakeFiles/tp1.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/tp1.dir/build.make CMakeFiles/tp1.dir/main.c.o.provides.build
.PHONY : CMakeFiles/tp1.dir/main.c.o.provides

CMakeFiles/tp1.dir/main.c.o.provides.build: CMakeFiles/tp1.dir/main.c.o


CMakeFiles/tp1.dir/codon.c.o: CMakeFiles/tp1.dir/flags.make
CMakeFiles/tp1.dir/codon.c.o: ../codon.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tg/FIUBA/taller/tp1/tp1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/tp1.dir/codon.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tp1.dir/codon.c.o   -c /home/tg/FIUBA/taller/tp1/tp1/codon.c

CMakeFiles/tp1.dir/codon.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tp1.dir/codon.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tg/FIUBA/taller/tp1/tp1/codon.c > CMakeFiles/tp1.dir/codon.c.i

CMakeFiles/tp1.dir/codon.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tp1.dir/codon.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tg/FIUBA/taller/tp1/tp1/codon.c -o CMakeFiles/tp1.dir/codon.c.s

CMakeFiles/tp1.dir/codon.c.o.requires:

.PHONY : CMakeFiles/tp1.dir/codon.c.o.requires

CMakeFiles/tp1.dir/codon.c.o.provides: CMakeFiles/tp1.dir/codon.c.o.requires
	$(MAKE) -f CMakeFiles/tp1.dir/build.make CMakeFiles/tp1.dir/codon.c.o.provides.build
.PHONY : CMakeFiles/tp1.dir/codon.c.o.provides

CMakeFiles/tp1.dir/codon.c.o.provides.build: CMakeFiles/tp1.dir/codon.c.o


CMakeFiles/tp1.dir/codigo_genetico.c.o: CMakeFiles/tp1.dir/flags.make
CMakeFiles/tp1.dir/codigo_genetico.c.o: ../codigo_genetico.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tg/FIUBA/taller/tp1/tp1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/tp1.dir/codigo_genetico.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tp1.dir/codigo_genetico.c.o   -c /home/tg/FIUBA/taller/tp1/tp1/codigo_genetico.c

CMakeFiles/tp1.dir/codigo_genetico.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tp1.dir/codigo_genetico.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tg/FIUBA/taller/tp1/tp1/codigo_genetico.c > CMakeFiles/tp1.dir/codigo_genetico.c.i

CMakeFiles/tp1.dir/codigo_genetico.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tp1.dir/codigo_genetico.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tg/FIUBA/taller/tp1/tp1/codigo_genetico.c -o CMakeFiles/tp1.dir/codigo_genetico.c.s

CMakeFiles/tp1.dir/codigo_genetico.c.o.requires:

.PHONY : CMakeFiles/tp1.dir/codigo_genetico.c.o.requires

CMakeFiles/tp1.dir/codigo_genetico.c.o.provides: CMakeFiles/tp1.dir/codigo_genetico.c.o.requires
	$(MAKE) -f CMakeFiles/tp1.dir/build.make CMakeFiles/tp1.dir/codigo_genetico.c.o.provides.build
.PHONY : CMakeFiles/tp1.dir/codigo_genetico.c.o.provides

CMakeFiles/tp1.dir/codigo_genetico.c.o.provides.build: CMakeFiles/tp1.dir/codigo_genetico.c.o


CMakeFiles/tp1.dir/socket.c.o: CMakeFiles/tp1.dir/flags.make
CMakeFiles/tp1.dir/socket.c.o: ../socket.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tg/FIUBA/taller/tp1/tp1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/tp1.dir/socket.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tp1.dir/socket.c.o   -c /home/tg/FIUBA/taller/tp1/tp1/socket.c

CMakeFiles/tp1.dir/socket.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tp1.dir/socket.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tg/FIUBA/taller/tp1/tp1/socket.c > CMakeFiles/tp1.dir/socket.c.i

CMakeFiles/tp1.dir/socket.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tp1.dir/socket.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tg/FIUBA/taller/tp1/tp1/socket.c -o CMakeFiles/tp1.dir/socket.c.s

CMakeFiles/tp1.dir/socket.c.o.requires:

.PHONY : CMakeFiles/tp1.dir/socket.c.o.requires

CMakeFiles/tp1.dir/socket.c.o.provides: CMakeFiles/tp1.dir/socket.c.o.requires
	$(MAKE) -f CMakeFiles/tp1.dir/build.make CMakeFiles/tp1.dir/socket.c.o.provides.build
.PHONY : CMakeFiles/tp1.dir/socket.c.o.provides

CMakeFiles/tp1.dir/socket.c.o.provides.build: CMakeFiles/tp1.dir/socket.c.o


CMakeFiles/tp1.dir/servidor.c.o: CMakeFiles/tp1.dir/flags.make
CMakeFiles/tp1.dir/servidor.c.o: ../servidor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tg/FIUBA/taller/tp1/tp1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/tp1.dir/servidor.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tp1.dir/servidor.c.o   -c /home/tg/FIUBA/taller/tp1/tp1/servidor.c

CMakeFiles/tp1.dir/servidor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tp1.dir/servidor.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tg/FIUBA/taller/tp1/tp1/servidor.c > CMakeFiles/tp1.dir/servidor.c.i

CMakeFiles/tp1.dir/servidor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tp1.dir/servidor.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tg/FIUBA/taller/tp1/tp1/servidor.c -o CMakeFiles/tp1.dir/servidor.c.s

CMakeFiles/tp1.dir/servidor.c.o.requires:

.PHONY : CMakeFiles/tp1.dir/servidor.c.o.requires

CMakeFiles/tp1.dir/servidor.c.o.provides: CMakeFiles/tp1.dir/servidor.c.o.requires
	$(MAKE) -f CMakeFiles/tp1.dir/build.make CMakeFiles/tp1.dir/servidor.c.o.provides.build
.PHONY : CMakeFiles/tp1.dir/servidor.c.o.provides

CMakeFiles/tp1.dir/servidor.c.o.provides.build: CMakeFiles/tp1.dir/servidor.c.o


CMakeFiles/tp1.dir/cliente.c.o: CMakeFiles/tp1.dir/flags.make
CMakeFiles/tp1.dir/cliente.c.o: ../cliente.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tg/FIUBA/taller/tp1/tp1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/tp1.dir/cliente.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tp1.dir/cliente.c.o   -c /home/tg/FIUBA/taller/tp1/tp1/cliente.c

CMakeFiles/tp1.dir/cliente.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tp1.dir/cliente.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tg/FIUBA/taller/tp1/tp1/cliente.c > CMakeFiles/tp1.dir/cliente.c.i

CMakeFiles/tp1.dir/cliente.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tp1.dir/cliente.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tg/FIUBA/taller/tp1/tp1/cliente.c -o CMakeFiles/tp1.dir/cliente.c.s

CMakeFiles/tp1.dir/cliente.c.o.requires:

.PHONY : CMakeFiles/tp1.dir/cliente.c.o.requires

CMakeFiles/tp1.dir/cliente.c.o.provides: CMakeFiles/tp1.dir/cliente.c.o.requires
	$(MAKE) -f CMakeFiles/tp1.dir/build.make CMakeFiles/tp1.dir/cliente.c.o.provides.build
.PHONY : CMakeFiles/tp1.dir/cliente.c.o.provides

CMakeFiles/tp1.dir/cliente.c.o.provides.build: CMakeFiles/tp1.dir/cliente.c.o


CMakeFiles/tp1.dir/aminoacido.c.o: CMakeFiles/tp1.dir/flags.make
CMakeFiles/tp1.dir/aminoacido.c.o: ../aminoacido.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tg/FIUBA/taller/tp1/tp1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/tp1.dir/aminoacido.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tp1.dir/aminoacido.c.o   -c /home/tg/FIUBA/taller/tp1/tp1/aminoacido.c

CMakeFiles/tp1.dir/aminoacido.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tp1.dir/aminoacido.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tg/FIUBA/taller/tp1/tp1/aminoacido.c > CMakeFiles/tp1.dir/aminoacido.c.i

CMakeFiles/tp1.dir/aminoacido.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tp1.dir/aminoacido.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tg/FIUBA/taller/tp1/tp1/aminoacido.c -o CMakeFiles/tp1.dir/aminoacido.c.s

CMakeFiles/tp1.dir/aminoacido.c.o.requires:

.PHONY : CMakeFiles/tp1.dir/aminoacido.c.o.requires

CMakeFiles/tp1.dir/aminoacido.c.o.provides: CMakeFiles/tp1.dir/aminoacido.c.o.requires
	$(MAKE) -f CMakeFiles/tp1.dir/build.make CMakeFiles/tp1.dir/aminoacido.c.o.provides.build
.PHONY : CMakeFiles/tp1.dir/aminoacido.c.o.provides

CMakeFiles/tp1.dir/aminoacido.c.o.provides.build: CMakeFiles/tp1.dir/aminoacido.c.o


# Object files for target tp1
tp1_OBJECTS = \
"CMakeFiles/tp1.dir/main.c.o" \
"CMakeFiles/tp1.dir/codon.c.o" \
"CMakeFiles/tp1.dir/codigo_genetico.c.o" \
"CMakeFiles/tp1.dir/socket.c.o" \
"CMakeFiles/tp1.dir/servidor.c.o" \
"CMakeFiles/tp1.dir/cliente.c.o" \
"CMakeFiles/tp1.dir/aminoacido.c.o"

# External object files for target tp1
tp1_EXTERNAL_OBJECTS =

tp1: CMakeFiles/tp1.dir/main.c.o
tp1: CMakeFiles/tp1.dir/codon.c.o
tp1: CMakeFiles/tp1.dir/codigo_genetico.c.o
tp1: CMakeFiles/tp1.dir/socket.c.o
tp1: CMakeFiles/tp1.dir/servidor.c.o
tp1: CMakeFiles/tp1.dir/cliente.c.o
tp1: CMakeFiles/tp1.dir/aminoacido.c.o
tp1: CMakeFiles/tp1.dir/build.make
tp1: CMakeFiles/tp1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tg/FIUBA/taller/tp1/tp1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable tp1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tp1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tp1.dir/build: tp1

.PHONY : CMakeFiles/tp1.dir/build

CMakeFiles/tp1.dir/requires: CMakeFiles/tp1.dir/main.c.o.requires
CMakeFiles/tp1.dir/requires: CMakeFiles/tp1.dir/codon.c.o.requires
CMakeFiles/tp1.dir/requires: CMakeFiles/tp1.dir/codigo_genetico.c.o.requires
CMakeFiles/tp1.dir/requires: CMakeFiles/tp1.dir/socket.c.o.requires
CMakeFiles/tp1.dir/requires: CMakeFiles/tp1.dir/servidor.c.o.requires
CMakeFiles/tp1.dir/requires: CMakeFiles/tp1.dir/cliente.c.o.requires
CMakeFiles/tp1.dir/requires: CMakeFiles/tp1.dir/aminoacido.c.o.requires

.PHONY : CMakeFiles/tp1.dir/requires

CMakeFiles/tp1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tp1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tp1.dir/clean

CMakeFiles/tp1.dir/depend:
	cd /home/tg/FIUBA/taller/tp1/tp1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tg/FIUBA/taller/tp1/tp1 /home/tg/FIUBA/taller/tp1/tp1 /home/tg/FIUBA/taller/tp1/tp1/cmake-build-debug /home/tg/FIUBA/taller/tp1/tp1/cmake-build-debug /home/tg/FIUBA/taller/tp1/tp1/cmake-build-debug/CMakeFiles/tp1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tp1.dir/depend
