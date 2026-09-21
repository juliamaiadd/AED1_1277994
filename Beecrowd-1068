/* 
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Julia Maia
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 01/09/2026
Objetivo    : Dada uma expressao qualquer com parenteses, indica se a quantidade de parenteses está correta ou nao.
Dificuldade : Utilizar pilha
Uso de IA   : Para verificacao de erros.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EXPRESSION 1001
#define MAX_EXPRESSIONS 10000

//estrutura da pilha
typedef struct {
    char* items;
    int top;
    int capacity;
} Stack;

//funcao para criar uma pilha
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    stack->items = (char*)malloc(capacity * sizeof(char));
    if (stack->items == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

//funcao para verificar se a pilha esta vazia
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

//funcao para verificar se a pilha esta cheia
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

//funcao para empilhar um caractere
void push(Stack* stack, char item) {
    if (isFull(stack)) {
        //aumenta a capacidade da pilha se necessario
        stack->capacity *= 2;
        stack->items = (char*)realloc(stack->items, stack->capacity * sizeof(char));
        if (stack->items == NULL) {
            printf("Erro de realocação de memória\n");
            exit(1);
        }
    }
    stack->items[++stack->top] = item;
}

//funcao para desempilhar um caractere
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->items[stack->top--];
}

//funcao para verificar o topo da pilha
char peek(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->items[stack->top];
}

//funcao para verificar o balanceamento de parenteses
int checkParentheses(const char* expression) {
    int len = strlen(expression);
    Stack* stack = createStack(100); //capacidade inicial
    
    for (int i = 0; i < len; i++) {
        char c = expression[i];
        
        if (c == '(') {
            push(stack, c);
        } 
        else if (c == ')') {
            if (isEmpty(stack)) {
                //encontrou um ')' sem um '(' correspondente
                free(stack->items);
                free(stack);
                return 0; // incorrect
            }
            // verifica se o topo da pilha é '('
            if (peek(stack) == '(') {
                pop(stack);
            } else {
                free(stack->items);
                free(stack);
                return 0; //incorreto
            }
        }
        //ignora outros caracteres
    }
    
    //verifica se ainda ha parenteses abertos na pilha
    int result = isEmpty(stack);
    
    free(stack->items);
    free(stack);
    
    return result;
}

int main() {
    char expression[MAX_EXPRESSION];
    int lineCount = 0;
    char results[MAX_EXPRESSIONS][10];
    
    //le todas as expressoes da entrada
    while (fgets(expression, sizeof(expression), stdin) != NULL) {
        //remove o caractere de nova linha se presente
        size_t len = strlen(expression);
        if (len > 0 && expression[len-1] == '\n') {
            expression[len-1] = '\0';
        }
        
        //verifica se a linha esta vazia
        if (strlen(expression) == 0) {
            continue;
        }
        
        if (checkParentheses(expression)) {
            strcpy(results[lineCount], "correct");
        } else {
            strcpy(results[lineCount], "incorrect");
        }
        lineCount++;
    }
    
    //imprime os resultados
    for (int i = 0; i < lineCount; i++) {
        printf("%s\n", results[i]);
    }
    
    return 0;
}
