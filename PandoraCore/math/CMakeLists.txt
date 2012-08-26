project (math)
cmake_minimum_required (VERSION 2.6.3)

if (NOT EXECUTABLE_OUTPUT_PATH)
  set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
endif (NOT EXECUTABLE_OUTPUT_PATH)

if (NOT LIBRARY_OUTPUT_PATH)
  set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
endif (NOT LIBRARY_OUTPUT_PATH)

set (PANDORA_MATH_DIR ${CMAKE_CURRENT_SOURCE_DIR})

include (CheckIncludeFiles)

configure_file("${PANDORA_MATH_DIR}/include/config.h.in" "${CMAKE_CURRENT_BINARY_DIR}/include/config.h")

# include own directories
include_directories (include ${CMAKE_CURRENT_BINARY_DIR}/include)

set (math_src
  src/vector2.cpp
  src/vector3.cpp
  src/vector4.cpp
  src/matrix2.cpp
  src/matrix3.cpp
  src/matrix4.cpp
  src/quaternion.cpp
  )

set (math_headers
  include/vector2.h
  include/vector3.h
  include/vector4.h
  include/matrix2.h
  include/matrix3.h
  include/matrix4.h
  include/quaternion.h
  )

add_library (math SHARED ${math_src})

if (NOT WIN32)
  target_link_libraries (math m)
endif (NOT WIN32)

install (TARGETS math DESTINATION lib)
install (FILES ${math_headers} DESTINATION include/pandora/math)

add_subdirectory (tests)
