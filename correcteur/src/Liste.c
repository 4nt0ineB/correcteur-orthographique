/*
    Antoine Bastos
    Yazan Aljannoud
    Création: 26/02/2022
    Modification: 18/03/2022
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../includes/Listes.h"

Cellule * liste_allouer_Cellule(char * mot){
    Liste l;
    l = (Liste) malloc(sizeof(Cellule));
    if(l){
        l->mot = (char *) calloc(strlen(mot)+1, sizeof(char));
        if(!l->mot)
            return NULL;
        strcpy(l->mot, mot);
        l->suivant = NULL;
    }
    return l;
}

int liste_inserer_en_tete(Liste * L, char * mot){
    Cellule * cel;
    cel = liste_allouer_Cellule(mot);
    if(!cel) return 0;
    cel->suivant = *L;
    *L = cel;
    return 1;
}

void liste_liberer_Liste(Liste * L){
    if(!*L) return;
    liste_liberer_Liste(&(*L)->suivant);
    free(*L);
    *L = NULL;
}
