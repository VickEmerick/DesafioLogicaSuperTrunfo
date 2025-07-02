#include <stdio.h>
#include <string.h>

int main() {
    // Variáveis para a Carta 1
    char estado1;
    char codigo1[5];
    char cidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidade1;
    float pibPerCapita1;

    // Variáveis para a Carta 2
    char estado2;
    char codigo2[5];
    char cidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2;
    float pibPerCapita2;

    int opcao;

    // --- Entrada de dados da Carta 1 ---
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Código da Carta (ex: A01): ");
    scanf("%4s", codigo1);

    getchar();
    printf("Nome da Cidade: ");
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = '\0';

    printf("População: ");
    scanf("%lu", &populacao1);

    printf("Área (km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1e9f) / populacao1;

    // --- Entrada de dados da Carta 2 ---
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Código da Carta (ex: B02): ");
    scanf("%4s", codigo2);

    getchar();
    printf("Nome da Cidade: ");
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = '\0';

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1e9f) / populacao2;

    // Menu interativo para escolher o atributo de comparação
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB per Capita\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    printf("\nComparação entre %s e %s:\n", cidade1, cidade2);

    switch (opcao) {
        case 1:
            printf("População: %lu vs %lu\n", populacao1, populacao2);
            if (populacao1 > populacao2)
                printf("%s venceu!\n", cidade1);
            else if (populacao2 > populacao1)
                printf("%s venceu!\n", cidade2);
            else
                printf("Empate!\n");
            break;
        case 2:
            printf("Área: %.2f km² vs %.2f km²\n", area1, area2);
            if (area1 > area2)
                printf("%s venceu!\n", cidade1);
            else if (area2 > area1)
                printf("%s venceu!\n", cidade2);
            else
                printf("Empate!\n");
            break;
        case 3:
            printf("PIB: %.2f bilhões vs %.2f bilhões\n", pib1, pib2);
            if (pib1 > pib2)
                printf("%s venceu!\n", cidade1);
            else if (pib2 > pib1)
                printf("%s venceu!\n", cidade2);
            else
                printf("Empate!\n");
            break;
        case 4:
            printf("Pontos Turísticos: %d vs %d\n", pontosTuristicos1, pontosTuristicos2);
            if (pontosTuristicos1 > pontosTuristicos2)
                printf("%s venceu!\n", cidade1);
            else if (pontosTuristicos2 > pontosTuristicos1)
                printf("%s venceu!\n", cidade2);
            else
                printf("Empate!\n");
            break;
        case 5:
            printf("Densidade Demográfica: %.2f hab/km² vs %.2f hab/km²\n", densidade1, densidade2);
            if (densidade1 < densidade2)
                printf("%s venceu!\n", cidade1);
            else if (densidade2 < densidade1)
                printf("%s venceu!\n", cidade2);
            else
                printf("Empate!\n");
            break;
        case 6:
            printf("PIB per Capita: %.2f reais vs %.2f reais\n", pibPerCapita1, pibPerCapita2);
            if (pibPerCapita1 > pibPerCapita2)
                printf("%s venceu!\n", cidade1);
            else if (pibPerCapita2 > pibPerCapita1)
                printf("%s venceu!\n", cidade2);
            else
                printf("Empate!\n");
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }

    return 0;
}
