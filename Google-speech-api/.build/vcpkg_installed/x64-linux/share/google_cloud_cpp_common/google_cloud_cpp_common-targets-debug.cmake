#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "google-cloud-cpp::common" for configuration "Debug"
set_property(TARGET google-cloud-cpp::common APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(google-cloud-cpp::common PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/lib/libgoogle_cloud_cpp_common.a"
  )

list(APPEND _cmake_import_check_targets google-cloud-cpp::common )
list(APPEND _cmake_import_check_files_for_google-cloud-cpp::common "${_IMPORT_PREFIX}/debug/lib/libgoogle_cloud_cpp_common.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
