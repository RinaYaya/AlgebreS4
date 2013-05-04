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
    fgets(chaine, size, stdin);  
    chaine[strlen(chaine) - 1] = '\0';  
} 
//----------------------------------------------------------------------
void Argument1(char chaine1[],char chaine2[])
{
	int i=0;
	
	while((i<4)&&(chaine[i] != ':')
	{
		if(chaine1[i] != ' ')
		{
			chaine2[i]=chaine1[i];
		}
		i++;
	}
	
	chaine2[i]='\0';
}
//----------------------------------------------------------------------
