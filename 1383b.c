/*
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Julia Maia
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 25/08/2026
Objetivo    : Verificar se uma matriz preenchida é solução para o jogo sudoku, utilizando alocacao dinamica
Dificuldade : utilizar alocacao dinamica
Uso de IA   : Usado para verificar se havia erros no codigo
*/

#include <stdio.h>
#include <stdlib.h>

#define N 9

/* verifica se o vetor de contagem tem exatamente 1 em cada posicao 1..9. 
o indice 0 e ignorado. */
int valido(int *cont) {
    for (int v = 1; v <= 9; v++)
        if (cont[v] != 1)
            return 0;
    return 1;
}

//verifica se a matriz 9x9 e solucao de sudoku 
int ehSudoku(int **m) {
    int i, j, bi, bj;

    //verifica linhas 
    for (i = 0; i < N; i++) {
        int cont[10] = {0};
        for (j = 0; j < N; j++) {
            int v = m[i][j];
            if (v < 1 || v > 9) return 0;
            cont[v]++;
        }
        if (!valido(cont)) return 0;
    }

    //verifica colunas 
    for (j = 0; j < N; j++) {
        int cont[10] = {0};
        for (i = 0; i < N; i++) {
            int v = m[i][j];
            if (v < 1 || v > 9) return 0;
            cont[v]++;
        }
        if (!valido(cont)) return 0;
    }

    //verifica as 9 regioes 3x3 
    for (bi = 0; bi < 3; bi++) {
        for (bj = 0; bj < 3; bj++) {
            int cont[10] = {0};
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    int v = m[bi * 3 + i][bj * 3 + j];
                    if (v < 1 || v > 9) return 0;
                    cont[v]++;
                }
            }
            if (!valido(cont)) return 0;
        }
    }

    return 1;
}

int main() {
    int **matriz;
    int i, j, k;
    int n;
    int linhas = 9, colunas = 9;

    //le o numero de instancias
    if (scanf("%d", &n) != 1) return 0;

    //alocacao dinamica do vetor de ponteiros (linhas)
    matriz = (int **) malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        printf("erro de alocacao\n");
        return 1;
    }

    //alocando colunas para cada linha 
    for (i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("erro de alocacao\n");
            return 1;
        }
    }

    //processa cada instancia 
    for (k = 1; k <= n; k++) {

        //leitura da matriz
        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        // impressao do resultado
        printf("Instancia %d\n", k);
        if (ehSudoku(matriz))
            printf("SIM\n\n");
        else
            printf("NAO\n\n");
    }

    //liberacao da memoria
    for (i = 0; i < linhas; i++) {
        free(matriz[i]); 
    }
    free(matriz);    

    return 0;
}
