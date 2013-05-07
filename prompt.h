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
#include <string.h>
#include <ctype.h>
#include <assert.h>
//-----------------------------Structure--------------------------------
typedef struct {char *variable; float valeur; } StrNombre, *Nombre;
typedef struct {char *nom; Matrix matrice;} StrMatrice, *Matrice;
typedef struct { char** tab; int nbArg; int taille;} StrArguments,*arguments;

//-----------------------------Prototype--------------------------------
void LireChaine(char chaine[]);
void Argument(char chaine1[], char chaine2[],int choix);
Nombre NewNombre(char* nom, float a);
float getValNombre(Nombre x);
Matrice NewMatrice(char* nom, int L, int C);
Matrix getMatrice(Matrice m);
int NbLigne(char chaine[]);
int NbColonne(char chaine[]);
arguments chargeArguments(char* arg);
int compterLigne(char*name);
#endif
