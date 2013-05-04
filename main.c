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



	Argument(s,s2,1);
	Argument(s,s1,2);
	printf("| %s | %s | %s \n",s1,s2,s);
	//~ switch (s2)
	//~ {
		//~ case "a":
				//~ break;
				//~ 
	//~ }

  return 0;
}
//----------------------------------------------------------------------
