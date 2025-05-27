cmake_minimum_required(VERSION 3.16)
project(SampleGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Если SampleGame и Engine на одном уровне, то:
# add_subdirectory(../Engine Engine_build)  # если собираешь из корня, не отсюда!

add_executable(SampleGame src/main.cpp)

# Указать публичные инклюды DreamEngine (CMake это сделает автоматически через target_link_libraries)
target_link_libraries(SampleGame PRIVATE DreamEngine)
