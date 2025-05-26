# Editor build script
add_executable(DreamEngineEditor
        src/editor_main.cpp
        # add other editor source files here
)

target_include_directories(DreamEngineEditor PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/Engine/include
        ${CMAKE_BINARY_DIR}
)

target_link_libraries(DreamEngineEditor PRIVATE DreamEngine)
