/*
    Antoine Bastos
    Yazan Aljannoud
    Création: 18/02/2022
    Modification: 18/03/2022
*/

#ifndef CORRECTEUR_ORTHOGRAPHIQUE_PARSER
#define CORRECTEUR_ORTHOGRAPHIQUE_PARSER

#include "ATR.h"
#include "Listes.h"

/**
 * Remplie un arbre ternaire de recherche (ATR)
 * avec les mots d'un fichier
 * @param A l'arbre ternaire
 * @param chemin chemin vers le fichier
 * @return 1 si le fichier à pu être lu, 0 sinon
 */
int interface_charger_dico(const char *chemin, ATR *A);

/**
 * Remplit une liste chainées des mots mal orthographies pour un fichier et un
 * dictionnaire dans une structure d'arbre ternaire
 * @param f_a_corriger
 * @param dico
 * @param erreurs
 * @return
 */
int interface_chercher_erreurs(const char * f_a_corriger, ATR dico, Liste * erreurs);


/**
 * Affiche la liste chainee de mots de la fin de liste vers la tête
 * @param L
 */
void interface_afficher_Liste(Liste L, int align);

/**
 * Sortie formatée de la liste
 * des corrections du mot respectivement à ce qui
 * est demandé dans le sujet
 * @param A
 * @param l
 */
void interface_afficher_corrections(ATR A, Liste l);

#endif
