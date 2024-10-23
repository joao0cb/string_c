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
    printf("1 - Cadastro de novo produto.\n");
    printf("Alterar valor de um produto.\n");
    printf("Valor de um produto.\n");
    printf("")
}