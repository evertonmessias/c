#include <stdio.h>
main() {
float x = 10 , *p;
p = &x;
printf ("p = %d\n",p); // 2293528
p++; // somou 4bytes, como no inteiros, veja :
printf ("p = %d\n",p); // 2293532
}// hoje, sistemas de 64bits tem 4bytes para int ou float, difere apenas na precisão.
