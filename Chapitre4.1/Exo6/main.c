#include <stdio.h>
#include <string.h>
#include "insaio.h"

void custom_strcat(char str1[], char str2[]) {
    int len_str1 = strlen(str1);
    for (int i = 0; i < strlen(str2); ++i) {
        str1[len_str1 + i] = str2[i];
    }
}

void custom_strncat(char str1[], char str2[], int n) {
    int len_str1 = strlen(str1);
    for (int i = 0; i < n && i < strlen(str2); ++i) {
        str1[len_str1 + i] = str2[i];
    }
}

int differents(char str[]) {
    for (int i = 0; i < strlen(str); ++i) {
        for (int j = 0; j < strlen(str); ++j) {
            if (i != j && (str[i] == str[j] || str[i] == str[j] - 'a' + 'A')) {
                return 0;
            }
        }
    }
    return 1;
}

void compter(char ch[]) {
    int abc[26] = {0};
    for (int i = 0; i < strlen(ch); ++i) {
        if ('a' <= ch[i] && ch[i] <= 'z') {
            abc[ch[i] - 'a']++;
        } else if ('A' <= ch[i] && ch[i] <= 'Z') {
            abc[ch[i] - 'A']++;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (abc[i] == 0) {
            continue; // On n'affiche pas si la lettre n'est pas présente
        }

        char lettre = 'a' + i; // A cause du fonctionnement de AFFICHER. Sinon on peut faire sans passer par une variable
        AFFICHER(lettre, " : ", abc[i], "\n");
    }
}


int main() {
    char ch1[50], ch2[50], ch3[50];

    AFFICHER("Entrez une chaine de caractères : ");
    SAISIR(ch1);
    AFFICHER("Entrez une seconde chaine de caractères : ");
    SAISIR(ch2);
    custom_strcat(ch1, ch2);
    AFFICHER("Resultat : ", ch1);

    AFFICHER("Entrez une chaine de caractères : ");
    SAISIR(ch1);
    AFFICHER("Entrez une seconde chaine de caractères : ");
    SAISIR(ch2);
    custom_strncat(ch1, ch2, 3);
    AFFICHER("Resultat : ", ch1);

    AFFICHER("Entrez une chaine de caractères : ");
    SAISIR(ch1);
    if (differents(ch1))
    {
        AFFICHER("Tout les caractères sont différants");
    } else {
        AFFICHER("Tout les caractères ne sont pas différants");
    }

    AFFICHER("Entrez une chaine de caractères : ");
    SAISIR(ch1);
    compter(ch1);

    return 0;
}
