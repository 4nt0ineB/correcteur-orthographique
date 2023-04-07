/*
    Antoine Bastos
    Yazan Aljannoud
    Création: 26/02/2022
    Modification: 18/03/2022
*/

#ifndef CORRECTEUR_ORTHOGRAPHIQUE_ATR_H
#define CORRECTEUR_ORTHOGRAPHIQUE_ATR_H

typedef struct noeud_atr{
    char c;
    struct noeud_atr * gauche, *fils, *droit;
} NoeudATR, * ATR;

/**
 * Libère un ATR
 * @param A
 */
void atr_liberer_ATR(ATR * A);

/**
 * Insere un mot dans un ATR
 * @param A
 * @param mot
 * @return
 */
int atr_inserer_dans_ATR(ATR * A, const char * mot);

/**
 * Supprime un mot d'un ATR
 * @param A
 * @param mot
 */
int atr_chercher_dans_ATR(ATR A, char *mot);

/**
 * Cherche un mot dans l'arbre lexicographique ATR
 *
 * @param A
 * @param mot
 * @return 1 si present dans l'ATR
 */
void atr_supprimer_dans_ATR(ATR * A, const char * mot);

/**
 * Affiche les mots de l'arbre lexicographiquement
 * @param A
 */
void atr_afficher_ATR(ATR A);

#endif
