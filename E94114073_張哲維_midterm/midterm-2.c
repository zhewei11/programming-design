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
		if(n==1) printf("玩家=剪刀\n");
		if(n==2) printf("玩家=石頭\n");
		if(n==3) printf("玩家=布\n");
		if(m==1) printf("電腦=剪刀\n");
		if(m==2) printf("電腦=石頭\n");
		if(m==3) printf("電腦=布\n");
		
		
		if(n==1 && m==1) printf("平手\n");
		else if(n==2 && m==2) printf("平手\n");
		else if(n==3 && m==3) printf("平手\n");
		else if(n==1 && m==2) printf("電腦贏\n");
		else if(n==1 && m==3) printf("玩家贏\n");
		else if(n==2 && m==3) printf("電腦贏\n");
		else if(n==2 && m==1) printf("玩家贏\n");
		else if(n==3 && m==2) printf("玩家贏\n");
		else if(n==3 && m==1) printf("電腦贏\n");
		printf("============================\n");
		f++;}	
}
