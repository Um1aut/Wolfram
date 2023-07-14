#include "../variables/variables.hpp"
#include "imgui.h"
#include "imgui_impl_vulkan.h"
#include "imgui_impl_glfw.h"
#include <iostream>

namespace Gui {
        void initImGui() {
                ImGui::CreateContext();

                std::cout<<VulkanVariables::msaaSamples<<std::endl;

                // Build the ImGui fonts
                ImGuiIO& io = ImGui::GetIO();
                io.Fonts->AddFontDefault();
                io.Fonts->Build();

                ImGui_ImplGlfw_InitForVulkan(VulkanVariables::window, true);

                // Initialize ImGui Vulkan-specific functionality
                ImGui_ImplVulkan_InitInfo init_info = {};
                init_info.Instance = VulkanVariables::instance;
                init_info.PhysicalDevice = VulkanVariables::physicalDevice;
                init_info.Device = VulkanVariables::device;
                init_info.Queue = VulkanVariables::graphicsQueue;
                init_info.DescriptorPool = VulkanVariables::descriptorPool;
                init_info.MinImageCount = 2;
                init_info.ImageCount = 2;
                init_info.Subpass = 0;
                init_info.MSAASamples = VulkanVariables::msaaSamples;
                ImGui_ImplVulkan_Init(&init_info, VulkanVariables::renderPass);


                VkCommandBuffer commandBuffer = VulkanVariables::beginSingleTimeCommands();
                ImGui_ImplVulkan_CreateFontsTexture(commandBuffer);
                VulkanVariables::endSingleTimeCommands(commandBuffer);

                vkDeviceWaitIdle(VulkanVariables::device);
                ImGui_ImplVulkan_DestroyFontUploadObjects();
        }
};