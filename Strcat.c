#include <stdio.h>
#include <string.h>

int main()
{
   char s1[11] = "Hola";
   char s2[6] = "amigos";

   printf( "s1=%s\t", s1 );
   printf( "s2=%s\n", s2 );
   strcat( s1, s2 );
   printf( "s1=%s\n", s1 );

   return 0;
}
