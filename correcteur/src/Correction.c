/*
    Antoine Bastos
    Yazan Aljannoud
    Création: 18/02/2022
    Modification: 18/03/2022
*/

#include <assert.h>

#include "../includes/Correction.h"
#include "../includes/Levenshtein.h"
#include "../includes/Constantes.h"

static void correction_corriger_(ATR dico, char buffer[], int i, int * dmin, const char * mot, Liste * corrections){
    int d;
    if(!dico)
        return;
    correction_corriger_(dico->gauche, buffer, i, dmin, mot, corrections);
    buffer[i] = dico->c;
    if (dico->c == STOP_CHAR) {
        /* On a un mot */
        d = levenshtein(mot, buffer);
        if (d <= *dmin) {
            if (d < *dmin) {
                *dmin = d;
                liste_liberer_Liste(corrections);
            }
            liste_inserer_en_tete(corrections, buffer);
        }
    } else
        correction_corriger_(dico->fils, buffer, i + 1, dmin, mot, corrections);
    correction_corriger_(dico->droit, buffer, i, dmin, mot, corrections);
}

void correction_corriger(ATR dico, const char * mot, Liste * corrections){
    char buffer[MAX_LETTRES];
    int x;
    int * dmin;
    assert(dico);
    x = __INT_MAX__;
    dmin = &x;
    correction_corriger_(dico, buffer, 0, dmin, mot, corrections);
}
