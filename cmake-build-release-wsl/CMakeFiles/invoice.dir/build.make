# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /mnt/c/Users/macie/Desktop/invoice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/macie/Desktop/invoice/cmake-build-release-wsl

# Include any dependencies generated for this target.
include CMakeFiles/invoice.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/invoice.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/invoice.dir/flags.make

CMakeFiles/invoice.dir/main.c.o: CMakeFiles/invoice.dir/flags.make
CMakeFiles/invoice.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/macie/Desktop/invoice/cmake-build-release-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/invoice.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/invoice.dir/main.c.o   -c /mnt/c/Users/macie/Desktop/invoice/main.c

CMakeFiles/invoice.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/invoice.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/macie/Desktop/invoice/main.c > CMakeFiles/invoice.dir/main.c.i

CMakeFiles/invoice.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/invoice.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/macie/Desktop/invoice/main.c -o CMakeFiles/invoice.dir/main.c.s

CMakeFiles/invoice.dir/structures/Person.c.o: CMakeFiles/invoice.dir/flags.make
CMakeFiles/invoice.dir/structures/Person.c.o: ../structures/Person.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/macie/Desktop/invoice/cmake-build-release-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/invoice.dir/structures/Person.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/invoice.dir/structures/Person.c.o   -c /mnt/c/Users/macie/Desktop/invoice/structures/Person.c

CMakeFiles/invoice.dir/structures/Person.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/invoice.dir/structures/Person.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/macie/Desktop/invoice/structures/Person.c > CMakeFiles/invoice.dir/structures/Person.c.i

CMakeFiles/invoice.dir/structures/Person.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/invoice.dir/structures/Person.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/macie/Desktop/invoice/structures/Person.c -o CMakeFiles/invoice.dir/structures/Person.c.s

CMakeFiles/invoice.dir/structures/Address.c.o: CMakeFiles/invoice.dir/flags.make
CMakeFiles/invoice.dir/structures/Address.c.o: ../structures/Address.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/macie/Desktop/invoice/cmake-build-release-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/invoice.dir/structures/Address.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/invoice.dir/structures/Address.c.o   -c /mnt/c/Users/macie/Desktop/invoice/structures/Address.c

CMakeFiles/invoice.dir/structures/Address.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/invoice.dir/structures/Address.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/macie/Desktop/invoice/structures/Address.c > CMakeFiles/invoice.dir/structures/Address.c.i

CMakeFiles/invoice.dir/structures/Address.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/invoice.dir/structures/Address.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/macie/Desktop/invoice/structures/Address.c -o CMakeFiles/invoice.dir/structures/Address.c.s

CMakeFiles/invoice.dir/structures/Ware.c.o: CMakeFiles/invoice.dir/flags.make
CMakeFiles/invoice.dir/structures/Ware.c.o: ../structures/Ware.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/macie/Desktop/invoice/cmake-build-release-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/invoice.dir/structures/Ware.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/invoice.dir/structures/Ware.c.o   -c /mnt/c/Users/macie/Desktop/invoice/structures/Ware.c

CMakeFiles/invoice.dir/structures/Ware.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/invoice.dir/structures/Ware.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/macie/Desktop/invoice/structures/Ware.c > CMakeFiles/invoice.dir/structures/Ware.c.i

CMakeFiles/invoice.dir/structures/Ware.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/invoice.dir/structures/Ware.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/macie/Desktop/invoice/structures/Ware.c -o CMakeFiles/invoice.dir/structures/Ware.c.s

CMakeFiles/invoice.dir/structures/Invoice.c.o: CMakeFiles/invoice.dir/flags.make
CMakeFiles/invoice.dir/structures/Invoice.c.o: ../structures/Invoice.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/macie/Desktop/invoice/cmake-build-release-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/invoice.dir/structures/Invoice.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/invoice.dir/structures/Invoice.c.o   -c /mnt/c/Users/macie/Desktop/invoice/structures/Invoice.c

CMakeFiles/invoice.dir/structures/Invoice.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/invoice.dir/structures/Invoice.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/macie/Desktop/invoice/structures/Invoice.c > CMakeFiles/invoice.dir/structures/Invoice.c.i

CMakeFiles/invoice.dir/structures/Invoice.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/invoice.dir/structures/Invoice.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/macie/Desktop/invoice/structures/Invoice.c -o CMakeFiles/invoice.dir/structures/Invoice.c.s

CMakeFiles/invoice.dir/functions/utilities.c.o: CMakeFiles/invoice.dir/flags.make
CMakeFiles/invoice.dir/functions/utilities.c.o: ../functions/utilities.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/macie/Desktop/invoice/cmake-build-release-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/invoice.dir/functions/utilities.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/invoice.dir/functions/utilities.c.o   -c /mnt/c/Users/macie/Desktop/invoice/functions/utilities.c

CMakeFiles/invoice.dir/functions/utilities.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/invoice.dir/functions/utilities.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/macie/Desktop/invoice/functions/utilities.c > CMakeFiles/invoice.dir/functions/utilities.c.i

CMakeFiles/invoice.dir/functions/utilities.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/invoice.dir/functions/utilities.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/macie/Desktop/invoice/functions/utilities.c -o CMakeFiles/invoice.dir/functions/utilities.c.s

CMakeFiles/invoice.dir/functions/input.c.o: CMakeFiles/invoice.dir/flags.make
CMakeFiles/invoice.dir/functions/input.c.o: ../functions/input.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/macie/Desktop/invoice/cmake-build-release-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/invoice.dir/functions/input.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/invoice.dir/functions/input.c.o   -c /mnt/c/Users/macie/Desktop/invoice/functions/input.c

CMakeFiles/invoice.dir/functions/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/invoice.dir/functions/input.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/macie/Desktop/invoice/functions/input.c > CMakeFiles/invoice.dir/functions/input.c.i

CMakeFiles/invoice.dir/functions/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/invoice.dir/functions/input.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/macie/Desktop/invoice/functions/input.c -o CMakeFiles/invoice.dir/functions/input.c.s

CMakeFiles/invoice.dir/structures/InvoiceBox.c.o: CMakeFiles/invoice.dir/flags.make
CMakeFiles/invoice.dir/structures/InvoiceBox.c.o: ../structures/InvoiceBox.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/macie/Desktop/invoice/cmake-build-release-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/invoice.dir/structures/InvoiceBox.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/invoice.dir/structures/InvoiceBox.c.o   -c /mnt/c/Users/macie/Desktop/invoice/structures/InvoiceBox.c

CMakeFiles/invoice.dir/structures/InvoiceBox.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/invoice.dir/structures/InvoiceBox.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/macie/Desktop/invoice/structures/InvoiceBox.c > CMakeFiles/invoice.dir/structures/InvoiceBox.c.i

CMakeFiles/invoice.dir/structures/InvoiceBox.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/invoice.dir/structures/InvoiceBox.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/macie/Desktop/invoice/structures/InvoiceBox.c -o CMakeFiles/invoice.dir/structures/InvoiceBox.c.s

CMakeFiles/invoice.dir/functions/output.c.o: CMakeFiles/invoice.dir/flags.make
CMakeFiles/invoice.dir/functions/output.c.o: ../functions/output.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/macie/Desktop/invoice/cmake-build-release-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/invoice.dir/functions/output.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/invoice.dir/functions/output.c.o   -c /mnt/c/Users/macie/Desktop/invoice/functions/output.c

CMakeFiles/invoice.dir/functions/output.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/invoice.dir/functions/output.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/macie/Desktop/invoice/functions/output.c > CMakeFiles/invoice.dir/functions/output.c.i

CMakeFiles/invoice.dir/functions/output.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/invoice.dir/functions/output.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/macie/Desktop/invoice/functions/output.c -o CMakeFiles/invoice.dir/functions/output.c.s

# Object files for target invoice
invoice_OBJECTS = \
"CMakeFiles/invoice.dir/main.c.o" \
"CMakeFiles/invoice.dir/structures/Person.c.o" \
"CMakeFiles/invoice.dir/structures/Address.c.o" \
"CMakeFiles/invoice.dir/structures/Ware.c.o" \
"CMakeFiles/invoice.dir/structures/Invoice.c.o" \
"CMakeFiles/invoice.dir/functions/utilities.c.o" \
"CMakeFiles/invoice.dir/functions/input.c.o" \
"CMakeFiles/invoice.dir/structures/InvoiceBox.c.o" \
"CMakeFiles/invoice.dir/functions/output.c.o"

# External object files for target invoice
invoice_EXTERNAL_OBJECTS =

invoice: CMakeFiles/invoice.dir/main.c.o
invoice: CMakeFiles/invoice.dir/structures/Person.c.o
invoice: CMakeFiles/invoice.dir/structures/Address.c.o
invoice: CMakeFiles/invoice.dir/structures/Ware.c.o
invoice: CMakeFiles/invoice.dir/structures/Invoice.c.o
invoice: CMakeFiles/invoice.dir/functions/utilities.c.o
invoice: CMakeFiles/invoice.dir/functions/input.c.o
invoice: CMakeFiles/invoice.dir/structures/InvoiceBox.c.o
invoice: CMakeFiles/invoice.dir/functions/output.c.o
invoice: CMakeFiles/invoice.dir/build.make
invoice: CMakeFiles/invoice.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/macie/Desktop/invoice/cmake-build-release-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable invoice"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/invoice.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/invoice.dir/build: invoice

.PHONY : CMakeFiles/invoice.dir/build

CMakeFiles/invoice.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/invoice.dir/cmake_clean.cmake
.PHONY : CMakeFiles/invoice.dir/clean

CMakeFiles/invoice.dir/depend:
	cd /mnt/c/Users/macie/Desktop/invoice/cmake-build-release-wsl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/macie/Desktop/invoice /mnt/c/Users/macie/Desktop/invoice /mnt/c/Users/macie/Desktop/invoice/cmake-build-release-wsl /mnt/c/Users/macie/Desktop/invoice/cmake-build-release-wsl /mnt/c/Users/macie/Desktop/invoice/cmake-build-release-wsl/CMakeFiles/invoice.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/invoice.dir/depend

