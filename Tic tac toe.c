#include <stdio.h>

int main() {
    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    char player = 'X';
    int move, count = 0;
    int win1 = -1, win2 = -1, win3 = -1; // placeholder as winning line doesn't exist yet

    while (1) {
        // Initializing board setup
        printf("\n %c | %c | %c\n", board[0], board[1], board[2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c\n", board[3], board[4], board[5]);
        printf("---|---|---\n");
        printf(" %c | %c | %c\n", board[6], board[7], board[8]);

        // User input
        printf("\nPlayer %c, enter your move (1-9): ", player);
        scanf("%d", &move);

        // Check validity
        if (move < 1 || move > 9 || board[move-1]=='X' || board[move-1]=='O') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Make move
        board[move-1] = player;
        count++;

        // Check all winning possibilities
        int won = 0;
        int wins[8][3] = {
            {0,1,2},{3,4,5},{6,7,8},   // rows
            {0,3,6},{1,4,7},{2,5,8},   // columns
            {0,4,8},{2,4,6}            // diag
        };

        for (int i=0; i<8; i++) {
            if (board[wins[i][0]] == player && board[wins[i][1]] == player && board[wins[i][2]] == player) {
                win1 = wins[i][0];
                win2 = wins[i][1];
                win3 = wins[i][2];
                won = 1;
                break;
            }
        }

        if (won) {
            // This block will make last move as player symbol before anyone wins
            board[win1] = player;
            board[win2] = player;
            board[win3] = player;

            // Print final board with winning cells updated
            printf("\n %c | %c | %c\n", board[0], board[1], board[2]);
            printf("---|---|---\n");
            printf(" %c | %c | %c\n", board[3], board[4], board[5]);
            printf("---|---|---\n");
            printf(" %c | %c | %c\n", board[6], board[7], board[8]);

            printf("\nPlayer %c wins!\n", player);
            break;
        }

        // Check for draw
        if (count == 9) {
            printf("\nIt's a draw!\n");
            break;
        }

        // Alternating players
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
