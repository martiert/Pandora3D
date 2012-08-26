include_directories (include)
include_directories ("${gtest_SOURCE_DIR}/include")
include_directories ("${system_SOURCE_DIR}/include")

set (src
  src/test-runner.cpp
  )

add_executable (systemtests ${src})
target_link_libraries (systemtests gtest gtest_main system)

add_test (systemtests ${CMAKE_BINARY_DIR}/bin/systemtests)
