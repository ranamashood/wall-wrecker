#ifndef BALL_H
#define BALL_H

#include <raylib.h>

struct Ball {
  int x, y;
  int radius;
  Vector2 speed;
};

struct Ball createBall(int radius);
void moveBall(struct Ball *ball);

#endif // !BALL_H
