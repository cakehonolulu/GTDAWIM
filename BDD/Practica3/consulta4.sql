use PRAC3;

-- The main idea behind this query is to select the employers name that are not found in the merge of zones_biocontencio,ordinaris and assignacions if and only if they comply with a series of preconditions; the most important one being that the employee's don't have to be assigned to a zones_biocontencio where it's nivell is 'A' (Alt).
-- This gets automatically filtered out by the initial select _not in_

select distinct empleats.nom from empleats where empleats.nom not in (select distinct empleats.nom from empleats inner join ordinaris on empleats.num_pass=ordinaris.num_pass inner join assignacions on ordinaris.num_pass=assignacions.empl_ord inner join zones_biocontencio on assignacions.zona = zones_biocontencio.codi and assignacions.lab = zones_biocontencio.codiLab where zones_biocontencio.nivell = 'A')
