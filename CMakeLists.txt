cmake_minimum_required(VERSION 3.12)


project(MyGameProject)

find_package(OpenGL REQUIRED)

# Include directories for headers
include_directories(include)

# Add glad library
add_library(glad STATIC src/glad.c)

# Add executable
add_executable(MyGameProject src/main.cpp)

# Link with GLFW, glad, and OpenGL
target_link_libraries(MyGameProject PRIVATE glad glfw ${OPENGL_LIBRARIES})




