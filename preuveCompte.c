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
    COMPTE c0 = malloc(sizeof(t_compte));
    COMPTE c1 = malloc(sizeof(t_compte));
    COMPTE c2 = malloc(sizeof(t_compte));
    COMPTE c3 = malloc(sizeof(t_compte));
    COMPTE c4 = malloc(sizeof(t_compte));
    COMPTE c5 = malloc(sizeof(t_compte));
    COMPTE c6 = malloc(sizeof(t_compte));
    COMPTE c7 = malloc(sizeof(t_compte));
    COMPTE c8 = malloc(sizeof(t_compte));
    COMPTE c9 = malloc(sizeof(t_compte));
    COMPTE c10 = malloc(sizeof(t_compte));

    char *username = "Étienne DUVERNE";
    char *tabUsername[] = {};
    COMPTE tabCompte[NBCOMPTEMAX] = {};
    int nbCompte = sizeof(tabUsername) / sizeof(tabUsername[0]);
    if (c == NULL || c0 == NULL || c1 == NULL || c2 == NULL || c3 == NULL || c4 == NULL || c5 == NULL || c6 == NULL || c7 == NULL || c8 == NULL || c9 == NULL || c10 == NULL)
    {
        printf("Allocation impossible \n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < nbCompte; i++)
    {
        test_creer(tabCompte[i], tabUsername[i]);
    }
    void add_name(COMPTE accountNumber, char *username)
    {
        BOOLEAN alreadyTaken = FALSE;
        for (int i = 0; i < nbCompte; i++)
        {

            if (username == tabCompte[i]->titulaire)
            {
                printf("username already taken\n");
                alreadyTaken = TRUE;
            }
        }
        if (alreadyTaken == FALSE)
        {
            test_creer(accountNumber, username);
            nbCompte++;
            printf("%d\n", nbCompte);
            tabCompte[nbCompte - 1] = accountNumber;
        }
    }

    add_name(c0, "Etienne DUVERNE");
    add_name(c1, "Castorama");
    add_name(c2, "Fabrice");
    add_name(c3, "Francis");
    add_name(c4, "Castorama");
    
    for (int i = 0; i < nbCompte; i++)
    {
        printf("%d, %d\n", i, nbCompte);
        afficherStruct(tabCompte[i]);
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
    printf("Fin normale de la vérification de l'implémentation du type abstrait.\n");

    for (int i = 0; i < nbCompte; i++)
    {
        free(tabCompte[i]);
    }

    free(c);

    return (EXIT_SUCCESS);
}