#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix newMatrix(int nb_rows, int nb_columns)
{
	Matrix m;
	int i=0, j=0;
	m = (Matrix) malloc(sizeof(struct matrix));
	m->mat = (float*) malloc(nb_rows*nb_columns*sizeof(float));
	m->nrows = nb_rows;
	m->ncols = nb_columns;
	
	for(
	
	return m;
}

// precondition : row < nrows, column < ncols
float getElt(Matrix m, int row, int column)
{
	return m->mat[(row-1)*m->ncols + (column-1)];
}

void setElt(Matrix m, int row, int column, float val)
{
	m->mat[(row-1)*m->ncols + (column-1)] = val;
}

void deleteMatrix(Matrix m)
{
	free(m->mat);
	free(m);
}

void displayMatrix(Matrix m, float *B)
{
	int i, l = (m->nrows)*(m->ncols), j = 0;
	int displaym, displayB;
	
	for(i = 0; i < l; i++)
	{
		displaym = (int)m->mat[i];
		printf("%d ", displaym);
		
		if((i+1)%(m->ncols) == 0) {
			displayB = (int)B[j];
			printf("| %d\n", displayB);
			j++;
		}
	}
	
	printf("\n");
}

Matrix identite(Matrix m, int r, int c)
{
	m = newMatrix(r, c);
	int i, j;
	
	for(j = 0; j < m->nrows; j++)
	{
		for(i = 0; i < m->ncols; i++)
		{
			if(i == j)
				setElt(m, j+1, i+1, 1);
			else
				setElt(m, j+1, i+1, 0);
		}
	}
	
	return m;
}

Matrix aleatoire(Matrix m, int r, int c, int min, int max)
{
	m = newMatrix(r, c);
	int i, l = (m->nrows)*(m->ncols);
	
	for(i = 0; i < l; i++)
	{
		m->mat[i] = (rand() % (max - min + 1)) + min;
	}
	
	return m;
}

Matrix copie(Matrix m, Matrix m2) {
	m2 = newMatrix(m->nrows, m->ncols);
	int i;
	for(i = 0; i < m->nrows*m->ncols; i++) {
		m2->mat[i] = m->mat[i];
	}
	
	return m2;
}
