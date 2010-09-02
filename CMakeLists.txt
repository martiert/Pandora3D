#Top-Level CmakeLists.txt
cmake_minimum_required(VERSION 2.6)

project(Pandora3D)

set(Pandora3D_VERSION_MAJOR 0)
set(Pandora3D_VERSION_MINOR 1)
option(DEBUG "Compile with debugging symbols" OFF)

add_subdirectory(PandoraCore)
