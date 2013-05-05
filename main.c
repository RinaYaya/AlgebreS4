#include "prompt.h"
#include "operations.h"
#include "matrix.h"
#include "resol.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define N 50
//----------------------------------------------------------------------
int main ()
{

int iQuit =0;
char s[50];
char s2[50];
char s1[50];
char s3[50];
char Temp[50];
Matrice	TabMat[10];
Nombre TabNombre[10];
int iVar=0, iMat=0, Ligne=0, Col=0, iCptL=0, iCptC=0, iT=0,i=0,ouvert=0;

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
		else
		{
			if(strcmp(s2,"matrix")==0)
			{
				printf(" Entrer dans matrix \n");
				i=0;
				iT=0;
				iCptC=0;
				iCptL=0;
				Ligne=NbLigne(s);
				Col=NbColonne(s);
				Col++;
				printf(" L %d C %d %s \n",Ligne,Col,s);
				TabMat[iMat]=NewMatrice(s1,s2);
					while( (i<N)&&(s[i] != ':'))
					{
						printf("%c ",s[i]);
						i++;
					}
				while((i<N)&&(s[i] != '\0'))
				{

					
					if(s[i] == '[')
					{
						printf(" 		Entrer [ \n");
						ouvert=1;
						iCptL++;
					}
					
					if(s[i]== ']')
					{
						ouvert =0;
					}
					
					if(((s[i]>='0')&&(s[i]<='9'))&&(ouvert==1))
					{
						printf(" 	Entrer dans 0-9 \n");
						Temp[iT]=s[i];
						iT++;
					}
					
					if((s[i] == ',')&&(ouvert == 1)
					{
						printf(" 	Entrer dans , ] \n");
						Temp[iT]='\0';
						printf(" AJOUT %f \n",atof(Temp));
						setElt(TabMat[iMat]->matrice, iCptL-1,iCptC, atof(Temp));
						iCptC++;
						iT=0;
						
					}
					i++;
				}
				iMat++;
				for(iCptL=0; iCptL <Ligne; iCptL++)
				{
					for(iCptC=0; iCptC<Col; iCptC++)
					{
						printf("%f ",getElt(TabMat[iMat-1]->matrice, iCptL, iCptC));
					}
					
					printf("\n");
				}
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
											TabNombre[iVar]=NewNombre(s1,atof(s2));
											printf(" %s = %f \n",TabNombre[iVar]->variable,TabNombre[iVar]->valeur);
											iVar++;
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
