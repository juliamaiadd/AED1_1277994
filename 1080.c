/*
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Julia Maia
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 24/08/2026
Objetivo    : Ler 100 valores inteiros, apresentar o maior valor lido e a posição dentre os valores lidos.
Dificuldade : encontrar o maior valor
Uso de IA   : não foi usado
*/
#include <stdio.h>
 
int main() {
 
     int vetor[100];

    for(int i = 0;i<100;i++){
        scanf("%d", &vetor[i]);
    }

    int maior = vetor[0];
    int posicaoMaior = 0;
    for(int i = 1;i<100;i++){
        if (vetor[i]>maior){
            maior = vetor[i];
            posicaoMaior = i;
        }
    }
    printf("%d\n", maior);
    printf("%d\n", posicaoMaior + 1);
 
    return 0;
}
