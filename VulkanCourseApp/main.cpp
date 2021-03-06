#define GLFW_INCLUDE_VULKAN
#include    "GLFW/glfw3.h"
#include    "VulkanRenderer.h"
#include    <iostream>
#include    <stdexcept>
#include    <vector>

GLFWwindow* window;
VulkanRenderer vulkanRenderer;

void initWindow(std::string wName = "Test Window", 
                const int width = 800, 
                const int height = 600)
{
    // Initialize glfw
    glfwInit();

    // Set GLFW to not work with OpenGL
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, wName.c_str(),nullptr,nullptr);
}

int main() 
{
    initWindow();

    if(vulkanRenderer.init(window) == EXIT_FAILURE) return EXIT_FAILURE;

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    vulkanRenderer.cleanup();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}