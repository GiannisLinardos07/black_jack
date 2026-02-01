#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "general.h"
#include "deck.h"

void intro(){

    printf("Welcome to BlackJack Table\n");
    printf("Press 1 to join the table or 0 to quit")


    int choice;

    // "0" or "1"
    if(scanf("%d",choice) != 1){
        exit(1);
    }

    if(scanf("%d", choice) == 1)
        play();
    else 
        exit(1);

}

//Checks the count of cards given versus the cards remaining on the deck
void check_max(int *c){
    if(c > MAX_CARDS - 1){
        // We need a new deck because cards have already been dealt
        deck_create();
        printf("A new deck has been created...\n");
        deck_shuffle();
        printf("Shuffling deck...\n");

        //deck pos back to 0
        *c = 0;
    }
}

//function play
void play() {
    Player player;
    Player dealer;
    player.balance = 1000;

    int deck_counter = 0;

    printf("Loading deck from the files\n");
    deck_create();

    //Συνθήκη για την while!!!
    while (1) {
        printf("New round starting..\n");
        printf("Shuffling cards...\n");
        deck_shuffle();

        player.sum = 0;
        dealer.sum = 0;

        printf("Your current balance: %d\n", player.balance);

        printf("Place your bet: ");
        scanf("%d", &player.bet);

        printf("Dealing...\n");

        //Dealer: 1st card (Open)
        dealer.Hand.Cards[0] = deck[deck_counter].value;
        dealer.sum += deck[deck_counter].value;
        printf("Dealer's first card: %s\n", deck[deck_counter].card_type);
        deck_counter++;

        //Dealer: 2nd card (Hidden)
        deal.sum += deck[deck_counter].value;
        printf("Dealer's 2nd card is hidden\n");
        deck_counter++;

        //Player: 1st card
        player.sum += deck[deck_counter].value;
        printf("Your 1st card: %s\n", deck[deck_counter].card_type);
        deck_counter++;

        //Player: 2nd card
        player.sum += deck[deck_counter].value;
        printf("Your 2nd card: %s\n", deck[deck_counter].card_type);
        printf("Total: %d\n", player.sum);
        deck_counter++;

        //Hit or Stand (maybe also double)
        while (player.sum < 21) {
            char choice;

            printf("Hit or Stand (H or S)? ");

            if (scanf(" %c", &choice) != 1)
                exit (1);
            
            if (choice == 'H') {
                // Checking if there are any more cards to be dealt
                check_max(&deck_counter);

                printf("Card given: %s\n", deck[deck_counter].card_type);
                
                player.sum += deck[deck_counter].value;
                
                deck_counter++;
                
                printf("New Total: %d\n", player_sum);
            } else
                break;
        }

        //Check if player busted
        if (player.sum > 21) {
            printf("You busted! You just lost %d.\n", player.bet);
            player.balance -= player.bet;
            printf("New balance: %d\n",player.balance);
        } else {
            printf("Dealer reveals hidden card. His Total is: %d\n", dealer.sum);

            while (dealer.sum < 17) {
                //Κάνει hit ο dealer μέχρι να φτάσει στα 17. Μετά σταματάει
                check_max(&deck_counter);

                 printf("Card given: %s\n", deck[deck_counter].card_type);
                
            }

        }

    }
    
}