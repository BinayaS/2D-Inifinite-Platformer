#include "player.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

float sign(float x) {
  return (x > 0) - (x < 0);
}

bool place_meeting(int x, int y, int width, int height, std::vector<Solid> solidArray) {
  int counter;
  std::vector<Solid>::const_iterator iterSolid;
  counter = 0;
  for (iterSolid = solidArray.begin(); iterSolid != solidArray.end(); iterSolid++) {
    if(solidArray[counter].body.getGlobalBounds().contains(x, y)) {
      return true;
    }
    if(solidArray[counter].body.getGlobalBounds().contains(x + width, y + height)) {
      return true;
    }
    if(solidArray[counter].body.getGlobalBounds().contains(x, y + height)) {
      return true;
    }
    if(solidArray[counter].body.getGlobalBounds().contains(x + width, y)) {
      return true;
    }
    counter++;
  }
  return false;
}

void Player::didPlayerDie(Camera camera) {
  if(body.getPosition().x < camera.getX() - (1180/2)) {
    alive = 0;
  }

  if(body.getPosition().y < -32) {
    alive = 0;
  }

  if(body.getPosition().y > 752) {
    alive = 0;
  }
}

Player::Player() {

  alive = 1;

  maxRunSpeed = 6.6;//4.8;
  maxFallSpeed = 14;//12
  maxJetSpeed = 4.3;//4

  xSpeed = 0;
  ySpeed = 0;

  frict = 0.2;
  accel = 0.4;

  weight = 0.5;

  jetPower = 0.6; //0.12;
  jumpPower = 10;

  body.setSize(sf::Vector2f(32.0f, 32.0f));
  body.setPosition(1080/2, 720/2);

  body.setFillColor(sf::Color(0, 250, 100));
}

void Player::draw(sf::RenderWindow &mainWindow) {
  mainWindow.draw(body);
}

void Player::step(std::vector<Solid> solidArray){

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    if(xSpeed > -maxRunSpeed) {
      xSpeed -= accel;
    }
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    if(xSpeed < maxRunSpeed) {
      xSpeed += accel;
    }
  }

  if( !(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) &&
      !(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) {
    if(xSpeed != 0) {
      xSpeed -= sign(xSpeed) * frict;
      if(xSpeed > 0 && xSpeed < 0.9) {
        xSpeed = 0;
      }
      if(xSpeed < 0 && xSpeed > -0.9) {
        xSpeed = 0;
      }
    }
  }

//std::cout << "body.getPosition().x: " << body.getPosition().x << std::endl;
//std::cout << "body.getPosition().x + body.getGlobalBounds().width : " << body.getPosition().x + body.getGlobalBounds().width << std::endl;
//std::cout << "body.getGlobalBounds().width: " << body.getGlobalBounds().width << std::endl;
//std::cout << "xSpeed: " << xSpeed << std::endl;

//std::cout << "body.getPosition().y: " << body.getPosition().y << std::endl;
//std::cout << "body.getPosition().y + body.getGlobalBounds().height : " << body.getPosition().y + body.getGlobalBounds().height << std::endl;


  if(!place_meeting(body.getPosition().x + xSpeed, body.getPosition().y, body.getGlobalBounds().width, body.getGlobalBounds().height, solidArray)) {
    body.move(xSpeed, 0);
  } else {
    while (!place_meeting(body.getPosition().x + sign(xSpeed), body.getPosition().y, body.getGlobalBounds().width, body.getGlobalBounds().height, solidArray)) {
      body.move(sign(xSpeed), 0);
    }
    xSpeed = 0;
  }

  switch (vertState) {
    case verticalState::onGround:

    if(!place_meeting(body.getPosition().x, body.getPosition().y + 1, body.getGlobalBounds().width, body.getGlobalBounds().height, solidArray)) {
      vertState = verticalState::falling;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      ySpeed = -jumpPower;
      vertState = verticalState::jumping;
    }

    break;

    case verticalState::jumping:

    if(ySpeed >= 0) {
      vertState = verticalState::falling;
    }

    break;

    case verticalState::jetpacking:

    if(ySpeed > -maxJetSpeed && !place_meeting(body.getPosition().x, body.getPosition().y + 1, body.getGlobalBounds().width, body.getGlobalBounds().height, solidArray)) {
      ySpeed -= jetPower + weight + std::max(0, abs(ySpeed) / 20);
    }

    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      vertState = verticalState::falling;
    }

    break;

    case verticalState::falling:

    if(place_meeting(body.getPosition().x, body.getPosition().y + 1, body.getGlobalBounds().width, body.getGlobalBounds().height, solidArray)) {
      vertState = verticalState::onGround;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      vertState = verticalState::jetpacking;
    }

    break;
  }

  //std::cout << vertState << std::endl;

  if(vertState != verticalState::onGround) {
    if(ySpeed < maxFallSpeed) {
      ySpeed += weight;
    }
  }

  if(!place_meeting(body.getPosition().x, body.getPosition().y + ySpeed, body.getGlobalBounds().width, body.getGlobalBounds().height, solidArray)) {
    body.move(0, ySpeed);
  } else {
    while (!place_meeting(body.getPosition().x, body.getPosition().y + sign(ySpeed), body.getGlobalBounds().width, body.getGlobalBounds().height, solidArray)) {
      body.move(0, sign(ySpeed));
    }
    ySpeed = 0;
  }

}

void Player::setColor(int r, int g, int b) {
  body.setFillColor(sf::Color(r, g, b));
}

Player::~Player() {
}
