# Engine build script
add_library(DreamEngine STATIC
        src/Engine.cpp
        src/core/logger/LogManager.cpp
        src/core/logger/Logger.cpp
        src/core/logger/ConsoleLogger.cpp
        src/core/timer/TimeUtils.cpp
        src/core/timer/Timer.cpp
        src/core/timer/TimerManager.cpp
        src/core/alloc/Allocator.cpp
        src/core/alloc/MallocAllocator.cpp
        src/core/alloc/ArenaAllocator.cpp
)

target_include_directories(DreamEngine PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Optionally link third-party libraries here
# target_link_libraries(DreamEngine ...)
