#include "player.h"
#include "raylib.h"
#include "raymath.h"
#include "map.h"
Vector2 playerposition = {450,300};
Vector2 playerdirection = {1,0};
Vector2 plane = {0, 0.66f};
float speed = 100;
float rotatSpeed = 0.1f ;
void rotate(float rotatespeed){
    float olddirection = playerdirection.x;
    playerdirection.x = playerdirection.x *cosf(rotatespeed ) - playerdirection.y * sinf(rotatespeed);
    playerdirection.y = olddirection * sinf(rotatespeed ) + playerdirection.y * cosf(rotatespeed );

    float oldplanex = plane.x;
    plane.x = plane.x * cosf(rotatespeed ) - plane.y * sinf(rotatespeed);
    plane.y = oldplanex * sinf(rotatespeed ) + plane.y * cosf(rotatespeed );

}
void player(void){
    Vector2 newposition = playerposition;
    Vector2 move = {0};
    Vector2 right = { playerdirection.y, -playerdirection.x };
    float dt = GetFrameTime();

    if (IsKeyDown(KEY_LEFT_CONTROL))
    {
        speed = 50;
    }
    if (IsKeyReleased(KEY_LEFT_CONTROL))
    {
        speed = 100;
    }
    if (IsKeyDown(KEY_LEFT_SHIFT))
    {
        speed = 400;
    }
    if (IsKeyReleased(KEY_LEFT_SHIFT))
    {
        speed = 100;
    }
    
    
    
    

    if (IsKeyDown(KEY_W))
    {
        move = Vector2Add(move,playerdirection);
    }
    if (IsKeyDown(KEY_S))
    {
        move = Vector2Subtract(move,playerdirection);
    }
    if (IsKeyDown(KEY_A))
    {
        move = Vector2Add(move,right);
    }
    if (IsKeyDown(KEY_D))
    {        
        move = Vector2Subtract(move,right);
    }
    if (Vector2Length(move) > 0)
{
    move = Vector2Normalize(move);
    // playerposition = Vector2Add(playerposition, Vector2Scale(move, speed * GetFrameTime()));
}

    Vector2 newpositionX = { playerposition.x + move.x * speed * dt, playerposition.y };
        int i = newpositionX.x / 30;
        int j = playerposition.y / 30;
        if (world_map[i][j] == 0)
        {
            playerposition.x = newpositionX.x;
        }
        else playerposition.x = playerposition.x;
        Vector2 newpositionY = { playerposition.x, playerposition.y + move.y * speed * dt };
        i = playerposition.x / 30;
        j = newpositionY.y / 30;
        if (world_map[i][j] == 0)
        playerposition.y = newpositionY.y;
        else playerposition.y = playerposition.y;

    if (IsKeyDown(KEY_RIGHT))
    {
        rotate(rotatSpeed);
    }
    if (IsKeyDown(KEY_LEFT))
    {
        rotate(-rotatSpeed);
    }
    playerdirection = Vector2Normalize(playerdirection);
    
}



void draw_player(void){
    DrawCircleV(playerposition,10, RED);
    Vector2 lineEnd = Vector2Add(
    playerposition,
    Vector2Scale(playerdirection, 20)
);
    DrawLineEx(playerposition, lineEnd, 5, RED);
}

