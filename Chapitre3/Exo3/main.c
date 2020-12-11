#include "insaio.h"
#include <stdio.h>

#define MAX_SIZE 30

int ask_notes_count();

void saisie_notes(float tab[], int size);

void affichage_notes(float tab[], int size);

void affichage_tab_stats(float tab[], int size);

void make_quartiles(int quartiles[], float tab[], int size);

int ask_notes_count() {
    int size = 0;
    do {
        AFFICHER("Nombre de notes ? ");
        SAISIR(size);
    } while (size < 1 || size > MAX_SIZE);
    return size;
}

void saisie_notes(float tab[], int size) {
    AFFICHER("Saisir les notes : ");
    for (int i = 0; i < size; ++i) {
        SAISIR(tab[i]);
    }
}

void affichage_notes(float tab[], int size) {
    AFFICHER("Récapitulatif des notes : \n");
    for (int i = 0; i < size; ++i) {
        AFFICHER("Note n°", i, " : ", tab[i], "\n");
    }
}

void affichage_tab_stats(float tab[], int size) {
    float min = 3.40282e+038f; // Valeur max pour un float
    float max = 0; // La note ne peux pas être inferieur à 0
    float somme = 0, moyenne;
    for (int i = 0; i < size; ++i) {
        if (tab[i] > max) {
            max = tab[i];
        }

        if (tab[i] < min) {
            min = tab[i];
        }
        somme += tab[i];
    }
    moyenne = somme / size;
    AFFICHER("\nNote min : ", min, "\nNote max : ", max, "\nMoyenne : ", moyenne);
}

void make_quartiles(int quartiles[], float tab[], int size) {
    for (int i = 0; i < size; ++i) {
        if (tab[i] >= 0 && tab[i] < 8) {
            quartiles[0] += 1;
        } else if (tab[i] >= 8 && tab[i] < 10) {
            quartiles[1] += 1;
        } else if (tab[i] >= 10 && tab[i] < 12) {
            quartiles[2] += 1;
        } else if (tab[i] >= 12 && tab[i] <= 20) {
            quartiles[3] += 1;
        }
    }
}


int main() {
    float tableau[MAX_SIZE];
    int size = ask_notes_count();
    int quartiles[4] = {0, 0, 0, 0};

    saisie_notes(tableau, size);
    affichage_notes(tableau, size);

    affichage_tab_stats(tableau, size);

    make_quartiles(quartiles, tableau, size);

    // On pourrait aussi faire une fonction pour l'affichage des quartiles mais ce n'est pas demandé
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