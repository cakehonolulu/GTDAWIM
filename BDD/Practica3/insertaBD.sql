use PRAC3;

--- fill paisos table
insert into paisos(nom, pot_desenv, tractat_signat) values ('Portugal', 3, 'S');
insert into paisos(nom, pot_desenv, tractat_signat) values ('Xina', 10, 'D');
insert into paisos(nom, pot_desenv, tractat_signat) values ('Estats Units', 8, 'N');
insert into paisos(nom, pot_desenv, tractat_signat) values ('Italia', 6, 'N');
insert into paisos(nom, pot_desenv, tractat_signat) values ('Espanya', 5, 'S');
insert into paisos(nom, pot_desenv, tractat_signat) values ('Korea', 8, 'N');

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

insert into laboratoris(codi, nom, pais) values (2, 'Flipp', 'Italia');
insert into laboratoris(codi, nom, pais) values (41, 'L4B', 'Italia');
insert into laboratoris(codi, nom, pais) values (337, 'LXKE', 'Italia');

insert into laboratoris(codi, nom, pais) values (90, 'BCN-XXX', 'Espanya');
insert into laboratoris(codi, nom, pais) values (1289, 'Mayor', 'Espanya');
insert into laboratoris(codi, nom, pais) values (54124, 'Esme', 'Espanya');

insert into laboratoris(codi, nom, pais) values (253, 'Ping', 'Korea');
insert into laboratoris(codi, nom, pais) values (42532, 'Namp', 'Korea');
insert into laboratoris(codi, nom, pais) values (8423, 'Xae', 'Korea');

--- fill empleats table
insert into empleats(num_pass, nom) values ('89264729A', 'John Doe');
insert into empleats(num_pass, nom) values ('9810391BD', 'CONFIDENTIAL');
insert into empleats(num_pass, nom) values ('721641720', 'Jane Doe');
insert into empleats(num_pass, nom) values ('AABBCCDDE', 'BOB');
insert into empleats(num_pass, nom) values ('001122334', 'Alice');
insert into empleats(num_pass, nom) values ('235981241', 'Pep');
insert into empleats(num_pass, nom) values ('129427314', 'Joan');
insert into empleats(num_pass, nom) values ('941231234', 'Sivir');
insert into empleats(num_pass, nom) values ('I8912E123', 'Jayce');
insert into empleats(num_pass, nom) values ('982141231', 'Flive');
insert into empleats(num_pass, nom) values ('124512412', 'Ivan');
insert into empleats(num_pass, nom) values ('132552351', 'Paul');
insert into empleats(num_pass, nom) values ('523523123', 'Adrian');
insert into empleats(num_pass, nom) values ('341245124', 'Zeke');
insert into empleats(num_pass, nom) values ('98124214A', 'Cole');

insert into empleats(num_pass, nom) values ('182471241', 'Angel');
insert into empleats(num_pass, nom) values ('098124871', 'Pere');
insert into empleats(num_pass, nom) values ('A91231231', 'Peter');
insert into empleats(num_pass, nom) values ('12398412A', 'Schneid');
insert into empleats(num_pass, nom) values ('91728412C', 'Ling');
insert into empleats(num_pass, nom) values ('12512412S', 'Pei');
insert into empleats(num_pass, nom) values ('87214124A', 'Bruce');
insert into empleats(num_pass, nom) values ('18924124Z', 'Wiom');
insert into empleats(num_pass, nom) values ('871241241', 'Shayn');
insert into empleats(num_pass, nom) values ('91824821S', 'Maria');
insert into empleats(num_pass, nom) values ('61246123A', 'Angela');

--- fill ordinaris table
insert into ordinaris(num_pass) value ('721641720');
insert into ordinaris(num_pass) value ('89264729A');
insert into ordinaris(num_pass) value ('129427314');
insert into ordinaris(num_pass) value ('941231234');
insert into ordinaris(num_pass) value ('982141231');
insert into ordinaris(num_pass) value ('235981241');
insert into ordinaris(num_pass) value ('98124214A');
insert into ordinaris(num_pass) value ('124512412');

--- zones_biocontencio has a circular dependency w/qualificats; set that field to null and update it later
insert into zones_biocontencio(codi, codiLab, nivell, responsable) values (908070600, 1, 'A', null);
insert into zones_biocontencio(codi, codiLab, nivell, responsable) values (129874123, 741, 'M', null);
insert into zones_biocontencio(codi, codiLab, nivell, responsable) values (101134241, 1337, 'A', null);
insert into zones_biocontencio(codi, codiLab, nivell, responsable) values (918241242, 62, 'B', null);
insert into zones_biocontencio(codi, codiLab, nivell, responsable) values (124891241, 11, 'B', null);
insert into zones_biocontencio(codi, codiLab, nivell, responsable) values (671241241, 1232, 'M', null);
insert into zones_biocontencio(codi, codiLab, nivell, responsable) values (785123712, 124, 'A', null);
insert into zones_biocontencio(codi, codiLab, nivell, responsable) values (761241412, 9471, 'A', null);
insert into zones_biocontencio(codi, codiLab, nivell, responsable) values (909124791, 52212, 'A', null);
insert into zones_biocontencio(codi, codiLab, nivell, responsable) values (812741012, 2, 'B', null);
insert into zones_biocontencio(codi, codiLab, nivell, responsable) values (741092480, 41, 'M', null);
insert into zones_biocontencio(codi, codiLab, nivell, responsable) values (466131012, 337, 'M', null);
insert into zones_biocontencio(codi, codiLab, nivell, responsable) values (198214124, 90, 'A', null);
insert into zones_biocontencio(codi, codiLab, nivell, responsable) values (987124214, 1289, 'A', null);
insert into zones_biocontencio(codi, codiLab, nivell, responsable) values (712471241, 54124, 'M', null);
insert into zones_biocontencio(codi, codiLab, nivell, responsable) values (812747124, 253, 'B', null);
insert into zones_biocontencio(codi, codiLab, nivell, responsable) values (981247124, 42532, 'B', null);
insert into zones_biocontencio(codi, codiLab, nivell, responsable) values (741274124, 8423, 'M', null);

-- fill qualificats table
insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('9810391BD', 'Master Bioquimica', 908070600, 1);
insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('89264729A', 'Doctorat Quimica', 908070600, 1);

insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('235981241', 'Master Bioquimica', 129874123, 741);

insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('341245124', 'Grau Superior Quimica', 101134241, 1337);

insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('124512412', 'Master Ciberseguretat', 918241242, 62);

insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('941231234', 'Doctorat Fisica', 124891241, 11);

insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('132552351', 'Master Fisica', 671241241, 1232);

insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('721641720', 'Grau Quimica', 785123712, 124);

insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('182471241', 'Master Bioquimica', 761241412, 9471);
insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('098124871', 'Doctorat Quimica', 909124791, 52212);

insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('A91231231', 'Master Bioquimica', 812741012, 2);

insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('12398412A', 'Grau Superior Quimica', 741092480, 41);

insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('91728412C', 'Master Ciberseguretat', 466131012, 337);

insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('12512412S', 'Doctorat Fisica', 198214124, 90);

insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('87214124A', 'Master Fisica', 987124214, 1289);

insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('18924124Z', 'Grau Quimica', 712471241, 54124);

insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('871241241', 'Doctorat Fisica', 812747124, 253);

insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('91824821S', 'Master Fisica', 981247124, 42532);

insert into qualificats(num_pass, titulacio, zona_assignada, lab) values ('61246123A', 'Grau Quimica', 741274124, 8423);

-- update zones_biocontencio with the newly filled qualificats
update zones_biocontencio set responsable = 22222 where zones_biocontencio.codi = 741;

-- fill armes_biologiques table
insert into armes_biologiques(nom, data_, potencial, zona, lab) values ('Arma1', CURDATE(), 2, 908070600, 741);

-- fill assignacions table
insert into assignacions(data_, empl_ord, zona, lab, data_fi_) values (CURDATE(), '721641720', 129874123, 741, CURDATE());
insert into assignacions(data_, empl_ord, zona, lab, data_fi_) values (CURDATE(), '235981241', 101134241, 1337, CURDATE());
insert into assignacions(data_, empl_ord, zona, lab, data_fi_) values (CURDATE(), '124512412', 918241242, 62, CURDATE());
