#include <stdio.h>
#include <stdlib.h>
int main(void)
{
   int i;
   
   printf("�i�Q2�P3�㰣�A������Q12�㰣���Ʀ� ");
   for(i=1;i<=100;i++)
   {
      if(i%2==0 && i%3==0 && i%12!=0)
          printf("%d ",i);
        continue;
   }
   
   system("pause");
   return 0;
}

