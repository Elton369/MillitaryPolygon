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

/// <summary>
/// Загрузка шейдера из файлаю
/// </summary>
/// <param name="filename">Путь к файлу.</param>
/// <returns>Строка с кодом шейдера.</returns>
string LoadShader(const char* filename);

/// <summary>
/// Функция инициализации всего и создания окна.
/// </summary>
/// <param name="w">Ширина окна.</param>
/// <param name="h">Высота окна.</param>
/// <param name="Fullscreen">Режим полного экрана. </param>
/// <returns>Указатель на созданное окно.</returns>
GLFWwindow* InitAll(int w = 640, int h = 480, bool Fullscreen = false);
/// <summary>
/// Функция для корректного завершения программы.
/// </summary>
void EndAll();

//Набор функций для обработки событий

/// <summary>
/// Обработчик изменения размера окна.
/// </summary>
/// <param name="window">Указатель на окно.</param>
/// <param name="width">Новая ширина окна.</param>
/// <param name="height">Новая высота окна.</param>
void window_size_callback(GLFWwindow* window, int width, int height);
/// <summary>
/// Обработчик нажатия клавиш.
/// </summary>
/// <param name="window">Указатель на окно.</param>
/// <param name="key">Код клавиши.</param>
/// <param name="scancode">Код символа.</param>
/// <param name="action">Действие.</param>
/// <param name="mods">Состояние модификаторов нажатия.</param>
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
