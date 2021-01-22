#include <stdio.h>
#include <string.h>
#include "insaio.h"

int occurance(char str[], char c) {
    int count = 0;
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}

int main() {
    char str[50], c;
    AFFICHER("Entrez une chaine de caractères : ");
    SAISIR(str);
    AFFICHER("Saisir un caractère à compter : ");
    SAISIR(c);

    AFFICHER("Il y a ", occurance(str, c), " ", c, " dans : ", str);

    return 0;
}
