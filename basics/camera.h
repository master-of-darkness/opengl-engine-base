#pragma once

class Camera {
    void updateVectors();
public:
    Camera(glm::vec3 position, float fov);

    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;

    glm::vec3 position;
    float fov;
    glm::mat4 rotation;

    void rotate(float x, float y, float z);

    glm::mat4 getView();
};

