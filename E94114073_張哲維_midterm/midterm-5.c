#include<stdio.h>
#include<stdlib.h>

int main(){
	char i;
	int n;
	while(1){
	printf("Input:");
	scanf("%c",&i);
	n=("%d",i);
	if(n>=65 && n<=90) {
	printf("The character is an uppercase letter.\n");}
	else if(n>=97 && n<=122) {
		printf("The character is a lowercase letter\n");}
	else if(n>=48 && n<=57) {
		printf("The character is a digit\n");}
	else {
		printf("The character is a symbol\n");}
} 
}
