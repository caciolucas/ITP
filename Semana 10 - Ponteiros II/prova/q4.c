#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct stack
{
    struct node *top;
    int size;
};
struct node
{
    int data;
    struct node *next;
};

int push(int, struct stack *);
int pop(struct stack *);
void destroy(struct stack *);
void exit();

void printStack(struct stack *);

int main()
{
    struct node memory[1000];
    struct stack pilha;
    pilha.size = 0;
    pilha.top = memory;
    int max_size=0;
    char operacao[11];
    scanf("%d", &max_size);
    if (max_size==0)
    {
        max_size=10;
    }
    
    while (true)
    {
        // puts("Operacao:");
        scanf("%s", operacao);
        if (strcmp(operacao, "exit") == 0)
        {
            break;
        }
        else if (strcmp(operacao, "push") == 0)
        {
            int number;
            scanf("%d", &number);
            if (pilha.size < max_size)
            {
                push(number, &pilha);
            }
            else
            {
                puts("pilha cheia. nao eh possivel adicionar mais elementos");
            }
        }
        else if (strcmp(operacao, "pop") == 0)
        {
            if (pilha.size > 0)
            {
                pop(&pilha);
            }
            else
            {
                puts("pilha vazia, nao eh possivel realizar pop");
            }
        }
        else if (strcmp(operacao, "destroy") == 0)
        {
            destroy(&pilha);
        }
    }

    return 0;
}
void printStack(struct stack *pilha)
{
    // printf("pilha: ");
    for (int i = 0; i < pilha->size; i++)
    {
        printf("%d ", pilha->top[i].data);
    }
    puts(" ");
}
int push(int n, struct stack *pilha)
{
    for (int i = pilha->size; i >= 0; i--)
    {
        pilha->top[i].data = pilha->top[i-1].data;
    }
    pilha->top[0].data = n;
    pilha->size++;    
    printf("pilha: ");
    printStack(pilha);
    return 1;
}
int pop(struct stack *pilha)
{
    for (int i = 0; i < pilha->size; i++)
    {
        if (i == pilha->size - 1)
            pilha->top[i].data = 0;
        else
            pilha->top[i].data = pilha->top[i+1].data;
    }
    pilha->size--;
    printf("pilha : ");
    printStack(pilha);
    return 1;
}
void destroy(struct stack *pilha)
{
    pilha->size = 0;
    return;
}