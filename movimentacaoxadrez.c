#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

// Inicializa o tabuleiro com peças iniciais simplificadas
void initBoard() {
    memset(board, ' ', sizeof(board));

    // Peças pretas
    board[0][0] = board[0][7] = 'r'; // torres
    board[0][1] = board[0][6] = 'n'; // cavalos
    board[0][2] = board[0][5] = 'b'; // bispos
    board[0][3] = 'q';               // rainha
    board[0][4] = 'k';               // rei
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = 'p'; // peões pretos
    }

    // Peças brancas
    board[7][0] = board[7][7] = 'R'; // torres
    board[7][1] = board[7][6] = 'N'; // cavalos
    board[7][2] = board[7][5] = 'B'; // bispos
    board[7][3] = 'Q';               // rainha
    board[7][4] = 'K';               // rei
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[6][i] = 'P'; // peões brancos
    }
}

// Mostra o tabuleiro no console
void printBoard() {
    printf("   a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Converte notação como "e2" para coordenadas (linha, coluna)
int parseMove(const char *pos, int *row, int *col) {
    if (strlen(pos) != 2) return 0;
    *col = pos[0] - 'a';
    *row = 8 - (pos[1] - '0');
    return (*col >= 0 && *col < 8 && *row >= 0 && *row < 8);
}

// Move uma peça se o movimento for válido (apenas movimento, sem regra de peça)
int movePiece(const char *from, const char *to) {
    int fromRow, fromCol, toRow, toCol;
    if (!parseMove(from, &fromRow, &fromCol) || !parseMove(to, &toRow, &toCol)) {
        printf("Coordenadas inválidas.\n");
        return 0;
    }

    char piece = board[fromRow][fromCol];
    if (piece == ' ') {
        printf("Não há peça em %s.\n", from);
        return 0;
    }

    board[toRow][toCol] = piece;
    board[fromRow][fromCol] = ' ';
    return 1;
}

int main() {
    char from[3], to[3];
    initBoard();

    while (1) {
        printBoard();
        printf("Digite o movimento (ex: e2 e4): ");
        if (scanf("%2s %2s", from, to) != 2) {
            printf("Entrada inválida. Encerrando.\n");
            break;
        }

        if (!movePiece(from, to)) {
            printf("Movimento inválido. Tente novamente.\n");
        }
    }

    return 0;
}
