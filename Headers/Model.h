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

#include "tiny_obj_loader.h"

using namespace std;


/// <summary>
/// Структура с данными про объект *.obj файла.
/// </summary>
struct OBJData {
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> textures;
    std::vector<glm::vec3> normals;
    std::string textureName;
    std::string bumpName;
};


/// <summary>
/// Структура с данными про материал объекта. Содержит конструктор по умолчанию с настройками "изумруд"
/// </summary>
struct Material
{
    glm::vec3 ka; // коэф. фонового отражения (цвет фонового освещения)
    glm::vec3 kd; // коэф. диффузного отражения (цвет объекта)
    glm::vec3 ks; // коэф. зеркального блика
    GLfloat shininess; // показатель глянцевости
    // Значения по умолчанию
    Material()
    {
        ka = glm::vec3(0.0215, 0.1745, 0.0215);
        kd = glm::vec3(0.07568, 0.61424, 0.07568);
        ks = glm::vec3(0.633, 0.727811, 0.633);
        shininess = 128 * 0.6;
    };
};
/// <summary>
/// Структура с описанием параметров фонового освещения
/// </summary>
struct DirLight
{
    /// <summary>
    /// Направление
    /// </summary>
    glm::vec3 direction;
    //Параметры света
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
};
/// <summary>
/// Структура с описанием точечного источника света
/// </summary>
struct PointLight
{
    /// <summary>
    /// Координаты
    /// </summary>
    glm::vec3 position;
    //Затухание
    float constant;
    float linear;
    float quadratic;

    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
};
/// <summary>
/// Структура с описанием направленного источника света
/// </summary>
struct SpotLight
{
    //Местоположение и направление
    glm::vec3 position;
    glm::vec3 direction;
    //Радиус луча
    float cutOff;
    float outerCutOff;

    float constant;
    float linear;
    float quadratic;

    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
};

/// <summary>
/// Структура с описанием источников света на сцене
/// </summary>
struct LightsInfo {
    /// <summary>
    /// Параметры фонового освещения
    /// </summary>
    DirLight dirLight;
    /// <summary>
    /// Массив с точечными источниками света
    /// </summary>
    std::vector<PointLight> pointLights;
    /// <summary>
    /// Массив с направленными источниками света
    /// </summary>
    std::vector<SpotLight> spotLights;

    //Количество точечных и направленных источников света
    int numPLights;
    int numSLights;

};



/// <summary>
/// Основной класс модели объекта. Содержит методы для загрузки параметров и рендеринга.
/// </summary>
class Model
{
public:
    /// <summary>
    /// Простой конструктор - создаёт массив вершин, пока пустой. И подключает окно.
    /// </summary>
    /// <param name="w">Указатель на окно.</param>
    /// <param name="mode">Тип модели. 0 - цветная, 1 - с материалом, 2 - с текстурой.</param>
    Model(GLFWwindow* w, GLuint mode = 0) {
        glGenVertexArrays(1, &vao);
        window = w;
        modelMode = mode;
    };

    //Деструктор. Так как динамической памяти нет, то он ничего не делает.
    ~Model() {};


    auto loadOBJTiny(const string& objPath, const std::string& mtlBaseDir, vector<OBJData> &objData) -> void;


    /// <summary>
    /// Рендер с поддержкой освещения
    /// </summary>
    /// <param name="modelMatrix">Матрица модели.</param>
    /// <param name="viewMatrix">Матрица вида.</param>
    /// <param name="projMatrix">Матрица проекции.</param>
    /// <param name="lights">Параметры освещения сцены.</param>
    /// <param name="mode">Режим рисования.</param>
    void render(glm::mat4 modelMatrix, glm::mat4 viewMatrix, glm::mat4 projMatrix, LightsInfo lights ,GLuint mode);

    /// <summary>
    /// Метод для загрузки координат вершин.
    /// </summary>
    /// <param name="verteces">Массив с координатами.</param>
    /// <param name="count">Размер массива.</param>
    void load_coords(glm::vec3* verteces, size_t count);

    /// <summary>
    /// Метод для загрузки нормалей
    /// </summary>
    /// <param name="normals">Массив с нормалями.</param>
    /// <param name="count">Размер массива.</param>
    void load_normals(glm::vec3* normals, size_t count);

    /// <summary>
    /// Метод для загрузки текстурных координат.
    /// </summary>
    /// <param name="tex">Массив с текстурными координатами.</param>
    /// <param name="count">Размер массива.</param>
    void load_texcoord(glm::vec2* tex, size_t count);

    /// <summary>
    /// Метод для загрузки текстур.
    /// </summary>
    /// <param name="path">Путь к основной текстуре.</param>
    /// <param name="pathtomap">Путь к карте отражений. (может быть пустым)</param>
    void load_texture(string path, string pathtomap);

    /// <summary>
    /// Метод для загрузки шейдеров. С целью примера загружает только вершинный и фрагментный шейдеры
    /// В результате выполнения будет скомпонована шейдерная программа.
    /// </summary>
    /// <param name="vect">Путь к вершинному шейдеру</param>
    /// <param name="frag">Путь к фрагментному шейдеру</param>
    void load_shaders(const char* vect, const char* frag);

    /// <summary>
    /// Метод для задания параметров материала
    /// </summary>
    /// <param name="a">Фоновый свет.</param>
    /// <param name="d">Диффузный свет.</param>
    /// <param name="s">Отражённый свет.</param>
    /// <param name="shine">Глянцевость.</param>
    void setMaterial(glm::vec3 a, glm::vec3 d, glm::vec3 s, GLfloat shine);

private:

    /// <summary>
    /// ID массива вершин
    /// </summary>
    GLuint vao = -1;    //Начальное значение - максимальное число, заведомо невозможное
    /// <summary>
    /// Количество вершин
    /// </summary>
    size_t verteces_count = 0;
    /// <summary>
    /// Количество индексов
    /// </summary>
    size_t indices_count = 0;

    /// <summary>
    /// ID шейдерной программы
    /// </summary>
    GLuint shader_programme = -1;//Начальное значение - максимальное число, заведомо невозможное

    /// <summary>
    /// Указатель на окно
    /// </summary>
    GLFWwindow *window;

    /// <summary>
    /// Материал из которого состоит объект
    /// </summary>
    Material material;

    /// <summary>
    /// Вспомогательная переменная, устанавливающая тип модели - с цветами или материалом/текстурой
    /// </summary>
    GLuint modelMode = 0;

    /// <summary>
    /// Текстура
    /// </summary>
    GLuint texture;
    /// <summary>
    /// Карта отражений
    /// </summary>
    GLuint texturemap;
};
