cmake_minimum_required(VERSION 2.8.11)
project(CMake-Example)


# This project consist of 3 components, each in one directory, so add each of them
add_subdirectory(DynamicLib)
add_subdirectory(StaticLib)
add_subdirectory(DemoApp)


# Below line set Demo as startup application in Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Demo)


# Add installer (it is called CPack) which brings all files together (.exe, .lib, .dll, and .h) and put into one file 
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR 7)
set(CPACK_PACKAGE_VERSION_MINOR 11)
set(CPACK_PACKAGE_VERSION_PATCH 4)
include(CPack)

