#include <stdio.h>
#include <stdlib.h>

// Função para comparar valores para a função de ordenação
int compare(const void *a, const void *b) {
    if (*(float*)a < *(float*)b) return -1;
    else if (*(float*)a > *(float*)b) return 1;
    else return 0;
}

// Função para calcular a nota final de um candidato
float calcular_nota_final(float candidatos[][10], int num_tests[], int num_candidatos) {
    float nota_final_candidato = 0;
    
    for (int i = 0; i < num_candidatos; i++) {
        float nota_total = 0;

        for (int j = 0; j < num_tests[i]; j++) {
            int n = num_tests[i];

            if (n > 2) {
                // Ordenar as notas
                qsort(candidatos[j], n, sizeof(float), compare);

                // Somar as notas excluindo a maior e a menor
                float nota_final = 0;
                for (int k = 1; k < n - 1; k++) {
                    nota_final += candidatos[j][k];
                }

                nota_total += nota_final;
                printf("Nota final do teste = %.1f\n", nota_final);
            }
        }

        printf("Nota final do candidato = %.1f\n", nota_total);
        nota_final_candidato += nota_total;
    }
    
    return nota_final_candidato;
}

int main() {
    // Exemplo de entrada
    float candidatos[5][10] = {
        {10.0, 5.0, 7.0, 3.0},
        {5.0, 3.0, 8.0, 9.0, 7.0},
        {7.0, 5.0, 5.0, 8.0},
        {3.0, 4.0, 7.0, 9.0, 8.0, 10.0},
        {8.0, 4.0, 5.0, 10.0, 7.0}
    };
    int num_tests[5] = {4, 5, 4, 6, 5};  // Número de notas em cada teste
    int num_candidatos = 5;

    float resultado = calcular_nota_final(candidatos, num_tests, num_candidatos);
    printf("Nota final do candidato = %.1f\n", resultado);

    return 0;
}
