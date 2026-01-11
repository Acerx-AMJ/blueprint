#ifndef STATES_LOADING_STATE_HPP
#define STATES_LOADING_STATE_HPP

#include "states/state.hpp"
#include <string>

struct LoadingState: public State {
   enum class Loading { none = -1, fonts, textures, sounds, music, loadingCount };

   // Constructors

   LoadingState();
   ~LoadingState() = default;

   // Functions

   void update() override;
   void render() const override;
   State *change() const override;

   // Members

   std::string loadingText;
   Loading loadingPhase = Loading::none;
   float finalWaitTimer = 1.0f;
};

#endif