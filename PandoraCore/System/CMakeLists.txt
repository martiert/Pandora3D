project(PandoraSystem)

include_directories(include)

set(src src/PandoraSet.cpp
        src/PandoraString.cpp
        src/PandoraHashSet.cpp
        src/PandoraHashTable.cpp
        src/PandoraList.cpp
        src/PandoraStack.cpp
        src/PandoraVector.cpp)

add_library(PandoraSystem
    SHARED ${src})
