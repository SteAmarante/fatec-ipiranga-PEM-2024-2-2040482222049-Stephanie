/*--------------------------------------------------------
Disciplina: Programaçao Estruturada e Modular
Prof. Carlos Veríssimo                                    
--------------------------------------------------------
Objetivo do Programa: Tabuleiro de Xaderz: Xeque Pastor(Refatorado)
Data - 20/09/2024
Autor: Stephanie Carolline Amarante
--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 4 // Define o tamanho da pilha (memórias X, Y, Z, T)

// Estrutura da pilha que armazena as memórias X, Y, Z, T
typedef struct {
    int mem[MAX]; // Armazena os valores
    int topo;     // Índice do topo da pilha
} Pilha;

// Função para inicializar a pilha
void inicializaPilha(Pilha *p) {
    p->topo = -1; // A pilha começa vazia
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha *p) {
    return (p->topo == -1);
}

// Função para verificar se a pilha está cheia
int pilhaCheia(Pilha *p) {
    return (p->topo == MAX - 1);
}

// Função para empilhar um valor
void empilhar(Pilha *p, int valor) {
    if (!pilhaCheia(p)) {
        p->mem[++(p->topo)] = valor;
    } else {
        printf("Erro: Pilha cheia!\n");
    }
}

// Função para desempilhar um valor
int desempilhar(Pilha *p) {
    if (!pilhaVazia(p)) {
        return p->mem[(p->topo)--];
    } else {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
}

// Função para processar uma operação RPN
void processaOperacao(Pilha *p, char operador) {
    if (p->topo < 1) { // Verifica se há operandos suficientes
        printf("Erro: operandos insuficientes!\n");
        return;
    }

    int b = desempilhar(p); // Retira o último operando
    int a = desempilhar(p); // Retira o penúltimo operando
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
                printf("Erro: divisão por zero!\n");
                return;
            }
            break;
        default:
            printf("Erro: operador inválido!\n");
            return;
    }

    empilhar(p, resultado); // Empilha o resultado de volta
}

// Função para verificar se o usuário deseja realizar uma nova operação
int novaOperacao() {
    char escolha;
    printf("Deseja realizar uma nova operação? (s/n): ");
    scanf(" %c", &escolha);
    return (escolha == 's' || escolha == 'S');
}

// Função principal
int main() {
    Pilha pilha;
    char entrada[100]; // Buffer para armazenar a entrada RPN

    do {
        inicializaPilha(&pilha);

        printf("Digite a expressão RPN (ex: 3 4 + 2 *): ");
        scanf(" %[^\n]", entrada); // Lê a expressão

        char *token = strtok(entrada, " ");
        while (token != NULL) {
            if (isdigit(token[0])) {
                empilhar(&pilha, atoi(token)); // Se for número, empilha
            } else {
                processaOperacao(&pilha, token[0]); // Se for operador, processa
            }
            token = strtok(NULL, " ");
        }

        if (pilha.topo == 0) {
            printf("Resultado: %d\n", pilha.mem[pilha.topo]); // Exibe o resultado final
        } else {
            printf("Erro: Expressão inválida!\n");
        }

    } while (novaOperacao());

    printf("Obrigado por usar nossa Calculadora Fatec-HP12c!\n");
    return 0;
}
