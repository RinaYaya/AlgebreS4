#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main ()
{

char s[50];
int i=0;
	while(1)
	{
		i=0;
		//on vide le buffer
		while(s[i] != '\0')
		{
			i++;
		}
		
		printf("> ");
		scanf("%s ",s);
		printf("%s \n",s);
		
		
	}

  return 0;
}
