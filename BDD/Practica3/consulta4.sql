use PRAC3;

select distinct empleats.nom from empleats where empleats.num_pass in (select distinct assignacions.empl_ord from assignacions where assignacions.zona in (select distinct zones_biocontencio.codi from zones_biocontencio where zones_biocontencio.nivell != 'A'));
