#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int n;
	int f=1;
	int m;
	srand(time(NULL));
	while(1){
	
		printf("round%d=",f);
		scanf("%d",&n);
		m=rand()%3+1;
		printf("============================\n");
		if(n==1) printf("���a=�ŤM\n");
		if(n==2) printf("���a=���Y\n");
		if(n==3) printf("���a=��\n");
		if(m==1) printf("�q��=�ŤM\n");
		if(m==2) printf("�q��=���Y\n");
		if(m==3) printf("�q��=��\n");
		
		
		if(n==1 && m==1) printf("����\n");
		else if(n==2 && m==2) printf("����\n");
		else if(n==3 && m==3) printf("����\n");
		else if(n==1 && m==2) printf("�q��Ĺ\n");
		else if(n==1 && m==3) printf("���aĹ\n");
		else if(n==2 && m==3) printf("�q��Ĺ\n");
		else if(n==2 && m==1) printf("���aĹ\n");
		else if(n==3 && m==2) printf("���aĹ\n");
		else if(n==3 && m==1) printf("�q��Ĺ\n");
		printf("============================\n");
		f++;}	
}
