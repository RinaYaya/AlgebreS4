#include "prompt.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//----------------------------------------------------------------------
int main ()
{

char s[50];
char s2[50];
	
		printf("> ");
		LireChaine(s);

	Argument1(s,s2);
	
	printf(" RECUPERE : %s",s2);
	printf("verif");

  return 0;
}
//----------------------------------------------------------------------
