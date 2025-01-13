#pragma once

#include <glm/glm.hpp>

#define PI 3.14159265358979323846f


extern const glm::mat4 WorldMatrix;

extern int WinWidth;

extern int WinHeight;

extern glm::vec3 CamPosition;

extern glm::vec3 CamFront;

extern glm::vec3 CamUp;

extern GLfloat CamDistance;

extern GLfloat CamSpeed;

extern GLfloat CamSensitivity;

extern bool CamMoved;

extern float yaw, pitch;

extern float lastX, lastY;

extern float progress;

extern float seaHawkZ;
