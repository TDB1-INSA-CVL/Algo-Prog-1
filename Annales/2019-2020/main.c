#include <stdio.h>
#include <math.h>
#include "insaio.h"

void saisie(float tab[], int n) {
    AFFICHER("Saisir ", n, " valeurs : ");
    for (int i = 0; i < n; ++i) {
        SAISIR(tab[i]);

    }

    AFFICHER("Le tableau contient : ");
    for (int i = 0; i < n; ++i) {
        AFFICHER(tab[i], " ");
    }
}

float moyenne(float tab[], int n) {
    float somme = 0;
    for (int i = 0; i < n; ++i) {
        somme += tab[i];
    }
    return somme / n;
}

float variance(float tab[], int n) {
    float v = 0;
    float x_barre = moyenne(tab, n);
    for (int i = 0; i < n; ++i) {
        v += (tab[i] - x_barre) * (tab[i] - x_barre);
    }
    return (1 / n) * v;
}

void norm(float tab[],int n)
{
    float moy = moyenne(tab, n);
    float ecart = sqrt(variance(tab, n));

    for (int i = 0; i < n; ++i) {
        tab[i] = (tab[i] - moy) / ecart;
    }
}

int main() {
    float x[20], y[30];
    int n_x = 20, n_y = 30;

    saisie(x, n_x);
    saisie(y, n_y);

    AFFICHER("\nTableau 1 : ");
    for (int i = 0; i < n_x; ++i) {
        AFFICHER(x[i], " ");
    }
    AFFICHER("\nTableau 2 : ");
    for (int i = 0; i < n_y; ++i) {
        AFFICHER(y[i], " ");
    }

    AFFICHER("\nMoyenne du tableau x : ", moyenne(x, n_x));
    AFFICHER("\nMoyenne du tableau y : ", moyenne(y, n_y));

    AFFICHER("\nVariance du tableau x : ", variance(x, n_x));
    AFFICHER("\nVariance du tableau y : ", variance(y, n_y));

    norm(x, n_x);
    norm(y, n_y);

    AFFICHER("\nMoyenne du tableau x après norm : ", moyenne(x, n_x));
    AFFICHER("\nMoyenne du tableau y après norm : ", moyenne(y, n_y));

    AFFICHER("\nVariance du tableau x après norm : ", variance(x, n_x));
    AFFICHER("\nVariance du tableau y après norm : ", variance(y, n_y));

    return 0;
}
