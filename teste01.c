#include <stdio.h>
#include <conio.h> /* Este programa usa conio.h e não funciona no Unix */
int main ()
{
char letra; // para obter o cod ASCII troque char por int ...
letra=getch();  // No Unix usar: scanf("%c", & letra). Desvantagem; tem q pressionar <ENTER>
printf ("Voce pressionou a tecla %c",letra);
}
