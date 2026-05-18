#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHA 3
#define COLUNA 3


int tabuleiro[3][3];

int desenhaTabuleiro(){
    for(int l = 0; l < LINHA; l++){
        for(int c = 0; c < COLUNA; c++){
            tabuleiro[l][c] = 0;
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n");
    }
    return 0;
}

int random(){
    int aleatorio[2];
    aleatorio[0] = rand() % 3;
    aleatorio[1] = rand() % 3;
    for(int i = 0; i < 2; i++){
        printf("%d ", aleatorio[i]);
    }
    printf("\n");
    return 0;
}

int main() {
    srand(time(NULL));
    desenhaTabuleiro();
    int win = 0;
    for(int i = 0; i < 5; i++){
        random();
    }
    

    return 0;
}