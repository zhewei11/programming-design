#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int i =1;
	int n,sum=0;
   printf("�п�Jn�ȡAn���_��:");
   scanf("%d",&n);
   
   while(i<=n){
   	sum+=i;
   	i+=2;
	}
   printf("1+3+5+...+%d=%d\n",n,sum);
      
   system("pause");
   return 0;
}
	

