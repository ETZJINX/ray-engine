#include "player.h"
#include "raylib.h"
#include "raymath.h"
#include "map.h"

void raydirection(void){
        float deltadistx,perpWallDist;
        float deltadisty;
        int stepx;
        float sidedistx;
        int stepy;
        float sidedisty;
        int screenWidth  = GetScreenWidth();
        int screenHeight = GetScreenHeight();
    
    for (int i = 0; i < screenWidth; i++)
    {
        int side ;
        double cameraX = 2 * (i / (float)screenWidth) - 1;
        double raydirx =(double) playerdirection.x + plane.x * cameraX;
        double raydiry =(double) playerdirection.y + plane.y * cameraX;
        deltadistx = (raydirx == 0) ? 1e30f : fabsf(1.0 / raydirx);
        deltadisty = (raydiry == 0) ? 1e30f : fabsf(1.0 / raydiry);
        int mapx =(int) playerposition.x;
        int mapy = (int) playerposition.y;
        




        if (raydirx < 0)
        {
            stepx = -1;
            sidedistx = (playerposition.x  - mapx) * deltadistx;
        }
        else{
            stepx = 1;
            sidedistx = (mapx + 1.0f  - playerposition.x) * deltadistx;
        }
        if (raydiry < 0)
        {
            stepy = -1;
            sidedisty = (playerposition.y  - mapy) * deltadisty;
        }
        else{
            stepy = 1;
            sidedisty = (mapy + 1.0f - playerposition.y) * deltadisty;
        }

        while (
            mapx >= 0 && mapx < 900 &&
            mapy >= 0 && mapy < 900 &&
            world_map[mapx / 30][mapy / 30] == 0
        )
        {
        if (sidedistx < sidedisty)
        {
            sidedistx += deltadistx;
            mapx += stepx;
            side = 0;
        }
        else
        {
            sidedisty += deltadisty;
            mapy += stepy;
            side = 1;
        }
    }
    if (side == 0)
    {
        perpWallDist = (sidedistx - deltadistx) /30;
    }
    else
        perpWallDist = (sidedisty - deltadisty) /30;

    if (perpWallDist < 0.0001f) perpWallDist = 0.0001f;




    int linehight =(int) (screenHeight / perpWallDist);
    int drawstart = (-linehight / 2) + (screenHeight / 2);
    if (drawstart < 0)
    {
        drawstart = 0;
    }
    int drawend = (linehight / 2) + (screenHeight / 2);
    if (drawend >= screenHeight)
    {
        drawend = screenHeight;
    }
    DrawRectangle(i,0,i,drawstart,BLUE);
    if (side == 1)
    {
        DrawRectangle(i,drawstart,i,drawend,DARKGRAY);
    }
    else DrawRectangle(i,drawstart,i,drawend,GRAY);
    
    DrawRectangle(i,drawend,i,screenHeight,BROWN);    
    }
    
    







}



