#include "background.hpp"

Background::Background() {

  tex_SolidBackground.loadFromFile("Resources/Background/SolidBackground.png");
  //tex_BigWhiteStars.loadFromFile("Resources/Background/BigWhiteStars.png");
  tex_MediumWhiteStars.loadFromFile("Resources/Background/MediumWhiteStars.png");
  tex_SmallWhiteStars.loadFromFile("Resources/Background/SmallWhiteStars.png");
  //tex_PurpleStars.loadFromFile("Resources/Background/PurpleStars.png");
  tex_RedStars.loadFromFile("Resources/Background/RedStars.png");
  tex_YellowStars.loadFromFile("Resources/Background/YellowStars.png");
  //tex_SmallBlueStars.loadFromFile("Resources/Background/SmallBlueStars.png");
  tex_SmallerBlueStars.loadFromFile("Resources/Background/SmallerBlueStars.png");


  spr_SolidBackground.setTexture(tex_SolidBackground);
  //spr_BigWhiteStars.setTexture(tex_BigWhiteStars);
  spr_MediumWhiteStars.setTexture(tex_MediumWhiteStars);
  spr_SmallWhiteStars.setTexture(tex_SmallWhiteStars);
  //spr_PurpleStars.setTexture(tex_PurpleStars);
  spr_RedStars.setTexture(tex_RedStars);
  spr_YellowStars.setTexture(tex_YellowStars);
  //spr_SmallBlueStars.setTexture(tex_SmallBlueStars);
  spr_SmallerBlueStars.setTexture(tex_SmallerBlueStars);


  spr_SolidBackground.setPosition(0,0);
  //spr_BigWhiteStars.setPosition(0,0);
  spr_MediumWhiteStars.setPosition(0,0);
  spr_SmallWhiteStars.setPosition(0,0);
  //spr_PurpleStars.setPosition(0,0);
  spr_RedStars.setPosition(0,0);
  spr_YellowStars.setPosition(0,0);
  //spr_SmallBlueStars.setPosition(0,0);
  spr_SmallerBlueStars.setPosition(0,0);

}

Background::~Background() {
}

void Background::draw(sf::RenderWindow &window) {
  window.draw(spr_SolidBackground);
  //window.draw(spr_BigWhiteStars);
  window.draw(spr_MediumWhiteStars);
  window.draw(spr_SmallWhiteStars);
//  window.draw(spr_PurpleStars);
  window.draw(spr_RedStars);
  window.draw(spr_YellowStars);
//  window.draw(spr_SmallBlueStars);
  window.draw(spr_SmallerBlueStars);
}

void Background::move(Camera camera) {

  int speed = camera.getScrollSpeed();

  spr_SolidBackground.move(speed, 0);
  //spr_BigWhiteStars.move(speed - 1, 0);
  spr_MediumWhiteStars.move(speed - 1.7, 0);
  spr_SmallWhiteStars.move(speed - 2.1, 0);
  //spr_PurpleStars.move(speed - 2.4, 0);
  spr_RedStars.move(speed - 1.3, 0);
  spr_YellowStars.move(speed - 1.9 , 0);
  //spr_SmallBlueStars.move(speed - 2.2, 0);
  spr_SmallerBlueStars.move(speed - 2.6, 0);

}
