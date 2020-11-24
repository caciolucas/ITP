#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef unsigned int UINT;
typedef struct
{
    UINT size;  // tamanho do array alocado para os elementos do conjunto
    UINT num;   // número de elementos atualmente alocados
    int *array; // array com os elementos
} Set;

Set *create()
{
    Set *conjunto = malloc(sizeof(Set));
    conjunto->array = malloc(sizeof(int[10]));
    conjunto->size = 10;
    conjunto->num = 0;
    return conjunto;
}
bool has(Set *s, int value)
{
    for (int i = 0; i < s->num; i++)
    {
        if (s->array[i] == value)
        {
            return true;    
        }
    }
    return false;
}

void add(Set *s, int value)
{
    has(s,value);
    if (!has(s, value))
    {
        if (s->num==s->size)
        {
            s->size+=10;
            s->array = realloc(s->array,sizeof(int[s->size]));
        }
        
        int index = s->num;
        s->array[index] = value;
        s->num++;
    }
    return;
}
Set *checkComum(Set *m, Set *n){
    Set *conjunto = create();
    for (int i = 0; i < m->num; i++)
    {
        for (int j = 0; j < n->num; j++)
        {
            if (m->array[i]==n->array[j])
            {
                add(conjunto,m->array[i]);
            }
        }
    }
    return conjunto;

}
void printSet(Set *s){
    for (int i = 0; i < s->num; i++)
    {
        printf("%d ",s->array[i]);
    }
    puts("");
    
}
void printStats(Set *s){
    printf("%d %d",s->num,s->size);
    puts("");
}
int main()
{
    Set *conjuntoN = create();
    Set *conjuntoM = create();
    Set *conjuntoComum = create();
    int n, m, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        add(conjuntoN, x);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x);
        add(conjuntoM, x);
    }    
    conjuntoComum = checkComum(conjuntoM,conjuntoN);
    printSet(conjuntoComum);
    printStats(conjuntoN);
    printStats(conjuntoM);
    return 0;
}
