#include "Wolfram.h"

Wolfram wolfram;

void initVulkan() {

        wolfram.createInstance();
        wolfram.setupDebugMessenger();
        wolfram.createSurface();
        wolfram.pickPhysicalDevice();
        wolfram.createLogicalDevice();
        wolfram.createSwapChain();
        wolfram.createImageViews();
        wolfram.createRenderPass();
        wolfram.createDescriptorSetLayout();
        wolfram.createGraphicsPipeline();
        wolfram.createCommandPool();
        wolfram.createColorResources();
        wolfram.createDepthResources();
        wolfram.createFramebuffers();
        wolfram.createTextureImage();
        wolfram.createTextureImageView();
        wolfram.createTextureSampler();
        wolfram.loadModel();
        wolfram.createVertexBuffer();
        wolfram.createIndexBuffer();
        wolfram.createUniformBuffers();
        wolfram.createDescriptorPool();
        wolfram.createDescriptorSets();
        wolfram.createCommandBuffers();
		wolfram.createSyncObjects();
}


void run_app() {
	wolfram.initWindow();
	initVulkan();
	wolfram.mainLoop();
	wolfram.cleanup();
}

int main() {
	run_app();
    return EXIT_SUCCESS;	
}
