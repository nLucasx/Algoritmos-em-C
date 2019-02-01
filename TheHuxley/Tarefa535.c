#include <stdio.h>
void base(int xlargura, int xareia);
void ampulheta(int margem, int i, int hareia, int altura2, int altura);
void ampulheta2(int margem, int i, int hareia, int altura2, int altura);

int main()
{
	int altura, areia, margem, i, altura2, j, n;
	scanf("%d", &n);
	for (j = 0; j < n; j++)	
	{	
		scanf("%d%d", &altura, &areia);
		printf("Caso %d:\n", j);
		base(altura, areia);
		margem = 1;
		altura2 = altura;
		for (i = 0; i < altura - 1; i++)
		{
			ampulheta(margem, i, areia, altura2, altura-1);
			margem++;
			altura2--;
		}
		margem = altura - 1;
		altura2 = 2;
		for (i = altura - 2; i >= 0; i--)
		{
			ampulheta2(margem, i, areia, altura2, altura);
			margem--;
			altura2++;
		}
		base(altura, areia);
	}	
	

}
void base(int xlargura, int xareia)
{
	int i = 0, aux = 1;
	printf("**");

	for (i = 0; i < (2 * xlargura) - 3; i++)
	{
		if (aux % 2 != 0)
		{
			printf(" ");
		}
		else
		{
			printf("*");
		}
		aux++;
	}
	printf("**\n");
}

void ampulheta(int margem, int i, int hareia, int altura2, int altura)
{
	int j;
	printf("*");
	for (j = 0; j < margem; j++)
	{
		printf(" ");
	}
	printf("*");

	for (j = 0; j < (2 *(altura2 -2)-1); j++)
	{
		if (i < hareia)
		{
			printf(" ");
		}
		else
		{
			printf(".");
		}
	}
	if (i < altura -1)
	{
		printf("*");
	}
	
	for (j = 0; j < margem; j++)
	{
		printf(" ");
	}
	
	printf("*");
	printf("\n");
}
void ampulheta2(int margem, int i, int hareia, int altura2, int altura)
{
	int j;
	printf("*");
	for (j = 0; j < margem; j++)
	{
		printf(" ");
	}
	printf("*");

	for (j = 0; j < (2 *(altura2 -2)-1); j++)
	{
		if (i > hareia - 1)
		{
			printf(" ");
		}
		else
		{
			printf(".");
		}
	}
	if (i < altura - 2)
	{
		printf("*");
	}
	
	for (j = 0; j < margem; j++)
	{
		printf(" ");
	}
	
	printf("*");
	printf("\n");
}

