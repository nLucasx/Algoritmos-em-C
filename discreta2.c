#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void combinacaol(int a, int b);

int main()
{
	int a, b;

	scanf("%d%d", &a, &b);
	combinacaol(a,b);
	return 0;
}
void combinacaol(int a, int b)
{
	int quocientes[100000], i = 0, aux, j, r, resposta[100000], k =0, finala, finalb;
	
	if (b > a)
	{
		aux = b;
		b = a;
		a = aux;
	}
	finala = a;
	finalb = b;
	while (b != 0)
	{
		quocientes[i] = a / b;
		i++;
		r = a % b;
		a = b;
		b = r;
		
	}
	resposta[0] = 1;
	for (j = i-2; j >= 0; j--)
	{
		if (k == 0)
		{
			resposta[k+1] = quocientes[j] * resposta[k];
			k++;
		}
		else
		{
			resposta[k+1] = (quocientes[j] * resposta[k]) + (resposta[k-1]);
			k++;
		}
	}
	if (k % 2 == 0)
	{
		system("clear");
		printf("MDC = COMBINACAO LINEAR ENTRE %d %d:\n", finala, finalb);
		printf("%d = (-%d) * %d + (%d) * %d", a, resposta[k-1], finala, resposta[k], finalb);
	}
	else
	{
		system("clear");
		printf("MDC = COMBINACAO LINEAR ENTRE %d %d:\n", finala, finalb);
		printf("%d = (%d) * %d + (-%d) * %d", a, resposta[k-1], finala, resposta[k], finalb);	
	}
	printf("\n");
	//tarefa 6 mat discreta.
}
