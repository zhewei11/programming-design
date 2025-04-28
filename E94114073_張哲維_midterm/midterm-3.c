#include<stdio.h>
#include<stdlib.h>

int fib(int);

int main(){
	int n;
	int num;
	printf("input:");
	scanf("%d\n",&num);
	for(n=1;n<=num;n++)
	printf("fib(%d)=%d\n",n,fib(n));
	return 0;
	
}
int fib(int n){
	if(n=1 || n==2)
		return 1;
	else
		return (fib(n-1)+fib(n-2));
} 
