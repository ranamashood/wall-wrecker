#ifndef BALL_H
#define BALL_H

#include <raylib.h>

struct Ball {
  Vector2 pos;
  int radius;
  Vector2 speed;
};

struct Ball createBall(int radius, Vector2 speed);
void moveBall(struct Ball *ball);
bool ballCollidesUpperWall(struct Ball ball);
bool ballCollidesSideWalls(struct Ball ball);
bool ballCollidesPlayer(struct Ball ball, Rectangle player);

#endif // !BALL_H
