/** 
 * Funcio que calcula la mitjana d'una taula que conte 'nv' enters
 * @param taula (Valor (E): taula d'enters). La taula amb les dades
 * @param nv (Valor (E): enter). El nombre d'elements efectius 
 * @return float. La mitjana aritmetica dels nv valors
 */ 
float mitjana(int taula[], int nv);    

/** 
 * Funcio que troba el maxim i el minim d'una taula que conte 'nv' enters
 * @param taula (Valor (E): taula d'enters). La taula amb les dades
 * @param nv (Valor (E): enter). El nombre d'elements efectius 
 * @param max (Ref. (S): enter). El valor maxim
 * @param min (Ref. (S): enter). El valor minim
 */ 
void maxmin(int taula[], int nv, int *max, int *min);
