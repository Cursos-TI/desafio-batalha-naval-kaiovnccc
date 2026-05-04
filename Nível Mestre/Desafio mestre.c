#include <stdio.h>

int main() {

    // Letras das colunas
    char letras[10] = {'A','B','C','D','E','F','G','H','I','J'};

    // Tabuleiro principal
    int tabuleiro[10][10];

    // Matrizes das habilidades
    int cone[3][5];
    int cruz[5][5];
    int octaedro[5][5];

    int linhaNavio, colunaNavio;
    int tamanhoNavio = 3;

    // TABULEIRO PREENCHIDO
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // POSICIONAR NAVIO
    char letraColuna;

    while (1) {

    printf("Digite a linha do navio (1 a 10): ");
    scanf("%d", &linhaNavio);

    printf("Digite a coluna do navio (A a J): ");
    scanf(" %c", &letraColuna);

    // Ajustar linha
    linhaNavio--;

    // Converter letra para índice
    colunaNavio = letraColuna - 'A';

    // Validar
    if (linhaNavio >= 0 && linhaNavio < 10 &&
        colunaNavio >= 0 && colunaNavio < 10 &&
        colunaNavio + tamanhoNavio <= 10) {

        break;

    } else {

        printf("\nNavio não cabe nessa posição. Tente novamente.\n\n");
        }
    }

    // Inserir navio
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaNavio][colunaNavio + i] = 3;
    }

    // CONE
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {

            if ((i == 0 && j == 2) ||
                (i == 1 && j >= 1 && j <= 3) ||
                (i == 2)) {

                cone[i][j] = 3;

            } else {
                cone[i][j] = 0;
            }
        }
    }

    // CRUZ
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (i == 2 || j == 2) {
                cruz[i][j] = 3;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // OCTAEDRO
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if ((i == 0 && j == 2) ||
                (i == 1 && j >= 1 && j <= 3) ||
                (i == 2) ||
                (i == 3 && j >= 1 && j <= 3) ||
                (i == 4 && j == 2)) {

                octaedro[i][j] = 3;

            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // POSICIONAR CONE
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {

            if (cone[i][j] == 3) {
                tabuleiro[i][j] = 3;
            }
        }
    }

    // POSICIONAR CRUZ
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (cruz[i][j] == 3) {
                tabuleiro[i + 3][j + 5] = 3;
            }
        }
    }

    // POSICIONAR OCTAEDRO
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (octaedro[i][j] == 3) {
                tabuleiro[i + 5][j] = 3;
            }
        }
    }

    // TABULEIRO
    printf("\n     TABULEIRO BATALHA NAVAL\n\n");

    printf("   ");
    for (int i = 0; i < 10; i++) {
        printf("%2c ", letras[i]);
    }

    printf("\n");

    for (int i = 0; i < 10; i++) {

        printf("%2d ", i + 1);

        for (int j = 0; j < 10; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }

        printf("\n");
    }

    return 0;
}