#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int numero[67];
void binario(int x);

int main() {
	
	int n, num1, num2, bin1[67], bin2[67], i, j, cont = 0;
	scanf("%d", &n);
	for (j = 0; j < n; j++)
	{	
		scanf("%d%d", &num1, &num2);
	
		binario(num1);
	
		for (i = 0; i < 64; i++)
		{
			bin1[i] = numero[i];
			printf("%d", bin1[i]);
		}
		printf("\n");
		binario(num2);
	
		for (i = 0; i < 64; i++)
		{
			bin2[i] = numero[i];
			printf("%d", bin2[i]);
		}

		printf("\n");
		for (i = 0; i < 64; i++)
		{
			if (bin1[i] != bin2[i])
			{
				cont++;
			}
		}
		printf("%d\n", cont);
		cont = 0;
	}
		return 0;
}
void binario(int x)
{
	int i = 63, j = i;
	if (x >= 1)
	{	
		while (x / 2 > 0)
		{
			numero[i] = x % 2;
			x = x/2;
			i--;
			j--;
		}
		numero[i] = 1;
		
		for (i = 0; i < j; i++)
		{
			numero[i] = 0;
		}
	}
	else if (x == 0)
	{
		for (i = 0; i < 64; i++)
		{
			numero[i] = 0;
		}
	}
	else
	{
		x = x * (-1);
		while (x / 2 > 0)
		{
			numero[i] = x % 2;
			x = x/2;
			i--;
			j--;
		}
		numero[i] = 1;
		
		for (i = 0; i < j; i++)
		{
			numero[i] = 0;
		}

		for (i = 0; i < 64; i++)
		{
			if (numero[i] == 0)
			{
				numero[i] = 1;
			}
			else
			{
				numero[i] = 0;
			}
		}
		for (i = 63; i >= 0; i--)
		{
			if (numero[i] + 1 == 1)
			{
				numero[i] = 1;
				break;
			}
			else
			{
				numero[i] = 0;
			}
		}
	}
}
