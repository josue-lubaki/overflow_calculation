
/**********************************************************************
***																	***
***				@authors : Josue Lubaki & Raissa Mbikayi			***
***																	***
**********************************************************************/

#include <stdio.h>
#include <math.h>
#include "fonctions.h"

//	PARTIE EXPLICITE DE TOUTES LES FONCTIONS DE MON PROGRAMME
void additionSINT(short int nombre1, short int nombre2) {
	short int somme = 0;
	somme = nombre1 + nombre2;
	printf("La somme en short int est %hi \n", somme);

	//Condition pour verifier les overflows dans le calcul
	if ((nombre1 < 0 && nombre2 < 0 && somme >= 0))
		printf("il y a un deborderment negatif\n\n");
	else if ((nombre1 > 0 && nombre2 > 0 && somme < 0))
		printf("il y a debordement positif\n\n");
	else
		printf("Le calcul est correct\n\n");
}

//	Fonction epsilon pour la répresentation réelle simple précision (float)
void epsilonf() {
	float eps = 1; //epsilon de l'architecture INTEL vaut 10^-20
	float n = 0;
	float unPluseps = 1 + eps;

	while (unPluseps > 1) {
		eps = eps / 2;
		unPluseps = 1 + eps;
		n++;
	}
	printf("\nEpsilon a simple precision = %.40f\n", eps * 2);
	printf("Nombre de chiffre significatif a simple precision = %f\n\n", n - 1);
}

//Fonction epsilon pour la répresentation double précision
void epsilond() {
	double eps = 1;
	double n = 0;
	double unPluseps = 1 + eps;

	while (unPluseps > 1) {
		eps = eps / 2;
		unPluseps = 1 + eps;
		n++;
	}
	printf("Epsilon a double precision = %.40f\n", eps * 2);
	printf("Nombre de chiffre significatif a double precision = %f\n\n", n - 1);
}

//	Somme successive (float)
void sommef(double exposant) {
	float N = (float)pow(10, exposant);
	float i = 1.0;
	float saut = 1 / N;
	float somme = 0;
	do {
		somme = somme + saut;
		i++;
	} while (i <= N);
	printf("\nLa valeur de N (simple precision) est %f\nLa somme est %.40f\n", N, somme);
	float y = 1 - somme;
	printf("L\'erreur est %.40f \n\n", y);
}

//	Somme successive (double)
void sommed(double exposant) {
	double N = pow(10, exposant);
	double i = 1;
	double saut = 1 / N;
	double somme = 0;
	do {
		somme = somme + saut;
		i++;
	} while (i <= N);
	printf("La valeur de N (double precision) est %f\nLa somme est %.40f\nL\'erreur est %.40f \n\n", N, somme, (1 - somme));
}

//Fonction Somme Ascendante à simple precision (float)
void sommeascf() {
	float n = 1;
	while (n <= 3) {
		float i = 1.0;
		float somme = 0;
		while (i <= 32767) {
			somme = somme + (float)(1 / powf(i, n));
			i++;
		}
		printf("\nLa somme asc pour N (float) %f est : %.40f", n, somme);
		n++;
	}
	printf("\n");
}

//Fonction Somme ascendante à double précision
void sommeascd() {
	double n = 1;
	while (n <= 3) {
		double i = 1.0;
		double somme = 0;
		while (i <= 32767) {
			somme = somme + (1 / pow(i, n));
			i++;
		}
		printf("\nLa somme asc pour N (double) %f est : %.40f", n, somme);
		n++;
	}
	printf("\n");
}

//Fonction Somme descendante à simple precision (float)
void sommedescf() {
	float n = 1;
	while (n <= 3) {
		float i = 32767.0;
		float somme = 0;
		while (i >= 1.0) {
			somme = somme + (float)(1.0 / powf(i, n));
			i--;
		}
		printf("\nLa somme desc pour N (float) %f est : %.40f", n, somme);
		n++;
	}
	printf("\n");
}

//Fonction Somme descendante à double précision
void sommedescd() {
	double n = 1;
	while (n <= 3) {
		double i = 32767.0;
		double somme = 0;
		while (i >= 1.0) {
			somme = somme + (1 / pow(i, n));
			i--;
		}
		printf("\nLa somme desc pour N (double) %f est : %.40f", n, somme);
		n++;
	}
	printf("\n\n");
}

/*
	Fonction qui calcule la valeur de la fonction parabolique, qui calcul la position y (hauteur)
	d'une balle sur sa
	trajectoire en x
*/
double F(double x, double theta0, double v0, double y0)
{
	return (tan(theta0 * PI / 180.0) * x - ((G / (2.0 * v0 * v0 * cos(theta0 * PI / 180.0) * cos(theta0 * PI /
		180.0))) * x * x) + y0);
}

/*
Fonction qui calcule la valeur de la position x pour y = 0 donnant la distance parcourue d'une
balle
*/
double rtbis(double x1, double x2, double theta0, double v0, double y0, double xacc, double
	zeroacc)
{
	int j;
	double dx, f, fmid, xmid, rtb;

	f = F(x1, theta0, v0, y0);
	fmid = F(x2, theta0, v0, y0);
	if (f * fmid >= 0.0) printf("\nRacine absente de cet intervalle dans RTBIS\n");
	rtb = f < 0.0 ? (dx = x2 - x1, x1) : (dx = x1 - x2, x2);
	for (j = 1; j <= MAXIT; j++) {
		fmid = F(xmid = rtb + (dx *= 0.5), theta0, v0, y0);
		if (fmid <= 0.0) rtb = xmid;
		if (fabs(dx) < xacc || fabs(fmid) < zeroacc)
		{
			printf("\nNombre d'iterations: %d dx: %17.15lf f(rtb): %17.15lf",
				j, dx, fmid);
			return rtb;
		}
		//printf("Trop de bissections dans RTBIS\n");
	}
}