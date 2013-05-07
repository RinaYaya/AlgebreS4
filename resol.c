#include "resol.h"
#include <math.h>

Matrix extraction(Matrix A, int n, int i, int j) 
{
	Matrix B = newMatrix(n-1, n-1);
	int k, l;
	for(k = 1; k <= i-1; k++) 
	{
		for(l = 1; l <= j-1; l++) 
		{
			setElt(B, k, l, getElt(A, k, l));
		}
	}
	
	for(k = 1; k <= i-1; k++) 
	{
		for(l = j+1; l <= n; l++) 
		{
			setElt(B, k, l-1, getElt(A, k, l));
		}
	}
	
	for(k = i+1; k <= n; k++) 
	{
		for(l = 1; l <= j-1; l++) 
		{
			setElt(B, k-1, l, getElt(A, k, l));
		}
	}
	
	for(k = i+1; k <= n; k++) 
	{
		for(l = j+1; l <= n; l++) 
		{
			setElt(B, k-1, l-1, getElt(A, k, l));
		}
	}
	
	return B;
}

int determinant_naif(Matrix A, int n) 
{
	Matrix B;
	int i;
	int c;
	float d;
	if(n == 1) 
	{
		return getElt(A, 1, 1);
	}
	else 
	{
		d = 0;
		c = 1;
	
		for(i = 1; i <= n; i++) 
		{
			B = extraction(A, n, i, 1);
			d += getElt(A, i, 1)*c*determinant_naif(B, n-1);
			c = -c;
		}
	return d;
	}
}

Matrix addmultipleDet(Matrix A, int i, int j, float c) 
{
	int k;
	for(k = 1; k <= A->nrows; k++) 
	{
		setElt(A, i, k, getElt(A, i, k)+c*getElt(A, j, k));
	}
	
	return A;
}


Matrix addmultiple(Matrix A, float *B, int i, int j, float c) {
	int k;
	for(k = 1; k <= A->nrows; k++) 
	{
		setElt(A, i, k, getElt(A, i, k)+c*getElt(A, j, k));
	}
	B[i-1] += c*B[j-1];
	
	return A;
}

int choixPivot(Matrix A, int i) {
	int j;
	for(j = i; j <= A->nrows; j++) 
	{ 
		if(getElt(A, j, i) != 0) 
		{
			return j;
		}
	}
	return -1;
}

Matrix echangeLigneDet(Matrix A, int i, int j) {
	int k;
	float temp;
	for(k = 1; k <= A->nrows; k++)
	 {
		temp = getElt(A, i, k);
		setElt(A, i, k, getElt(A, j, k));
		setElt(A, j, k, temp);
	}

	return A;
}

Matrix echangeLigne(Matrix A, float *B, int i, int j) {
	int k;
	float temp;
	for(k = 1; k <= A->nrows; k++) 
	{
		temp = getElt(A, i, k);
		setElt(A, i, k, getElt(A, j, k));
		setElt(A, j, k, temp);
	}
	temp = B[i-1];
	B[i-1] = B[j-1];
	B[j-1] = temp;
	
	return A;
}

Matrix triangulaire(Matrix A, float *B)
 {
	int i, j;
	for(i = 1; i <= A->nrows-1; i++) 
	{
		j = choixPivotPartiel(A, i);
		A = echangeLigne(A, B, i, j);
		for(j = i+1; j <= A->nrows; j++) 
		{
			A = addmultiple(A, B, j, i, -getElt(A, j, i)/getElt(A, i, i));
		}
	}
	
	return A;
}

int choixPivotPartiel(Matrix A, int i) 
{
	int p, j;
	p = i;
	float v = fabs(getElt(A, i, i));
	
	for(j = i+1; j <= A->nrows; j++) 
	{
		if(fabs(getElt(A, j, i)) > v) 
		{
			p = j;
			v = fabs(getElt(A, j, i));
		}
	}
	return p;
}

int triangulaire_Det(Matrix A)
 {
	int c = 1, i, j;
	for(i = 1; i <= A->nrows; i++)
	 {
		j = choixPivotPartiel(A, i);
		if(j != i)
		{
			echangeLigneDet(A, i, j);
			c = -c;
		}
		for(j = i+1; j <= A->nrows; j++) 
		{
			addmultipleDet(A, j, i, -getElt(A, j, i)/getElt(A, i, i));
		}
	}
	
	return c;
}

int determinant_opt(Matrix A) 
{
	int i;
	float c = triangulaire_Det(A);
	for(i = 1; i <= A->nrows; i++) 
	{
		c = c*getElt(A, i, i);
	}

	return (int)((c > 0.0) ? floor(c + 0.5) : ceil(c - 0.5)); // arrondi
}

void remontee(Matrix A, float *B, float *X) 
{
	int i, j;
	for(i = A->nrows; i >= 1; i--) 
	{
		X[i-1] = B[i-1];
		for(j = i+1; j <= A->nrows; j++) 
		{
			X[i-1] -= getElt(A, i, j)*X[j-1];
		}
		X[i-1] /= getElt(A, i, i);
	}
}

void gauss(Matrix A, float *B, float *X) 
{
	triangulaire(A, B);
	remontee(A, B, X);
}
