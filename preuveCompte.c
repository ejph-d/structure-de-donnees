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
    /* on alloue de la mémoire à chaque structure, la taille de la mémoire allouée est la taille de la mémoire de la strucure */
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

    char *tabUsername[] = {};
    COMPTE tabCompte[NBCOMPTEMAX] = {c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10};

    /* calcul du nombre de compte créé. */
    int nbCompte = sizeof(tabUsername) / sizeof(tabUsername[0]);

    /* test pour voir si l'allocation de la mémoire est OK*/
    for (int i = 0; i < NBCOMPTEMAX; i++)
    {
        if (tabCompte[i] == NULL)
        {
            printf("Allocation impossible \n");
            exit(EXIT_FAILURE);
        }
    }



    /* cration de la fonction add_name qui test un titulaire pour verifier qu'iel n'a pas déjà un compte. Puis l'ajoute dans notre tabeau d'username*/
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
            tabCompte[nbCompte - 1] = accountNumber;
        }
    }
    /* Ajout de compte (la fonction add_name creer un compte en verifiant que le titulaire n'a pas deja un compte) */
    add_name(c0, "Étienne DUVERNE");
    add_name(c1, "Castorama");
    add_name(c2, "Fabrice");
    add_name(c3, "Francis");
    add_name(c4, "castafior");



    /* on commence les tests */

    /* on creer un compte */
    char *username = tabUsername[0]; /* tout les tests se feront avec le premier compte créé.*/
    int success = 0;
    success += test_creer(c0, username);

    if (success != 1)
    {
        printf("erreur 1\n");
        exit(EXIT_FAILURE);
    }

    /* on creer un compte puis on le credite */
    success = 0;
    success += test_creer(c0, username);
    success += test_crediter(c0, 100);

    if (success != 2)
    {
        printf("erreur 2\n");
        exit(EXIT_FAILURE);
    }

    /* on creer un compte puis on le debite */
    success = 0;
    success += test_creer(c0, username);
    success += test_debiter(c0, 100);

    if (success != 2)
    {
        printf("erreur 3\n");
        exit(EXIT_FAILURE);
    }

    /* on creer un compte puis on le cloture */
    success = 0;
    success += test_creer(c0, username);
    success += test_cloturer(c0);

    if (success != 2)
    {
        printf("erreur 4\n");
        exit(EXIT_FAILURE);
    }

    /* on creer un compte puis on verifie son solde */
    success = 0;
    success += test_creer(c0, username);
    success += test_solde(c0);
    if (success != 2)
    {
        printf("erreur 5\n");
        exit(EXIT_FAILURE);
    }

    /* on creer un compte puis on verifie son titulaire */
    success = 0;
    success += test_creer(c0, username);
    success += test_titulaire(c0, username);
    if (success != 2)
    {
        printf("erreur 6\n");
        exit(EXIT_FAILURE);
    }

    /* on creer un compte puis on verifie son état */
    success = 0;
    success += test_creer(c0, username);
    success += test_estCloture(c0);
    if (success != 2)
    {
        printf("erreur 7\n");
        exit(EXIT_FAILURE);
    }

    /* si toutes les conditions ont été respectées avant, le programme affiche ceci, c'est la validation de l'imprementation*/
    printf("L'implementation du type abstrait est vérifiée.\n");
    printf("Fin normale de la vérification de l'implémentation du type abstrait.\n");

    /* on libère la mémoire à la fin du programme*/
    for (int i = 0; i < nbCompte; i++)
    {
        free(tabCompte[i]);
    }

    free(c);

    return (EXIT_SUCCESS);
}