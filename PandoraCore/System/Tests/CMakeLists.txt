INCLUDE_DIRECTORIES (include)

SET (Boost_USE_STATIC_LIBS ON)
FIND_PACKAGE (Boost COMPONENTS unit_test_framework REQUIRED)
INCLUDE_DIRECTORIES (${Boost_INCLUDE_DIRS})

SET (src
  )

ADD_EXECUTABLE (SystemTests ${src})
TARGET_LINK_LIBRARIES (SystemTests ${Boost_LIBRARIES} PandoraSystem)

ADD_TEST (SystemTests ${CMAKE_BINARY_DIR}/bin/SystemTests)
