#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "general.h"

void deck_create(deck Card){
    FILE *fptr;
    fptr = fopen("cards.txt","r")

    deck Card[52];

    for(int i = 0; i < MAX_CARDS; i++){
        if((scanf("%d %s",Card[i].value,Card[i].card_type)) != 2){
            exit(1);
        }
        if(Card[i] == NULL){
            exit(1);
        }
    }

    fclose(fptr);
}



void deck_shuffle(deck Card){
    srand(time(0));
    // Shuffle each card
    for(int i = MAX_CARDS - 1; i > 0 ; i--){
        int j = rand() % MAX_CARDS;

        int temp = Card[i].value;
        Card[i].value = Card[j].value;
        Card[j].value = temp;
        
        char temp_c[20];
        strcpy(temp_c,Card[i].card_type);
        strcpy(Card[i].card_type,Card[j].card_type);
        strcpy(Card[j].card_type,temp_c);
        
    }
}
