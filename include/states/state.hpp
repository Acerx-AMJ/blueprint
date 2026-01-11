#ifndef STATES_STATE_HPP
#define STATES_STATE_HPP

struct State {
   State() = default;
   virtual ~State() = default;

   // Virtual functions

   virtual void update() = 0;
   virtual void render() const = 0;
   virtual State *change() const = 0;

   // Members

   bool quitState = false;
};

#endif