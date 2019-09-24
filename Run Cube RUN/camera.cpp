#include "camera.hpp"

Camera::Camera() {
  scrollSpeed = 4;
}

Camera::~Camera() {
}

void Camera::move(int x, int y) {
  this->x = x;
  this->y = y;
}

void Camera::step() {
  x += scrollSpeed;
}
