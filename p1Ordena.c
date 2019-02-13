#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int ehprimo(int x);
void ordenaarrays(int array[], float array2[], int n);
int main()
{
	int n;
	scanf("%d", &n);
	
	int i, array[n];
	float array2[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	system("clear");
	for (i = 0; i < n; i++)
	{
		if (ehprimo(array[i]))
		{
			array2[i] = array[i] * 3;
		}
		else
		{
			if (i != 0 && i != n-1)
			{	
				if (array[i] % 2 != 0)
				{
					array2[i] = (float)(array[i-1] + array[i+1]) / 2;
				}
				else
				{
					array2[i] = array[i];
				}
			}
			else
			{
				if (array[i] % 2 != 0)
				{
					if (i == 0)
					{
						array2[i] = (float)(array[i+1] + array[n-1]) / 2;
					}
					else
					{
						array2[i] = (float)(array[n-2] + array[0]) / 2;
					}
				}
				else
				{
					array2[i] = array[i];
				}
			}
		}
		printf("%.1f ", array2[i]);
	}
	printf("\nANTES: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	ordenaarrays(array, array2, n);
	printf("\nORDENADO: ");
	for (i = 0; i < n; i++)
	{
		printf("%.1f ", array2[i]);
	}
	
}
int ehprimo(int x)
{
	int i;
	if (x == 2)
	{
		return 1;
	}
	else if (x % 2 == 0 || x == 1 || x == 0)
	{
		return 0;
	}	
	else
	{
		for (i = 3; i <= sqrt(x); i+=2)
		{
			if (x % i == 0)
			{
				return 0;
			}
		}
		
		return 1;
	}	
}
void ordenaarrays(int array[], float array2[], int n)
{
	int i, j, aux1, aux2;

	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if (array2[i] > array2[j])
			{
				aux2 = array[i];
				array[i] = array[j];
				array[j] = aux2;

				aux1 = array2[i];
				array2[i] = array2[j];
				array2[j] = aux1;


			}	
		}
	}
	printf("\nMAGICA: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}

}