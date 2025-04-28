#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int i =1;
	int n,sum=0;
   printf("請輸入n值，n為奇數:");
   scanf("%d",&n);
   
   while(i<=n){
   	sum+=i;
   	i+=2;
	}
   printf("1+3+5+...+%d=%d\n",n,sum);
      
   system("pause");
   return 0;
}
	

