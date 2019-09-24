#ifndef BACKGROUND
#define BACKGROUND

#include <SFML/Graphics.hpp>
#include "camera.hpp"

class Background {
public:
  Background();
  ~Background();
  void draw(sf::RenderWindow &window);
  void move(Camera camera);

private:

  sf::Texture tex_SolidBackground;
  sf::Texture tex_BigWhiteStars;
  sf::Texture tex_MediumWhiteStars;
  sf::Texture tex_SmallWhiteStars;
  sf::Texture tex_PurpleStars;
  sf::Texture tex_RedStars;
  sf::Texture tex_YellowStars;
  sf::Texture tex_SmallBlueStars;
  sf::Texture tex_SmallerBlueStars;

  sf::Sprite spr_SolidBackground;
  sf::Sprite spr_BigWhiteStars;
  sf::Sprite spr_MediumWhiteStars;
  sf::Sprite spr_SmallWhiteStars;
  sf::Sprite spr_PurpleStars;
  sf::Sprite spr_RedStars;
  sf::Sprite spr_YellowStars;
  sf::Sprite spr_SmallBlueStars;
  sf::Sprite spr_SmallerBlueStars;

};


#endif
