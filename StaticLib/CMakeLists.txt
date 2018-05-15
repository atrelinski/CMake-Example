

set(MODULE_FILES
	s-hello.cpp
	s-hello.h
)


add_library(SLib STATIC ${MODULE_FILES})


# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories(SLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# List files that install and/or package should provide.
# Each library should know what it want to distribute,
# which files are internal or intermediate and which are public library export.
install(TARGETS SLib DESTINATION SLib-bin)
install(FILES s-hello.h DESTINATION SLib-include)
