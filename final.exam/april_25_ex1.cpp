#include <stdio.h>
#include <stdlib.h> 

int main()
{
	int score[10]={86,55,95,80,73,100,96,25,64,20};
	int count;
	int max,min;
	int e=0,o=0;
	for (int i=0;i<10;i++){
		count+=score[i];
		if(i<9) printf("%1d+",score[i]);
		else printf("%1d=%1d\n",score[i],count);
		
		if(score[i]>max) max=score[i];
		
		if(score[i]<min) min=score[i];
		if(score[i]%2==0) e++;
		else o++;
		}
	printf("max=%1dmin=%1d\n",max,min);
	printf("even=%d,odd=%d\n",e,o);
}
	
		

