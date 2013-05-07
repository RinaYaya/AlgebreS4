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

arguments a=NULL;

char Temp[50], tmp1[1][50];
Matrice	TabMat[10];
Nombre TabNombre[10];
Matrix m1, m2,m3;
int iVar=0, iMat=0, Ligne=0, Col=0, iCptL=0, iCptC=0, iT=0,i=0,ouvert=0, imult=0, imult2=0;
float ftmp;

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
					

					if(((s[i]>='0')&&(s[i]<='9'))||(s[i] == '-'))
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
					
						while((i<N)&&(s[i] != '('))
						{
							i++;
						}
						
					while((i<N)&&(s[i] != ','))
					{
						if((s[i] != ',')&&(s[i] != ' ')&&(s[i] != '('))
						{
							tmp1[0][imult2]=s[i];
							imult2++;
						}
						i++;
					}
					tmp1[0][imult2]='\0';
					imult2=0;
					while((i<N)&&(s[i] != ')'))
					{
						if((s[i] != ',')&&(s[i] != ' ')&&(s[i] != '('))
						{
							tmp1[1][imult2]=s[i];
							imult2++;
						}
						i++;
					}
					tmp1[1][imult2]='\0';
					
					printf("%s x %s \n",tmp1[0],tmp1[1] );
					
					i=0;
					
					while(i<iMat)
					{
						if(strcmp(TabMat[i]->nom,tmp1[0])==0)
						{
							printf("\n Matrice : %s chargée \n",tmp1[0]);
							m1=TabMat[i]->matrice;
						}
						
						if(strcmp(TabMat[i]->nom,tmp1[1])==0)
						{
							printf("Matrice : %s chargée \n",tmp1[1]);
							m2=TabMat[i]->matrice;
						}
						i++;
					}
					
					TabMat[iMat]=NewMatrice(s1,m1->nrows,m2->ncols);
					m3=multiplication(m1,m2);
					
					for(iCptL=1;iCptL<= m3->nrows; iCptL++)
					{
						for(iCptC=1; iCptC <= m3->ncols; iCptC++)
						{
							printf("%f ",getElt(m3,iCptL,iCptC));
						}
						printf("\n");
					}
					TabMat[iMat]->matrice=m3;
					iMat++;
				}
				else
					if(strcmp(s2,"invert")==0)
					{
						printf(" inverse \n");
					}
					else
						if(strcmp(s2,"det")==0)
						{
							i=0;
							imult=0;
							imult2=0;
					
							while((i<N)&&(s[i] != '('))
							{
								i++;
							}
								
							while((i<N)&&(s[i] != ')'))
							{
								if((s[i] != ',')&&(s[i] != ' ')&&(s[i] != '('))
								{
									tmp1[0][imult2]=s[i];
									imult2++;
								}
								i++;
							}
							tmp1[0][imult2]='\0';
							
							printf("Matrice %s chargé",tmp1[0]);
							
							while(i<iMat)
							{
								if(strcmp(TabMat[i]->nom,tmp1[0])==0)
								{
									printf("\n Matrice : %s chargée \n",tmp1[0]);
									m1=TabMat[i]->matrice;
								}
							}
							//~ ftmp= determinant_opt(m1);
							//~ printf(" %s = %f \n",s1,ftmp);
							//~ TabNombre[iVar]=NewNombre(s1,ftmp);
							//~ iVar++;
							
							
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
									if(strncmp(s2,"speedtest ",9)==0)
									{
										printf("s2: %s\n",s2);
										printf(" SP \n");
										//speedTest
										a=chargeArguments(s2);
										for(i=0;i<a->nbArg;i++)
										{
											printf("%s \n",a->tab[i]);
										}
										//~ speedTest("add", 5, 50, 5,3);
									}
									else
										if(strcmp(s2,"add")==0)
										{
											i=0;
											imult=0;
											imult2=0;
											
											while((i<N)&&(s[i] != '('))
											{
												i++;
											}
												
											while((i<N)&&(s[i] != ','))
											{
												if((s[i] != ',')&&(s[i] != ' ')&&(s[i] != '('))
												{
													tmp1[0][imult2]=s[i];
													imult2++;
												}
												i++;
											}
											tmp1[0][imult2]='\0';
											imult2=0;
											while((i<N)&&(s[i] != ')'))
											{
												if((s[i] != ',')&&(s[i] != ' ')&&(s[i] != '('))
												{
													tmp1[1][imult2]=s[i];
													imult2++;
												}
												i++;
											}
											tmp1[1][imult2]='\0';
											
											printf("%s + %s \n",tmp1[0],tmp1[1] );
											i=0;
					
											while(i<iMat)
											{
												if(strcmp(TabMat[i]->nom,tmp1[0])==0)
												{
													printf("\n Matrice : %s chargée \n",tmp1[0]);
													m1=TabMat[i]->matrice;
												}
												
												if(strcmp(TabMat[i]->nom,tmp1[1])==0)
												{
													printf("Matrice : %s chargée \n",tmp1[1]);
													m2=TabMat[i]->matrice;
												}
												i++;
											}
											if((m1->nrows == m2->nrows)&&(m1->ncols == m2->ncols))
											{
												TabMat[iMat]=NewMatrice(s1,m1->nrows,m2->ncols);
												m3=addition(m1,m2);
												
												for(iCptL=1;iCptL<= m3->nrows; iCptL++)
												{
													for(iCptC=1; iCptC <= m3->ncols; iCptC++)
													{
														printf("%f ",getElt(m3,iCptL,iCptC));
													}
													printf("\n");
												}
												TabMat[iMat]->matrice=m3;
												iMat++;
											}
											else
											{
												printf(" Addition: Matrice pas de meme type \n\n");
											}
										}
										else
											if(strcmp(s2,"sub")==0)
											{
												i=0;
												imult=0;
												imult2=0;
												
												while((i<N)&&(s[i] != '('))
												{
													i++;
												}
													
												while((i<N)&&(s[i] != ','))
												{
													if((s[i] != ',')&&(s[i] != ' ')&&(s[i] != '('))
													{
														tmp1[0][imult2]=s[i];
														imult2++;
													}
													i++;
												}
												tmp1[0][imult2]='\0';
												imult2=0;
												while((i<N)&&(s[i] != ')'))
												{
													if((s[i] != ',')&&(s[i] != ' ')&&(s[i] != '('))
													{
														tmp1[1][imult2]=s[i];
														imult2++;
													}
													i++;
												}
												tmp1[1][imult2]='\0';
												
												printf("%s + %s \n",tmp1[0],tmp1[1] );
												i=0;
						
												while(i<iMat)
												{
													if(strcmp(TabMat[i]->nom,tmp1[0])==0)
													{
														printf("\n Matrice : %s chargée \n",tmp1[0]);
														m1=TabMat[i]->matrice;
													}
													
													if(strcmp(TabMat[i]->nom,tmp1[1])==0)
													{
														printf("Matrice : %s chargée \n",tmp1[1]);
														m2=TabMat[i]->matrice;
													}
													i++;
												}
												if((m1->nrows == m2->nrows)&&(m1->ncols == m2->ncols))
												{
													TabMat[iMat]=NewMatrice(s1,m1->nrows,m2->ncols);
													m3=soustraction(m1,m2);
													
													for(iCptL=1;iCptL<= m3->nrows; iCptL++)
													{
														for(iCptC=1; iCptC <= m3->ncols; iCptC++)
														{
															printf("%f ",getElt(m3,iCptL,iCptC));
														}
														printf("\n");
													}
													TabMat[iMat]->matrice=m3;
													iMat++;
												}
												else
												{
													printf(" Soustraction: Matrice pas de meme type \n\n");
												}
											}
											else
												if(strcmp(s2,"trans")==0)
												{
													i=0;
													imult=0;
													imult2=0;
											
													while((i<N)&&(s[i] != '('))
													{
														i++;
													}
														
													while((i<N)&&(s[i] != ')'))
													{
														if((s[i] != ',')&&(s[i] != ' ')&&(s[i] != '('))
														{
															tmp1[0][imult2]=s[i];
															imult2++;
														}
														i++;
													}
													tmp1[0][imult2]='\0';
													
													printf("Matrice |%s| chargé \n",tmp1[0]);
													
													while(i<iMat)
													{
														if(strcmp(TabMat[i]->nom,tmp1[0])==0)
														{
															printf("\n Matrice : |%s| chargée \n",TabMat[i]->nom);
															m1=TabMat[i]->matrice;
														}
													}
													
													
													TabMat[iMat]=NewMatrice(s1,0,0);
													TabMat[iMat]->matrice=transpose(m1);
													iMat++;
												}
												else
													if(((s2[0] >= '0')&&(s2[0] <= '9'))||(s[i] == '-'))
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
