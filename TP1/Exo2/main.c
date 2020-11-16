#include "insaio.h"
#include <stdio.h>

int main() {
    float a, b;

    AFFICHER("Saisir 2 réels : \n");
    SAISIR(a, b);

    AFFICHER("La somme vaut : ", a + b);

    return 0;
}
