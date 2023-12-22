#include "player.h"
#include "constants.h"
#include <raylib.h>

struct Player createPlayer(int width, int height, int speed) {
  struct Player player = {.width = width, .height = height, .speed = speed};
  player.x = ((float)SCREEN_WIDTH / 2) - ((float)player.width / 2);
  player.y = (SCREEN_HEIGHT - player.height) - 5;

  return player;
}

void movePlayer(struct Player *player) {
  if (IsKeyDown(KEY_A) && player->x > 0) {
    player->x -= player->speed;
  } else if (IsKeyDown(KEY_D) && player->x < (SCREEN_WIDTH - player->width)) {
    player->x += player->speed;
  }
}
