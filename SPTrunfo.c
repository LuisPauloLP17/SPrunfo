#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    int codigo;
    char nome [50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

void calcular_metricas(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;

    carta->pib_per_capita = (carta->pib * 1000000000.0) /carta->populacao;

    carta->super_poder = (float)carta->populacao +
    carta->area +
    carta->pib +
    (float)carta->pontos_turisticos +
    carta->pib_per_capita +
    (1.0 / carta->densidade_populacional);
}

void ler_carta(Carta *carta){
    printf("digite o estado: ");
    scanf("%[^\n]", carta->estado);

    prinft("digite o codigo: ");
    scanf("%d", &carta->codigo);

    printf("digite o nome: ");
    scanf(" %[^\n]", carta->nome);

    printf("digite a população: ");
    scanf("%lu", &carta->populacao);

    printf("digite a área (Km²) ");
    scanf("%F", &carta->area);

    printf("digite o pib (bilhões): ");
    scanf("%f", &carta->pib);

    printf("digite o numeros de pontos turisticos: ");
    scanf("%d", &carta->pontos_turisticos);

    calcular_metricas(carta);
}


void comparar_cartas(Carta carta1, Carta carta2){
    printf("\ncomparação de cartas:\n");

    printf("população: carta %d venceu (%d)\n"),
        (carta1.populacao > carta2.populacao) ? 1 : 2,
        (carta1.populacao > carta2.populacao) ? 1 : 0;

    printf("área: carta %d venceu (%d)\n"),
         (carta1.area > carta2.area) ? 1 : 2,
         (carta1.area > carta2.area) ? 1 : 0;

         printf("PIB: carta %d venceu (%d)\n"),
            (carta1.pib > carta2.pib) ? 1 : 2,
            (carta1.pib > carta2.pib) ? 1 : 0;

            printf("Pontos Turisticos: carta %d venceu (%d)\n"),
            (carta1.pontos_turisticos > carta2.pontos_turisticos) ? 1 : 2,
            (carta1.pontos_turisticos > carta2.pontos_turisticos) ? 1 : 0;

            printf("Densidade populacional: carta %d venceu (%d)\n"),
            (carta1.densidade_populacional > carta2.densidade_populacional) ? 1 : 2,
            (carta1.densidade_populacional > carta2.densidade_populacional) ? 1 : 0;

            printf("PIB Per Capita: carta %d venceu (%d)\n"),
            (carta1.pib_per_capita > carta2.pib_per_capita) ? 1 : 2,
            (carta1.pib_per_capita > carta2.pib_per_capita) ? 1 : 0;

            printf("Super Poder carta %d venceu (%d)\n"),
            (carta1.super_poder > carta2.super_poder) ? 1 : 2,
            (carta1.super_poder > carta2.super_poder) ? 1 : 0;
}

int main(){
    Carta carta1, carta2;

    printf("===Dados de Carta 1 ===\n");
    ler_carta(&carta1);

    printf("===Dados De Carta 2 ===\n");
    ler_carta(&carta2);

    comparar_cartas(carta1, carta2);

    return 0;
}