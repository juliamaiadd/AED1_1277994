/* 
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Julia Maia
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 20/10/2026
Objetivo    : Dado o número de casas N, o número de encomendas M, a lista de números das casas (ordenada) e a lista de destinos das encomendas (na ordem de entrega), calcule o tempo total que o carteiro gasta andando de uma casa até outra.
Dificuldade : utilizar busca binaria
Uso de IA   : Para verificacao de erros.
*/

#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(long long *casas, int n, long long valor) {
    int e = -1, d = n, m;
    while (e < d - 1) {
        m = (e + d) / 2;
        if (casas[m] == valor) return m;
        else if (casas[m] < valor) e = m;
        else d = m;
    }
    return d;
}

int main() {
    int n, m, i;
    long long *casas;
    long long *encomendas;
    long long tempo = 0;
    int posicaoAtual = 0;

    scanf("%d %d", &n, &m);

    casas = (long long *) malloc(n * sizeof(long long));
    encomendas = (long long *) malloc(m * sizeof(long long));

    if (casas == NULL || encomendas == NULL) {
        printf("erro de alocacao\n");
        return 1;
    }

    for (i = 0; i < n; i++)
        scanf("%lld", &casas[i]);

    for (i = 0; i < m; i++)
        scanf("%lld", &encomendas[i]);

    for (i = 0; i < m; i++) {
        int destino = buscaBinaria(casas, n, encomendas[i]);

        long long distancia = (long long) destino - posicaoAtual;
        if (distancia < 0) {
            distancia = -distancia;
        }
        tempo += distancia;
        posicaoAtual = destino;
    }

    printf("%lld\n", tempo);

    free(casas);
    free(encomendas);

    return 0;
}
