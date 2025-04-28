#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int input,cnt=0,ans=rand()%100,max=100,min=0;
   
   while(1)
   {
      printf("guess number: ");
      scanf("%d", &input);
     
      cnt++;
      if(input==ans)
      {
         printf("you got it");  
         break;
      }  
	  	else{
	  		if(input>ans)
	  			max=input;
	  		else if (input<ans)
	  			min=input;
	  		printf("range:%d~%d\n",min,max);}      
      if(cnt>=10)
      {
         printf("Over 10 times!!\n");
         break;
      } 
   }      
   
   system("pause");
}
