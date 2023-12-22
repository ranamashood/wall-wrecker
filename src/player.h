#ifndef PLAYER_H
#define PLAYER_H

struct Player {
  int x, y;
  int width, height;
  int speed;
};

struct Player createPlayer(int width, int height, int speed);
void movePlayer(struct Player *player);

#endif // !PLAYER_H
