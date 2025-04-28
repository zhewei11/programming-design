#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int num_trail =10000000;	//pull times 
	int five_num_star=0;		//pull five-star card times
	int four_num_star=0;		//pull four-star card times
	srand(time(NULL));
	
//gacha ----------------------------------------------------------------
	for (int i = 0 ; i<num_trail ;i++){
//-------------------------------------------------------------------------------------------------------	
//		int rand_num =rand() % 10000;					//Randomly generate number between 0 and 10000  
//																										
//		if(rand_num <=60){           					//number<=60 , get five-star card				
//			five_num_star++;																			
//		} 
//		else if(rand_num<=570){							//60< number <=510 , get four-star card
//			four_num_star++;	
//		}
//-------------------------------------------------------------------------------------------------------
		double rand_num =(double)rand() /RAND_MAX;		//Randomly generate number between 0 and 1
			
		if(rand_num <=0.006){           				//number<=0.006, get five-star card 
			five_num_star++;
		} 
		else if(rand_num<=0.057){						//0.006< number <=0.057, get four-star card
			four_num_star++;	
		}
}
	//probability 
	printf("⒱쩧5촒쩮업쾤: %.4f%%\n", (double)five_num_star/num_trail*100);
	printf("⒱쩧4촒쩮업쾤: %.4f%%\n", (double)four_num_star/num_trail*100);
	return 0;
}

