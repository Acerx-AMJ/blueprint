#ifndef STATES_LOADING_STATE_HPP
#define STATES_LOADING_STATE_HPP

#include "states/state.hpp"
#include <string>

struct LoadingState: public State {
   enum class Loading { fonts, textures, shaders, sounds, music, loadingCount };

   // Constructors

   LoadingState();
   ~LoadingState() = default;

   // Functions

   void update() override;
   void render() const override;
   State *change() const override;

   // Members

   std::string loadingText;
   Loading loadingPhase = Loading::fonts;
};

#endif
