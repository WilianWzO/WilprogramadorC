#include <stdio.h>  

void moverTorre(int casas, int passo) {  
    if (passo > casas) return;  
    
    printf("Direita %d\n", passo);  
    moverTorre(casas, passo + 1);   
}  

void moverBispo(int casasVertical, int casasHorizontal, int linhaAtual) {  
    if (linhaAtual > casasVertical) return;  

    printf("Cima %d (Para linha %d)\n", linhaAtual, linhaAtual);  
    
    for (int colAtual = 1; colAtual <= casasHorizontal; colAtual++) {  
        printf("Direita %d (Para coluna %d)\n", colAtual, colAtual);  
    }  
    
    moverBispo(casasVertical, casasHorizontal, linhaAtual + 1);   
}   

void moverRainha(int casas, int passo) {  
    if (passo > casas) return;  

    printf("Esquerda %d\n", passo);  
    moverRainha(casas, passo + 1);  
}  

void moverCavalo() {  
    int movimentoVertical = 2;  
    int movimentoHorizontal = 1;  

    for (int i = 1; i <= movimentoVertical; i++) {  
        printf("Cima %d\n", i);  
    }  

    for (int j = 1; j <= movimentoHorizontal; j++) {  
        printf("Direita %d\n", j);  
    }  
}  

int main() {  
    printf("Movimento Torre:\n");  
    moverTorre(5, 1);  

    printf("\n");  

    printf("Movimento Bispo:\n");  
    moverBispo(5, 5, 1);  

    printf("\n");  

    printf("Movimento Rainha:\n");  
    moverRainha(8, 1);  

    printf("\n");  

    printf("Movimento Cavalo:\n");  
    moverCavalo();  

    return 0;  
}  