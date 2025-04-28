#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int num_trial = 1000000;    	 //pull times 
    int five_num_star = 0;       	 //pull five-star card times
    int four_num_star = 0;       	 //pull four-star card times 
    double five_star_prob = 0.006;   //five-star card probability
    double four_star_prob = 0.051;   //four-star card probability
    int five_star_acc = 0;       	 //five-star card accumulated times
    int four_star_acc = 0;       	 //four-star card accumulated times 
    srand(time(NULL));

    for (int i = 0; i < num_trial; i++) { 
        //four-star card minimum guaranteed  
        if (four_star_acc == 8)   		//ninth-draw probability
		{four_star_prob = 0.562;} 
			
		else if (four_star_acc == 9) 	//tenth-draw  probability 
		{four_star_prob = 0.994;} 
			
		else 							//the others-draws probability
		{four_star_prob = 0.051; }

        //five-star card minimum guaranteed
        if (five_star_acc >= 73 && five_star_acc < 89) 	//In 73~89 draws ,probability+0.06 for every extra draw 
		{five_star_prob += 0.06;} 
		
		else if (five_star_acc == 89) 					//ninetieth-draw probability
		{five_star_prob = 1.0;}
			
			
			
			
			
		else 											//the others-draws of probability
		{five_star_prob = 0.006;}

        //Randomly generate number between 0 and 1
        double rand_num = (double)rand() / RAND_MAX;
//gacha--------------------------------------------------------------- 
        if (rand_num < five_star_prob) {
            five_num_star++;       //get five-star card 
            four_star_acc++;       //four-star card accumulated times +1
            five_star_acc = 0;     //reset five-star card accumulated times
        } 
		else if (rand_num < five_star_prob + four_star_prob) {
            four_num_star++;       //get four-star card
            five_star_acc++;       //five-star card accumulated times+1
            four_star_acc = 0;     //reset four-star card accumulated times
        } 
        
        
        
        
        
        
        
		else {                     //get the others-card
            four_star_acc++;       //four-star card accumulated times+1
            five_star_acc++;       //five-star card accumulated times+1
        }
    }
    //comprehensive probability
    printf("⒱쩧5촒쩮업쾤: %.4f%%\n", (double)five_num_star / num_trial * 100);
    printf("⒱쩧4촒쩮업쾤: %.4f%%\n", (double)four_num_star / num_trial * 100);

    return 0;
}
