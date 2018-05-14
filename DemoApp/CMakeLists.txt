add_executable (Demo main.cpp)


# Demo application require both libraries, so add them
target_link_libraries(Demo
	DLib
	SLib
)


# Point to which directory Demo is copied during installation and packaging
install (TARGETS Demo DESTINATION demo)


