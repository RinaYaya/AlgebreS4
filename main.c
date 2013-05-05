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
	
	//~ Matrix m = newMatrix(3,3);
	//~ int i=0,j=0;
	//~ float k=0.0;
	//~ for(i=0; i<3; i++)
	//~ {
		//~ for(j=0; j<3; j++)
		//~ {
			//~ setElt(m,i,j,k);
			//~ k++;
		//~ }
	//~ }
	//~ 
	//~ for(i=0; i<3; i++)
	//~ {
		//~ for(j=0; j<3; j++)
		//~ {
			//~ printf(" %f ",getElt(m,i,j));
		//~ }
		//~ printf("\n");
	//~ }
	//~ 

int iQuit =0;
char s[50];
char s2[50];
char s1[50];
char s3[50];
char Temp[50], tmp1[1][50];
Matrice	TabMat[10];
Nombre TabNombre[10];
int iVar=0, iMat=0, Ligne=0, Col=0, iCptL=0, iCptC=0, iT=0,i=0,ouvert=0, imult=0, imult2=0, i1=0, i2=0;

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
				
				TabMat[iMat]=NewMatrice(s1,Ligne, Col);
					while( (i<N)&&(s[i] != ':'))
					{
						i++;
					}
					i=i+2;
					
					
				while((i<N)&&(s[i] != '\0'))
				{
					
					if(s[i] == '[')
					{
					}
					

					if(((s[i]>='0')&&(s[i]<='9')))
					{
						Temp[iT]=s[i];
						iT++;
					}
					
					if((s[i] == ',')||(s[i] == ']'))
					{
						//~ printf(" 	Entrer dans , ] \n");
						Temp[iT]='\0';
						setElt(TabMat[iMat]->matrice, iCptL+1,iCptC+1, atof(Temp));
						iCptC++;
						iT=0;
						
					}
					
					if(s[i]== ']')
					{
						i++;
						ouvert =0;
						iCptC=0;
						iCptL++;
					}
					i++;
				}
				for(iCptL=1; iCptL <Ligne+1; iCptL++)
				{
					for(iCptC=1; iCptC<Col+1; iCptC++)
					{
						printf("m[ %d ][ %d ] = %f",iCptL,iCptC,getElt(TabMat[iMat]->matrice, iCptL, iCptC));
					}
					
					printf("\n");
				}
				iMat++;

			}
			else
				if(strcmp(s2,"mult")==0)
				{
					i=0;
					imult=0;
					imult2=0;
					while((i<N)&&(s[i] != '\0'))
					{
						while(s[i] != '(')
						{
							i++;
						}
						
						if((s[i] != ' ')&&(s[i] != '('))
						{
							tmp1[imult][imult2]=s[i];
							imult2++;
						}
						
						if(s[i] == ',')
						{
							imult++;
							imult2=0;
						}
						i++;
					}
					
					for(i=0; i<iMat; i++)
					{
						if(strcmp(TabMat[i]->nom,tmp1[0]) == 0)
						{
							i1=i;
						}
						if(strcmp(TabMat[i]->nom,tmp1[1]) == 0)
						{
							i2=i;
						}	
					}
					 
					
					TabMat[iMat]=NewMatrice(s1,TabMat[i1]->matrice->nrows,TabMat[i2]->matrice->ncols );
					printf("%s: %d %s : %d \n",TabMat[i1]->nom,TabMat[i1]->matrice->nrows,TabMat[i2]->nom,TabMat[i2]->matrice->ncols);
					strcpy(TabMat[iMat]->nom, s1);
					TabMat[iMat]->matrice=multiplication(TabMat[i1]->matrice,TabMat[i2]->matrice);
					
					for(iCptL=1; iCptL <TabMat[i2]->matrice->nrows+1; iCptL++)
					{
						for(iCptC=1; iCptC<TabMat[i1]->matrice->ncols+1; iCptC++)
						{
							printf("m[ %d ][ %d ] = %f",iCptL,iCptC,getElt(TabMat[iMat]->matrice, iCptL, iCptC));
						}
						
						printf("\n");
					}
					iMat++;
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
