#include <stdio.h>

int main()
{
	double km,mile;

	printf("輸入公里:");
	scanf("%lf",&km);
	
	mile = km / 1.60;
	
	printf("%.2f公里=%.2f英里\n",km,mile);
	
	return 0;
}

