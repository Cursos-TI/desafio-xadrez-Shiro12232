#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 65001 > nul"); 

    // ------------------- Torre -------------------
    // Torre move-se 5 casas para a direita (linha reta horizontal)
    int movimentoTorre = 0;
    printf("Movimento da Torre:\n");
    while (movimentoTorre < 5) {
        printf("Direita\n");
        movimentoTorre++;
    }

    printf("\n"); // linha em branco para separar

    // ------------------- Bispo -------------------
    // Bispo move-se 5 casas na diagonal (cima e direita)
    printf("Movimento do Bispo:\n");
    for (int i = 0; i < 5; i++) {
        printf("Cima Direita\n");
    }

    printf("\n"); // linha em branco para separar

    // ------------------- Rainha -------------------
    // Rainha move-se 8 casas para a esquerda
    printf("Movimento da Rainha:\n");
    int movimentoRainha = 0;
    do {
        printf("Esquerda\n");
        movimentoRainha++;
    } while (movimentoRainha < 8);

    return 0;
}