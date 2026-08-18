// light.hpp
#pragma once
#include <glm/glm.hpp>
#include "shaders/shader.hpp"

class PointLight {
public:
    glm::vec3 position;
    glm::vec3 color;

    float ambientStrength;
    float specularStrength;

    PointLight(const glm::vec3& pos, const glm::vec3& col,
                float ambient = 0.1f, float specular = 0.5f)
        : position(pos), color(col), ambientStrength(ambient), specularStrength(specular) {}

    void applyToShader(Shader& shader) const {
        shader.setVec3("lightPos", position);
        shader.setVec3("lightColor", color);
        shader.setFloat("ambientStrength", ambientStrength);
        shader.setFloat("specularStrength", specularStrength);
    }
};