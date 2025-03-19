#include <stdio.h>

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

// Função que calcula a sobreposição das figuras a partir do seu centro
void calcEffect(int area[5][5], int center[2], int tabuleiro[10][10]){
    // Valor de centralização da figura
    int origen[2] = {center[0] - 2, center[1] - 2};
    // Laço externo para sobreposição
    for (int square_l = 0; square_l < 5; square_l++)
    {
        // Laço interno para sobreposição
        for (int square_c = 0; square_c < 5; square_c++)
        {
            // Switch de validação de sobreposição da figura em cada casa do tabuleiro
            switch (tabuleiro[origen[0] + square_l][origen[1] + square_c])
            {
                // se 0 -> alocar o valor do pedaço da figura na casa do tabuleiro
            case 0:
                tabuleiro[origen[0] + square_l][origen[1] + square_c] = area[square_l][square_c];
            break;

                // Pula
            case 1:
                /* code */
            break;

                // se 3 -> fazer uma validação:
            case 3:
                // se o pedaço da figura for 0, soma 0
                if (area[square_l][square_c] == 0){
                    tabuleiro[origen[0] + square_l][origen[1] + square_c] += 0;
                // Se for 1, soma 2 para virar 5 e mostrar que o navio foi afetado.
                } else if (area[square_l][square_c] == 1)
                {
                    tabuleiro[origen[0] + square_l][origen[1] + square_c] += 2;
                }
                
            break;
            
            default:
                break;
            }
        }
        
    }
    
}

// Função que adiciona o efeito de are especifico.
void addAreaEffect(int effect, int center[2], int tabuleiro[10][10]) {
    // Validação com base nas coordenadas se a figura vai ficar dentro do tabuleiro.
    if ( (1 < center[0] && center[0] < 7) && (1 < center[1] && center[1] < 7)){
        switch (effect)
        {
        case 1:
        {
            int area_cruz[5][5] = {
                {0, 0, 1, 0, 0},
                {0, 0, 1, 0, 0},
                {1, 1, 1, 1, 1},
                {0, 0, 1, 0, 0},
                {0, 0, 1, 0, 0},
            };
            calcEffect(area_cruz, center, tabuleiro);
        }
        break;
        
        case 2:
        {
            int area_octaedro[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 1, 1, 1, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0},
            };
            calcEffect(area_octaedro, center, tabuleiro);
        }
        break;

        case 3:
        {
            int area_cone[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 1, 1, 1, 0},
                {1, 1, 1, 1, 1},
                {0, 0, 0, 0, 0},
            };
            calcEffect(area_cone, center, tabuleiro);
        }
        break;

        default:
        break;
        }
    } else {
        printf("O efeito em area, está fora do tabuleiro...\n");
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

    addNavio(navio, 'd', 1, 2, board); // Diagonal
    addNavio(navio, 'd', 7, 1, board); // Diagonal

    int coordenadas[2];

    // Primeira chamada de criação de figura
    coordenadas[0] = 2;
    coordenadas[1] = 6;
    addAreaEffect(1, coordenadas, board);

    // Segunda chamada de criação de figura
    coordenadas[0] = 2;
    coordenadas[1] = 2;
    addAreaEffect(2, coordenadas, board);

    // Terceira chamada de criação de figura
    coordenadas[0] = 6;
    coordenadas[1] = 6;
    addAreaEffect(3, coordenadas, board);

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
