#include "insaio.h"
#include <stdio.h>

#define MAX_SIZE 30

int main() {
    // Question 1 :
    float tableau[MAX_SIZE], size;

    do {
        AFFICHER("Nombre de notes ? ");
        SAISIR(size);
    } while (size < 1 || size > MAX_SIZE);

    // Question 2
    AFFICHER("Saisir les notes : ");
    for (int i = 0; i < size; ++i) {
        SAISIR(tableau[i]);
    }

    // Question 3
    AFFICHER("Récapitulatif des notes : \n");
    for (int i = 0; i < size; ++i) {
        AFFICHER("Note n°", i, " : ", tableau[i], "\n");
    }

    // Question 4
    float min = 3.40282e+038f; // Valeur max pour un float
    float max = 0; // La note ne peux pas être inferieur à 0
    float somme = 0, moyenne;
    for (int i = 0; i < size; ++i) {
        if (tableau[i] > max) {
            max = tableau[i];
        }

        if (tableau[i] < min) {
            min = tableau[i];
        }
        somme += tableau[i];
    }
    moyenne = somme / size;
    AFFICHER("\nNote min : ", min, "\nNote max : ", max, "\nMoyenne : ", moyenne);

    // Question 5
    int quartiles[4] = {0, 0, 0, 0};
    for (int i = 0; i < size; ++i) {
        if (tableau[i] >= 0 && tableau[i] < 8)
        {
            quartiles[0] += 1;
        }
        else if (tableau[i] >= 8 && tableau[i] < 10)
        {
            quartiles[1] += 1;
        }
        else if (tableau[i] >= 10 && tableau[i] < 12)
        {
            quartiles[2] += 1;
        }
        else if (tableau[i] >= 12 && tableau[i] <= 20)
        {
            quartiles[3] += 1;
        }
    }

    // Question 6
    AFFICHER("\n0-8   : ");
    for (int i = 0; i < quartiles[0]; ++i) {
        AFFICHER("*");
    }

    AFFICHER("\n8-10  : ");
    for (int i = 0; i < quartiles[1]; ++i) {
        AFFICHER("*");
    }

    AFFICHER("\n10-12 : ");
    for (int i = 0; i < quartiles[2]; ++i) {
        AFFICHER("*");
    }

    AFFICHER("\n12-20 : ");
    for (int i = 0; i < quartiles[3]; ++i) {
        AFFICHER("*");
    }

    return 0;
}
