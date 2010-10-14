PROJECT(PANDORAMATH)

IF(NOT LIBRARY_OUTPUT_PATH)
    SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
ENDIF(NOT LIBRARY_OUTPUT_PATH)

INCLUDE_DIRECTORIES(include)

SET(src src/PandoraMath.cpp
        src/PandoraVector2.cpp
        src/PandoraVector3.cpp
        src/PandoraVector4.cpp
        src/PandoraMatrix2.cpp
        src/PandoraMatrix3.cpp
        src/PandoraMatrix4.cpp
        src/PandoraQuat.cpp)

ADD_LIBRARY(PandoraMath STATIC ${src})

ADD_SUBDIRECTORY(tests)
