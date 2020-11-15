// C++ program to find sum of two large numbers.
#include <stdio.h>
#include <string.h>


void strrev(char string[], char reversed[]){
    int begin, end, count = 0;

    count = strlen(string);

    end = count - 1;

    for (begin = 0; begin < count; begin++) {
        reversed[begin] = string[end];
        end--;
    }

    reversed[begin] = '\0'; 

}
// Function for finding sum of larger numbers
void findSum(char str1[], char str2[], char res[])
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (strlen(str1) > strlen(str2))
    {
        char temp[50];
        strcpy(temp, str1);
        strcpy(str1, str2);
        strcpy(str2, temp);
    }

    // Calculate length of both string
    int n1 = strlen(str1), n2 = strlen(str2);

    // // Reverse both of strings
    char str1rev[50], str2rev[50];
    strrev(str1,str1rev);
    strrev(str2,str2rev);
    
    int dezena = 0, unidade;
    for (int i=0; i<n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0')+(str2[i]-'0')+dezena);
        unidade=sum%10 +'0';
        res[i]=unidade;

        // Calculate carry for next step
        dezena = sum/10;
    }
    printf("\"%s\"\n",res);
//     // Add remaining digits of larger number
//     for (int i=n1; i<n2; i++)
//     {
//         int sum = ((str2[i]-'0')+carry);
//         str[i]=sum%10 + '0';
//         carry = sum/10;
//     }

//     // Add remaining carry
//     if (carry)
//         str[0](carry+'0');

//     // // reverse resultant string
//     // reverse(str.begin(), str.end());

    // return res;
// }

// Driver code
int main()
{
    char str1[50] = "12";
    char str2[50] = "198111";
    char res[50] = "";
    findSum(str1,str2,res);
    printf("%s", res);
    return 0;
}