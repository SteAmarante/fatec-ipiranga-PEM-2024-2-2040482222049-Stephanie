/* Disciplina: Programaçao Estruturada e Modular
Prof. Carlos Veríssimo                                    
--------------------------------------------------------
Objetivo do Programa: Utilizando ponteiros 
Data - 05/11/2024                                                
Autores: Julio Cesar Santana - RA 2040482312048
         Stephanie Carolline Amarante - RA 2040482222049
--------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    int quantidadeEmEstoque;
    double valorDoProduto;
} Produto;

// Função para incluir um produto
void incluirProduto(Produto *produtos, int *totalProdutos) {
    if (*totalProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto *produto = &produtos[*totalProdutos];

    printf("Digite o ID do produto: ");
    scanf("%d", &produto->id);
    printf("Digite o nome do produto: ");
    scanf("%s", produto->nome);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &produto->quantidadeEmEstoque);
    printf("Digite o valor do produto: ");
    scanf("%lf", &produto->valorDoProduto);

    (*totalProdutos)++;
    printf("Produto incluído com sucesso!\n");
}

// Função para consultar um produto por ID
void consultarProduto(Produto *produtos, int totalProdutos, int id) {
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].id == id) {
            printf("ID: %d\n", produtos[i].id);
            printf("Nome: %s\n", produtos[i].nome);
            printf("Quantidade em Estoque: %d\n", produtos[i].quantidadeEmEstoque);
            printf("Valor do Produto: %.2f\n", produtos[i].valorDoProduto);
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", id);
}

// Função para alterar um produto por ID
void alterarProduto(Produto *produtos, int totalProdutos, int id) {
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].id == id) {
            printf("Alterando produto com ID %d\n", id);
            printf("Digite o novo nome do produto: ");
            scanf("%s", produtos[i].nome);
            printf("Digite a nova quantidade em estoque: ");
            scanf("%d", &produtos[i].quantidadeEmEstoque);
            printf("Digite o novo valor do produto: ");
            scanf("%lf", &produtos[i].valorDoProduto);
            printf("Produto alterado com sucesso!\n");
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", id);
}

// Função para excluir um produto por ID
void excluirProduto(Produto *produtos, int *totalProdutos, int id) {
    for (int i = 0; i < *totalProdutos; i++) {
        if (produtos[i].id == id) {
            for (int j = i; j < *totalProdutos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            (*totalProdutos)--;
            printf("Produto com ID %d excluído com sucesso!\n", id);
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", id);
}

// Função para vender um produto
void venderProduto(Produto *produtos, int totalProdutos, int id, int quantidade) {
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].id == id) {
            if (produtos[i].quantidadeEmEstoque >= quantidade) {
                produtos[i].quantidadeEmEstoque -= quantidade;
                printf("Venda realizada com sucesso!\n");
            } else {
                printf("Quantidade insuficiente em estoque.\n");
            }
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", id);
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int totalProdutos = 0;
    int opcao, id, quantidade;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Incluir produto\n");
        printf("2. Consultar produto\n");
        printf("3. Alterar produto\n");
        printf("4. Excluir produto\n");
        printf("5. Vender produto\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirProduto(produtos, &totalProdutos);
                break;
            case 2:
                printf("Digite o ID do produto para consulta: ");
                scanf("%d", &id);
                consultarProduto(produtos, totalProdutos, id);
                break;
            case 3:
                printf("Digite o ID do produto para alteração: ");
                scanf("%d", &id);
                alterarProduto(produtos, totalProdutos, id);
                break;
            case 4:
                printf("Digite o ID do produto para exclusão: ");
                scanf("%d", &id);
                excluirProduto(produtos, &totalProdutos, id);
                break;
            case 5:
                printf("Digite o ID do produto para venda: ");
                scanf("%d", &id);
                printf("Digite a quantidade a ser vendida: ");
                scanf("%d", &quantidade);
                venderProduto(produtos, totalProdutos, id, quantidade);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
