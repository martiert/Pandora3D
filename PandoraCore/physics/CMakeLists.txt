PROJECT (PHYSICS)
CMAKE_MINIMUM_REQUIRED (VERSION 2.6.3)

IF (NOT EXECUTABLE_OUTPUT_PATH)
  SET (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
ENDIF (NOT EXECUTABLE_OUTPUT_PATH)

IF (NOT LIBRARY_OUTPUT_PATH)
  SET (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
ENDIF (NOT LIBRARY_OUTPUT_PATH)

SET (PANDORA_PHYSICS_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# include own directories
INCLUDE_DIRECTORIES (include)
INCLUDE_DIRECTORIES ("${Math_SOURCE_DIR}/include")

SET (Physics_src
  )

ADD_LIBRARY (Physics SHARED ${Physics_src})
TARGET_LINK_LIBRARIES (Physics Math)

ADD_SUBDIRECTORY (tests)