#include "insaio.h"
#include <stdio.h>

int main() {
    int a, b;

    AFFICHER("Saisir a et b: \n");
    SAISIR(a, b);

    AFFICHER("Equation à résoudre : ", a, ".X + ", b);

    if (-b % a == 0) {
        AFFICHER("\n\nSolution entière : ", -b / a);
    } else {
        AFFICHER("\n\nPas de solution entière");
    }

    return 0;
}
