#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

struct Player {
  Vector2 pos;
  Vector2 size;
  int speed;
};

struct Player createPlayer(int width, int height, int speed);
void movePlayer(struct Player *player);

#endif // !PLAYER_H
