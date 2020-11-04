#include <stdio.h>
#include <stdbool.h>

struct Element
{
    int valor;
};
struct c_vector
{
    struct Element elementos[40];
    int tam;
};

int exist(struct Element element, struct c_vector vetor){
    for (int i = 0; i < vetor.tam; i++)
    {
        if (element.valor==vetor.elementos[i].valor)
        {
            return 1;
        }
        
    }
    return 0;
}

struct c_vector remove_from(struct c_vector vetor, int indice)
{
    struct Element zero;
    zero.valor = 0;
    if (indice >= vetor.tam)
    {
        return vetor;
    }
    for (int i = indice; i < vetor.tam; i++)
    {
        if (i == vetor.tam - 1)
        {
            vetor.elementos[i] = zero;
        }
        else
        {
            vetor.elementos[i] = vetor.elementos[i + 1];
        }
    }
    vetor.tam -= 1;
    return vetor;
}

struct c_vector insert_at(struct Element elemento, int indice, struct c_vector vetor)
{
    if (indice >= vetor.tam)
    {
        vetor.elementos[vetor.tam] = elemento;
        vetor.tam = vetor.tam + 1;
        return vetor;
    }
    for (int i = vetor.tam; i >= indice; i--)
    {
        vetor.elementos[i] = vetor.elementos[i - 1];
    }
    vetor.elementos[indice] = elemento;
    vetor.tam = vetor.tam + 1;
    return vetor;
}
int main()
{
    struct c_vector array;
    array.tam = 0;
    char comando[10];

    char funcao;
    int valor;
    int posicao;
    while (true)
    {
        struct Element elemento;
        fgets(comando, 10, stdin);
        funcao = comando[0];
        if (funcao == 'i')
        {
            sscanf(comando, "%c %d %d", &funcao, &elemento.valor, &posicao);
            array = insert_at(elemento, posicao, array);
        }
        else if (funcao == 'r')
        {
            sscanf(comando, "%c %d", &funcao, &posicao);
            array = remove_from(array, posicao);
        }
        else if (funcao == 'e'){
            sscanf(comando, "%c %d", &funcao, &elemento);
            printf("%d\n",exist(elemento,array));
        }
        else if (funcao == 'x')
        {
            if (!array.tam)
            {
                puts("vazio");
            }
            else{
                for (int i = 0; i < array.tam; i++)
                {
                    printf("%d ", array.elementos[i].valor);
                }
                puts("");

            }
            break;
        }
    }

    return 0;
}