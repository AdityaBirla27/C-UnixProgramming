#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4  //As we have 4 suits(Spades, Hearts, Clubs, Diamonds)-> Global variables
#define FACES 13 //As we have 13 face cards-> Global variables
#define CARDS 52 //Total of 52 cards-> Global variables

void shuffle(unsigned int deck[][FACES]);//Prototype
void deal(unsigned int deck[][FACES], unsigned int hand[][2], char *suit[], char *face[]);//Prototype
void pair(unsigned int hand[][2], char *suit[], char *face[]);//Prototype
void three_of_kind(unsigned int hand[][2], char *suit[], char *face[]);//Prototype
void four_of_kind(unsigned int hand[][2], char *suit[], char *face[]);//Prototype
void flush(unsigned int hand[][2], char *suit[], char *face[]);//Prototype
int main(){
    char *suit[SUITS] = { "Spades", "Hearts", "Clubs", "Diamonds" };
    char *face[FACES] = { "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    unsigned int deck[SUITS][FACES]; //represents deck of cards
    unsigned int hand[5][2]; //represents hand
    size_t row, column; 
    for (row = 0; row < SUITS; ++row){ //for rows of deck
        for (column = 0; column < FACES; ++column) //for columns of deck for current row
        {
            deck[row][column] = 0;
        }
    }
    srand(time(0)); // seed random number generator
    shuffle(deck);
    deal(deck, hand, suit, face);//Deal cards
    four_of_kind(hand, suit, face);//Check for four of kinds
    three_of_kind(hand, suit, face);//Check for three of kinds
    flush(hand, suit, face);//Check for flush
    pair(hand, suit, face);//Check for pairs
}
void shuffle(unsigned int deck[][FACES]){
    size_t row;
    size_t column;
    unsigned int card;
    // for each of the 52 cards, choose a slot of the deck randomly
    for (card = 1; card <= CARDS; ++card){
        do // choose a new random location until unoccupied slot is found
        {
            row = rand() % SUITS; // randomly select row
            column = rand() % FACES; //randomly select column
        } while (deck[row][column] != 0); //end do ... while
        deck[row][column] = card;
    }
}
void deal(unsigned int deck[][FACES], unsigned int hand[][2], char *suit[], char *face[]){
    unsigned int r = 0; //counter for position in the hand
    size_t card, row, column; //loop counters
    puts("The hand is:\n");
    //loop to distribute cards
    for (card = 1; card < 6; ++card)
        for (row = 0; row < SUITS; ++row)
        for (column = 0; column < FACES; ++column)
            if (deck[row][column] == card){
            hand[r][0] = row;
            hand[r][1] = column;
            printf("%5s of %-8s\n", face[column], suit[row]);
            ++r;
    }
    puts("\n");
}

void pair(unsigned int hand[][2], char *suit[], char *face[]){
    //counter that records how many cards of each rank are in the hand
    unsigned int counter[FACES] = { 0 };
    size_t r, p; // loop counters
    //record how many cards of each rank are in the hand
    for (r = 0; r < 5; ++r)
        ++counter[hand[r][1]];
    for (p = 0; p < FACES; ++p)
        if (counter[p] == 2)
            printf("Pair: %ss.\n", face[p]);
}
void three_of_kind(unsigned int hand[][2], char *suit[], char *face[]){
    unsigned int counter[FACES] = { 0 };
    size_t r, t; // loop counters
    for (r = 0; r < 5; ++r)
        ++counter[hand[r][1]];
    for (t = 0; t < FACES; ++t)
        if (counter[t] == 3)
            printf("Three of a Kind: %ss.\n", face[t]);
} 

void four_of_kind(unsigned int hand[][2], char *suit[], char *face[]){
    unsigned int counter[FACES] = { 0 };
    size_t r, k; // loop counters
    for (r = 0; r < 5; ++r)
        ++counter[hand[r][1]];
    for (k = 0; k < FACES; ++k)
        if (counter[k] == 4)
            printf("Four of a kind: %ss.\n", face[k]);
}

void flush(unsigned int hand[][2], char *suit[], char *face[]){
    //counter that records how many cards of each suit are in a hand
    unsigned int count[SUITS] = { 0 };
    size_t r, f; // loop counters
    //record how many cards of each suit are in the hand
    for (r = 0; r < 5; ++r)
        ++count[hand[r][0]];
    for (f = 0; f < SUITS; ++f)
        if (count[f] == 5)
            printf("Flush: %ss.\n", suit[f]);
}
