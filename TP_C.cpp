
/**********************************************************************
***																	***
***				@authors : Josue Lubaki & Raissa Mbikayi			***
***																	***
**********************************************************************/

#include <stdio.h>
#include <math.h>
#include "fonctions.h"
#include "fonctions.cpp"

int main(void)
{
	//declaration et initialisation des variables.
	short int n1 = 0;
	short int n2 = 0;
	double exposant = 0;
	short choix = 0;
	int continuer = 0;

	do {

		printf("\nVoici nos 5 fonctions disponibles\nTapez:\n\t(1) Pour la fonction addictionSINT()\n\t");
		printf("(2) Pour la fonction Epsilon()\n\t(3) Pour la fonction somme consecutif\n\t");
		printf("(4) Pour la fonction somme ascendante et descendante\n\t(5) Pour la fonction rtbis()\n\n");

		do{
			printf("Faites votre choix parmi les fonctions disponibles ");
			scanf_s("%hd", &choix);
		} while (choix <= 0 || choix > 32767);


		switch (choix)
		{
			case 1:
			{
				printf("Entrer deux valeurs entre -32768 et 32767\n");
				scanf_s("%hi\n" "%hi", &n1, &n2);

			/*
				Appel de la fonction addictionSINT() qui recoit deux paramètre; et en fait la somme
				tout en verifiant s'il y a debordement de l'espace alloué (overflow positif ou negatif)
			*/
				additionSINT(n1, n2);
			}

			break;

			case 2:
			{
			//Appel de la fonction Epsilon
				epsilonf();
				epsilond();
			}
			break;

			case 3:
			{
			//Fonction Somme successive
				printf("Entrer l'exposant x pour la base 10^x\tx = ");
				scanf_s("%lf", &exposant);

			//printf("Vous avez entre 10^%d\n", exposant);
				sommef(exposant);
				sommed(exposant);

			}
			break;

			case 4:
			{
			//Appel de fonction somme ascendante à simple précision
				sommeascf();

			//Appel de la fonction somme ascendante à double précision
				sommeascd();

			//Appel de la fonction somme descendante à simple precision
				sommedescf();

			//Appel de la fonction somme descendante à double precision
				sommedescd();
			}
			break;

			case 5:
			{
				double F(double x);
				double rtbis(double x1, double x2, double theta0, double v0, double y0, double xacc, double
				zeroacc);

				// Exemple d'appel permettant le calcul de la distance en x parcourue par une balle
				// Parametre 1 x1: borne inferieure des valeurs en x (m)
				// Parametre 2 x2: borne superieure des valeurs en x (m)
				// Parametre 3 theta0: angle en degre par rapport de la direction de la balle au depart
				// Parametre 4 v0: vitesse initiale (m/s)
				// Parametre 5 y0: hauteur de la balle au depart (m)
				// Parametre 6 xacc: precision sur la localisation de la racine en x
				// Parametre 7 zeroacc: précision sur la localisation du 0 de fonction (en y)

				printf("\n Valeur de la racine (bissection) = %lf m.\n\n", rtbis(1, 300, 30, 50, 2, PRECISIONX,
				PRECISIONZERO));
			}
			break;

			default:
				printf("Cette fonction n'est pas repertoriee, choississez une fonction disponible\n\n");
			break;
		}

		//Condition de validation pour poursuivre avec le programme
			do{
				printf("Voulez-vous utiliser une autre fonction ? Tapez (1) pour Oui / (0) pour Non\n");
				scanf_s("%d", &continuer);
			} while (continuer != 0 && continuer != 1);

	} while (continuer == 1);
	printf("\nNous esperons vous revoir tres BIENTOT dans notre application\n");
	return 0;
}
