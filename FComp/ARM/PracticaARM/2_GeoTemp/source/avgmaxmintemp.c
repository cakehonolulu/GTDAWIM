/*----------------------------------------------------------------
|   "avgmaxmintemp.c": rutines de c�lcul de valors mitjans, m�xims
|	i m�nims d'una taula de temperatures, expressades en graus
|	Celsius o Fahrenheit, en format Q12 (coma fixa 1:19:12).
| ----------------------------------------------------------------
|	santiago.romani@urv.cat
|	pere.millan@urv.cat
|	(Abril 2021, Mar� 2022)
| ----------------------------------------------------------------*/

#include <Q12.h>				/* Q12: tipus Coma Fixa 1:19:12 */
#include "divmod.h"				/* rutina div_mod(), en "LibFonCompus.a" */
#include "CelsiusFahrenheit.h"	/* rutines de conversi� C->F i F->C */
#include "avgmaxmintemp.h"		/* mmres: tipus de retorn de m�xim i m�nim */


/* avgmaxmin_city(): calcula la temperatura mitjana, m�xima i m�nima d'una
|				ciutat d'una taula de temperatures, amb una fila per ciutat i
|				una columna per mes, expressades en graus Celsius en format
|				Q12.
|	Par�metres:
|		ttemp[][12]	->	taula de temperatures, amb 12 columnes i nrows files
|		nrows		->	n�mero de files de la taula
|		id_city		->	�ndex de la fila (ciutat) a processar
|		*mmres		->	adre�a de l'estructura t_maxmin que retornar� els
|						resultats de temperatures m�ximes i m�nimes
|	Resultat:	temperatura mitjana, expressada en graus Celsius, en format Q12.
*/	
#ifndef CHECK_ASM
Q12 avgmaxmin_city(Q12 ttemp[][12], unsigned short nrows, unsigned short id_city, t_maxmin *mmres)
{
	Q12 avg, max, min;
	unsigned short idmin = 0, idmax = 0;	// �ndexos de temp. m�nima i m�x.
	unsigned short i;
	Q12 tvar;						// variable temporal de temperatura
  
	avg = ttemp[id_city][0];		// inicialitza valors amb primera columna
	max = avg;						// (mes de gener)
	min = avg;
	for (i = 1; i < 12; i++)		// per a la resta de mesos
	{
		tvar = ttemp[id_city][i];			// obtenir temperatura del seg�ent mes
		avg += tvar;
		if (tvar > max)
		{	max = tvar;						// actualitzar valors resultat
			idmax = i;
		}
		if (tvar < min)
		{
			min = tvar;
			idmin = i;
		}
	}

	avg /= 12;						// ajustar valor mitj�
	
	mmres->tmin_C = min;			// transferir m�nim-m�xim en Celsius
	mmres->tmax_C = max;
									// transferir m�nim-m�xim en Fahrenheit
	mmres->tmin_F = Celsius2Fahrenheit(min);
	mmres->tmax_F = Celsius2Fahrenheit(max);
									// transferir �ndexos m�nim i m�xim
	mmres->id_min = idmin;
	mmres->id_max = idmax;

	return(avg);
}
#endif

/* avgmaxmin_month(): calcula la temperatura mitjana, m�xima i m�nima d'un mes
|				d'una taula de temperatures, amb una fila per ciutat i una
|				columna per mes, expressades en graus Celsius en format Q12.
|	Par�metres:
|		ttemp[][12]	->	taula de temperatures, amb 12 columnes i nrows files
|		nrows		->	n�mero de files de la taula (m�nim 1 fila)
|		id_month	->	�ndex de la columna (mes) a processar
|		*mmres		->	adre�a de l'estructura t_maxmin que retornar� els
|						resultats de temperatures m�ximes i m�nimes
|	Resultat:	temperatura mitjana, expressada en graus Celsius, en format Q12.
*/		

Q12 avgmaxmin_month(Q12 ttemp[][12], unsigned short nrows, unsigned short id_month, t_maxmin *mmres)
{
	Q12 avg, max, min;
	unsigned short idmin = 0, idmax = 0;	// �ndexos de temp. m�nima i m�x.
	unsigned short i;
	Q12 tvar;						// variable temporal de temperatura
	unsigned int mod;				// variable per invocar div_mod()
	unsigned char avgNeg;			// boole� per indicar si mitjana negativa
 
	avg = ttemp[0][id_month];		// inicialitza valors amb primera fila
	max = avg;						// (primera ciutat de la taula)
	min = avg;
	i = 1;							// posicionar �ndex a la segona fila
	while (i < nrows)				// per a la resta de ciutats
	{
		tvar = ttemp[i][id_month];		// obtenir temperatura seg�ent ciutat
		avg += tvar;
		if (tvar > max)
		{	max = tvar;						// actualitzar valors resultat
			idmax = i;
		}
		if (tvar < min)
		{
			min = tvar;
			idmin = i;
		}
		i++;
	}
	avgNeg = (avg < 0);					// memoritza si valor acumulat negatiu
	tvar = (avgNeg ? -avg : avg); 		// tvar cont� valor absolut de avg
	div_mod(tvar, nrows, (unsigned int *)&avg, &mod);	// calcular valor mitj� sobre avg
	if (avgNeg) avg = -avg;				// canviar signe de valor mitj�
	
	mmres->tmin_C = min;			// transferir m�nim-m�xim en Celsius
	mmres->tmax_C = max;
									// transferir m�nim-m�xim en Fahrenheit
	mmres->tmin_F = Celsius2Fahrenheit(min);
	mmres->tmax_F = Celsius2Fahrenheit(max);
									// transferir �ndexos m�nim i m�xim
	mmres->id_min = idmin;
	mmres->id_max = idmax;

	return(avg);
}

