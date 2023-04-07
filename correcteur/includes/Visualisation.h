/*
    Antoine Bastos
    Yazan Aljannoud
    Création: 18/02/2022
    Modification: 18/03/2022
*/

#ifndef CORRECTEUR_ORTHOGRAPHIQUE_VISUALISEUR
#define CORRECTEUR_ORTHOGRAPHIQUE_VISUALISEUR

#include "ATR.h"

#define CHEMIN_SORTIE "./data/graphe"

/**
 * Ecrit dans un fichier la représentation
 * d'un ATR formaté pour le langage dot
 * @param atr
 * @param path
 */
void atr_vers_dot(ATR atr, const char * path);

#endif
