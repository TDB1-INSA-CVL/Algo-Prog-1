#include "insaio.h"
#include <stdio.h>

void affiche_Entier(int valeur);

int maximum(int a, int b);

float puissance(float valeur, int puissance);

void facto(int valeur);

void affiche_Tab(float tab[], int size);

float moy_Tab(int tab[], int size);

void copie_tableau(int tab[], float copie[], int size);


void affiche_Entier(int valeur) {
    AFFICHER(valeur);
}

int maximum(int a, int b) {
    /*if (a > b) {
     *    return a;
     * } else {
     *    return b;
     * }
     */
    // Equivalent au if else au dessus (expression ternaire 'condition' ? 'valeur_si_vrai' : 'valeur_si_faux'
    return a > b ? a : b;
}

float puissance(float valeur, int puissance) {
    float resultat = 1;
    for (int i = 0; i < puissance; ++i) {
        resultat *= valeur;
    }
    return resultat;
}

void facto(int valeur) {
    int result = 1;
    for (int i = 1; i <= valeur; i++)
        result = result * i;
    AFFICHER(valeur, "! = ", result);
}

void affiche_Tab(float tab[], int size) {
    for (int i = 0; i < size; ++i) {
        AFFICHER(tab[i], " ");
    }
}

float moy_Tab(int tab[], int size) {
    float somme = 0;
    for (int i = 0; i < size; ++i) {
        somme += tab[i];
    }
    return somme / size;
}

void copie_tableau(int tab[], float copie[], int size) {
    for (int i = 0; i < size; ++i) {
        copie[i] = tab[i];
    }
}


int main() {
    int tab_size = 4;
    float tab1[] = {1.5f, 2, 3.6f, 2.34f};
    int tab2[] = {1, 6, 3, 9};
    float tab3[tab_size];

    AFFICHER("affiche_Entier(4) : ");
    affiche_Entier(4);

    AFFICHER("\nmaximum(4, 5) = ", maximum(4, 5));

    AFFICHER("\npuissance(4, 5) = ", puissance(4, 5));

    AFFICHER("\nfacto(4) : ");
    facto(4);

    AFFICHER("\naffiche_Tab(tab1, tab_size) : ");
    affiche_Tab(tab1, tab_size);

    AFFICHER("\nmoy_Tab(tab2, tab_size) = ", moy_Tab(tab2, tab_size));

    AFFICHER("\ncopie_tableau : ");
    copie_tableau(tab2, tab3, tab_size);
    affiche_Tab(tab3, tab_size);

    return 0;
}


