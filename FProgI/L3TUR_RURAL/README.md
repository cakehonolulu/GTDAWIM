# Laboratory 3 - Turisme Rural

## Joc de proves

| Prova | Descripció                          | Entrades               | Sortida esperada                                                   | Sortida obtinguda                                                               | OK? |
| :---- |:----------------------------------- |:---------------------- |:------------------------------------------------------------------ |:------------------------------------------------------------------------------- |:---:|
| 1     | Es supera la capacitat de la casa   | Persones: 13, Nits: 10 | Ha introduit (x > 12) persones, el máxim són 12!                   | Ha introduit 13 persones, el máxim són 12!                                      | ✓   |
| 2     | S'ocupa tota la casa                | Persones: 12, Nits: 10 | Preu allotjament 1500 euros, IVA 135 euros, Preu total 1815 euros  | Preu sense IVA: 1500 €, IVA (21%): 315.00 €, Preu Total (IVA Inclòs): 1815.00 € | ✓   |
| 3     | No s'ocupa tota la casa             | Persones: 11, Nits: 3  | Preu allotjament 450 euros, IVA 94.5 euros, Preu total 554,5 euros | Preu sense IVA: 450 €, IVA (21%): 94.50 €, Preu Total (IVA Inclòs): 544.50 €    | ✓   |
| 4     | Es supera el total de nits permeses | Persones: 11, Nits: 13 | Ha introduit (x > 12) nits, el máxim són 12!                       | El nombre de nits excedeix les 12 máximes permeses!                             | ✓   |
