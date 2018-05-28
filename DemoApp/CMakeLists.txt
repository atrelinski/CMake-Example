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


