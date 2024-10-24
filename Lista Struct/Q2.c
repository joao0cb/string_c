#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_DESC 101
#define TAM_PROD 2
#define NOME_PROD 50

struct Papelaria {
    int codigo, estoque;
    char descricao[TAM_DESC];
    float valor;
};

void lerStr(char *str, int tam);
void preencherZero(struct Papelaria cadastro[], int tam);
void cadastroProduto(struct Papelaria cadastro[], int tam);
void alterarValor(struct Papelaria cadastro[], int tam);
float valorProduto(struct Papelaria cadastro[], int tam);
int estoqueProduto(struct Papelaria cadastro[], int tam);
void atualizarEstoque(struct Papelaria cadastro[], int tam);
void codigoDescricaoProdutos(struct Papelaria cadastro[], int tam);
void codigoDescricaoProdutosZero(struct Papelaria cadastro[], int tam);

int main() {
    struct Papelaria cadastro[TAM_PROD];
    preencherZero(cadastro, TAM_PROD);
    int escolha;
    do {
        printf("O que você deseja fazer?\n");
        printf("1 - Cadastrar produto.\n");
        printf("2 - Alterar valor.\n");
        printf("3 - Valor de um produto.\n");
        printf("4 - Estoque de um produto.\n");
        printf("5 - Venda de um produto.\n");
        printf("6 - Atualizar estoque.\n");
        printf("7 - Exibir produtos.\n");
        printf("8 - Exibir produtos com estoque 0.\n");
        printf("0 - Encerrar programa.\n");
        scanf("%d", &escolha);
        
        switch (escolha) {
            case 1:
                cadastroProduto(cadastro, TAM_PROD);
                break;
            case 2:
                alterarValor(cadastro, TAM_PROD);
                break;
            case 3:
                {
                    float valorProd = valorProduto(cadastro, TAM_PROD);
                    if(valorProd == -1) {
                        printf("Código não encontrado.\n");
                    } else {
                        printf("Valor do produto: %.2f\n", valorProd);
                    }
                }
                break;
            case 4:
                {
                    int estoqueProd = estoqueProduto(cadastro, TAM_PROD);
                    if(estoqueProd == -1) {
                        printf("Código não encontrado.\n");
                    } else {
                        printf("Estoque do produto: %d\n", estoqueProd);
                    }
                }
                break;
            case 5:
                printf("Função de venda ainda não implementada.\n");
                break;
            case 6:
                atualizarEstoque(cadastro, TAM_PROD);
                break;
            case 7:
                codigoDescricaoProdutos(cadastro, TAM_PROD);
                break;
            case 8:
                codigoDescricaoProdutosZero(cadastro, TAM_PROD);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while(escolha != 0);
    return 0;
}

void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void preencherZero(struct Papelaria cadastro[], int tam) {
    for(int i = 0; i < tam; ++i) {
        cadastro[i].codigo = 0;
        cadastro[i].estoque = 0;
        cadastro[i].valor = 0;
    }
}

void cadastroProduto(struct Papelaria cadastro[], int tam) {
    int i = 0;
    char temp[TAM_DESC];
    printf("\nCADASTRO\n");
    while(cadastro[i].codigo != 0) {
        ++i;
    }
    printf("Código: ");
    scanf("%d", &cadastro[i].codigo);
    printf("Estoque: ");
    scanf("%d", &cadastro[i].estoque);
    printf("Descrição: ");
    lerStr(temp, TAM_DESC);
    lerStr(cadastro[i].descricao, TAM_DESC);
    printf("Valor: ");
    scanf("%f", &cadastro[i].valor);
    printf("\n");
}

void alterarValor(struct Papelaria cadastro[], int tam) {
    int cod, encontrado = 0;
    printf("\nDigite o código do produto que deseja alterar: ");
    scanf("%d", &cod);
    for(int i = 0; i < tam; ++i) {
        if(cadastro[i].codigo == cod) {
            printf("Insira o novo valor: ");
            scanf("%f", &cadastro[i].valor);
            encontrado = 1;
            break;
        }
    }
    if(!encontrado) {
        printf("Código não encontrado.\n");
    }
}

float valorProduto(struct Papelaria cadastro[], int tam) {
    int cod;
    printf("\nDigite o código do produto para saber o valor: ");
    scanf("%d", &cod);
    for(int i = 0; i < tam; ++i) {
        if(cadastro[i].codigo == cod) {
            return cadastro[i].valor;
        }
    }
    return -1;
}

int estoqueProduto(struct Papelaria cadastro[], int tam) {
    int cod;
    printf("\nDigite o código do produto para saber o estoque: ");
    scanf("%d", &cod);
    for(int i = 0; i < tam; ++i) {
        if(cadastro[i].codigo == cod) {
            return cadastro[i].estoque;
        }
    }
    return -1;
}

void atualizarEstoque(struct Papelaria cadastro[], int tam) {
    int cod, encontrado = 0;
    printf("\nDigite o código do produto que deseja atualizar o estoque: ");
    scanf("%d", &cod);
    for(int i = 0; i < tam; ++i) {
        if(cadastro[i].codigo == cod) {
            printf("Insira a quantidade atualizada: ");
            scanf("%d", &cadastro[i].estoque);
            encontrado = 1;
            break;
        }
    }
    if(!encontrado) {
        printf("\nCódigo não encontrado.\n");
    }
}

void codigoDescricaoProdutos(struct Papelaria cadastro[], int tam) {
    int encontrado = 0;
    for(int i = 0; i < tam; ++i) {
        if(cadastro[i].codigo != 0) {
            printf("\nCódigo: %d\n", cadastro[i].codigo);
            printf("Descrição: %s\n", cadastro[i].descricao);
            encontrado = 1;
        }
    }
    if(!encontrado) {
        printf("\nNenhum produto cadastrado.\n");
    }
}

void codigoDescricaoProdutosZero(struct Papelaria cadastro[], int tam) {
    int encontrado = 0;
    for(int i = 0; i < tam; ++i) {
        if(cadastro[i].estoque == 0 && cadastro[i].codigo != 0) {
            printf("\nCódigo: %d\n", cadastro[i].codigo);
            printf("Descrição: %s\n", cadastro[i].descricao);
            encontrado = 1;
        }
    }
    if(!encontrado) {
        printf("\nNenhum produto com estoque zero.\n");
    }
}
