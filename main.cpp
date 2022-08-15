#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <sys/ioctl.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}
void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
	}
}

int main(){
	int width, height;
	width=999; height=999;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	
	GLFWwindow* window = glfwCreateWindow(width, height, "God help me.", NULL, NULL);
	if (window == NULL){
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	glViewport(0, 0, width, height);
	//Resize with user input
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	while(!glfwWindowShouldClose(window)){
		processInput(window);
		glClearColor(1.0, 0.1, 0.1, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();    
	}
	glfwTerminate();
    return 0;
}