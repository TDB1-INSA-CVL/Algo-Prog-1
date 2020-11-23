#include "insaio.h"
#include <stdio.h>

int main() {
    int n, j = 1, result_for = 1, result_while = 1;
    AFFICHER("Saisir n : ");
    SAISIR(n);

    if (n < 1)
        return -1;

    while (j <= n ) {
        result_while *= j;
        j++;
    }
    AFFICHER("\nAvec boucle while : ", n, "! = ", result_while, "\n");


    for (int i = 1; i <= n; ++i) {
        result_for *= i;
    }
    AFFICHER("\nAvec boucle for : ", n, "! = ", result_for, "\n");

    return 0;
}
