#include <stdio.h>
main() {
    int x=10,*p=&x,**p2=&p;
    printf ("p2 : %d\n", p2);// &p
    printf ("*p2 : %d\n",*p2); //&x
    printf ("**p2 : %d\n",**p2);} //x
