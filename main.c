#include "prompt.h"
#include "operations.h"
#include "matrix.h"
#include "resol.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//----------------------------------------------------------------------
int main ()
{

char s[50];
char s2[50];
char s1[50];
	
		printf("> ");
		LireChaine(s);



	Argument(s,s2,0);
	Argument(s,s1,1);
	printf(" %s | %s \n",s2,s1);
	//~ switch (s2)
	//~ {
		//~ case "a":
				//~ break;
				//~ 
	//~ }

  return 0;
}
//----------------------------------------------------------------------
