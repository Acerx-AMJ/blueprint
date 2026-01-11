#include "states/loadingState.hpp"
#include <raylib.h>
#include <cstdlib>
#include <ctime>

int main() {
   srand(time(nullptr));
   InitWindow(800, 600, "Blueprint");
   SetTargetFPS(60);
   InitAudioDevice();
   SetExitKey(KEY_NULL);

   State *state = new LoadingState();

   while (!WindowShouldClose()) {
      if (state->quitState) {
         State *newState = state->change();
         delete state;
         state = newState;
      }

      if (!state) {
         break;
      }

      state->update();
      BeginDrawing();
         ClearBackground(BLACK);
         state->render();
      EndDrawing();
   }
   CloseWindow();
   CloseAudioDevice();
}