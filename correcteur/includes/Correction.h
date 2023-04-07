/*
    Antoine Bastos
    Yazan Aljannoud
    Création: 18/02/2022
    Modification: 18/03/2022
*/

#ifndef CORRECTEUR_ORTHOGRAPHIQUE_CORRECTION
#define CORRECTEUR_ORTHOGRAPHIQUE_CORRECTION

#include "ATR.h"
#include "Listes.h"

/**
 * Renvoie la liste des corrections possibles d'un mot
 * donné pour un dictionnaire donné pour une distance de Levenshtein minimale
 * @param dico
 * @param mot
 * @param corrections
 * @return
 */
void correction_corriger(ATR dico, const char * mot, Liste * corrections);

#endif
