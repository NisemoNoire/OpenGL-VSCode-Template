#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum class MOVEMENT {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

/* Default camera values */
constexpr float YAW         = -90.0f;
constexpr float PITCH       = 0.0f;
constexpr float SPEED       = 2.5f;
constexpr float SENSITIVITY = 0.1f;
constexpr float ZOOM        = 45.0f;

class Camera {
public:
    /* attributes */
    glm::vec3 _position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 _front    = glm::vec3(0.0f, 0.0f, -1.0f); // right-hand system
    glm::vec3 _up       = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 _right    = glm::vec3(1.0f, 0.0f, 0.0f);
    glm::vec3 _worldUp  = glm::vec3(0.0f, 1.0f, 0.0f);

    /* options */
    float _yaw              = YAW;
    float _pitch            = PITCH;
    float _moveSpeed        = SPEED;
    float _mouseSensitivity = SENSITIVITY;
    float _zoom             = ZOOM;

    /* 构造函数 */
    Camera() = default;
    Camera(glm::vec3 position)
        : _position(position)
    { }
    Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
        : _position(position)
        , _worldUp(up)
        , _yaw(yaw)
        , _pitch(pitch)
    {
        updateCameraVectors();
    }
    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
        : Camera(glm::vec3(posX, posY, posZ), glm::vec3(upX, upY, upZ), yaw, pitch)
    {
        updateCameraVectors();
    }
    ~Camera() = default;

    /* view matrix */
    glm::mat4 getViewMatrix()
    {
        return glm::lookAt(_position, _position + _front, _up);
    }

    /* keyboard event */
    void move(MOVEMENT direction, float deltaTime)
    {
        float velocity = _moveSpeed * deltaTime;
        switch (direction) {
        case MOVEMENT::FORWARD:
            _position += _front * velocity;
            break;
        case MOVEMENT::BACKWARD:
            _position -= _front * velocity;
            break;
        case MOVEMENT::LEFT:
            _position -= _right * velocity;
            break;
        default:
            _position += _right * velocity;
            break;
        }
        _position.y = 0.0f;
    }

    /* mouse event */
    void sight(float xoffset, float yoffset, GLboolean constrainPitch = true)
    {
        xoffset *= _mouseSensitivity;
        yoffset *= _mouseSensitivity;

        _yaw   += xoffset;
        _pitch += yoffset;

        if (constrainPitch) {
            if (_pitch > 89.0f) _pitch = 89.0f;
            if (_pitch < -89.0f) _pitch = -89.0f;
        }

        updateCameraVectors();
    }

    /* scroll event */
    void zoom(float yoffset)
    {
        _zoom -= yoffset;
        if (_zoom > 45.0f) _zoom = 45.0f;
        if (_zoom < 1.0f) _zoom = 1.0f;
    }

private:
    void updateCameraVectors()
    {
        /* calculate the Front vector */
        glm::vec3 front;
        front.x = cos(glm::radians(_pitch)) * cos(glm::radians(_yaw));
        front.y = sin(glm::radians(_pitch));
        front.z = cos(glm::radians(_pitch)) * sin(glm::radians(_yaw));
        _front  = glm::normalize(front);
        /* calculate Right & LocalUp */
        _right = glm::normalize(glm::cross(_front, _worldUp)); // perpendicular to F-WU plane
        _up    = glm::normalize(glm::cross(_right, _front));   // perpendicular to R-F plane
    }
};