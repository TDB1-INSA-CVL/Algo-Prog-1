#include "insaio.h"
#include "stdio.h"

int main() {

    int a = 5;
    float b = 3.524356;

    AFFICHER("La variable entière vaut : ", a, "\n");
    AFFICHER("La variable reelle vaut : ", b, "\n");

    AFFICHER("La variable entière vaut : ", a, "\nLa variable reelle vaut : ", b, "\n");

    return 0;
}
