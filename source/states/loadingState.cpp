#include "states/loadingState.hpp"
#include "states/menuState.hpp"
#include <raylib.h>

// Constructors

LoadingState::LoadingState() {

}

// Update

void LoadingState::update() {
   if (IsKeyPressed(KEY_ESCAPE)) {
      quitState = true;
   }
}

// Render

void LoadingState::render() const {
   DrawText("This is the loading state... Press ESCAPE to switch.", 10, 10, 25, WHITE);
}

// Change

State *LoadingState::change() const {
   return new MenuState();
}