/* Disciplina: Programaçao Estruturada e Modular
Prof. Carlos Veríssimo                                    
--------------------------------------------------------
Objetivo do Programa: Comparação entre o Bubble Sort e o Insertion Sort 
Data - 06/10/2024                                                
Autores: Julio Cesar Santana - RA 2040482312048
         Stephanie Carolline Amarante - RA 2040482222049
--------------------------------------------------------*/
//Bubble Sort com Medições:

#include <stdio.h>
#include <time.h>

void bubbleSort(int arr[], int n, int *trocas, int *ciclos) {
    int i, j, temp;
    *trocas = 0;
    *ciclos = 0;

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            (*ciclos)++;
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*trocas)++;
            }
        }
    }
}

void insertionSort(int arr[], int n, int *trocas, int *ciclos) {
    int i, elemento, j;
    *trocas = 0;
    *ciclos = 0;

    for (i = 1; i < n; i++) {
        elemento = arr[i];
        j = i - 1;

        (*ciclos)++;
        while (j >= 0 && arr[j] > elemento) {
            arr[j + 1] = arr[j];
            j--;
            (*trocas)++;
        }
        arr[j + 1] = elemento;
    }
}

void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arrBubble[] = {5, 3, 8, 4, 2, 115, 113, 118, 114, 112, 125, 123, 128, 124, 122, 35, 33, 38, 34, 32, 45, 43, 48, 44, 42, 55, 53, 58, 54, 52, 65, 63, 68, 64, 62, 75, 73, 78, 74, 72, 85, 83, 88, 84, 82, 95, 93, 98, 94, 92, 15, 13, 18, 14, 12, 25, 23, 28, 24, 22};
    int arrInsertion[] = {5, 3, 8, 4, 2, 115, 113, 118, 114, 112, 125, 123, 128, 124, 122, 35, 33, 38, 34, 32, 45, 43, 48, 44, 42, 55, 53, 58, 54, 52, 65, 63, 68, 64, 62, 75, 73, 78, 74, 72, 85, 83, 88, 84, 82, 95, 93, 98, 94, 92, 15, 13, 18, 14, 12, 25, 23, 28, 24, 22};
    int nBubble = sizeof(arrBubble) / sizeof(arrBubble[0]);
    int nInsertion = sizeof(arrInsertion) / sizeof(arrInsertion[0]);
    int trocas, ciclos;

    clock_t start, end;
    double cpu_time_used;

    // Medição do Bubble Sort
    start = clock();
    bubbleSort(arrBubble, nBubble, &trocas, &ciclos);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Array ordenado (Bubble Sort): ");
    imprimirArray(arrBubble, nBubble);
    printf("Tempo de execução (Bubble Sort): %f segundos\n", cpu_time_used);
    printf("Número de trocas (Bubble Sort): %d\n", trocas);
    printf("Número de ciclos (Bubble Sort): %d\n\n", ciclos);

    // Medição do Insertion Sort
    start = clock();
    insertionSort(arrInsertion, nInsertion, &trocas, &ciclos);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Array ordenado (Insertion Sort): ");
    imprimirArray(arrInsertion, nInsertion);
    printf("Tempo de execução (Insertion Sort): %f segundos\n", cpu_time_used);
    printf("Número de trocas (Insertion Sort): %d\n", trocas);
    printf("Número de ciclos (Insertion Sort): %d\n", ciclos);

    return 0;
}
