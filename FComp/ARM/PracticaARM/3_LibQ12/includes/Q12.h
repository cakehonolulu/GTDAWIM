/*-----------------------------------------------------------------
|   Declaraci� de tipus, m�scares i macro del format Q12, �s a dir, 
|	en format Coma Fixa 1:19:12.
| -----------------------------------------------------------------
|	pere.millan@urv.cat
|	santiago.romani@urv.cat
|	(Mar� 2021, Mar� 2022)
| ----------------------------------------------------------------*/

#ifndef Q12_H
#define Q12_H


/* Declaraci� de tipus Coma Fixa 1:19:12 
		 1 bit  de signe (bit 31), =0 -> positiu, =1 -> negatiu
		19 bits de part entera (bits 30..12), aprox. 5-6 d�gits en base 10
		12 bits de part fraccion�ria (bits 11..0), aprox. 3-4 d�gits en base 10
*/
typedef int Q12;


/* Macro per convertir valors reals en valors Coma Fixa 1:19:12
		Exemples:
		MAKE_Q12(3.1416) --> 0x00003244
		MAKE_Q12(-5.125) --> 0xFFFEAE00
*/
#define MAKE_Q12(real)	(int)((real)*(1<<12)+(real<0?-0.5:0.5)) 


/* M�SCARES per als camps de bits de valors 1:19:12 */
#define MASK_SIGN	0x80000000	/* bit 31:		signe */
#define MASK_INT	0x7FFFF000	/* bits 30..12:	part entera */
#define MASK_FRAC	0x00000FFF	/* bits 11..0:	part fraccion�ria */



/* Operacions aritm�tiques b�siques en Coma Fixa 1:19:12 */

/* add_Q12():	calcula i retorna la suma dels 2 primers operands,
  (num1 + num2) codificats en coma fixa 1:19:12.
				El 3r par�metre (per refer�ncia) retorna l'overflow:
				0: no s'ha produ�t overflow, resultat correcte.
				1: hi ha overflow (resultat massa gran) i el que es
				   retorna s�n els bits baixos del resultat.
*/
extern Q12 add_Q12(Q12 num1, Q12 num2, unsigned char * overflow);


/* sub_Q12():	calcula i retorna la difer�ncia dels 2 primers operands,
  (num1 - num2) codificats en coma fixa 1:19:12.
				El 3r par�metre (per refer�ncia) retorna l'overflow:
				0: no s'ha produ�t overflow, resultat correcte.
				1: hi ha overflow (resultat massa gran) i el que es
				   retorna s�n els bits baixos del resultat.
*/
extern Q12 sub_Q12(Q12 num1, Q12 num2, unsigned char * overflow);


/* mul_Q12():	calcula i retorna el producte dels 2 primers operands,
  (num1 * num2) codificats en Coma fixa 1:19:12.
				El 3r par�metre (per refer�ncia) retorna l'overflow:
				0: no s'ha produ�t overflow, resultat correcte.
				1: hi ha overflow (resultat massa gran) i el que es
				   retorna s�n els bits baixos del resultat.
*/
extern Q12 mul_Q12(Q12 num1, Q12 num2, unsigned char * overflow);


/* div_Q12():	calcula i retorna la divisi� dels 2 primers operands,
  (num1 / num2) codificats en Coma fixa 1:19:12.
				El 3r par�metre (per refer�ncia) retorna l'overflow:
				0: no s'ha produ�t overflow, resultat correcte.
				1: hi ha overflow (resultat massa gran) i el que es
				   retorna s�n els bits baixos del resultat.
*/
extern Q12 div_Q12(Q12 num1, Q12 num2, unsigned char * overflow);


#endif /* Q12_H */
