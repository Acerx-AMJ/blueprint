#ifndef UI_BLOCKS_HPP
#define UI_BLOCKS_HPP

#include <raylib.h>
#include <string>

// Constants

constexpr inline float buttonWidth    = 210.0f;
constexpr inline float buttonHeight   = 100.0f;
constexpr inline float buttonPaddingX = buttonWidth + 20.0f;
constexpr inline float buttonPaddingY = buttonHeight + 20.0f;
constexpr inline float buttonRoundness    = 0.3f;
constexpr inline float buttonSegments    = 5;
constexpr inline Color baseColor=WHITE;
// Button

struct Button {
   void update(float dt, float offsetY = 0.0f);
   void render(float offsetY = 0.0f) const;

   Rectangle normalizeRect() const;

   // Members

   Texture2D *texture = nullptr;
   Rectangle rectangle;
   std::string text, keybind;
   Color baseColor=WHITE;
   bool hovering = false;
   bool down     = false;
   bool clicked  = false;
   bool favorite = false;
   bool disabled = false;

   float baseScale = 1.0f;
};

#endif
