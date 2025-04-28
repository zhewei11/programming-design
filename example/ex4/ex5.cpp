#include <stdio.h>
#include <stdlib.h>
int main(void)
{
   int i,num,prime,flag=0;
   printf("Intput: "); 
   scanf("%d",&num);
   prime =num-1;
   while(flag!=1)
   {
   for(i=2;i<prime;i++)
      if(prime%i==0)
      {
        prime--;
        continue;
      }
    flag=1;
  }
   printf("小於%d最大質數%d\n",num ,prime);   
   
   system("pause");
   return 0;
}		
