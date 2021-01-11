#include <stdio.h>
#include <string.h>
#include "insaio.h"

void convert_case(char str[]) {
    for (int i = 0; i < strlen(str); ++i) {
        if ('a' <= str[i] && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        } else if ('A' <= str[i] && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

int main() {
    char str[50];

    AFFICHER("Entrez une chaine de caractères : ");
    SAISIR(str);
    convert_case(str);
    AFFICHER("Resultat : ", str);


    return 0;
}
