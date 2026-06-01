set(headers
 "${CPP_CUSTOM_SOURCE_DIR}/includes/Allocator.h"
 "${CPP_CUSTOM_SOURCE_DIR}/includes/CAllocator.h"
 "${CPP_CUSTOM_SOURCE_DIR}/includes/LinearAllocator.h"
 "${CPP_CUSTOM_SOURCE_DIR}/includes/StackAllocator.h"
 "${CPP_CUSTOM_SOURCE_DIR}/includes/PoolAllocator.h"
 "${CPP_CUSTOM_SOURCE_DIR}/includes/FreeListAllocator.h"
 "${CPP_CUSTOM_SOURCE_DIR}/includes/FreeTreeAllocator.h"
 "${CPP_CUSTOM_SOURCE_DIR}/includes/BuddyAllocator.h"
 "${CPP_CUSTOM_SOURCE_DIR}/includes/LinkedList.h"
 "${CPP_CUSTOM_SOURCE_DIR}/includes/RBTree.h"
 "${CPP_CUSTOM_SOURCE_DIR}/includes/Utils.h")

add_library(CPP_CUSTOM
   ${headers}
   "CAllocator.cpp"
   "LinearAllocator.cpp"
   "StackAllocator.cpp"
   "PoolAllocator.cpp"
   "FreeListAllocator.cpp"
   "FreeTreeAllocator.cpp"
   "BuddyAllocator.cpp"
   "LinkedList.cpp"
   "RBTree.cpp"
   )

target_include_directories(CPP_CUSTOM PUBLIC
                       $<BUILD_INTERFACE:${CPP_CUSTOM_SOURCE_DIR}/include>
                       $<INSTALL_INTERFACE:${CPP_CUSTOM_INC_INSTALL_DIR}>
        )

set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")

set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(targets_export_name "${PROJECT_NAME}Targets")

include(CMakePackageConfigHelpers)
configure_package_config_file(
 "${CPP_CUSTOM_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
 "${project_config}"
 INSTALL_DESTINATION ${CPP_CUSTOM_CMAKE_CONFIG_INSTALL_DIR})
write_basic_package_version_file("${version_config}" COMPATIBILITY SameMajorVersion)

if (CPP_CUSTOM_ENABLE_INSTALL)
  install(TARGETS CPP_CUSTOM
   EXPORT ${targets_export_name}
   ARCHIVE DESTINATION ${CPP_CUSTOM_ARCHIVE_INSTALL_DIR}
   LIBRARY DESTINATION ${CPP_CUSTOM_LIBRARY_INSTALL_DIR}
   RUNTIME DESTINATION ${CPP_CUSTOM_RUNTIME_INSTALL_DIR}
   FRAMEWORK DESTINATION ${CPP_CUSTOM_FRAMEWORK_INSTALL_DIR})

  install(
  DIRECTORY "${CPP_CUSTOM_SOURCE_DIR}/includes"
  DESTINATION ${CPP_CUSTOM_INC_INSTALL_DIR}
  FILES_MATCHING PATTERN "*.*h")

  install(
      FILES "${project_config}" "${version_config}"
      DESTINATION "${CPP_CUSTOM_CMAKE_CONFIG_INSTALL_DIR}")

  install(
  EXPORT ${targets_export_name}
  DESTINATION ${CPP_CUSTOM_CMAKE_CONFIG_INSTALL_DIR})
endif()
