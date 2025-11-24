#include <stdio.h>


// etapa 4

struct Produto {
    char nome[50];
    int quantidade;
    float preco;
    float total;
};


// etapa 5

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

// desconto - etapa 2
float aplicarDesconto(float total) {
    if (total >= 100) {
        printf("\nDesconto de 10%% aplicado!\n");
        return total * 0.90;
    } else {
        printf("\nNenhum desconto aplicado.\n");
        return total;
    }
}


void listarProdutos(struct Produto lista[], int qtd) {
    int i;

    printf("\nProdutos\n");

    for (i = 0; i < qtd; i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("Nome: %s\n", lista[i].nome);
        printf("Quantidade: %d\n", lista[i].quantidade);
        printf("Preço: R$ %.2f\n", lista[i].preco);
        printf("Total: R$ %.2f\n", lista[i].total);
    }
}

// nota fiscal (produtos + total + desconto)
void emitirNotaFiscal(struct Produto lista[], int qtd) {
    float totalBruto, totalFinal;

    listarProdutos(lista, qtd);

    totalBruto = calcularTotal(lista, qtd);
    printf("\nTotal bruto: R$ %.2f\n", totalBruto);

    totalFinal = aplicarDesconto(totalBruto);
    printf("Total final: R$ %.2f\n", totalFinal);
}

// PROGRAMA

int main() {

    
    struct Produto lista[100];
    int qtd = 0;
    int adicionais;
    int opcao;
    int i;

    printf("Mercadinho Fiu Fiu\n");

    // etapa 1
    printf("\nCadastre o primeiro produto\n");
    adicionarProduto(lista, &qtd);

    // etapa 3
    printf("\nDeseja cadastrar quantos produtos adicionais? ");
    scanf("%d", &adicionais);

    for (i = 0; i < adicionais; i++) {
        adicionarProduto(lista, &qtd);
    }

    // etapa 5
    do {
        printf("\nMenu\n");
        printf("1 - Adicionar novo produto\n");
        printf("2 - Listar produtos cadastrados\n");
        printf("3 - Emitir nota fiscal\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(lista, &qtd);
                break;
            case 2:
                listarProdutos(lista, qtd);
                break;
            case 3:
                emitirNotaFiscal(lista, qtd);
                break;
            case 4:
                printf("\nEncerrando o sistema...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }

    } while (opcao != 4);

    return 0;
}