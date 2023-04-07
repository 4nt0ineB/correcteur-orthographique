/*
    Antoine Bastos
    Yazan Aljannoud
    Création: 18/02/2022
    Modification: 18/03/2022
*/

#include <stdio.h>
#include <ctype.h>
#include <assert.h>

#include "../includes/Interface.h"
#include "../includes/ATR.h"
#include "../includes/Listes.h"
#include "../includes/Constantes.h"
#include "../includes/Correction.h"

int interface_charger_dico(const char *chemin, ATR *A){
    FILE * fichier;
    char buffer[MAX_LETTRES];
    assert(chemin);
    fichier = fopen(chemin, "r");
    if(!fichier)
        return 0;
    while(fscanf(fichier, "%s", buffer) == 1)
        atr_inserer_dans_ATR(A, buffer);
    fclose(fichier);
    return 1;
}

int interface_chercher_erreurs(const char * f_a_corriger, ATR dico, Liste * erreurs){
    FILE * fichier;
    char buff[MAX_LETTRES];
    char c;
    int i;
    assert(f_a_corriger);
    fichier = fopen(f_a_corriger, "r");
    if(!fichier) return 0;
    i = 0;
    while((c = getc(fichier)) != EOF){
        if(i == MAX_LETTRES)
            return -1;
        c = tolower(c);
        if(c >= 'a' && c <= 'z') {
            buff[i] = c;
            i++;
        }else{
            buff[i] = '\0';
            i = 0;
            if(c == '\n')
                continue;
            if(!atr_chercher_dans_ATR(dico, buff))
                liste_inserer_en_tete(erreurs, buff);
        }
    }
    return 1;
}

void interface_afficher_Liste(Liste L, int align){
    if(!L) return;
    interface_afficher_Liste(L->suivant, align);
    if(L->suivant)
        printf("%s", align ? "\n" : ", ");
    printf("%s", L->mot);
}

void interface_afficher_corrections(ATR A, Liste l){
    Liste corrections;
    if(!l)
        return;
    corrections = NULL;
    interface_afficher_corrections(A, l->suivant);
    printf("Mot mal orthographié : %s\n", l->mot);
    printf("Proposition(s) : ");
    correction_corriger(A, l->mot, &corrections);
    interface_afficher_Liste(corrections, 0);
    printf("\n");
}
