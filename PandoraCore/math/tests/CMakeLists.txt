include_directories (include)

include_directories ("${gtest_SOURCE_DIR}/include")
include_directories ("${math_SOURCE_DIR}/include")
include_directories ("include")

set (src
  src/test-helpers.cpp
  src/quaternion-test.cpp
  src/matrix4-test.cpp
  src/matrix3-test.cpp
  src/matrix2-test.cpp
  src/vec4-test.cpp
  src/vec3-test.cpp
  src/vec2-test.cpp
  )

add_executable (mathtests ${src})
target_link_libraries (mathtests gtest gtest_main math)

add_test (mathtests ${CMAKE_BINARY_DIR}/bin/mathtests)

install (TARGETS mathtests DESTINATION bin)
