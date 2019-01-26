#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int vetor[1000000], n, i, j, k, aux = 0, meio, inicio, fim, aux2 = 0, teste = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &vetor[i]);
		aux++;
	}
	
	scanf("%d", &k);
	while (1)
	{
	    inicio = 0;
		fim = aux - 1;
	    while (inicio <= fim)
	    {
	        meio = (inicio + fim) / 2;
	        if (vetor[meio] + vetor[aux2] == k && vetor[meio] != vetor[aux2])
	        {
	            printf("%d %d", vetor[aux2], vetor[meio]);
	            teste = 4;
	            break;
	            
	        }
	        else if (vetor[meio] + vetor[aux2] > k)
	        {
	            fim = meio - 1;
	        }
	        else if (vetor[meio] + vetor[aux2] < k)
	        {
	            inicio = meio + 1;
	        }

	    }
	    aux2++;
	    if (teste == 4)
	    {
	        break;
	    }
	}
	
	return 0;
}
