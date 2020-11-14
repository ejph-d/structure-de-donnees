#include "compte.c"

void modif_account(COMPTE c, int solde, BOOLEAN cloture)
{
    c->solde = solde;
    c->estCloture = cloture;
}

void reset_account(COMPTE c)
{
    c->solde = 0;
    c->estCloture = FALSE;
}

int test_creer(COMPTE c, char *username)
{
    if (creer(c, username) != 1)
    {
        printf("Implémentation incorrecte du constructeur creer(c,*p).\n");
        printf("Interruption de la vérification: revoir l'implémentation du type abstrait.\n");
        return 0;
    }
    return 1;
}

int test_crediter(COMPTE c, int s)
{

    if (crediter(c, s) != 1)
    {
        printf("Implémentation incorrecte du constructeur crediter(c,s).\n");
        printf("Interruption de la vérification: revoir l'implémentation du type abstrait.\n");
        return 0;
    }
    return 1;
}

int test_debiter(COMPTE c, int s)
{
    if (debiter(c, s) != 1)
    {
        printf("Implémentation incorrecte du constructeur debiter(c,s).\n");
        printf("Interruption de la vérification: revoir l'implémentation du type abstrait.\n");
        return 0;
    }
    return 1;
}

int test_cloturer(COMPTE c)
{
    if (cloturer(c) != 1)
    {
        printf("Implémentation incorrecte du constructeur cloturer(c).\n");
        printf("Interruption de la vérification: revoir l'implémentation du type abstrait.\n");
        return 0;
    }
    return 1;
}

int test_titulaire(COMPTE c, char *username)
{
    if (titulaire(c) != username)
    {
        printf("Implémentation incorrecte du constructeur titulaire(c).\n");
        printf("Interruption de la vérification: revoir l'implémentation du type abstrait.\n");
        return 0;
    }
    return 1;
}

int test_solde(COMPTE c)
{
    if (solde(c) != c->solde)

    {
        printf("Implémentation incorrecte du constructeur solde(c).\n");
        printf("Interruption de la vérification: revoir l'implémentation du type abstrait.\n");
        return 0;
    }
    return 1;
}

int test_estCloture(COMPTE c)
{
    if (estCloture(c) != c->estCloture)
    {

        printf("Implémentation incorrecte du constructeur estCloture(c).\n");
        printf("Interruption de la vérification: revoir l'implémentation du type abstrait.\n");
        return 0;
    }
    return 1;
}

int main()
{
    COMPTE c = malloc(sizeof(t_compte));
    COMPTE c1 = malloc(sizeof(t_compte));
    char *username = "Étienne DUVERNE";

    if (c == NULL || c1 == NULL)
    {
        printf("Allocation impossible \n");
        exit(EXIT_FAILURE);
    }

    /* on commence les tests */

    /* on creer un compte */
    int success = 0;
    success += test_creer(c, username);

    if (success != 1)
    {
        printf("erreur 1\n");
        exit(EXIT_FAILURE);
    }

    /* on creer un compte puis on le credite */
    success = 0;
    success += test_creer(c, username);
    success += test_crediter(c, 100);

    if (success != 2)
    {
        printf("erreur 2\n");
        exit(EXIT_FAILURE);
    }

    /* on creer un compte puis on le debite */
    success = 0;
    success += test_creer(c, username);
    success += test_debiter(c, 100);

    if (success != 2)
    {
        printf("erreur 3\n");
        exit(EXIT_FAILURE);
    }

    /* on creer un compte puis on le cloture */
    success = 0;
    success += test_creer(c, username);
    success += test_cloturer(c);

    if (success != 2)
    {
        printf("erreur 4\n");
        exit(EXIT_FAILURE);
    }

    /* on creer un compte puis on verifie son solde */
    success = 0;
    success += test_creer(c, username);
    success += test_solde(c);
    if (success != 2)
    {
        printf("erreur 5\n");
        exit(EXIT_FAILURE);
    }

    /* on creer un compte puis on verifie son titulaire */
    success = 0;
    success += test_creer(c, username);
    success += test_titulaire(c, username);
    if (success != 2)
    {
        printf("erreur 6\n");
        exit(EXIT_FAILURE);
    }

    /* on creer un compte puis on verifie son état */
    success = 0;
    success += test_creer(c, username);
    success += test_estCloture(c);
    if (success != 2)
    {
        printf("erreur 7\n");
        exit(EXIT_FAILURE);
    }



    printf("L'implementation du type abstrait est vérifiée.\n");
    printf("Fin normale de la vérification de l'implémentation du type abstrait.\n"); */
    free(c);
    free(c1);
    return (EXIT_SUCCESS);
}