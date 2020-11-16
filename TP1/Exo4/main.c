#include "insaio.h"
#include <stdio.h>

int main() {
    int a;

    AFFICHER("Entrez un nombre : \n");
    SAISIR(a);

    AFFICHER("\n", a / 100, " centaine(s), ", (a % 100) / 10, " dizaine(s), ", (a % 100) % 10, " unité(s)");

    return 0;
}
