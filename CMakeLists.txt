cmake_minimum_required(VERSION 3.27)
project(opengl_engine)

set(CMAKE_CXX_STANDARD 17)

find_package (OpenGL REQUIRED)
find_package (glfw3 REQUIRED)
find_package (GLEW REQUIRED)

# Set where the ImGui files are stored
set(IMGUI_PATH ${PROJECT_SOURCE_DIR}/dependencies/imgui)

# Compile as static library
file(GLOB IMGUI_SOURCES ${IMGUI_PATH}/*.cpp ${IMGUI_PATH}/backends/*.cpp)

# ONLY FOR LINUX
# TODO: add check for linux/darwin/android etc.
list(REMOVE_ITEM IMGUI_SOURCES ${IMGUI_PATH}/backends/imgui_impl_dx12.cpp)
list(REMOVE_ITEM IMGUI_SOURCES ${IMGUI_PATH}/backends/imgui_impl_dx11.cpp)
list(REMOVE_ITEM IMGUI_SOURCES ${IMGUI_PATH}/backends/imgui_impl_dx10.cpp)
list(REMOVE_ITEM IMGUI_SOURCES ${IMGUI_PATH}/backends/imgui_impl_dx9.cpp)
list(REMOVE_ITEM IMGUI_SOURCES ${IMGUI_PATH}/backends/imgui_impl_android.cpp)
list(REMOVE_ITEM IMGUI_SOURCES ${IMGUI_PATH}/backends/imgui_impl_wgpu.cpp)
list(REMOVE_ITEM IMGUI_SOURCES ${IMGUI_PATH}/backends/imgui_impl_win32.cpp)


add_library("ImGui" STATIC ${IMGUI_SOURCES})
target_include_directories("ImGui" PUBLIC ${IMGUI_PATH})



include_directories(
        ${GLFW_INCLUDE_DIRS}
        ${GLEW_INCLUDE_DIRS})

link_libraries(${GLEW_LIBRARIES})

add_executable(opengl_engine main.cpp
        basics/camera.cpp
        basics/camera.h
        pch/pch.h
        utils/Window.cpp
        utils/Window.h
        utils/common.h
        utils/common.cpp)

target_link_libraries (opengl_engine
        ${OPENGL_LIBRARIES}
        ${GLFW3_LIBRARY} glfw ImGui)

target_precompile_headers(opengl_engine PRIVATE pch/pch.h)