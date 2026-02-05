#include <stdio.h>
#include "map.h"
#include "raylib.h"
#include "player.h"
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
        int i2 = playerposition.x / 30;
        int j2 = playerposition.y /30;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if ((i != 0 && i != 29 && j != 0 && j != 29) && !(i2 ==i && j2 == j))
            {
                world_map[i][j] = !world_map[i][j];
            }
            
        }
        
    }

    void draw_minimap(void){
        int miniCellSize = 6;
        int mapWidthInPixels = 30 * miniCellSize;
        int screenWidth = GetScreenWidth();

        int offsetX = screenWidth - mapWidthInPixels - 10;
        int offsetY = 10;
        DrawRectangle(offsetX, offsetY, mapWidthInPixels, mapWidthInPixels, Fade(BLACK, 0.5f));
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                DrawRectangleLines(offsetX + (i * miniCellSize), 
                              offsetY + (j * miniCellSize), 
                              miniCellSize, miniCellSize, BLACK);
                if (world_map[i][j] == 1)
                {
                    DrawRectangle(offsetX + (i * miniCellSize), 
                              offsetY + (j * miniCellSize), 
                              miniCellSize, miniCellSize, LIGHTGRAY);
                    
                }
            }
        }
        float scale = (float)miniCellSize / 30.0f;
    
        int playerMiniX = offsetX + (int)(playerposition.x * scale);
        int playerMiniY = offsetY + (int)(playerposition.y * scale);

        DrawCircle(playerMiniX, playerMiniY, 3, RED);

        DrawLine(playerMiniX, playerMiniY, 
                playerMiniX + (int)(playerdirection.x * 10), 
                playerMiniY + (int)(playerdirection.y * 10), RED);
    }

    void save_map(const char *filename){
        FILE *file = fopen(filename, "w");

        if (file == NULL) {
        TraceLog(LOG_ERROR, "Failed to save map file!");
        return;
    }

    for (int j = 0; j < 30; j++) 
    {
        for (int i = 0; i < 30; i++) 
        {
            fprintf(file, "%d ", world_map[i][j]); 
        }
        fprintf(file, "\n");
    }
    fclose(file);
    TraceLog(LOG_INFO, "Map saved successfully to %s", filename);
    }
    void load_map(const char *filename){

        FILE *file = fopen(filename, "r");
        if (file == NULL) {
        TraceLog(LOG_WARNING, "Map file not found! creating a new one or ignoring.");
        return;
    }
    for (int j = 0; j < 30; j++)
    {
        for (int i = 0; i < 30; i++)
        {
            fscanf(file, "%d", &world_map[i][j]); 
        }
    }

    fclose(file);
    TraceLog(LOG_INFO, "Map loaded successfully from %s", filename);
    }




