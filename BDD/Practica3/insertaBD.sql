use PRAC3;

--- fill paisos table
insert into paisos(nom, pot_desenv, tractat_signat) values ('Portugal', 3, 'S');
insert into paisos(nom, pot_desenv, tractat_signat) values ('Xina', 10, 'D');
insert into paisos(nom, pot_desenv, tractat_signat) values ('Estats Units', 8, 'N');

--- fill laboratoris table
insert into laboratoris(codi, nom, pais) values (1, 'Lisbon', 'Portugal');
insert into laboratoris(codi, nom, pais) values (741, 'Lab01', 'Portugal');
insert into laboratoris(codi, nom, pais) values (1337, 'Lab-01', 'Portugal');

insert into laboratoris(codi, nom, pais) values (62, 'Pyong', 'Xina');
insert into laboratoris(codi, nom, pais) values (11, 'X-01', 'Xina');
insert into laboratoris(codi, nom, pais) values (1232, 'Lab-01', 'Xina');

insert into laboratoris(codi, nom, pais) values (124, 'Reagan', 'Estats Units');
insert into laboratoris(codi, nom, pais) values (9471, 'Lab01', 'Estats Units');
insert into laboratoris(codi, nom, pais) values (52212, 'A01', 'Estats Units');

--- fill empleats table
insert into empleats(num_pass, nom) values ('89264729A', 'John Doe');
insert into empleats(num_pass, nom) values ('9810391BD', 'CONFIDENTIAL');
insert into empleats(num_pass, nom) values ('721641720', 'Jane Doe');
insert into empleats(num_pass, nom) values ('AABBCCDDE', 'BOB');
insert into empleats(num_pass, nom) values ('001122334', 'Alice');

--- fill ordinaris table
insert into ordinaris(num_pass) value ('721641720');
insert into ordinaris(num_pass) value ('89264729A');

--- zones_biocontencio has a circular dependency w/qualificats; set that field to null and update it later
insert into zones_biocontencio(codi, codiLab, nivell, responsable) values (908070600, 741, 'B', null);

-- fill qualificats table
insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('9810391BD', 'Master Bioquimica', 908070600, 741);

-- update zones_biocontencio with the newly filled qualificats
update zones_biocontencio set responsable = 22222 where zones_biocontencio.codi = 741;

-- fill armes_biologiques table
insert into armes_biologiques(nom, data_, potencial, zona, lab) values ('Arma1', CURDATE(), 2, 908070600, 741);

-- fill assignacions table
insert into assignacions(data_, empl_ord, zona, lab, data_fi_) values (CURDATE(), '721641720', 908070600, 741, CURDATE());
