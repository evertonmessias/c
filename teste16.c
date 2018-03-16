#include <stdio.h>
int main() {
int x=10,*p=NULL;
p = &x;
printf ("x = %d\n",x); // 10, o valor em x
printf ("*p = %d\n",*p); // 10 , aponta para o end de x que contem 10
printf ("&x = %d\n",&x); // 2293532, o end de x
printf ("p = %d\n",p); // 2293532, o end de x pois ele recebeu o end de x
printf ("&p = %d\n",&p); } // 2293528 o end do ponteiro
