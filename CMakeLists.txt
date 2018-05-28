cmake_minimum_required(VERSION 3.8.2) # 3.8.0 is minimum version that allow Linux remote building and debugging
project(CMake-Example)


# Enforce c++11 standard.
set (CMAKE_CXX_STANDARD 11)


# The version number.
set(Example_VERSION_MAJOR 2)
set(Example_VERSION_MINOR 3)
set(Example_VERSION_PATCH 1)


# This project consist of 3 components, each in one directory, so add each of them
add_subdirectory(DynamicLib)
add_subdirectory(StaticLib)
add_subdirectory(DemoApp)


# USE_FOLDERS group cmake generated projects into one (CMakePredefinedTargets) folder
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Below line set Demo as startup application in Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Demo)


# Add installer (it is called CPack) which brings all files together (.exe, .lib, .dll, and .h) and put into one file 
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR ${Example_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${Example_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${Example_VERSION_PATCH})
include(CPack)

