#include "map.h"
#include "raylib.h"
int world_map[30][30];
void init_world_map(void){
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (i == 0 || i == 29 || j == 0 || j == 29)
            {
                world_map[i][j] = 1;
            }
            else{ world_map[i][j] = 0;
            }
        }
    }
    }
    void draw_world_map(void){
         for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (world_map[i][j] == 1)
            {
                DrawRectangle(i*30,j *30,30,30,DARKGRAY);
                DrawRectangleLines(i * 30,j * 30,30,30,BLACK);
            }
            else{
                DrawRectangle(i * 30, j * 30,30,30,WHITE);
                DrawRectangleLines(i * 30,j * 30,30,30,BLACK);

            }
            
        }
    }
    }

    void update_map(void){
        Vector2 mouseposition = GetMousePosition();
        int i = mouseposition.x /30;
        int j = mouseposition.y /30;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if ((i != 0 && i != 29 && j != 0 && j != 29))
            {
                world_map[i][j] = !world_map[i][j];
            }
            
        }
        
    }
