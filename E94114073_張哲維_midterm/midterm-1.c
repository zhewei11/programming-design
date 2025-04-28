#include<stdio.h>
#include<stdlib.h>

int main(){
	int ch[4];
	int num;
	while(1){
		printf("input:");
		scanf("%d%d%d%d\n",&ch[0],&ch[1],&ch[2],&ch[3]);
		num=ch[0]*8+ch[1]*4+ch[2]*2+ch[3];
		printf("output:%d\n",num);
	}
} 
