#include <stdio.h>
#include <stdlib.h>

char estado1[] = "Espírito Santo";
unsigned long int populacao1 = 1800000;
float area1 = 93000;
float PIB1 = 31000000;
int pontosturisticos1 = 40;

char estado2[] = "Ceará";
unsigned long int populacao2 = 2400000;
float area2 = 149000;
float PIB2 = 19400000;
int pontosturisticos2 = 40;


float densidade_populacao(unsigned long int populacao, float area) {
    return (float)populacao / area;
}

void exibir_menu(int atributos_usados[]) {
    printf("Escolha um atributo para comparar:\n");
    if (!atributos_usados[1]) printf("1. População\n");
    if (!atributos_usados[2]) printf("2. Área\n");
    if (!atributos_usados[3]) printf("3. PIB\n");
    if (!atributos_usados[4]) printf("4. Pontos Turísticos\n");
    if (!atributos_usados[5]) printf("5. Densidade Demográfica\n");
    printf("Opção: ");
}

int main() {
    int atributos_usados[6] = {0, 0, 0, 0, 0, 0}; 
    int escolhas[3]; 
    int i;

    float densidade1 = densidade_populacao(populacao1, area1);
    float densidade2 = densidade_populacao(populacao2, area2);

    printf("Bem-vindo ao jogo de comparação!\n");


    for (i = 0; i < 3; i++) {
        int escolha;
        do {
            exibir_menu(atributos_usados);
            scanf("%d", &escolha);
            if (escolha < 1 || escolha > 5 || atributos_usados[escolha]) {
                printf("Opção inválida ou já escolhida. Tente novamente.\n");
            }
        } while (escolha < 1 || escolha > 5 || atributos_usados[escolha]);

        escolhas[i] = escolha;
        atributos_usados[escolha] = 1; 
    }


    int pontos1 = 0, pontos2 = 0;
    printf("\nComparando atributos:\n");
    for (i = 0; i < 3; i++) {
        int atributo = escolhas[i];
        switch (atributo) {
            case 1: 
                printf("População -> %s: %lu, %s: %lu\n", estado1, populacao1, estado2, populacao2);
                pontos1 += (populacao1 > populacao2) ? 1 : 0;
                pontos2 += (populacao2 > populacao1) ? 1 : 0;
                break;
            case 2: 
                printf("Área -> %s: %.2f km², %s: %.2f km²\n", estado1, area1, estado2, area2);
                pontos1 += (area1 > area2) ? 1 : 0;
                pontos2 += (area2 > area1) ? 1 : 0;
                break;
            case 3: 
                printf("PIB -> %s: %.2f, %s: %.2f\n", estado1, PIB1, estado2, PIB2);
                pontos1 += (PIB1 > PIB2) ? 1 : 0;
                pontos2 += (PIB2 > PIB1) ? 1 : 0;
                break;
            case 4: 
                printf("Pontos Turísticos -> %s: %d, %s: %d\n", estado1, pontosturisticos1, estado2, pontosturisticos2);
                pontos1 += (pontosturisticos1 > pontosturisticos2) ? 1 : 0;
                pontos2 += (pontosturisticos2 > pontosturisticos1) ? 1 : 0;
                break;
            case 5: 
                printf("Densidade Demográfica -> %s: %.2f, %s: %.2f\n", estado1, densidade1, estado2, densidade2);
                pontos1 += (densidade1 < densidade2) ? 1 : 0; // Menor valor vence
                pontos2 += (densidade2 < densidade1) ? 1 : 0;
                break;
        }
    }

    
    printf("\nResultado final:\n");
    printf("%s: %d pontos\n", estado1, pontos1);
    printf("%s: %d pontos\n", estado2, pontos2);

    if (pontos1 > pontos2) {
        printf("%s venceu!\n", estado1);
    } else if (pontos2 > pontos1) {
        printf("%s venceu!\n", estado2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
