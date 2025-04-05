#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_HAB 5
#define TAM_NAV 5

void cria_cone(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            if (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void cria_cruz(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            habilidade[i][j] = (i == TAM_HAB / 2 || j == TAM_HAB / 2) ? 1 : 0;
        }
    }
}

void cria_octaedro(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            if (abs(TAM_HAB / 2 - i) + abs(TAM_HAB / 2 - j) <= TAM_HAB / 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void aplica_habilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int linha, int coluna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int x = linha - TAM_HAB / 2 + i;
            int y = coluna - TAM_HAB / 2 + j;

            if (x >= 0 && x < TAM && y >= 0 && y < TAM && habilidade[i][j] == 1) {
                if (tabuleiro[x][y] == 0) { 
                    tabuleiro[x][y] = 5; 
                }
            }
        }
    }
}

void exibe_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n    ");
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0)
                printf(" 0 ");
            else if (tabuleiro[i][j] == 3)
                printf(" 7 "); 
            else if (tabuleiro[i][j] == 5)
                printf(" 1 ");
            else
                printf(" ? "); 
        }
        printf("\n");
    }
}

void posiciona_navio(int tabuleiro[TAM][TAM], int linha, int coluna, char direcao) {
    for (int i = 0; i < TAM_NAV; i++) {
        if (direcao == 'H') {
            if (coluna + i < TAM) {
                tabuleiro[linha][coluna + i] = 3;
            }
        } else if (direcao == 'V') {
            if (linha + i < TAM) {
                tabuleiro[linha + i][coluna] = 3;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    cria_cone(cone);
    cria_cruz(cruz);
    cria_octaedro(octaedro);

    posiciona_navio(tabuleiro, 2, 3, 'H');
    posiciona_navio(tabuleiro, 6, 6, 'V'); 

    aplica_habilidade(tabuleiro, cone, 3, 3);
    aplica_habilidade(tabuleiro, cruz, 5, 5);
    aplica_habilidade(tabuleiro, octaedro, 7, 2);

    exibe_tabuleiro(tabuleiro);

    return 0;
}
