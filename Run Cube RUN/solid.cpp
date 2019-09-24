#include "solid.hpp"

Solid::Solid(int width, int height, int posx, int posy) {
  body.setSize(sf::Vector2f(width, height));
  //body.setOrigin(body.getSize()/2.0f);
  body.setPosition(posx, posy);
  body.setFillColor(sf::Color(255, 255, 255));
}

Solid::~Solid() {
}

void Solid::setSize(int width, int height) {
  body.setSize(sf::Vector2f(width, height));
}

void Solid::setPosition(int posx, int posy) {
  body.setPosition(posx, posy);
}

void Solid::setColor(int r, int g, int b) {
  body.setFillColor(sf::Color(r, g, b));
}
