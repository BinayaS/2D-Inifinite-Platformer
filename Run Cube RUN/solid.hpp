#ifndef SOLID
#define SOLID

#include <SFML/Graphics.hpp>

class Solid {
public:
  Solid(int width, int height, int posx, int posy);
  ~Solid();

  void setPosition(int posx, int posy);
  void setSize(int width, int height);
  void setColor(int r, int g, int b);

  sf::RectangleShape body;

private:

};

#endif
