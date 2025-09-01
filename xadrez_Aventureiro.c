#include <stdio.h>

int main() {
    int movimentosBaixo = 2;
    int movimentosEsquerda = 1;

    printf("\n"); // separa o movimento do Cavalo dos outros

    // Loop externo: movimento para baixo
    for (int i = 0; i < movimentosBaixo; i++) {
        printf("Baixo\n");

        // Quando chegar no último "Baixo", faz o movimento para esquerda
        if (i == movimentosBaixo - 1) {
            int j = 0;
            while (j < movimentosEsquerda) {
                printf("Esquerda\n");
                j++;
            }
        }
    }

    return 0;
}