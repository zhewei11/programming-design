#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include <time.h>
int q[4];  //把出好的題目放在這裡，需四個位置
char a[500];  //放讓使用者輸入的數字 
int a_int[4];  //把使用者輸入的字串轉成數字後放在這四個位置 
int ifclear = 0;  //當布林值用，表示過關與否，一開始當然沒過關，所以是0 
int tocontinue = 1;  //當布林值用，表示要繼續遊戲與否 
int toquit = 0;  //當布林值用，表示要跳出遊戲與否 
 
void makeQ(void);  //出題 
void getA();  //取得數字
void outcome(void);  //顯示結果
void intro(void);  //介紹文
void menu(void);  //使用者選單
 
int main(void){  //嘿嘿，主程式好短∼應該不難懂∼ 
    intro();  //先來個介紹文吧∼
    while(1==1){
        ifclear =0;
        tocontinue = 1;
        makeQ();  //出題
        while(tocontinue){
            getA();
        }
        if(toquit) break;
    } 
    return 0;
}

/****** 介紹文 ******/
void intro(void){
    printf("***************************************************\n");
    printf("***************************************************\n");
    printf("**                                               **\n");
    printf("**  大兜蟲猜數字遊戲 Ver1.1                      **\n");
    printf("**                                               **\n");
    printf("**  遊戲規則：                                   **\n");
    printf("**  1.輸入4個不重複的數字                        **\n");
    printf("**  2.出現A的次數代表你猜對了幾個數字且位置正確  **\n");
    printf("**  3.出現B的次數代表你猜對了幾個數字但位置不對  **\n");
    printf("**  4.也就是說當4A0B的時候，就是你過關的時候     **\n");
    printf("**  5.祝好運！                                   **\n");
    printf("**                                               **\n");
    printf("**  操作說明：                                   **\n");
    printf("**  1.輸入四個數字直到猜出來                     **\n");
    printf("**  2.輸入'm'可以進入選單控制                    **\n");
    printf("**  3.輸入大兜蟲的出生日年月日會有異想不到的驚喜 **\n");
    printf("**                                               **\n");
    printf("***************************************************\n");
    printf("***************************************************\n");
}
/****** 出題函數 ******/
void makeQ(void){
    int i,j;
    srand(time(0));
    for(i=0;i<4;i++){
        *(q+i) = rand()%10;
        for(j=0;j<i;j++){
            while(*(q+i) == *(q+j)){  //這個while是用來當數字重複出現時讓就再一次取亂數
                *(q+i) = rand()%10;
            }
        }
     
    }
}
/****** 讀數字函數 ******/
void getA(){
    printf("\n請輸入: ");
    int i,j;  //迴圈專用 
    int boolin = 1;  //用來表示使用者是否正常輸入
    
    fgets(a,sizeof(a),stdin);
    *(a+strlen(a)-1)= '\0'; 
    //因為fget只要成功讀取，會自動在'\0'前面加上'\n'，所以要把'\n'變成'\0'，不然結果會不如預期地多出1
    
    if(*(a) == 'm' && strlen(a) == 1){  //只要使用者一輸入m就立即叫出選單 
        menu();
    }else if(*a == '7' && *(a+1) == '8' && *(a+2) == '1' && *(a+3) == '1' && *(a+4) == '2' && *(a+5) == '3' && strlen(a) == 6){
        printf("大兜偷偷告訴你...答案是："); 
        for(i=0;i<4;i++){
            printf("%d",*(q+i));
        }
        printf("\n");
    }else{ 
        
        if(!(strlen(a)==4)){  //判斷使用者是否輸入了四個字元 
            boolin *=0;  //表示使用者不正常輸入 
            printf("請不要輸入太多或太少\n");
        }
        for(i=0;i<strlen(a);i++){  //判斷讓使用者是否輸入0到9 
            if(!(*(a+i) >= '0' && *(a+i) <= '9')){
                boolin *= 0;
                printf("請輸入數字0~9\n");
                break;
            }
        }
    
        for(i=0;i<4;i++){  //判斷使用者是否輸入重複數字 
            for(j=0;j<i;j++){
                while(*(a+i) == *(a+j)){  //這裡和上述出題用的是一樣的原理 
                    printf("請不要輸入重複的數字\n");
                    boolin *= 0;
                    break;
                }
                if(!boolin) break;
            }
            if(!boolin) break;
        }
    
        if(boolin){  //boolin如果等於1，也就是使用者正常輸入，才開始把字串轉成數字 
            for(i=0;i<4;i++){
                *(a_int+i) = *(a+i) - '0'; 
            }
            outcome();  //轉成數字後呼叫outcome看看結果為幾A幾B
        }
    }   
}
