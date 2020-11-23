#include "insaio.h"
#include <stdio.h>

int main() {
    int n;

    AFFICHER("Saisir n : ");
    SAISIR(n);

    if (n < 1)
    {
        AFFICHER("n ne doit pas être négatif");
        return -1;
    }

    for (int i = 1; i <= n; ++i) {
        AFFICHER("\n-----------------------\nTable de ", i, "\n");
        for (int j = 1; j <= 10; ++j) {
            AFFICHER(i, "*", j, "=", i * j, "\n");
        }
    }

    return 0;
}
