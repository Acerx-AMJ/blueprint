#include "states/loadingState.hpp"

// Constructors

LoadingState::LoadingState() {

}

// Update

void LoadingState::update() {
   quitState = true;
}

// Render

void LoadingState::render() const {

}

// Change

State *LoadingState::change() const {
   return nullptr;
}
