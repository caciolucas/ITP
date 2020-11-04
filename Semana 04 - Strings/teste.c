#include <stdio.h>
#include <string.h>
int main()
{
  char texto[100];
  gets(texto);
  int n=strlen(texto), i, j, swap;

  
  for (i = 0 ; i < n - 1; i++)
  {
    for (j = 0 ; j < n - i - 1; j++)
    {
      if (texto[j] > texto[j+1]) /* For decreasing order use < */
      {
        swap       = texto[j];
        texto[j]   = texto[j+1];
        texto[j+1] = swap;
      }
    }
  }

  printf("Sorted list in ascending order:\n");

  for (i = 0; i < n; i++)
     printf("%c\n", texto[i]);

  return 0;
}