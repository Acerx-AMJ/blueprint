#include "mngr/asset.hpp"
#include "states/loadingState.hpp"
#include "mngr/sound.hpp"
#include "states/menuState.hpp"
#include "utils/render.hpp"
#include <raylib.h>

// Constructors

LoadingState::LoadingState() {
   loadFont("RobotoMono", "assets/fonts/RobotoMono.ttf");
}

// Update

void LoadingState::update() {
   // Load assets one by one
   if (loadingPhase == Loading::none) {
      loadingText = "Loading Fonts...";
      loadingPhase = Loading::fonts;
   }
   else if (loadingPhase == Loading::fonts) {
      loadFonts();

      loadingText = "Loading Textures...";
      loadingPhase = Loading::textures;
   }
   else if (loadingPhase == Loading::textures) {
      loadTextures();

      loadingText = "Loading Sounds...";
      loadingPhase = Loading::sounds;
   }
   else if (loadingPhase == Loading::sounds) {
      loadSounds();
      loadSavedSounds();

      loadingText = "Loading Music...";
      loadingPhase = Loading::music;
   }
   else if (loadingPhase == Loading::music) {
      loadMusic();

      loadingText = "Loading Done!";
      loadingPhase = Loading::loadingCount;
   }
   else if (loadingPhase == Loading::loadingCount) {
      finalWaitTimer -= std::min(0.25f, GetFrameTime()); // std::min it to avoid huge jumps
      quitState = (finalWaitTimer <= 0.0f);
   }
}

// Render

void LoadingState::render() const {
   std::string finalLoadingText = loadingText;
   if (loadingPhase != Loading::loadingCount) {
      finalLoadingText += std::to_string((int)loadingPhase) + "/" + std::to_string((int)Loading::loadingCount);
   }

   drawTextCentered(getFont("RobotoMono"), getScreenCenter(), finalLoadingText.c_str(), 80);
}

// Change

State *LoadingState::change() const {
   return new MenuState();
}