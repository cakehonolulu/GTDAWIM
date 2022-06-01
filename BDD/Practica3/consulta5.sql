use PRAC3;

-- The main idea behind this query is to locate the lab's name and the biocontention zone's code where they have more than 3 qualified employers; we couldn't manage to order them.

select distinct laboratoris.nom, laboratoris.codi from laboratoris inner join zones_biocontencio on laboratoris.codi = zones_biocontencio.codiLab where laboratoris.codi in (select codiLab from zones_biocontencio inner join qualificats on zones_biocontencio.codi = qualificats.zona_assignada and zones_biocontencio.codiLab = qualificats.lab having count(qualificats.num_pass) >= 3);
