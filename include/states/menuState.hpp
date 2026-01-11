#ifndef STATES_MENU_STATE_HPP
#define STATES_MENU_STATE_HPP

#include "states/state.hpp"

struct MenuState: public State {
   // Constructors

   MenuState();
   ~MenuState() = default;

   // Functions

   void update() override;
   void render() const override;
   State *change() const override;
};

#endif
