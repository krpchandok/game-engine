#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform {
    glm::vec3 position{0.0f};
    glm::vec3 rotation{0.0f}; 
    glm::vec3 scale{1.0f};

    public:
        Transform() = default;
        Transform(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scl);

        glm::mat4 getModelMatrix() const;

        void setPosition(const glm::vec3& pos);
        void setRotation(const glm::vec3& rot);
        void setScale(const glm::vec3& scl);

        const glm::vec3& getPosition() const;
        const glm::vec3& getRotation() const;
        const glm::vec3& getScale() const;
};