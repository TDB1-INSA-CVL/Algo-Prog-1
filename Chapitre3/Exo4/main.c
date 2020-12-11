#include "insaio.h"
#include <math.h>
#include <stdio.h>

#define MAX_SIZE 10
#define precision 0.00001

int ask_vector_dimension();

void saisie_vecteur(float tab[], int dimension);

float norme(float vecteur[], int dimension);

float scalaire(float vecteur1[], float vecteur2[], int dimension);

int colineaire(float vecteur1[], float vecteur2[], int dimension);

int orthogonaux(float vecteur1[], float vecteur2[], int dimension);

int ask_vector_dimension() {
    int dimension = 0;
    do {
        AFFICHER("Dimension des vecteurs ? ");
        SAISIR(dimension);
    } while (dimension < 1 || dimension > MAX_SIZE);
    return dimension;
}

void saisie_vecteur(float tab[], int dimension) {
    AFFICHER("Saisir un vecteur : ");
    for (int i = 0; i < dimension; ++i) {
        SAISIR(tab[i]);
    }
}

float norme(float vecteur[], int dimension) {
    float somme = 0;
    for (int i = 0; i < dimension; ++i) {
        somme += vecteur[i] * vecteur[i];
    }
    return sqrtf(somme);
}

float scalaire(float vecteur1[], float vecteur2[], int dimension) {
    float somme = 0;
    for (int i = 0; i < dimension; ++i) {
        somme += vecteur1[i] * vecteur2[i];
    }
    return somme;
}

int colineaire(float vecteur1[], float vecteur2[], int dimension) {

    for (int i = 0; i < dimension; ++i) {
        if (abs(vecteur1[0] * vecteur2[i] - vecteur1[i] * vecteur2[0]) > precision) {
            return 0; // False
        }
    }
    return 1; // True
}

int orthogonaux(float vecteur1[], float vecteur2[], int dimension) {
    /*if (scalaire(vecteur1, vecteur2, dimension) == 0) {
        return 1; // True
    } else {
        return 0; // False
    }*/
    return scalaire(vecteur1, vecteur2, dimension) == 0 ? 1 : 0;
}

int main() {
    float vecteur1[MAX_SIZE];
    float vecteur2[MAX_SIZE];

    int dimension = ask_vector_dimension();

    saisie_vecteur(vecteur1, dimension);
    saisie_vecteur(vecteur2, dimension);


    AFFICHER("Norme vecteur1 = ", norme(vecteur1, dimension), "\nNorme vecteur2 = ", norme(vecteur2, dimension));
    AFFICHER("\nScalaire vecteur1 . vecteur2 = ", scalaire(vecteur1, vecteur2, dimension));
    AFFICHER("\nVecteur1 et Vecteur2 colinaire : ", colineaire(vecteur1, vecteur2, dimension));
    AFFICHER("\nVecteur1 et Vecteur2 orthogonaux : ", orthogonaux(vecteur1, vecteur2, dimension));

    return 0;
}
