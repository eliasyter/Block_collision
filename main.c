
#include <stdio.h>
#include <stdbool.h> 

typedef struct block {
	double positionX; 
	int mass;
	double speed ; 
}block; 

int main() {
    
    block smallbox; 
    smallbox.positionX=50; 
    smallbox.mass=1; 
    smallbox.speed=0; 

    block bigbox; 
    bigbox.positionX=2000; 
    bigbox.mass=10000000; 
    bigbox.speed=-0.01; 
    
    int amount_of_collisions=0; 
    // bigbox speed will normaly be smaler because it is moving in a negative diraction
    while(true){

        if (bigbox.speed> smallbox.speed && smallbox.speed>0){
            break; 
        }
        bool wall_collision=smallbox.positionX<=0;
        if (wall_collision){
            amount_of_collisions++; 

            smallbox.positionX=0;
            smallbox.speed=-smallbox.speed; 
        }


        bool box_collision = smallbox.positionX>=bigbox.positionX;
        if (box_collision){
            amount_of_collisions++; 
            printf("%i\n", amount_of_collisions);
            printf("smallbox: %f, bigbox:%f\n", smallbox.speed, bigbox.speed);
            bigbox.positionX= smallbox.positionX; 
            //calculation of collision 
            double tempspeed_smallbox=(smallbox.mass*smallbox.speed+bigbox.mass*bigbox.speed-bigbox.mass*smallbox.speed+bigbox.mass*bigbox.speed)/(smallbox.mass+bigbox.mass); 
            double tempspeed_bigbox=smallbox.speed-bigbox.speed+tempspeed_smallbox; 
            smallbox.speed=tempspeed_smallbox;
            bigbox.speed=tempspeed_bigbox;


            printf("%i\n", amount_of_collisions);
            printf("smallbox: %f, bigbox:%f\n", smallbox.speed, bigbox.speed);

        }
        smallbox.positionX+=smallbox.speed;
        bigbox.positionX+=bigbox.speed; 

    }       
    

	printf("%i\n", amount_of_collisions);
	return 0;
} 











