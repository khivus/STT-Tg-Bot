#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "upb::upb" for configuration "Release"
set_property(TARGET upb::upb APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(upb::upb PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libupb.a"
  )

list(APPEND _cmake_import_check_targets upb::upb )
list(APPEND _cmake_import_check_files_for_upb::upb "${_IMPORT_PREFIX}/lib/libupb.a" )

# Import target "upb::utf8_range" for configuration "Release"
set_property(TARGET upb::utf8_range APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(upb::utf8_range PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libupb_utf8_range.a"
  )

list(APPEND _cmake_import_check_targets upb::utf8_range )
list(APPEND _cmake_import_check_files_for_upb::utf8_range "${_IMPORT_PREFIX}/lib/libupb_utf8_range.a" )

# Import target "upb::fastdecode" for configuration "Release"
set_property(TARGET upb::fastdecode APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(upb::fastdecode PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libupb_fastdecode.a"
  )

list(APPEND _cmake_import_check_targets upb::fastdecode )
list(APPEND _cmake_import_check_files_for_upb::fastdecode "${_IMPORT_PREFIX}/lib/libupb_fastdecode.a" )

# Import target "upb::json" for configuration "Release"
set_property(TARGET upb::json APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(upb::json PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libupb_json.a"
  )

list(APPEND _cmake_import_check_targets upb::json )
list(APPEND _cmake_import_check_files_for_upb::json "${_IMPORT_PREFIX}/lib/libupb_json.a" )

# Import target "upb::descriptor_upb_proto" for configuration "Release"
set_property(TARGET upb::descriptor_upb_proto APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(upb::descriptor_upb_proto PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libdescriptor_upb_proto.a"
  )

list(APPEND _cmake_import_check_targets upb::descriptor_upb_proto )
list(APPEND _cmake_import_check_files_for_upb::descriptor_upb_proto "${_IMPORT_PREFIX}/lib/libdescriptor_upb_proto.a" )

# Import target "upb::reflection" for configuration "Release"
set_property(TARGET upb::reflection APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(upb::reflection PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libupb_reflection.a"
  )

list(APPEND _cmake_import_check_targets upb::reflection )
list(APPEND _cmake_import_check_files_for_upb::reflection "${_IMPORT_PREFIX}/lib/libupb_reflection.a" )

# Import target "upb::textformat" for configuration "Release"
set_property(TARGET upb::textformat APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(upb::textformat PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libupb_textformat.a"
  )

list(APPEND _cmake_import_check_targets upb::textformat )
list(APPEND _cmake_import_check_files_for_upb::textformat "${_IMPORT_PREFIX}/lib/libupb_textformat.a" )

# Import target "upb::mini_table" for configuration "Release"
set_property(TARGET upb::mini_table APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(upb::mini_table PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libupb_mini_table.a"
  )

list(APPEND _cmake_import_check_targets upb::mini_table )
list(APPEND _cmake_import_check_files_for_upb::mini_table "${_IMPORT_PREFIX}/lib/libupb_mini_table.a" )

# Import target "upb::extension_registry" for configuration "Release"
set_property(TARGET upb::extension_registry APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(upb::extension_registry PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libupb_extension_registry.a"
  )

list(APPEND _cmake_import_check_targets upb::extension_registry )
list(APPEND _cmake_import_check_files_for_upb::extension_registry "${_IMPORT_PREFIX}/lib/libupb_extension_registry.a" )

# Import target "upb::collections" for configuration "Release"
set_property(TARGET upb::collections APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(upb::collections PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libupb_collections.a"
  )

list(APPEND _cmake_import_check_targets upb::collections )
list(APPEND _cmake_import_check_files_for_upb::collections "${_IMPORT_PREFIX}/lib/libupb_collections.a" )

# Import target "upb::protoc-gen-upb" for configuration "Release"
set_property(TARGET upb::protoc-gen-upb APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(upb::protoc-gen-upb PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/upb/protoc-gen-upb"
  )

list(APPEND _cmake_import_check_targets upb::protoc-gen-upb )
list(APPEND _cmake_import_check_files_for_upb::protoc-gen-upb "${_IMPORT_PREFIX}/tools/upb/protoc-gen-upb" )

# Import target "upb::protoc-gen-upbdefs" for configuration "Release"
set_property(TARGET upb::protoc-gen-upbdefs APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(upb::protoc-gen-upbdefs PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/tools/upb/protoc-gen-upbdefs"
  )

list(APPEND _cmake_import_check_targets upb::protoc-gen-upbdefs )
list(APPEND _cmake_import_check_files_for_upb::protoc-gen-upbdefs "${_IMPORT_PREFIX}/tools/upb/protoc-gen-upbdefs" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
