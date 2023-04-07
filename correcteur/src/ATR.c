/*
    Antoine Bastos
    Yazan Aljannoud
    Création: 26/02/2022
    Modification: 14/03/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include "../includes/ATR.h"
#include "../includes/Constantes.h"

/**
 * Alloue un noeud d'ATR
 * @param c
 * @return un pointeur sur un noeud
 */
static ATR alloue_noeud_ATR(char c){
    ATR A = (ATR) malloc(sizeof(NoeudATR));
    if(A){
        A->c = c;
        A->gauche = A->fils = A->droit = NULL;
    }
    return A;
}

/**
 * Insère une branche partant d'un noeud d'ATR
 * (suite de fils portant les lettres du mot donne)
 * @param A
 */
static int inserer_banche_dans_ATR(ATR * A, const char * word){
    if(!A) return 0;
    if((*A = alloue_noeud_ATR(*word))){
        if(*word)
           return inserer_banche_dans_ATR(&(*A)->fils, word+1);
        return 1;
    }
    return 0;
}

int atr_inserer_dans_ATR(ATR * A, const char * mot){
    char c;
    if(!*A)
        return inserer_banche_dans_ATR(A, mot);
    else{
        c = *mot;
        if(c < (*A)->c)
            return atr_inserer_dans_ATR(&(*A)->gauche, mot);
        else if(c > (*A)->c)
            return atr_inserer_dans_ATR(&(*A)->droit, mot);
        else{
            if(*mot == STOP_CHAR)
                return 1;
            return atr_inserer_dans_ATR(&(*A)->fils, ++mot);
        }
    }
}

void supprimer_dans_ATR(ATR * A, const char * mot){
    if(!*A) return;
    if(*mot == (*A)->c){
        if(*mot == STOP_CHAR){
            ATR tmp = (*A);
            *A = (*A)->droit;
            free(tmp);
            return;
        }
        supprimer_dans_ATR(&(*A)->fils, mot+1);
        if(!(*A)->gauche && !(*A)->droit){
            free(*A);
            *A = NULL;
        }
        return;
    }
    if(*mot > (*A)->c){
        supprimer_dans_ATR(&(*A)->droit, mot);
        return;
    }
    supprimer_dans_ATR(&(*A)->gauche, mot);
    return;
}

int atr_chercher_dans_ATR(ATR A, char *mot){
    if(!A) return 0;
    if(*mot == A->c){
        if(*mot == STOP_CHAR)
            return 1;
        return atr_chercher_dans_ATR(A->fils, mot+1);
    }
    if(*mot > A->c)
        return atr_chercher_dans_ATR(A->droit, mot);
    return atr_chercher_dans_ATR(A->gauche, mot);
}

/**
 * Affiche les mots de l'arbre lexicographiquement
 * @param A
 * @param buffer
 * @param i
 */
static void atr_afficher_ATR_util(ATR A, char buffer[], int i){
    if(A){
        atr_afficher_ATR_util(A->gauche, buffer, i);
        buffer[i] = A->c;
        if(A->c == STOP_CHAR)
            printf("%s\n", buffer);
        else
            atr_afficher_ATR_util(A->fils, buffer, i+1);
        atr_afficher_ATR_util(A->droit, buffer, i);
    }
}

void atr_afficher_ATR(ATR A){
    char buffer[MAX_LETTRES];
    atr_afficher_ATR_util(A, buffer, 0);
}

void atr_liberer_ATR(ATR * A){
    if(!*A)
        return;
    atr_liberer_ATR(&(*A)->gauche);
    atr_liberer_ATR(&(*A)->droit);
    atr_liberer_ATR(&(*A)->fils);
    free(*A);
    *A = NULL;
}
