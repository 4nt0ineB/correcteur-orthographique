/*
    Antoine Bastos
    Yazan Aljannoud
    Création: 18/02/2022
    Modification: 18/03/2022
*/

#include <stdio.h>
#include "../includes/Visualisation.h"

static void visualisation_ecrire(ATR atr, FILE *file){
    char c;

    if(!atr) return;
    c = atr->c == '\0' ? '0' : atr->c;
    fprintf(file, "  n%p [label=\"%c\"]\n", (void *) &*atr, c);
    if(atr->gauche){
        fprintf(file, "  n%p:w -> n%p:c [color=\"#ab2222\"]\n", (void *) &*atr, (void *) atr->gauche);
        visualisation_ecrire(atr->gauche, file);
    }
    if(atr->fils){
        fprintf(file, "  n%p:s -> n%p:c  \n", (void *) &*atr, (void *) atr->fils);
        visualisation_ecrire(atr->fils, file);
    }
    if(atr->droit){
        fprintf(file, "  n%p:e -> n%p:c [color=\"#2257ab\"]\n", (void *) &*atr, (void *) atr->droit);
        visualisation_ecrire(atr->droit, file);
    }
}

void atr_vers_dot(ATR atr, const char * path){
    FILE *file = fopen(path, "w");
    fprintf(file, "digraph arbre {\n"
                  "graph [ splines=true]\n"
                  "  node [shape=circle,height=.1]\n"
                  "  \n\n");
    visualisation_ecrire(atr, file);
    fprintf(file, "\n}");
}
