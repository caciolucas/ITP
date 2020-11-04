#include <stdio.h>
#include <ctype.h>

int contaOcorrencias(char * frase, char * trecho); // Define a função sem descrever ela 

int main()
{
    char frase[41], trecho[41]; // Strings principais
    int ocorrencias; // Número de ocorrencias
    
    gets(trecho); // Recebe o trecho a ser buscado
    gets(frase); // Recebe a frase onde será buscada

    ocorrencias = contaOcorrencias(frase, trecho); // Executa a função a baixo e retorna o valor de ocorrencias achadas

    printf("%d", ocorrencias); // Exibe o valor de ocorrências

    return 0;
}
int contaOcorrencias(char* frase, char* trecho) // Cria a função em si e descreve seu funcionamento
{
    int i, j, encontrou, ocorrencias;
    int tamanhoFrase=0, tamanhoTrecho=0; 

    for (i = 0; frase[i]!=0; i++) {frase[i]=tolower(frase[i]);tamanhoFrase++;}
    for (i = 0; trecho[i]!=0; i++){trecho[i]=tolower(trecho[i]);tamanhoTrecho++;}
    //  Pensei em usar +36 pra transformar em minusculo, mas os espaços também seriam afetados
    // Também pensei em usar strlen, mas acho que seria mais um laço, preferi ja usar esse e incrementar no contador

    ocorrencias = 0; // Starta o contador de ocorrências em 0

    for (i=0; i <= tamanhoFrase-tamanhoTrecho; i++) 
    // Ao invés de procurar quando as ocorrências acontecem, eu assumo que elas acontecem e paro o laço quando vejo que não ocorrem
    {
        encontrou = 1;
        for(j=0; j<tamanhoTrecho; j++)
        {
            if(frase[i + j] != trecho[j])
            {
                encontrou = 0;
                break;
            }
        }

        if(encontrou == 1)
        {
            ocorrencias++;
        }
    }

    return ocorrencias;
}