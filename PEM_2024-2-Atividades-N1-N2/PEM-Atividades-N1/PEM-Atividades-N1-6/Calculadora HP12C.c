/*--------------------------------------------------------
Disciplina: Programaçao Estruturada e Modular
Prof. Carlos Veríssimo                                    
--------------------------------------------------------
Objetivo do Programa: Calculadora HP12C
Data - 20/09/2024
Autor: Júlio César Santana - RA: 2040482312048
Stephanie Caroline Amarante - RA: 2040482222049
--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
 
#define MAX 4 // Define o tamanho da pilha (memórias X, Y, Z, T)
 
// Estrutura para representar a pilha
typedef struct {
    int mem[MAX]; // Armazena as memórias X, Y, Z, T
    int topo;     // Índice do topo da pilha
} Pilha;
 
// Funções de manipulação da pilha
void inicializaPilha(Pilha *p) {
    p->topo = -1; // Inicializa a pilha vazia
}
 
int pilhaVazia(Pilha *p) {
    return (p->topo == -1);
}
 
int pilhaCheia(Pilha *p) {
    return (p->topo == MAX - 1);
}
 
void empilhar(Pilha *p, int valor) {
    if (!pilhaCheia(p)) {
        p->mem[++(p->topo)] = valor;
    } else {
        printf("Pilha cheia! Não é possível empilhar.\n");
    }
}
 
int desempilhar(Pilha *p) {
    if (!pilhaVazia(p)) {
        return p->mem[(p->topo)--];
    } else {
        printf("Pilha vazia! Não é possível desempilhar.\n");
        return -1; // Indicador de erro
    }
}
 
// Função para processar a operação RPN
void processaRPN(Pilha *p, char operador) {
    if (p->topo < 1) {
        printf("Operação inválida: operandos insuficientes.\n");
        return;
    }
    
    int b = desempilhar(p);
    int a = desempilhar(p);
    int resultado;
 
    switch (operador) {
        case '+':
            resultado = a + b;
            break;
        case '-':
            resultado = a - b;
            break;
        case '*':
            resultado = a * b;
            break;
        case '/':
            if (b != 0) {
                resultado = a / b;
            } else {
                printf("Erro: divisão por zero.\n");
                return;
            }
            break;
        default:
            printf("Operador inválido.\n");
            return;
    }
 
    empilhar(p, resultado);
}
 
// Função principal
int main() {
    Pilha pilha;
    inicializaPilha(&pilha);
    
    char entrada[100]; // Buffer para armazenar a entrada RPN
    printf("Digite a expressão RPN (ex: 3 4 + 2 *): ");
    fgets(entrada, sizeof(entrada), stdin); // Leitura da expressão
 
    char *token = strtok(entrada, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            empilhar(&pilha, atoi(token)); // Se for um número, empilha
        } else {
            processaRPN(&pilha, token[0]); // Se for um operador, processa
        }
        token = strtok(NULL, " ");
    }
 
    if (pilha.topo == 0) {
        printf("Resultado: %d\n", pilha.mem[pilha.topo]); // Exibe o resultado final
    } else {
        printf("Expressão inválida.\n");
    }
 
    return 0;
}
