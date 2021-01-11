#include <stdio.h>
#include <string.h>
#include "insaio.h"

int main() {
    char ch1[50], ch2[50], ch3[50] = "";

    AFFICHER("Entrez une chaine de caractères : ");
    SAISIR(ch1);

    AFFICHER("Entrez une seconde chaine de caractères : ");
    SAISIR(ch2);

    strncat(ch3, ch1, strlen(ch1) / 2);
    strncat(ch3, ch2, strlen(ch2) / 2);

    AFFICHER("Resultat : ", ch3);

    return 0;
}
