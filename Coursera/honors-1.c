#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52

// Enums of card attributes.
enum pip{Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
enum color{Red, Black};
enum suit{Heart, Diamond, Club, Spade};

// Struct of a card
typedef struct card{
    int pip;
    enum suit suit;
    enum color color;
}card;

void print_deck(card deck[]);
//void shuffle_deck(card deck[]);

int main()
{
    card deck[DECK_SIZE];

    //Initialize the deck;
    for (int i = 0; i < DECK_SIZE; i++)
    {
        deck[i].pip = i % 13;
        deck[i].suit = i % 4;
        if (deck[i].suit == Heart || deck[i].suit == Diamond) deck[i].color = Red; 
        else deck[i].color = Black; 
    }

    print_deck(deck);
}

// Prints all the cards in the deck. 
void print_deck(card deck[])
{
    // Arrays for printing.
    char *color[] = {"Red", "Black"};
    char *suit[] = {"Heart", "Diamond", "Club", "Spade"};
    char *pip[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
 
    // Prints the deck
    puts("DECK:");
    for (int i = 0; i < DECK_SIZE; i++)
        printf("%i\t %s\t\t%s\t\t%s\n", i+1, pip[deck[i].pip], suit[deck[i].suit], color[deck[i].color]);
}

// Shuffles the deck
void shuffle_deck(card deck[])
{
    for (int i = DECK_SIZE - 1; i > 0; i--)
        
}