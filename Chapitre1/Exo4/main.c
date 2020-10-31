#include "insaio.h"
#include "stdio.h"

int main() {
    int a, b;
    float c;

    AFFICHER("Saisir a et b :\n");
    SAISIR(a, b);

    c = a;

    AFFICHER("\na : ", a, "\nb : ", b);
    AFFICHER("\n\nResultats :\nQuotient entier : ", a / b, "\nReste : ", a % b, "\nQuotient réel : ", c / b);

    return 0;
}
