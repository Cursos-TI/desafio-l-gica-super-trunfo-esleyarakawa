#include <stdio.h>
#include <string.h>

int main() {
    // Dados das cartas (fixos conforme desafio)
    char pais1[] = "Brasil";
    int populacao1 = 213000000;
    float area1 = 8515767.0;
    float pib1 = 1.8; // PIB em trilhões
    int pontosTuristicos1 = 50;
    float densidade1 = populacao1 / area1;

    char pais2[] = "Argentina";
    int populacao2 = 45380000;
    float area2 = 2780400.0;
    float pib2 = 0.45;
    int pontosTuristicos2 = 30;
    float densidade2 = populacao2 / area2;

    int opcao;

    do {
        printf("\n=== SUPER TRUNFO - MENU DE COMPARACAO ===\n");
        printf("1 - Comparar Populacao\n");
        printf("2 - Comparar Area\n");
        printf("3 - Comparar PIB\n");
        printf("4 - Comparar Pontos Turisticos\n");
        printf("5 - Comparar Densidade Demografica\n");
        printf("6 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nComparando POPULACAO:\n");
                printf("%s: %d habitantes\n", pais1, populacao1);
                printf("%s: %d habitantes\n", pais2, populacao2);
                if(populacao1 > populacao2)
                    printf("Vencedor: %s!\n", pais1);
                else if(populacao2 > populacao1)
                    printf("Vencedor: %s!\n", pais2);
                else
                    printf("Empate!\n");
                break;

            case 2:
                printf("\nComparando AREA:\n");
                printf("%s: %.2f km²\n", pais1, area1);
                printf("%s: %.2f km²\n", pais2, area2);
                if(area1 > area2)
                    printf("Vencedor: %s!\n", pais1);
                else if(area2 > area1)
                    printf("Vencedor: %s!\n", pais2);
                else
                    printf("Empate!\n");
                break;

            case 3:
                printf("\nComparando PIB:\n");
                printf("%s: %.2f trilhoes\n", pais1, pib1);
                printf("%s: %.2f trilhoes\n", pais2, pib2);
                if(pib1 > pib2)
                    printf("Vencedor: %s!\n", pais1);
                else if(pib2 > pib1)
                    printf("Vencedor: %s!\n", pais2);
                else
                    printf("Empate!\n");
                break;

            case 4:
                printf("\nComparando PONTOS TURISTICOS:\n");
                printf("%s: %d pontos\n", pais1, pontosTuristicos1);
                printf("%s: %d pontos\n", pais2, pontosTuristicos2);
                if(pontosTuristicos1 > pontosTuristicos2)
                    printf("Vencedor: %s!\n", pais1);
                else if(pontosTuristicos2 > pontosTuristicos1)
                    printf("Vencedor: %s!\n", pais2);
                else
                    printf("Empate!\n");
                break;

            case 5:
                printf("\nComparando DENSIDADE DEMOGRAFICA (MENOR VENCE):\n");
                printf("%s: %.4f hab/km²\n", pais1, densidade1);
                printf("%s: %.4f hab/km²\n", pais2, densidade2);
                if(densidade1 < densidade2)
                    printf("Vencedor: %s!\n", pais1);
                else if(densidade2 < densidade1)
                    printf("Vencedor: %s!\n", pais2);
                else
                    printf("Empate!\n");
                break;

            case 6:
                printf("\nSaindo... Obrigado por jogar!\n");
                break;

            default:
                printf("\nOpcao invalida! tente novamente.\n");
        }

    } while(opcao != 6);

    return 0;
}