#include "compte.h"

/* création de la fonction creer qui prend pour parametre un pointeur sur la structure compte (c) et le nom d'un titulaire (p) */
int creer(COMPTE c, char *p)
{

    c->solde = 0;
    c->titulaire = p;
    c->estCloture = FALSE;
    return 1;
}

/* permet de crediter un compte existant (c), en ajoutant de l'argent au solde, on passe par la variable (s) */
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

/* permet de crediter un compte existant (c), en retirant de l'argent au solde, on passe par la variable (s) */
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

/* cloturer un compte (attention, ne fonctionne que si le solde est égale à 0 et si le compte n'est pas déjà cloturé) */
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

/* permet d'afficher le nom du titulaire du compte et prend pour paramètre le nom du compte (c) */
char *titulaire(COMPTE c)
{
    return (c->titulaire);
}

/*  retourne la valeur du solde de la structure (c) */
int solde(COMPTE c)
{
    return (c->solde);
}

/* retourne si le compte est cloturé ou non */
BOOLEAN estCloture(COMPTE c)
{
    return (c->estCloture);
}
/* Affiche la structure (c) */
void afficherStruct(COMPTE c)
{
    printf("solde:      %d\ntitulaire:  %s\ncloture:    %d\n", c->solde, c->titulaire, c->estCloture);
    printf("----------------------------------------------------\n");
}