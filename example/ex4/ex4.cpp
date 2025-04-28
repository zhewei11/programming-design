#include <stdio.h>
#include <stdlib.h>
int main(void)
{
   int i;
   
   printf("可被2與3整除，但不能被12整除的數有 ");
   for(i=1;i<=100;i++)
   {
      if(i%2==0 && i%3==0 && i%12!=0)
          printf("%d ",i);
        continue;
   }
   
   system("pause");
   return 0;
}

