/*HW1.c*/
#include <stdio.h>									/*��stdio.h�t�A�i��*/
#include <stdlib.h>									/*��stdlib.h�t�A�i��*/

int main(void){										/*�D���main()�}�l*/
	int i= 5;            							/*�ŧi����ܼ� i=5*/		
	int j= 10;										/*�ŧi����ܼ� j=10*/

	printf("%d+%d=%d\n",i,j,i+j);					/*print i+j �íp����*/
	printf("%d-%d=%d\n",i,j,i-j);					/*print i-j �íp����*/
	printf("(%d+%d)*15/%d=%d\n",i,j,i,(i+j)*15/i);	/*print (i+j)*15/i �íp����*/
	system("pause");								/*�I�sdos�̭���pause���O�A�ΨӼȰ��{��������*/ 
	return 0;										/*main()�����A�Ǧ^0�A��ܨ�ƥ��`����*/ 
} 



/*output------- 
5+10=15
5-10=-5
(5+10)*15/5=45 
---------------*/ 
