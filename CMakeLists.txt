cmake_minimum_required(VERSION 3.27)
project(opengl_engine)

set(CMAKE_CXX_STANDARD 17)

find_package (OpenGL REQUIRED)
find_package (glfw3 REQUIRED)
find_package (GLEW REQUIRED)
find_package (spdlog REQUIRED)

# Set where the ImGui files are stored
set(IMGUI_PATH ${PROJECT_SOURCE_DIR}/engine/dependencies/imgui)

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
        ${GLEW_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/engine)

link_libraries(${GLEW_LIBRARIES})

add_executable(opengl_engine main.cpp
        engine/basics/camera/Camera.cpp # engine files start
        engine/basics/camera/Camera.h
        engine/utils/common.cpp
        engine/utils/common.h
        engine/utils/Shader.cpp
        engine/utils/Shader.h
        engine/utils/Texture.cpp
        engine/utils/Texture.h
        engine/utils/Window.cpp
        engine/utils/Window.h) # engine files end

target_link_libraries (opengl_engine
        ${OPENGL_LIBRARIES}
        ${GLFW3_LIBRARY} glfw ImGui spdlog::spdlog_header_only)

target_precompile_headers(opengl_engine PRIVATE engine/pch/pch.h)