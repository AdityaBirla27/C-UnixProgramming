#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status { CONTINUE, WON, LOST};
int rolls;           // Count number of rolls
int games_played = 1000;   // Total number of games
int count_won = 0;         // num of games won
int count_lose = 0;        // num of games lost
int num_won[20] = {0};   // num_won[i] = no. of games won after i+1 rolls
int num_lose[20] = {0}; // num_lose[i] = no. of games lost after i+1 rolls
int game_len = 0;     // Sum of length of all games

int rollDice(void); //Prototype
void print_result(void);//Prototype

int main() {
    srand(time(0));
    int trial = 1;
    while(trial <= games_played) { // Play numTrial no. of games
        ++trial;
        rolls = 0;           // new game, so reset rolls to 0

        int myPoint;
        enum Status gameStatus;
        int sum = rollDice();

        switch(sum) {
            //Player wins when sum of 7 or 11 is rolled on dices
            case 7:
                gameStatus = WON;
                break;
            case 11:
                gameStatus = WON;
                break;
            //Player loses when sum of 2, 3 or 12 is rolled on dices
            case 2:
                gameStatus = LOST;
                break;
            case 3:
                gameStatus = LOST;
                break;
            case 12:
                gameStatus = LOST;
                break;
          
            default:
                gameStatus = CONTINUE;
                myPoint = sum;
                break;
        }

        while(gameStatus == CONTINUE) {
            sum = rollDice(); // sum of rolled dices

            if(sum == myPoint) {
                gameStatus = WON;
            }
            else {
                if(sum == 7) {
                    gameStatus = LOST;
                }
            }
        }

        if(gameStatus == WON) {
            ++count_won;                   // another game won
            if(rolls <= 20)
                ++num_won[rolls-1];   // if game win in <= 20 rolls
        }
        else {
            ++ count_lose;                 // another game lost
            if(rolls <= 20)
                ++num_lose[rolls-1]; // if game is lost in <= 20 rolls
        }
        game_len += rolls;         // add the length of this game to the total
    }
    print_result();
}

int rollDice(void) {
    ++rolls;                     // die rolled
    int die1 = 1 + (rand() % 6);
    int die2 = 1 + (rand() % 6);

    return die1 + die2;// sum of rolls
}

void print_result(void) {
    printf("\na.\n");
    printf("Number of roles \tNumebr of games won\n");
    for(int i = 0; i < 20; ++i) {
        printf("\t%d \t \t \t %d\n", i+1, num_won[i]);
    }

    // PART b.
    printf("\nb.\n");
    printf("Number of roles \tNumebr of games lost\n");
    for(int i = 0; i < 20; ++i) {
        printf("\t%d\t\t\t%d\n", i+1, num_lose[i]);
    }

    // PART c.
    printf("\nc.\n");
    printf("Chances of winning: %.2f %%\n", (double)count_won/games_played * 100);

    // PART d.
    printf("\nd.\n");
    printf("Average length of a games: \t%d\n", game_len/games_played);

    // PART e.
    printf("\ne.\n");
    printf("Number of roles \tChances of winning\n");
    for(int i = 0; i < 20; ++i) {
        printf("\t%d\t\t\t%.2f %%\n", i+1, (float)num_won[i]/games_played * 100);
    }
}