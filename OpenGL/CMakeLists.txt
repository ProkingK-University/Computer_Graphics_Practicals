cmake_minimum_required(VERSION 3.5)
project(my_opengl_project VERSION 0.1.0 LANGUAGES C)
cmake_policy(SET CMP0072 NEW)

include(CTest)
enable_testing()

find_package(OpenGL REQUIRED)

add_executable(my_opengl_project 
src/main.c
src/glad.c
)

target_link_libraries(my_opengl_project 
glfw
OpenGL::GL
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
