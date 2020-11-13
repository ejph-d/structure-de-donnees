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
    c->solde = c->solde + s;
    return c;
}

COMPTE debiter(COMPTE c, int s)
{
    c->solde = c->solde - s;
    return c;
}

COMPTE cloturer(COMPTE c)
{
    if (c->solde == 0 && c->estCloture == FALSE)
    {
        c->estCloture = TRUE;
    }
    return c;
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