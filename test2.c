#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10  // Definindo o limite de registros

// Estrutura para armazenar os dados (nome e valor numérico)
typedef struct {
    char *name;
    float value;  // Usaremos um valor numérico com ponto flutuante (float)
} Item;

Item *items = NULL;  // Ponteiro para a matriz de registros
int total_items = 0; // Contador de itens cadastrados

// Funções
void cadastrar_dado();
void imprimir_dados();
int buscar_dado(const char *name, float value);
void remover_dado(int position);
void atualizar_dado(int position);
void menu();

int main() {
    items = (Item *)malloc(MAX_ITEMS * sizeof(Item));
    if (!items) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    menu();
    
    // Liberando a memória alocada
    for (int i = 0; i < total_items; i++) {
        free(items[i].name);
    }
    free(items);
    return 0;
}

void menu() {
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar dados\n");
        printf("2. Imprimir dados\n");
        printf("3. Buscar dado\n");
        printf("4. Remover dado\n");
        printf("5. Atualizar dado\n");
        printf("6. Encerrar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_dado();
                break;
            case 2:
                imprimir_dados();
                break;
            case 3: {
                char name[100];
                float value;
                printf("Digite o nome ou valor para busca: ");
                printf("Nome: ");
                scanf("%s", name);
                printf("Valor: ");
                scanf("%f", &value);
                int pos = buscar_dado(name, value);
                if (pos != -1) {
                    printf("Dado encontrado na posição: %d\n", pos);
                } else {
                    printf("Dado não encontrado.\n");
                }
                break;
            }
            case 4: {
                int pos;
                printf("Digite a posição para remover: ");
                scanf("%d", &pos);
                remover_dado(pos);
                break;
            }
            case 5: {
                int pos;
                printf("Digite a posição para atualizar: ");
                scanf("%d", &pos);
                atualizar_dado(pos);
                break;
            }
            case 6:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 6);
}

void cadastrar_dado() {
    if (total_items >= MAX_ITEMS) {
        printf("Limite de registros atingido!\n");
        return;
    }

    // Alocando memória para o nome
    items[total_items].name = (char *)malloc(100 * sizeof(char));
    
    printf("Digite o nome: ");
    scanf("%s", items[total_items].name);
    
    printf("Digite o valor numérico: ");
    scanf("%f", &items[total_items].value);
    
    total_items++;
    printf("Dado cadastrado com sucesso!\n");
}

void imprimir_dados() {
    if (total_items == 0) {
        printf("Nenhum dado cadastrado.\n");
        return;
    }

    printf("\nLista de dados cadastrados:\n");
    for (int i = 0; i < total_items; i++) {
        printf("Posição %d - Nome: %s, Valor: %.2f\n", i, items[i].name, items[i].value);
    }
}

int buscar_dado(const char *name, float value) {
    for (int i = 0; i < total_items; i++) {
        if (strcmp(items[i].name, name) == 0 || items[i].value == value) {
            return i;  // Retorna a posição do dado encontrado
        }
    }
    return -1;  // Retorna -1 se não encontrar
}

void remover_dado(int position) {
    if (position < 0 || position >= total_items) {
        printf("Posição inválida!\n");
        return;
    }

    // Liberando a memória do nome
    free(items[position].name);

    // Deslocando os elementos para preencher o espaço da posição removida
    for (int i = position; i < total_items - 1; i++) {
        items[i] = items[i + 1];
    }

    total_items--;
    printf("Dado removido com sucesso!\n");
}

void atualizar_dado(int position) {
    if (position < 0 || position >= total_items) {
        printf("Posição inválida!\n");
        return;
    }

    printf("Digite o novo nome: ");
    scanf("%s", items[position].name);
    
    printf("Digite o novo valor: ");
    scanf("%f", &items[position].value);

    printf("Dado atualizado com sucesso!\n");
}
