# include <stdio.h>
struct exemplo {
    int x,y,z,w;};
main() {
printf ("char = %d\n",sizeof (char)); // 1 byte
printf ("int = %d\n",sizeof (int)); // 4 bytes
printf ("float = %d\n",sizeof (float)); // 4 bytes
printf ("double = %d\n",sizeof (double)); // 8 bytes
printf ("struct = %d\n",sizeof (struct exemplo));} // 4*4 = 16 bytes
