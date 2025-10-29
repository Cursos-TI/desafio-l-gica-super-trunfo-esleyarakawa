/* super_trunfo_mestre.c
   Nível MESTRE - Comparações Avançadas com Atributos Múltiplos
   Inclui PIB per capita como atributo extra (opção 6)

   Autor: (seu nome)
   Data: (hoje)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Estrutura para armazenar dados de cada país/carta */
typedef struct {
    char nome[50];
    long long populacao;   // habitantes
    double area;           // km^2
    double pib;            // PIB (unidade arbitrária: trilhões ou bilhões, consistente nas cartas)
    int pontos_turisticos;
    /* valores calculados */
    double densidade;      // populacao / area
    double pib_per_capita; // pib / populacao
} Carta;

/* Função para limpar o buffer de entrada (quando scanf falha) */
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

/* Obtém o valor do atributo conforme opção escolhida (1..6).
   Retorna o valor como double para facilitar soma/comparações.
*/
double obter_valor_atributo(const Carta *c, int opcao) {
    switch (opcao) {
        case 1: return (double)c->populacao;
        case 2: return c->area;
        case 3: return c->pib;
        case 4: return (double)c->pontos_turisticos;
        case 5: return c->densidade;
        case 6: return c->pib_per_capita;
        default: return 0.0;
    }
}

/* Retorna o nome legível do atributo */
const char* nome_do_atributo(int opcao) {
    switch (opcao) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Demografica";
        case 6: return "PIB per Capita";
        default: return "Desconhecido";
    }
}

/* Compara um atributo entre duas cartas e exibe o resultado individual.
   Para densidade (opcao 5), menor vence. Para os demais, maior vence.
   Retorna: 1 se carta1 vence, 2 se carta2 vence, 0 empate.
*/
int comparar_atributo(const Carta *c1, const Carta *c2, int opcao) {
    double v1 = obter_valor_atributo(c1, opcao);
    double v2 = obter_valor_atributo(c2, opcao);

    printf("\nAtributo: %s\n", nome_do_atributo(opcao));
    /* Imprime valores com formatação adequada */
    if (opcao == 1) { // populacao: inteiro grande
        printf("%s: %lld\n", c1->nome, c1->populacao);
        printf("%s: %lld\n", c2->nome, c2->populacao);
    } else if (opcao == 4) { // pontos turisticos: int
        printf("%s: %d\n", c1->nome, c1->pontos_turisticos);
        printf("%s: %d\n", c2->nome, c2->pontos_turisticos);
    } else {
        /* double: area, pib, densidade, pib per capita */
        printf("%s: %.6g\n", c1->nome, v1);
        printf("%s: %.6g\n", c2->nome, v2);
    }

    if (opcao == 5) { // densidade: menor vence
        if (v1 < v2) {
            printf("Vencedor no atributo (menor vence): %s\n", c1->nome);
            return 1;
        } else if (v2 < v1) {
            printf("Vencedor no atributo (menor vence): %s\n", c2->nome);
            return 2;
        } else {
            printf("Resultado do atributo: Empate!\n");
            return 0;
        }
    } else { // demais atributos: maior vence
        if (v1 > v2) {
            printf("Vencedor no atributo (maior vence): %s\n", c1->nome);
            return 1;
        } else if (v2 > v1) {
            printf("Vencedor no atributo (maior vence): %s\n", c2->nome);
            return 2;
        } else {
            printf("Resultado do atributo: Empate!\n");
            return 0;
        }
    }
}

/* Função principal */
int main() {
    /* Cartas pré-definidas (pode ajustar valores conforme desejar) */
    Carta carta1 = {
        "Brasil",
        213000000LL,
        8515767.0,
        1.8e12,   /* PIB em unidades monetárias (ex.: 1.8 trilhões) */
        50,
        0.0, /* densidade (calcular abaixo) */
        0.0  /* pib per capita (calcular abaixo) */
    };

    Carta carta2 = {
        "Argentina",
        45380000LL,
        2780400.0,
        450000000000.0, /* 0.45 trilhões = 450 bilhões */
        30,
        0.0,
        0.0
    };

    /* Calcula densidade e PIB per capita para ambas as cartas */
    carta1.densidade = (double)carta1.populacao / carta1.area;
    carta2.densidade = (double)carta2.populacao / carta2.area;

    carta1.pib_per_capita = carta1.pib / (double)carta1.populacao;
    carta2.pib_per_capita = carta2.pib / (double)carta2.populacao;

    int opcao1 = 0, opcao2 = 0;
    int leitura;
    int sair = 0;

    printf("=== SUPER TRUNFO - NIVEL MESTRE ===\n");
    printf("Compare duas cartas escolhendo DOIS atributos diferentes.\n\n");

    /* Loop principal para permitir várias rodadas até o usuário sair */
    while (!sair) {
        /* Menu para escolher o primeiro atributo */
        do {
            printf("\nEscolha o PRIMEIRO atributo para comparar:\n");
            printf("1 - Populacao\n");
            printf("2 - Area\n");
            printf("3 - PIB\n");
            printf("4 - Pontos Turisticos\n");
            printf("5 - Densidade Demografica (menor vence)\n");
            printf("6 - PIB per Capita\n");
            printf("7 - Sair do programa\n");
            printf("Opcao: ");

            leitura = scanf("%d", &opcao1);
            if (leitura != 1) {
                printf("Entrada invalida! Digite um numero de 1 a 7.\n");
                limpar_buffer();
                opcao1 = 0;
                continue;
            }

            if (opcao1 < 1 || opcao1 > 7) {
                printf("Opcao invalida! Tente novamente.\n");
                opcao1 = 0;
            } else if (opcao1 == 7) {
                sair = 1;
                break;
            }
        } while (opcao1 == 0);

        if (sair) {
            printf("Saindo... Obrigado por jogar!\n");
            break;
        }

        /* Menu dinâmico para o segundo atributo:
           Não mostra a opção escolhida em opcao1 */
        do {
            printf("\nEscolha o SEGUNDO atributo para comparar (diferente do %s):\n", nome_do_atributo(opcao1));

            /* Mostra somente as opções válidas; alternativa simples: sempre mostra 1-6, mas verifica igualdade
               Aqui implementamos uma versão onde mostramos todas e avisamos se escolher o mesmo. */
            printf("1 - Populacao\n");
            printf("2 - Area\n");
            printf("3 - PIB\n");
            printf("4 - Pontos Turisticos\n");
            printf("5 - Densidade Demografica (menor vence)\n");
            printf("6 - PIB per Capita\n");
            printf("Opcao: ");

            leitura = scanf("%d", &opcao2);
            if (leitura != 1) {
                printf("Entrada invalida! Digite um numero de 1 a 6.\n");
                limpar_buffer();
                opcao2 = 0;
                continue;
            }

            if (opcao2 < 1 || opcao2 > 6) {
                printf("Opcao invalida! Tente novamente.\n");
                opcao2 = 0;
            } else if (opcao2 == opcao1) {
                printf("Voce ja escolheu '%s'. Escolha um atributo diferente.\n", nome_do_atributo(opcao1));
                opcao2 = 0;
            }
        } while (opcao2 == 0);

        /* Exibe resumo das escolhas */
        printf("\nResumo da escolha:\n");
        printf("Carta 1: %s\n", carta1.nome);
        printf("Carta 2: %s\n", carta2.nome);
        printf("Atributos escolhidos: 1) %s  2) %s\n", nome_do_atributo(opcao1), nome_do_atributo(opcao2));

        /* Comparações individuais - também mostramos quem ganhou cada atributo */
        int resultado1 = comparar_atributo(&carta1, &carta2, opcao1);
        int resultado2 = comparar_atributo(&carta1, &carta2, opcao2);

        /* Soma dos valores dos atributos (valores brutos) */
        double v1_op1 = obter_valor_atributo(&carta1, opcao1);
        double v2_op1 = obter_valor_atributo(&carta2, opcao1);
        double v1_op2 = obter_valor_atributo(&carta1, opcao2);
        double v2_op2 = obter_valor_atributo(&carta2, opcao2);

        double soma_carta1 = v1_op1 + v1_op2;
        double soma_carta2 = v2_op1 + v2_op2;

        printf("\n--- Resultado final pela SOMA dos atributos (valores brutos) ---\n");
        printf("%s soma: %.6g\n", carta1.nome, soma_carta1);
        printf("%s soma: %.6g\n", carta2.nome, soma_carta2);

        if (soma_carta1 > soma_carta2) {
            printf("\nResultado final: %s venceu!\n", carta1.nome);
        } else if (soma_carta2 > soma_carta1) {
            printf("\nResultado final: %s venceu!\n", carta2.nome);
        } else {
            printf("\nResultado final: Empate!\n");
        }

        /* Exemplo de uso do operador ternário (simples): definir mensagem de encerramento da rodada */
        const char *msg_rodada = (soma_carta1 == soma_carta2) ? "Round empatado." : "Round finalizado.";
        printf("\n%s\n", msg_rodada);

        /* Pergunta ao usuário se deseja jogar outra rodada ou sair */
        int escolha_continue = 0;
        do {
            printf("\nDeseja jogar outra rodada? 1 - Sim | 2 - Nao (Sair): ");
            leitura = scanf("%d", &escolha_continue);
            if (leitura != 1) {
                printf("Entrada invalida. Digite 1 ou 2.\n");
                limpar_buffer();
                escolha_continue = 0;
            } else if (escolha_continue != 1 && escolha_continue != 2) {
                printf("Opcao invalida. Digite 1 ou 2.\n");
                escolha_continue = 0;
            }
        } while (escolha_continue == 0);

        if (escolha_continue == 2) {
            sair = 1;
            printf("Obrigado por jogar! Ate a proxima.\n");
        } else {
            /* reinicia as escolhas para nova rodada */
            opcao1 = 0;
            opcao2 = 0;
        }
    } /* fim while principal */

    return 0;
}