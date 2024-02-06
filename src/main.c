#include "ball.h"
#include "constants.h"
#include "player.h"
#include <raylib.h>
#include <raymath.h>

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Breakout");
  SetTargetFPS(60);

  struct Player player = createPlayer(150, 15, 10);
  struct Ball ball = createBall(13, (Vector2){4, 4});

  while (!WindowShouldClose()) {
    movePlayer(&player);
    moveBall(&ball);

    Rectangle playerRect = {player.pos.x, player.pos.y, player.size.x,
                            player.size.y};

    if (ballCollidesUpperWall(ball) || ballCollidesPlayer(ball, playerRect)) {
      ball.speed = Vector2Reflect(ball.speed, INVERT_Y);
    } else if (ballCollidesSideWalls(ball)) {
      ball.speed = Vector2Reflect(ball.speed, INVERT_X);
    }

    BeginDrawing();
    ClearBackground(BLACK);

    DrawRectangleV(player.pos, player.size, RED);
    DrawCircleV(ball.pos, ball.radius, BLUE);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
