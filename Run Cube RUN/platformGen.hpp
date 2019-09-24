#ifndef PLATFORMGEN
#define PLATFORMGEN

#include <SFML/Graphics.hpp>
#include <iostream>
#include "camera.hpp"
#include "solid.hpp"

void checkForOutOfBounds(std::vector<Solid> &solidArray, Camera camera);
void toBeAdded(std::vector<Solid> &solidArray, Camera camera, int maxSolids);

#endif
