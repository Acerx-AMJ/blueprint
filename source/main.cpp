#include <raylib.h>

int main() {
   InitWindow(800, 600, "Blueprint");
   SetTargetFPS(60);

   while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(BLACK);
      DrawRectangle(50, 50, 100, 100, RED);
      EndDrawing();
   }
}
