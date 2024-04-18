cmake_minimum_required(VERSION 3.5)

project(dear_imgui)
add_library(dear_imgui)

file(GLOB ROOT_SOURCES "imgui/*.cpp")

target_sources(dear_imgui PRIVATE 
    ${ROOT_SOURCES} 
    "imgui/backends/imgui_impl_opengl3.cpp"
    "imgui/backends/imgui_impl_glfw.cpp"
)

target_include_directories(dear_imgui PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(dear_imgui PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/imgui")
target_link_libraries(dear_imgui PUBLIC glfw glad)
