// xadrez.c
// Simulação dos movimentos da Torre, Bispo e Rainha no xadrez
// Autor: [Pedro Nottingham]
// Desafio de repetição - Estruturas: for, while, do-while

#include <stdio.h>

int main() {
    // -------------------------------
    // Movimento da TORRE - 5 casas para a direita
    // Usando estrutura FOR
    // -------------------------------
    printf("Movimento da Torre (5 casas para a Direita):\n");
    for (int i = 0; i < 5; i++) {
        printf("Direita\n");
    }

    // -------------------------------
    // Movimento do BISPO - 5 casas na diagonal (cima e direita)
    // Usando estrutura WHILE
    // -------------------------------
    printf("\nMovimento do Bispo (5 casas para Cima e Direita):\n");
    int bispoMov = 0;
    while (bispoMov < 5) {
        printf("Cima Direita\n");
        bispoMov++;
    }

    // -------------------------------
    // Movimento da RAINHA - 8 casas para a esquerda
    // Usando estrutura DO-WHILE
    // -------------------------------
    printf("\nMovimento da Rainha (8 casas para a Esquerda):\n");
    int rainhaMov = 0;
    do {
        printf("Esquerda\n");
        rainhaMov++;
    } while (rainhaMov < 8);

    return 0;
}
