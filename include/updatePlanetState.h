#ifndef UPDATE_H
#define UPDATE_H

#include <vector>

#include "celestialBody.h"
#include "picture.h"

void updateBodies(std::vector<CelestialBody> &planets, const int dt);


void drawBodies(const std::vector<CelestialBody> &planets, Picture &pic,
                size_t systemSize, bool finalPos = false);

#endif
