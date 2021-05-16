#include <stdio.h>
#include <stdlib.h>

/*  SEMINÁRIO: MARATONA DE PROGRAMAÇÃO
    Problem M – Mount Marathon
    FUNDAMENTOS DE PROGRAMAÇÃO
    DÉBORA DE AZEVEDO RODRIGUES
*/

int main ()
{
  FILE *f1 = fopen ("in.txt","r");
  int N_cartas = 0;
  int vetor [52] = {0};
  int j = 0, i = 0,z=0;
  int valor_repetido_count=0;
  printf(" INPUT\n");
  fscanf (f1,"%d", &N_cartas);
  printf ("%d\n",N_cartas);

  if ( N_cartas >= 1 && N_cartas <= 52)
  {
    for (j = 0; j <= N_cartas -1; j++)
    {
      fscanf(f1,"%d",&vetor[j]);
      printf("%d ", vetor[j]);
      if ( vetor[j] < 1 || vetor[j] > 13)
        break;
    }
    fclose(f1);
    for (i = N_cartas - 2; i >=0 ; i--)
    {
      if (vetor[i] >= vetor[i+1])
        N_cartas --;
    }
    printf("\n\n OUTPUT\n");
    printf("%d\n",N_cartas);

    FILE * saida;
    saida = fopen ("sol.txt","w");
    if (saida == NULL)
    {
      printf("Nao foi possivel criar documento de escrita.");
      return 1;
    }else
    {
      fprintf (saida,"%d",N_cartas);
      fclose (saida);
    }
  }
  return 0;
}