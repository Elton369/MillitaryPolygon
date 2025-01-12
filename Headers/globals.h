#pragma once

#include <glm/glm.hpp>

//Набор глобальных переменных и констант для управления сценой

#define PI 3.14159265358979323846f

/// <summary>
/// Единичная матрица. Для быстрого сброса значений.
/// </summary>
extern const glm::mat4 WorldMatrix;

/// <summary>
/// Ширина окна.
/// </summary>
extern int WinWidth;
/// <summary>
/// Высота окна.
/// </summary>
extern int WinHeight;
/// <summary>
/// Позиция камеры
/// </summary>
extern glm::vec3 CamPosition;
/// <summary>
/// Позиция цели камеры
/// </summary>
extern glm::vec3 CamTarget;
/// <summary>
/// Двигалась ли камера после предыдущего кадра
/// </summary>
extern bool CamMoved;
/// <summary>
/// Скорость камеры
/// </summary>
extern GLfloat CamSpeed;

extern glm::vec3 CamUp;
extern GLfloat CamDistance;
extern float yaw, pitch;
extern bool leftMousePressed, middleMousePressed;
extern double lastMouseX, lastMouseY;

extern float progress;

extern float seaHawkZ;
