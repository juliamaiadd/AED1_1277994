/* 
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Julia Maia
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 10/11/2026
Objetivo    : 
Dificuldade : Utilizar pilha
Uso de IA   : Para verificacao de erros.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 400

// retorna a precedencia de um operador
// quanto maior o numero, maior a prioridade
int precedencia(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;  // para parenteses e outros
}

int main(void) {
    int n;
    scanf("%d", &n);

    char linha[MAX];

    // le o \n que sobrou depois do numero de casos de teste
    getchar();

    for (int caso = 0; caso < n; caso++) {
        // le a expressao inteira
        fgets(linha, MAX, stdin);

        // remove o \n do final, se existir
        int len = strlen(linha);
        if (len > 0 && linha[len - 1] == '\n') {
            linha[len - 1] = '\0';
            len--;
        }

        // pilha de operadores e parenteses
        char pilha[MAX];
        int topo = -1;

        // vetor de saida (pos-fixa)
        char saida[MAX];
        int posSaida = 0;

        // percorre cada caractere da expressao infixa
        for (int i = 0; i < len; i++) {
            char c = linha[i];

            // operando vai direto para a saida
            if (isalnum(c)) {
                saida[posSaida++] = c;
            }
            // abre parenteses: empilha
            else if (c == '(') {
                pilha[++topo] = c;
            }
            // fecha parenteses: desempilha ate achar o abre
            else if (c == ')') {
                while (topo >= 0 && pilha[topo] != '(') {
                    saida[posSaida++] = pilha[topo--];
                }
                // descarta o '(' que sobrou no topo
                if (topo >= 0) {
                    topo--;
                }
            }
            // operador: desempilha operadores de maior/igual precedencia
            else {
                while (topo >= 0 && pilha[topo] != '(' &&
                       (precedencia(pilha[topo]) > precedencia(c) ||
                        (precedencia(pilha[topo]) == precedencia(c) && c != '^'))) {
                    saida[posSaida++] = pilha[topo--];
                }
                // empilha o operador atual
                pilha[++topo] = c;
            }
        }

        // ao final, desempilha tudo que sobrou
        while (topo >= 0) {
            saida[posSaida++] = pilha[topo--];
        }

        // termina a string de saida e imprime
        saida[posSaida] = '\0';
        printf("%s\n", saida);
    }

    return 0;
}
