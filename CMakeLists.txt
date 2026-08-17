cmake_minimum_required(VERSION 3.10)

project (CozyGameEngineProject)
set (PROJECT_SOURCE_FILES
    src/main.cpp
    src/textures/stb/stb_image.cpp
)

include_directories(src)
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})

# Provide project source dir to the compiler so runtime can locate shader files
target_compile_definitions(${PROJECT_NAME} PRIVATE PROJECT_SOURCE_DIR="${CMAKE_SOURCE_DIR}")

add_subdirectory(thirdparty/glfw-3.4 "${CMAKE_CURRENT_BINARY_DIR}/glfw_build")
include_directories(thirdparty/glfw-3.4/include)
include_directories(src/textures/stb)

set(BUILD_UTILS OFF CACHE BOOL "utilities" FORCE)
add_subdirectory(thirdparty/glew/build/cmake "${CMAKE_CURRENT_BINARY_DIR}/glew_build")
include_directories(thirdparty/glew/include)
include_directories(thirdparty)
set_property(TARGET glew_s PROPERTY FOLDER GLEW)
set_property(TARGET glew   PROPERTY FOLDER GLEW)

# Link all thirdparty libraries
target_link_libraries(${PROJECT_NAME} 
    glfw 
    glew_s
)
