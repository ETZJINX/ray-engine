#include <stdio.h>
#include "raylib.h"
#include "map.h"
#include "player.h"
#include "raycasting.h"
 int main(){
   int neshane = 0;
   SetConfigFlags(FLAG_WINDOW_HIGHDPI);
   SetTargetFPS(60);
   InitWindow(900,900,"عرفان توحیدی ");
   init_world_map();
   while (!WindowShouldClose())
   {
      if (IsKeyPressed(KEY_M))
      {
         neshane = !neshane;
      }
      player();
      BeginDrawing();
      ClearBackground(RAYWHITE);
      if (neshane == 0)
      {
         update_map();
         draw_world_map();
         draw_player();
      }
      else 
      {
         raydirection();
      }
      EndDrawing();
      
      
      
      
   }
   CloseWindow();
    return 0;
 }