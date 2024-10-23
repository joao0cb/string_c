#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_NOME 30
#define QTD_ESTADOS 26
#define TEMP_CHAR 999

struct Acidentes {
    char nomeEstado[TAM_NOME];
    int numVeiculos, numAcidentes;
};

void lerStr(char *str, int tam);
void lerEstados(struct Acidentes estados[], int tam);
void maioreMenorAcidentes(struct Acidentes estados[], int tam, int *indMaior, int *indMenor);
float porcentagemAcidentes(struct Acidentes estados[], int i);
int mediaAcidentesPais(struct Acidentes estados[], int tam);
void estadosAcimaMedia(struct Acidentes estados[], int acidentesMedia, int tam);

int main() {
    struct Acidentes estados[QTD_ESTADOS];
    int indMaior, indMenor;
    lerEstados(estados, QTD_ESTADOS);
    maioreMenorAcidentes(estados, QTD_ESTADOS, &indMaior, &indMenor);
    printf("O estado com o menor números de acidentes foi %s com %d.\n", estados[indMenor].nomeEstado, estados[indMenor].numAcidentes);
    printf("O estado com o maior números de acidentes foi %s com %d.\n", estados[indMaior].nomeEstado, estados[indMaior].numAcidentes);
    printf("\nPercentual de acidentes para cada estado:\n");
    for(int i = 0; i < QTD_ESTADOS; ++i) {
        float porcAcident = porcentagemAcidentes(estados, i);
        printf("%s: %.2f%%\n", estados[i].nomeEstado, porcAcident);
    }
    int acidentesMedia = mediaAcidentesPais(estados, QTD_ESTADOS);
    printf("\nA média de acidentes no país é %d.\n", acidentesMedia);
    estadosAcimaMedia(estados, acidentesMedia, QTD_ESTADOS);

    return 0;
}

void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void lerEstados(struct Acidentes estados[], int tam) {
    for(int i = 0; i < tam; ++i) {
        char temp[TEMP_CHAR];
        printf("Digite o estado: ");
        lerStr(estados[i].nomeEstado, TAM_NOME);
        printf("Digite o número de veículos que circulam neste estado (em 2007): ");
        scanf("%d", &estados[i].numVeiculos);
        printf("Digite o números de acidentes de trânsito neste estado (em 2007): ");
        scanf("%d", &estados[i].numAcidentes);
        lerStr(temp, TEMP_CHAR);
        printf("\n");
    }
}

void maioreMenorAcidentes(struct Acidentes estados[], int tam, int *indMaior, int *indMenor) {
    *indMaior = 0;
    *indMenor = 0;
    for(int i = 1; i < tam; ++i) {
        if(estados[i].numAcidentes > estados[*indMaior].numAcidentes) {
            *indMaior = i;
        }
        if(estados[i].numAcidentes < estados[*indMaior].numAcidentes) {
            *indMenor = i;
        }
    }
}

float porcentagemAcidentes(struct Acidentes estados[], int i) {
    float porcentAcidentes = ((float)estados[i].numAcidentes / estados[i].numVeiculos) * 100;
    return porcentAcidentes;
}

int mediaAcidentesPais(struct Acidentes estados[], int tam) {
    int mediaAcidentes, somaAcidentes = 0;
    for(int i = 0; i < tam; ++i) {
        somaAcidentes += estados[i].numAcidentes;
    }
    mediaAcidentes = somaAcidentes / tam;
    return mediaAcidentes;
}

void estadosAcimaMedia(struct Acidentes estados[], int acidentesMedia, int tam) {
    printf("\nEstados acima da média de acidentes:\n");
    for(int i = 0; i < tam; ++i) {
        if(estados[i].numAcidentes > acidentesMedia) {
            printf("%s\n", estados[i].nomeEstado);
        }
    }
}