#include "resol.h"
#include <math.h>

Matrix extraction(Matrix A, int n, int i, int j) {
	Matrix B = newMatrix(n-1, n-1);
	int k, l;
	for(k = 1; k <= i-1; k++) {
		for(l = 1; l <= j-1; l++) {
			setElt(B, k, l, getElt(A, k, l));
		}
	}
	
	for(k = 1; k <= i-1; k++) {
		for(l = j+1; l <= n; l++) {
			setElt(B, k, l-1, getElt(A, k, l));
		}
	}
	
	for(k = i+1; k <= n; k++) {
		for(l = 1; l <= j-1; l++) {
			setElt(B, k-1, l, getElt(A, k, l));
		}
	}
	
	for(k = i+1; k <= n; k++) {
		for(l = j+1; l <= n; l++) {
			setElt(B, k-1, l-1, getElt(A, k, l));
		}
	}
	
	return B;
}

int determinant_naif(Matrix A, int n) {
	Matrix B;
	int i;
	int c;
	float d;
	if(n == 1) {
		return getElt(A, 1, 1);
	}
	else {
		d = 0;
		c = 1;
	
		for(i = 1; i <= n; i++) {
			B = extraction(A, n, i, 1);
			d += getElt(A, i, 1)*c*determinant_naif(B, n-1);
			c = -c;
		}
	return d;
	}
}

Matrix addmultipleDet(Matrix A, int i, int j, float c) {
	int k;
	for(k = 1; k <= A->nrows; k++) {
		setElt(A, i, k, getElt(A, i, k)+c*getElt(A, j, k));
	}
	
	return A;
}


Matrix addmultiple(Matrix A, float *B, int i, int j, float c) {
	int k;
	for(k = 1; k <= A->nrows; k++) {
		setElt(A, i, k, getElt(A, i, k)+c*getElt(A, j, k));
	}
	B[i-1] += c*B[j-1];
	
	return A;
}

int choixPivot(Matrix A, int i) {
	int j;
	for(j = i; j <= A->nrows; j++) { 
		if(getElt(A, j, i) != 0) {
			return j;
		}
	}
	return -1;
}

Matrix echangeLigneDet(Matrix A, int i, int j) {
	int k;
	float temp;
	for(k = 1; k <= A->nrows; k++) {
		temp = getElt(A, i, k);
		setElt(A, i, k, getElt(A, j, k));
		setElt(A, j, k, temp);
	}

	return A;
}

Matrix echangeLigne(Matrix A, float *B, int i, int j) {
	int k;
	float temp;
	for(k = 1; k <= A->nrows; k++) {
		temp = getElt(A, i, k);
		setElt(A, i, k, getElt(A, j, k));
		setElt(A, j, k, temp);
	}
	temp = B[i-1];
	B[i-1] = B[j-1];
	B[j-1] = temp;
	
	return A;
}

Matrix triangulaire(Matrix A, float *B) {
	int i, j;
	for(i = 1; i <= A->nrows-1; i++) {
		j = choixPivotPartiel(A, i);
		A = echangeLigne(A, B, i, j);
		for(j = i+1; j <= A->nrows; j++) {
			A = addmultiple(A, B, j, i, -getElt(A, j, i)/getElt(A, i, i));
		}
	}
	
	return A;
}

int choixPivotPartiel(Matrix A, int i) {
	int p, j;
	p = i;
	float v = fabs(getElt(A, i, i));
	
	for(j = i+1; j <= A->nrows; j++) {
		if(fabs(getElt(A, j, i)) > v) {
			p = j;
			v = fabs(getElt(A, j, i));
		}
	}
	return p;
}

int triangulaire_Det(Matrix A) {
	int c = 1, i, j;
	for(i = 1; i <= A->nrows; i++) {
		j = choixPivotPartiel(A, i);
		if(j != i) {
			echangeLigneDet(A, i, j);
			c = -c;
		}
		for(j = i+1; j <= A->nrows; j++) {
			addmultipleDet(A, j, i, -getElt(A, j, i)/getElt(A, i, i));
		}
	}
	
	return c;
}

int determinant_opt(Matrix A) {
	int i;
	float c = triangulaire_Det(A);
	for(i = 1; i <= A->nrows; i++) {
		c = c*getElt(A, i, i);
	}

	return (int)((c > 0.0) ? floor(c + 0.5) : ceil(c - 0.5)); // arrondi
}

void remontee(Matrix A, float *B, float *X) {
	int i, j;
	for(i = A->nrows; i >= 1; i--) {
		X[i-1] = B[i-1];
		for(j = i+1; j <= A->nrows; j++) {
			X[i-1] -= getElt(A, i, j)*X[j-1];
		}
		X[i-1] /= getElt(A, i, i);
	}
}

void gauss(Matrix A, float *B, float *X) {
	triangulaire(A, B);
	remontee(A, B, X);
}

//-------------------- Pour inversion-------------------------------


Matrix permut(Matrix A,int i, int j){
	int k;
	float tmp;
	for(k=0;k<A->nrows;k++)
	{
		tmp=getElt(A,i,k);
		setElt(A,getElt(A,j,k),i,k);
		setElt(A, tmp,j,k);
	}
	return A;
}

//---------------------------------------------------------------------

//----------------------------------------------------------------------

//additionne à la ligne i le résultat de la multiplication de le ligne j par un facteur k
Matrix addEtmultipleK(Matrix a,int i,int j,float k){
	int x;
	float y;
	for(x=0;x<a->nrows;x++)//pour chaque élément a->m[i][x] de la ligne i
	{
		y=getElt(a,i,x)+k*getElt(a,j,x);//on l'aditionne par k*l'élement a->m[j][x]
		setElt(a,y,i,x);
	}
	return a;
}
//---------------------------------------------------------------------

Matrix inversion(Matrix a)
{
	Matrix b=newMatrix(a->nrows,a->ncols);
	b=identite(b,a->nrows,a->ncols);
	int i,j;
	float x;
	
	//triangulaire pour a ET b
	for(i=1;i<a->nrows;i++)
	{
		j=choixPivot(a,i);
		permut(a,i,j);
		printf("permutation a ok\n");
		permut(b,i,j);
		printf("permutation b ok\n");
		
		for(j=i+1;j<a->nrows;j++)
		{
			x=-(getElt(a,j,i))/getElt(a,i,i);
			addEtmultipleK(a,j,i,x);
			addEtmultipleK(b,j,i,x);
		}
	}
	return b;
}

void displaymatrix(Matrix m){
	int i,j;
	
	for(i=0;i<m->nrows;i++)
	{
		for(j=0;j<m->ncols;j++)
		{
			printf("%f ",getElt(m,i,j));
		}
		printf("\n");
	}
}

void mainInverstion(char* s)
{
	printf("Matrice a:\n");
	Matrix a=aleatoire(a,3,3,1,10);
	displaymatrix(a);
	printf("Matrice b:\n");
	Matrix b=aleatoire(b,3,3,1,10);
	displaymatrix(b);
	printf("Inversion:\n");
	b=inversion(a);
	printf("COuouc\n");
	displaymatrix(b);
	
}
