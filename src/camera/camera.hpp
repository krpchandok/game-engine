#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Converts world space to view space by generating view matrix

enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class Camera {
    glm::vec3 position{0.0f};
    glm::vec3 front{0.0f, 0.0f, -1.0f};
    glm::vec3 up{0.0f, 1.0f, 0.0f};
    glm::vec3 right{1.0f, 0.0f, 0.0f};
    glm::vec3 worldUp{0.0f, 1.0f, 0.0f};

    float yaw{-90.0f};
    float pitch{0.0f};

    float movementSpeed{2.5f};
    float mouseSensitivity{0.1f};
    float zoom{45.0f};

    public:
        Camera() = default;
        Camera(const glm::vec3& pos, const glm::vec3& upVec, float yawAngle, float pitchAngle);

        glm::mat4 getViewMatrix() const;

        void processKeyboard(Camera_Movement direction, float deltaTime);
        void processMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);
        void processMouseScroll(float yoffset);

        const glm::vec3& getPosition() const;
        const glm::vec3& getFront() const;
        const glm::vec3& getUp() const;
        const glm::vec3& getRight() const;
        float getYaw() const;
        float getPitch() const;
        float getZoom() const;

    private:
        void updateCameraVectors();
};

