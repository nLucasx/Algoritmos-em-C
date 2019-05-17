#include <stdio.h>
int buscabinaria(int array[], int inicio, int fim, int valor_busca)
{
	int meio = (inicio+fim) /2;

	if (inicio > fim)
	{
		return -1;
	}
	if (array[meio] == valor_busca)
	{
		return meio;
	}
	else if (array[meio] < valor_busca)
	{
		return buscabinaria(array,meio+1, fim, valor_busca);
	}
	else
	{
		return buscabinaria(array,inicio, meio-1, valor_busca);
	}

}
void ordena(int array[], int n)
{
	int i, j, temp;

	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if (array[j] < array[i])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
	printf("Lista de numeros ordenada:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
int main(){
	int n, i, pos, valor;

	printf("Digite a quantidade de numeros >> ");
	scanf("%d", &n);
	printf("Digite os numeros >> ");
	int array[n];

	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	ordena(array, n);
	printf("Qual valor voce quer encontrar na lista? ");
	scanf("%d", &valor);

	
	if (buscabinaria(array,0, n, valor) == -1)
	{
		printf("O numero nao foi encontrado na lista!\n");
	}
	else
	{
		printf("O numero %d foi encontrado na posicao %d", valor, buscabinaria(array,0, n, valor)+1);
	}
}