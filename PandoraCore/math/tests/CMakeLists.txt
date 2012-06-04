INCLUDE_DIRECTORIES (include)

INCLUDE_DIRECTORIES ("${gtest_SOURCE_DIR}/include")
INCLUDE_DIRECTORIES ("${Math_SOURCE_DIR}/include")
INCLUDE_DIRECTORIES ("include")

SET (src
    src/test-helpers.cpp
    src/quaternion-test.cpp
    src/matrix4-test.cpp
    src/matrix3-test.cpp
    src/matrix2-test.cpp
    src/vec4-test.cpp
    src/vec3-test.cpp
    src/vec2-test.cpp
    )

ADD_EXECUTABLE (MathTests ${src})
TARGET_LINK_LIBRARIES (MathTests gtest gtest_main Math)

ADD_TEST (MathTests ${CMAKE_BINARY_DIR}/bin/MathTests)
