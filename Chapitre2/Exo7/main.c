#include "insaio.h"
#include <stdio.h>

#define MAX_SIZE 50

int main() {
    int tableau_1[30][30], tableau_2[900];
    int nb_lignes, nb_colonnes;

    AFFICHER("Combien de ligne et de colonnes souhaitez vous utiliser (max 30) ? ");
    SAISIR(nb_lignes, nb_colonnes);

    AFFICHER("Saisir les valeurs : ");
    for (int i = 0; i < nb_lignes; ++i) {
        for (int j = 0; j < nb_colonnes; ++j) {
            SAISIR(tableau_1[i][j]);
        }
    }

    for (int i = 0; i < nb_lignes; ++i) {
        for (int j = 0; j < nb_colonnes; ++j) {
            tableau_2[i * 4 + j] = tableau_1[i][j];
        }
    }

    AFFICHER("Affichage du tableau 2 :");
    for (int i = 0; i < nb_lignes * nb_colonnes; ++i) {
        AFFICHER(" ", tableau_2[i]);
    }

    return 0;
}
