#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta
typedef struct {
    char estado[50];
    int codigo;
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular métricas derivadas
void calcular_metricas(Carta *carta) {
    // Calcula densidade populacional (hab/km²)
    carta->densidade_populacional = carta->populacao / carta->area;

    // Calcula PIB per capita
    carta->pib_per_capita = (carta->pib * 1000000000.0) / carta->populacao;

    // Calcula super poder
    carta->super_poder = (float)carta->populacao +
                        carta->area +
                        carta->pib +
                        (float)carta->pontos_turisticos +
                        carta->pib_per_capita +
                        (1.0 / carta->densidade_populacional);
}

// Função para ler dados de uma carta
void ler_carta(Carta *carta) {
    printf("Digite o estado: ");
    scanf(" %[^\n]", carta->estado);

    printf("Digite o código: ");
    scanf("%d", &carta->codigo);

    printf("Digite o nome: ");
    scanf(" %[^\n]", carta->nome);

    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);

    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (bilhões): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);

    calcular_metricas(carta);
}

// Função para comparar atributos e retornar 1 se carta1 vence, 0 se carta2 vence
void comparar_cartas(Carta carta1, Carta carta2) {
    printf("\nComparação de Cartas:\n");

    // População
    printf("População: Carta %d venceu (%d)\n",
           (carta1.populacao > carta2.populacao) ? 1 : 2,
           (carta1.populacao > carta2.populacao) ? 1 : 0);

    // Área
    printf("Área: Carta %d venceu (%d)\n",
           (carta1.area > carta2.area) ? 1 : 2,
           (carta1.area > carta2.area) ? 1 : 0);

    // PIB
    printf("PIB: Carta %d venceu (%d)\n",
           (carta1.pib > carta2.pib) ? 1 : 2,
           (carta1.pib > carta2.pib) ? 1 : 0);

    // Pontos Turísticos
    printf("Pontos Turísticos: Carta %d venceu (%d)\n",
           (carta1.pontos_turisticos > carta2.pontos_turisticos) ? 1 : 2,
           (carta1.pontos_turisticos > carta2.pontos_turisticos) ? 1 : 0);

    // Densidade Populacional (menor vence)
    printf("Densidade Populacional: Carta %d venceu (%d)\n",
           (carta1.densidade_populacional < carta2.densidade_populacional) ? 1 : 2,
           (carta1.densidade_populacional < carta2.densidade_populacional) ? 1 : 0);

    // PIB per Capita
    printf("PIB per Capita: Carta %d venceu (%d)\n",
           (carta1.pib_per_capita > carta2.pib_per_capita) ? 1 : 2,
           (carta1.pib_per_capita > carta2.pib_per_capita) ? 1 : 0);

    // Super Poder
    printf("Super Poder: Carta %d venceu (%d)\n",
           (carta1.super_poder > carta2.super_poder) ? 1 : 2,
           (carta1.super_poder > carta2.super_poder) ? 1 : 0);
}

int main() {
    Carta carta1, carta2;

    printf("=== Dados da Carta 1 ===\n");
    ler_carta(&carta1);

    printf("\n=== Dados da Carta 2 ===\n");
    ler_carta(&carta2);

    comparar_cartas(carta1, carta2);

    return 0;
}