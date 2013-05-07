#include "prompt.h"
#include "operations.h"
#include "matrix.h"
#include "resol.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#define N 50
//----------------------------------------------------------------------
int main(int argc, char* argv[])
{
	//declaration et Init
	srand(time(NULL));
	FILE* fa=NULL;
	int iQuit =0;
	char s[400];
	char s2[50];
	char s1[50];

	arguments a=NULL;

	char Temp[50], tmp1[1][50], tmc[400],r='a';
	Matrice	TabMat[10];
	Nombre TabNombre[10];
	Matrix m1, m2,m3;
	int iVar=0, iMat=0, Ligne=0, n,Col=0, iCptL=0, iCptC=0, iT=0,i=0,ouvert=0, imult=0, imult2=0, itmp=0, ifichier=0, charger =0,ic=0;
	float ftmp;


	// je verifie si j'ai un fichier en argument si oui je l'ouvre
		
	if(argc!=2)
	{
		printf("\n");
	}
	else
	{
		ifichier=compterLigne(argv[1]);
		fa=fopen(argv[1],"r");
		assert(fa!=NULL);
	}
	
	//boucle geante qui gere le Prompt :P
	while(iQuit == 0)
	{	
	
	
		printf("> ");
		
		//si charger et à 0 on lit au clavier, sinon on lit dans le fichier
		if(charger == 0)
		{
			LireChaine(s);
		}
		else
		{
			//si r = EOF on met charger à 0 pour lire au clavier, sinon on lit une ligne du fichier
			if(r == EOF)
			{
				charger =0;
			}
			else
			{
				ic=0;
				r='a';
				//lecture d'une ligne d'un fichier
				while((r !='\n')&&(r!=EOF))
				{
					r=fgetc(fa);
					s[ic]=r;
					ic++;
				}
				s[ic]='\0';
				printf(" Execution de : \n %s \n", s);
			}
		}
		//separation du mot avant le ':' et apres
		Argument(s,s2,0);
		Argument(s,s1,1);
		
		
		//le switch à l'ancienne :P permet de gere les options
		if(strcmp(s1,"charger")==0)
		{
			//met a 1, pour charger 
			printf("chargement du fichier \n");
			charger = 1;
		}
		else
		if(strcmp(s1,"quit") ==0)
		{
			iQuit=1;
		}
		else
			if(strcmp(s2,"matrix")==0)
			{
				//remise à zero des parametre
				i=0;
				iT=0;
				iCptC=0;
				iCptL=0;
				Ligne=NbLigne(s);
				Col=NbColonne(s);
				Col++;
				
				//on ajoute une entré dans le tableau de matrice
				TabMat[iMat]=NewMatrice(s1,Ligne, Col);
				
					//on avance jusque ':' dans la chaine
					while( (i<N)&&(s[i] != ':'))
					{
						i++;
					}
					//on saute l'espace et le :
					i=i+2;
					
				//on parcours le reste jusqu'a la fin	
				while((i<N)&&(s[i] != '\0'))
				{
					//si c'est un chiffre ou un -on ajoute
					if(((s[i]>='0')&&(s[i]<='9'))||(s[i] == '-'))
					{
						Temp[iT]=s[i];
						iT++;
					}
					//si c'est une , ou ] on ajoute le '\0' pour dire que c'est la fin de la chaine et on l'insere dans la matrice
					if((s[i] == ',')||(s[i] == ']'))
					{
					
						Temp[iT]='\0';
						setElt(TabMat[iMat]->matrice, iCptL+1,iCptC+1, atof(Temp));
						iCptC++;
						iT=0;
						
					}
					
					
					//on fini une ligne de la matrice
					if(s[i]== ']')
					{
						i++;
						ouvert =0;
						iCptC=0;
						iCptL++;
					}
					i++;
				}
				
				//boucle pour afficher la matrice, c'etait un pur reflexe les boucles imbriqué je me rend compte que vu que la matrice et
				//continu on aurait pu lire d'un coup avec une boucle :p
				
				for(iCptL=1; iCptL <Ligne+1; iCptL++)
				{
					for(iCptC=1; iCptC<Col+1; iCptC++)
					{
						printf("[ %d ][ %d ] = %f",iCptL,iCptC,getElt(TabMat[iMat]->matrice, iCptL, iCptC));
					}
					
					printf("\n");
				}
				iMat++;

			}
			else
				if(strcmp(s2,"mult")==0)
				{
					//mise a zero des param
					i=0;
					imult=0;
					imult2=0;
					
					//on avance jusqu'a (
						while((i<N)&&(s[i] != '('))
						{
							i++;
						}
						
					// on lit jusque ,	
					while((i<N)&&(s[i] != ','))
					{
						//	si on tombe sur , ' ' ou ( on ajoute le caractere
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
							printf("Entre dans det \n");
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
							
							i=0;
							while(i<iMat)
							{
								if(strcmp(TabMat[i]->nom,tmp1[0])==0)
								{
									m1=TabMat[i]->matrice;
								}
								i++;
							}
							itmp=determinant_opt(m1);
							
							printf(" determinant = %d ",itmp);
							
							ftmp= itmp;
						
							TabNombre[iVar]=NewNombre(s1,ftmp);
							iVar++;
							
							
						}
						else
							if(strcmp(s2,"solve")==0)
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
										printf("\n Matrice : |%s| chargée \n",TabMat[i]->nom);
										m1=TabMat[i]->matrice;
									}
									
									if(strcmp(TabMat[i]->nom,tmp1[1])==0)
									{
										printf("Matrice : |%s| chargée \n",TabMat[i]->nom);
										m2=TabMat[i]->matrice;
									}
									i++;
								}
								
								n = m1->nrows;
								
								float *X = (float*) malloc(n*sizeof(float));
								
								gauss(m1, m2->mat, X);
	
								printf("\nSolutions :\n");
								for(i = 0; i < n; i++) 
								{
									printf("x%d = %f\n", i+1, X[i]);
								}
								
								TabMat[iMat]=NewMatrice(s1, n,1);
								TabMat[iMat]->matrice->mat=X;
								iMat++;
								
								free(X);
								
								
							}
							else
								if(strcmp(s2,"rank")==0)
								{
									printf(" rang \n");
								}
								else
									if(strncmp(s2,"speedtest ",9)==0)
									{
										//~ printf("s2: %s\n",s2);
										//~ printf(" SP \n");
										//speedTest
										//~ a=chargeArguments(s2);
										//~ for(i=0;i<a->nbArg;i++)
										//~ {
											//~ printf("%s \n",a->tab[i]);
										//~ }
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
													
													printf("Matrice |%s| chargé %d \n",tmp1[0],iMat);
													i=0;
													while(i<iMat)
													{
														printf(" i : %d \n",i);
														if(strcmp(TabMat[i]->nom,tmp1[0])==0)
														{
															printf("\n Matrice : |%s| chargée O \n",TabMat[i]->nom);
															m1=TabMat[i]->matrice;
														}
														i++;
													}
																				
													TabMat[iMat]=NewMatrice(s1,0,0);
													TabMat[iMat]->matrice=transpose(m1);
													iMat++;
													m3=transpose(m1);
													
													for(iCptL=1;iCptL<= m3->nrows; iCptL++)
													{
														for(iCptC=1; iCptC <= m3->ncols; iCptC++)
														{
															printf("%f ",getElt(m3,iCptL,iCptC));
														}
														printf("\n");
													}
												}
												else
													if(((s2[0] >= '0')&&(s2[0] <= '9'))||(s[i] == '-'))
													{
														TabNombre[iVar]=NewNombre(s1,atof(s2));
														printf(" %s = %f \n",TabNombre[iVar]->variable,TabNombre[iVar]->valeur);
														iVar++;
													}
													else
														if(strcmp(s2,"exp")==0)
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
																	i++;
																}
																
																imult=atoi(tmp1[1]);
																
																m2=copie(m1,m2);
																printf("ajout pk L %d C %d \n",m2->nrows,m2->ncols);
																printf("ajout pk L %d C %d \n",m1->nrows,m1->ncols);
																printf(" copie + atoi %d ok \n", imult );
																
																if(imult==1)
																{
																	TabMat[iMat]=NewMatrice(s1,m2->nrows, m2->ncols);
																	TabMat[iMat]->matrice=m2;
																	iMat++;
																}
																else
																{
																	if(imult==0)
																	{
																		
																		for(iCptL=1; iCptL<=m2->nrows; iCptL++)
																		{
																			for(iCptC=1; iCptC<=m2->ncols; iCptC++)
																			{
																				if(iCptC == iCptL)
																				{
																					setElt(m2,iCptL,iCptC,1);
																					printf("%f ",getElt(m2,iCptL,iCptC));
																				}
																				else
																				{
																					setElt(m2,iCptL,iCptC,0);
																					printf("%f ",getElt(m2,iCptL,iCptC));
																				}
																			}
																			printf("\n");
																		}
																		
																		
																		
																	}
																	else
																	{
																		for(i=0; i<imult; i++)
																		{
																			printf(" i = %d \n",i);
																			m2=multiplication(m1,m2);
																			
																		}
																		
																		printf("multi ok \n");
																		TabMat[iMat]=NewMatrice(s1,m2->nrows, m2->ncols);
																		TabMat[iMat]->matrice=m2;
																		
																		printf("ajout pk L %d C %d \n",m2->nrows,m2->ncols);
																
																	
																	}
																	
																for(iCptL=1; iCptL<=m2->nrows; iCptL++)
																{
																	for(iCptC=1; iCptC<=m2->ncols; iCptC++)
																	{
																			printf("%f ",getElt(m2,iCptL,iCptC));
																	}
																	printf("\n");
																}
																		
																iMat++; 
															}
														}
														else
															if(strcmp(s2,"scal")==0)
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
																
																ftmp=atof(tmp1[1]);
																
																
																i=0;
																while(i<iMat)
																{
																	if(strcmp(TabMat[i]->nom,tmp1[0])==0)
																	{
																		printf("\n Matrice : %s chargée \n",tmp1[0]);
																		m1=TabMat[i]->matrice;
																	}
																	i++;
																}
																
																TabMat[iMat]=NewMatrice(s1,m1->nrows,m1->ncols);
																
																m2=TabMat[iMat]->matrice;
																
																for(iCptL=1; iCptL<=m1->nrows; iCptL++)
																{
																	for(iCptC=1; iCptC<=m1->ncols; iCptC++)
																	{
																		setElt(m2,iCptL,iCptC, getElt(m1,iCptL,iCptC)*ftmp);
																		printf("%f ",getElt(m2,iCptL,iCptC));
																	}
																	printf("\n");
																}
																iMat++;
																
															}
															else
															{
																printf("%s : function not implemented \n",s2);
															}
														
	}
	
	fclose(fa);
  return 0;
}
//----------------------------------------------------------------------
