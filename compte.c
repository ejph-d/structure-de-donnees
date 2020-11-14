#include "compte.h"

COMPTE creer(COMPTE c, char *p)
{
    c->solde = 0;
    c->titulaire = p;
    c->estCloture = FALSE;
    return c;
}

COMPTE crediter(COMPTE c, int s)
{
    if (estCloture(c))
    {
        printf("IMPOSSIBLE CHACAL");
    }
    else
    {
        c->solde = c->solde + s;
    }

    return c;
}

COMPTE debiter(COMPTE c, int s)
{
    c->solde = c->solde - s;
    return c;
}

int cloturer(COMPTE c)
{
    int success;

    if (estCloture(c))
    {
        return 0;
    }

    else if (solde(c) == 0)
    {
        return 1;
    }

    return -1;
}

char *titulaire(COMPTE c)
{
    return (c->titulaire);
}

int solde(COMPTE c)
{
    return (c->solde);
}

BOOLEAN estCloture(COMPTE c)
{
    return (c->estCloture);
}

void afficherStruct(COMPTE c)
{
    printf("----------------------------------------------------\n");
    printf("solde:      %d\ntitulaire:  %s\ncloture:    %d\n", c->solde, c->titulaire, c->estCloture);
    printf("----------------------------------------------------\n");
}