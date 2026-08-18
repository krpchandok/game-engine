#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "shaders/shader.hpp"
#include <string>
#include <vector>
using namespace std;

// vertex array data for opengl
struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

struct Texture {
    unsigned int id;
    string type;
};

class Mesh {
    vector<Vertex> vertices; 
    vector<GLuint> indices; 
    vector<Texture> textures; 
    GLuint VBO, VAO, EBO;

    public:
        Mesh(vector<Vertex>& vertices, vector<GLuint>& indices, vector<Texture>& textures);

        void draw(Shader& shader);

};