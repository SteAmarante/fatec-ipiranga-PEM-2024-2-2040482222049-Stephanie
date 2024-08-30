/* Disciplina: Programaçao Estruturada e Modular
Prof. Carlos Veríssimo                                    
--------------------------------------------------------
Objetivo do Programa: tabuleiro de xadrez      
Data - 27/08/2024                                                
Autores: Julio Cesar Santana - RA 2040482312048 e Stephanie Carolline Amarante - RA 2040482222049*/

#include <stdio.h>

#define TAMANHO_TABULEIRO 8

// Função para inicializar o tabuleiro com peças
void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int i, j;

    // Inicializar casas vazias com 'X'
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 'X';
        }
    }

    // Posicionar peças brancas
    tabuleiro[7][0] = 'T'; // Torre branca à esquerda
    tabuleiro[7][1] = 'C'; // Cavalo branco à esquerda
    tabuleiro[7][2] = 'B'; // Bispo branco à esquerda
    tabuleiro[7][3] = 'D'; // Rainha branca
    tabuleiro[7][4] = 'R'; // Rei branco
    tabuleiro[7][5] = 'B'; // Bispo branco à direita
    tabuleiro[7][6] = 'C'; // Cavalo branco à direita
    tabuleiro[7][7] = 'T'; // Torre branca à direita

    for (j = 0; j < TAMANHO_TABULEIRO; j++) {
        tabuleiro[6][j] = 'P'; // Peões brancos
    }

    // Posicionar peças pretas
    tabuleiro[0][0] = 't'; // Torre preta à esquerda
    tabuleiro[0][1] = 'c'; // Cavalo preto à esquerda
    tabuleiro[0][2] = 'b'; // Bispo preto à esquerda
    tabuleiro[0][3] = 'd'; // Rainha preta
    tabuleiro[0][4] = 'r'; // Rei preto
    tabuleiro[0][5] = 'b'; // Bispo preto à direita
    tabuleiro[0][6] = 'c'; // Cavalo preto à direita
    tabuleiro[0][7] = 't'; // Torre preta à direita

    for (j = 0; j < TAMANHO_TABULEIRO; j++) {
        tabuleiro[1][j] = 'p'; // Peões pretos
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int i, j;
    printf("  a b c d e f g h\n");
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", TAMANHO_TABULEIRO - i);
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("%d\n", TAMANHO_TABULEIRO - i);
    }
    printf("  a b c d e f g h\n");
}

int main() {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializarTabuleiro(tabuleiro);
    exibirTabuleiro(tabuleiro);

    return 0;
}