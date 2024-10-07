#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 20

void lerStr(char *str, int tam);
void formatandoFrase(char strOriginal[], char strNova[]);

int main() {
    char strOriginal[TAM];
    char strNova[TAM];
    printf("Qual frase você deseja inserir?\n");
    lerStr(strOriginal, TAM);
    printf("Frase digitada: -->%s<--\n", strOriginal);
    printf("Tamanho da string: %d\n", strlen(strOriginal));

    formatandoFrase(strOriginal, strNova);

    if (strcmp(strOriginal, strNova) == 0) {
        printf("É um palíndromo.\n");
    } else {
        printf("Não é um palíndromo.\n");
    }

    return 0;
}

void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// void trocando(char strOriginal[], char strNova[]) {
//     int len = strlen(strOriginal);
//     int j = 0;

//     for (int i = len - 1; i >= 0; --i) {
//         strNova[j] = strOriginal[i];
//         ++j;
//     }
//     strNova[j] = '\0';
// }

void formatandoFrase(char strOriginal[], char strNova[]) {
    int len = strlen(strOriginal);
    int j = 0;

    for(int i = len-1; i >= 0; --i) {
        if(strOriginal[i] != ' ') {
            strNova[j] = strOriginal[i];
            ++j;
        }
    }
    strNova[j] = '\0';
}