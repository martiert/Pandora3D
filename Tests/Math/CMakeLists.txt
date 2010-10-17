PROJECT(PANDORAMATHTESTS)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.3)

IF(NOT LIBRARY_OUTPUT_PATH)
    SET(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
ENDIF(NOT LIBRARY_OUTPUT_PATH)

IF(NOT EXECUTABLE_OUTPUT_PATH)
    SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
ENDIF(NOT EXECUTABLE_OUTPUT_PATH)

SET(Math_tests_src src/testRunner.cpp
        src/Vector2_test.cpp
#        src/Vector3_test.cpp
#        src/Vector4_test.cpp
#        src/Matrix2_test.cpp
#        src/Matrix3_test.cpp
#        src/Matrix4_test.cpp
#        src/Quaternion_test.cpp
#        src/Math_test.cpp
        )

# Find Boost unit testing
FIND_PACKAGE(Boost REQUIRED COMPONENTS unit_test_framework)

FIND_PATH(PANDORAMATH_INCLUDE_DIR PandoraMath.h PATHS
    ../../PandoraCore/Math/include
    DOC "Path to the directory where PandoraMath.h can be found")
FIND_PATH(PANDORAMATH_LIB_DIR
    NAMES
    libPandoraMath.a
    PandoraMath.lib
    PATHS
    ../../build/lib
    ../../build/lib/Release
    ../../build/lib/Debug
    DOC "Path to directory where the PandoraMath library can be found")

INCLUDE_DIRECTORIES(
    include
    ${PANDORAMATH_INCLUDE_DIR}
    ${Boost_INCLUDE_DIR}
    )
