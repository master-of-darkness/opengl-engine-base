cmake_minimum_required(VERSION 3.27)
project(opengl_engine)

set(CMAKE_CXX_STANDARD 17)

find_package (OpenGL REQUIRED)
find_package (glfw3 REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${GLFW_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

link_libraries(${GLEW_LIBRARIES})

add_executable(opengl_engine main.cpp)
target_link_libraries (opengl_engine
        ${OPENGL_LIBRARIES}
        ${GLFW3_LIBRARY} glfw)