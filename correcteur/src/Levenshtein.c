/*
    Antoine Bastos
    Yazan Aljannoud
    Création: 18/02/2022
    Modification: 18/03/2022
*/

#include <stdlib.h>
#include <string.h>

#include "../includes/Levenshtein.h"

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

int levenshtein(const char *s1, const char *s2){
    unsigned int len1, len2;
    unsigned int i, j;
    unsigned int **mat;

    len1 = strlen(s1);
    len2 = strlen(s2);

    mat = (unsigned int **) malloc(sizeof(int*) * (len2 + 1));
    for(j = 0; j <= len2; j++)
        mat[j] = (unsigned int *) malloc(sizeof(int) * (len1 + 1));
    mat[0][0] = 0;
    /* init */
    for (i = 1; i <= len2; i++)
        mat[i][0] = mat[i-1][0] + 1;
    for (j = 1; j <= len1; j++)
        mat[0][j] = mat[0][j-1] + 1;
    /* fill */
    for (i = 1; i <= len2; i++)
        for (j = 1; j <= len1; j++)
            mat[i][j] = MIN3(mat[i-1][j] + 1, mat[i][j-1] + 1, mat[i-1][j-1] + (s1[j-1] == s2[i-1] ? 0 : 1));

    return mat[len2][len1];
}
