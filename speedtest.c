#include <math.h>
#include <sys/time.h>
#include "resol.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "matrix.h"
#include "operations.h"
#include <string.h>
#include <ctype.h>
#include "prompt.h"
#define MIN 0
#define MAX 50
/**
 * \fn void ecritureFichier(int n, double t, char *foutput)
 * \brief écrit dans le fichier foutput les lignes "n t"
 * \param n taille du couple de matrice
 * \param t temps de calcul de la multiplication des matrices
 * \return void
 */
void ecritureFichier(int n, int t, char *foutput) { 
	FILE* fichier = NULL;
	fichier = fopen(foutput, "a");
	
	//vérification de l'ouverture du fichier
	if(fichier != NULL)
	{
		//écriture dans le fichier
		fprintf(fichier, "%d %d\n", n, t);
		fclose(fichier);
	}
}

//---------------------------------------------------------------------------------------------------------

/**
 * \fn void fichierCmde(char* foutput) 
 * \brief écriture dans un fichier des commandes nécéssaires pour afficher le graphe
 * \param foutput le fichier de données
 * \return void
 */
void fichierCmde(char* foutput)
{ 
	FILE* fichier = NULL;
	fichier = fopen("speedTest.gp", "w+");
	if(fichier != NULL) {
		fprintf(fichier, "set terminal png size 600, 400\n");
		fprintf(fichier, "set xlabel \"Taille des matrices\"\n");
		fprintf(fichier, "set ylabel \"Temps de calcul (en µs) \"\n");
		fprintf(fichier, "set grid \n");
		fprintf(fichier, "set zeroaxis \n");
		fprintf(fichier, "set title \"Temps de calcul en fonction de la taille des matrices\"\n");
		fprintf(fichier,"set output \"speedTest.png\"\nplot \"%s\"\n",  foutput);
		fclose(fichier);
	}
	
	system("gnuplot < speedTest.gp");
}

//---------------------------------------------------------------------------------------------------------

int commande(char* cmd,Matrix a, Matrix b)
{
	struct timeval start, end;
	int temps=0;
	Matrix m;
	printf("%c\n",cmd[0]);
	switch(cmd[0])
	{
		
		case 'a':
						gettimeofday(&start, NULL);
						m=addition(a,b);
						gettimeofday(&end, NULL);
						temps =fabs(end.tv_usec - start.tv_usec); // temps (µs)
						printf("temps : %d\n",temps);
						break;
						
		case 'm':
						gettimeofday(&start, NULL);
						m=multiplication(a,b);
						gettimeofday(&end, NULL);
						temps =fabs(end.tv_usec - start.tv_usec); // temps (µs)
						break;
						
		case 's':
						gettimeofday(&start, NULL);
						m=soustraction(a,b);
						gettimeofday(&end, NULL);
						temps =fabs(end.tv_usec - start.tv_usec); // temps (µs)
						break;
		
		default: 
					break;
	}
	
	return temps;
}

//---------------------------------------------------------------------------------------------------------


void speedTest(char* cmd,int tailleMin,int tailleMax,int pas, int nbSec) {
	int i;
	int temps=0;
	Matrix a=NULL,b=NULL;
	for(i=tailleMin;i<=tailleMax;i+=pas)
	{
		//génère un couple de matrice de taille i*i
		a=aleatoire(a,i,i,MIN,MAX);
		b=aleatoire(b,i,i,MIN,MAX);
		temps=commande(cmd,a,b);
		if(temps/1000>nbSec)
		{
			printf("le temps de calcul est supérieur à %ds\n",nbSec);
			exit(0);
		}
		else
		{
			ecritureFichier(i,temps,"speedTest.data");
		}
	}
	
	deleteMatrix(a);
	deleteMatrix(b);
	
	fichierCmde("speedTest.data");
}

//---------------------------------------------------------------------------------------------------------

void mainSpeedtest(char* s)
{
	arguments a;
	int i;
	a=chargeArguments(s);
	//~ for(i=0;i<a->nbArg;i++)
	//~ {
		//~ printf("%s \n",a->tab[i]);
	//~ }
	i=0;
	while(strcmp("speedtest",a->tab[i])!=0)
	{
		i++;
		printf("%d\n",i);
	}
	if(a->nbArg-i<5 && a->nbArg-i>6)
	{
			printf("usage : speedtest commande taille_min taille_max pas [nb_sec]\n");
			exit(0);
	}
	else
	{
	
		if(a->nbArg-i==5)
		{
				speedTest(a->tab[i+1], atoi(a->tab[i+2]), atoi(a->tab[i+3]), atoi(a->tab[i+4]),1);
		}
		else
		{
				speedTest(a->tab[i+1], atoi(a->tab[i+2]), atoi(a->tab[i+3]), atoi(a->tab[i+4]),atoi(a->tab[i+5]));
		}
	}
}
