#include "prompt.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//----------------------------------------------------------------------
int main ()
{

char s[50];
char s2[50];
	while(1)
	{
		printf("> ");
		LireChaine(s,50);
		printf("%s \n",s);
	}

	Argument1(s,s2);
	
	printf(" RECUPERE : %s \n",s2);

  return 0;
}
//----------------------------------------------------------------------
