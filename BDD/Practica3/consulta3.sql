use PRAC3;

select distinct laboratoris.codi,laboratoris.nom from laboratoris inner join zones_biocontencio on laboratoris.codi = zones_biocontencio.codiLab where nivell = 'A' order by nom;