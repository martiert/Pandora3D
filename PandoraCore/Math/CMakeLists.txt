PROJECT(PANDORAMATH)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.3)

IF(NOT EXECUTABLE_OUTPUT_PATH)
    SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
ENDIF(NOT EXECUTABLE_OUTPUT_PATH)

IF(NOT LIBRARY_OUTPUT_PATH)
    SET(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
ENDIF(NOT LIBRARY_OUTPUT_PATH)

INCLUDE_DIRECTORIES(include)

SET(Math_src src/PandoraMath.cpp
        src/PandoraVector2.cpp
        src/PandoraVector3.cpp
        src/PandoraVector4.cpp
        src/PandoraMatrix2.cpp
        src/PandoraMatrix3.cpp
        src/PandoraMatrix4.cpp
        src/PandoraQuat.cpp
        )

ADD_LIBRARY(PandoraMath STATIC ${Math_src})

ADD_SUBDIRECTORY(tests)
