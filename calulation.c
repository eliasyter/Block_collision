


#include <stdio.h>
#include <stdbool.h> 

typedef struct block {
	double positionX; 
	long mass;
	double speed ; 
}block; 

int main() {
    
    block smallbox; 
    smallbox.positionX=50; 
    smallbox.mass=1; 
    smallbox.speed=0; 

    block bigbox; 
    bigbox.positionX=2000; 
    bigbox.mass=1000000000000; 
    bigbox.speed=-1; 
    
    int amount_of_collisions=0; 
    // bigbox speed will normaly be smaler because it is moving in a negative diraction
    while(true){

       if (bigbox.speed> smallbox.speed && smallbox.speed>0){
           break; 
       }

        if (smallbox.speed>=0){
        amount_of_collisions++; 
        //calculation of collision 
        double tempspeed_smallbox=(smallbox.mass*smallbox.speed+bigbox.mass*bigbox.speed-bigbox.mass*smallbox.speed+bigbox.mass*bigbox.speed)/(smallbox.mass+bigbox.mass); 
        double tempspeed_bigbox=smallbox.speed-bigbox.speed+tempspeed_smallbox; 
        smallbox.speed=tempspeed_smallbox;
        bigbox.speed=tempspeed_bigbox;
        }


        if(smallbox.speed<0){
        amount_of_collisions++;
        smallbox.speed=-smallbox.speed; 
        }



    }       
    

	printf("%i\n", amount_of_collisions);
	return 0;
} 





























