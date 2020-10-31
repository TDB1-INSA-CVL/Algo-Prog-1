#include "insaio.h"
#include "stdio.h"

int main() {
    int a, b;

    ///
    AFFICHER("Saisir a et b :\n");
    SAISIR(a, b);
    AFFICHER("\na : ", a, "\nb : ", b, "\n\n");
    ///
    
    if (a > b) {
        AFFICHER("premier choix \n");
    } else if (a > 10) {
        AFFICHER("deuxième choix \n");
    }

    if (b < 10) {
        AFFICHER("troisième choix \n");
    } else {
        AFFICHER("quatrième choix \n");
    }

    return 0;
}
