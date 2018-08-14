#include <stdio.h>
void imprime (int *v, int tamanho) { // tem q indicar o tamanho do vetor
				int i;
				for (i=0;i<tamanho;i++)
                    printf ("%d \n",v[i]);} // nao precisa do * pois o vetor ja é ponteiro
int main () {
    int v[5] = {1,2,3,4,5};
    imprime (v,5); // nao precisa do & , indicar o tamanho do vetor
    system ("pause");return 0;}
