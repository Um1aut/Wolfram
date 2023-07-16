#include "../../variables/variables.hpp"
#include <chrono>
#include <cstring>
#include <iostream>

void calculateCameraCoords() {
    glm::vec3 c = cameraPosition + cameraFront;
    cameraCoords = c;
}

void updateUniformBuffer(uint32_t currentImage) {
        static auto startTime = std::chrono::high_resolution_clock::now();

        auto currentTime = std::chrono::high_resolution_clock::now();
        float deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - startTime).count();

        // Update camera orientation based on mouse movement
        deltaX *= sensivity;
        deltaY *= sensivity;
        float yaw = glm::radians(rotationSpeed * static_cast<float>(-deltaX));
        float pitch = glm::radians(rotationSpeed * static_cast<float>(deltaY));

        glm::quat yawRotation = glm::angleAxis(yaw, glm::vec3(0.0f, 0.0f, 1.0f));
        cameraFront = glm::normalize(yawRotation * cameraFront);
        cameraUp = glm::normalize(yawRotation * cameraUp);

        glm::vec3 cameraRight = glm::normalize(glm::cross(cameraFront, cameraUp));
        glm::quat pitchRotation = glm::angleAxis(pitch, cameraRight);
        cameraFront = glm::normalize(pitchRotation * cameraFront);
        cameraUp = glm::normalize(pitchRotation * cameraUp);

        VulkanVariables::UniformBufferObject ubo{};
        ubo.model = glm::translate(glm::mat4(1.0f), modelPosition);
        ubo.model = glm::rotate(ubo.model, glm::radians(rotationAngles.x+90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        ubo.model = glm::rotate(ubo.model, glm::radians(rotationAngles.y), glm::vec3(0.0f, 1.0f, 0.0f));
        ubo.model = glm::rotate(ubo.model, glm::radians(rotationAngles.z), glm::vec3(0.0f, 0.0f, 1.0f));
        glm::vec3 cameraTarget = cameraPosition + cameraFront;
        ubo.view = glm::lookAt(cameraPosition, cameraTarget, -cameraUp);

        ubo.proj = glm::perspective(glm::radians(60.0f), swapChainExtent.width / static_cast<float>(swapChainExtent.height), 0.1f, distanceRender*10);
        ubo.proj[1][1] *= -1;



        void* data;
        vkMapMemory(device, uniformBuffersMemory[currentImage], 0, sizeof(ubo), 0, &data);
        memcpy(data, &ubo, sizeof(ubo));
        vkUnmapMemory(device, uniformBuffersMemory[currentImage]);
}