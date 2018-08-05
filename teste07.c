#include <stdio.h>
int main () {

    int num,fat=1;

    printf("Digite um numero: ");
    scanf("%d",&num);

    if (num == 0){
    printf("\nFatorial: %d ",fat);
    }else{

    while(num > 0){
    fat = fat * num;
    num--;
    }
    printf("\nFatorial: %d ",fat);
    }
}
