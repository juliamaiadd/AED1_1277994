/*
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Julia Maia
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 25/08/2026
Objetivo    : Verificar se uma matriz preenchida é solução para o jogo sudoku
Dificuldade : Verificar as tres condicoes de forma simultanea
Uso de IA   : Usado para verificar se havia erros no codigo
*/
#include <stdio.h>
 
int main() {
 
    int n, matriz[9][9];
    scanf("%d", &n);
    
    for(int instancia = 1; instancia <= n; instancia++) {
        //ler a matriz
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
        
        int valido = 1; //assume que e valido
        
        //verificar linhas
        for(int i = 0; i < 9 && valido; i++) {
            int presente[10] = {0}; //vetor para marcar números 1-9
            for(int j = 0; j < 9; j++) {
                int num = matriz[i][j];
                if(num < 1 || num > 9 || presente[num]) {
                    valido = 0;
                    break;
                }
                presente[num] = 1;
            }
        }
        
        //verificar colunas
        for(int j = 0; j < 9 && valido; j++) {
            int presente[10] = {0};
            for(int i = 0; i < 9; i++) {
                int num = matriz[i][j];
                if(num < 1 || num > 9 || presente[num]) {
                    valido = 0;
                    break;
                }
                presente[num] = 1;
            }
        }
        
        //verificar regioes 3x3
        for(int bloco = 0; bloco < 9 && valido; bloco++) {
            int presente[10] = {0};
            int linhaInicio = (bloco / 3) * 3;
            int colunaInicio = (bloco % 3) * 3;
            
            for(int i = linhaInicio; i < linhaInicio + 3; i++) {
                for(int j = colunaInicio; j < colunaInicio + 3; j++) {
                    int num = matriz[i][j];
                    if(num < 1 || num > 9 || presente[num]) {
                        valido = 0;
                        break;
                    }
                    presente[num] = 1;
                }
                if(!valido) break;
            }
        }
        
        printf("Instancia %d\n", instancia);
        printf("%s\n", valido ? "SIM" : "NAO");
        printf("\n"); 
    }
    return 0;
}
