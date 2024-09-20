/*--------------------------------------------------------
Disciplina: Programaçao Estruturada e Modular
Prof. Carlos Veríssimo                                    
--------------------------------------------------------
Objetivo do Programa: Tabuleiro de Xaderz: Xeque Pastor(Refatorado)
Data - 13/09/2024
Autor: Stephanie Carolline Amarante
--------------------------------------------------------*/
#include <stdio.h>

// Função para exibir o tabuleiro, mostrando o estado atual das peças
void exibirTabuleiro(char tabuleiro[8][8]) {
    printf("Estado atual do tabuleiro:\n");
    for (int linha = 0; linha < 8; linha++) {
        for (int coluna = 0; coluna < 8; coluna++) {
            printf("%c ", tabuleiro[linha][coluna]);  // Exibe cada peça do tabuleiro
        }
        printf("\n");  // Nova linha após cada linha do tabuleiro
    }
    printf("\n");
}

// Função para movimentar uma peça de uma posição para outra no tabuleiro
void moverPeca(char tabuleiro[8][8], int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    // Movimenta a peça para a nova posição
    tabuleiro[linhaDestino][colunaDestino] = tabuleiro[linhaOrigem][colunaOrigem];
    // A posição antiga da peça é agora vazia, representada por '.'
    tabuleiro[linhaOrigem][colunaOrigem] = '.';
    printf("Peça movida de [%d, %d] para [%d, %d]\n", linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);
}

int main() {
    // Inicialização do tabuleiro de xadrez com as peças nas posições padrão
    char tabuleiro[8][8] = {
        {'t', 'c', 'b', 'd', 'r', 'b', 'c', 't'},  // Pretas
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},  // Vazio
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},  // Brancas
        {'T', 'C', 'B', 'D', 'R', 'B', 'C', 'T'}
    };

    // Exibe o tabuleiro inicial
    printf("Tabuleiro inicial:\n");
    exibirTabuleiro(tabuleiro);

    // Jogada 1: Peão branco do Rei (e2) para e4
    moverPeca(tabuleiro, 6, 4, 4, 4);
    exibirTabuleiro(tabuleiro);

    // Jogada 1: Peão preto do Rei (e7) para e5
    moverPeca(tabuleiro, 1, 4, 3, 4);
    exibirTabuleiro(tabuleiro);

    // Jogada 2: Bispo branco do Rei (f1) para c4
    moverPeca(tabuleiro, 7, 5, 4, 2);
    exibirTabuleiro(tabuleiro);

    // Jogada 2: Cavalo preto da Dama (b8) para c6
    moverPeca(tabuleiro, 0, 1, 2, 2);
    exibirTabuleiro(tabuleiro);

    // Jogada 3: Dama branca (d1) para h5
    moverPeca(tabuleiro, 7, 3, 3, 7);
    exibirTabuleiro(tabuleiro);

    // Jogada 3: Cavalo preto do Rei (g8) para f6
    moverPeca(tabuleiro, 0, 6, 2, 5);
    exibirTabuleiro(tabuleiro);

    // Jogada 4: Dama branca captura o Peão preto (h5 captura f7) - Xeque Mate
    moverPeca(tabuleiro, 3, 7, 1, 5);
    exibirTabuleiro(tabuleiro);

    printf("Fim de jogo! Xeque Mate!\n");

    return 0;
}
