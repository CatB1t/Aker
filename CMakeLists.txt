cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 20)

add_compile_definitions("SHADERS_ROOT_ABS_PATH=\"${CMAKE_SOURCE_DIR}/assets/shaders/\"")
project(Aker VERSION 0.1)

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "src/*.h")
add_executable(Aker ${SOURCE_FILES})

add_subdirectory(thirdparty/glfw)
add_subdirectory(thirdparty/glad)
add_subdirectory(thirdparty/glm)
add_subdirectory(thirdparty/stbi)

find_package(OpenGL REQUIRED)
target_link_libraries(Aker PRIVATE stbi glm::glm glfw glad ${OPENGL_LIBRARIES})