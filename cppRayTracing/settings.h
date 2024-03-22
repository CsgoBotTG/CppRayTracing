#pragma once
#include <string>
#include <math.h>
// settings
float WIDTH = 1200;
float HEIGHT = 800;
float HALF_WIDTH = WIDTH / 2;
float HALF_HEIGHT = HEIGHT / 2;
int FPS = 60;
int TILE = 100;
std::string TITLE = "CppRayCasting";

// ray casting settings
float FOV = 3.1415927410125732421 / 3;
float HALF_FOV = FOV / 2;
int NUM_RAYS = 120;
int MAX_DEPTH = 800;
float DELTA_ANGLE = FOV / NUM_RAYS;
float DIST = NUM_RAYS / (2 * tan(HALF_FOV));
float PROJ_COEFF = 3 * DIST * TILE;
float SCALE = WIDTH / NUM_RAYS;