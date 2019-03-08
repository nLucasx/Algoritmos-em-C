#include <stdio.h>
#include <stdlib.h>
int retornaM(int modulo[], int n);
int mdc(int a, int b);
void ms(int mzoes[], int n, int m, int modulo[]);
int inverso(int a, int m);
//funções utilizadas no programa.
//Tarefas 9 e 10 Matemática Discreta.
//Prof: Lucas Amorim.

int main()
{
    int n, i, j, m, xo = 0;
    system("clear");
    printf("Digite o numero de congruencias: ");
    scanf("%d", &n);

    int modulo[n], b[n], mzoes[n], solucoes[n];

    printf("\nEx: x ≡ b mod m\n");
    printf("Digite os valores de b e os modulos das congruencias: ");
    
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &b[i], &modulo[i]); // lendo os valores de b e m
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (mdc(modulo[i], modulo[j]) != 1) // verificando se os modulos sao coprimos.
            {
                printf("Os modulos nao sao coprimos!\nFechando...\n");
                return 0;
            }
        }
    }
    
    m = retornaM(modulo, n); // Calculando o valor de M.
    ms(mzoes, n, m, modulo); // Calculando o valor de M1, M2, Mi...

    for (i = 0; i < n; i++) // calculando os inversos das congruências Mi * x ≡ 1 (mod m).
    {
        if (inverso(mzoes[i], modulo[i]) >= 0)
        {
            solucoes[i] = inverso(mzoes[i], modulo[i]);
        }
        else
        {
            solucoes[i] = inverso(mzoes[i], modulo[i]);
            while (1) // aplicando um loop infinito somando o modulo m até encontrar a solução única.
            {
                solucoes[i] += modulo[i];
                if (solucoes[i] >= 0) // entre 0 e m.
                {
                    break;
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        xo += mzoes[i] * b[i] * solucoes[i]; // calculando xo.
    }
    
    if (xo > m)
    {
        xo = xo % m; // se o valor de xo passar do valor de M, a solução única será xo mod m.
    }

    system("clear");
    for (i = 0; i < n; i++)
    {
        printf("x ≡ %d (mod %d)     ", b[i], modulo[i]); // mostrando as congruências na tela do usuário.
        if (i % 2 == 0 && i != 0)
        {
          printf("\n"); // printar de 3 em 3 congruências. 
        }
    } 
    
    printf("\n\n");
    printf("A solucao para o sistema de congruencias eh: %d\n", xo);

    //Esta é a tarefa 10 que é a extensão da tarefa 9: "encontrar a solução para o sistema de n congruências utilizando o Teorema Chinês do Resto."
    //Tarefa 10 concluída.



    
}
int mdc(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return mdc(b, a%b);
    }
}
int retornaM(int modulo[], int n)
{
    int m = 1, i;

    for (i = 0; i < n; i++)
    {
        m = m * modulo[i];
    }
    return m;
}
void ms(int mzoes[], int n, int m, int modulo[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        mzoes[i] = m / modulo[i];
    }
}
int inverso(int a, int m)
{
  int quocientes[100000], i = 0, aux, j, r, resposta[100000], k =0, finala, finalb;

  finala = a;
  finalb = m;
  while (m != 0)
  {
    quocientes[i] = a / m;
    i++;
    r = a % m;
    a = m;
    m = r;
    
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
    if (finala > finalb)
    {
        return -resposta[k-1];
    }
    else
    {
        return resposta[k];
    }
  }
  else
  {
    if (finala > finalb)
    {
        return resposta[k-1];
    }
    else
    {
        return resposta[k];
    }
  }
}
