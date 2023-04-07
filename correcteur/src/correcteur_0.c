/*
    Antoine Bastos
    Yazan Aljannoud
    Création: 26/02/2022
    Modification: 14/03/2022
*/

#include <stdio.h>
#include <ctype.h>
#include <assert.h>
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

    if(interface_chercher_erreurs(argv[1], A, &l) == 0){
        printf("Impossible de lire le fichier %s\n", argv[1]);
        return 0;
    }

    printf("Mot(s) mal orthographié(s) :\n");
    interface_afficher_Liste(l, 1);
    printf("\n");

    /* free */
    atr_liberer_ATR(&A);
    liste_liberer_Liste(&l);
    return 0;
}
