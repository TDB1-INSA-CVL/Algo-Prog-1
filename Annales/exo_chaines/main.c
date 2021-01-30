/*
 * 
 * 
 * /!\ On ne peut pas tester le programme avec les valeurs donné dans la consigne car les chaines ne sont pas de la meme longeur (else qu'il ne faut pas remplir)
 * 
 * 
 * 
 */


#include "insaio.h"
#include <string.h>

#define NB_OCC_MAX 100
#define TAILLE_CHAINE_MAX 100

/* La fonction suivante retourne le nombre d'occurrence(s) d'une chaîne B dans
une chaîne A, autrement dit, le nombre de fois où B apparaît dans A. Elle
remplit un tableau d'entiers avec les indices (les positions) des occurrences
de B dans A (plus précisément, la position du premier caractère de chaque
occurrence de B dans A). On supposera que le tableau d'entier est suffisamment
grand. Exemple :
int nb_occ;
int pos[100];
nb_occ = occurrences_chaine("Bernadette, elle est très chouette", "ette", pos);
nb_occ vaut 2, pos[0] vaut 6 et pos[1] vaut 30 */
int occurrences_chaine(char a[], char b[], int pos[]) {
    /* i sera utilisé pour parcourir a */
    /* j sera utilisé pour parcourir b */
    int i, j;
    int nbocc;
    i = 0;
    nbocc = 0;
    /* Tant que la fin de a n'est pas atteinte */
    while (a[i] != '\0') {
        /* Tant que le premier caractère de b n'est pas rencontré
        (et que la fin de a n'est pas atteinte) */
        while (a[i] != b[0])
            i++;

        if (a[i] != '\0') {
            /* Le premier caractère de b a été trouvé */
            /* On parcourt b avec l'indice j */
            /* On parcourt a avec l'indice i+j */
            j = 1;
            while (a[i + j] != '\0' && b[j] != '\0' && a[i + j] == b[j])
                j++;
            if (b[j] == '\0') {
                /* Une occurence a été trouvée. On place son indice de début dans
                le tableau pos */
                pos[nbocc] = i;
                nbocc++;
                /* Dans a, on avance jusqu'à la fin de l'occurence */
                i = i + j;
            }
            else
                i++;
        }
    }
    return nbocc;
}

/* La fonction suivante recopie in dans out, en remplaçant chaque occurrence
 de s par r */
void remplace_occurrences_chaine(char in[], char s[], char out[], char r[]) {
    int n;
    int pos[NB_OCC_MAX];
    n = occurrences_chaine(in, s, pos);
    strcpy(out, in);
    if (n > 0) {
        if (strlen(s) == strlen(r)) {
            /* La chaîne à rechercher et la chaîne de remplacement
            ont la même longueur, c'est facile :) */
            int i, occ, pos_depart_occ;
            for (occ = 0; occ < n; occ++) {
                /* On remplace les caractères de out par ceux de r */
                pos_depart_occ = pos[occ];
                for (i = 0; i < strlen(s); i++)
                    out[pos_depart_occ + i] = r[i];
            }
        } else {
            /* Cas plus difficile, considérez qu'il est traité dans ce bloc */
            /* N'ECRIVEZ RIEN ICI */
            /* .......... */
        }
    }
}

int main() {
    char out[TAILLE_CHAINE_MAX];
    remplace_occurrences_chaine("Les amis de mes amis sont des gens bien",
                                "amis", out, "ennemis");
    printf("%s\n", out);
    /* Affiche "Les ennemis de mes ennemis sont des gens bien" */
    return 0;
}
