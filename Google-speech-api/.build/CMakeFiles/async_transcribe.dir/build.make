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
CMAKE_SOURCE_DIR = /mnt/c/Users/Khivus/Documents/Progs/exmp/cpp-samples/speech/api

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Khivus/Documents/Progs/exmp/cpp-samples/speech/api/.build

# Include any dependencies generated for this target.
include CMakeFiles/async_transcribe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/async_transcribe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/async_transcribe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/async_transcribe.dir/flags.make

CMakeFiles/async_transcribe.dir/async_transcribe.cc.o: CMakeFiles/async_transcribe.dir/flags.make
CMakeFiles/async_transcribe.dir/async_transcribe.cc.o: ../async_transcribe.cc
CMakeFiles/async_transcribe.dir/async_transcribe.cc.o: CMakeFiles/async_transcribe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Khivus/Documents/Progs/exmp/cpp-samples/speech/api/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/async_transcribe.dir/async_transcribe.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/async_transcribe.dir/async_transcribe.cc.o -MF CMakeFiles/async_transcribe.dir/async_transcribe.cc.o.d -o CMakeFiles/async_transcribe.dir/async_transcribe.cc.o -c /mnt/c/Users/Khivus/Documents/Progs/exmp/cpp-samples/speech/api/async_transcribe.cc

CMakeFiles/async_transcribe.dir/async_transcribe.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/async_transcribe.dir/async_transcribe.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Khivus/Documents/Progs/exmp/cpp-samples/speech/api/async_transcribe.cc > CMakeFiles/async_transcribe.dir/async_transcribe.cc.i

CMakeFiles/async_transcribe.dir/async_transcribe.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/async_transcribe.dir/async_transcribe.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Khivus/Documents/Progs/exmp/cpp-samples/speech/api/async_transcribe.cc -o CMakeFiles/async_transcribe.dir/async_transcribe.cc.s

# Object files for target async_transcribe
async_transcribe_OBJECTS = \
"CMakeFiles/async_transcribe.dir/async_transcribe.cc.o"

# External object files for target async_transcribe
async_transcribe_EXTERNAL_OBJECTS =

async_transcribe: CMakeFiles/async_transcribe.dir/async_transcribe.cc.o
async_transcribe: CMakeFiles/async_transcribe.dir/build.make
async_transcribe: libparse_arguments.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgoogle_cloud_cpp_speech.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libboost_program_options.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgoogle_cloud_cpp_cloud_speech_protos.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgoogle_cloud_cpp_grpc_utils.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgoogle_cloud_cpp_iam_protos.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgoogle_cloud_cpp_iam_v1_iam_policy_protos.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgoogle_cloud_cpp_iam_v1_options_protos.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgoogle_cloud_cpp_iam_v1_policy_protos.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgoogle_cloud_cpp_type_expr_protos.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgoogle_cloud_cpp_common.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgoogle_cloud_cpp_speech_protos.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgoogle_cloud_cpp_api_field_behavior_protos.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgoogle_cloud_cpp_api_resource_protos.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgoogle_cloud_cpp_longrunning_operations_protos.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgoogle_cloud_cpp_api_annotations_protos.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgoogle_cloud_cpp_api_http_protos.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgoogle_cloud_cpp_api_client_protos.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgoogle_cloud_cpp_rpc_status_protos.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgoogle_cloud_cpp_rpc_error_details_protos.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgrpc++.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgrpc.a
async_transcribe: vcpkg_installed/x64-linux/lib/libz.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libcares.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libaddress_sorting.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libre2.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_raw_hash_set.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_hashtablez_sampler.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_hash.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_city.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_low_level_hash.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_statusor.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libgpr.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_bad_variant_access.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libupb_json.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libupb_textformat.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libupb_reflection.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libupb_collections.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libupb_mini_table.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libupb.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libupb_fastdecode.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libupb_utf8_range.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libupb_extension_registry.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libdescriptor_upb_proto.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_status.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_strerror.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_random_distributions.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_random_seed_sequences.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_random_internal_pool_urbg.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_random_internal_randen.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_random_internal_randen_hwaes.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_random_internal_randen_hwaes_impl.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_random_internal_randen_slow.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_random_internal_platform.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_random_internal_seed_material.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_random_seed_gen_exception.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_cord.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_bad_optional_access.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_cordz_info.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_cord_internal.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_cordz_functions.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_exponential_biased.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_cordz_handle.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_str_format_internal.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_synchronization.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_stacktrace.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_symbolize.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_debugging_internal.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_demangle_internal.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_graphcycles_internal.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_time.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_civil_time.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_strings.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_int128.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_throw_delegate.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_strings_internal.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_time_zone.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_malloc_internal.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_base.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_spinlock_wait.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_raw_logging_internal.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libabsl_log_severity.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libssl.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libcrypto.a
async_transcribe: vcpkg_installed/x64-linux/debug/lib/libprotobufd.a
async_transcribe: CMakeFiles/async_transcribe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Khivus/Documents/Progs/exmp/cpp-samples/speech/api/.build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable async_transcribe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/async_transcribe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/async_transcribe.dir/build: async_transcribe
.PHONY : CMakeFiles/async_transcribe.dir/build

CMakeFiles/async_transcribe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/async_transcribe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/async_transcribe.dir/clean

CMakeFiles/async_transcribe.dir/depend:
	cd /mnt/c/Users/Khivus/Documents/Progs/exmp/cpp-samples/speech/api/.build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Khivus/Documents/Progs/exmp/cpp-samples/speech/api /mnt/c/Users/Khivus/Documents/Progs/exmp/cpp-samples/speech/api /mnt/c/Users/Khivus/Documents/Progs/exmp/cpp-samples/speech/api/.build /mnt/c/Users/Khivus/Documents/Progs/exmp/cpp-samples/speech/api/.build /mnt/c/Users/Khivus/Documents/Progs/exmp/cpp-samples/speech/api/.build/CMakeFiles/async_transcribe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/async_transcribe.dir/depend
