#include <stdio.h>
#include <stdlib.h>
int main(void)
{
   int input,cnt=0,passwd=61;
   int max=100;
   int min=0;
   
   while(1)
   {
      printf("Password: ");
      scanf("%d", &input);
      cnt++;
      if(input==passwd)
      {
         printf("Correct! Welcome to the system!\n");  
         break;}
	  else if (input>passwd){
	  	max=input;
		printf("%d~%d\n",min,max);
	  }
	  else if (input<passwd){
	  	min=input;
	  	printf("%d~%d\n",min,max);
	  }
	  printf("還有%d次機會\n",10-cnt);
              
      if(cnt>=10)
      {
         printf("Over 10 times!!\n");
         break;
      } 
   }      
   
   system("pause");
   return 0;
}

