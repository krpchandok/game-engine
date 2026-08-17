#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "transform.hpp"
// Converts the raw position of the object to its
// position in the world space by producing the model matrix

Transform::Transform(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scl)
    : position(pos), rotation(rot), scale(scl) {}

glm::mat4 Transform::getModelMatrix() const {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, scale);
    return model;
}

void Transform::setPosition(const glm::vec3& pos) {
    position = pos;
}

void Transform::setRotation(const glm::vec3& rot) {
    rotation = rot;
}

void Transform::setScale(const glm::vec3& scl) {
    scale = scl;
}

const glm::vec3& Transform::getPosition() const {
    return position;
}

const glm::vec3& Transform::getRotation() const {
    return rotation;
}

const glm::vec3& Transform::getScale() const {
    return scale;
}