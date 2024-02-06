#include "ball.h"
#include "constants.h"
#include <raylib.h>

struct Ball createBall(int radius, Vector2 speed) {
  struct Ball ball = {
      (float)SCREEN_WIDTH / 2,
      radius * 2,
      radius,
      speed,
  };

  return ball;
}

void moveBall(struct Ball *ball) {
  float dt = GetFrameTime() * DT_CONST;
  ball->pos.x += ball->speed.x * dt;
  ball->pos.y += ball->speed.y * dt;
}

bool ballCollidesUpperWall(struct Ball ball) {
  return (ball.pos.y - ball.radius) <= 0;
}

bool ballCollidesSideWalls(struct Ball ball) {
  return (ball.pos.x + ball.radius) >= SCREEN_WIDTH ||
         (ball.pos.x - ball.radius) <= 0;
}

bool ballCollidesPlayer(struct Ball ball, Rectangle player) {
  return CheckCollisionCircleRec(ball.pos, ball.radius, player);
}
