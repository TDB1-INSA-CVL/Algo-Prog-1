#include <stdio.h>
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

float mediane(float tab[], int n) {
    if (n % 2 == 0) {
        return (tab[n / 2] + tab[(n / 2) - 1]) / 2.0f;
    } else {
        return tab[(n - 1) / 2];
    }
}

int main() {
    float tableau[20];
    float tableau_tri[20];
    int n;

    AFFICHER("Saisir le nombre de valeur : "); // Doit on demander la saisie de n ?
    SAISIR(n);

    saisie(tableau, n);
    AFFICHER("\nMoyenne du tableau : ", moyenne(tableau, n));

    tri(tableau, tableau_tri, n); // On tri le tableau et on utilise le tableau_tri pour calculer la mediane
    AFFICHER("\nMediane du tableau : ", mediane(tableau_tri, n));

    return 0;
}
