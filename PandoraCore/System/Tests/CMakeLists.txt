INCLUDE_DIRECTORIES (include)
INCLUDE_DIRECTORIES ("${gtest_SOURCE_DIR}/include")
INCLUDE_DIRECTORIES ("${System_SOURCE_DIR}/include")

SET (src
    src/test-runner.cpp
    src/stack-test.cpp
    )

ADD_EXECUTABLE (SystemTests ${src})
TARGET_LINK_LIBRARIES (SystemTests gtest gtest_main System)

ADD_TEST (SystemTests ${CMAKE_BINARY_DIR}/bin/SystemTests)
