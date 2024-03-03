//
// Created by an on 03.03.24.
//

#include "Camera.h"
#include "../../utils/Window.h"

Camera::Camera(glm::vec3 position, float fov) : position(position), fov(fov), rotation(1.0f){
    updateVectors();
}

void Camera::updateVectors(){
    front = glm::vec3(rotation * glm::vec4(0,0,-1,1));
    right = glm::vec3(rotation * glm::vec4(1,0,0,1));
    up = glm::vec3(rotation * glm::vec4(0,1,0,1));
}

void Camera::rotate(float x, float y, float z){
    rotation = glm::rotate(rotation, z, glm::vec3(0,0,1));
    rotation = glm::rotate(rotation, y, glm::vec3(0,1,0));
    rotation = glm::rotate(rotation, x, glm::vec3(1,0,0));

    updateVectors();
}

glm::mat4 Camera::getProjection(){

    float aspect = (float)Window::width / (float)Window::height;
    return glm::perspective(fov, aspect, 0.1f, 100.0f);
}

glm::mat4 Camera::getView(){
    return glm::lookAt(position, position+front, up);
}
