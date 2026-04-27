#include <stdio.h>

int main() {

    // Letras das Colunas
    char letras[10] = {'A','B','C','D','E','F','G','H','I','J'};

    // Tabuleiro 10x10
    int tabuleiro[10][10];

    int tamanhoNavio = 3;

    // Tabuleiro preenchido
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio diagonal
    int linha = 2;
    int coluna = 2;

    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linha + i][coluna + i] = 3;
    }

    // Navio diagonal 2
    int linha4 = 1;
    int coluna4 = 8;

    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linha4 + i][coluna4 - i] = 3;
    }
    
    // Navio vertical
    int linha2 = 5;
    int coluna2 = 2;

    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linha2 + i][coluna2] = 3;
    }

    // Navio horizontal
    int linha3 = 7;
    int coluna3 = 6;

    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linha3][coluna3 + i] = 3;
    }

    // Título
    printf("\n     TABULEIRO BATALHA NAVAL \n\n");

    // Colunas
    printf("   "); // Linhas

    for (int j = 0; j < 10; j++) {
        printf("%2c ", letras[j]);
    }

    printf("\n");

    // Imprimir o tabuleiro
    for (int i = 0; i < 10; i++) {

        // imprime número da linha (1 até 10)
        printf("%2d ", i + 1);

        for (int j = 0; j < 10; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }

        printf("\n");
    }
    return 0;
}