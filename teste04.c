#include <stdio.h>
#include <stdlib.h>
#define VET 5
int main () {
    int i;
  int vetor [VET];

  int vetor2 [3] = {1,2,3};

  for (i=0;i<VET;i++){
    scanf("%d", &vetor[i]);
    }


  for (i=0;i<VET;i++){
    printf("%d\t", vetor[i]);
    }

    printf("\n\n");

    for (i=0;i<3;i++){
    printf("%d\t", vetor2[i]);
    }
}
