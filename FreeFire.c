// Desafio Free Fire - tema2
// Nível novato

#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

typedef struct Item {
    char nome[50];
    char tipo[30];
    int quantidade;
} Item;

int main(){
    Item mochila[MAX_ITENS];
    int quantidade = 0;
    int opcao;

    do {
        printf("=========================================\n");
        printf("MOCHILA DE SOBREVIVENCIA - CODIGO DA ILHA\n");
        printf("=========================================\n");
        printf("Itens na Mochila: (%d/10)\n\n", quantidade);
        printf("1. Adicionar novo item (Loot)\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens na Mochila\n");
        printf("0. Sair\n");
        printf("------------------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); //limpa o buffer

        switch (opcao) {
            case 1: // adicionar
            if (quantidade >= MAX_ITENS){
                printf("Mochila cheia!\n");
            } else {
                printf("--- Adicionar novo Item ---\n");
                printf("Nome do item: ");
                fgets(mochila[quantidade].nome, 50, stdin);
                mochila[quantidade].nome[strcspn(mochila[quantidade].nome, "\n")] = 0;
                
                printf("Tipo do item (arma, municao, cura, etc.): ");
                fgets(mochila[quantidade].tipo, 30, stdin);
                mochila[quantidade].tipo[strcspn(mochila[quantidade].tipo, "\n")] = 0;
                                
                printf("Quantidade: ");
                scanf("%d", &mochila[quantidade].quantidade);
                getchar();

                quantidade++;
               printf("Item adicionado com sucesso!\n");
            }
            break;

            case 2: //remover
                if (quantidade == 0) {
                    printf("Mochila vazia!\n");
                } else {
                    char nomeRemover[50];
                    printf("Digite o nome do item a remover: ");
                    fgets(nomeRemover, 50, stdin);
                    nomeRemover[strcspn(nomeRemover, "\n")] = 0;

                    int encontrado = 0;
                    for (int i = 0; i < quantidade; i++) {
                        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                            for (int j = i; j < quantidade -1; j++) {
                                mochila[j] = mochila[j + 1];
                            }
                            quantidade--;
                            printf("Item removido!\n");
                            encontrado = 1;
                            break;
                        }
                    }
                    if (!encontrado)
                        printf("Item não encontrado!\n");
                }
                break;

                case 3: //listar
                if (quantidade == 0) {
                    printf("Nenhum item na mochila.\n");
                } else {
                    printf("\n=== ITENS NA MOCHILA (%d/10) ===\n", quantidade);
                    printf("%-20s %-20s %-10s\n", "NOME", "TIPO", "QTD");
                    for (int i = 0; i < quantidade; i++) {
                        printf("%-20s %-20s %-10d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
                    }
                }
                break;

                case 0:
                printf("Encerrando o programa...\n");
                break;
        
        default:
            printf("Opção inválida!\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}