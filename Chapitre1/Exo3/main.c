#include "insaio.h"
#include "stdio.h"

int main() {
    int a, b, c, temp;
    AFFICHER("Saisir a, b et c :\n");
    SAISIR(a, b, c);

    AFFICHER("\nAvant : \na : ", a, "\nb : ", b, "\nc : ", c);

    temp = b;
    b = a;
    a = c;
    c = temp;

    AFFICHER("\nAprès : \na : ", a, "\nb : ", b, "\nc : ", c);

    return 0;
}
