#include "insaio.h"
#include <stdio.h>

int main() {
    int temp;
    int somme = 0;

    AFFICHER("Entrez 10 valeurs : ");

    for (int i = 0; i < 10; ++i) {
        SAISIR(temp);

        somme += temp;
    }

    AFFICHER("Somme : ", somme, "\nMoyenne : ", somme / 10.0f);

    return 0;
}
