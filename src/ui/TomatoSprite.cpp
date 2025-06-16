#include "TomatoSprite.h"
#include "hardware/DisplayManager.h"

// Helper macro to offset drawing coordinates so the sprite is centred on screen
#define TX(v) (dx + (v))
#define TY(v) (dy + (v))

void TomatoSprite::drawIdle(DisplayManager& display, int x, int y) {
  // Chillin pose
  int dx = display.width() / 2 - 42 + x;
  int dy = display.height() / 2 - 25 + y;

  display.fillCircle(TX(42), TY(25), 9, SSD1306_WHITE);
  display.fillRect(TX(38), TY(22), 2, 2, SSD1306_BLACK);
  display.fillRect(TX(46), TY(22), 2, 2, SSD1306_BLACK);

  display.drawPixel(TX(39), TY(28), SSD1306_BLACK);
  display.drawPixel(TX(39), TY(29), SSD1306_BLACK);
  display.drawPixel(TX(40), TY(29), SSD1306_BLACK);
  display.drawPixel(TX(40), TY(30), SSD1306_BLACK);
  display.drawPixel(TX(41), TY(30), SSD1306_BLACK);
  display.drawPixel(TX(42), TY(31), SSD1306_BLACK);
  display.drawPixel(TX(43), TY(31), SSD1306_BLACK);
  display.drawPixel(TX(44), TY(31), SSD1306_BLACK);
  display.drawPixel(TX(45), TY(31), SSD1306_BLACK);
  display.drawPixel(TX(46), TY(31), SSD1306_BLACK);
  display.drawPixel(TX(46), TY(30), SSD1306_BLACK);
  display.drawPixel(TX(47), TY(30), SSD1306_BLACK);
  display.drawPixel(TX(47), TY(29), SSD1306_BLACK);

  display.drawPixel(TX(37), TY(16), SSD1306_BLACK);
  display.drawPixel(TX(38), TY(16), SSD1306_BLACK);
  display.drawPixel(TX(39), TY(16), SSD1306_BLACK);
  display.drawPixel(TX(39), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(40), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(40), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(41), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(42), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(43), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(44), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(45), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(45), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(46), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(47), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(47), TY(16), SSD1306_BLACK);
  display.drawPixel(TX(48), TY(16), SSD1306_BLACK);

  display.drawPixel(TX(41), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(38), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(38), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(37), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(36), TY(13), SSD1306_WHITE);

  display.drawPixel(TX(43), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(44), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(44), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(45), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(45), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(46), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(47), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(48), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(47), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(46), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(45), TY(14), SSD1306_WHITE);

  display.drawPixel(TX(40), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(38), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(38), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(37), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(36), TY(12), SSD1306_WHITE);

  display.drawPixel(TX(41), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(42), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(42), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(42), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(42), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(41), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(41), TY(11), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(11), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(10), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(9), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(9), SSD1306_WHITE);

  display.drawPixel(TX(36), TY(32), SSD1306_WHITE);
  display.drawPixel(TX(36), TY(33), SSD1306_WHITE);
  display.drawPixel(TX(35), TY(33), SSD1306_WHITE);
  display.drawPixel(TX(35), TY(34), SSD1306_WHITE);
  display.drawPixel(TX(35), TY(35), SSD1306_WHITE);

  display.drawPixel(TX(48), TY(31), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(31), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(32), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(33), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(34), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(35), SSD1306_WHITE);
  display.drawPixel(TX(50), TY(35), SSD1306_WHITE);

  display.drawPixel(TX(51), TY(26), SSD1306_WHITE);
  display.drawPixel(TX(51), TY(25), SSD1306_WHITE);
  display.drawPixel(TX(52), TY(25), SSD1306_WHITE);
  display.drawPixel(TX(52), TY(24), SSD1306_WHITE);
  display.drawPixel(TX(53), TY(23), SSD1306_WHITE);
  display.drawPixel(TX(53), TY(22), SSD1306_WHITE);
  display.drawPixel(TX(53), TY(21), SSD1306_WHITE);
  display.drawPixel(TX(53), TY(20), SSD1306_WHITE);

  display.drawPixel(TX(33), TY(25), SSD1306_WHITE);
  display.drawPixel(TX(32), TY(25), SSD1306_WHITE);
  display.drawPixel(TX(31), TY(25), SSD1306_WHITE);
  display.drawPixel(TX(30), TY(25), SSD1306_WHITE);
  display.drawPixel(TX(29), TY(25), SSD1306_WHITE);
}

void TomatoSprite::drawCheer(DisplayManager& display, int x, int y) {
  // Waving pose
  int dx = display.width() / 2 - 42 + x;
  int dy = display.height() / 2 - 25 + y;

  display.fillCircle(TX(42), TY(25), 9, SSD1306_WHITE);
  display.fillRect(TX(38), TY(22), 2, 2, SSD1306_BLACK);
  display.fillRect(TX(46), TY(22), 2, 2, SSD1306_BLACK);

  display.drawPixel(TX(39), TY(28), SSD1306_BLACK);
  display.drawPixel(TX(39), TY(29), SSD1306_BLACK);
  display.drawPixel(TX(40), TY(29), SSD1306_BLACK);
  display.drawPixel(TX(40), TY(30), SSD1306_BLACK);
  display.drawPixel(TX(41), TY(30), SSD1306_BLACK);
  display.drawPixel(TX(42), TY(31), SSD1306_BLACK);
  display.drawPixel(TX(43), TY(31), SSD1306_BLACK);
  display.drawPixel(TX(44), TY(31), SSD1306_BLACK);
  display.drawPixel(TX(45), TY(31), SSD1306_BLACK);
  display.drawPixel(TX(46), TY(31), SSD1306_BLACK);
  display.drawPixel(TX(46), TY(30), SSD1306_BLACK);
  display.drawPixel(TX(47), TY(30), SSD1306_BLACK);
  display.drawPixel(TX(47), TY(29), SSD1306_BLACK);

  display.drawPixel(TX(37), TY(16), SSD1306_BLACK);
  display.drawPixel(TX(38), TY(16), SSD1306_BLACK);
  display.drawPixel(TX(39), TY(16), SSD1306_BLACK);
  display.drawPixel(TX(39), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(40), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(40), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(41), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(42), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(43), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(44), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(45), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(45), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(46), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(47), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(47), TY(16), SSD1306_BLACK);
  display.drawPixel(TX(48), TY(16), SSD1306_BLACK);

  display.drawPixel(TX(41), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(38), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(38), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(37), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(36), TY(13), SSD1306_WHITE);

  display.drawPixel(TX(43), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(44), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(44), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(45), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(45), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(46), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(47), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(48), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(47), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(46), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(45), TY(14), SSD1306_WHITE);

  display.drawPixel(TX(40), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(38), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(38), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(37), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(36), TY(12), SSD1306_WHITE);

  display.drawPixel(TX(41), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(42), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(42), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(42), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(42), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(41), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(41), TY(11), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(11), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(10), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(9), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(9), SSD1306_WHITE);

  display.drawPixel(TX(36), TY(32), SSD1306_WHITE);
  display.drawPixel(TX(36), TY(33), SSD1306_WHITE);
  display.drawPixel(TX(35), TY(33), SSD1306_WHITE);
  display.drawPixel(TX(35), TY(34), SSD1306_WHITE);
  display.drawPixel(TX(35), TY(35), SSD1306_WHITE);

  display.drawPixel(TX(48), TY(31), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(31), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(32), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(33), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(34), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(35), SSD1306_WHITE);
  display.drawPixel(TX(50), TY(35), SSD1306_WHITE);

  display.drawPixel(TX(51), TY(26), SSD1306_WHITE);
  display.drawPixel(TX(51), TY(25), SSD1306_WHITE);
  display.drawPixel(TX(52), TY(25), SSD1306_WHITE);
  display.drawPixel(TX(52), TY(24), SSD1306_WHITE);
  display.drawPixel(TX(53), TY(23), SSD1306_WHITE);
  display.drawPixel(TX(53), TY(22), SSD1306_WHITE);
  display.drawPixel(TX(53), TY(21), SSD1306_WHITE);
  display.drawPixel(TX(53), TY(20), SSD1306_WHITE);

  display.drawPixel(TX(33), TY(25), SSD1306_WHITE);
  display.drawPixel(TX(32), TY(25), SSD1306_WHITE);
  display.drawPixel(TX(31), TY(25), SSD1306_WHITE);
  display.drawPixel(TX(30), TY(25), SSD1306_WHITE);
  display.drawPixel(TX(29), TY(25), SSD1306_WHITE);
}

void TomatoSprite::drawSad(DisplayManager& display, int x, int y) {
  // Sad pose
  int dx = display.width() / 2 - 42 + x;
  int dy = display.height() / 2 - 25 + y;

  display.fillCircle(TX(42), TY(25), 9, SSD1306_WHITE);
  display.fillRect(TX(38), TY(22), 2, 2, SSD1306_BLACK);
  display.fillRect(TX(46), TY(22), 2, 2, SSD1306_BLACK);

  display.drawPixel(TX(37), TY(16), SSD1306_BLACK);
  display.drawPixel(TX(38), TY(16), SSD1306_BLACK);
  display.drawPixel(TX(39), TY(16), SSD1306_BLACK);
  display.drawPixel(TX(39), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(40), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(40), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(41), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(42), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(43), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(44), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(45), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(45), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(46), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(47), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(47), TY(16), SSD1306_BLACK);
  display.drawPixel(TX(48), TY(16), SSD1306_BLACK);

  display.drawPixel(TX(41), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(38), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(38), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(37), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(36), TY(13), SSD1306_WHITE);

  display.drawPixel(TX(43), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(44), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(44), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(45), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(45), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(46), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(47), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(48), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(47), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(46), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(45), TY(14), SSD1306_WHITE);

  display.drawPixel(TX(40), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(38), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(38), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(37), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(36), TY(12), SSD1306_WHITE);

  display.drawPixel(TX(41), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(42), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(42), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(42), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(42), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(41), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(41), TY(11), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(11), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(10), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(9), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(9), SSD1306_WHITE);

  display.drawPixel(TX(36), TY(32), SSD1306_WHITE);
  display.drawPixel(TX(36), TY(33), SSD1306_WHITE);
  display.drawPixel(TX(35), TY(33), SSD1306_WHITE);
  display.drawPixel(TX(35), TY(34), SSD1306_WHITE);
  display.drawPixel(TX(35), TY(35), SSD1306_WHITE);

  display.drawPixel(TX(48), TY(31), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(31), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(32), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(33), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(34), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(35), SSD1306_WHITE);
  display.drawPixel(TX(50), TY(35), SSD1306_WHITE);

  display.drawPixel(TX(52), TY(24), SSD1306_WHITE);
  display.drawPixel(TX(53), TY(24), SSD1306_WHITE);
  display.drawPixel(TX(54), TY(24), SSD1306_WHITE);
  display.drawPixel(TX(55), TY(24), SSD1306_WHITE);

  display.drawPixel(TX(33), TY(24), SSD1306_WHITE);
  display.drawPixel(TX(32), TY(24), SSD1306_WHITE);
  display.drawPixel(TX(31), TY(24), SSD1306_WHITE);
  display.drawPixel(TX(30), TY(24), SSD1306_WHITE);
  display.drawPixel(TX(29), TY(24), SSD1306_WHITE);

  display.drawPixel(TX(121), TY(45), SSD1306_WHITE);

  display.drawPixel(TX(39), TY(29), SSD1306_BLACK);
  display.drawPixel(TX(40), TY(28), SSD1306_BLACK);
  display.drawPixel(TX(41), TY(27), SSD1306_BLACK);
  display.drawPixel(TX(42), TY(27), SSD1306_BLACK);
  display.drawPixel(TX(43), TY(27), SSD1306_BLACK);
  display.drawPixel(TX(44), TY(27), SSD1306_BLACK);
  display.drawPixel(TX(45), TY(27), SSD1306_BLACK);
  display.drawPixel(TX(46), TY(27), SSD1306_BLACK);
  display.drawPixel(TX(46), TY(28), SSD1306_BLACK);
  display.drawPixel(TX(47), TY(28), SSD1306_BLACK);
}

void TomatoSprite::drawBored(DisplayManager& display, int x, int y) {
  // Bored pose
  int dx = display.width() / 2 - 42 + x;
  int dy = display.height() / 2 - 25 + y;

  display.fillCircle(TX(42), TY(25), 9, SSD1306_WHITE);
  display.fillRect(TX(38), TY(22), 2, 2, SSD1306_BLACK);
  display.fillRect(TX(46), TY(22), 2, 2, SSD1306_BLACK);

  display.drawPixel(TX(37), TY(16), SSD1306_BLACK);
  display.drawPixel(TX(38), TY(16), SSD1306_BLACK);
  display.drawPixel(TX(39), TY(16), SSD1306_BLACK);
  display.drawPixel(TX(39), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(40), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(40), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(41), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(42), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(43), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(44), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(45), TY(18), SSD1306_BLACK);
  display.drawPixel(TX(45), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(46), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(47), TY(17), SSD1306_BLACK);
  display.drawPixel(TX(47), TY(16), SSD1306_BLACK);
  display.drawPixel(TX(48), TY(16), SSD1306_BLACK);

  display.drawPixel(TX(41), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(38), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(38), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(37), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(36), TY(13), SSD1306_WHITE);

  display.drawPixel(TX(43), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(44), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(44), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(45), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(45), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(46), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(47), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(48), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(47), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(46), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(45), TY(14), SSD1306_WHITE);

  display.drawPixel(TX(40), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(38), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(38), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(37), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(36), TY(12), SSD1306_WHITE);

  display.drawPixel(TX(41), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(42), TY(15), SSD1306_WHITE);
  display.drawPixel(TX(42), TY(14), SSD1306_WHITE);
  display.drawPixel(TX(42), TY(13), SSD1306_WHITE);
  display.drawPixel(TX(42), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(41), TY(12), SSD1306_WHITE);
  display.drawPixel(TX(41), TY(11), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(11), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(10), SSD1306_WHITE);
  display.drawPixel(TX(40), TY(9), SSD1306_WHITE);
  display.drawPixel(TX(39), TY(9), SSD1306_WHITE);

  display.drawPixel(TX(36), TY(32), SSD1306_WHITE);
  display.drawPixel(TX(36), TY(33), SSD1306_WHITE);
  display.drawPixel(TX(35), TY(33), SSD1306_WHITE);
  display.drawPixel(TX(35), TY(34), SSD1306_WHITE);
  display.drawPixel(TX(35), TY(35), SSD1306_WHITE);

  display.drawPixel(TX(48), TY(31), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(31), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(32), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(33), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(34), SSD1306_WHITE);
  display.drawPixel(TX(49), TY(35), SSD1306_WHITE);
  display.drawPixel(TX(50), TY(35), SSD1306_WHITE);

  display.drawPixel(TX(52), TY(24), SSD1306_WHITE);
  display.drawPixel(TX(53), TY(24), SSD1306_WHITE);
  display.drawPixel(TX(54), TY(24), SSD1306_WHITE);
  display.drawPixel(TX(55), TY(24), SSD1306_WHITE);

  display.drawPixel(TX(33), TY(24), SSD1306_WHITE);
  display.drawPixel(TX(32), TY(24), SSD1306_WHITE);
  display.drawPixel(TX(31), TY(24), SSD1306_WHITE);
  display.drawPixel(TX(30), TY(24), SSD1306_WHITE);
  display.drawPixel(TX(29), TY(24), SSD1306_WHITE);

  display.drawPixel(TX(121), TY(45), SSD1306_WHITE);

  display.drawPixel(TX(40), TY(28), SSD1306_BLACK);
  display.drawPixel(TX(41), TY(28), SSD1306_BLACK);
  display.drawPixel(TX(42), TY(28), SSD1306_BLACK);
  display.drawPixel(TX(43), TY(28), SSD1306_BLACK);
  display.drawPixel(TX(44), TY(28), SSD1306_BLACK);
  display.drawPixel(TX(45), TY(28), SSD1306_BLACK);
  display.drawPixel(TX(46), TY(28), SSD1306_BLACK);
}

void TomatoSprite::cycleIdle(DisplayManager& display, int x, int y) {
  // Cycle through idle frames
  static int frameCounter = 0;
  int dx = display.width() / 2 - 42 + x;
  int dy = display.height() / 2 - 25 + y;

  if (frameCounter < 10) {
    drawIdle(display, x, y);
  } else if (frameCounter < 50) {
    drawCheer(display, x, y);
  } else if (frameCounter < 100) {
    drawBored(display, x, y);
  } else if (frameCounter < 300) {
    frameCounter = -1; // Reset after sad frame
  }

  frameCounter++;  
}