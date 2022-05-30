use PRAC3;

select zones_biocontencio.codi
from zones_biocontencio
where zones_biocontencio.codi in (  select qualificats.zona_assignada
                                    from qualificats
                                    having count(qualificats.num_pass)>=3);