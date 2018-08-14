#include <stdio.h>
#include <stdlib.h>
int main () {
    int mat [3][4],i,j;
    for (i=0;i<3;i++){
        for (j=0;j<4;j++){
            printf ("Digite um numero para mat[%i][%i]\n",i,j);
            scanf ("%d",&mat[i][j]);
        }
    }
    printf("\n\n\n");
    for (i=0;i<3;i++){
        for (j=0;j<4;j++){
            printf ("%d ",mat[i][j]);
        }
        printf ("\n");
    }
    system ("pause");
    return 0;
    }
