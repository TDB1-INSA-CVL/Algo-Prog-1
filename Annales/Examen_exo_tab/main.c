#include "insaio.h"
#include <string.h>

#define TAILLE 35

int fonctionMystere(int tab[], int taille) {
    int i;
    for (i = 0; i < taille - 1; i++) {
        if (tab[i] < tab[i + 1])
            return 0;
    }
    return 1;
}

void afficherTableau(int tab[], int size) {
    int k;
    for (k = 0; k < size; k++)
    {
        AFFICHER(tab[k], " ");

        // Methode second semestre
        // printf("%i ", tab[k]);
    }
}

void question3(int tab[], int size) {
    int valeur_saisie;

    for (int i = 0; i < size; ++i) {
        valeur_saisie = -1;
        do {
            SAISIR(valeur_saisie);
        } while (valeur_saisie < 0 || valeur_saisie > 20);
        tab[i] = valeur_saisie;
    }
}

int question4(int tab[], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (tab[i] == tab[j])
                return 1;
        }
    }
    return 0;
}

int main() {
    int tab1[] = {1, 2, 3, 4}, tab2[] = {4, 3, 2, 1};

    AFFICHER(fonctionMystere(tab1, 4), "\n");
    AFFICHER(fonctionMystere(tab2, 4), "\n");
    // La fonction retourne 1 si l'ensemble des éléments sont décroissant

    AFFICHER("Tableau 1 : \n");
    afficherTableau(tab1, 4);

    AFFICHER("\nSaisir 4 valeurs : ");
    question3(tab1, 4);

    AFFICHER(question4(tab1, 4), "\n");
    AFFICHER(question4(tab2, 4), "\n");

    // Question 5
    int Notes[TAILLE];

    AFFICHER("Saisie tableau : \n");
    question3(Notes, TAILLE);
    AFFICHER("Affichage tableau : \n");
    afficherTableau(Notes, TAILLE);
    AFFICHER("Fonction question 4 : \n");
    question4(Notes, TAILLE);

    return 0;
}
