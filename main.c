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
		Matrice	TabMat[10];
		Nombre TabNombre[10];
		int iVar=0;
		printf("> ");
		LireChaine(s);
		Argument(s,s2,0);
		Argument(s,s1,1);
		
		
		if(strcmp(s1,"quit") ==0)
		{
			iQuit=1;
		}
		else
		{
			if(strcmp(s2,"matrix")==0)
			{
				
			}
			else
				if(strcmp(s2,"mult")==0)
				{
					printf(" Multiplication \n");
				}
				else
					if(strcmp(s2,"invert")==0)
					{
						printf(" inverse \n");
					}
					else
						if(strcmp(s2,"determinant")==0)
						{
							printf(" Det \n");
						}
						else
							if(strcmp(s2,"solve")==0)
							{
								printf(" solve \n");
							}
							else
								if(strcmp(s2,"rank")==0)
								{
									printf(" rang \n");
								}
								else
									if(strcmp(s2,"speedtest")==0)
									{
										printf(" SP \n");
									}
									else
										if((s2[0] >= '0')&&(s2[0] <= '9'))
										{
											TabNombre[iVar]=NewNombre(s1,atoi(s2));
											printf(" %s = %d \n",TabNombre->variable,TabNombre->valeur);
										}
										else
										{
											printf("%s : function not implemented \n",s2);
										}
		}
	}
  return 0;
}
//----------------------------------------------------------------------
