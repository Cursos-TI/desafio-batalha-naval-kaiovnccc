#include <stdio.h>

int main() {

    char letras[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[10][10];
    int tamanhoNavio = 3;

    // Preencher tabuleiro com 0
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int linha, coluna;

    // Entrada do usuário com validação
    while (1) {
        printf("Digite a linha (1 a 10): ");
        scanf("%d", &linha);

        printf("Digite a coluna (1 a 10): ");
        scanf("%d", &coluna);

        // Ajustar para índice (0 a 9)
        linha--;
        coluna--;

        // Verificar se cabe (horizontal)
        if (coluna + tamanhoNavio <= 10) {
            break; // válido
        } else {
            printf("Navio não cabe! Tente novamente.\n\n");
        }
    }

    // Posicionar navio horizontal
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }

    // Exibir tabuleiro
    printf("\n     TABULEIRO BATALHA NAVAL \n\n");

    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf("%2c ", letras[j]);
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