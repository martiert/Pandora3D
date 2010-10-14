PROJECT(MATHTESTS)

IF(NOT LIBRARY_OUTPUT_PATH)
    SET(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
ENDIF(NOT LIBRARY_OUTPUT_PATH)

IF(NOT EXECUTABLE_OUTPUT_PATH)
    SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
ENDIF(NOT EXECUTABLE_OUTPUT_PATH)

SET(src src/testRunner.cpp
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
SET(Boost_USE_STATIC_LIBS ON)
SET(Boost_USE_MULTITHREADED ON)
FIND_PACKAGE(Boost 1.36.0 COMPONENTS unit_test_framework REQUIRED)

INCLUDE_DIRECTORIES(include ${Boost_INCLUDE_DIR})
LINK_DIRECTORIES(${Boost_LIBRARIES} ${LIBRARY_OUTPUT_PATH})

#Build link and make as test
ADD_EXECUTABLE(MathTests ${src})
ADD_DEPENDENCIES(MathTests PandoraMath)
TARGET_LINK_LIBRARIES(MathTests ${Boost_LIBRARIES} PandoraMath)

#ADD_TEST(MathTests ${EXECUTABLE_OUTPUT_PATH}/MathTests)
