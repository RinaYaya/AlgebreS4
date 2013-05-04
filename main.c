#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
//----------------------------------------------------------------------
void LireChaine(char chaine[], int size) 
{  
    fgets(chaine, size, stdin);  
    chaine[strlen(chaine) - 1] = '\0';  
}  
//----------------------------------------------------------------------
int main ()
{

char s[50];
int i=0;
	while(1)
	{
		printf("> ");
		LireChaine(s,50);
		printf("%s \n",s);
	}

  return 0;
}
