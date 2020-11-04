#include <stdio.h>
#include <string.h>

void ordenaString(char *texto);
void ordenaPeloPattern(char* mask, char* texto);
int main()
{
    char input[41],resultado[41];
    gets(input);
    char* pattern = "aeioubcdfghjklmnpqrstvwxyz";

    // ordenaString(input);
    ordenaPeloPattern(pattern,input);

    return 0;
}

// void ordenaString(char *texto)

// {
//     char consoantes[40] = "", vogais[40] = "";
//     int sizeC = 0, sizeV = 0; // Contadores pra aproveitar o loop e não ter que usar mais um strlen

//     for (int i = 0; texto[i] != 0; i++) // Faz a separação em 2 vetores, de vogais e consoantes
//     {
//         if (texto[i] == 'a' || texto[i] == 'e' || texto[i] == 'i' || texto[i] == 'o' || texto[i] == 'u')
//         {
//             vogais[strlen(vogais)] = texto[i];
//             sizeV++;
//         }
//         else
//         {
//             consoantes[strlen(consoantes)] = texto[i];
//             sizeC++;
//         };
//     }
//     char swap;
//     int i, j;
//     for (i = 0; i < sizeV - 1; i++)
//     {
//         for (j = 0; j < sizeV - i - 1; j++)
//         {
//             if (vogais[j] > vogais[j + 1]) /* For decreasing order use < */
//             {
//                 swap = vogais[j];
//                 vogais[j] = vogais[j + 1];
//                 vogais[j + 1] = swap;
//             }
//         }
//     }

//     for (i = 0; i < sizeC - 1; i++)
//     {
//         for (j = 0; j < sizeC - i - 1; j++)
//         {
//             if (consoantes[j] > consoantes[j + 1]) /* For decreasing order use < */
//             {
//                 swap = consoantes[j];
//                 consoantes[j] = consoantes[j + 1];
//                 consoantes[j + 1] = swap;
//             }
//         }
//     }

//     printf("%s%s", vogais, consoantes);
// }

void ordenaPeloPattern(char* mask, char* texto)
{
    char sortedTexto[41];
    strcpy(sortedTexto,texto);

    int ocorrencias[26] = {0};
    // Numero de ocorrencias pra cada letra
    // 0 1 2 3 ... 24 25 26 - indice
    // A B C D ... X  Y  Z  - letra
    // 0 0 0 0 ... 0  0  0  - n ocorrencias
    // Desse modo, é possivel relacionar o indice à letra
    
    // Verifica cada letra da string recebida 
    for (int i = 0 ; i < strlen(texto); i++)
    {
        // Usa-se o - 'a' para descobrir qual o indice de "ocorrencias" sera incrementado
        
        // Ex.: texto[i]= 'd'
        //      'd' - 'a' = 3
        //      100 - 97  = 3

        // O item no 3º indice de "ocorrencias" representa 
        // as occorências da letra 'd' e será incrementado
        ocorrencias[texto[i] - 'a']++;

    }
    // Indice que sera usado pra percorrer e preencher a nova string
    int pos = 0;

    //  Pra cada posicao da mascara
    for (int i = 0; i < strlen(mask); i++)
    {
        // Verei quantas ocorrencias tiveram daquela letra através do:
        //      "ocorrencias[mask[i] - 'a']"

        // ex.: "mask[i]='d'"
        //      "ocorrencias[mask[0] - 'a']"
        //      "ocorrencias[  'd'   - 'a']"
        //      "occorrencia[3]"
        for (int j = 0; j < ocorrencias[mask[i] - 'a']; j++)
        {
            sortedTexto[pos] = mask[i];
            pos++;
        }
    }
    for (int i = 0; sortedTexto[i]!=0; i++) {
      printf("%c", sortedTexto[i]);
    }
}