#define MAX_CARDS 52

#ifndef GENERAL_H
#define GENERAL_H

typedef struct deck{
    int value;
    char card_type[20];
} Card;



typedef struct hand{
    int cards[MAX_CARDS];
    char *type[MAX_CARDS];
} Hand;


typedef struct player{
    int bet;
    int balance;
    int sum;
    Hand hand;
} Player;

#endif