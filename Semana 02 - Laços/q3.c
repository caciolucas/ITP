#include <stdio.h>

int main()
{
	int size = 5, odd = 0, even = 0, pos = 0, neg = 0, x;

	// 	int array[size];//Gera array com tamanho definido
	//
	//	for(i;i<=size;i++){ //Popula o array
	//		scanf("%d",&x);
	//		array[i]=x;
	//	}

	while (size)
	{

		scanf("%d", &x);
		switch (x % 2 == 0)
		{
		case 1:
			// printf("é par\n");
			even += 1;
			break;
		case 0:
			// printf("é impar\n");
			odd += 1;
			break;
		}
		switch (x > 0)
		{
		case 1:
			// printf("é pos\n");
			pos += 1;
			break;
		case 0:
			if (x == 0)
			{
				break;
			}

			// printf("é neg\n");
			neg += 1;
			break;
		}
		size--;
	}
	printf("%d valores pares\n", even);
	printf("%d valores impares\n", odd);
	printf("%d valores positivos\n", pos);
	printf("%d valores negativos\n", neg);
}
