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
        printf("Le compte a bien été cloturé.\n");
    }
    else if (c->estCloture == TRUE)
    {
        printf("Le compte est déjà cloturé.\n");
    }
    else if (c->solde != 0)
    {
        printf("Le compte n'est pas cloturable car il n'est pas vide.\n");
    }
    else
    {
        printf("Le compte n'a pas pu être cloturé pour une raison inconnue.\n");
    }
    return c;
}

COMPTE titulaire(COMPTE c)
{
    return *titulaire;
}

COMPTE solde(COMPTE c)
{
    return solde;
}

BOOLEAN estCloture(COMPTE c)
{
     return estCloture;
}
void afficherStruct(COMPTE c)
{
    printf("----------------------------------------------------\n");
    printf("solde:      %d\ntitulaire:  %s\ncloture:    %d\n", c->solde, c->titulaire, c->estCloture);
}

int main()
{
    COMPTE c = malloc(sizeof(t_compte));
    creer(c, "Jaqueline Delasouche");
    crediter(c, 100);
    debiter(c, 25);
    /* cloturer(c); */
    titulaire(c);
    solde(c);
    estCloture(c);
    afficherStruct(c);

    return 0;
}