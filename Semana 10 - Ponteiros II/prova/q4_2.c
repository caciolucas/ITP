#include <stdio.h>
#include <stdbool.h>

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

typedef struct node node_t;
typedef struct stack stack_t;

int push(int, struct stack *);
int pop(struct stack *);
void destroy(struct stack *);
void exit();

int main()
{
    stack_t pilha;
    pilha.size = 0;
    int max_size = 0;
    char operacao[11];
    scanf("%d", &max_size); 

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

int push(int, struct stack *){}