#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}
void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_Q) a== GLFW_PRESS){
        glfwSetWindowShouldClose(window, 1);
		exit(0);
	}
}
int shaderCompSucc(unsigned int vertexShader){
	int  success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);	
	std::cout<<infoLog;
	if(!success){
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	return success;
}

int main(){
	// stupid ass shader ong v
	const char *vertexShaderSource="#version 330 core
	layout (location = 0) in vec3 aPos;

	void main()
	{
    	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
	}"
	int width, height;
	width=999; height=999;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	float vertices[] = { //VBO Vertexes
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
	};  
	unsigned int VBO;
	glGenBuffers(1, &VBO); //Generates Vertex Buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO); //Bind the VBO to a the vertex array
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //Copy the vertex data into memory
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER); //Creating the shader
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); //Pass shader source code
	glCompileShader(vertexShader); //Compilethe shader
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