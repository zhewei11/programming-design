#include <stdio.h>

int main(void){
	int i=1;
	while(1){
		if(i % 3 == 1 && i % 5 == 3 && i % 7 == 2){
		
			printf("³Ì¤Ö%d\n",i);
			break;
		}
		i++;
	}
} 

