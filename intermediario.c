#include <stdio.h>   // Biblioteca para entrada e saída. Para printf e scanf.
#include <string.h>  // Biblioteca para manipulação de strings.

/*
Variáveis

- Cada carta tem suas próprias variáveis (estado1, codigo1, nomeCidade1, etc.).

- Strings (char[]) foram usadas para código e nome da cidade.

- Tipos numéricos (int e float) foram usados para população, área, PIB e pontos turísticos. As novas variáveis densidade e pibpercapita utilizam tipos numéricos float.

- Entrada de dados (scanf)

- Para o estado, usamos " %c" → o espaço antes do %c evita que o Enter anterior seja lido.

- Para o código da carta, usamos "%s" → lê uma string até o espaço.

- Para o nome da cidade, usamos " %[^\n]" → permite ler nomes compostos (ex.: Rio de Janeiro).

- Para os demais dados (int e float), usamos os formatos adequados.

Saída formatada (printf)

- Cada campo da carta é exibido de forma clara e individual, sendo ambas exibidas ao final da entrada da última carta.

- O %.2f garante que float (área e PIB) apareçam com duas casas decimais.

- Neste programa para que ocorra a comparação entre as cartas o participante deve inserir os dados que serão impressos e postriormente comparados. Optei por não possibilitar escolher qual dos dados será comparado para fazer a comparação.

*/

int main() {
    // Declaração das variáveis da Carta 1
    char estado1;             
    char codigo1[4];          
    char nomeCidade1[50];     
    unsigned long int populacao1; // modifiquei para unsigned long int para possibilitar números maiores          
    float area1;              
    float pib1;               
    int pontosTuristicos1; 
    float densidade1;
    float pibPerCapita1;
    float superPoder1;   

    // Declaração das variáveis da Carta 2
    char estado2;             
    char codigo2[4];          
    char nomeCidade2[50];     
    unsigned long int populacao2; // modifiquei para unsigned long int para possibilitar números maiores            
    float area2;              
    float pib2;               
    int pontosTuristicos2; 
    float densidade2;
    float pibPerCapita2;  
    float superPoder2;     

    // Entrada de dados da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    printf("Populacao: ");
    scanf("%Iu", &populacao1);

    printf("Area (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em milhoes de reais): ");
    scanf("%f", &pib1);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // Agora calcular a densidade populacional e o PIB per capita da carta 1
    printf("\n=== Cálculos da Carta 1 ===\n"); 
    densidade1 = (float) populacao1/area1;
    pibPerCapita1 = (pib1 * 1000000) / (float) populacao1; // conversão de milhões para reais; multipliquei o PIB por um milhão para converter em reais antes de dividir pela população
    superPoder1 = (float) populacao1 + pib1 + (float) pontosTuristicos1 + pibPerCapita1 + (1.0f / densidade1);

    // Saída da carta 1
    printf("\n=== Carta 1 ===\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f milhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade populacional: %.2f hab/km2 \n", densidade1);
    printf("PIB per capita: %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    // Entrada de dados da Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Codigo da Carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Populacao: ");
    scanf("%Iu", &populacao2);

    printf("Area (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em milhoes de reais): ");
    scanf("%f", &pib2);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // Agora calcular a densidade populacional e o PIB per capita da carta 2
    printf("\n=== Cálculos da Carta 2 ===\n"); 
    densidade2 = populacao2/area2;
    pibPerCapita2 = (pib2 * 1000000) / populacao2; // conversão de milhões para reais; multipliquei o PIB por um milhão para converter em reais antes de dividir pela população
    superPoder2 = (float) populacao2 + pib2 + (float) pontosTuristicos2 + pibPerCapita2 + (1.0f / densidade2);

    // Saída da carta 2
    printf("\n=== Carta 2 ===\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f milhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade populacional: %.2f hab/km2 \n", densidade2);
    printf("PIB per capita: %.2f reis\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // Função para comparar atributos em que o MAIOR valor vence
int compararMaior(float a, float b) {
    return a > b ? 1 : 0;   // 1 se Carta 1 venceu, 0 se Carta 2 venceu
}

// Função para comparar atributos em que o MENOR valor vence (densidade populacional)
int compararMenor(float a, float b) {
    return a < b ? 1 : 0;   // 1 se Carta 1 venceu, 0 se Carta 2 venceu
}

    // Aqui vou comparar as cartas
    printf("\n===Comparando as cartas===\n");
    
    int resultado;

    resultado = compararMaior((float) populacao1, (float) populacao2);
    printf("Populacao: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    resultado = compararMaior(area1, area2);
    printf("Area: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    resultado = compararMaior(pib1, pib2);
    printf("PIB: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    resultado = compararMaior((float) pontosTuristicos1, (float) pontosTuristicos2);
    printf("Pontos Turisticos: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    resultado = compararMenor(densidade1, densidade2);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    resultado = compararMaior(pibPerCapita1, pibPerCapita2);
    printf("PIB per Capita: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    resultado = compararMaior(superPoder1, superPoder2);
    printf("Super Poder: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    return 0;
}
