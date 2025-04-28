/*HW1.c*/
#include <stdio.h>									/*把stdio.h含括進來*/
#include <stdlib.h>									/*把stdlib.h含括進來*/

int main(void){										/*主函數main()開始*/
	int i= 5;            							/*宣告整數變數 i=5*/		
	int j= 10;										/*宣告整數變數 j=10*/

	printf("%d+%d=%d\n",i,j,i+j);					/*print i+j 並計算其值*/
	printf("%d-%d=%d\n",i,j,i-j);					/*print i-j 並計算其值*/
	printf("(%d+%d)*15/%d=%d\n",i,j,i,(i+j)*15/i);	/*print (i+j)*15/i 並計算其值*/
	system("pause");								/*呼叫dos裡面的pause指令，用來暫停程式的執行*/ 
	return 0;										/*main()結束，傳回0，表示函數正常結束*/ 
} 



/*output------- 
5+10=15
5-10=-5
(5+10)*15/5=45 
---------------*/ 
