PROJECT (MATH)
CMAKE_MINIMUM_REQUIRED (VERSION 2.6.3)

IF (NOT EXECUTABLE_OUTPUT_PATH)
  SET (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
ENDIF (NOT EXECUTABLE_OUTPUT_PATH)

IF (NOT LIBRARY_OUTPUT_PATH)
  SET (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
ENDIF (NOT LIBRARY_OUTPUT_PATH)

SET (PANDORA_MATH_DIR ${CMAKE_CURRENT_SOURCE_DIR})

INCLUDE (CheckIncludeFiles)

CONFIGURE_FILE("${PANDORA_MATH_DIR}/include/config.h.in" "${CMAKE_CURRENT_BINARY_DIR}/include/config.h")

# include own directories
INCLUDE_DIRECTORIES (include ${CMAKE_CURRENT_BINARY_DIR}/include)

SET (Math_src
  src/vector2.cpp
  src/vector3.cpp
  src/vector4.cpp
  src/matrix2.cpp
  src/matrix3.cpp
  src/matrix4.cpp
  src/quaternion.cpp
  )

SET (Math_headers
  include/vector2.h
  include/vector3.h
  include/vector4.h
  include/matrix2.h
  include/matrix3.h
  include/matrix4.h
  include/quaternion.h
  )

ADD_LIBRARY (Math SHARED ${Math_src})

IF (NOT WIN32)
  TARGET_LINK_LIBRARIES (Math m)
ENDIF (NOT WIN32)

install (TARGETS Math DESTINATION lib)
install (FILES ${Math_headers} DESTINATION include/pandora/math)

ADD_SUBDIRECTORY (tests)
