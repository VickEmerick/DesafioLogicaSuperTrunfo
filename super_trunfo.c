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

    int atributo1 = 0, atributo2 = 0;
    float valor1_c1 = 0, valor1_c2 = 0, valor2_c1 = 0, valor2_c2 = 0;

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

    // Menu para escolher dois atributos
    printf("\nAtributos disponíveis:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n6 - PIB per Capita\n");

    printf("Escolha o primeiro atributo para comparação: ");
    scanf("%d", &atributo1);

    printf("\nEscolha o segundo atributo (diferente do primeiro): ");
    do {
        scanf("%d", &atributo2);
        if (atributo2 == atributo1) {
            printf("Atributo já escolhido. Escolha outro: ");
        }
    } while (atributo2 == atributo1);

    // Atribuir os valores dos atributos escolhidos
    switch (atributo1) {
        case 1: valor1_c1 = populacao1; valor1_c2 = populacao2; break;
        case 2: valor1_c1 = area1; valor1_c2 = area2; break;
        case 3: valor1_c1 = pib1; valor1_c2 = pib2; break;
        case 4: valor1_c1 = pontosTuristicos1; valor1_c2 = pontosTuristicos2; break;
        case 5: valor1_c1 = densidade1; valor1_c2 = densidade2; break;
        case 6: valor1_c1 = pibPerCapita1; valor1_c2 = pibPerCapita2; break;
        default: printf("Atributo inválido!\n"); return 1;
    }

    switch (atributo2) {
        case 1: valor2_c1 = populacao1; valor2_c2 = populacao2; break;
        case 2: valor2_c1 = area1; valor2_c2 = area2; break;
        case 3: valor2_c1 = pib1; valor2_c2 = pib2; break;
        case 4: valor2_c1 = pontosTuristicos1; valor2_c2 = pontosTuristicos2; break;
        case 5: valor2_c1 = densidade1; valor2_c2 = densidade2; break;
        case 6: valor2_c1 = pibPerCapita1; valor2_c2 = pibPerCapita2; break;
        default: printf("Atributo inválido!\n"); return 1;
    }

    // Exibir valores e calcular soma
    printf("\nComparando %s e %s com os atributos %d e %d\n", cidade1, cidade2, atributo1, atributo2);
    printf("%s: %.2f + %.2f\n", cidade1, valor1_c1, valor2_c1);
    printf("%s: %.2f + %.2f\n", cidade2, valor1_c2, valor2_c2);

    // Aplicar lógica (densidade menor vence)
    if (atributo1 == 5) {
        valor1_c1 = 1.0f / valor1_c1;
        valor1_c2 = 1.0f / valor1_c2;
    }
    if (atributo2 == 5) {
        valor2_c1 = 1.0f / valor2_c1;
        valor2_c2 = 1.0f / valor2_c2;
    }

    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    printf("\nResultado Final:\n");
    printf("%s: %.2f\n", cidade1, soma1);
    printf("%s: %.2f\n", cidade2, soma2);

    printf("Vencedor: %s\n", soma1 > soma2 ? cidade1 : soma2 > soma1 ? cidade2 : "Empate!");

    return 0;
}
