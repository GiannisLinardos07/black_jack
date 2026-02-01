#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "general.h"

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
                    printf("%.2s",card[c].card_type);
                    j++;
                }else{
                    printf("%c",card[c].card_type);
                }
            }else if ((i == (VER - 1) && j == HOR)){
                if(Card[c].value == 10){
                    printf("%.2s",card[c].card_type);
                    j++;
                }else{
                    printf(" ");
                    printf("%c",card[c].card_type);
                    j++;
                }
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
    Card card[MAX_CARDS];
    int c = 0;
    show_card(c);
    return 0;
}

