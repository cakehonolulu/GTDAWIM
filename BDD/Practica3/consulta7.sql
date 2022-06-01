use PRAC3;

-- This query tries to find all the ordinary employers that have been to more zones than the employee 'Jordi Guasch'

select empl_ord from assignacions group by assignacions.empl_ord having count(*) > (select count(*) from assignacions inner join empleats on (select num_pass from ordinaris where ordinaris.num_pass = empleats.num_pass) where empleats.nom = 'Jordi Guasch');
