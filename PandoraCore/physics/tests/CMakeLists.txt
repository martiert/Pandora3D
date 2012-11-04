include_directories(include)
include_directories("${gtest_SOURCE_DIR}/include")
include_directories("${math_SOURCE_DIR}/include")
include_directories("${physics_SOURCE_DIR}/include")

set(src
    src/particle-test-harness.cpp
    src/particle-tests.cpp
    src/particleforce-tests.cpp
    src/test-helpers.cpp
    )

add_executable(physicstests ${src})
target_link_libraries(physicstests gtest gtest_main physics math)

add_test(physicstests ${CMAKE_BINARY_DIR}/bin/physicstests)

install(TARGETS physicstests DESTINATION bin)
