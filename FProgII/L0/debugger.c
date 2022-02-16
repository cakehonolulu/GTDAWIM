#include "debugger.h"

int main()
{
	char frase[MAX];
	int nv;
	printf("Escriu una frase acabada amb punt: ");
	scanf("%79[^\n]", frase);

	if (acaba_amb_punt(frase))
	{
		nv = n_vocals(frase);
		printf("Té %d vocals\n", nv);
		a_majuscules(frase);
		printf("La frase amb majúscules és %s\n", frase);
	}
	else
	{
		printf("La frase no acaba amb punt!\n");
	}
}

bool acaba_amb_punt(char frase[MAX])
{
	bool punt_final = false;
	int i = 0;

	while (frase[i] != '\0' && !punt_final)
	{
		if (frase[i] == '.')
		{
			punt_final = true;
		}
		else
		{
			i++;
		}
	}

	return punt_final;
}

void a_majuscules(char frase[MAX])
{
	int i = 0;

	while (frase[i] != '.')
	{
		if (frase[i] >= 'a' && frase[i] <= 'z')
		{
			frase[i] = (frase[i] + ('A' - 'a'));
		}

		i++;
	}
}

bool es_vocal(char c)
{
	bool vocal;

	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
	{
		vocal = true;
	}
	else
	{
		vocal = false;
	}

	return vocal;
}

int n_vocals(char frase[MAX])
{
	int nv = 0, i = 0;

	while (frase[i] != '.')
	{
		if (es_vocal(frase[i]))
		{
			nv++;
		}

		i++;
	}

	return nv;
}
