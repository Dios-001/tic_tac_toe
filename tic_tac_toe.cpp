#include <stdio.h>
#include <stdlib.h>


void initializeBoard(char board[3][3]) {
    int i, j, count = 1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = count + '0'; 
            count++;
        }
    }
}
void displayBoard(char board[3][3]) {
    printf("\nTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n\n");
}
int checkWin(char board[3][3], char symbol) {
    int i, j;
    for (i = 0; i < 3; i++) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return 1; // Win
        }
    }

    
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return 1; // Win
    }

    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0; 
            }
        }
    }
    return -1; 
}

int main() {
    char board[3][3];
    int choice, currentPlayer = 1;
    char symbol;
    initializeBoard(board);
    do {
        displayBoard(board); 
        currentPlayer = (currentPlayer % 2) ? 1 : 2;
        symbol = (currentPlayer == 1) ? 'X' : 'O';
        printf("Player %d, enter a number (1-9): ", currentPlayer);
        scanf("%d", &choice);
  if (choice < 1 || choice > 9 || board[(choice - 1) / 3][(choice - 1) % 3] == 'X' ||
            board[(choice - 1) / 3][(choice - 1) % 3] == 'O') {
            printf("Invalid move. Please try again.\n");
            continue;
        }board[(choice - 1) / 3][(choice - 1) % 3] = symbol;
        int result = checkWin(board, symbol);
        if (result == 1) {
            displayBoard(board);
            printf("Player %d wins!\n", currentPlayer);
            break;
        } else if (result == -1) {
            displayBoard(board);
            printf("It's a draw!\n");
            break;
        }

        currentPlayer++;
    } while (1);

    return 0;
}
