#include "prompt.h"
#include "operation.h"
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
	
		printf("> ");
		LireChaine(s);

	Argument1(s,s2);
	
	switch (s2)
	{
		case "a":
				break;
				
	}

  return 0;
}
//----------------------------------------------------------------------
