#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Nível Novato - Posicionamento dos Navios
// Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
// Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
// Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

// Função que adiciona o navio
void addNavio(int navio[3], char orintacao, int linha, int coluna, int tabuleiro[10][10]) {
    // Validando a orientação do navio
    if (orintacao == 'x'){
        // Validando se na linha o navio vai ficar fora do tabuleiro
        if (linha >= 0 && linha <= 7)
        {
            // Validando se na coluna o navio vai ficar fora do tabuleiro
            if (coluna >= 0 && coluna <= 9)
            {
                // Alocando o Navio
                for (int i = 0; i < 3; i++)
                {
                    // validando se existe um navio na casa atual
                    if (tabuleiro[linha][coluna + i] == 0)
                    {
                        tabuleiro[linha][coluna + i] = navio[i];
                    } else
                    {
                        printf("Nessa posição já tem um navio\n");
                        break;
                    }
                    
                }
            } else {
                printf("Sua coordenada de coluna no eixo x deixa o navio fora do tabuleiro...\n");
            }
        } else
        {
            printf("Sua coordenada de linha no eixo x deixa o navio fora do tabuleiro...\n");
        }
    }
    else if (orintacao == 'd'){
        // Validando se na linha o navio vai ficar fora do tabuleiro
        if (linha >= 0 && linha <= 7)
        {
            // Validando se na coluna o navio vai ficar fora do tabuleiro
            if (coluna >= 0 && coluna <= 7)
            {
                // Alocando o Navio
                for (int i = 0; i < 3; i++)
                {
                    // validando se existe um navio na casa atual
                    if (tabuleiro[linha + i][coluna + i] == 0)
                    {
                        tabuleiro[linha + i][coluna + i] = navio[i];
                    } else
                    {
                        printf("Nessa posição já tem um navio\n");
                        break;
                    }
                    
                }
            } else {
                printf("Sua coordenada de coluna no eixo d (diagonal) deixa o navio fora do tabuleiro...\n");
            }
        } else
        {
            printf("Sua coordenada de linha no eixo d (diagonal) deixa o navio fora do tabuleiro...\n");
        }
    } else {
        if (linha >= 0 && linha <= 9)
        {
            if (coluna >= 0 && coluna <= 7)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (tabuleiro[linha + i][coluna] == 0)
                    {
                        tabuleiro[linha + i][coluna] = navio[i];
                    } else
                    {
                        printf("Nessa posição já tem um navio\n");
                        break;
                    }
                }
            } else
            {
                printf("Sua coordenada de coluna no eixo y deixa o navio fora do tabuleiro...\n");
            }
        } else
        {
            printf("Sua coordenada de linha no eixo y deixa o navio fora do tabuleiro...\n");
        }
        
    }
}

int main() {
    printf("TABULEIRO DE BATALHA NAVAL\n");

    // Inicializando o tabuleiro
    //        l   c
    int board[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Adicionando navios

    int navio[3] = {3, 3, 3};

    addNavio(navio, 'x', 0, 2, board); // Horizontal
    addNavio(navio, 'y', 4, 3, board); // Vertical

    addNavio(navio, 'd', 1, 2, board);
    addNavio(navio, 'd', 7, 1, board);

    // Exibindo o tabuleiro
    for (int square_l = 0; square_l < 10; square_l++)
    {
        for (int square_c = 0; square_c < 10; square_c++)
        {
            printf("%d ", board[square_l][square_c]);
        }
        printf("\n");
    }

    return 0;
}

// Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
// Sugestão: Expanda o tabuleiro para uma matriz 10x10.
// Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
// Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

// Nível Mestre - Habilidades Especiais com Matrizes
// Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
// Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
// Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

// Exemplos de exibição das habilidades:
// Exemplo para habilidade em cone:
// 0 0 1 0 0
// 0 1 1 1 0
// 1 1 1 1 1

// Exemplo para habilidade em octaedro:
// 0 0 1 0 0
// 0 1 1 1 0
// 0 0 1 0 0

// Exemplo para habilidade em cruz:
// 0 0 1 0 0
// 1 1 1 1 1
// 0 0 1 0 0
