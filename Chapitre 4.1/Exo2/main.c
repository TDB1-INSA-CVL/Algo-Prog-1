#include <stdio.h>
#include <string.h>
#include "insaio.h"

int palindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - i - 1]) { // Le - 1 correspond au \0
            return 0;
        }
    }
    return 1;
}
/*
str[0] // 1 er
str[1] // 2eme
str[2] // 3eme
//etc..
str[len - 2 - 1] // avant avant dernier
str[len - 1 - 1] // avant dernier
str[len - 0 - 1] // dernier
*/


int main() {
    char str[50];

    AFFICHER("Entrez une chaine de caractères : ");
    SAISIR(str);

    if (palindrome(str)) {
        AFFICHER("La chaine est palindrome");
    } else {
        AFFICHER("La chaine n'est pas palindrome");
    }


    return 0;
}
