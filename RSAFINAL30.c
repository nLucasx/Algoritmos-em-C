#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ehprimo(int x);
int mdc(int a, int b);
long long int inverso(long long int a, long long int b);
long long int RSA(long long int a, long long int e, long long int n);
long int proxprime(long int numero);
void acharprimos(long long int primos [] , long long  int n);

long long int firstprimes[2000000];
int produto = 0, decisao = 1;


int main()
{
  long long int p, q, n, d, e, totiente, i = 0, j = 0, codigo, primos[2];
  int tamanho = 0, decodificado[100000], k, resposta1;
  char frase[100000], caract[10], alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

  inicio:
  system("clear");
  system("setterm -foreground yellow");
  printf("      =======================================\n");
  printf("      ╦═╗╔═╗╔═╗  ╔═╗╔╗╔╔═╗╦═╗╦ ╦╔═╗╔╦╗╦╔═╗╔╗╔\n"); 
  printf("      ╠╦╝╚═╗╠═╣  ║╣ ║║║║  ╠╦╝╚╦╝╠═╝ ║ ║║ ║║║║\n"); 
  printf("      ╩╚═╚═╝╩ ╩  ╚═╝╝╚╝╚═╝╩╚═ ╩ ╩   ╩ ╩╚═╝╝╚╝\n"); 
  printf("      =======================================\n\n");                                                 
                                                                                             

  printf("      [1] - GERAR CHAVES PUBLICA E PRIVADA\n");
  printf("      [2] - CODIFICAR\n");
  printf("      [3] - DECODIFICAR\n");
  printf("      [4] - QUEBRAR CRIPTOGRAFIA\n");
  system("setterm -foreground red");
  printf("      [0] - SAIR\n");
  printf("\n");
  system("setterm -foreground white");
  printf("RSA > ");
  scanf("%d", &resposta1);

  if (resposta1 == 1) 
  { 
    escolha1:
    printf("RSA > DIGITE SEUS DOIS PRIMOS: ");
    scanf("%lld%lld", &p, &q);

    if (ehprimo(p) != 1 || ehprimo(q) != 1)
    {
      printf("Voce digitou algum numero nao primo, entre com primos!\n");
      goto escolha1;
    }
    else if (p * q < 27)
    {
      printf("Voce digitou primos muito pequenos, (p*q < 27), digite outros!\n");
      goto escolha1;
    }
    else
    {
      n = p * q;
      totiente = (p - 1) * (q - 1);

      printf("\nφ(n) = %lld\n", totiente);
      printf("DIGITE UM VALOR PARA 'e', (1 < e < φ(n))\n");
      printf("O MDC(φ(n), e) deve ser igual a 1, ou seja, devem ser primos entre si!\n\n");

      while (1)
      {
        printf("RSA > ");
        scanf("%lld", &e);
        if (e >= totiente || e <= 1)
        {
          printf("O valor de 'e' deve ser entre 1 e %lld, digite um outro 'e'!\n", totiente);
        }
        else if (mdc(totiente, e) == 1)
        {
          system("setterm -foreground green");
          printf("Valor de 'e' valido!\n\n");
          break;
        }
        else
        {
          printf("O mdc nao eh 1, digite um outro 'e': ");
        }

      }
      d = inverso(totiente, e);

      FILE *chaves;
      chaves = fopen("chaves.txt", "w");
      fprintf(chaves, "Chaves publicas: %lld e %lld\nChaves privadas: %lld, %lld e %lld\n", n, e, p, q, d);
      fclose(chaves); // criacao do arquivo txt contendo as chaves.

      system("setterm -foreground cyan");
      printf("Suas chaves publicas sao: %lld e %lld\n", n, e);
      printf("Suas chaves privadas sao: %lld, %lld e %lld\n", p, q, d);
      system("setterm -foreground yellow");
      printf("\nArquivo Chaves.txt salvo com suas chaves!\n\n");
      printf("[1] - SIM\n");
      printf("[2] - NAO\n");
      system("setterm -foreground white");
      printf("\nDeseja algo mais?\n");
      printf("RSA > ");
      scanf("%d", &resposta1);

      if (resposta1 == 1)
      {
          goto inicio;
      }
      else
      {
          printf("Fechando...\n\n");
      }
    }
  }
  else if (resposta1 == 2)
  {
    printf("RSA > DIGITE AS CHAVES PUBLICAS 'n' e 'e': ");
    scanf("%lld%lld", &n, &e);

    printf("RSA > DIGITE A MENSAGEM A SER CODIFICADA: ");
    getchar();
    fgets(frase, 100000, stdin);
    
    FILE *codificada;
    
    system("clear");
    system("setterm -foreground red");
    printf("SUA MENSAGEM CODIFICADA:\n");
    system("setterm -foreground green");
    
    codificada = fopen("codigo.txt", "w");
    fprintf(codificada, "SUA MENSAGEM CODIFICADA:\n\n");
    
    for (i = 0; i < strlen(frase)-1; i++)
    { 
      for (j = 0; j < strlen(alfabeto); j++)
      {  
          if (toupper(frase[i]) == alfabeto[j])  
          {  
              fprintf(codificada, "%lld ", RSA(j, e, n));
              printf("%lld ", RSA(j, e, n));
              break;
          }
      }
    }
    fclose(codificada); // criacao do arquivo txt contendo a mensagem codificada.

    printf("\n\n"); 
    system("setterm -foreground yellow");
    printf("Arquivo Codigo.txt salvo com sua mensagem codificada!\n\n");
    printf("[1] - SIM\n");
    printf("[2] - NAO\n");
    system("setterm -foreground white");
    printf("\nDeseja algo mais?\n");
    printf("RSA > ");
    scanf("%d", &resposta1);

    if (resposta1 == 1)
    {
        goto inicio;
    }
    else
    {
        printf("Fechando...\n\n");
    }

  }
  else if (resposta1 == 3)
  {
    FILE *decode;

    printf("RSA > DIGITE OS NUMEROS PRIMOS: ");
    scanf("%lld%lld", &p, &q);
    printf("RSA > DIGITE O VALOR DE 'e': ");
    scanf("%lld", &e);

    printf("RSA > DIGITE O CODIGO A SER DESCRIPTOGRAFADO: ");
    n = p * q;
    totiente = (p-1) * (q-1);
    d = inverso(totiente, e);
    tamanho = 0;
    decode = fopen("decode.txt", "w");

    while (1)
    {
      scanf("%lld", &codigo);
      decodificado[tamanho] = RSA(codigo, d, n);
      tamanho++;
      if (getchar() == '\n')
      {
        system("clear");
        system("setterm -foreground red");
        printf("MENSAGEM DECODIFICADA:\n");
        fprintf(decode, "MENSAGEM DECODIFICADA:\n\n");
        system("setterm -foreground green");

        for (k = 0; k < tamanho; k++)
        {
            for (j = 0; j < strlen(alfabeto); j++)
            {
                if (decodificado[k] == j)
                {
                    fprintf(decode, "%c", alfabeto[j]);
                    printf("%c", alfabeto[j]);
                }
            }
        }

        
        printf("\n\n");
        break;
      }
    }
    fclose(decode); // criacao do arquivo txt contendo a mensagem decodificada.

    system("setterm -foreground yellow");
    printf("Arquivo decode.txt salvo com sua mensagem codificada!\n\n");
    printf("[1] - SIM\n");
    printf("[2] - NAO\n");
    system("setterm -foreground white");
    printf("\nDeseja algo mais?\n");
    printf("RSA > ");
    scanf("%d", &resposta1);

    if (resposta1 == 1)
    {
        goto inicio;
    }
    else
    {
        printf("Fechando...\n\n");
    }


  }
  else if (resposta1 == 4)
  {
    long long int quebrarprimos[2];
    printf("RSA > Digite a chave pública 'n': ");
    scanf("%lld", &n);
    acharprimos(quebrarprimos, n);
    printf("%lld %lld\n", quebrarprimos[0], quebrarprimos[1]);

  }
  else
  {
    system("setterm -foreground white");
    printf("Fechando...\n");
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
  if (b == 0)
  {
    return a;
  }
  else
  {
    return mdc(b, a % b);
  }
}

long long int inverso(long long int a, long long int b)
{
  long long int i = 0, j, r, tam = 0, d = 0, totiente, quocientes[100000], resposta[100000];
  totiente = a; // variavel recebe o valor da funcao totiente passada como parametro para nao perdermos seu valor.

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
    d = resposta[tam];
    return d;
  }
  else
  {
    d = -resposta[tam];
    while (1)
    {
        d = d + totiente;
        if (d >= 0)
        {
          break;
        }
    }
    return d;
  }
}
long long int RSA(long long int codigo, long long int expoente, long long int modulo)
{
  
  long long int p = 1;
  
  while(1)
  {
    if(expoente == 0)
    {
      return p;
    }
    else if(expoente % 2 != 0)
    {     
      p = (codigo * p) % modulo;
      expoente = (expoente-1)/2;
    }
    else
    {
      expoente = expoente/2;
    }
    codigo = (codigo * codigo) % modulo;
  }
  
}

void lerprimos()
{
  FILE *primos;
  primos=fopen("primes1.txt", "r");
  long long int i;

  for(i=0; i<1000000; i++)
  {
    fscanf(primos, "%lld", &firstprimes[i]);
    printf("%lld\n", firstprimes[i]);
  }
  
  fclose(primos);
  primos=fopen("primes2.txt", "r");
  for(;i<2000000;i++)
  {
    fscanf(primos, "%lld", &firstprimes[i]);
  }
  fclose(primos);
}

void acharprimos(long long int primos [0] , long long  int n)
{
  lerprimos();
  long long int prime1=0, prime2 = 1;
  primos[0]=firstprimes[prime1];
  primos[1]=firstprimes[prime2];
  while(primos[0]*primos[1]!=n)
  {
    if(primos[0] * primos[1] > n || prime2>=2000000)
    {
      prime1++;
      primos[0] = firstprimes[prime1];
      while(primos[0]*primos[1] > n)
      {
        prime2/=2;
        primos[1] = firstprimes[prime2];
      }
    }
    else
    {
      prime2++;
      if(prime2<2000000){
        primos[1] = firstprimes[prime2];
      }
    }
  }
}