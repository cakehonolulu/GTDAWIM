#include "fahr.h"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Fº->Cº\n");
		printf("Ús: ./ftoc [nom_del_arxiu]\n");
		return 1;
	}

	char *m_filename;

	m_filename = argv[1];

	printf("Nom del arxiu: %s\n", m_filename);

	m_file_load(m_filename);

	float m_fahrenheit;
	float m_celsius;

	printf("Fº->Cº\n");
	printf("Conversor de Fahrenheit a Celsius\n");
	printf("Escrigui una temperatura en Fahrenheit: ");

	scanf("%f", &m_fahrenheit);

	m_celsius = (((m_fahrenheit - 32) * 5) / 9);

	printf("%0.2fº Fahrenheits són %0.2fº Celsius!\n", m_fahrenheit, m_celsius);

	return 0;
}