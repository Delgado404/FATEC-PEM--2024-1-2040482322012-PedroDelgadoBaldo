#include <stdio.h>
#include <string.h>

// Função para preencher o tabuleiro com as peças nas posições iniciais
void preencherTabuleiro(char tabuleiro[8][8][4]) {

    // Peças pretas nas primeiras duas linhas
    for (int i = 0; i < 8; i++) {
        sprintf(tabuleiro[0][i], "tP%d", i + 1);
        sprintf(tabuleiro[1][i], "pP%d", i + 1);
    }
    strcpy(tabuleiro[0][1], "cP2"); // Cavalo preto
    strcpy(tabuleiro[0][2], "bP3"); // Bispo preto
    strcpy(tabuleiro[0][3], "dP4"); // Dama preta
    strcpy(tabuleiro[0][4], "rP5"); // Rei preto
    strcpy(tabuleiro[0][5], "bP6"); // Bispo preto
    strcpy(tabuleiro[0][6], "cP7"); // Cavalo preto

    // Espaços vazios
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            strcpy(tabuleiro[i][j], "   ");
        }
    }

    // Peças brancas nas últimas duas linhas
    for (int i = 0; i < 8; i++) {
        sprintf(tabuleiro[6][i], "pB%d", i + 1);
        sprintf(tabuleiro[7][i], "tB%d", i + 1);
    }

    strcpy(tabuleiro[7][1], "cB2"); // Cavalo branco
    strcpy(tabuleiro[7][2], "bB3"); // Bispo branco
    strcpy(tabuleiro[7][3], "dB4"); // Dama branca
    strcpy(tabuleiro[7][4], "rB5"); // Rei branco
    strcpy(tabuleiro[7][5], "bB6"); // Bispo branco
    strcpy(tabuleiro[7][6], "cB7"); // Cavalo branco
}

void imprimirTabuleiro(char tabuleiro[8][8][4]) {
    printf("   a   b   c   d   e   f   g   h\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf("%s ", tabuleiro[i][j]);
        }
        printf("%d\n", 8 - i);
    }
    printf("   a   b   c   d   e   f   g   h\n");
}

void jogada1(char tabuleiro[8][8][4]){
    printf("Jogada #1:\n");
    printf("---------------brancas--------------\n");    
    strcpy(tabuleiro[6][4], "..."); // Remover o peão branco da posição e2    
    strcpy(tabuleiro[4][4], "pB5"); // Peão branco movido para a posição e4
    imprimirTabuleiro(tabuleiro);
    printf("---------------pretas---------------");
    printf("\n");

    strcpy(tabuleiro[1][4], "..."); // Remover o peão preto da posição e7
    strcpy(tabuleiro[3][4], "pP5"); // Peão preto movido para a posição e5
    imprimirTabuleiro(tabuleiro);
    printf("\n");
}

void jogada2(char tabuleiro[8][8][4]){
    printf("Jogada #2 :\n");
    printf("---------------brancas--------------\n");
    strcpy(tabuleiro[7][5], "..."); // Remover o bispo branco da posição f1
    strcpy(tabuleiro[4][2], "bB6"); // Bispo branco movido para a posição c4
    imprimirTabuleiro(tabuleiro);
    printf("---------------pretas---------------");
    printf("\n");

    strcpy(tabuleiro[0][1], "..."); // Remover o cavalo preto da posição b8
    strcpy(tabuleiro[2][2], "cP2"); // Cavalo preto movido para a posição c6
    imprimirTabuleiro(tabuleiro);
    printf("\n");
}

void jogada3(char tabuleiro[8][8][4]){
    printf("Jogada #3:\n");
    printf("---------------brancas--------------\n");
    strcpy(tabuleiro[7][3], "..."); // Remover a dama branca da posição d1
    strcpy(tabuleiro[3][7], "dB4"); // Dama branca movida para a posição h5
    imprimirTabuleiro(tabuleiro);
    printf("---------------pretas---------------");
    printf("\n");

    strcpy(tabuleiro[0][6], "..."); // Remover o cavalo preto da posição g8
    strcpy(tabuleiro[2][5], "cP7"); // Cavalo preto movido para a posição f6
    imprimirTabuleiro(tabuleiro);
    printf("\n");
}

void jogada4(char tabuleiro[8][8][4]){
    printf("Jogada #4 (Xeque Mate - Brancas):\n");
    strcpy(tabuleiro[0][4], "-X-"); 
    strcpy(tabuleiro[3][7], "..."); 
    strcpy(tabuleiro[1][5], "dB4"); 
    imprimirTabuleiro(tabuleiro);
    printf("\n");
}

int main() {
    char tabuleiro[8][8][4]; 

    preencherTabuleiro(tabuleiro);
    
    printf("Tabuleiro Inicial:\n");
    imprimirTabuleiro(tabuleiro);
    printf("\n");

    jogada1(tabuleiro);
    jogada2(tabuleiro);
    jogada3(tabuleiro);
    jogada4(tabuleiro);
    
    return 0;
}