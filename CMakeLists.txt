#Top-Level CmakeLists.txt
project (pandora3d CXX)

set (pandora3d_VERSION_MAJOR 0)
set (pamdora3d_VERSION_MINOR 1)

# Needs at least 2.6.3 for ctest support
cmake_minimum_required (VERSION 2.6.3)

set (CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules" CACHE STRING "Path to cmake modules")

if (NOT CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE "Release" CACHE STRING "What kind of build this is" FORCE)
endif (NOT CMAKE_BUILD_TYPE)

if (NOT LIBRARY_OUTPUT_PATH)
  set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
endif (NOT LIBRARY_OUTPUT_PATH)

if (NOT EXECUTABLE_OUTPUT_PATH)
  set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
endif (NOT EXECUTABLE_OUTPUT_PATH)

enable_testing ()
include (CTest)

find_package (CXX11 REQUIRED)

if (NOT CXX11_FOUND)
  message (FATAL_ERROR "Your compiler don't seem to support C++11")
endif (NOT CXX11_FOUND)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX11_FLAGS}")

add_subdirectory (tools)
add_subdirectory (PandoraCore)
