#include <stdio.h>
#include <locale.h>

// =======================
// ETAPA 4 - STRUCT PRODUTO
// =======================
struct Produto {
    char nome[50];
    int quantidade;
    float preco;
    float total;
};

// =======================
// ETAPA 5 - FUNÇÕES
// =======================
void adicionarProduto(struct Produto lista[], int *qtd) {

    printf("\nCadastro de Produto\n");

    printf("Nome do produto: ");
    scanf(" %[^\n]", lista[*qtd].nome);

    printf("Quantidade: ");
    scanf("%d", &lista[*qtd].quantidade);

    printf("Preço: ");
    scanf("%f", &lista[*qtd].preco);

    lista[*qtd].total = lista[*qtd].preco * lista[*qtd].quantidade;

    printf("Produto cadastrado!\n");

    (*qtd)++;
}

float calcularTotal(struct Produto lista[], int qtd) {
    float soma = 0;
    int i;

    for (i = 0; i < qtd; i++) {
        soma += lista[i].total;
    }

    return soma;
}

// Desconto baseado na etapa 2
float aplicarDesconto(float total) {
    if (total >= 200) {
        printf("\nDesconto de 15%% aplicado!\n");
        return total * 0.85;
    } else if (total >= 100) {
        printf("\nDesconto de 10%% aplicado!\n");
        return total * 0.90;
    } else if (total >= 50) {
        printf("\nDesconto de 5%% aplicado!\n");
        return total * 0.95;
    } else {
        printf("\nNenhum desconto aplicado.\n");
        return total;
    }
}

void listarProdutos(struct Produto lista[], int qtd) {
    int i;

    printf("\n=== Lista de Produtos ===\n");

    for (i = 0; i < qtd; i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("Nome: %s\n", lista[i].nome);
        printf("Quantidade: %d\n", lista[i].quantidade);
        printf("Preço: R$ %.2f\n", lista[i].preco);
        printf("Total: R$ %.2f\n", lista[i].total);
    }
}

void emitirNotaFiscal(struct Produto lista[], int qtd) {
    float totalBruto, totalFinal;

    listarProdutos(lista, qtd);

    totalBruto = calcularTotal(lista, qtd);
    printf("\nTotal bruto: R$ %.2f\n", totalBruto);

    totalFinal = aplicarDesconto(totalBruto);
    printf("Total final: R$ %.2f\n", totalFinal);
}



// =======================
// MAIN FINAL DO PROJETO
// =======================
int main() {
    setlocale(LC_ALL, "Portuguese");

    struct Produto lista[50];
    int qtd = 0;
    int opcao;

    do {
        printf("\n=====================================\n");
        printf("        SISTEMA DE PRODUTOS\n");
        printf("=====================================\n");
        printf("1 - Adicionar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Emitir nota fiscal\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(lista, &qtd);
                break;

            case 2:
                if (qtd == 0)
                    printf("\nNenhum produto cadastrado.\n");
                else
                    listarProdutos(lista, qtd);
                break;

            case 3:
                if (qtd == 0)
                    printf("\nNenhum produto para emitir nota.\n");
                else
                    emitirNotaFiscal(lista, qtd);
                break;

            case 4:
                printf("\nEncerrando...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }

    } while (opcao != 4);

    return 0;
}
