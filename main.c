#include "prompt.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//----------------------------------------------------------------------
int main ()
{

char s[50];

	while(1)
	{
		printf("> ");
		LireChaine(s,50);
		printf("%s \n",s);
	}

  return 0;
}
//----------------------------------------------------------------------
