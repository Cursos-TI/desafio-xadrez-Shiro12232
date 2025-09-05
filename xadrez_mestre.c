#include <stdio.h>
#include <stdlib.h>

/* ---------------------------------------------------------
   Configurações (entradas definidas no código)
   Altere aqui a quantidade de casas/movimentos por peça
   --------------------------------------------------------- */
const int PASSOS_TORRE          = 3; // Ex.: Torre para a direita por 3 casas
const int PASSOS_BISPO          = 4; // Ex.: Bispo para cima+direita por 4 casas
const int PASSOS_RAINHA_RETA    = 2; // Ex.: Rainha em linha reta (cima) 2 casas
const int PASSOS_RAINHA_DIAG    = 3; // Ex.: Rainha em diagonal (cima+direita) 3 casas
const int MOVIMENTOS_CAVALO     = 3; // Ex.: 3 movimentos em L (2 pra cima, 1 pra direita)

/* ---------------------------------------------------------
   Utilitários
   --------------------------------------------------------- */

/* Imprime uma direção (string) N vezes, recursivamente.
   Usada na Torre/Rainha reta. Mantém a pilha pequena (passos limitados). */
void imprimeDirecaoRec(const char* direcao, int passos) {
    if (passos <= 0) return;
    printf("%s\n", direcao);
    imprimeDirecaoRec(direcao, passos - 1);
}

/* Para movimentos diagonais (Bispo/Rainha diagonal):
   a cada "passo" diagonal, move 1 na vertical e 1 na horizontal,
   imprimindo duas direções por casa diagonal. */
void moveDiagonalRec(const char* dirVertical, const char* dirHorizontal, int passos) {
    if (passos <= 0) return;
    printf("%s\n", dirVertical);
    printf("%s\n", dirHorizontal);
    moveDiagonalRec(dirVertical, dirHorizontal, passos - 1);
}

/* ---------------------------------------------------------
   Torre (recursivo)
   Exemplo: mover "Direita" PASSOS_TORRE vezes.
   Para outros sentidos, altere a string passada.
   --------------------------------------------------------- */
void moverTorreRecursivo(int passos, const char* direcao) {
    /* Substitui loop simples por recursão de cauda */
    imprimeDirecaoRec(direcao, passos);
}

/* ---------------------------------------------------------
   Bispo (duas abordagens exigidas)

   1) Recursivo: usa moveDiagonalRec (cima + direita, por exemplo).
   2) Loops aninhados: loop externo = vertical, interno = horizontal,
      imprimindo 1 passo vertical e 1 horizontal por cada "casa" diagonal.
   --------------------------------------------------------- */

/* 1) Recursivo */
void moverBispoRecursivo(int passos, const char* dirVertical, const char* dirHorizontal) {
    moveDiagonalRec(dirVertical, dirHorizontal, passos);
}

/* 2) Loops aninhados (externo = vertical, interno = horizontal) */
void moverBispoLoops(int passos, const char* dirVertical, const char* dirHorizontal) {
    for (int v = 0; v < passos; v++) {
        /* Um passo vertical por iteração externa */
        printf("%s\n", dirVertical);

        /* Um passo horizontal por iteração interna (poderia ser >1 se quisesse) */
        for (int h = 0; h < 1; h++) {
            printf("%s\n", dirHorizontal);
        }
    }
}

/* ---------------------------------------------------------
   Rainha (recursivo)
   - Reta: reaproveita a lógica da Torre (imprimeDirecaoRec)
   - Diagonal: reaproveita a lógica do Bispo (moveDiagonalRec)
   --------------------------------------------------------- */
void moverRainhaRetaRecursivo(int passos, const char* direcao) {
    imprimeDirecaoRec(direcao, passos);
}

void moverRainhaDiagonalRecursivo(int passos, const char* dirVertical, const char* dirHorizontal) {
    moveDiagonalRec(dirVertical, dirHorizontal, passos);
}

/* ---------------------------------------------------------
   Cavalo (loops aninhados com múltiplas variáveis/condições)
   Movimento pedido: para cima e para a direita em "L"
   (duas casas para cima + uma casa para a direita) repetido N vezes.

   Requisitos atendidos:
   - loops aninhados
   - múltiplas variáveis/condições
   - uso de continue e break para controlar fluxo
   - imprime direção por casa percorrida
   --------------------------------------------------------- */
void moverCavaloLoops(int movimentos) {
    /* 
      Neste bloco, cada "movimento" do cavalo é composto por:
      - 2 passos "Cima"
      - 1 passo "Direita"

      O primeiro for controla quantos "L" faremos.
      O for interno usa duas contagens (v = verticais, h = horizontais)
      com condições OR para ilustrar múltiplas condições.
    */
    for (int m = 0; m < movimentos; m++) {

        /* Loop interno: executa até completar 2 verticais e 1 horizontal */
        for (int v = 0, h = 0; (v < 2) || (h < 1); ) {

            /* Enquanto ainda faltar vertical, priorize a vertical */
            if (v < 2) {
                printf("Cima\n");
                v++;

                /* Enquanto não completar as 2 verticais, continue
                   (não entra no bloco de horizontal) */
                if (v < 2) {
                    continue; /* controla o fluxo explicitamente */
                }
            }

            /* Só chega aqui quando as 2 verticais estiverem completas
               (ou se já estavam completas antes). Agora faz a horizontal. */
            if (h < 1) {
                printf("Direita\n");
                h++;
            }

            /* Se completamos v==2 e h==1, quebramos o laço interno. */
            if (v >= 2 && h >= 1) {
                break; /* encerra o L atual */
            }
        }
    }
}

/* ---------------------------------------------------------
   Programa principal
   --------------------------------------------------------- */
int main(void) {
    /* Em Windows, habilita UTF-8 no console (opcional) */
    system("chcp 65001 > nul");

    /* ----------------- TORRE (Recursivo) ----------------- */
    printf("Torre (recursivo) — Direita por %d casas:\n", PASSOS_TORRE);
    moverTorreRecursivo(PASSOS_TORRE, "Direita");
    printf("\n");

    /* ----------------- BISPO (Recursivo) ----------------- */
    printf("Bispo (recursivo) — Cima + Direita por %d casas:\n", PASSOS_BISPO);
    moverBispoRecursivo(PASSOS_BISPO, "Cima", "Direita");
    printf("\n");

    /* ------- BISPO (Loops aninhados: V externo, H interno) ------- */
    printf("Bispo (loops aninhados) — Cima + Direita por %d casas:\n", PASSOS_BISPO);
    moverBispoLoops(PASSOS_BISPO, "Cima", "Direita");
    printf("\n");

    /* --------------- RAINHA (Recursivo: reta) --------------- */
    printf("Rainha (recursivo, reta) — Cima por %d casas:\n", PASSOS_RAINHA_RETA);
    moverRainhaRetaRecursivo(PASSOS_RAINHA_RETA, "Cima");
    printf("\n");

    /* -------- RAINHA (Recursivo: diagonal) -------- */
    printf("Rainha (recursivo, diagonal) — Cima + Direita por %d casas:\n", PASSOS_RAINHA_DIAG);
    moverRainhaDiagonalRecursivo(PASSOS_RAINHA_DIAG, "Cima", "Direita");
    printf("\n");

    /* --------------- CAVALO (Loops complexos) --------------- */
    printf("Cavalo (loops aninhados, L = 2x Cima + 1x Direita) — %d movimentos:\n", MOVIMENTOS_CAVALO);
    moverCavaloLoops(MOVIMENTOS_CAVALO);
    printf("\n");

    return 0;
}
