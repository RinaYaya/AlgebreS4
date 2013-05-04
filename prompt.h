/**
* \file prompt.h
* \brief  Fonction qui gere le prompt
*/

#ifndef _SOMMET_H__
#define _SOMMET_H__
//-----------------------------Include----------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "matrix.h"
#include "operations.h"
#include "resol.h"
#include "matrix.h"
#include <string.h>
//-----------------------------Structure--------------------------------
typedef struct {char *variable; float valeur; } StrNombre, *Nombre;
typedef struct {char *nom; matrix matrice;} StrMatrice, *Matrice;

//-----------------------------Prototype--------------------------------
void LireChaine(char chaine[]);
void Argument1(char chaine1[], char chaine2[],int choix);
Nombre NewNombre(char* nom, float a);
float getValNombre(Nombre x);
Matrice NewMatrice(char* nom, char chaine[]);
Matrix getMatrice(Matrice m);

#endif
