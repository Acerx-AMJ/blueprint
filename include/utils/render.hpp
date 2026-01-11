#ifndef UTILS_RENDER_HPP
#define UTILS_RENDER_HPP

#include <raylib.h>

// Render functions

void drawTextCentered(Font font, const Vector2 &position, const char *text, float fontSize);

// Coordinate functions

Vector2 getScreenSize();
Vector2 getScreenCenter();
Vector2 getScreenCenter(const Vector2 &offset);

Vector2 getCenter(const Vector2 &size);
Vector2 getCenter(Font font, const char *text, float fontSize, float spacing);

#endif
