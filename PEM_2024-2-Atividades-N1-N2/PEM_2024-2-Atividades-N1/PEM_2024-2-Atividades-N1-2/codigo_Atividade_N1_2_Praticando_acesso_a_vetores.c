// Stephanie Carolline Amarante - RA2040482222049
#include <stdio.h>
#include <stdlib.h>

#define MAX_NOTAS 5
#define MAX_PROVAS 3

// Função para calcular a soma das notas
float soma_notas(float notas[], int num_notas) {
    float soma = 0.0;
    for (int i = 0; i < num_notas; i++) {
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
        printf("Digite as %d notas, separadas por espaços: ", MAX_NOTAS);

        // Lê a linha inteira de notas
        for (int j = 0; j < MAX_NOTAS; j++) {
            if (scanf("%f", &notas[j]) != 1) {
                fprintf(stderr, "Entrada inválida. Por favor, insira números válidos.\n");
                exit(EXIT_FAILURE);
            }
        }

        // Limpa o buffer de entrada após ler todas as notas
        while (getchar() != '\n');

        // Calcula a soma das notas
        provas[i] = soma_notas(notas, MAX_NOTAS);
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
