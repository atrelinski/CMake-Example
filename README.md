# This CMake Example

This is simple CMake Example.

It doesn't contain any wise C++ code, it shows how to use CMake, in particular:
- create Static library (StaticLib.lib)
- create Dynamic library (DynamicLib.dll)
- provide demo application which use both libraries (Demo.exe)
- Install feature, which install all 3 components (Demo.exe, StaticLib.lib, DynamicLib.dll and headers) on machine where CMake Install is executed (CMake Install)
- Installation Package (single file (.exe, .7z, .zip etc.)) that contain above components, so program could be distributed and installed on other machines (CPack)


# To Do:
- Source Package (to distribute sources)
- GoogleTests integration (to test StaticLib and DynamicLib code)
