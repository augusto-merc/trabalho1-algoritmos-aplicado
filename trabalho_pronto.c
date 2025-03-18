/*
    Autores:
    - RA: 198020 | Nome: Augusto Cezar da Silva Mercado
    - RA: 197590 | Nome: André Gonçalves da Silva
    - RA: 197459 | Nome: Abner Matheus Moraes Saconi
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variáveis Globais Projeto 1
const int size = 4; 
int magicSquare[4][4];  // Variável global para a matriz

// Variáveis Globais Projeto 3
int total_medicines = 0; // Contador de remédios cadastrados

// Estrutura Remédios Projeto 3
typedef struct 
{
    char *name;
    double price;
} Medicine;

Medicine *medicines = NULL;  // Ponteiro de remédios

// Procedimentos e Módulos Projeto 1
void inputMatrix();  // Procedimento 
int magic_square(int matrix[size][size]);  // Módulo

// Procedimentos e Módulos Projeto 3
void createData(); // Procedimento 
void printMedicines(); // Procedimento 
int searchMedicineName(const char *name); // Módulo
int searchMedicinePrice(double price); // Módulo
void removeMedicine(int position); // Procedimento 
void updateMedicine(int position); // Procedimento 
void menuProject3();  // Procedimento 

int main() 
{

    int option = 1;
    while (option != 0) 
    {  // Loop do menu principal
        printf("Insira a sua opcao: \n");
        printf("0 - Sair\n");
        printf("1 - Projeto 1 (Quadrado Mágico)\n");
        printf("3 - Projeto 3 (Medicamentos)\n");
        printf("> ");
        scanf("%d", &option);

        switch (option) 
        {  
            case 1:  // Abre o Projeto 1
                printf("Programa de verificacao de quadrados magicos\n");
                inputMatrix();
                printf("O quadrado %s\n", magic_square(magicSquare) ? "eh magico" : "nao eh magico");
                break;
            case 3:  // Abre o Projeto 3
                menuProject3();
                break;
            case 0:  // Sai do programa
                printf("Saindo...\n");
                break;
            default: 
                printf("Opcao invalida\n");
                break;
        }
    }

    // Liberando a memória alocada para os medicamentos
    for (int i = 0; i < total_medicines; i++) 
    {
        free(medicines[i].name);
    }
    free(medicines);
    return 0;
}

// Funções do Projeto 1
void inputMatrix() // Procedimento para inserir os valores
{
    printf("Insira os elementos da matriz %dx%d \n\n", size, size);
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &magicSquare[i][j]);
        }
    }
}

int magic_square(int matrix[size][size]) 
{
    int sum_reference_row = 0, sum_reference_column = 0;
    int sum_reference_d1 = 0, sum_reference_d2 = 0;

    for(int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            sum_reference_row += magicSquare[i][j];
            sum_reference_column += magicSquare[j][i];
            if (i == 0) 
            {
                sum_reference_d1 += magicSquare[j][j];
                sum_reference_d2 += magicSquare[j][size-j-1];
            }
        }
        if (sum_reference_row != sum_reference_column || sum_reference_column != sum_reference_d1 || sum_reference_d1 != sum_reference_d2) 
        {
            return 0;
        }
        sum_reference_row = 0, sum_reference_column = 0;
    }

    return 1;
}

// Funções do Projeto 3
void menuProject3() 
{

    medicines = (Medicine *)malloc(total_medicines+1 * sizeof(Medicine)); // Aloca a memória do vetor de remédios
    if (!medicines)
    {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    int option;

    printf("Programa de registros de medicamentos!\n");
    do 
    {
        printf("\nMenu Projeto 3:\n");
        printf("1. Cadastrar dados\n");
        printf("2. Imprimir dados\n");
        printf("3. Buscar dado\n");
        printf("4. Remover dado\n");
        printf("5. Atualizar dado\n");
        printf("6. Encerrar projeto 3\n");
        printf("> ");
        scanf("%d", &option);

        switch (option) 
        {
            case 1:
                createData();
                break;
            case 2:
                printMedicines();
                break;
            case 3: 
            {
                char name[100];
                double price;
                int op, temp;
                printf("\nDeseja buscar pelo nome ou pelo preço do produto: \n");
                printf("1 - Nome\n");
                printf("2 - Preço\n");
                printf("> ");
                scanf("%d", &op);
                switch(op) 
                {
                    case 1:
                        printf("\nDigite o nome para busca: ");
                        scanf("%s", name);
                        temp = searchMedicineName(name);
                        if (temp == -1) 
                        {
                            printf("\nO produto %s nao foi encontrado!\n", name);
                            break;
                        }
                        printf("\nO produto %s foi encontrado!\n", name);
                        printf("Posição: %d\n", temp);
                        break;
                    case 2:
                        printf("\nDigite o preço para busca: ");
                        scanf("%lf", &price);
                        temp = searchMedicinePrice(price);
                        if (temp == -1) 
                        {
                            printf("\nO produto com preço %.2lf nao foi encontrado!\n", price);
                            break;
                        }
                        printf("\nO produto com preço %.2lf foi encontrado!\n", price);
                        printf("Posição: %d\n", temp);
                        break;
                    default:
                        printf("\nOpção inválida! Tente novamente.\n");
                }
                break;
            }
            case 4: 
            {
                int pos;
                printf("\nDigite a posição para remover: ");
                scanf("%d", &pos);
                removeMedicine(pos);
                break;
            }
            case 5: 
            {
                int pos;
                printf("\nDigite a posição para atualizar: ");
                scanf("%d", &pos);
                updateMedicine(pos);
                break;
            }
            case 6:
                printf("\nEncerrando o projeto 3...\n\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (option != 6);
}

void createData() 
{
    // Alocando memória para o nome do medicamento
    medicines[total_medicines].name = (char *)malloc(100 * sizeof(char));
    
    printf("\nDigite o nome do medicamento: ");
    scanf("%s", medicines[total_medicines].name);
    
    printf("Digite o preço do medicamento: ");
    scanf("%lf", &medicines[total_medicines].price);
    
    medicines = (Medicine *)realloc(medicines, ++total_medicines * sizeof(Medicine));

    if (!medicines) 
    {
        printf("\nErro na alocação de memória!\n");
        return;
    }

    printf("\nMedicamento cadastrado com sucesso!\n");
}

void printMedicines() 
{
    if (total_medicines == 0) 
    {
        printf("\nNenhum medicamento cadastrado.\n");
        return;
    }

    printf("\nLista de medicamentos cadastrados:\n");
    for (int i = 0; i < total_medicines; i++) 
    {
        printf("Posição %d - Nome: %s, Preço: %.2f\n", i, medicines[i].name, medicines[i].price);
    }
}

int searchMedicineName(const char *name) 
{
    for (int i = 0; i < total_medicines; i++) 
    {
        if (strcmp(medicines[i].name, name) == 0 ) 
        {
            return i;  // Retorna a posição do dado encontrado
        }
    }
    return -1;  // Retorna -1 se não encontrar
}

int searchMedicinePrice(double price) 
{
    for (int i = 0; i < total_medicines; i++) 
    {
        if (price == medicines[i].price) 
        {
            return i;  // Retorna a posição do dado encontrado
        }
    }
    return -1;  // Retorna -1 se não encontrar
}

void removeMedicine(int position) {
    if (position < 0 || position > total_medicines) 
    {
        printf("Posição inválida!\n");
        return;
    }

    // Liberando a memória do nome do medicamento
    free(medicines[position].name);

    // Deslocando os elementos para preencher o espaço da posição removida
    for (int i = position; i < total_medicines-1; i++) 
    {
        medicines[i] = medicines[i + 1];
    }

    total_medicines--;
    printf("Medicamento removido com sucesso!\n");
}

void updateMedicine(int position) 
{
    if (position < 0 || position >= total_medicines) 
    {
        printf("Posição inválida!\n");
        return;
    }

    int op;
    printf("O que deseja atualizar?\n");
    printf("1 - Nome\n");
    printf("2 - Preço\n");
    scanf("%d", &op);
    switch(op) 
    {
        case 1:
            printf("Digite o novo nome do medicamento: ");
            scanf("%s", medicines[position].name);
            printf("Medicamento atualizado com sucesso!\n");
            break;
        case 2:
            printf("Digite o novo preço do medicamento: ");
            scanf("%lf", &medicines[position].price);
            printf("Medicamento atualizado com sucesso!\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }
}
