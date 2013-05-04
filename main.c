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

int iQuit =0;
char s[50];
char s2[50];
char s1[50];

	while(iQuit == 0)
	{	
		printf("> ");
		LireChaine(s);
		Argument(s,s2,0);
		Argument(s,s1,1);
		
		if(strcmp(s1,"quit") ==0)
		{
			iQuit=1;
		}
	}




	printf(" %s | %s \n",s2,s1);


  return 0;
}
//----------------------------------------------------------------------
