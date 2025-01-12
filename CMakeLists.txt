cmake_minimum_required(VERSION 3.26)
project(MillitaryPolygon)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("Headers" "Libraries")

file(GLOB_RECURSE SOURCES "Sources/*.cpp")
add_executable(MillitaryPolygon ${SOURCES})

add_custom_command(
        TARGET MillitaryPolygon POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Shaders
        ${CMAKE_BINARY_DIR}/Shaders
)

add_custom_command(
        TARGET MillitaryPolygon POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/OBJ
        ${CMAKE_BINARY_DIR}/OBJ
)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

target_link_libraries(MillitaryPolygon OpenGL::GL GLEW::GLEW glfw glm::glm)
