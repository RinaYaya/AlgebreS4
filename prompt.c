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
void Argument(char chaine1[],char chaine2[],int choix)
{
	int i=0;
	
	switch (choix)
	{
		case '1':	while((i<N)&&(chaine1[i] != ':'))
					{
						if(chaine1[i] != ' ')
						{
							chaine2[i]=chaine1[i];
						}
						i++;
					}
					chaine2[i]='\0';
					break;
					
		case '2':	while((i<N)&&(chaine1[i] != ':'))
					{
						i++;
					}
					
					while((i<N)&&(chaine1[i] != '('))
					{
						if(chaine1[i] != ' ')
						{
							chaine2[i]=chaine1[i];
						}
						i++;
					}
					chaine2[i]='\0';
					break;
					

	}
}
//----------------------------------------------------------------------
