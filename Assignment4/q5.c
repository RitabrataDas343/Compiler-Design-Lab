#include <stdio.h>
#include <stdlib.h>

#define L_SIZE 5
#define D_SIZE 5
#define UNION_SIZE (L_SIZE + D_SIZE)
#define LD_SIZE (L_SIZE * D_SIZE)
#define LU_D_SIZE (L_SIZE * UNION_SIZE)

char L[L_SIZE] = {'a', 'b', 'c', 'd', 'e'};
char D[D_SIZE] = {'0', '1', '2', '3', '4'};
char union_LD[UNION_SIZE];
char LD[LD_SIZE][2];
char LU_D[LU_D_SIZE][2];

int main()
{
   int i, j, k;
   for (i = 0; i < L_SIZE; i++)
   {
      union_LD[i] = L[i];
   }
   for (j = 0; j < D_SIZE; j++)
   {
      union_LD[i + j] = D[j];
   }

   printf("L union D: {");
   for (k = 0; k < UNION_SIZE; k++)
   {
      if(k == UNION_SIZE-1) printf("%c}", union_LD[k]);
      else printf("%c, ", union_LD[k]);
   }
   printf("\n\n");

   int l, m;
   for (l = 0; l < L_SIZE; l++)
   {
      for (m = 0; m < D_SIZE; m++)
      {
         LD[l * D_SIZE + m][0] = L[l];
         LD[l * D_SIZE + m][1] = D[m];
      }
   }

   printf("LD: {");
   for (l = 0; l < LD_SIZE; l++)
   {
      if(l == LD_SIZE-1) printf("%c%c}", LD[l][0], LD[l][1]);
      else printf("%c%c, ", LD[l][0], LD[l][1]);
   }
   printf("\n\n");

   int n, o;
   for (n = 0; n < L_SIZE; n++)
   {
      for (o = 0; o < UNION_SIZE; o++)
      {
         LU_D[n * UNION_SIZE + o][0] = L[n];
         LU_D[n * UNION_SIZE + o][1] = union_LD[o];
      }
   }

   printf("L(L union D): {");
   for (n = 0; n < LU_D_SIZE; n++)
   {
      if(n == LU_D_SIZE-1) printf("%c%c}", LU_D[n][0], LU_D[n][1]);
      else printf("%c%c, ", LU_D[n][0], LU_D[n][1]);
      
   }
   printf("\n");

   return 0;
}
