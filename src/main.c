#include "ball.h"
#include "constants.h"
#include "player.h"
#include <raylib.h>

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Breakout");
  SetTargetFPS(60);

  struct Player player = createPlayer(100, 15, 10);
  struct Ball ball = createBall(15);

  while (!WindowShouldClose()) {
    movePlayer(&player);
    moveBall(&ball);

    BeginDrawing();
    ClearBackground(BLACK);

    Rectangle playerBar = {player.x, player.y, player.width, player.height};
    DrawRectangleRounded(playerBar, 10, 10, RED);

    DrawCircle(ball.x, ball.y, ball.radius, BLUE);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
