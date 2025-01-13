#include "func.h"

#define PI 3.14159265358979323846f


constexpr auto WorldMatrix = glm::mat4(1.0f);

int WinWidth;
int WinHeight;

glm::vec3 CamPosition;
glm::vec3 CamFront(0);
glm::vec3 CamUp(0, 1, 0);
GLfloat CamDistance = 25.0f;
GLfloat CamSpeed = 0.5f;
GLfloat CamSensitivity = 0.1f;
bool CamMoved = false;
float yaw = -90.0f, pitch = 0.0f;
float lastX = 512, lastY = 384;

float seaHawkZ = 0.0f;

float progress = 0.0f;


int main() {
    GLFWwindow *window = InitAll(1024, 768, false);
    if (window == nullptr) {
        EndAll();
        return -1;
    }

    double start_time = glfwGetTime();

    int part = 0;
    int parts = 0;

    Model Shelter(window,2);
    vector<Model> shelter;
    vector<OBJData> objDataShelter;
    Shelter.loadOBJTiny("OBJ/Shelter/Shelter.obj", "OBJ/Shelter/", objDataShelter);
    parts += objDataShelter.size();

    Model SeaHawk(window,2);
    vector<Model> seaHawk;
    vector<OBJData> objDataSeaHawk;
    SeaHawk.loadOBJTiny("OBJ/SeaHawk/SeaHawk.obj", "OBJ/SeaHawk/", objDataSeaHawk);
    parts += objDataSeaHawk.size();

    Model Spaceship(window, 2);
    vector<Model> spaceship;
    vector<OBJData> objDataSpaceship;
    Spaceship.loadOBJTiny("OBJ/Spaceship/Spaceship.obj", "OBJ/Spaceship/", objDataSpaceship);
    parts += objDataSpaceship.size();

    for (size_t i = 0; i < objDataShelter.size(); ++i) {
        shelter.emplace_back(window, 2);
        auto &obj = shelter[i];
        auto &objData = objDataShelter[i];
        obj.load_coords(objData.vertices.data(), objData.vertices.size());
        obj.load_normals(objData.normals.data(), objData.normals.size());
        obj.load_texcoord(objData.textures.data(), objData.textures.size());
        obj.load_shaders("Shaders/vs.glsl", "Shaders/fs.glsl");
        obj.setMaterial(glm::vec3(0), glm::vec3(0), glm::vec3(0), 256);
        obj.load_texture("OBJ/Shelter/" + objData.textureName, "OBJ/Shelter/" + objData.bumpName);

        progress = static_cast<float>(++part) / parts;
        renderLoadingScreen(window);
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    for (size_t i = 0; i < objDataSeaHawk.size(); ++i) {
        seaHawk.emplace_back(window, 2);
        auto &obj = seaHawk[i];
        auto &objData = objDataSeaHawk[i];
        obj.load_coords(objData.vertices.data(), objData.vertices.size());
        obj.load_normals(objData.normals.data(), objData.normals.size());
        obj.load_texcoord(objData.textures.data(), objData.textures.size());
        obj.load_shaders("Shaders/vs.glsl", "Shaders/fs.glsl");
        obj.setMaterial(glm::vec3(0), glm::vec3(0), glm::vec3(0), 256);
        obj.load_texture("OBJ/SeaHawk/" + objData.textureName, "OBJ/SeaHawk/" + objData.bumpName);

        progress = static_cast<float>(++part) / parts;
        renderLoadingScreen(window);
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    for (size_t i = 0; i < objDataSpaceship.size(); ++i) {
        spaceship.emplace_back(window, 2);
        auto &obj = spaceship[i];
        auto &objData = objDataSpaceship[i];
        obj.load_coords(objData.vertices.data(), objData.vertices.size());
        obj.load_normals(objData.normals.data(), objData.normals.size());
        obj.load_texcoord(objData.textures.data(), objData.textures.size());
        obj.load_shaders("Shaders/vs.glsl", "Shaders/fs.glsl");
        obj.setMaterial(glm::vec3(0), glm::vec3(0), glm::vec3(0), 256);
        obj.load_texture("OBJ/Spaceship/" + objData.textureName, "OBJ/Spaceship/" + objData.bumpName);

        progress = static_cast<float>(++part) / parts;
        renderLoadingScreen(window);
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    LightsInfo Lights;
    setLightsInfo(Lights);

    glm::mat4 MMatr = WorldMatrix;
    glm::mat4 VMatr = WorldMatrix;
    glm::mat4 PMatr = WorldMatrix;
    setMVP(MMatr, VMatr, PMatr);

    while (!glfwWindowShouldClose(window)) {
        float rotation = glfwGetTime() - start_time;

        glViewport(0, 0, WinWidth, WinHeight);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (CamMoved) {
            VMatr = glm::lookAt(CamPosition, CamPosition + CamFront, CamUp);
            CamMoved = false;
        }

        for (auto &obj : shelter) {
            MMatr = WorldMatrix;
            MMatr = glm::rotate(MMatr, glm::radians(-90.0f), glm::vec3(0.0, 1.0, 0.0));
            MMatr = glm::translate(MMatr, glm::vec3(0.0, -7.0, 0.0));
            MMatr = glm::scale(MMatr, glm::vec3(0.5, 0.5, 0.5));
            obj.render(MMatr, VMatr, PMatr, Lights, GL_TRIANGLES);
        }

        for (auto &obj : seaHawk) {
            MMatr = WorldMatrix;
            MMatr = glm::translate(MMatr, glm::vec3(0.0, -6.90, seaHawkZ));
            MMatr = glm::scale(MMatr, glm::vec3(0.03, 0.03, 0.03));
            obj.render(MMatr, VMatr, PMatr, Lights, GL_TRIANGLES);
        }

        for (auto &obj : spaceship) {
            MMatr = WorldMatrix;
            MMatr = glm::rotate(MMatr, glm::radians(180.0f), glm::vec3(1.0, 0.0, 0.0));
            MMatr = glm::rotate(MMatr, PI / 2 - rotation, glm::vec3(0.0, 1.0, 0.0));
            MMatr = glm::translate(MMatr, glm::vec3(12.0, 0.0, 0.0));
            MMatr = glm::scale(MMatr, glm::vec3(0.2, 0.2, 0.2));
            obj.render(MMatr, VMatr, PMatr, Lights, GL_TRIANGLES);
        }

        glfwPollEvents();
        glfwSwapBuffers(window);
        if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose(window, 1);
        }
    }

    return 0;
}
