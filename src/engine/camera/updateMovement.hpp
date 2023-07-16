#include "../../variables/variables.hpp"
#include <GLFW/glfw3.h>
#include "imgui.h"
void updateCameraMovement(GLFWwindow* window, float& rotationAngle, float rotationSpeed)
  { 
    double mouseX, mouseY;


    if (glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS)
    {
      altPressed = true;
    }
    else if (glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_RELEASE)
    {
      altPressed = false;
    }


      if (altPressed) {
            // Check for keyboard input
      if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPosition += cameraSpeed * cameraFront;
      if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPosition -= cameraSpeed * cameraFront;
      if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPosition += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
      if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPosition -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    }

      if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
      {
        ImGui::SetMouseCursor(ImGuiMouseCursor_None);
        glfwGetCursorPos(window, &mouseX, &mouseY);

        deltaX = mouseX - lastMouseX;
        deltaY = mouseY - lastMouseY;

        rotationAngle += rotationSpeed * static_cast<float>(deltaX);

        lastMouseX = mouseX;
        lastMouseY = mouseY;

      }  else {
        ImGui::SetMouseCursor(ImGuiMouseCursor_Arrow);
        glfwGetCursorPos(window, &lastMouseX, &lastMouseY);
      }
  }