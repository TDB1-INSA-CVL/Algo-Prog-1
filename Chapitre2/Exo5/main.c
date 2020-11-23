#include "insaio.h"
#include <stdio.h>

#define MAX_SIZE 50

int main() {
    int tableau[MAX_SIZE], current_index = -1, total = 0, payer, a_rendre, coupures_10 = 0, coupures_5 = 0, coupures_2 = 0, coupures_1 = 0;

    AFFICHER("Entrez le prix des articles : ");

    do
    {
        current_index += 1;
        SAISIR(tableau[current_index]);
        total += tableau[current_index];
    }
    while (current_index < 50 && tableau[current_index] != 0);

    AFFICHER("Total : ", total, "\nEntrez le montant payé : ");
    SAISIR(payer);

    a_rendre = payer - total;
    if (a_rendre < 0)
        AFFICHER("Il faut donner plus !!");
    else
    {
        while (a_rendre - 10 >= 0)
        {
            a_rendre -= 10;
            coupures_10++;
        }
        while (a_rendre - 5 >= 0)
        {
            a_rendre -= 5;
            coupures_5++;
        }
        while (a_rendre - 2 >= 0)
        {
            a_rendre -= 2;
            coupures_2++;
        }
        while (a_rendre - 1 >= 0)
        {
            a_rendre -= 1;
            coupures_1++;
        }
        AFFICHER("Il faut rendre : ", coupures_10, "*10€ ", coupures_5, "*5€ ", coupures_2, "*2€ ", coupures_1, "*1€");
    }

    return 0;
}
