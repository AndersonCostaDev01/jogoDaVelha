#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

// Função para inicializar o tabuleiro
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Função para desenhar o tabuleiro
void drawBoard(char board[SIZE][SIZE]) {
    system("clear"); // Limpa a tela no Linux/Mac, use "cls" em Windows
    for (int i = 0; i < SIZE; i++) {
        printf("|");
        for (int j = 0; j < SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("-----\n");
        }
    }
}

// Função para verificar se alguém ganhou
char checkWin(char board[SIZE][SIZE]) {
    // Verifica linhas e colunas
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];
        }
    }

    // Verifica diagonais
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }

    // Verifica se há empate
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return ' '; // Ainda há espaços vazios, jogo não acabou
            }
        }
    }

    return 'D'; // Empate
}

// Função principal do jogo
int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    int currentPlayer = 1; // 1 para jogador X, -1 para jogador O
    int row, col;
    char winner;

    while (1) {
        drawBoard(board);

        if (currentPlayer == 1) {
            printf("Jogador X, digite a linha (0-2): ");
            scanf("%d", &row);
            printf("Jogador X, digite a coluna (0-2): ");
            scanf("%d", &col);
        } else {
            printf("Jogador O, digite a linha (0-2): ");
            scanf("%d", &row);
            printf("Jogador O, digite a coluna (0-2): ");
            scanf("%d", &col);
        }

        // Verifica se a posição está vazia
        if (board[row][col] == ' ') {
            board[row][col] = currentPlayer == 1 ? 'X' : 'O';
        } else {
            printf("Posição já ocupada, tente novamente.\n");
            continue;
        }

        // Verifica se alguém ganhou ou se houve empate
        winner = checkWin(board);
        if (winner != ' ') {
            drawBoard(board);
            if (winner == 'D') {
                printf("Empate!\n");
            } else {
                printf("Jogador %c venceu!\n", winner);
            }
            break;
        }

        // Alterna entre jogadores
        currentPlayer = -currentPlayer;
    }

    return 0;
}
