/*
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Julia Maia
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 24/08/2026
Objetivo    : Ler 100 valores inteiros, apresentar o maior valor lido e a posição dentre os valores lidos, utilizando alocação dinâmica de vetores
Dificuldade : alocação dinâmica
Uso de IA   : não foi usado
*/
#include <stdio.h>
#include <stdlib.h>
 
int main() {
    
    int n, i;
    int *vetor;
    
    n = 100;
    
    //alocacao dinamica
    vetor =  (int *) malloc(n * sizeof(int));
    
    //leitura do vetor
    for (i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    
    int maior = vetor[0];
    int posicaoMaior = 0;
    
    for (i = 1; i < n; i++){
        if(vetor[i] > maior){
            maior = vetor[i];
            posicaoMaior = i;
        }
    }
    
    printf("%d\n", maior);
    printf("%d\n", posicaoMaior + 1);
 
    free(vetor);
    
    return 0;
}
