#Main CmakeLists.txt file

project(PandoraCore)

include(PrecompiledHeader)

set (HEADER_FILES
        include/PandoraMath.h
        include/PandoraVector2.h
        include/PandoraVector3.h
        include/PandoraVector4.h
        include/PandoraMatrix2.h
        include/PandoraMatrix3.h
        include/PandoraMatrix4.h
        include/PandoraQuat.h
        include/PandoraSystem.h
        include/PandoraList.h
        include/PandoraSet.h
        include/PandoraStack.h
        include/PandoraSingleton.h
        include/PandoraString.h
        include/PandoraVector.h
        include/PandoraHashtable.h
)

set (SOURCE_FILES
        src/PandoraMath.cpp
        src/PandoraVector2.cpp
        src/PandoraVector3.cpp
        src/PandoraVector4.cpp
        src/PandoraMatrix2.cpp
        src/PandoraMatrix3.cpp
        src/PandoraMatrix4.cpp
        src/PandoraQuat.cpp
        src/PandoraSystem.cpp
        src/PandoraList.cpp
        src/PandoraVector.cpp
        src/PandoraSet.cpp
        src/PandoraStack.cpp
        src/PandoraString.cpp
        src/PandoraHashtable.cpp
)
