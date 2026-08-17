#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"
#include <string>

using namespace std;

class Texture {
    int width;
    int height;
    int channels;

    public:
        Texture(const string& fn) {
            const char* filename = fn.c_str();
            unsigned char* data = stbi_load(filename, &width, &height, &channels, 0);
                
            if (!data) {
                std::cout << "Failed to load texture" << std::endl;
            }

            GLuint texture;
            glGenTextures(1, &texture);


            glBindTexture(GL_TEXTURE_2D, texture);  
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

            stbi_image_free(data);  
        }

        void generate()
};