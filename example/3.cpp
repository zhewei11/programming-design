#include <stdio.h>

int main()
{
	double km,mile;

	printf("��J����:");
	scanf("%lf",&km);
	
	mile = km / 1.60;
	
	printf("%.2f����=%.2f�^��\n",km,mile);
	
	return 0;
}

