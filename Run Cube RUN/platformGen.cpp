#include "platformGen.hpp"

void checkForOutOfBounds(std::vector<Solid> &solidArray, Camera camera) {
  int counter;
  std::vector<Solid>::const_iterator iterSolid;
  counter = 0;

  for (iterSolid = solidArray.begin(); iterSolid != solidArray.end(); iterSolid++) {

    if((solidArray[counter].body.getGlobalBounds().width + solidArray[counter].body.getPosition().x) < (camera.getX() - 540)) {

      // if(counter == 0) {
      //   solidArray.erase(solidArray.begin());
      // } else {
      //   solidArray.erase(solidArray.begin() + (counter - 1));
      // }

      solidArray.erase(solidArray.begin() + counter);

    }

    counter++;

  }

  //std::cout << counter << std::endl;
  //std::cout << "Size: " <<solidArray.size() << std::endl;

}

void toBeAdded(std::vector<Solid> &solidArray, Camera camera, int maxSolids) {

  if(solidArray.size() < maxSolids) {

    // Solid x(1080, 32, camera.getX() + (1080/2), 0);
    // Solid y(1080, 32, camera.getX() + (1080/2), (720-32));
    // solidArray.push_back(x);
    // solidArray.push_back(y);

    Solid s(rand() % 200 + 32, rand() % 106 + 32, camera.getX() + 540 + rand() % 500, rand() % 700 - 84);
    s.setColor( rand() % 255, rand() % 255, rand() %255 );
    solidArray.push_back(s);
  }

  //std::cout << solidArray.size() << std::endl;

}
