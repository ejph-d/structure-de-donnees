#include "compte.c"

int main()
{
    COMPTE c = malloc(sizeof(t_compte));
    char *d = malloc(sizeof(char *));
    int success;
    int credit = 0;
    int debit = 0;
    int temp;
    char *username = "Jean Patrick";

    if (c == NULL)
    {
        printf("Allocation impossible \n");
        exit(EXIT_FAILURE);
    }

    success = 0;
    c = creer(c, username);
    if (titulaire(c) == username)
    {
        success++;
        if (solde(c) == 0)
        {
            success++;
            if (estCloture(c) == FALSE)
                success++;
        }
    }
    if (success != 3)
    {
        printf("Implémentation incorrecte du constructeur creer(c,*p).\n");
        printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
        exit(EXIT_FAILURE);
    }
    success = 0;
    temp = c->solde;
    creer(c, username);
    crediter(c, credit);
    if (c->solde == temp + credit)
        success++;

    if (success != 1)
    {
        printf("Implémentation incorrecte du constructeur crediter(c,s).\n");
        printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
        exit(EXIT_FAILURE);
    }

    success = 0;
    temp = c->solde;
    creer(c, username);
    debiter(c, debit);
    if (c->solde == temp - credit)
        success++;

    if (success != 1)
    {
        printf("Implémentation incorrecte du constructeur debiter(c,s).\n");
        printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
        exit(EXIT_FAILURE);
    }
    success = 0;
    creer(c, username);
    cloturer(c);
    if (estCloture(c) == TRUE)
    {
        success++;
        if (solde(c) == 0)
        {
            success++;
        }
    }
    if (success != 2)
    {
        printf("Implémentation incorrecte du constructeur cloturer(c).\n");
        printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
        exit(EXIT_FAILURE);
    }
    success = 0;
    creer(c, username);
    d = titulaire(c);
    if (d == username)
        success++;
    if (success != 1)
    {
        printf("Implémentation incorrecte du constructeur titulaire(c).\n");
        printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
        exit(EXIT_FAILURE);
    }

    success = 0;
    creer(c, username);
    solde(c);
    if (solde(c) == c->solde)
        success++;

    if (success != 1)
    {
        printf("Implémentation incorrecte du constructeur solde(c).\n");
        printf("Interruption de la vérification: revoir l'implémentation du type abstrait \n");
        exit(EXIT_FAILURE);
    }

    printf("L'implementation du type abstrait est vérifiée.\n");
    printf("Fin normale de la vérification de l'implémentation du type abstrait.\n",);
    return (EXIT_SUCCESS);
}