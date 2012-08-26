project (system)
cmake_minimum_required (VERSION 2.6.3)

if (NOT EXECUTABLE_OUTPUT_PATH)
  set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
endif (NOT EXECUTABLE_OUTPUT_PATH)

if (NOT LIBRARY_OUTPUT_PATH)
  set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
endif (NOT LIBRARY_OUTPUT_PATH)

set (PANDORA_SYSTEM_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# include own directories
include_directories (include)

set (system_src
  )

add_library (system SHARED ${system_src})

add_subdirectory (tests)
