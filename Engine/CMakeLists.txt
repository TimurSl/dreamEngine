# Engine build script
add_library(DreamEngine STATIC
        src/engine_core.cpp
        # add other engine source files here
)

target_include_directories(DreamEngine PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Optionally link third-party libraries here
# target_link_libraries(DreamEngine ...)
