#include <stdio.h>
#include <string.h>



void alterarString(char *strRecebida,int tamanho)
{
    char novaString="ESTRAGUEI";
    for (int *i = 0; *i < tamanho; i++)
    {
        *strRecebida=novaString[i];
        strRecebida;
    }
  
}
int main()
{
  char *str;
  str=NULL;
  *str="MINHA STRING";
  printf("Minha string: %s \n",*str);/*IMPRIME : Minha string : MINHA STRING*/
  alterarString(str);

  printf("Minha string alterada: %s",*str);
//IMPRIME: MINHA STRING. A VARIÁVEL NÃO FOI ALTERADA

  return 0;
}