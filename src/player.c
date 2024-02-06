#include "player.h"
#include "constants.h"

struct Player createPlayer(int width, int height, int speed) {
  struct Player player = {.size = {width, height}, .speed = speed};
  player.pos.x = ((float)SCREEN_WIDTH / 2) - ((float)player.size.x / 2);
  player.pos.y = (SCREEN_HEIGHT - player.size.y) - 5;

  return player;
}

void movePlayer(struct Player *player) {
  if (IsKeyDown(KEY_A) && player->pos.x > 0) {
    player->pos.x -= player->speed;
  } else if (IsKeyDown(KEY_D) &&
             player->pos.x < (SCREEN_WIDTH - player->size.x)) {
    player->pos.x += player->speed;
  }
}
