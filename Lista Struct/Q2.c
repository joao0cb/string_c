#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_DESC 101
#define TAM_

struct Papelaria {
    int codigo, estoque;
    char descricao[TAM_DESC];
    float valor;
};

int main() {
    struct Papelaria cadastro[40];
    printf("O que você deseja fazer?\n");
    printf("1 - Cadastrar produto.\n");
    printf("2 - Alterar valor.\n");
    printf("3 - Valor de um produto.\n");
    printf("4 - Estoque de um produto.\n");
    printf("5 - Venda de um produto.\n");
    printf("6 - Atualizar estoque.\n");
    printf("Exibir produtos.\n");
    printf("Exibir produtos com estoque 0.\n");
}

/*
int Menu() {
    int escolha = 0;
    do {
        printf("(1)Cliente\n(2)Funcionário\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            printf("O que você deseja fazer?\n");
            printf("Valor de um produto.\n");
            printf("Estoque de um produto.\n");
        }
    

}
*/