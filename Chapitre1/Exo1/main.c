#include "insaio.h"
#include "stdio.h"

int main() {
    int a=5, b=2, c;
    float f = 5, g = 2, h1, h2, h3;

    ///
    AFFICHER("Saisir a, b, f et g ou vide pour les valeurs du cours : \n");
    SAISIR(a, b, f, g);
    AFFICHER("\na : ", a, "\nb : ", b, "\nf : ", f, "\ng : ", g);
    ///

    c = a / b;
    h1 = f / g;
    h2 = a / b;
    h3 = f / b;

    ///
    AFFICHER("\n\nResultats : \nc : ", c, "\nh1 : ", h1, "\nh2 : ", h2, "\nh3 : ", h3);
    ///

    return 0;
}
