#include "insaio.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int solution, valeur_essaye, max_essai = 10;

    srand(time(NULL));
    solution = rand() % 100;

    AFFICHER("Trouver la solution qui est comprise entre 1 et 100\n");

    for (int i = 0; i < max_essai; ++i) {
        SAISIR(valeur_essaye);

        if (valeur_essaye == solution)
        {
            AFFICHER("Vous avez trouvé la solution en ", i, " essai(s)\n");
            break;
        }
        else if (valeur_essaye < solution)
        {
            AFFICHER("La solution est plus grande\n");
        }
        else if (valeur_essaye > solution)
        {
            AFFICHER("La solution est plus petite\n");
        }
    }
    
    return 0;
}
