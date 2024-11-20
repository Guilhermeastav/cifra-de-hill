#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MODULO 26

//função para multiplicar matriz pelo vetor
void multiplicarMatriz(int matriz[2][2], int vetor[2], int resultado[2]) {
    for (int i = 0; i < 2; i++) {
        resultado[i] = 0;
        for (int j = 0; j < 2; j++) {
            resultado[i] += matriz[i][j] * vetor[j];
        }
        resultado[i] %= MODULO; 
    }
}

//função para criptografar texto usando a cifra de Hill
void cifraHill(char *texto, int matriz[2][2]) {
    int n = strlen(texto);

    //caso o número de caracteres não for múltiplo de 2, adiciona 'X'
    if (n % 2 != 0) {
        texto[n] = 'X';
        texto[n + 1] = '\0';
    }

    //processa o texto em blocos de tamanho 2
    for (int i = 0; i < strlen(texto); i += 2) {
        int vetor[2] = {texto[i] - 'A', texto[i + 1] - 'A'};
        int resultado[2];

        //multiplica a matriz pela entrada
        multiplicarMatriz(matriz, vetor, resultado);

        //atualiza os caracteres do texto 
        texto[i] = resultado[0] + 'A';
        texto[i + 1] = resultado[1] + 'A';
    }
}

//função para ler a matriz de chave
void lerMatriz(int matriz[2][2]) {
    printf("Digite os valores da matriz 2x2 (linha por linha):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main() {
    int matriz[2][2];
    char texto[100];

    //lê a matriz do usuário
    lerMatriz(matriz);

    //solicita o texto ao usuário
    printf("Digite o texto (apenas letras): ");
    getchar(); 
    fgets(texto, sizeof(texto), stdin);

    //converte para letras maiúsculas 
    int j = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) {
            texto[j++] = toupper(texto[i]);
        }
    }
    texto[j] = '\0';

    //criptografa
    cifraHill(texto, matriz);

    //exibe o texto criptografado
    printf("Texto criptografado: %s\n", texto);

    return 0;
}
