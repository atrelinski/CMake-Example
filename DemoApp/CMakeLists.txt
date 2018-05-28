# Pass information about version to C++ code through header
#    that will be supplemented by cmake.
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/version.h.in"
    "${CMAKE_CURRENT_BINARY_DIR}/version.h"
)

# version.h file is in output directory.
# Add the binary tree directory to find the version.h file
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(Demo main.cpp version.h)



# Demo application require both libraries, so add them
target_link_libraries(Demo
	DLib
	SLib
)


# Point to which directory Demo is copied during installation and packaging
install(TARGETS Demo DESTINATION demo)


# Below doesn't work!
#install(TARGETS Demo EXPORT DLib DESTINATION demo)
#install(EXPORT DLib DESTINATION dddd)

# Below doesn't work!    variations also doesn't work becasue path is relative to sources
#install(TARGETS ../DLib-bin/DLib DESTINATION demo)

# Below work but leads to nowhere
#install(FILES ../License.txt DESTINATION demo)
