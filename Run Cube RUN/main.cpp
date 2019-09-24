#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <sstream>

#include "player.hpp"
#include "solid.hpp"
#include "camera.hpp"
#include "platformGen.hpp"
#include "score.hpp"
#include "background.hpp"

int main(int argc, char *argv[]) {
  std::srand(time(NULL));

  sf::Color c_Green(0, 255, 0);
  sf::Color c_Gray(170, 170, 170);
  sf::Color c_Red(255, 50, 50);
  sf::Color c_Blue(0, 0, 255);
  sf::Color c_Yellow(255, 255, 0);
  sf::Color c_Lime(0, 255, 0);
  sf::Color c_Orchid(218, 112, 214);
  sf::Color c_Silver(192, 192, 192);
  sf::Color c_DeepSkyBlue(0, 191, 255);
  sf::Color c_AquaMarine(127, 255, 212);

  int counter;
  int timer;
  int restart;
  int maxSolids;

  sf::RenderWindow mainWindow(sf::VideoMode(1080, 720), "Run Cube RUN!!", sf::Style::Titlebar | sf::Style::Close);
  mainWindow.setFramerateLimit(60);

  /*----------SETUP----------*/

  Player objPlayer;
  Camera mainCamera;
  //Background starBackground;

  sf::Font scoreFont;
  scoreFont.loadFromFile("Resources/Fonts/STIX-Regular.otf");

  sf::Text currentScore;
  sf::Text info;

  sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1080.0f, 720.0f));

  std::vector<Solid>::const_iterator iterSolid;
  std::vector<Solid> solidArray;

  A:

  timer = 0;
  restart = 0;
  maxSolids = 20;

  mainCamera.move(540, 360);

  Solid solid1(1080, 32, 0, 720-32);
  Solid solid2(1080, 32, 0, 0);
  solidArray.push_back(solid1);
  solidArray.push_back(solid2);

  currentScore.setFont(scoreFont);
  currentScore.setCharacterSize(100);
  currentScore.setPosition(130.0f, 160.0f);
  currentScore.setColor(c_Green);

  info.setFont(scoreFont);
  info.setCharacterSize(30);
  info.setPosition(130.0f, 280.0f);
  info.setColor(c_Green);

  currentScore.setString("Run Cube RUN!!");
  info.setString("<-- left arrow key \n--> right arrow key \n^ up arrow key \n\n*Hold up to float* \n\n\n                                       Press Space to Start");
  mainWindow.draw(currentScore);
  mainWindow.draw(info);
  counter = 0;
  for (iterSolid = solidArray.begin(); iterSolid != solidArray.end(); iterSolid++) {
    mainWindow.draw(solidArray[counter].body);
    counter++;
  }
  objPlayer.draw(mainWindow);
  mainWindow.display();

  while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && mainWindow.isOpen()) {
    sf::Event evnt;
    while(mainWindow.pollEvent(evnt)) {
      switch (evnt.type) {
        case sf::Event::Closed:
          mainWindow.close();
        break;
      }
    }
  }

  mainWindow.clear();

  currentScore.setCharacterSize(50);
  currentScore.setPosition(0.0f, 0.0f);
  currentScore.setColor(c_Red);

  while(mainWindow.isOpen() && objPlayer.playerCheck()) {
    sf::Event evnt;
    while(mainWindow.pollEvent(evnt)) {

      switch (evnt.type) {
        case sf::Event::Closed:
          mainWindow.close();
        break;
      }
    }
    /*----------GAME LOOP----------*/

    if(timer == 1000 || timer == 2000 || timer == 3000 || timer == 4000 || timer == 5000 || timer == 6000 || timer == 7000 || timer == 8000 || timer == 9000 || timer == 10000) {
      mainCamera.GoFaster();
      objPlayer.GoFaster();
      if(maxSolids > 8) {
        maxSolids -= 1;
      }
    }

    std::stringstream ss;
    timer++;
    ss << "Score: ";
    ss << timer/30;
    currentScore.setString( ss.str().c_str() );

    checkForOutOfBounds(solidArray, mainCamera);
    toBeAdded(solidArray, mainCamera, maxSolids);

    objPlayer.didPlayerDie(mainCamera);
    objPlayer.step(solidArray);
    //starBackground.move(mainCamera);

    currentScore.move(mainCamera.getScrollSpeed(), 0);
    mainCamera.step();

    view.setCenter(mainCamera.getX(), mainCamera.getY());

    mainWindow.clear();

    mainWindow.setView(view);

    //starBackground.draw(mainWindow);

    counter = 0;
    for (iterSolid = solidArray.begin(); iterSolid != solidArray.end(); iterSolid++) {
      mainWindow.draw(solidArray[counter].body);
      counter++;
    }

    objPlayer.draw(mainWindow);

    mainWindow.draw(currentScore);

    mainWindow.display();
  }

  mainWindow.clear();

  info.setCharacterSize(100);
  info.setPosition(mainCamera.getX() - 490, mainCamera.getY() + 10);
  info.setString("Press Space to try again");

  currentScore.setCharacterSize(100);
  currentScore.setPosition(mainCamera.getX() - 210, mainCamera.getY() - 60);
  currentScore.setColor(c_Green);

  std::stringstream ss;
  ss << "Score: ";
  ss << timer/30;
  currentScore.setString( ss.str().c_str() );

  mainWindow.draw(currentScore);
  mainWindow.draw(info);
  mainWindow.display();

  while(mainWindow.isOpen()) {
    sf::Event evnt;
    while(mainWindow.pollEvent(evnt)) {

      switch (evnt.type) {
        case sf::Event::Closed:
          mainWindow.close();
        break;
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
      restart = 1;
      break;
    }

  }

  if(restart) {
    objPlayer.playerRestart();
    mainCamera.Reset();
    solidArray.erase(solidArray.begin(), solidArray.end());
    goto A;
  }

  /*----------GAME/PROGRAM ENDED----------*/

  return 0;
}
