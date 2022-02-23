#include <stdio.h>

int main()
{
	FILE *m_file;
	short int m_number;

	m_file = fopen("secret.bin", "rb");

	if (m_file)
	{
		fseek(m_file, 6, SEEK_SET);

		fread(&m_number, sizeof(m_number), 1, m_file);

		do {
			printf("%c", (char) (m_number / 66));
			fread(&m_number, sizeof(m_number), 1, m_file);
		} while (m_number != -1);

		printf("\n");

		fclose(m_file);
	}

	return 0;
}
