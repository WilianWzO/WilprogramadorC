#include <stdio.h>

int main() {

    char estado1[] = "espiritosanto";
    char codigo1[] = "A01";
    char cidade1[] = "vitoria";
    unsigned long int populacao1 = 1800000;
    float area1 = 93000;
    float PIB1 = 31000000;
    int pontosturisticos1 = 40;

    float densidadepopulacao1 = populacao1 / area1;
    float PIB_per_capita1 = PIB1 / populacao1;
    float Super_Poder1 = populacao1 + area1 + PIB1 + pontosturisticos1 + PIB_per_capita1 + (1 / densidadepopulacao1) + pontosturisticos1;

    printf("Estado: %s\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f\n", area1);
    printf("PIB: %.2f\n", PIB1);
    printf("Pontosturisticos: %d\n", pontosturisticos1);
    printf("Densidade populacional: %.2f pessoas/Km²\n", densidadepopulacao1);
    printf("PIB per capita1: %.2f\n", PIB_per_capita1);
    printf("Super Poder: %.2f\n", Super_Poder1);
    printf("\n");

    char estado2[] = "ceara";
    char codigo2[] = "B02";
    char cidade2[] = "fortaleza";
    unsigned long int populacao2 = 2400000;
    float area2 = 149000;
    float PIB2 = 19400000;
    int pontosturisticos2 = 40;

    float densidadepopulacao2 = populacao2 / area2;
    float PIB_per_capita2 = PIB2 / populacao2;
    float Super_Poder2 = populacao2 + area2 + PIB2 + pontosturisticos2 + PIB_per_capita2 + (1 / densidadepopulacao2) + pontosturisticos2;

    printf("Estado: %s\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f\n", area2);
    printf("PIB: %.2f\n", PIB2);
    printf("Pontosturisticos: %d\n", pontosturisticos2);
    printf("Densidade populacional: %.2f pessoas/Km²\n", densidadepopulacao2);
    printf("PIB per capita2: %.2f\n", PIB_per_capita2);
    printf("Super Poder: %.2f\n", Super_Poder2);
    printf("\n");

    printf("Comparações:\n");
    printf("Populacao1 > Populacao2: %d\n", populacao1 > populacao2);
    printf("Area1 > Area2: %d\n", area1 > area2);
    printf("PIB1 > PIB2: %d\n", PIB1 > PIB2);
    printf("Pontosturisticos1 > Pontosturisticos2: %d\n", pontosturisticos1 > pontosturisticos2);
    printf("Densidadepopulacao1 < Densidadepopulacao2: %d\n", densidadepopulacao1 < densidadepopulacao2);
    printf("PIB_per_capita1 > PIB_per_capita2: %d\n", PIB_per_capita1 > PIB_per_capita2);
    printf("Super_Poder1 > Super_Poder2: %d\n", Super_Poder1 > Super_Poder2);

    printf("\nResultados das Comparações:\n");
    printf("População: Carta %d venceu\n", (populacao1 > populacao2) ? 1 : 2);
    printf("Área: Carta %d venceu\n", (area1 > area2) ? 1 : 2);
    printf("PIB: Carta %d venceu\n", (PIB1 > PIB2) ? 1 : 2);
    printf("Pontos Turísticos: Carta %d venceu\n", (pontosturisticos1 > pontosturisticos2) ? 1 : 2);
    printf("Densidade Populacional: Carta %d venceu\n", (densidadepopulacao1 < densidadepopulacao2) ? 1 : 2);
    printf("PIB per Capita: Carta %d venceu\n", (PIB_per_capita1 > PIB_per_capita2) ? 1 : 2);
    printf("Super Poder: Carta %d venceu\n", (Super_Poder1 > Super_Poder2) ? 1 : 2);

    return 0;
}
