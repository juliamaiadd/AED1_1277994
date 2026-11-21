/* 
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Julia Maia
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 10/11/2026
Objetivo    : Verificar, para cada permutação de saída desejada, se é possível reorganizar os vagões 1..N usando uma única pilha (a estação), respondendo **Yes** ou **No** para cada uma.
Dificuldade : Utilizar pilha
Uso de IA   : Para verificacao de erros.
*/

#include <stdio.h>

#define MAX 1000

int main(void) {
    int n;

    // laco externo: le o n de cada bloco de testes
    while (scanf("%d", &n) == 1 && n != 0) {
        int perm[MAX];

        // laco interno: le cada permutacao do bloco
        while (scanf("%d", &perm[0]) == 1 && perm[0] != 0) {
            // le o restante da permutacao
            for (int i = 1; i < n; i++) {
                scanf("%d", &perm[i]);
            }

            // variaveis da simulacao da pilha
            int pilha[MAX];
            int topo = -1;        // pilha vazia
            int proximo = 1;      // proximo vagao a entrar (1..n)
            int possivel = 1;     // assume que e possivel

            // percorre a permutacao da esquerda para a direita
            for (int i = 0; i < n; i++) {
                int desejado = perm[i];  // vagao que deve sair agora

                // se o topo da pilha ja e o desejado, desempilha
                if (topo >= 0 && pilha[topo] == desejado) {
                    topo--;
                    continue;
                }

                // empurra vagoes da entrada ate achar o desejado
                while (proximo <= n && proximo != desejado) {
                    pilha[++topo] = proximo;
                    proximo++;
                }

                // se a entrada acabou sem achar o desejado, falhou
                if (proximo > n) {
                    possivel = 0;
                    break;
                }

                // o desejado esta na entrada agora
                proximo++;
            }

            // imprime o resultado da permutacao
            printf("%s\n", possivel ? "Yes" : "No");
        }
        
        printf("\n");
    }

    return 0;
}
