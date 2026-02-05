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
       if (IsKeyPressed(KEY_K)) {
          save_map("my_map.txt"); 
      }
      
      if (IsKeyPressed(KEY_L)) {
          load_map("my_map.txt"); 
      }
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
         DrawText("K: Save Map | L: Load Map | M: 3D Mode", 10, 10, 20, RED);
      }
      else 
      {
         raydirection();
         draw_minimap();
      }
      EndDrawing();
      
      
      
      
   }
   CloseWindow();
    return 0;
 }