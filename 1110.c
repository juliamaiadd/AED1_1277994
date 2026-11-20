/* 
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Julia Maia
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 01/09/2026
Objetivo    : Dada uma pilha de cartas enumeradas de 1 ate n com 1 no topo e n na base, joga fora a carta do topo e move a proxima carta paara a base da pilha.
Dificuldade : Utilizacao de lista encadeada
Uso de IA   : Para verificar erros no programa
- */

#include <stdio.h>
#include <stdlib.h>

//definicao da estrutura do no da lista encadeada
typedef struct Node {
    int card;
    struct Node* next;
} Node;

//funcao para criar um novo no
Node* createNode(int card) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    newNode->card = card;
    newNode->next = NULL;
    return newNode;
}

//funcao para criar uma pilha com n cartas
Node* createStack(int n) {
    if (n <= 0) return NULL;
    
    Node* head = createNode(1);
    Node* current = head;
    
    for (int i = 2; i <= n; i++) {
        current->next = createNode(i);
        current = current->next;
    }
    
    return head;
}

//funcao para encontrar o último no da lista
Node* getLastNode(Node* head) {
    if (head == NULL) return NULL;
    
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    return current;
}

//funcao para processar a pilha e encontrar as cartas descartadas
void processCards(int n) {
    if (n <= 0) return;
    
    Node* head = createStack(n);
    Node* current = head;
    int discardedCount = 0;
    int* discardedCards = (int*)malloc((n - 1) * sizeof(int));
    
    if (discardedCards == NULL) {
        printf("Erro de alocação de memória\n");
        return;
    }
    
    //processamento principal
    while (current != NULL && current->next != NULL) {
        // Descarta a carta do topo
        discardedCards[discardedCount++] = current->card;
        Node* toRemove = current;
        
        // move a proxima carta para a base
        Node* nextCard = current->next;
        current = nextCard->next;  // Avança para a carta após a que será movida
        
        //encontra o ultimo no para adicionar a carta movida
        if (current != NULL) {
            Node* last = getLastNode(current);
            if (last != NULL) {
                last->next = nextCard;
                nextCard->next = NULL;
            }
        } else {
            //se current e NULL, significa que so temos a carta que sera movida
            current = nextCard;
            current->next = NULL;
        }
        
        free(toRemove);
    }
    
    //imprime as cartas descartadas
    printf("Discarded cards: ");
    for (int i = 0; i < discardedCount; i++) {
        printf("%d", discardedCards[i]);
        if (i < discardedCount - 1) {
            printf(", ");
        }
    }
    printf("\n");
    
    //imprime a carta remanescente
    if (current != NULL) {
        printf("Remaining card: %d\n", current->card);
    } else {
        // Caso especial: n = 1
        printf("Remaining card: 1\n");
    }
    
    //libera memoria
    free(discardedCards);
    if (current != NULL) {
        free(current);
    }
}

int main() {
    int n;
    
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        processCards(n);
    }
    
    return 0;
}
