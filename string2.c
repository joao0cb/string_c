#include <stdio.h>
#include <string.h>

#define TAM_NOME 30
#define QTD_ESTADOS 27

void lerStr(char *str, int tam);

struct Acidentes {
    char nomeEstado[TAM_NOME];
    int numVeiculos, numAcidentes;
};

int main() {
    struct Acidentes estados[QTD_ESTADOS];


}

void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void lerAcidentes(struct Acidentes estados[], int tam) {
    for(int i = 0; i < tam; ++i) {
        printf("Digite o estado: \n");
        lerStr(estados[i].nomeEstado[i], tam);
    }
}

void imprimirAcidentes(struct Acidentes estados[], int tam){
    
}