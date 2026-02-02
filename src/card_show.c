#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "general.h"
#include "deck.h"

#define HOR 7
#define VER 6



void show_card(int c){
    //+-----+
    printf("+");
    for(int i = 0; i < HOR; i++){
        printf("-");
    }
    printf("+");

    // |     |
    for(int i = 0; i < VER; i++){
        printf("\n");
        for(int j = 0; j < (HOR + 2); j++){
            if(j == 0 || (HOR + 1) == j){
                printf("|");
            }else if((i == 1 && j == 1)){
                if(card[c].value == 10){
                    printf("%c%c",card[c].card_type[0],card[c].card_type[1]);
                    
                }else{
                    printf("%c",card[c].card_type[0]);
                }
            }else if ((i == (VER - 1) && j == HOR)){
                if(card[c].value == 10){
                    printf("%c%c",card[c].card_type[0],card[c].card_type[1]);
                    
                }else{
                    printf(" ");
                    printf("%c",card[c].card_type[0]);
                    j++;
                }
            }else{
                printf(" ");
            }
        }
    }

    //+-----+
    printf("\n");
    printf("+");
    for(int i = 0; i < HOR; i++){
        printf("-");
    }
    printf("+\n");
    return;
}



int main(){

    int c = 0;
    
    deck_create();

    show_card(c);
    
    return 0;
}

