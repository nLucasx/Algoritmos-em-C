#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int ehprimo(int x);
int mdc(int a, int b);
int combinacaol(long int a, long int b, int quocientes[], int resposta[]);
int RSA(long int a, long int e, long int n);
long int proxprime(long int numero);
void acharprimos(long int primos [0] , long long  n);

long long int firstprimes [2000000];
int uprimo=1, produto = 0, decisao = 1;


int main()
{
	long long int p, q, n, d, e, totiente, i = 0, resposta1, aux, j = 0, teste1, primos[2];
	int quocientes[100000], resposta[100000], teste2, auxd;
	char frase[5000], caract[10], decodificado[10000];

	system("clear");
	system("setterm -foreground yellow");
	system("figlet RSA ENCRYPTION");


	printf("[1] - GERAR CHAVES PUBLICA E PRIVADA\n");
	printf("[2] - CODIFICAR\n");
	printf("[3] - DECODIFICAR\n");
	printf("[4] - QUEBRAR CRIPTOGRAFIA\n");
	system("setterm -foreground white");
	printf("\n");
	printf("RSA > ");
	scanf("%lld", &resposta1);

	if (resposta1 == 1) 
	{	
		printf("RSA > DIGITE SEUS DOIS PRIMOS: ");
		scanf("%lld%lld", &p, &q);

		if (ehprimo(p) != 1 || ehprimo(q) != 1)
		{
			printf("Voce digitou algum numero nao primo, entre com primos!\n");
			return 0;
		}
		else
		{
			n = p * q;
			totiente = (p - 1) * (q - 1);

			printf("\nφ(n) = %lld\n", totiente);
			printf("DIGITE UM VALOR PARA 'e', (1 < e < %lld)\n\n", totiente);
			printf("RSA > O MDC(%lld, e) deve ser igual a 1, ou seja, devem ser primos entre si!: ", totiente);

			while (1)
			{
				scanf("%lld", &e);
				if (e >= totiente || e <= 1)
				{
					printf("O valor de 'e' deve ser entre 1 e %lld, digite um outro 'e': ", totiente);
				}
				else if (mdc(totiente, e) == 1)
				{
					system("clear");
					system("setterm -foreground green");
					printf("Valor de 'e' valido!\n\n");
					break;
				}
				else
				{
					printf("O mdc nao eh 1, digite um outro 'e': ");
				}

			}
			auxd = combinacaol(totiente, e, quocientes, resposta);
			if (auxd < 0)
			{
				for (;;)
				{
					auxd = auxd + totiente;
					if (auxd >= 0)
					{
						break;
					}
				}
			}
			d = auxd;

			system("setterm -foreground cyan");
			printf("Suas chaves publicas sao: %lld e %lld\n", n, e);
			printf("Suas chaves privadas sao: %lld, %lld e %lld\n", p, q, d);
		}
	}
	else if (resposta1 == 2)
	{
		printf("RSA > DIGITE AS CHAVES PUBLICAS 'n' e 'e': ");
		scanf("%lld%lld", &n, &e);

		printf("RSA > DIGITE A MENSAGEM A SER CODIFICADA: ");
		getchar();
		scanf("%[^\n]s", frase);
		system("clear");
		system("setterm -foreground red");
		printf("SUA MENSAGEM CODIFICADA:\n");
		system("setterm -foreground green");
		for (i = 0; i < strlen(frase); i++)
		{	
			printf("%d ", RSA(frase[i], e, n));
		}
		printf("\n\n\n\n\n"); 

	}
	else if (resposta1 == 3)
	{
		printf("RSA > DIGITE OS NUMEROS PRIMOS: ");
		scanf("%lld%lld", &p, &q);
		printf("RSA > DIGITE O VALOR DE d: ");
		scanf("%lld", &d);
		printf("RSA > DIGITE O CODIGO A SER DESCRIPTOGRAFADO: ");
		n = p * q;
		for (;;)
		{
			scanf("%lld", &teste1);
			decodificado[i] = (char)RSA(teste1, d, n);
			i++;
			if (getchar() == '\n')
			{
				system("clear");
				system("setterm -foreground red");
				printf("MENSAGEM DECODIFICADA:\n");
				system("setterm -foreground green");
				for (i = 0; i < strlen(decodificado); i++)
				{
					printf("%c", decodificado[i]);
				}
				printf("\n\n\n\n\n");
				break;
			}
		}


	}
	else if (resposta1 == 4)
	{
		long int primos[2];
		printf("RSA > Digite a chave pública 'n': ");
		scanf("%lld", &n);
		acharprimos(primos, n);
		printf("%ld %ld\n", primos[0], primos[1]);

	}
}

int ehprimo(int x)
{
	int i = 0, cont = 0;
	if ((x % 2 == 0 && x != 2) || x == 1)
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

int mdc(int a, int b)
{
	int resto;

	if (b == 0)
	{
		return a;
	}
	else
	{
		return mdc(b, a % b);
	}
}

int combinacaol(long int a, long int b, int quocientes[], int resposta[])
{
	int i = 0, aux, j, r, tam = 0;
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
		if (tam == 0)
		{
			resposta[tam+1] = quocientes[j] * resposta[tam];
			tam++;
		}
		else
		{
			resposta[tam+1] = (quocientes[j] * resposta[tam]) + (resposta[tam-1]);
			tam++;
		}
	}
	if (tam % 2 == 0)
	{
		return resposta[tam];
	}
	else
	{
		return -resposta[tam];	
	}
}
int RSA(long int a, long int e, long int n){
	
	long long int A = a, P = 1, E = e;
	
	while(1){

		//Chegou ao fim da expansão, retorna o P
		if(E == 0)
			return P;

		//Se o expoente é ímpar
		else if(E%2 != 0){
			//Realizamos a redução módulo n de cada uma das multpilicações 			
			P = (A * P)%n;
			E = (E-1)/2;
		}

		//Se o expoente é par
		else{
			E = E/2;
		}
		//Obtém a sequência de potências
		A = (A*A)%n;
	}
	
}
long int proxprime(long int numero){
	if(numero==2)
	{
		return 3;
	}
	else
	{
		long int i, notprime=1;
		while(notprime == 1)
		{
			notprime=0;
			if(decisao==1)
			{
				produto++;
				numero = ((6*produto)-1);
				decisao*=(-1);
			}
			else
			{
				numero= ((6*produto)+1);
				decisao*=(-1);
			}
			for(i=0; i<uprimo && firstprimes[i] <= sqrt(numero); i++)
			{
				if(numero%firstprimes[i] == 0 && numero != firstprimes[i])
				{
					notprime= 1;
				}
			}
		}	
		if(uprimo<2000000)
		{
			firstprimes[uprimo]=numero;
			uprimo++;
		}
		printf("%ld\n", numero);

		return numero;
	}
}

void acharprimos(long int primos [0] , long long  n){
	primos[0]=2;
	primos[1]=3;
	firstprimes[0]=3;
	
	int prime1=0, prime2 = 1;
 	while(primos[0]*primos[1]!=n)
 	{
 		if(primos[0] * primos[1] > n)
 		{
 			primos[0] = firstprimes[prime1];
 			prime1++;
 			while(primos[0]*primos[1] > n)
 			{
 				prime2/=2;
 				primos[1] = firstprimes[prime2];
 			}
 		}
 		else
 		{
 			prime2++;
 			primos[1] = (prime2 >= uprimo ? proxprime(primos[1]) : firstprimes[prime2]);
 		}
 	}
}

