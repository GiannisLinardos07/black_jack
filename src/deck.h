#define MAX_CARDS 52

typedef struct deck{
    int value;
    char card_type[20];
} Card;


typedef struct player{
    int bet;
    int balance;

} Player;

typedef struct hand{
    
}