#Main CmakeLists.txt file

project(PandoraCore)

add_subdirectory(Math)
add_subdirectory(System)

add_library(Pandora SHARED main.cpp)
target_link_libraries(Pandora PandoraMath)
target_link_libraries(Pandora PandoraSystem)
