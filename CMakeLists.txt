cmake_minimum_required(VERSION 3.13)
project(Wolfram)

set(CMAKE_CXX_STANDARD 17)
find_package(Vulkan REQUIRED)
add_subdirectory(includes/glfw)
add_subdirectory(includes/glm)
add_subdirectory(src)
target_link_libraries(Wolfram glfw ${GLFW_LIBRARIES} Vulkan::Vulkan)
target_link_libraries(Wolfram glm)