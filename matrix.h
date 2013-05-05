#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <stdio.h>
#include <stdlib.h>
#define MIN 0
#define MAX 20
typedef struct matrix {
	float *mat;
	int nrows, ncols;
} *Matrix;

Matrix newMatrix(int nb_rows, int nb_columns);
float getElt(Matrix m, int row, int column);
void setElt(Matrix m, int row, int column, float val);
void deleteMatrix(Matrix m);
void displayMatrix(Matrix m, float *B);
Matrix identite(Matrix m, int r, int c);
Matrix aleatoire(Matrix m, int r, int c, int min, int max);
Matrix copie(Matrix m, Matrix m2);

#endif
