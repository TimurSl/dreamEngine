cmake_minimum_required(VERSION 3.20)

project(DreamEngine VERSION 0.1.0)

configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/version.h.in
        ${CMAKE_BINARY_DIR}/version.h
        @ONLY
)
include_directories(${CMAKE_BINARY_DIR})

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Engine
add_subdirectory(Engine)

# Add Editor
add_subdirectory(Editor)

# Add SampleGame
add_subdirectory(SampleGame)
