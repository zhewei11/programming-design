#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_CARDS 52 //defined the quantity of poker cards (excluding jokers)

//Defining a struct named Card with two integer fields suit and number.
typedef struct {
    char suit;    //poker suit
    int number;   //poker number 
} Card;

//building a  new deck in numerical order
void initializeDeck(Card *deck) {
    int index = 0;
    
    for (int number = 1; number <= 13; number++) {
        deck[index].suit = 'S';   // Spades
        deck[index].number = number;
        index++;

        deck[index].suit = 'H';   // Hearts
        deck[index].number = number;
        index++;

        deck[index].suit = 'D';   // Diamonds
        deck[index].number = number;
        index++;

        deck[index].suit = 'C';   // Clubs
        deck[index].number = number;
        index++;
    }
}

//shuffle the deck
void shuffleDeck(Card *deck) {
    srand(time(NULL));
    
    for (int i = MAX_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}


int main() {
    Card deck[MAX_CARDS]; //buildingthe deck with the 52 cards
    int numCards;         //the number of the cards user want to get 
    char choice;		  //the variable determine whether to continue the game 
    char response;		  //the variable determine whether to continue to get cards
    
    printf("           the poker deck established !\n\n ");
    while(true){
    printf("Please enter the desired quantity of cards¡]1-13¡^¡G");
    scanf("%d", &numCards);
    
    if (numCards < 1 || numCards > 13) {
        printf("wrong inout range¡I\n");
        continue;
    }
    

    initializeDeck(deck); //start building the deck
    shuffleDeck(deck);    //start shuffle the deck
    
    int i = 0;
    printf("press the enter button to get one card¡G\n");

		while (true) {
        getchar();  // push enter button to get one card
        printf("NO.%d: suit¡G%c , number¡G%d\n",i+1, deck[i].suit, deck[i].number);
        i++;
        
 // user determine whether to get more card when the suquence reaches the sixth       
        if(i==6){
        	printf("Total number of cards is too large ,whether to continue to be listed ! (Y/N)\n");
    		scanf(" %c", &response);
 			if (response == 'N' || response == 'n') {
 				printf("whether to restart the game ¡H¡]Y/N¡^¡G");
            	scanf(" %c", &choice);
        
		        if (choice == 'N' || choice == 'n') {
		            break;
		        } 
				else if (choice != 'Y' && choice != 'y') {
		            printf("wrong input !, please enter Y or N¡C\n");
		            continue;
		        }
		        printf("Please enter the desired quantity of cards¡]1-13¡^¡G");
		    	scanf("%d", &numCards);
		    while(numCards < 1 || numCards > 13){
			
		        	printf("wrong input range¡I\n");
		        	printf("Please enter the desired quantity of cards¡]1-13¡^¡G");
    				scanf("%d", &numCards);
		    	
		    }
		        // reshuffle the desk and card sequence if user restart the game 
		        shuffleDeck(deck);
		        i = 0;
		 }
 			else if (response != 'Y' && response != 'y') {
            printf("\n");
            continue;}		
		}
        
//if the number of cards user determine send out ,asking the user whether to restart the game and re-enter the quantity 
        if (i >= numCards) {
            printf("No more cards¡I\n");
            printf("=========================\n\n");
            printf("whether to restart the game¡H¡]Y/N¡^¡G");
            scanf(" %c", &choice);
        
        if (choice == 'N' || choice == 'n') {
            break;
        } 
		else if (choice != 'Y' && choice != 'y') {
            printf("wrong input !, please enter Y or N¡C\n");
            continue;
        }
        printf("Please enter the desired quantity of cards¡]1-13¡^¡G");
    	scanf("%d", &numCards);
    
    	while(numCards < 1 || numCards > 13){
        	printf("wrong input range¡I\n");
        	printf("Please enter the desired quantity of cards¡]1-13¡^¡G");
    		scanf("%d", &numCards);
    		}
        shuffleDeck(deck);
        i = 0;
            
		   }
    }
    if (choice == 'N' || choice == 'n') {
        	printf("thanks for playing ! ");
            break;
	}
}
}

