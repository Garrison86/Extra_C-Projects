#include <stdio.h>
#include <stdlib.h>
#define DECKSIZE 52

typedef struct
{ // declare a card struct
    int pips;
    char suit;
} card;                              // typedef as card type



card deck[DECKSIZE] = {0, 0};        // declare a deck of cards
char suits[] = {'C', 'H', 'S', 'D'}; // clubs, hearts spades,…
void swap(card *, card *);           // forward declarations
void initialize(card *);
void display(card *);
void shuffle(card *);



int main(void)
{
    printf("Initializing deck..\n");
    initialize(deck);
    printf("Displaying unshuffled deck\n");
    display(deck);
    printf("Shuffling the deck...\n");
    shuffle(deck);
    printf("Shuffled deck\n");
    display(deck);
}



void initialize(card *deck)
{
    for (int crdctr = 0; crdctr < DECKSIZE; deck++, crdctr++)
    {
        deck->pips = crdctr % 13 + 1;
        deck->suit = suits[(crdctr) / 13];
    }
}
void display(card *deck)
{
    for (int crdctr = 0; crdctr < DECKSIZE; deck++, crdctr++)
    {
        printf("%d%c", deck->pips, deck->suit);
        printf((crdctr + 1) % 13 ? " " : "\n");
    }
    printf("\n");
}
void shuffle(card *deck)
{
    int swapCard;
    for (int crdctr = 0; crdctr < DECKSIZE; crdctr++)
    {
        swapCard = rand() % DECKSIZE;
        swap(deck + crdctr, deck + swapCard);
    }
}
void swap (card *c1, card *c2){
   card tempCard = *c1;
   c1 = c2;
   *c2 = tempCard;  
}