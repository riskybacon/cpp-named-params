# Require at least version 2.8 of CMake
cmake_minimum_required(VERSION 2.8)

set(PROJ_NAME cpp_named_params)

# The project name. A project can have multiple targets
project(${PROJ_NAME})

# Set CMAKE_MODULE_PATH
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS unit_test_framework system REQUIRED)

set(PROJ_INCLUDE_DIRS
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}
  ${Boost_INCLUDE_DIRS}
)

set(PROJ_LIBRARIES
  ${Boost_LIBRARIES}
)

set(CPP_LANG_FLAGS "-std=c++14")

include(ProjAddExecutable)

add_subdirectory("tests")
