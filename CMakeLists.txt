cmake_minimum_required(VERSION 3.14 FATAL_ERROR) # Set the minimum required version of CMake

project(kiwicpp VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library target
add_library(
  ${PROJECT_NAME}
  INTERFACE
)

target_include_directories(
  ${PROJECT_NAME}
  INTERFACE
  "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:include>"
)


# Optional builds
option(BUILD_EXAMPLES "Build examples" ON)
option(BUILD_TESTS "Build tests" ON)
option(BENCHMARK "Build with benchmark mode" OFF)

# Benchmark mode
if(BENCHMARK)
    target_compile_definitions(${PROJECT_NAME} PRIVATE BENCHMARK_MODE)
endif()

# Examples
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# Tests
if(BUILD_TESTS)
    # Fetch GoogleTest
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG "v1.15.2"
        GIT_PROGRESS TRUE
    )
    FetchContent_MakeAvailable(googletest)
    enable_testing()
    add_subdirectory(tests)
endif()
