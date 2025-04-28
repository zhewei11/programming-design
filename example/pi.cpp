#include<stdio.h>
#include<stdlib.h>

double l(int);
double p(double,int);

int main(){
	
	int i;
	for (i=1;i<=10000;i++); 
	printf("l(%d)=%12.10f\n",10000,l(10000));
	return 0;

}
double l(int n){
	int k;
	double sum=0.;
	for(k=1;k<=n;k++) 
		sum=sum+p(-1.0,k-1)/(2*k-1);
	return 4*sum;
}
double p(double base, int n){
	int i;
	double pow=1.0;
	for(i=1;i<=n;i++) 
		pow=pow*base;
	return pow;
}
