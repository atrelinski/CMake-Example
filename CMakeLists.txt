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


#add_custom_target(BUNDLE COMMAND ${CMAKE_COMMAND} -E touch "doxygen$<CONFIGURATION>.stamp")
#


#add_custom_command( OUTPUT bund5.stamp
#  COMMAND ${CMAKE_COMMAND}
#    # this one must be written as is, DO NOT put the `$<CONFIGURATION>` inside a variable!
#    -D "CPACK_PACKAGE_FILE_NAME=KKLL-$<CONFIGURATION>-LLKK"
##    -D "CPACK_BUNDLE_TEMPLATE_CONFIG_FILE=${CPACK_BUNDLE_TEMPLATE_CONFIG_FILE}"
##    -D "CPACK_BUNDLE_OUTPUT_CONFIG_FILE=${CPACK_BUNDLE_OUTPUT_CONFIG_FILE}"
##    # this one must be after all `-D`s
#    -P "${CMAKE_BINARY_DIR}/CPackCon.cmake" 
#	VERBATIM
#	)


#add_custom_command(
#    OUTPUT
#        docs/doxygen.stamp
#    DEPENDS
#        docs/Doxyfile
#    COMMAND
#        doxygen docs/Doxyfile
#    COMMAND
#        cmake -E touch docs/doxygen.stamp
#    COMMENT
#        "Generating API documentation with Doxygen"
#    VERBATIM
#    )
#
#add_custom_target(bundle
#  COMMAND ${CMAKE_COMMAND}
#    # this one must be written as is, DO NOT put the `$<CONFIGURATION>` inside a variable!
#    -D "CPACK_PACKAGE_FILE_NAME=${PROJECT_NAME}-${CPACK_PACKAGE_VERSION}-win32-$<CONFIGURATION>"
#    -D "CPACK_BUNDLE_TEMPLATE_CONFIG_FILE=${CPACK_BUNDLE_TEMPLATE_CONFIG_FILE}"
#    -D "CPACK_BUNDLE_OUTPUT_CONFIG_FILE=${CPACK_BUNDLE_OUTPUT_CONFIG_FILE}"
#    # this one must be after all `-D`s
#    -P "${CMAKE_CURRENT_LIST_DIR}/CPackMakeConfig.cmake"
#  COMMAND "${CMAKE_CPACK_COMMAND}" 
#    "-G" "NSIS"
#    "-C" "$<CONFIGURATION>"
#    "--config" "${CPACK_OUTPUT_CONFIG_FILE}")


# Add installer (it is called CPack) which brings all files together (.exe, .lib, .dll, and .h) and put into one file 
include(InstallRequiredSystemLibraries)
set(CPACK_GENERATOR "ZIP")
#set(CPACK_PACKAGE_FILE_NAME "ZZZ_${CPACK_PACKAGE_VERSION}_ZZZ") # dziala w CPackPropterties.cmake i w CMakeLists.txt
#set(CPACK_PACKAGE_FILE_NAME "WWW_$<CONFIG>_WWW") # NIE dziala w CPackPropterties.cmake ani w CMakeLists.txt
#set(CPACK_PACKAGE_FILE_NAME "PPP_$<CONFIGURATION>_PPP") # NIE dziala w CPackPropterties.cmake ani w CMakeLists.txt
#SET(CPACK_PACKAGE_FILE_NAME "TT_${CMAKE_BUILD_TYPE}_TT") # NIE dziala w CPackPropterties.cmake ani w CMakeLists.txt
#SET(CPACK_PACKAGE_FILE_NAME "YY_${BUILD_TYPE}_YY") # NIE dziala w CPackPropterties.cmake ani w CMakeLists.txt


##<CONFIG>_POSTFIX  # NIE dziala w CPackPropterties.cmake ani w CMakeLists.txt
#SET(DEBUG_POSTFIX "DDD")
#SET(Debug_POSTFIX "DDD")
#SET(debug_POSTFIX "DDD")
#SET(RELEASE_POSTFIX "RRR")
#SET(Release_POSTFIX "RRR")
#SET(release_POSTFIX "RRR")
#
##CMAKE_<CONFIG>_POSTFIX # NIE dziala w CPackPropterties.cmake ani w CMakeLists.txt
#SET(CMAKE_DEBUG_POSTFIX "DDD")
#SET(CMAKE_Debug_POSTFIX "DDD")
#SET(CMAKE_debug_POSTFIX "DDD")
#SET(CMAKE_RELEASE_POSTFIX "RRR")
#SET(CMAKE_Release_POSTFIX "RRR")
#SET(CMAKE_release_POSTFIX "RRR")




#SET(CPACK_PACKAGE_FILE_NAME "YY-${BUILD_TYPE}YY") # NIE dziala w CPackPropterties.cmake ani w CMakeLists.txt


set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR ${Example_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${Example_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${Example_VERSION_PATCH})
include(CPack)

#get_cmake_property(_variableNames VARIABLES)
#list (SORT _variableNames)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach() 


add_custom_target(bund2 ALL
  COMMAND ${CMAKE_COMMAND}
    # this one must be written as is, DO NOT put the `$<CONFIGURATION>` inside a variable!
    -D "CPACK_PACKAGE_FILE_NAME=KK-$<CONFIGURATION>-KK"
##    -D "CPACK_BUNDLE_TEMPLATE_CONFIG_FILE=${CPACK_BUNDLE_TEMPLATE_CONFIG_FILE}"
##    -D "CPACK_BUNDLE_OUTPUT_CONFIG_FILE=${CPACK_BUNDLE_OUTPUT_CONFIG_FILE}"
##    # this one must be after all `-D`s
    -P "${CMAKE_SOURCE_DIR}/CPackCon.cmake")

