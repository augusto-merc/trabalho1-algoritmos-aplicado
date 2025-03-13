/*
    Autores:
    - RA: 198020 | Nome: Augusto Cezar da Silva Mercado
    - RA: 197590 | Nome: André Gonçalves da Silva
    - RA: 197459 | Nome: Abner Matheus Moraes Saconi
*/

// Bibliotecas
#include <stdio.h>

// Variáveis Globais
    //  Projeto 1
const int size = 4; 
int matrix[size][size]; 

    // Projeto 3
#define MAX_MECINE 10  // Definindo o limite de registros

typedef struct 
{
    char *name;
    double price;
} Medicine;

Medicine *medicines = NULL;  // Ponteiro para a matriz de registros
int total_medicines = 0; // Contador de itens cadastrados

// Módulos e Procedimentos
//  Projeto 1
void inputMatrix(); // Procedimento
int magic_square(int matrix[size][size]); // Módulo

// Projeto 3


int main() 
{

    int option = 1;

    while (option != 0) // Loop do menu
    { 
        printf("Insira a sua opcao: \n");
        printf("0 - Sair\n");
        printf("1 - Projeto 1\n");
        printf("3 - Projeto 3\n");
        scanf("%d", &option);
        
        switch (option) // Menu
        { 
            case 1: // Abre o primeiro projeto
                printf("Programa de verificacao de quadrados magicos\n");
                inputMatrix();
                printf("O quadrado %s\n", magic_square(matrix) ? "eh magico" : "nao eh magico");
                break;
            case 3: // Abre o terceiro projeto
                printf("Insira a opcao que deseja\n");
                break;
            case 0: // Sai do programa
                printf("Saindo...\n");
                break;
            default: 
                printf("Opcao invalida\n");
                break;
        }
    }

    return 0;
}


// Projeto 1
void inputMatrix() // Faz a leitura do input da matriz salvando os dados na variável global
{
    printf("Insira os elementos da matriz %dx%d \n\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

int magic_square(int matrix[size][size]) // Função que verifica se uma matriz é um quadrado mágico.
// Retorna 1 (true) se for um quadrado mágico, 0 (false) caso contrário.
{
    int sum_reference_row = 0, sum_reference_column = 0;
    int sum_reference_d1 = 0, sum_reference_d2 = 0;

    for(int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            sum_reference_row += matrix[i][j];
            sum_reference_column += matrix[j][i];
            if (i == 0)
            {
                sum_reference_d1 += matrix[j][j];
                sum_reference_d2 += matrix[j][size-j-1];
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


// Projeto 3
void project3Menu() 
{
    int option;
    do 
    {
        printf("Projeto 3\n");
        printf("\nMenu:\n");
        printf("1. Cadastrar dados\n");
        printf("2. Imprimir dados\n");
        printf("3. Buscar dado\n");        
        printf("4. Remover dado\n");
        printf("5. Atualizar dado\n");
        printf("6. Encerrar\n");
        printf("Escolha uma opção: ");

        scanf("%d", &option);

        switch (option) {
            
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (option != 6);
}

