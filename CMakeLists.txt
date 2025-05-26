cmake_minimum_required(VERSION 3.20)
project(DreamEngine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Engine
add_subdirectory(Engine)

# Add Editor
add_subdirectory(Editor)
