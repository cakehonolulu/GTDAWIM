drop database PRAC3;

create database PRAC3;
use PRAC3;

create table paisos (
    nom varchar(25) not null primary key,
    pot_desenv int(2) check (pot_desenv >= 0 AND pot_desenv <= 10),
    tractat_signat varchar(1) check (tractat_signat LIKE "S" OR tractat_signat LIKE "N" OR tractat_signat LIKE "D")
) engine=innodb;

create table laboratoris (
    codi int(10) not null primary key,
    nom varchar(25) not null,
    pais varchar(25) not null,
    constraint foreign key (pais) references paisos (nom)
) engine=innodb;

create table empleats (
    num_pass varchar(9) primary key not null,
    nom varchar(32) not null
) engine=innodb;

create table ordinaris (
    num_pass varchar(9) primary key,
    constraint foreign key (num_pass) references empleats (num_pass)
) engine=innodb;

create table zones_biocontencio (
    codi int(5) not null,
    codiLab int(10) not null,
    nivell varchar(1) not null check (nivell LIKE "A" OR nivell LIKE "M" OR nivell LIKE "B"),
    responsable varchar(9) not null,
    primary key (codi, codiLab),
    constraint foreign key (codiLab) references laboratoris (codi)
) engine=innodb;

create table qualificats (
    num_pass varchar(9) primary key,
    titulacio varchar(32) not null,
    zona_assignada int(5) not null,
    lab int(10) not null,
    constraint foreign key (num_pass) references empleats (num_pass),
    constraint foreign key (zona_assignada) references zones_biocontencio (codi),
    constraint foreign key (lab) references zones_biocontencio (codiLab)
) engine=innodb;

alter table zones_biocontencio
add constraint foreign key (responsable) references qualificats (num_pass);

create table armes_biologiques (
    nom varchar(10) not null primary key,
    data_ date not null,
    potencial int(2) not null check (potencial >= 0 AND potencial <= 10),
    zona int(5) not null,
    lab int(10) not null,
    constraint foreign key (zona) references zones_biocontencio (codi),
    constraint foreign key (lab) references zones_biocontencio (codiLab)
) engine=innodb;

insert into paisos(nom, pot_desenv, tractat_signat) values ('Regne Unit', 1, 'S');

insert into laboratoris(codi,nom, pais) values (1, 'Lab01', 'Regne Unit');
