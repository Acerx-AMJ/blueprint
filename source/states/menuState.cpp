#include "states/menuState.hpp"
#include <raylib.h>

// Constructors

MenuState::MenuState() {

}

// Update

void MenuState::update() {
   if (IsKeyPressed(KEY_ESCAPE)) {
      quitState = true;
   }
}

// Render

void MenuState::render() const {
   DrawText("This is the menu state... Press ESCAPE to quit.", 10, 10, 25, WHITE);
}

// Change

State *MenuState::change() const {
   return nullptr; // Just quit the game
}