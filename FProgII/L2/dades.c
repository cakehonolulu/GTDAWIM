#include <dades.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/** 
 * Funcio que emplena la taula amb 'nv' enters aleatoris
 * Els valors estan entre max i min ambdos inclosos
 * @param taula (Ref. (S): taula d'enters). La taula a emplenar
 * @param nv (Valor (E): enter). El nombre d'elements efectius
 * @param min (Valor (E): enter). El valor minim que prenen els valors
 * @param max (Valor (E): enter). El valor maxim que prenen els valors
 */ 
void obtenir_dades(int taula[], int nv, int min, int max)
{
	int i;

	srand(time(0));

	for (i = 0; i < nv ; i++)
	{
		taula[i] = (rand() % (max + 1)) + min;
	}
}

/** 
 * Funcio que mostra per pantalla les dades
 * @param taula (Valor (E): taula d'enters). La taula amb les dades
 * @param nv (Valor (E): enter). El nombre d'elements efectius 
 */ 
void mostrar_dades(int taula[], int nv)
{
	int i;

	for (i = 0; i < nv; i++)
	{
		printf("%d ", taula[i]);
	}

	printf("\n");
}
