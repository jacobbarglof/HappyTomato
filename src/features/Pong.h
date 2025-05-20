#ifndef PONG_H
#define PONG_H

#include "features/Feature.h"

class Pong : public Feature {
public:
  Pong();
  void update() override;
  void draw(DisplayManager& display) override;

private:
  int ballX, ballY;
  int ballVX, ballVY;
  int paddleY, aiY;
  int paddleHeight = 18;
  int screenWidth = 128;
  int screenHeight = 64;

  int playerScore = 0;
  int aiScore = 0;
  bool gameOver = false;

  void resetBall(bool towardPlayer);
  void resetGame();
};

#endif
