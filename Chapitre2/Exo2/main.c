#include "insaio.h"
#include <stdio.h>

int main() {
    int n;
    float result = 0;
    AFFICHER("Saisir n : ");
    SAISIR(n);

    if (n < 1)
        return -1;

    for (int i = 1; i <= n; ++i) {
        result += 1.0f/i;
    }
    AFFICHER("\nResulat : ", result, "\n");

    return 0;
}
