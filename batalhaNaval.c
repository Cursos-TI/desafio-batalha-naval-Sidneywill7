#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

void posicionarNavioHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (coluna + NAVIO <= TAMANHO) {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha][coluna + i] = 3; // 3 representa um navio
        }
    }
}

void posicionarNavioVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha + NAVIO <= TAMANHO) {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha + i][coluna] = 3; // 3 representa um navio
        }
    }
}

void atirar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    tabuleiro[linha][coluna] = 1; // 1 representa um tiro
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("  A B C D E F G H I J\n"); // Cabeçalho das colunas
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1); // Números das linhas
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Posicionamento do primeiro navio (horizontal)
    // Na linha 2 (linha 1 no array), colunas D, E e F (colunas 3, 4 e 5 no array)
    posicionarNavioHorizontal(tabuleiro, 1, 3);

    // Posicionamento do segundo navio (vertical)
    // Na coluna H (coluna 7 no array), linhas 6, 7 e 8 (linhas 5, 6 e 7 no array)
    posicionarNavioVertical(tabuleiro, 5, 7);

    // Disparos
    atirar(tabuleiro, 1, 3); // Disparo na posição D2
    atirar(tabuleiro, 1, 4); // Disparo na posição E2
    atirar(tabuleiro, 1, 5); // Disparo na posição F2
    atirar(tabuleiro, 5, 7); // Disparo na posição H6
    atirar(tabuleiro, 6, 7); // Disparo na posição H7
    atirar(tabuleiro, 7, 7); // Disparo na posição H8

    // Exibir tabuleiro
    printf("TABULEIRO BATALHA NAVAL\n\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}