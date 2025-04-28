#include <stdio.h>

int main()
{
	int a, b, c;
	printf("input:");
	scanf("%d %d",&a,&b);

	while(a<=0 ||b<=0);
	c=a%b;
	while(b!=0)
	{
		c=a%b;
		a=b;
		b=c;
		
	}
	printf("最大公因數%d\n",a);

}
