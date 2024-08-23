//Stephanie Carolline Amarante - RA2040482222049
// Inclui as bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>

// Define constantes para o tamanho máximo de notas e provas
#define MAX_NOTAS 100
#define MAX_PROVAS 5

// Função para ordenar as notas em ordem crescente
void ordena_notas(float *notas, int n) {
    // Variáveis para armazenar temporariamente as notas
    int i, j;
    float temp;

    // Loop para ordenar as notas
    for (i = 0; i < n; i++) {
        // Loop para comparar as notas
        for (j = i + 1; j < n; j++) {
            // Se a nota atual for maior que a nota seguinte, troca-as
            if (notas[i] > notas[j]) {
                temp = notas[i];
                notas[i] = notas[j];
                notas[j] = temp;
            }
        }
    }
}

// Função para calcular a soma das notas, excluindo a maior e a menor
float calcula_soma_notas(float *notas, int n) {
    // Variável para armazenar a soma das notas
    float soma = 0.0;

    // Loop para somar as notas, excluindo a maior e a menor
    for (int i = 1; i < n - 1; i++) {
        soma += notas[i];
    }

    // Retorna a soma das notas
    return soma;
}

// Função principal
int main() {
    // Variáveis para armazenar a quantidade de notas e as notas em si
    int n, i, j;
    float notas[MAX_NOTAS];

    // Variável para armazenar as somas das notas de cada prova
    float provas[MAX_PROVAS];

    // Variável para armazenar a nota final do candidato
    float nota_final = 0.0;

    // Loop para ler as notas de cada prova
    while (scanf("%d", &n) != EOF) {
        // Se a quantidade de notas for 0, sai do loop
        if (n == 0) break;

        // Loop para ler as notas de cada prova
        for (i = 0; i < n; i++) {
            // Lê a nota e armazena no vetor notas
            scanf("%f", &notas[i]);
        }

        // Ordena as notas em ordem crescente
        ordena_notas(notas, n);

        // Calcula a soma das notas, excluindo a maior e a menor
        provas[j] = calcula_soma_notas(notas, n);

        // Incrementa o índice para a próxima prova
        j++;

        // Imprime a soma das notas da prova atual
        printf("Nota prova %d = %.0f\n", j, provas[j - 1]);
    }

    // Loop para calcular a nota final do candidato
    for (i = 0; i < j; i++) {
        // Soma as somas das notas de cada prova
        nota_final += provas[i];
    }

    // Imprime a nota final do candidato
    printf("Nota final do candidato = %.0f\n", nota_final);

    // Retorna 0 para indicar que o programa terminou corretamente
    return 0;
}