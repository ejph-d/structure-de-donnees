#ifndef COMPTE__H__
#define COMPTE__H__
#include <stdio.h>
#include <stdlib.h>
#define FALSE 0      /* defini le mot clé FALSE sur 0 */
#define TRUE 1       /* defini le mot clé TRUE sur 1 */
typedef int BOOLEAN; /* defini le type BOOLEEN */

typedef struct s_compte /* type concret pour implémenter le type abstrait des comptes */
{
    int solde;
    char *titulaire;
    BOOLEAN estCloture;

} t_compte;

typedef t_compte *COMPTE;

/* création de la fonction creer qui prend pour parametre un nom de compte (c) et le nom d'un titulaire (p) */
int creer(COMPTE c, char *p);

/* permet de crediter un compte existant (c), en ajoutant de l'argent au solde, on passe par la variable (s) */
int crediter(COMPTE c, int s);

/* permet de crediter un compte existant (c), en retirant de l'argent au solde, on passe par la variable (s) */
int debiter(COMPTE c, int s);

/* cloturer un compte (c) (attention, ne fonctionne que si le solde est égale à 0 et si le compte n'est pas déjà cloturé) */
int cloturer(COMPTE c);

/* permet d'afficher le nom du titulaire du compte et prend pour paramètre le nom du compte (c) */
char *titulaire(COMPTE c);

/*  retourne le solde du compte (c) */
int solde(COMPTE c);

/* retourne si le compte est cloturé ou non */
BOOLEAN estCloture(COMPTE c);



#endif /* COMPTE__H__ */