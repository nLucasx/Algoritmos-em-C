#include <stdio.h>
#include <stdlib.h>

void preenche(char matriz[3][3]);
void jogo(char matriz[3][3], int vez, int flag);
int verifica(char matriz[3][3]);
int draw(char matriz[3][3]);

int main()
{
	char tabuleiro[3][3];
	preenche(tabuleiro);
	jogo(tabuleiro, 0, 1);


}
void preenche(char matriz[3][3])
{
	int i, j;
	char cont = '1';
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			matriz[i][j] = cont;
			cont++;
		}
	}
}
void jogo(char matriz[3][3], int vez, int flag)
{
	int escolha;
	char jogador;
	system("clear");

	printf("\n\n      ============ TIC TAC TOE ============\n\n\n");
	printf("                    |     |      \n");
	printf("                %c   |  %c  |   %c  \n", matriz[0][0], matriz[0][1], matriz[0][2]);
	printf("               _____|_____|______\n");
	printf("                    |     |      \n");
	printf("                %c   |  %c  |   %c  \n", matriz[1][0], matriz[1][1], matriz[1][2]);
	printf("               _____|_____|______\n");
	printf("                    |     |      \n");
	printf("                %c   |  %c  |   %c  \n\n\n\n", matriz[2][0], matriz[2][1], matriz[2][2]);

	if (draw(matriz))
	{
		flag = -1;
	}
	if (verifica(matriz) == 1)
	{
		printf("\nO jogador 'O' venceu!\n\n");
		flag = 0;
	}
	else if (verifica(matriz) == 2)
	{
		printf("\nO jogador 'X venceu!\n\n");
		flag = 0;
	}
	if (flag > 0)
	{

		if (vez % 2 == 0)
		{
			jogador = 'X';
			printf("\nVez do X, escolha uma casa: ");
		}
		else
		{
			jogador = 'O';
			printf("\nVez do O, escolha uma casa: ");
		}

		while (1)
		{	
			scanf("%d", &escolha);
			if (escolha == 1)
			{
				if (matriz[0][0] != '1')
				{
					printf("Esta casa ja foi usada, escolha outra: ");
				}
				else
				{
					break;
				}	
			}
			else if (escolha == 2)
			{
				if (matriz[0][1] != '2')
				{
					printf("Esta casa ja foi usada, escolha outra: ");
				}
				else
				{
					break;
				}	
			}
			else if (escolha == 3)
			{
				if (matriz[0][2] != '3')
				{
					printf("Esta casa ja foi usada, escolha outra: ");
				}
				else
				{
					break;
				}	
			}
			else if (escolha == 4)
			{
				if (matriz[1][0] != '4')
				{
					printf("Esta casa ja foi usada, escolha outra: ");
				}
				else
				{
					break;
				}	
			}
			else if (escolha == 5)
			{
				if (matriz[1][1] != '5')
				{
					printf("Esta casa ja foi usada, escolha outra: ");
				}
				else
				{
					break;
				}	
			}
			else if (escolha == 6)
			{
				if (matriz[1][2] != '6')
				{
					printf("Esta casa ja foi usada, escolha outra: ");
				}
				else
				{
					break;
				}	
			}
			else if (escolha == 7)
			{
				if (matriz[2][0] != '7')
				{
					printf("Esta casa ja foi usada, escolha outra: ");
				}
				else
				{
					break;
				}	
			}	
			else if (escolha == 8)
			{
				if (matriz[2][1] != '8')
				{
					printf("Esta casa ja foi usada, escolha outra: ");
				}
				else
				{
					break;
				}	
			}
			else if (escolha == 9)
			{
				if (matriz[2][2] != '9')
				{
					printf("Esta casa ja foi usada, escolha outra: ");
				}
				else
				{
					break;
				}	
			}
			else
			{
				printf("Casa invalida, escolha outra: ");
			}

		}
	}
	if (flag > 0)
	{
		if (escolha == 1)
		{
			matriz[0][0] = jogador;
		}
		else if (escolha == 2)
		{
			matriz[0][1] = jogador;
		}
		else if (escolha == 3)
		{
			matriz[0][2] = jogador;
		}
		else if (escolha == 4)
		{
			matriz[1][0] = jogador;
		}
		else if (escolha == 5)
		{
			matriz[1][1] = jogador;
		}
		else if (escolha == 6)
		{
			matriz[1][2] = jogador;
		}
		else if (escolha == 7)
		{
			matriz[2][0] = jogador;
		}
		else if (escolha == 8)
		{
			matriz[2][1] = jogador;
		}
		else if (escolha == 9)
		{
			matriz[2][2] = jogador;
		}
		vez++;
		jogo(matriz, vez, flag);
	}
	else
	{
		if (flag == -1)
		{
			printf("\nHouve empate!\n\n");
		}
	}
}
int verifica(char matriz[3][3])
{
	int l, c, contO = 0, contX = 0;
	//verifica horizontais
	for (l = 0; l < 3; l++)
	{
		for (c = 0; c < 3; c++)
		{
			if (matriz[l][c] == 'O')
			{
				contO++;
			}
			else if (matriz[l][c] == 'X')
			{
				contX++;
			}
		}
		if (contO == 3)
		{
			return 1;
		}
		else
		{
			contO = 0;
		}
		if (contX == 3)
		{
			return 2;
		}
		else
		{
			contX = 0;
		}
	}

	//verifica verticais
	for (c = 0; c < 3; c++)
	{
		for (l = 0; l < 3; l++)
		{
			if (matriz[l][c] == 'O')
			{
				contO++;
			}
			else if (matriz[l][c] == 'X')
			{
				contX++;
			}
		}
		if (contO == 3)
		{
			return 1;
		}
		else
		{
			contO = 0;
		}
		if (contX == 3)
		{
			return 2;
		}
		else
		{
			contX = 0;
		}
	}

	//verifica diagonal principal
	for (l = 0; l < 3; l++)
	{
		if (matriz[l][l] == 'X')
		{
			contX++;
		}
		else if (matriz[l][l] == 'O')
		{
			contO++;
		}
	}
	if (contO == 3)
	{
		return 1;
	}
	else
	{	
		contO = 0;
	}
	if (contX == 3)
	{
			return 2;
	}
	else
	{
		contX = 0;
	}

	//verifica diagonal secundaria
	c = 0;
	for (l = 2; l >= 0; l--)
	{
		if (matriz[l][c] == 'X')
		{
			contX++;
		}
		else if (matriz[l][c] == 'O')
		{
			contO++;
		}
		c++;
	}
	if (contO == 3)
	{
		return 1;
	}
	else
	{	
		contO = 0;
	}
	if (contX == 3)
	{
			return 2;
	}
	else
	{
		contX = 0;
	}
	return 0;
}

int draw(char matriz[3][3])
{
	int l, c, cont = 0;
	for (l = 0; l < 3; l++)
	{
		for (c = 0; c < 3; c++)
		{
			if (matriz[l][c] == 'X' || matriz[l][c] == 'O')
			{
				cont++;
			}
		}
	}
	if (cont == 9)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}