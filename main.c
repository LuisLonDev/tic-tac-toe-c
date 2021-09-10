#include <stdio.h>
#define MAX 20

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkwin();
void board(int player1Score, int player2Score);

int main()
{
    int player = 1, i, j, out = 1, numberOfGames, choice;
    int player1Score = 0;
    int player2Score = 0;
    char mark;
    char player1[20];
    char player2[20];

    do
    {
        printf("please provide the number of games you want to play? ===> 1, 3 ,5\n");
        scanf("%d", &numberOfGames);

        if (numberOfGames != 1 && numberOfGames != 3 && numberOfGames != 5)
        {
            printf("invalid number\n");
        }
        else
        {
            out = -1;
        }
    } while (out == 1);

    for (int k = 0; k < numberOfGames; k++)
    {
        do
        {
            board(player1Score, player2Score);
            player = (player % 2) ? 1 : 2;

            printf("Player %d, enter a number:  ", player);
            scanf("%d", &choice);

            mark = (player == 1) ? 'X' : 'O';

            if (choice == 1 && square[1] == '1')
                square[1] = mark;

            else if (choice == 2 && square[2] == '2')
                square[2] = mark;

            else if (choice == 3 && square[3] == '3')
                square[3] = mark;

            else if (choice == 4 && square[4] == '4')
                square[4] = mark;

            else if (choice == 5 && square[5] == '5')
                square[5] = mark;

            else if (choice == 6 && square[6] == '6')
                square[6] = mark;

            else if (choice == 7 && square[7] == '7')
                square[7] = mark;

            else if (choice == 8 && square[8] == '8')
                square[8] = mark;

            else if (choice == 9 && square[9] == '9')
                square[9] = mark;

            else
            {
                printf("Invalid move ");

                player--;
                getchar();
            }
            i = checkwin();

            player++;
        } while (i == -1);

        board(player1Score, player2Score);

        if (i == 1)
        {
            printf("Player %d wins!! \n", --player);
            player1Score++;
            square[0] = 'o';
            square[1] = '1';
            square[2] = '2';
            square[3] = '3';
            square[4] = '4';
            square[5] = '5';
            square[6] = '6';
            square[7] = '7';
            square[8] = '8';
            square[9] = '9';
        }
        else
        {
            printf("It's a Tie!! \n");
            square[0] = 'o';
            square[1] = '1';
            square[2] = '2';
            square[3] = '3';
            square[4] = '4';
            square[5] = '5';
            square[6] = '6';
            square[7] = '7';
            square[8] = '8';
            square[9] = '9';
        }

        getchar();
    }

    board(player1Score, player2Score);

    return 0;
}

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}

void board(int player1Score, int player2Score)
{
    system("clear");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X): %d -  Player 2 (O): %d \n\n\n", player1Score, player2Score);

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}
