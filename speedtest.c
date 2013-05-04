#include <math.h>
#include <sys/time.h>
#include "resol.h"

/**
 * \fn void ecritureFichier(int n, double t, char *foutput)
 * \brief écrit dans le fichier foutput les lignes "n t"
 * \param n taille du couple de matrice
 * \param t temps de calcul de la multiplication des matrices
 * \return void
 */
void ecritureFichier(int n, double t, char *foutput) { 
	FILE* fichier = NULL;
	fichier = fopen(foutput, "a");
	
	//vérification de l'ouverture du fichier
	if(fichier != NULL)
	{
		//écriture dans le fichier
		fprintf(fichier, "%d %f\n", n, t);
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
	gnu = fopen("speedTest.gp", "w+");
	if(gnu != NULL) {
		fprintf(gnu, "set terminal png size 600, 400\nset output 'speedTest.png'\nplot \"%s\" u 2 title 't' with lines, \\\n\"%s\" using 4 title 'n' with lines\n", foutput, foutput);
		fclose(gnu);
	}
	
	system("gnuplot < speedTest.gp");
}

//---------------------------------------------------------------------------------------------------------

int commande(char* cmd,matrix a, matrix b)
{
	struct timeval start, end;
	int temps=0;
	matrix m;
	switch(cmd)
	{
		
		case "addition":
						gettimeofday(&start, NULL);
						m=addition(a,b);
						gettimeofday(&end, NULL);
						temps =fabs(end.tv_usec - start.tv_usec); // temps (µs)
						break;
						
		case "mult":
						gettimeofday(&start, NULL);
						m=multiplication(a,b);
						gettimeofday(&end, NULL);
						temps =fabs(end.tv_usec - start.tv_usec); // temps (µs)
						break;
						
		case "sub":
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


void speedTest(char* cmd,int tailleMin,int tailleMax,int pas, int nbSec) {
	int i;
	for(i=tailleMin;i<=tailleMax;i+=pas)
	{
		
	}
	
	//~ 
	//~ srand48(time(NULL));
	//~ 
	//~ int taille_min = atoi(argv[1]);
	//~ int inc = atoi(argv[2]);
	//~ int nb_matrices = atoi(argv[3]);
	//~ int n = taille_min, i; double t1; double t2;
	//~ 
	//~ Matrix m = NULL;
	//~ 
//~ 
	//~ for(i = 0; i < nb_matrices; i++) {
		//~ m = aleatoire(m, n, n, 0, 100); // matrice aléatoire n*n
		//~ 
		//~ 
		//~ determinant_naif(m, n); // naif
		//~ 
		//~ 
		//~ gettimeofday(&start, NULL);
		//~ determinant_opt(m); // optimal
		//~ gettimeofday(&end, NULL);
		//~ t2 = end.tv_usec - start.tv_usec; // temps 2 (µs)
		//~ 
		//~ sauvegarder(n, t1/10000, t2/10000, argv[4]); // écriture dans foutput
		//~ n += inc;
	//~ }
	//~ 
	//~ deleteMatrix(m);
	//~ 
	//~ plot(argv[4]); // écriture resultat.gnu, génération resultat.png
	//~ 
	//~ return 0;
}
