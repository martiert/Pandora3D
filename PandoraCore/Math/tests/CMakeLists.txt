PROJECT(MATHTESTS)

IF(NOT LIBRARY_OUTPUT_PATH)
    SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
ENDIF(NOT LIBRARY_OUTPUT_PATH)

IF(NOT EXECUTABLE_OUTPUT_PATH)
    SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin/tests)
ENDIF(NOT EXECUTABLE_OUTPUT_PATH)

SET(src src/testRunner.cpp
#        src/Vector2Test.cpp
#        src/Vector3Test.cpp
#        src/Vector4Test.cpp
#        src/Matrix2Test.cpp
#        src/Matrix3Test.cpp
#        src/Matrix4Test.cpp
#        src/QuaternionTest.cpp
#        src/MathTest.cpp
        )

# Find Boost unit testing
SET(Boost_USE_STATIC_LIBS ON)
SET(Boost_USE_MULTITHREADED ON)
FIND_PACKAGE(Boost 1.36.0 COMPONENTS unit_test_framework REQUIRED)
MESSAGE("${Boost_LIBRARIES}")

# Find our math library
FIND_LIBRARY(PandoraMath PandoraMath ${PROJECT_BINARY_DIR}/lib)

INCLUDE_DIRECTORIES(include ${Boost_INCLUDE_DIR})

#Build link and make as test
ADD_EXECUTABLE(MathTests ${src})
TARGET_LINK_LIBRARIES(MathTests PandoraMath ${Boost_LIBRARIES})
