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

    // Question 1 :
    int min = tableau[0], max = tableau[0];

    for (int i = 0; i < taille; ++i) {
        if (tableau[i] < min)
        {
            min = tableau[i];
        }
        if (tableau[i] > max)
        {
            max = tableau[i];
        }
    }
    AFFICHER("Max : ", max, "\nMin : ", min, "\n\n");


    //Question 2
    AFFICHER("Tableau inversé : ");
    int tableau_inv[MAX_SIZE];
    for (int i = 0; i < taille; ++i) {
        tableau_inv[i] = tableau[taille-i-1];
        AFFICHER(tableau_inv[i]);
    }

    //Question 3
    int valeur, found = 0;
    AFFICHER("\n\nEntrez une valeur à rechercher : ");
    SAISIR(valeur);

    for (int i = 0; i < taille; ++i) {
        if (tableau[i] == valeur)
        {
            AFFICHER("Trouvé à l'index ", i);
            found = 1;
        }
    }

    if (!found)
    {
        AFFICHER("Valeur non trouvé");
    }

    return 0;
}
