use PRAC3;

-- The main idea behind this query is to locate the laboratory's code and name where the level of dangerousness equals to 'A' (Alt).
-- It also specifies us to order by the name of them.

select distinct laboratoris.codi,laboratoris.nom from laboratoris inner join zones_biocontencio on laboratoris.codi = zones_biocontencio.codiLab where zones_biocontencio.nivell = 'A' order by laboratoris.nom;
