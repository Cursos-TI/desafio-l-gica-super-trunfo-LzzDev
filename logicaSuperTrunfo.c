#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
};

void cadastrarCarta(struct Carta *carta) {
    printf("\nCadastro de Carta:\n");
    printf("Estado: ");
    scanf(" %[^\n]", carta->estado);

    printf("Código da carta: ");
    scanf(" %[^\n]", carta->codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->nome);

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    if (carta->area != 0)
        carta->densidade = carta->populacao / carta->area;
    else
        carta->densidade = 0;
}

void exibirCarta(struct Carta carta) {
    printf("\n📄 Carta - %s (%s)\n", carta.nome, carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade);
}

void compararCartas(struct Carta c1, struct Carta c2, char atributo[]) {
    printf("\n🔍 Comparando pelo atributo: %s\n", atributo);

    if (strcmp(atributo, "populacao") == 0) {
        if (c1.populacao > c2.populacao)
            printf("🏆 Cidade vencedora: %s\n", c1.nome);
        else if (c2.populacao > c1.populacao)
            printf("🏆 Cidade vencedora: %s\n", c2.nome);
        else
            printf("⚖️ Empate!\n");
    }
    else if (strcmp(atributo, "area") == 0) {
        if (c1.area > c2.area)
            printf("🏆 Cidade vencedora: %s\n", c1.nome);
        else if (c2.area > c1.area)
            printf("🏆 Cidade vencedora: %s\n", c2.nome);
        else
            printf("⚖️ Empate!\n");
    }
    else if (strcmp(atributo, "pib") == 0) {
        if (c1.pib > c2.pib)
            printf("🏆 Cidade vencedora: %s\n", c1.nome);
        else if (c2.pib > c1.pib)
            printf("🏆 Cidade vencedora: %s\n", c2.nome);
        else
            printf("⚖️ Empate!\n");
    }
    else if (strcmp(atributo, "pontos") == 0) {
        if (c1.pontosTuristicos > c2.pontosTuristicos)
            printf("🏆 Cidade vencedora: %s\n", c1.nome);
        else if (c2.pontosTuristicos > c1.pontosTuristicos)
            printf("🏆 Cidade vencedora: %s\n", c2.nome);
        else
            printf("⚖️ Empate!\n");
    }
    else if (strcmp(atributo, "densidade") == 0) {
        if (c1.densidade < c2.densidade)
            printf("🏆 Cidade vencedora: %s (menor densidade)\n", c1.nome);
        else if (c2.densidade < c1.densidade)
            printf("🏆 Cidade vencedora: %s (menor densidade)\n", c2.nome);
        else
            printf("⚖️ Empate!\n");
    }
    else {
        printf("❌ Atributo inválido.\n");
    }
}

int main() {
    struct Carta carta1, carta2;
    char atributo[20];

    printf("🌍 SUPER TRUNFO - CIDADES BRASILEIRAS 🌆\n");

    cadastrarCarta(&carta1);
    cadastrarCarta(&carta2);

    exibirCarta(carta1);
    exibirCarta(carta2);

    printf("\nDigite o atributo para comparar (populacao, area, pib, pontos, densidade): ");
    scanf(" %[^\n]", atributo);

    compararCartas(carta1, carta2, atributo);

    return 0;
}
