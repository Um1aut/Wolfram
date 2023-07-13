cmake_minimum_required(VERSION 3.13)
project(Wolfram)

set(CMAKE_CXX_STANDARD 17)
find_package(Vulkan REQUIRED)
add_subdirectory(includes/glfw)
add_subdirectory(includes/glm)
add_subdirectory(src)

set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/includes/imgui)


add_library(imgui STATIC
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_demo.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        )

# Set include directories for ImGui


add_library(imgui_impl_vulkan STATIC
        includes/imgui/backends/imgui_impl_vulkan.cpp
        includes/imgui/backends/imgui_impl_glfw.cpp
        )

        target_include_directories(imgui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes/imgui)
target_include_directories(imgui_impl_vulkan PUBLIC ${IMGUI_DIR}/backends ${VULKAN_LIBRARIES} ${GLFW_LIBRARIES})

target_link_libraries(Wolfram imgui_impl_vulkan ${VULKAN_LIBRARIES} ${GLFW_LIBRARIES})
target_link_libraries(Wolfram imgui)
target_link_libraries(Wolfram glfw ${GLFW_LIBRARIES} Vulkan::Vulkan)
target_link_libraries(Wolfram glm)
