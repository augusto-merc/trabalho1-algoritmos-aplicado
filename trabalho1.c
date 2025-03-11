/*
    Autores:
    - RA: 198020 | Nome: Augusto Cezar da Silva Mercado
    - RA: 197590 | Nome: André Gonçalves da Silva
    - RA: 197459 | Nome: Abner Matheus Moraes Saconi
*/

// Bibliotecas
#include <stdio.h>

// Variáveis Globais
const int size = 4; 
int matrix[size][size]; 

// Módulos e Procedimentos
void inputMatrix(); // Procedimento
int magic_square(int matrix[size][size]); // Módulo

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
                magic_square(matrix);
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

