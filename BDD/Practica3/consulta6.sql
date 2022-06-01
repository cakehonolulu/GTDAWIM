use PRAC3;

-- The main idea behind this one is to grab the name of the employers that are from the ordinaris table that have been to the BCN-XXX lab sometime into their lifespan; it currently targets currently assigned ones and not previously assigned ones.

select empleats.nom from empleats inner join ordinaris on empleats.num_pass = ordinaris.num_pass where ordinaris.num_pass in (select assignacions.empl_ord from assignacions where assignacions.zona in ( select zones_biocontencio.codi from  zones_biocontencio inner join laboratoris on zones_biocontencio.codiLab = laboratoris.codi where laboratoris.nom = 'BCN-XXX') and assignacions.lab in ( select zones_biocontencio.codiLab from  zones_biocontencio inner join laboratoris on zones_biocontencio.codiLab = laboratoris.codi where laboratoris.nom = 'BCN-XXX'));
