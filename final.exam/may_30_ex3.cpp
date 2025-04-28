#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
	char s[10000];
	char b[10000];
	int cas = 1;
	int i;
	int num;
	while( scanf("%s",s) ){
		printf("Case #%d\n", cas++);
    size_t len = strlen(s);
    for(i=0;i<len;i++){
		

    	printf("S = %c\n",s[i]);
		printf("M = %d\n", len);
		}
	}
	return 0;
}
