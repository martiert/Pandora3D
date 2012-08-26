#Main CmakeLists.txt file
project (pandoracore)
cmake_minimum_required (VERSION 2.6.3)

if (MSVC)
  add_definitions (/W4)
else (MSVC)
  add_definitions (-Wall -Wextra -pedantic)
endif (MSVC)

if (NOT LIBRARY_OUTPUT_PATH)
  set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
endif (NOT LIBRARY_OUTPUT_PATH)

if (NOT EXECUTABLE_OUTPUT_PATH)
  set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
endif (NOT EXECUTABLE_OUTPUT_PATH)

add_subdirectory (math)
add_subdirectory (physics)
#add_subdirectory (system)
