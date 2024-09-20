/* Disciplina: Programaçao Estruturada e Modular
Prof. Carlos Veríssimo                                    
--------------------------------------------------------
Objetivo do Programa: Xeque Pastor    
Data - 06/09/2024                                                
Autores: Stephanie Carolline Amarante - RA 2040482222049*/

#include <stdio.h>

// Estrutura para representar uma peça no tabuleiro
typedef struct {
    char tipo; // Tipo de peça (P, B, C, D, R, K)
    char cor; // Cor da peça (B ou P)
    int linha; // Linha da peça no tabuleiro
    int coluna; // Coluna da peça no tabuleiro
} Peca;

// Função para imprimir o tabuleiro
void imprimirTabuleiro(Peca tabuleiro[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tabuleiro[i][j].tipo == ' ') {
                printf("  ");
            } else {
                printf("%c%c ", tabuleiro[i][j].tipo, tabuleiro[i][j].cor);
            }
        }
        printf("\n");
    }
}

// Função para mover uma peça no tabuleiro
void moverPeca(Peca tabuleiro[8][8], int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    Peca peca = tabuleiro[linhaOrigem][colunaOrigem];
    tabuleiro[linhaOrigem][colunaOrigem].tipo = ' ';
    tabuleiro[linhaDestino][colunaDestino] = peca;
}

int main() {
    // Inicializar o tabuleiro
    Peca tabuleiro[8][8] = {
        // ...
        // Inicializar as peças no tabuleiro
        // ...
    };

    // Jogada #1
    printf("Jogada #1:\n");
    printf("Brancas jogam Peão do Rei (e1)\n");
    moverPeca(tabuleiro, 6, 4, 4, 4);
    imprimirTabuleiro(tabuleiro);
    printf("Pretas jogam Peão do Rei (e5)\n");
    moverPeca(tabuleiro, 1, 4, 3, 4);
    imprimirTabuleiro(tabuleiro);

    // Jogada #2
    printf("Jogada #2:\n");
    printf("Brancas jogam Bispo do rei (Bc4)\n");
    moverPeca(tabuleiro, 7, 2, 5, 3);
    imprimirTabuleiro(tabuleiro);
    printf("Pretas jogam Cavalo da Dama (Cc6)\n");
    moverPeca(tabuleiro, 1, 5, 2, 6);
    imprimirTabuleiro(tabuleiro);

    // Jogada #3
    printf("Jogada #3:\n");
    printf("Brancas jogam Dama (Dh5)\n");
    moverPeca(tabuleiro, 7, 3, 4, 5);
    imprimirTabuleiro(tabuleiro);
    printf("Pretas jogam Cavalo do Rei (Cf6)\n");
    moverPeca(tabuleiro, 1, 5, 2, 5);
    imprimirTabuleiro(tabuleiro);

    // Jogada #4: Xeque Mate
    printf("Jogada #4: Xeque Mate\n");
    printf("Brancas capturam Peão do Rei e dão Xeque Mate: Dxf7#\n");
    moverPeca(tabuleiro, 4, 5, 6, 6);
    imprimirTabuleiro(tabuleiro);

    return 0;
}
