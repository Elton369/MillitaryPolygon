#pragma once

#include <glm/glm.hpp>

#define PI 3.14159265358979323846f


extern const glm::mat4 WorldMatrix;

extern int WinWidth;

extern int WinHeight;

extern glm::vec3 CamPosition;

extern glm::vec3 CamTarget;

extern bool CamMoved;

extern GLfloat CamSpeed;

extern glm::vec3 CamUp;

extern GLfloat CamDistance;

extern float yaw, pitch;

extern bool leftMousePressed, middleMousePressed;

extern double lastMouseX, lastMouseY;

extern float progress;

extern float seaHawkZ;
