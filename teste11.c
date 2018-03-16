# include <stdio.h>
enum escapes {retrocesso='\b',tabulacao='\t',novalinha='\n'};
main(){
    enum escapes e = novalinha;
    printf ("Everton%cMendes%cMessias%c",e,e,e);
    system ("pause");return 0;}
