#include <stdio.h>

#define MAX 1000

int main(void) {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {
        int perm[MAX];

        while (scanf("%d", &perm[0]) == 1 && perm[0] != 0) {
            for (int i = 1; i < n; i++) {
                scanf("%d", &perm[i]);
            }

            int pilha[MAX];
            int topo = -1;
            int proximo = 1;
            int possivel = 1;

            for (int i = 0; i < n; i++) {
                int desejado = perm[i];

                if (topo >= 0 && pilha[topo] == desejado) {
                    topo--;
                    continue;
                }

                while (proximo <= n && proximo != desejado) {
                    pilha[++topo] = proximo;
                    proximo++;
                }

                if (proximo > n) {
                    possivel = 0;
                    break;
                }

                proximo++;
            }

            printf("%s\n", possivel ? "Yes" : "No");
        }

        printf("\n");  // linha em branco apos cada bloco
    }

    return 0;
}
