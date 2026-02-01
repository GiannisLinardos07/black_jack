#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "general.h"

Card deck[MAX_CARDS];

void deck_create(){
    FILE *fptr = fopen("cards.txt", "r");
    if (fptr == NULL) {
        printf("Error!\n");
        exit(1);
    }

    for(int i = 0; i < MAX_CARDS; i++){
        if((scanf("%d %s",Card[i].value,Card[i].card_type)) != 2) {
            exit(1);
        }
        if(Card[i] == NULL) {
            exit(1);
        }
    }

    fclose(fptr);
}

void deck_shuffle(){
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
