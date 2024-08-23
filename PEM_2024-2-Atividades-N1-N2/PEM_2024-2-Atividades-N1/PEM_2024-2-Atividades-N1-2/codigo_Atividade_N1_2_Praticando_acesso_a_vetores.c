//Stephanie Carolline Amarante - RA2040482222049
// Inclui as bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>

// Define constantes para o tamanho máximo de notas e provas
#define MAX_NOTAS 5
#define MAX_PROVAS 3

// Função para calcular a soma das notas
float soma_notas(float notas[]) {
    float soma = 0.0;
    for (int i = 0; i < MAX_NOTAS; i++) {
        soma += notas[i];
    }
    return soma;
}

int main() {
    float notas[MAX_NOTAS];
    float provas[MAX_PROVAS];

    // Lê as notas de cada prova
    for (int i = 0; i < MAX_PROVAS; i++) {
        printf("Prova %d:\n", i + 1);
        for (int j = 0; j < MAX_NOTAS; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &notas[j]);
        }
        provas[i] = soma_notas(notas);
        printf("Soma das notas: %.2f\n", provas[i]);
    }

    // Calcula a nota final
    float nota_final = 0.0;
    for (int i = 0; i < MAX_PROVAS; i++) {
        nota_final += provas[i];
    }
    printf("Nota final: %.2f\n", nota_final);

    return 0;
}
