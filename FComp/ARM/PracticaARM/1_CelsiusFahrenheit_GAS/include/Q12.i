@;----------------------------------------------------------------
@;  Declaraci� de constants GAS per al tractament de dades 
@;	en format Coma Fixa 1:19:12.
@;----------------------------------------------------------------
@;	pere.millan@urv.cat
@;	santiago.romani@urv.cat
@;	(Mar� 2021, Mar� 2022)
@;----------------------------------------------------------------

@; M�SCARES per als camps de bits de valors 1:19:12
MASK_SIGN 			= 0x80000000	@; bit 31:		signe
MASK_INT  			= 0x7FFFF000	@; bits 30..12:	part entera
MASK_FRAC 			= 0x00000FFF	@; bits 11..0:	part fraccion�ria

MAKE_Q12_5_div_9 	= 0x000008E4
MAKE_Q12_9_div_5 	= 0x00001CCD
MAKE_Q12_32 		= 0x00020000
