/* Disciplina: Programaçao Estruturada e Modular
Prof. Carlos Veríssimo                                    
--------------------------------------------------------
Objetivo do Programa: Quick Sort 
Data - 06/10/2024                                                
Autores: Julio Cesar Santana - RA 2040482312048
         Stephanie Carolline Amarante - RA 2040482222049
--------------------------------------------------------*/
#include <stdio.h>

// Função para trocar os elementos
void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para particionar o array
int particao(int arr[], int limInferior, int limSup) {
    int pivo = arr[limSup];
    int ind = limInferior - 1;

    for (int j = limInferior; j < limSup; j++) {
        if (arr[j] <= pivo) {
            ind++;
            troca(&arr[ind], &arr[j]);
        }
    }
    troca(&arr[ind + 1], &arr[limSup]);
    return ind + 1;
}

// Função principal do Quicksort
void quickSort(int arr[], int limInferior, int limSup) {
    if (limInferior < limSup) {
        int indParticao = particao(arr, limInferior, limSup);

        // Recursão para ordenar as sublistas
        quickSort(arr, limInferior, indParticao - 1);
        quickSort(arr, indParticao + 1, limSup);
    }
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal
int main() {
    int arr[] = {100, 70, 90, 90, 10, 40, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array original: \n");
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    printf("Array ordenado: \n");
    printArray(arr, n);
    
    return 0;
}
