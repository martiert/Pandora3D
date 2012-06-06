INCLUDE_DIRECTORIES (include)
INCLUDE_DIRECTORIES ("${gtest_SOURCE_DIR}/include")
INCLUDE_DIRECTORIES ("${Math_SOURCE_DIR}/include")
INCLUDE_DIRECTORIES ("${Physics_SOURCE_DIR}/include")

SET (src
    src/particle-tests.cpp
    src/test-helpers.cpp
    )

ADD_EXECUTABLE (PhysicsTests ${src})
TARGET_LINK_LIBRARIES (PhysicsTests gtest gtest_main Physics Math)

ADD_TEST (PhysicsTests ${CMAKE_BINARY_DIR}/bin/PhysicsTests)
