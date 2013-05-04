#include "prompt.h"
#define N 50
//----------------------------------------------------------------------
/**
 * \fn void LireChaine(char chaine[], int size) 
 * \brief Lit une chaine et la met dans chaine []
 * \param size taille de chaine[]
 * \param chaine[] chaine de caractere
 * \return void
 *  \pre 
 */
void LireChaine(char chaine[]) 
{  
    fgets(chaine, N, stdin);  
    chaine[strlen(chaine) - 1] = '\0';  
} 
//----------------------------------------------------------------------
/**
 * \fn void Argument(char chaine1[],char chaine2[],int choix)
 * \brief Split la chaine et recupere l'element a gauche ou a droite de ':'
 * \param chaine1[] chaine de caractere a splitter
 * \param chaine[] chaine de caractere pour stocker le resultat
 * \return void
 *  \pre 
 */
 void Argument(char chaine1[],char chaine2[],int choix)
{
	int i=0;
	char chainetmp[N];
	printf("Valeur %s \n",chaine1);
	switch (choix)
	{
		case '1':	printf("puueeee \n");
					while((i<N)&&(chaine1[i] != ':'))
					{
						if(chaine1[i] != ' ')
						{

							chainetmp[i]=chaine1[i];
							printf("TMP %c %c ",chaine1[i], chainetmp[i]);
						}
						printf("TMP %c %c ",chaine1[i], chainetmp[i]);
						i++;
					}
					chainetmp[i]='\0';
					printf("\n");
					break;
					
		case '2':	printf("puudzadazeee \n");
					while((i<N)&&(chaine1[i] != ':'))
					{
						i++;
					}
					
					while((i<N)&&(chaine1[i] != '('))
					{
						if(chaine1[i] != ' ')
						{
							chainetmp[i]=chaine1[i];
							
						}
						printf("TMP %c %c ",chaine1[i], chainetmp[i]);
						i++;
					}
					chainetmp[i]='\0';
					printf("\n");
					break;
	}
	
	strcpy(chaine2,chainetmp);
					printf("Valeur %s %s \n",chainetmp, chaine2);
}
//----------------------------------------------------------------------
/**
 * \fn Nombre NewNombre(char* nom, float a)
 * \brief Creer un nouveau nombre
 * \param nom nom de la variable
 * \param float valeur
 * \return Nombre
 *  \pre 
 */
Nombre NewNombre(char* nom, float a)
{
	Nombre an = malloc(sizeof(StrNombre));
	
	if(an == NULL)
	{
		printf("Probleme MALLOC: NewNombre");
	}
	
	an->variable=malloc(20*sizeof(char));
	
	if(an->variable == NULL)
	{
		printf("Probleme MALLOC: NewNombre");
	}
	
	strcpy(an->variable,nom);
	an->valeur=a;
	
	return an;
}
//----------------------------------------------------------------------
/**
 * \fn Matrice NewMatrice(char* nom, char chaine[])
 * \brief Creer une nouvelle Matrice
 * \param nom nom de la variable
 * \param Chaine contenant les infos de la matrice
 * \return Nombre
 *  \pre 
 */
Matrice NewMatrice(char* nom, char chaine[])
{
	Matrice a = malloc(sizeof(StrMatrice));
	int rows=0,i=0, col=0;
	
	while(chaine[i] != '\0')
	{
		if(chaine[i] == '[')
		{
			rows++;
		}
		i++;
	}
	
	i=0;
	while((chaine[i] != '\0')&&(chaine[i] != ']'))
	{
		if(chaine[i] == ',')
		{
			col++;
		}
		i++;
	}
	if(a == NULL)
	{
		printf("Probleme MALLOC: NewNombre");
	}
	
	a->nom=malloc(20*sizeof(char));
	a->matrice=newMatrix(rows,col);
	return a;
	
}
