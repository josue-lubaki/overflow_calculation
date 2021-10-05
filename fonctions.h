
/**********************************************************************
***																	***
***				@authors : Josue Lubaki & Raissa Mbikayi			***
***																	***
**********************************************************************/

#ifndef FONCTIONS_H
#define FONCTIONS_H

/*
	Definition des onstantes et prototypes des fonctions, dont on retrouve la partie
	explicite après la fonction principale main(void)
*/
// Definition de constantes utiles
#define MAXIT 100
#define PI 3.14159
#define G 9.81
#define PRECISIONX 0.00000000000000000001
#define PRECISIONZERO 0.0000000000000000001
//Prototypes des fonctions
void additionSINT(short int nombre1, short int nombre2);
void epsilonf();
void epsilond();
void sommef(double exposant);
void sommed(double exposant);
void sommeascf();
void sommeascd();
void sommedescf();
void sommedescd();

#endif