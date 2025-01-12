#include "func.h"
#include "globals.h"


void renderLoadingScreen(GLFWwindow *window)
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    float barWidth = 0.8f; // Ширина прогресс-бара
    float barHeight = 0.05f; // Высота прогресс-бара
    float barX = -barWidth / 2.0f; // Начало по X
    float barY = 0.0f; // Положение по Y

    glColor3f(1.0f, 1.0f, 1.0f); // Белая рамка
    glBegin(GL_LINE_LOOP);
    glVertex2f(barX, barY - barHeight / 2.0f);
    glVertex2f(barX + barWidth, barY - barHeight / 2.0f);
    glVertex2f(barX + barWidth, barY + barHeight / 2.0f);
    glVertex2f(barX, barY + barHeight / 2.0f);
    glEnd();

    glColor3f(0.2f, 0.8f, 0.2f); // Зелёный прогресс
    glBegin(GL_QUADS);
    glVertex2f(barX, barY - barHeight / 2.0f);
    glVertex2f(barX + barWidth * progress, barY - barHeight / 2.0f);
    glVertex2f(barX + barWidth * progress, barY + barHeight / 2.0f);
    glVertex2f(barX, barY + barHeight / 2.0f);
    glEnd();

    glFlush();
}

void setLightsInfo(LightsInfo &lights)
{
    lights.numPLights = 14;
    lights.numSLights = 14;

    DirLight lSource;
    lSource.ambient = glm::vec3(0.8, 0.8, 0.7);
    lSource.diffuse = glm::vec3(0.8, 0.8, 0.7);
    lSource.specular = glm::vec3(0.5, 0.5, 0.5);
    lSource.direction = glm::vec3(1, -1, 1);

    lights.dirLight = lSource;

    PointLight P;
    P.constant = 1;
    P.linear = 0.7;
    P.quadratic = 1.8;

    P.ambient = glm::vec3(0.0f, 0.0f, 0.0f);
    P.diffuse = glm::vec3(0.4f, 0.5f, 0.4f);
    P.specular = glm::vec3(1.0f, 1.0f, 1.0f);

    P.position = glm::vec3(3.1, -4.5, -6.21);
    lights.pointLights.push_back(P);

    P.position = glm::vec3(3.1, -4.5, -4.34);
    lights.pointLights.push_back(P);

    P.position = glm::vec3(3.1, -4.5, -2.47);
    lights.pointLights.push_back(P);

    P.position = glm::vec3(3.1, -4.5, -0.6);
    lights.pointLights.push_back(P);

    P.position = glm::vec3(3.1, -4.5, 1.27);
    lights.pointLights.push_back(P);

    P.position = glm::vec3(3.1, -4.5, 3.14);
    lights.pointLights.push_back(P);

    P.position = glm::vec3(3.1, -4.5, 5.01);
    lights.pointLights.push_back(P);

    P.position = glm::vec3(-3.1, -4.5, -6.21);
    lights.pointLights.push_back(P);

    P.position = glm::vec3(-3.1, -4.5, -4.34);
    lights.pointLights.push_back(P);

    P.position = glm::vec3(-3.1, -4.5, -2.47);
    lights.pointLights.push_back(P);

    P.position = glm::vec3(-3.1, -4.5, -0.6);
    lights.pointLights.push_back(P);

    P.position = glm::vec3(-3.1, -4.5, 1.27);
    lights.pointLights.push_back(P);

    P.position = glm::vec3(-3.1, -4.5, 3.14);
    lights.pointLights.push_back(P);

    P.position = glm::vec3(-3.1, -4.5, 5.01);
    lights.pointLights.push_back(P);


    SpotLight SP;
    SP.constant = 1;
    SP.linear = 0.07;
    SP.quadratic = 0.18;

    SP.ambient = glm::vec3(0.0f, 0.0f, 0.0f);
    SP.diffuse = glm::vec3(0.4f, 0.5f, 0.4f);
    SP.specular = glm::vec3(1.0f, 1.0f, 1.0f);
    SP.direction = glm::vec3(0, -1, 0);
    SP.cutOff = glm::cos(glm::radians(12.5f));
    SP.outerCutOff = glm::cos(glm::radians(15.0f));

    SP.position = glm::vec3(3.1, -4.5, -6.21);
    lights.spotLights.push_back(SP);

    SP.position = glm::vec3(3.1, -4.5, -4.34);
    lights.spotLights.push_back(SP);

    SP.position = glm::vec3(3.1, -4.5, -2.47);
    lights.spotLights.push_back(SP);

    SP.position = glm::vec3(3.1, -4.5, -0.6);
    lights.spotLights.push_back(SP);

    SP.position = glm::vec3(3.1, -4.5, 1.27);
    lights.spotLights.push_back(SP);

    SP.position = glm::vec3(3.1, -4.5, 3.14);
    lights.spotLights.push_back(SP);

    SP.position = glm::vec3(3.1, -4.5, 5.01);
    lights.spotLights.push_back(SP);

    SP.position = glm::vec3(-3.1, -4.5, -6.21);
    lights.spotLights.push_back(SP);

    SP.position = glm::vec3(-3.1, -4.5, -4.34);
    lights.spotLights.push_back(SP);

    SP.position = glm::vec3(-3.1, -4.5, -2.47);
    lights.spotLights.push_back(SP);

    SP.position = glm::vec3(-3.1, -4.5, -0.6);
    lights.spotLights.push_back(SP);

    SP.position = glm::vec3(-3.1, -4.5, 1.27);
    lights.spotLights.push_back(SP);

    SP.position = glm::vec3(-3.1, -4.5, 3.14);
    lights.spotLights.push_back(SP);

    SP.position = glm::vec3(-3.1, -4.5, 5.01);
    lights.spotLights.push_back(SP);
}

void setMVP(glm::mat4 &MMatr, glm::mat4 &VMatr, glm::mat4 &PMatr)
{
    PMatr = glm::perspective(
        glm::radians(67.0f),                  // Угол обзора
        static_cast<float>(WinWidth) / WinHeight,    // Соотношение сторон
        0.01f,                                       // Ближняя плоскость отсечения
        10000.0f                                     // Дальняя плоскость отсечения
    );

    CamPosition = { 0, 0, CamDistance };
    VMatr = glm::lookAt(CamPosition, CamTarget, CamUp);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}


string LoadShader(const char* filename)
{
    string res;
    ifstream file(filename, ios::in);
    if (file.is_open()) {
        std::stringstream sstr; // Буфер для чтения
        sstr << file.rdbuf(); // Считываем файл
        res = sstr.str();   //Получаем строку из буфера
        file.close();       //Закрываем файл
    }
    return res;
}

GLFWwindow* InitAll(int w, int h, bool Fullscreen)
{
    //В глобальные переменные сохраняем размеры окна
    WinWidth = w;
    WinHeight = h;

    //Создаём переменную для хранения ID окна
    GLFWwindow* window = nullptr;

    //Подключение GLFW
    if (!glfwInit()) {
        cerr << "ERROR: could not start GLFW3\n";
        exit(-1);
    }

    //В зависимости от режима экрана создаётся окно с заголовком Capybara OpenGL
    if (Fullscreen)
    {

        GLFWmonitor* mon = glfwGetPrimaryMonitor();
        const GLFWvidmode* vmode = glfwGetVideoMode(mon);
        WinWidth = vmode->width;
        WinHeight = vmode->height;
        window = glfwCreateWindow(WinWidth, WinHeight, "OpenGL", mon, NULL);

    }
    else
        window = glfwCreateWindow(WinWidth, WinHeight, "OpenGL", NULL, NULL);

    //Привязываются функции для обработки событий
    glfwSetWindowSizeCallback(window, window_size_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    //Активируется контекст окна
    glfwMakeContextCurrent(window);

    //Подключение новейшей из доступных версий OpenGL
    glewExperimental = GL_TRUE;

    //Подключение функций OpenGL
    if (glewInit() != GLEW_OK) {
        cerr << "ERROR: could not start GLEW\n";
        return nullptr;
    }

    //Если дошли до сюда - возвращаем окно
    return window;
}

void EndAll()
{
    glfwTerminate();
}

void window_size_callback(GLFWwindow* window, int width, int height)
{
    //Просто меняем глобальные переменные
    WinWidth = width;
    WinHeight = height;
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    //Смена направления вращения модели.
    // if (key == GLFW_KEY_1 && action == GLFW_PRESS)
    // {
    //     RotationMode = !RotationMode;
    // }
    //Управление камерой - WASD перемещение, - и = удаление и приближение
    if (key == GLFW_KEY_W && (action == GLFW_REPEAT || action == GLFW_PRESS))
    {
//        CamTarget.y += CamSpeed;
        seaHawkZ += 0.1f;
        if (seaHawkZ > 8.0f) seaHawkZ = 8.0f;
        CamMoved = true;
    }
    if (key == GLFW_KEY_S && (action == GLFW_REPEAT || action == GLFW_PRESS))
    {
//        CamTarget.y -= CamSpeed;
        seaHawkZ -= 0.1f;
        if (seaHawkZ < 0.0f) seaHawkZ = 0.0f;
        CamMoved = true;
    }
//    if (key == GLFW_KEY_D && (action == GLFW_REPEAT || action == GLFW_PRESS))
//    {
//        CamTarget.x += CamSpeed;
//        CamMoved = true;
//    }
//    if (key == GLFW_KEY_A && (action == GLFW_REPEAT || action == GLFW_PRESS))
//    {
//        CamTarget.x -= CamSpeed;
//        CamMoved = true;
//    }
//    if (key == GLFW_KEY_EQUAL && (action == GLFW_REPEAT || action == GLFW_PRESS))
//    {
//        CamPosition.z -= CamSpeed;
//        CamMoved = true;
//    }
//    if (key == GLFW_KEY_MINUS && (action == GLFW_REPEAT || action == GLFW_PRESS))
//    {
//        CamPosition.z += CamSpeed;
//        CamMoved = true;
//    }
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    double xOffset = xpos - lastMouseX;
    double yOffset = ypos - lastMouseY;

    lastMouseX = xpos;
    lastMouseY = ypos;

    // Если зажата левая кнопка мыши, вращаем камеру вокруг объекта
    if (leftMousePressed) {
        yaw += xOffset * CamSpeed * 0.1f;
        pitch -= yOffset * CamSpeed * 0.1f;

        // Ограничиваем угол наклона камеры
        if (pitch > 89.0f) pitch = 89.0f;
        if (pitch < -89.0f) pitch = -89.0f;

        // Пересчитываем позицию камеры
        CamPosition.x = CamTarget.x + CamDistance * cos(glm::radians(pitch)) * cos(glm::radians(yaw));
        CamPosition.y = CamTarget.y + CamDistance * sin(glm::radians(pitch));
        CamPosition.z = CamTarget.z + CamDistance * cos(glm::radians(pitch)) * sin(glm::radians(yaw));

        CamMoved = true;
    }

    // Если зажат колесик мыши, перемещаем камеру (панорамируем)
    if (middleMousePressed) {
        glm::vec3 right = glm::normalize(glm::cross(CamUp, CamPosition - CamTarget));
        glm::vec3 up = glm::normalize(glm::cross(CamPosition - CamTarget, right));

        CamTarget += -right * static_cast<float>(xOffset * CamSpeed * 0.1f);
        CamTarget += up * static_cast<float>(yOffset * CamSpeed * 0.1f);

        CamPosition += -right * static_cast<float>(xOffset * CamSpeed * 0.1f);
        CamPosition += up * static_cast<float>(yOffset * CamSpeed * 0.1f);

        CamMoved = true;
    }
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    CamDistance -= yoffset * CamSpeed;
    if (CamDistance < 1.0f) CamDistance = 1.0f;

    // Пересчитываем позицию камеры
    CamPosition.x = CamTarget.x + CamDistance * cos(glm::radians(pitch)) * cos(glm::radians(yaw));
    CamPosition.y = CamTarget.y + CamDistance * sin(glm::radians(pitch));
    CamPosition.z = CamTarget.z + CamDistance * cos(glm::radians(pitch)) * sin(glm::radians(yaw));

    CamMoved = true;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT)
        leftMousePressed = (action == GLFW_PRESS);
    if (button == GLFW_MOUSE_BUTTON_MIDDLE)
        middleMousePressed = (action == GLFW_PRESS);

    // Сохраняем текущее положение мыши
    if (action == GLFW_PRESS) {
        glfwGetCursorPos(window, &lastMouseX, &lastMouseY);
    }

    CamMoved = true;
}
