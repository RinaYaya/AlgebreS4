#include "operations.h"
#include <stdlib.h>

Matrix addition(Matrix m1, Matrix m2)
{
	Matrix m = newMatrix(m1->nrows, m1->ncols);
	int i, l = (m->nrows)*(m->ncols);
	
	for(i = 0; i < l; i++)
	{
		m->mat[i] = m1->mat[i] + m2->mat[i];
	}
	
	return m;
}

Matrix soustraction(Matrix m1,Matrix m2)
{
	Matrix m = newMatrix(m1->nrows, m1->ncols);
	int i, l = (m->nrows)*(m->ncols);
	
	for(i = 0; i < l; i++)
	{
		m->mat[i] = m1->mat[i] - m2->mat[i];
	}
	
	return m;
}

// precondition : m1->cols = m2->rows
Matrix multiplication(Matrix m1, Matrix m2)
{
	Matrix m = newMatrix(m1->nrows, m2->ncols);
	int i, j, k;
	float s = 0;
	
	for(k = 0; k < m2->ncols; k++)
	{
		for(j = 0; j < m1->nrows; j++)
		{
			for(i = 0; i < m1->ncols; i++)
			{
				s += getElt(m1, j+1, i+1)*getElt(m2, i+1, k+1);
			}
			
			setElt(m, j+1, k+1, s);
			s = 0;
		}
	}
	
	return m;
}

Matrix transpose(Matrix m)
{
    Matrix mt = newMatrix(m->ncols, m->nrows);

    int i, j;

    for(j = 0 ; j < mt->nrows ; j++)
    {
        for(i = 0 ; i < mt->ncols ; i++)
        {
            setElt(mt, j+1, i+1, getElt(m, i+1, j+1));
        }
    }

    return mt;
}
