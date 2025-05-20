#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

class DisplayManager {
public:
  void begin();
  void clear();
  void update();
  void drawText(const char* text, int x, int y, int size = 1);
  void drawSplash(const char* text);
  int width();
  int height();

  void setContrast(uint8_t level);


  void fillCircle(int x, int y, int r, uint16_t color);
  void fillRect(int x, int y, int w, int h, uint16_t color);
  void drawRect(int x, int y, int w, int h, uint16_t color);
  void drawPixel(int x, int y, uint16_t color);
  void drawLine(int x0, int y0, int x1, int y1, uint16_t color);
  void drawBitmap(int x, int y, const uint8_t* bitmap, int w, int h, uint16_t color);

private:
  Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, -1);
};

#endif
