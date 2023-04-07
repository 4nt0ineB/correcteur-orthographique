/*
    Antoine Bastos
    Yazan Aljannoud
    Création: 26/02/2022
    Modification: 18/03/2022
*/

#include <stdio.h>
#include <string.h>

#include "../includes/ATR.h"
#include "../includes/Listes.h"
#include "../includes/Interface.h"
#include "../includes/Visualisation.h"

int main(int argc, char *argv[]){
    ATR A;
    Liste l;

    /* Verification des arguments */
    if(argc <= 2){
        printf("Argument manquants.\n");
        printf("%s [fichier à corriger] [fichier dictionnaire]\n", argv[0]);
        return 0;
    }

    A = NULL;
    l = NULL;

    if(interface_charger_dico(argv[2], &A) == 0){
        printf("Impossible de lire le fichier %s\n", argv[2]);
        return 0;
    }

    /* Fichier .dot */
    if(argc == 4 && strcmp(argv[3], "-a") == 0)
        atr_vers_dot(A, CHEMIN_SORTIE ".dot");

    if(interface_chercher_erreurs(argv[1], A, &l) == 0){
        printf("Impossible de lire le fichier %s\n", argv[1]);
        return 0;
    }

    interface_afficher_corrections(A, l);

    atr_vers_dot(A, CHEMIN_SORTIE ".dot");

    /* free */
    atr_liberer_ATR(&A);
    liste_liberer_Liste(&l);
    return 0;
}
