#include "ball.h"
#include "constants.h"
#include <raylib.h>

struct Ball createBall(int radius) {
  struct Ball ball = {
      .x = SCREEN_WIDTH / 2,
      .y = 0,
      .radius = radius,
      .speed = {0, 5},
  };

  return ball;
}

void moveBall(struct Ball *ball) {
  ball->x += ball->speed.x;
  ball->y += ball->speed.y;
}
