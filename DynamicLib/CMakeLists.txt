
   
set(MODULE_FILES
	d-hello.cpp
	d-hello.h
	dlib_export.h
)


add_library(DLib SHARED ${MODULE_FILES})


#include(GenerateExportHeader)
#generate_export_header(DLib)


# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories(DLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


# List files that install and/or package should provide.
# Each library should know what it want to distribute,
# which files are internal or intermediate and which are public library export.
install(TARGETS DLib DESTINATION DLib-bin)
install(FILES d-hello.h DESTINATION DLib-include)

# This work but only for install and it is ugly (DLib.dll know nothing about demo.exe).  Doesn't work for run for build directory (F5)
install(TARGETS DLib RUNTIME DESTINATION demo)
