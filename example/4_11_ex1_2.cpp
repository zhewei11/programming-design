#include <stdio.h>
#include <stdlib.h>

int find_k(int);

int main (void){
	int n;
	printf("輸入n值:");
	scanf("%d\n",&n);
	printf("整數%d值，使得4k+2值最接近%d\n",find_k(n),n);
	system("pause");
	return 0;
}
int find_k(int n){
	int k=1,num=2;
	while(1){
		if(abs(num-n)<=abs((4*k+2)-n))
			return k-1;
		else{
			num=4*k+2;
			k++;
		}
	}
	
	
}
