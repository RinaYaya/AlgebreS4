#ifndef __RESOL_H__
#define __RESOL_H__

#include "operations.h"

Matrix extraction(Matrix A, int n, int i, int j);
int determinant_naif(Matrix A, int n);
Matrix addmultiple(Matrix A, float *B, int i, int j, float c);
Matrix addmultipleDet(Matrix A, int i, int j, float c); // pour determinant
int choixPivot(Matrix A, int i);
Matrix echangeLigne(Matrix A, float *B, int i, int j);
Matrix echangeLigneDet(Matrix A, int i, int j); // pour determinant
Matrix triangulaire(Matrix A, float *B);
int choixPivotPartiel(Matrix A, int i);
int triangulaire_Det(Matrix A);
int determinant_opt(Matrix A);
void remontee(Matrix A, float *B, float *X);
void gauss(Matrix A, float *B, float *X);

#endif
