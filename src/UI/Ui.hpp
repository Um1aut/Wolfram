#include "../variables/variables.hpp"
#include "imgui.h"
#include "imgui_impl_vulkan.h"
#include "imgui_impl_glfw.h"
#include <iostream>

namespace Gui {
        void initImGui() {
                ImGui::CreateContext();

                std::cout<<msaaSamples<<std::endl;

                // Build the ImGui fonts
                ImGuiIO& io = ImGui::GetIO();
                io.Fonts->AddFontDefault();
                io.Fonts->Build();

                ImGui_ImplGlfw_InitForVulkan(window, true);

                // Initialize ImGui Vulkan-specific functionality
                ImGui_ImplVulkan_InitInfo init_info = {};
                init_info.Instance = instance;
                init_info.PhysicalDevice = physicalDevice;
                init_info.Device = device;
                init_info.Queue = graphicsQueue;
                init_info.DescriptorPool = descriptorPool;
                init_info.MinImageCount = 2;
                init_info.ImageCount = 2;
                init_info.Subpass = 0;
                init_info.MSAASamples = msaaSamples;
                ImGui_ImplVulkan_Init(&init_info, renderPass);


                VkCommandBuffer commandBuffer = beginSingleTimeCommands();
                ImGui_ImplVulkan_CreateFontsTexture(commandBuffer);
                endSingleTimeCommands(commandBuffer);

                vkDeviceWaitIdle(device);
                ImGui_ImplVulkan_DestroyFontUploadObjects();
        }

        void DefaultWindow()
    {
        ImGui::Begin("Settings");

        ImGui::InputFloat("Sensivity", &sensivity);
        ImGui::InputFloat("Distance Render", &distanceRender);
        ImGui::InputFloat("Camera Speed", &cameraSpeed);

        ImGui::Text("Rotation:");
        ImGui::SliderFloat("X", &rotationAngles.x, -180.0f, 180.0f);
        ImGui::SliderFloat("Y", &rotationAngles.y, -180.0f, 180.0f);
        ImGui::SliderFloat("Z", &rotationAngles.z, -180.0f, 180.0f);

        ImGui::End();
    }

    void DrawData() {
        ImGuiIO& io = ImGui::GetIO();
        ImVec2 windowPos = ImVec2(10, 10);  // Position the text at the top-left corner

        ImGui::SetNextWindowPos(windowPos, ImGuiCond_Always);

        ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar;
        if (ImGui::Begin("Model Position", nullptr, windowFlags)) {
            ImGui::Text("Hello!");
        }
        ImGui::End();
    }

    void ModelSettings()
    {
        ImGuiIO& io = ImGui::GetIO();
        ImVec2 windowPos = ImVec2(io.DisplaySize.x - 130, 10);  // Position the window at the top-right corner
        ImVec2 windowSize = ImVec2(120, 105);  // Set the window size

        ImGui::SetNextWindowPos(windowPos, ImGuiCond_Always);
        ImGui::SetNextWindowSize(windowSize, ImGuiCond_Always);

        ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse| ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar;
        if (ImGui::Begin("Model Position", nullptr, windowFlags)) {
            ImGui::Text("Model:");
            ImGui::InputFloat("X", &modelPosition.x, 1.0f, 0.0f, "%.1f");
            ImGui::InputFloat("Y", &modelPosition.y, 1.0f, 0.0f, "%.1f");
            ImGui::InputFloat("Z", &modelPosition.z, 1.0f, 0.0f, "%.1f");
        }
        ImGui::End();
    }

    void showOverlay() {
        static int location = 0;
        ImGuiIO& io = ImGui::GetIO();
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav;
        if (location >= 0)
        {
            const float PAD = 10.0f;
            const ImGuiViewport* viewport = ImGui::GetMainViewport();
            ImVec2 work_pos = viewport->WorkPos; // Use work area to avoid menu-bar/task-bar, if any!
            ImVec2 work_size = viewport->WorkSize;
            ImVec2 window_pos, window_pos_pivot;
            window_pos.x = (location & 1) ? (work_pos.x + work_size.x - PAD) : (work_pos.x + PAD);
            window_pos.y = (location & 2) ? (work_pos.y + work_size.y - PAD) : (work_pos.y + PAD);
            window_pos_pivot.x = (location & 1) ? 1.0f : 0.0f;
            window_pos_pivot.y = (location & 2) ? 1.0f : 0.0f;
            ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);
            window_flags |= ImGuiWindowFlags_NoMove;
        }
        else if (location == -2)
        {
            // Center window
            ImGui::SetNextWindowPos(ImGui::GetMainViewport()->GetCenter(), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
            window_flags |= ImGuiWindowFlags_NoMove;
        }
        ImGui::SetNextWindowBgAlpha(0.55f); // Transparent background
        if (ImGui::Begin("Data", nullptr, window_flags))
        {
            ImGui::Text("FPS: %.1f", io.Framerate);
            ImGui::Text("MSAA: x%d", msaaSamples);
            if (ImGui::BeginPopupContextWindow())
            {
                if (ImGui::MenuItem("Custom",       NULL, location == -1)) location = -1;
                if (ImGui::MenuItem("Center",       NULL, location == -2)) location = -2;
                if (ImGui::MenuItem("Top-left",     NULL, location == 0)) location = 0;
                if (ImGui::MenuItem("Top-right",    NULL, location == 1)) location = 1;
                if (ImGui::MenuItem("Bottom-left",  NULL, location == 2)) location = 2;
                if (ImGui::MenuItem("Bottom-right", NULL, location == 3)) location = 3;
                ImGui::EndPopup();
            }
        }
        ImGui::End();
    }

    void renderImGui(VkCommandBuffer commandBuffer) {
        ImGui_ImplVulkan_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        DefaultWindow();
        ModelSettings();
        DrawData();
        showOverlay();


        ImGui::Render();
        ImGui_ImplVulkan_RenderDrawData(ImGui::GetDrawData(), commandBuffer);
    }

};