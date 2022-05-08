#include "cjt_paraules.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void inicialitzar(cjt_paraules_t *c)
{
    memset(c, 0, sizeof(*c));
}

bool afegir(cjt_paraules_t *c, char p[])
{
    bool m_result = true, m_check = true;
    int i = 0, m_len;

    if (ple(c))
    {
        m_result = false;
    }
    else
    {
        m_len = strlen(p);

        if (m_len < 8)
        {  
            while (p[i] != '\0' && m_check == true)
            {
                if (isalnum(p[i]) != 0)
                {
                    if (isdigit(p[i]) == 0)
                    {
                        if (islower(p[i]) == 0)
                        {
                            m_check = false;
                            m_result = false;
                        }
                    }
                }
                else
                {
                    m_check = false;
                    m_result = false;
                }

                i++;
            }
            
            if (m_result != false)
            {
                m_check = true;
                i = 0;

                while (m_check == true && i < MAX_EL)
                {
                    if (c->paraules[i] == 0)
                    {
                        c->paraules[i] = malloc((sizeof(char) * m_len + 1));
                            
                        if (c->paraules[i] != NULL)
                        {
                            strncpy(c->paraules[i], p, (sizeof(char) * m_len + 1));
                            c->n_el++;
                        }
                        else
                        {
                            printf("No hi ha memòria disponible!\n");
                            m_result = false;
                        }

                        m_check = false;
                    }

                    i++;
                }
            }
            else
            {
                printf("La paraula conté caràcters no permesos!\n");
                m_result = false;
            }
        }
        else
        {
            printf("La paraula excedeix la longitud màxima permesa...\n");
            m_result = false;
        }
    }

    return m_result;
}

void eliminar(cjt_paraules_t *c, char p[])
{

}

bool pertany(cjt_paraules_t *c, char p[])
{
    int i = 0;
    bool m_check = true, m_result = false;

    while (m_check == true && i < c->n_el)
    {

        if (strcmp(p, c->paraules[i]) == 0)
        {
            m_check = true;
            m_result = true;
        }

        i++;
    }

    return m_result;
}

bool ple(cjt_paraules_t *c)
{
    bool m_ple = false;

    if (c->n_el > 99)
    {
        printf("El conjunt está ple!\n");
        m_ple = true;
    }

    return m_ple;
}

bool buit(cjt_paraules_t *c)
{
    if (c->n_el == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int n_elems(cjt_paraules_t *c)
{

}

void mostrar(cjt_paraules_t *c)
{
    int i;

    if (c->n_el != 0)
    {
        printf("Hi han %d paraules al conjunt!\n", c->n_el);
        
        for (i = 0; i < c->n_el; i++)
        {
            printf("%s, ", c->paraules[i]);
        }

        printf("\n");
    }
}

