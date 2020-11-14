#include "compte.h"

int creer(COMPTE c, char *p)
{
    
    c->solde = 0;
    c->titulaire = p;
    c->estCloture = FALSE;
    return 1;
}

int crediter(COMPTE c, int s)
{
    if (estCloture(c) == TRUE)
        return 0; /* account is closed */
    else
    {
        c->solde = c->solde + s;
        return 1;
    }
}

int debiter(COMPTE c, int s)
{
    if (estCloture(c) == TRUE)
        return 0; /* account is closed */
    else
    {
        c->solde = c->solde - s;
    }
    return 1;
}

int cloturer(COMPTE c)
{

    if (estCloture(c) == TRUE)
    {
        return 0; /* acount is already close */
    }

    else if (solde(c) == 0)
    {
        c->estCloture = TRUE;
        return 1;
    }
    else 
    {
        return -1;
    }
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
    printf("solde:      %d\ntitulaire:  %s\ncloture:    %d\n", c->solde, c->titulaire, c->estCloture);
    printf("----------------------------------------------------\n");
}