#include "prompt.h"

//----------------------------------------------------------------------
/**
 * \fn void LireChaine(char chaine[], int size) 
 * \brief Lit une chaine et la met dans chaine []
 * \param size taille de chaine[]
 * \param chaine[] chaine de caractere
 * \return void
 *  \pre 
 */
void LireChaine(char chaine[], int size) 
{  
    fgets(chaine, size, stdin);  
    chaine[strlen(chaine) - 1] = '\0';  
} 
//----------------------------------------------------------------------
