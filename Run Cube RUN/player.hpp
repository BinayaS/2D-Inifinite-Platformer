#ifndef PLAYER
#define PLAYER
#include <SFML/Graphics.hpp>
#include "solid.hpp"
#include "camera.hpp"

class Player {
public:
  Player();
  ~Player();
  void draw(sf::RenderWindow &window);
  void step(std::vector<Solid> solidArray);
  void setColor(int r, int g, int b);
  void didPlayerDie(Camera camera);

  int playerCheck() { return alive; }
  void playerDied() { alive = 0; }
  void playerRestart() { alive = 1; body.setPosition(1080/2, 720/2); maxRunSpeed = 6.6; }
  void GoFaster() { maxRunSpeed += 1; }

private:

  enum verticalState {
    onGround,
    jumping,
    jetpacking,
    falling,
    shooting
  };

  sf::RectangleShape body;

  int alive;

  float maxRunSpeed;
  float maxFallSpeed;
  float maxJetSpeed;

  float xSpeed;
  float ySpeed;

  float frict;
  float accel;

  float weight;

  float jetPower;
  float jumpPower;

  int vertState = verticalState::onGround;
};

#endif
