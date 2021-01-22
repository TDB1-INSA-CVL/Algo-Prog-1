#include <stdio.h>
#include <string.h>
#include "insaio.h"

int longeur_mot_le_plus_long(char str[]) {
    int result = 0, tmp_result = 0;
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == ' ') {
            if (tmp_result > result) {
                result = tmp_result;
            }
            tmp_result = 0;
        } else {
            tmp_result++;
        }
    }

    return result;
}

int main() {
    char str[50];

    AFFICHER("Entrez une chaine de caractères : ");
    SAISIR(str);

    AFFICHER("Resultat : ", longeur_mot_le_plus_long(str));

    return 0;
}
