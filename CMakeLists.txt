cmake_minimum_required(VERSION 3.13)
project(Wolfram)

set(CMAKE_CXX_STANDARD 17)
find_package(Vulkan REQUIRED)

set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/includes/imgui)
set(ENTT_DIR ${CMAKE_SOURCE_DIR}/includes/entt)

add_subdirectory(includes/glfw)
add_subdirectory(includes/glm)
add_subdirectory(src)

add_library(imgui STATIC
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_demo.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        )

add_library(imgui_impl_vulkan STATIC
        includes/imgui/backends/imgui_impl_vulkan.cpp
        includes/imgui/backends/imgui_impl_glfw.cpp
        )

# Add include directories for imgui, entt, and Vulkan
include_directories(${IMGUI_DIR})
include_directories(${ENTT_DIR})
include_directories(${Vulkan_INCLUDE_DIRS})

# Link libraries
target_link_libraries(imgui_impl_vulkan ${Vulkan_LIBRARIES} glfw ${GLFW_LIBRARIES})
target_link_libraries(Wolfram imgui imgui_impl_vulkan Vulkan::Vulkan glfw glm)

# Set include directories for imgui, entt, and Vulkan
target_include_directories(imgui PUBLIC ${IMGUI_DIR})
target_include_directories(imgui_impl_vulkan PUBLIC ${IMGUI_DIR}/backends)
target_include_directories(Wolfram PUBLIC ${ENTT_DIR} ${Vulkan_INCLUDE_DIRS})

# Set source files for entt
set(ENTT_SRC ${ENTT_DIR}/entt.hpp)

# Add entt as a header-only library
add_library(entt INTERFACE)
target_include_directories(entt INTERFACE ${ENTT_DIR})
target_sources(entt INTERFACE ${ENTT_SRC})
