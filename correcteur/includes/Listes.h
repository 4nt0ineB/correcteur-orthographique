/*
    Antoine Bastos
    Yazan Aljannoud
    Création: 26/02/2022
    Modification: 18/03/2022
*/

#ifndef CORRECTEUR_ORTHOGRAPHIQUE_LISTES_H
#define CORRECTEUR_ORTHOGRAPHIQUE_LISTES_H

typedef struct cellule {
    char * mot;
    struct cellule * suivant;
} Cellule, * Liste;

/**
 * Alloue une cellule de liste chainée de mots
 * @param mot
 * @return un pointeur sur une Cellule
 */
Cellule * liste_allouer_Cellule(char * mot);

/**
 * Insère en tête de liste chainee une nouveau mot
 * @param L
 * @param mot
 * @return 1 si le mot à bien été ajouté
 */
int liste_inserer_en_tete(Liste * L, char * mot);

/**
 * Désalloue une liste chainee
 * @param L
 */
void liste_liberer_Liste(Liste * L);

#endif
