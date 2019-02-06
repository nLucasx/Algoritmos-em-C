#include <stdio.h>
#include <math.h>
int ehprimo(int x);
void decompor(int y);
int proxprimo(int y);
void mmc(int fat1[], int exp1[], int exp2[], int tamanho);
void mdc(int fat1[], int exp1[], int exp2[], int tamanho);
int fatores[400];
int expoente[400];
int global = 0;

int main()
{
	int num1, num2, i, aux, fat1[400], fat2[400], exp1[400], exp2[400], tamanho1 = 0, tamanho2 = 0;

	scanf("%d%d", &num1, &num2);
	
	decompor(num1);
	for (i = 0; i <= global; i++)
	{
		fat1[i] = fatores[i];
		exp1[i] = expoente[i];
		tamanho1++;
	}
	decompor(num2);
	for (i = 0; i <= global; i++)
	{
		fat2[i] = fatores[i];
		exp2[i] = expoente[i];
		tamanho2++;
	}
	if (tamanho2 > tamanho1)
	{
		for (i = 0; i <= tamanho2; i++)
		{
			if (fat1[i] != fat2[i])
			{
				exp1[i] = 0;
			}

		}
		printf("O MMC ENTRE %d e %d EH: ", num1, num2);
		mmc(fat2, exp1, exp2, tamanho2);
		printf("O MDC ENTRE %d e %d EH: ", num1, num2);
		mdc(fat2, exp1, exp2, tamanho1);

	}
	else
	{
		for (i = 0; i <= tamanho1; i++)
		{
			if (fat2[i] != fat1[i])
			{
				exp2[i] = 0;
			}

		}
		printf("O MMC ENTRE %d e %d EH: ", num1, num2);
		mmc(fat1, exp1, exp2, tamanho1);
		printf("O MDC ENTRE %d e %d EH: ", num1, num2);
		mdc(fat1, exp1, exp2, tamanho1);

	}

}

int ehprimo(int x)
{
	int i;
	if (x == 2)
	{
		return 1;
	}

	if (x % 2 != 0 && x != 2)
	{	
		for (i = 3; i <= sqrt(x); i++)
		{
			if (x % i == 0)
			{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}
int proxprimo(int y)
{
	for (;;)
	{
	 	y++;
	 	
	 	if (ehprimo(y))
	 	{
	 		return y;
	 	}
	}
}

void decompor(int y)
{
	int x = 2, i = 0, exp = 0, flag = -1;
	global = 0;

	for (;;)
	{
		if (y % x == 0)
		{
			y = y / x;
			fatores[i] = x;
			expoente[i] = exp + 1;
			exp++;
			flag = 0;
		}
		else
		{	
			if (flag == 0)
			{	
				x = proxprimo(x);
				i++;
				exp = 0;
				global++;
				flag = -1;
			}
			else
			{
				fatores[i] = x;
				expoente[i] = 0;
				i++;
				global++;
				x = proxprimo(x);
			}
		}
		if (y == 1)
		{
			break;
		}
	}
}
void mmc(int fat1[], int exp1[], int exp2[], int tamanho)
{
	int i, cont = 1;

	for (i = 0; i < tamanho; i++)
	{
		if (exp1[i] >= exp2[i])
		{
			cont = cont * pow(fat1[i], exp1[i]);
		}
		else
		{
			cont = cont * pow(fat1[i], exp2[i]);
		}
	}
	printf("%d\n", cont);
}
void mdc(int fat1[], int exp1[], int exp2[], int tamanho)
{
	int i, cont = 1;

	for (i = 0; i < tamanho; i++)
	{
		if (exp1[i] <= exp2[i])
		{
			cont = cont * pow(fat1[i], exp1[i]);
		}
		else
		{
			cont = cont * pow(fat1[i], exp2[i]);
		}
	}
	printf("%d\n", cont);
}
