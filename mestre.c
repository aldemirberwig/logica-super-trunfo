#include <stdio.h>
#include <string.h>

// Estrutura para armazenar as informações de uma carta
struct Carta {
    char estado[3];
    char codigo[5];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para imprimir o nome do atributo baseado no índice
const char* nomeAtributo(int opcao) {
    switch (opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        default: return "Inválido";
    }
}

// Função para obter o valor de um atributo de uma carta
float valorAtributo(struct Carta c, int opcao) {
    switch (opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidadePopulacional;
        default: return -1;
    }
}

int main() {
    
    // Cadastro das cartas: os valores foram cadastrados seguindo as diretrizes da atividade proposta
    
    struct Carta carta1, carta2;

    // Carta 1
    strcpy(carta1.estado, "SP");
    strcpy(carta1.codigo, "A01");
    strcpy(carta1.cidade, "São Paulo");
    carta1.populacao = 12300000;
    carta1.area = 1521.11;
    carta1.pib = 699.28; // em milhões
    carta1.pontosTuristicos = 50;
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1000000) / carta1.populacao;

    // Carta 2
    strcpy(carta2.estado, "RJ");
    strcpy(carta2.codigo, "B02");
    strcpy(carta2.cidade, "Rio de Janeiro");
    carta2.populacao = 6748000;
    carta2.area = 1200.25;
    carta2.pib = 300.50; // em milhões
    carta2.pontosTuristicos = 30;
    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1000000) / carta2.populacao;

   
    // Menus dinâmicos visando calcular a densidade demográfica e o pib percapita e possibilitar a escolha dos atributos a serem comparados na disputa
   
    int atributo1, atributo2;

    printf("=== SUPER TRUNFO - NIVEL MESTRE ===\n");
    printf("Escolha o PRIMEIRO atributo:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n");
    printf("Opção: ");
    scanf("%d", &atributo1);

    if (atributo1 < 1 || atributo1 > 5) {
        printf("Opção inválida! Encerrando...\n");
        return 0;
    }

    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1) {
            printf("%d - %s\n", i, nomeAtributo(i));
        }
    }
    printf("Opção: ");
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Opção inválida! Encerrando...\n");
        return 0;
    }


    // Comparação de atributos escolhidos para indicar a carta vencedora

    float valor1_c1 = valorAtributo(carta1, atributo1);
    float valor1_c2 = valorAtributo(carta2, atributo1);

    float valor2_c1 = valorAtributo(carta1, atributo2);
    float valor2_c2 = valorAtributo(carta2, atributo2);

    // Regras: maior vence, exceto densidade (menor vence)
    int vencedor1 = (atributo1 == 5) ? 
        (valor1_c1 < valor1_c2 ? 1 : (valor1_c2 < valor1_c1 ? 2 : 0)) :
        (valor1_c1 > valor1_c2 ? 1 : (valor1_c2 > valor1_c1 ? 2 : 0));

    int vencedor2 = (atributo2 == 5) ? 
        (valor2_c1 < valor2_c2 ? 1 : (valor2_c2 < valor2_c1 ? 2 : 0)) :
        (valor2_c1 > valor2_c2 ? 1 : (valor2_c2 > valor2_c1 ? 2 : 0));

    // Soma dos valores (considerando regra invertida para densidade como simples soma de valor bruto)
    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    int vencedorFinal = (soma_c1 > soma_c2) ? 1 : (soma_c2 > soma_c1 ? 2 : 0);


    // Exibição dos resultados indicando a carta vencedora

    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("Cartas: %s (Carta 1) vs %s (Carta 2)\n\n", carta1.cidade, carta2.cidade);

    printf("Atributo 1: %s\n", nomeAtributo(atributo1));
    printf("%s: %.2f | %s: %.2f --> %s\n",
           carta1.cidade, valor1_c1, carta2.cidade, valor1_c2,
           vencedor1 == 1 ? carta1.cidade :
           vencedor1 == 2 ? carta2.cidade : "Empate");

    printf("\nAtributo 2: %s\n", nomeAtributo(atributo2));
    printf("%s: %.2f | %s: %.2f --> %s\n",
           carta1.cidade, valor2_c1, carta2.cidade, valor2_c2,
           vencedor2 == 1 ? carta1.cidade :
           vencedor2 == 2 ? carta2.cidade : "Empate");

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f | %s: %.2f\n", carta1.cidade, soma_c1, carta2.cidade, soma_c2);

    if (vencedorFinal == 1) {
        printf("\n>>> Carta 1 (%s) venceu a rodada!\n", carta1.cidade);
    } else if (vencedorFinal == 2) {
        printf("\n>>> Carta 2 (%s) venceu a rodada!\n", carta2.cidade);
    } else {
        printf("\n>>> Resultado final: Empate!\n");
    }

    return 0;
}
