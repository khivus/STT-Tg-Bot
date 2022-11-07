#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "google-cloud-cpp::speech" for configuration "Debug"
set_property(TARGET google-cloud-cpp::speech APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(google-cloud-cpp::speech PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/lib/libgoogle_cloud_cpp_speech.a"
  )

list(APPEND _cmake_import_check_targets google-cloud-cpp::speech )
list(APPEND _cmake_import_check_files_for_google-cloud-cpp::speech "${_IMPORT_PREFIX}/debug/lib/libgoogle_cloud_cpp_speech.a" )

# Import target "google-cloud-cpp::speech_protos" for configuration "Debug"
set_property(TARGET google-cloud-cpp::speech_protos APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(google-cloud-cpp::speech_protos PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/lib/libgoogle_cloud_cpp_speech_protos.a"
  )

list(APPEND _cmake_import_check_targets google-cloud-cpp::speech_protos )
list(APPEND _cmake_import_check_files_for_google-cloud-cpp::speech_protos "${_IMPORT_PREFIX}/debug/lib/libgoogle_cloud_cpp_speech_protos.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
