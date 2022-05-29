use PRAC3;

insert into paisos(nom, pot_desenv, tractat_signat) values ('Portugal', 3, 'S');
insert into paisos(nom, pot_desenv, tractat_signat) values ('Xina', 10, 'D');
insert into paisos(nom, pot_desenv, tractat_signat) values ('Estats Units', 8, 'N');

insert into laboratoris(codi, nom, pais) values (1, 'Lisbon', 'Portugal');
insert into laboratoris(codi, nom, pais) values (741, 'Lab01', 'Portugal');
insert into laboratoris(codi, nom, pais) values (1337, 'Lab-01', 'Portugal');

insert into laboratoris(codi, nom, pais) values (62, 'Pyong', 'Xina');
insert into laboratoris(codi, nom, pais) values (11, 'X-01', 'Xina');
insert into laboratoris(codi, nom, pais) values (1232, 'Lab-01', 'Xina');

insert into laboratoris(codi, nom, pais) values (124, 'Reagan', 'Estats Units');
insert into laboratoris(codi, nom, pais) values (9471, 'Lab01', 'Estats Units');
insert into laboratoris(codi, nom, pais) values (52212, 'A01', 'Estats Units');

insert into empleats(num_pass, nom) values ('89264729A', 'John Doe');
insert into empleats(num_pass, nom) values ('9810391BD', 'CONFIDENTIAL');
insert into empleats(num_pass, nom) values ('721641720', 'Jane Doe');
insert into empleats(num_pass, nom) values ('AABBCCDDE', 'BOB');
insert into empleats(num_pass, nom) values ('001122334', 'Alice');

insert into ordinaris(num_pass) value ('721641720');
insert into ordinaris(num_pass) value ('89264729A');

--insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('9810391BD', 'Master Bioquimica', 908070600, 741);
--insert into zones_biocontencio(codi, codiLab, nivell) values (908070600, 741, 'B');