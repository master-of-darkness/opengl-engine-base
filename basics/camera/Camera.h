//
// Created by an on 03.03.24.
//

#ifndef OPENGL_ENGINE_CAMERA_H
#define OPENGL_ENGINE_CAMERA_H

namespace cppzt::basics{
    class Camera {
    public:
        Camera(glm::vec3 position, float fov);
        void rotate(float x, float y, float z);
        void updateVectors();

        glm::mat4 getProjection();
        glm::mat4 getView();

        glm::vec3 front;
        glm::vec3 up;
        glm::vec3 right;

        glm::vec3 position;
        float fov;
        glm::mat4 rotation;
    };
}


#endif //OPENGL_ENGINE_CAMERA_H
