// DisplayManager.cpp - OLED screen logic for HappyTomato

#include "hardware/DisplayManager.h"

void DisplayManager::begin() {
  Wire.begin(21, 22); // SDA, SCL pins
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED init failed");
    while (true);
  }
  display.clearDisplay();
  display.display();
}

void DisplayManager::clear() {
  display.clearDisplay();
}

void DisplayManager::update() {
  display.display();
}

void DisplayManager::drawBitmap(int x, int y, const uint8_t* bitmap, int w, int h, uint16_t color) {
  display.drawBitmap(x, y, bitmap, w, h, color);
}

void DisplayManager::setContrast(uint8_t level) {
  display.ssd1306_command(SSD1306_SETCONTRAST);
  display.ssd1306_command(level);
}

void DisplayManager::drawRect(int x, int y, int w, int h, uint16_t color) {
  display.drawRect(x, y, w, h, color);
}

/**
 * Draws a filled circle at the specified coordinates with the given radius and color.
 *
 * @param x The x-coordinate of the circle's center.
 * @param y The y-coordinate of the circle's center.
 * @param r The radius of the circle.
 * @param color The color of the circle.
 */
void DisplayManager::fillCircle(int x, int y, int r, uint16_t color) {
  display.fillCircle(x, y, r, color);
}

void DisplayManager::fillRect(int x, int y, int w, int h, uint16_t color) {
  display.fillRect(x, y, w, h, color);
}

void DisplayManager::drawPixel(int x, int y, uint16_t color) {
  display.drawPixel(x, y, color);
}

void DisplayManager::drawLine(int x0, int y0, int x1, int y1, uint16_t color) {
  display.drawLine(x0, y0, x1, y1, color);
}

void DisplayManager::drawText(const char* text, int x, int y, int size) {
  display.setTextSize(size);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(x, y);
  display.print(text);
}

void DisplayManager::drawSplash(const char* text) {
  clear();
  drawText(text, 20, 28, 2);
  update();
  delay(2000);
}

int DisplayManager::width() {
  return display.width();
}

int DisplayManager::height() {
  return display.height();
}
