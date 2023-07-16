#include "Wolfram.h"
Wolfram w;
void init() {
        w.createInstance();
        w.setupDebugMessenger();
        w.createSurface();
        w.pickPhysicalDevice();
        w.createLogicalDevice();
        w.createSwapChain();
        w.createImageViews();
        w.createRenderPass();
        w.createDescriptorSetLayout();
        w.createGraphicsPipeline();
        w.createCommandPool();
        w.createColorResources();
        w.createDepthResources();
        w.createFramebuffers();
        // w.createTextureImage();
        // w.createTextureImageView();
        // w.createTextureSampler();
        w.loadModel();
        w.createVertexBuffer();
        w.createIndexBuffer();
        w.createUniformBuffers();
        w.createDescriptorPool();
        w.createDescriptorSets();
        w.loadTextures();
        w.createCommandBuffers();
		w.createSyncObjects();
}


void run_app() {
	w.initWindow();
	init();
	w.mainLoop();
	w.cleanup();
}

int main() {
	run_app();
    return EXIT_SUCCESS;	
}
