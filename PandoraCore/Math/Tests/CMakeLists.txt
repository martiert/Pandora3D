INCLUDE_DIRECTORIES (include)

INCLUDE_DIRECTORIES ("${PANDORA_INCLUDE_DIR}/gtest")
INCLUDE_DIRECTORIES ("${PANDORA_INCLUDE_DIR}/Math")

SET (src
    src/vec4-test.cpp
    src/vec3-test.cpp
    src/vec2-test.cpp
    )

ADD_EXECUTABLE (MathTests ${src})
TARGET_LINK_LIBRARIES (MathTests gtest gtest_main Math)

ADD_TEST (MathTests ${CMAKE_BINARY_DIR}/bin/MathTests)
