#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "general.h"
#include "deck.h"
#include "messages.h"

void intro(){

    printf("Welcome to BlackJack Table\n");
    printf("Press 1 to join the table or 0 to quit");


    int choice;

    // "0" or "1"
    if(scanf("%d", &choice) != 1){
        exit(1);
    }

    if(scanf("%d", &choice) == 1)
        play();
    else 
        exit(1);

}

//Checks the count of cards given versus the cards remaining on the deck
void check_max(int *c){
    if(*c > MAX_CARDS - 1){
        // We need a new deck because cards have already been dealt
        deck_create();
        printf("A new deck has been created...\n");
        deck_shuffle();
        printf("Shuffling deck...\n");

        //deck counter back to 0
        *c = 0;
    }
}

//function play
void play() {
    Player player;
    Player dealer;
    player.balance = 1000;

    int deck_counter = 0;
    int play_again = 1;

    printf("Loading deck from the files\n");
    deck_create();

    while (play_again && player.balance > 0) {
        printf("New round starting..\n");
        printf("Shuffling cards...\n");
        deck_shuffle();

        player.sum = 0;
        dealer.sum = 0;

        printf("Your balance: %d\n", player.balance);

        printf("Place your bet($): ");

        while (1) {
            if (scanf("%d", &player.bet) != 1) {
                printf("Invalid bet. Try again...\n");
                continue;
            }

            if (player.bet > player.balance || player.bet <= 0)
                printf("Invalid bet. Try again...\n");
            else
                break;
        }

        printf("Dealing...\n");

        //Dealer: 1st card (Open)
        dealer.sum += card[deck_counter].value;
        printf("Dealer's first card: %s\n", card[deck_counter].card_type);
        deck_counter++;

        //Dealer: 2nd card (Hidden)
        dealer.sum += card[deck_counter].value;
        printf("Dealer's 2nd card is hidden\n");
        deck_counter++;

        //Player: 1st card
        player.sum += card[deck_counter].value;
        printf("Your 1st card: %s\n", card[deck_counter].card_type);
        deck_counter++;

        //Player: 2nd card
        player.sum += card[deck_counter].value;
        printf("Your 2nd card: %s\n", card[deck_counter].card_type);
        printf("Total: %d\n", player.sum);
        deck_counter++;

        //Hit or Stand (maybe also double)
        while (player.sum < 21) {
            char choice;

            printf("Hit or Stand or Double(H or S or D)? ");

            while (scanf("%c", &choice) != 1){
                printf("Please try again. Wrong input!");
            }

            /* Choice (HIT,STAND,DOUBLE,SPLIT(on dev))*/        
            if (choice == 'H') { /*HIT*/
                // Checking if there are any more cards to be dealt
                check_max(&deck_counter);

                printf("Card given: %s\n", card[deck_counter].card_type);
                
                player.sum += card[deck_counter].value;
                
                deck_counter++;
                
                printf("New Total: %d\n", player.sum);
            } else if(choice == 'S') { /*STAND*/
                printf("You chose to stand at %d.\n", player.sum);
                break;
            } else if(choice == 'D') { /*DOUBLE*/
                if(player.bet * 2 >= player.balance){
                    int temp = player.bet * 2;
                    printf("Doubled your bet. Your new bet is: %d",temp);
                    continue;
                }else{
                    printf("You can't double the bet. Insufficient balance!");
                    continue;
                }      
            } else { /*WRONG INPUT*/
                printf("No option assigned to the letter you typed! Try again.");
                continue;
            }
        }
                
        

        //Check if player busted
        if (player.sum > 21) {
            printf("You busted! You just lost $%d.\n", player.bet);
            player.balance -= player.bet;
            printf("New balance: $%d\n",player.balance);
        } else {
            printf("Dealer reveals his hidden card --> %s. His Total now is: %d\n", card[deck_counter].card_type, dealer.sum);

            while (dealer.sum < 17) {
                printf("Dealer hits. Card given: %s\n", card[deck_counter].card_type);
                dealer.sum += card[deck_counter].value;
                printf("Dealer's Total: %d\n", dealer.sum);
                deck_counter++;
                
                check_max(&deck_counter);
            }

            if (dealer.sum > 21) {
                printf("Dealer busts! You won $%d!\n", player.bet);
                player.balance += player.bet;
            }else if (player.sum == 21){
                printf("Blackjack!! You won $%d!\n",player.bet);
                player.balance += player.bet;
            
            } else if (player.sum > dealer.sum) {
                printf("You just beat the dealer! You won $%d!\n", player.bet);
                player.balance += player.bet;
            } else if (player.sum < dealer.sum) {
                printf("Dealer wins. You lost $%d.\n", player.bet);
                player.balance -= player.bet;
            } else {
                printf("It's a tie! Your bet returned to your balance.\n");
            }
        }

        //Player's balance check
        if (player.balance <= 0) {
            printf("You are broke... Game is Over!\n");
            break;
        }

        printf("\nDo you want to play another round? (0 for No | 1 for Yes): ");
        scanf("%d", &play_again);
        
        //Πρέπει να μπει στην main λογικά
        //printf("Final balance: $%d\n", player.balance); 
    }
}
    
    


