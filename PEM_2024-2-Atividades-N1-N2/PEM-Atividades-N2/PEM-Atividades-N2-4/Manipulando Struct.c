/* Disciplina: Programaçao Estruturada e Modular
Prof. Carlos Veríssimo                                    
--------------------------------------------------------
Objetivo do Programa: Loja de Produtos eletrônicos 
Data - 21/10/2024                                                
Autores: Julio Cesar Santana - RA 2040482312048
         Stephanie Carolline Amarante - RA 2040482222049
--------------------------------------------------------*/


#include <stdio.h>
#include <string.h>

// Definição da struct Produto
typedef struct {
    int id;
    char nome[50];
    char descricao[100];
    float preco;
    int quantidade;
} Produto;

void inserirProduto(Produto *produtos, int *numProdutos);
void listarProdutos(Produto *produtos, int numProdutos);
void ordenarProdutos(Produto *produtos, int numProdutos);
void comprarProduto(Produto *produtos, int numProdutos);

int main() {
    Produto produtos[100];
    int numProdutos = 0;
    int opcao;

    do {
        printf("\nLoja de Produtos Eletrônicos\n");
        printf("1. Inserir produto\n");
        printf("2. Listar produtos\n");
        printf("3. Comprar produto\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                inserirProduto(produtos, &numProdutos);
                break;
            case 2:
                listarProdutos(produtos, numProdutos);
                break;
            case 3:
                comprarProduto(produtos, numProdutos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}

void inserirProduto(Produto *produtos, int *numProdutos) {
    printf("\nInserir novo produto:\n");
    printf("ID: ");
    scanf("%d", &produtos[*numProdutos].id);
    printf("Nome: ");
    scanf(" %[^\n]", produtos[*numProdutos].nome);
    printf("Descrição: ");
    scanf(" %[^\n]", produtos[*numProdutos].descricao);
    printf("Preço unitário: ");
    scanf("%f", &produtos[*numProdutos].preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &produtos[*numProdutos].quantidade);

    (*numProdutos)++;
    printf("Produto inserido com sucesso!\n");
}

void listarProdutos(Produto *produtos, int numProdutos) {
    if (numProdutos == 0) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    ordenarProdutos(produtos, numProdutos);

    printf("\nLista de produtos:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("ID: %d\nNome: %s\nDescrição: %s\nPreço: R$ %.2f\nQuantidade: %d\n\n",
               produtos[i].id, produtos[i].nome, produtos[i].descricao,
               produtos[i].preco, produtos[i].quantidade);
    }
}

void ordenarProdutos(Produto *produtos, int numProdutos) {
    Produto temp;
    for (int i = 0; i < numProdutos - 1; i++) {
        for (int j = 0; j < numProdutos - i - 1; j++) {
            if (strcmp(produtos[j].nome, produtos[j + 1].nome) > 0) {
                temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}

void comprarProduto(Produto *produtos, int numProdutos) {
    int id, quantidade;
    int encontrado = 0;

    printf("\nComprar produto\n");
    printf("Informe o código do produto: ");
    scanf("%d", &id);

    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].id == id) {
            encontrado = 1;
            printf("Produto encontrado: %s\n", produtos[i].nome);
            printf("Quantidade disponível: %d\n", produtos[i].quantidade);
            printf("Informe a quantidade desejada: ");
            scanf("%d", &quantidade);

            if (quantidade <= produtos[i].quantidade) {
                produtos[i].quantidade -= quantidade;
                printf("Compra realizada com sucesso!\n");
                printf("Total: R$ %.2f\n", produtos[i].preco * quantidade);
            } else {
                printf("Estoque insuficiente!\n");
            }
            break;
        }
    }

    if (!encontrado) {
        printf("Produto inexistente.\n");
    }
}
