
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 


typedef struct block {
	Vector3 position; 
	int mass;
	double speed ; 
}block;


int main(void)
{
    const int screenWidth = 1200;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "collision of blocks");


    SetTargetFPS(120);


    block smallbox; 
    smallbox.position.x=200;
    smallbox.position.y=screenHeight-35; 
    smallbox.position.z=10;
    smallbox.mass=1; 
    smallbox.speed=0; 

    block bigbox; 
    bigbox.position.x=300;
    bigbox.position.y=screenHeight-60; 
    bigbox.position.z=10; 
    bigbox.mass=10000; 
    bigbox.speed=-1;


    Vector3 cube_vector; 
    cube_vector.x=500;
    cube_vector.y=screenHeight-35; 
    cube_vector.z=10;


        // Main game loop
    //
    int amount_of_collisions=0;
 
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
            bool wall_collision=smallbox.position.x-25<=20;
            if (wall_collision){
                amount_of_collisions++; 

                smallbox.position.x=20+25;
                smallbox.speed=-smallbox.speed; 
            }


            bool box_collision = smallbox.position.x+25>=bigbox.position.x-50;
            if (box_collision){
                amount_of_collisions++; 
                bigbox.position.x= smallbox.position.x+75; 
                //calculation of collision 
                double tempspeed_smallbox=(smallbox.mass*smallbox.speed+bigbox.mass*bigbox.speed-bigbox.mass*smallbox.speed+bigbox.mass*bigbox.speed)/(smallbox.mass+bigbox.mass); 

                double tempspeed_bigbox=smallbox.speed-bigbox.speed+tempspeed_smallbox; 
                smallbox.speed=tempspeed_smallbox;
                bigbox.speed=tempspeed_bigbox;
                }
            
            bigbox.position.x= bigbox.position.x+bigbox.speed;
            smallbox.position.x=smallbox.position.x+smallbox.speed; 

            BeginDrawing();

            ClearBackground(BLACK);
            DrawLine(0, screenHeight-10, screenWidth, screenHeight-10, RED);
            DrawLine(20, 0, 20, screenHeight, RED); 
            DrawCube(smallbox.position, 50, 50, 20, RED);
            DrawCube(bigbox.position, 100, 100, 20, RED);

            int length_of_string = snprintf(NULL, 0, "%d",amount_of_collisions); 

            char* amount_of_collisions_text= malloc(length_of_string+1);
            snprintf(amount_of_collisions_text, length_of_string+1,"%d",amount_of_collisions); 

           
            DrawFPS(20, 20);                                                     // Draw current FPS
            DrawText(amount_of_collisions_text, screenWidth-50, 50, 12, GREEN);     

        EndDrawing();

        free(amount_of_collisions_text);
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // TODO: Unload all loaded resources at this point

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
















