project(physics)
cmake_minimum_required(VERSION 2.6.3)

if (NOT EXECUTABLE_OUTPUT_PATH)
  set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
endif (NOT EXECUTABLE_OUTPUT_PATH)

if (NOT LIBRARY_OUTPUT_PATH)
  set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
endif (NOT LIBRARY_OUTPUT_PATH)

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/include/config.h.in" "${CMAKE_CURRENT_BINARY_DIR}/include/config.h")

# include own directories
include_directories(include ${CMAKE_CURRENT_BINARY_DIR}/include)

# include math
include_directories("${math_SOURCE_DIR}/include")

set(physics_src
    src/particle.cpp
    src/particleforceregistry.cpp
    src/particlespring.cpp
    )

set(physics_headers
    include/particle.h
    include/particleforce.h
    include/particlespring.h
    include/particleforceregistry.h
    ${CMAKE_CURRENT_BINARY_DIR}/include/config.h
    )

add_library(physics SHARED ${physics_src})
target_link_libraries(physics math)

install(TARGETS physics DESTINATION lib)
install(FILES ${physics_headers} DESTINATION include/pandora/physics)

add_subdirectory(tests)
