cmake_minimum_required(VERSION 3.10.0)
project(lab3 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(lab3
    main.cpp
    src/point.cpp
    src/array.cpp
    src/figure.cpp
    src/octagon.cpp
    src/triangle.cpp
    src/square.cpp
)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests
    tests/tests.cpp
    src/point.cpp
    src/array.cpp
    src/figure.cpp
    src/octagon.cpp
    src/triangle.cpp
    src/square.cpp
)

target_link_libraries(tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)