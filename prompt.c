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
	int i=0, i2=0;
	char chainetmp[N];
	

	if(choix == 1)
	{
		while((i<N)&&(chaine1[i] != ':'))
		{
			if(chaine1[i] != ' ')
			{
				chainetmp[i]=chaine1[i];
			}
			i++;
		}
		chainetmp[i-1]='\0';
	}
					
	if(choix == 0)
	{
		while((i<N)&&(chaine1[i] != ':'))
		{
			i++;
		}
		
		i+=2;
		
		while((i<N)&&(chaine1[i] != '('))
		{
			if(chaine1[i] != ' ')
			{
				chainetmp[i2]=chaine1[i];		
			}
			i++;
			i2++;
		}
		chainetmp[i-1]='\0';
	}
	
	strcpy(chaine2,chainetmp);
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
Matrice NewMatrice(char* nom, int L, int C)
{
	Matrice a = malloc(sizeof(StrMatrice));
	int rows=L, col=C;
	
	if(a == NULL)
	{
		printf("Probleme MALLOC: NewNombre");
	}
	
	a->nom=malloc(20*sizeof(char));
	strcpy(a->nom,nom);
	a->matrice=newMatrix(rows,col);
	return a;
	
}
//----------------------------------------------------------------------
/**
 * \fn int NbLigne(char chaine[])
 * \brief compte les lignes d'une matrice
 * \param Chaine contenant les infos de la matrice
 * \return nombre de lignes
 *  \pre 
 */
int NbLigne(char chaine[])
{
	int i=0, rows=0;
	
	while(chaine[i] != '\0')
	{
		if(chaine[i] == '[')
		{
			rows++;
		}
		i++;
	}
	 return rows;
}
//----------------------------------------------------------------------
/**
 * \fn int iNbColonne(char chaine[])
 * \brief compte les colonnes d'une matrice
 * \param Chaine contenant les infos de la matrice
 * \return nombre de colonnes
 *  \pre 
 */
int NbColonne(char chaine[])
{
	int i=0, col=0;
	
	while((chaine[i] != '\0')&&(chaine[i] != ']'))
	{
		if(chaine[i] == ',')
		{
			col++;
		}
		i++;
	}
	return col;
}
//----------------------------------------------------------------------

arguments chargeArguments(char* arg)
{
	int j=0,i=0;
	arguments a=malloc(sizeof(StrArguments));
	a->taille=6;
	a->nbArg=0;
	
	//initialisation tableau
	a->tab=malloc(a->taille*sizeof(char*));
	for(i=0;i<a->taille;i++)
	{
		a->tab[i]=malloc(1024*sizeof(char));
	}

	i=0;
	while(arg[i]!='\0')
	{
		j=0;
		while(isspace(arg[i])==0 && arg[i]!='\0')
		{
			a->tab[a->nbArg][j]=arg[i];
			i++;
			j++;
			
		}
		
		if((a->nbArg)+1>a->taille)
		{
			a->taille=a->taille*2;
			a->tab=realloc(a->tab,a->taille*sizeof(char*));
		}

		a->nbArg++;
		
		while(isspace(arg[i])!=0)
		{
			 i++;
		}
	}
	return a;
}
