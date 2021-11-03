#include <stdio.h>

int main()
{
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