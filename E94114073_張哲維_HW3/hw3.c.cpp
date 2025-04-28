#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//mode1&3 generate answer
void generate_answer(int digit, int answer[]){
    int i,j;
    for(i=0;i<digit;i++)
    {
        answer[i]=rand()%10;
        for(j=0;j<i;j++)
        {
// if the number recur delete it 
            if (answer[i] == answer[j]) 
            {
                i--;  
                break;      
            }
        }
    }
}



// examine whether the guess numbers are correct
void game(int digit){
    int answer[digit];   // answer list
    generate_answer(digit, answer);
    int guess[digit];   // guess list
    int i, j;           // circle times
    int A, B;           // A & B times
    int round = 0;      // round times
    int isWin = 0;      // distinguish whether to guess the answer
    int isRepeat;		// distinguish whether the numbers are recurring
	
    while (!isWin) {
     	
        printf("請輸入 %d 個不重複的數字（0~9）：", digit);
        scanf("%1d%1d%1d%1d", &guess[0], &guess[1], &guess[2], &guess[3]);
            if (digit == 5) 
		{
            scanf("%1d", &guess[4]);
        }
        
    
//check for the duplicates
			isRepeat=0;      
        	for (i = 0; i < digit; i++) 
			{
		    for (j = i+1 ; j < digit; j++) 
				{
		        if (guess[i] == guess[j]) 
					{
		            printf("輸入的數字有重複，請重新輸入\n");
		            isRepeat = 1;
		            break;}
		        }
		    }
		    
		    

// count the a&b quantity

        A = B = 0;
        for (i = 0; i < digit; i++) {
            if (guess[i] == answer[i]) {
                A++;
            } else {
                for (j = 0; j < digit; j++) {
                    if (guess[i] == answer[j]) {
                        B++;
                        break;
                    }
                }
            }
        }
        if(isRepeat==0) printf("%dA%dB\n", A, B);
        round++;
        

// determine whether all of the number are correct 
        if (A == digit) {
            isWin = 1;
            printf("恭喜你猜中了！\n");
            printf("共猜了 %d 回合\n", round);
        }
    }
    
}




//Enter the numbers and let the computer guess
void comput(int digit){
	int answer[4];   // answer list
    int guess[digit];   // guess list
    int i, j;           // circle times
    int A, B;           // A & B times
    int round = 0;      // round times
    int isWin = 0;
    int isRepeat=1;

    printf("請輸入 %d 個不重複的數字（0~9）：",digit);
    scanf("%1d%1d%1d%1d", &answer[0], &answer[1], &answer[2], &answer[3]);
   
    while (!isWin) {
        //computer radomly generate a number 
        for (i = 0; i < 4; i++) {
            guess[i] = rand() % 10; //the numbers are between 0 and 9
            for (j = 0; j < i; j++) {
                if (guess[i] == guess[j]) {
                    i--; //if the number repeats ,delete it 
                    break;
                }
            }
        }

// count the a&b quantity
        A = B = 0;
        for (i = 0; i < 4; i++) {
            if (guess[i] == answer[i]) {
                A++;
            } else {
                for (j = 0; j < 4; j++) {
                    if (guess[i] == answer[j]) {
                        B++;
                        break;
                    }
                }
            }
        }

// print the result
        printf("電腦猜測的數字為：%1d%1d%1d%1d，結果為 %dA%dB\n", guess[0], guess[1], guess[2], guess[3],A, B);
        round++;

//determine whether the answer is correct
        if (A == 4) {
            isWin = 1;
            printf("電腦猜中了！\n");
            printf("共猜了 %1d回合\n", round);
        }
    }
}

int main()
{	
// the choices of mode
	int mode;		
	while (mode != 4) {
		printf("**=========================================**\n");
        printf("**             請選擇遊戲模式：            **\n");
        printf("** 1：電腦為出題者，使用者為答題者（4位數）**\n");
        printf("** 2：使用者為出題者，電腦為答題者（4位數）**\n");
        printf("** 3：電腦為出題者，使用者為答題者（5位數）**\n");
        printf("** 4：結束遊戲                             **\n");
        printf("**=========================================**\n");
        scanf("%d", &mode);
        if(mode!=1&&mode!=2&&mode!=3&&mode!=4){
        	printf("沒有那麼多模式!\n");
		}

//Enter the selected mode		
	switch (mode)
	{
		case 1:
			game(4);
			break;
		case 2:
			comput(4);
			break;
		case 3:
			game(5);
			break;
		case 4:
			printf("感謝遊玩!");
			break;
	}

}
}

		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	
		

