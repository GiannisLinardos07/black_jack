#define MAX_CARDS 52

typedef struct deck{
    int value;
    char card_type[20];
} Card;



typedef struct hand{
    int cards[52];
    char *type[52];
} Hand;


typedef struct player{
    int bet;
    int balance;
    int sum;
    Hand hand;
} Player;