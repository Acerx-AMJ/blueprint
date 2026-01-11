#include "utils/render.hpp"
#include <raymath.h>

// Render functions

void drawTextCentered(Font font, const Vector2 &position, const char *text, float fontSize) {
   DrawTextPro(font, text, position, getCenter(font, text, fontSize, 1), 0, fontSize, 1, WHITE);
}

// Coordinate functions

Vector2 getScreenSize() {
   return {(float)GetScreenWidth(), (float)GetScreenHeight()};
}

Vector2 getScreenCenter() {
   return Vector2Scale(getScreenSize(), 0.5f);
}

Vector2 getScreenCenter(const Vector2 &offset) {
   return Vector2Add(getScreenCenter(), offset);
}

Vector2 getCenter(const Vector2 &size) {
   return Vector2Scale(size, 0.5f);
}

Vector2 getCenter(Font font, const char *text, float fontSize, float spacing) {
   return getCenter(MeasureTextEx(font, text, fontSize, spacing));
}
