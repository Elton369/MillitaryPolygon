#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Model.h"


using namespace std;


void renderLoadingScreen(GLFWwindow *window);

void setLightsInfo(LightsInfo &lights);

void setMVP(glm::mat4 &MMatr, glm::mat4 &VMatr, glm::mat4 &PMatr);

string LoadShader(const char* filename);

GLFWwindow* InitAll(int w = 640, int h = 480, bool Fullscreen = false);

void EndAll();

void window_size_callback(GLFWwindow* window, int width, int height);

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
