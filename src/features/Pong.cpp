#include "features/Pong.h"
#include "globals.h"


Pong::Pong() {
  resetGame();
}

void Pong::resetGame() {
  playerScore = 0;
  aiScore = 0;
  gameOver = false;
  paddleY = aiY = screenHeight / 2 - paddleHeight / 2;
  resetBall(true);
}

void Pong::resetBall(bool towardPlayer) {
  ballX = screenWidth / 2;
  ballY = screenHeight / 2;
  ballVX = towardPlayer ? -2 : 2;
  ballVY = (random(0, 2) == 0) ? 1 : -1;
}

void Pong::update() {
  if (gameOver) {
    if (input.doubleClicked()) resetGame();
    return;
  }

  // PLAYER paddle (left side, controlled by pot)
  int potVal = analogRead(39);
  paddleY = map(potVal, 0, 4095, 0, screenHeight - paddleHeight);

  // Move ball
  ballX += ballVX;
  ballY += ballVY;

  if (ballY <= 0 || ballY >= screenHeight - 1) ballVY *= -1;

  // AI paddle (right) tracks ball
  if (ballY > aiY + paddleHeight / 2 + 1) aiY += 1;
  else if (ballY < aiY + paddleHeight / 2 - 1) aiY -= 1;
  aiY = constrain(aiY, 0, screenHeight - paddleHeight);

  // PLAYER paddle collision (left side)
  if (ballX <= 4 && ballY >= paddleY && ballY <= paddleY + paddleHeight) {
    ballVX = abs(ballVX); // bounce to right
    buzzer.click();
  }

  // AI paddle collision (right side)
  if (ballX >= screenWidth - 5 && ballY >= aiY && ballY <= aiY + paddleHeight) {
    ballVX = -abs(ballVX); // bounce to left
    buzzer.click();
  }

  // MISS: Player
  if (ballX < 0) {
    aiScore++;
    if (aiScore >= 5) gameOver = true;
    else resetBall(false);
  }

  // MISS: AI
  if (ballX > screenWidth) {
    playerScore++;
    if (playerScore >= 5) gameOver = true;
    else resetBall(true);
  }
}

void Pong::draw(DisplayManager& display) {
  display.drawText("PONG", 50, 0);

  if (gameOver) {
    if (playerScore >= 5) {
      display.drawText("You Win!", 35, 25);
      sprite.drawCheer(display, 50, -16);
    } else {
      display.drawText("You Lose!", 35, 25);
      sprite.drawSad(display, 50, -16);
    }
    display.drawText("Double-click to retry", 0, 55);
    return;
  }

  // Ball
  display.drawText("o", ballX, ballY);

  // Draw player paddle (left)
  for (int i = 0; i < paddleHeight; i += 2)
    display.drawText("|", 2, paddleY + i);

  // Draw AI paddle (right)
  for (int i = 0; i < paddleHeight; i += 2)
    display.drawText("|", 122, aiY + i);

  // Score
  char buf[16];
  sprintf(buf, "%d - %d", playerScore, aiScore);
  display.drawText(buf, 52, 55);
  //sprite.drawIdle(display, 0, 0);
}
