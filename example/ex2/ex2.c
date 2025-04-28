#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i=1;
	int j=2;
	int sum=0;
   while(i<=49){
   	sum+=i*i-j*j;
   	i+=2;
   	j+=2;
   }

   printf("1^2-2^2+3^2-4^2+...+49^2-50^2=%d\n",sum);
   
   system("pause");
	return 0;
}
