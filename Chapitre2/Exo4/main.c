#include "insaio.h"
#include <stdio.h>

#define MAX_SIZE 50

int main() {
    int tableau[MAX_SIZE], taille = -1, somme = 0;

    while (!(taille <= MAX_SIZE && taille >= 0))
    {
        AFFICHER("Entrer un nombre d'entier à saisir (max 50) : ");
        SAISIR(taille);
    }

    for (int i = 0; i < taille; ++i) {
        SAISIR(tableau[i]);
    }

    for (int i = 0; i < taille; ++i) {
        AFFICHER(tableau[i], " ");
        somme += tableau[i];
    }
    AFFICHER("\nMoyenne : ", somme / (float)taille);


    return 0;
}
