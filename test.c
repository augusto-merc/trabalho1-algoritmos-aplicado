
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DRUGS 10


typedef struct 
{
    char *name;
    int *price;
} Drug;

Drug *drugs = NULL;  // Usaremos alocação dinâmica
int total_drugs = 0;

// Funções
void cadastrar_remedio();
int buscar_remedio(const char *price);
void busca_binaria(const char *price);
void salvar_dados();
void menu();

int main() {
    drugs = (Drug *)malloc(MAX_DRUGS * sizeof(Drug));
    if (!drugs) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }
    menu();
    free(drugs);
    return 0;
}
void menu() {
    int option;
    do {
        printf("\nMenu:\n");
        printf("1. Cadastro\n");
        printf("2. Busca\n");
        printf("3. Salvar dados em arquivo\n");
        printf("4. Encerrar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                cadastrar_remedio();
                break;
            case 2: {
                char preco_remedio[12];
                printf("Digite o nome para busca: ");
                scanf("%s", name);
                break;
            }
            case 3:
                salvar_dados();
                break;
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);
}
void cadastrar_remedio() {
    if (total_remedios >= MAX_remedioS) {
        printf("Limite de remedios atingido!\n");
        return;
    }
    remedio *novo_remedio = &remedios[total_remedios];
    printf("Digite o nome: ");
    scanf("%s", novo_remedio->nome);
    printf("Digite o preco_remedio: ");
    scanf("%s", novo_remedio->preco_remedio);
    total_remedios++;
    printf("remedio cadastrado com sucesso!\n");
}
int buscar_remedio(const char *nome) {
    for (int i = 0; i < total_remedios; i++) {
        if (strcmp(remedios[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}
void update_medicine(int index, const char *price_medice) {
    printf("Digite o nome do remedio que deseja atualizar: ");
    int temp = buscar_medicine(medicines[index].name);
    if (temp == -1) {
        printf("medicine nao encontrado!\n");
        return;
    }
    else {
        printf("Digite o novo name: ");
        scanf("%11s", medicines[index].name);
        printf("Digite o novo price_medicine: ");
        scanf("%11s", medicines[index].price_medicine);
        printf("medicine atualizado com sucesso!\n");
        return;
    }
}
void remove_medicine() {
    char name[12];
    printf("Digite o name para remover: ");
    if (scanf("%11s", name) != 1) {
        printf("Erro ao ler name! Tente novamente.\n");
        while (getchar() != '\n');
    } else {
        int index = buscar_medicine(name);
        if (index != -1) {
            for (int i = index; i < total_medicines - 1; i++) {
                medicines[i] = medicines[i + 1];
            }
            total_medicines--;
            printf("medicine removido com sucesso!\n");
        } else {
            printf("medicine nao encontrado!\n");
        }
    }
}