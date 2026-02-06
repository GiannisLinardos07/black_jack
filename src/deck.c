#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "general.h"


void deck_create(){
    FILE *fptr = fopen("cards.txt", "r");
    if (fptr == NULL) {
        printf("Error!\n");
        exit(1);
    }

    for(int i = 0; i < MAX_CARDS; i++){
        if((scanf("%d %s",card[i].value,card[i].card_type)) != 2) {
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

        int temp = card[i].value;
        card[i].value = card[j].value;
        card[j].value = temp;
        
        char temp_c[20];
        strcpy(temp_c,card[i].card_type);
        strcpy(card[i].card_type,card[j].card_type);
        strcpy(card[j].card_type,temp_c);
        
    }
}
