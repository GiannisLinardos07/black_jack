#include <stdio.h>
#include <stdlib.h>
#include "deck.h"



void deck_create(deck Card){
    FILE *fptr;
    fptr = fopen("cards.txt","r")

    for(int i = 0; i < 52; i++){
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

}
