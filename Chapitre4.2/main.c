#include "insaio.h"
#include <string.h>

int longueur_chaine(char ch[]) {
    int i = 0;
    while (ch[i] != '\0') {
        i++;
    }
    return i;
}

int caractere_present(char ch[], char c) {
    for (int i = 0; i < longueur_chaine(ch); ++i) {
        if (ch[i] == c) {
            return 1;
        }
    }
    return 0;
}

int sequence_presente(char ch[], char seq[]) {
    int j = 0;
    int longeur_sequence = longueur_chaine(seq);
    for (int i = 0; i < longueur_chaine(ch); ++i) {
        if (ch[i] != seq[j]) {
            j = 0;
        }

        if (ch[i] == seq[j]) {
            if (j == longeur_sequence - 1) { // Toute la chaine a été trouvé
                return 1;
            } else { // Sinon on augmente j de 1 pour verifier si le caractère suivant dans ch correspond au caractere suivant de la sequence
                j++;
            }
        }
    }
    return 0;
}

void codage_cesar_3(char ch[]) {
    for (int i = 0; i < longueur_chaine(ch); ++i) {
        if (ch[i] > 'z' - 3 && ch[i] <= 'z') {
            ch[i] += -'z' + 'a' - 1;
        }
        if (ch[i] > 'Z' - 3 && ch[i] <= 'Z') {
            ch[i] += -'Z' + 'A' - 1;
        }
        ch[i] += 3;
    }
}

void decodage_cesar_3(char ch[]) {
    for (int i = 0; i < longueur_chaine(ch); ++i) {
        if (ch[i] < 'a' + 3 && ch[i] >= 'a') {
            ch[i] += -'a' + 'z' + 1;
        }
        if (ch[i] < 'A' + 3 && ch[i] >= 'A') {
            ch[i] += -'A' + 'Z' + 1;
        }
        ch[i] -= 3;
    }
}

void codage_cesar_n(char ch[], int decalage) {
    decalage = decalage > 25 ? 25 : decalage;
    decalage = decalage < 1 ? 1 : decalage;

    for (int i = 0; i < longueur_chaine(ch); ++i) {
        if (ch[i] > 'z' - decalage && ch[i] <= 'z') {
            ch[i] += -'z' + 'a' - 1;
        }
        if (ch[i] > 'Z' - decalage && ch[i] <= 'Z') {
            ch[i] += -'Z' + 'A' - 1;
        }
        ch[i] += decalage;
    }
}

void decodage_cesar_n(char ch[], int decalage) {
    if (decalage > 25) {
        decalage = 25;
    } else if (decalage < 1) {
        decalage = 1;
    }


    for (int i = 0; i < longueur_chaine(ch); ++i) {
        if (ch[i] < 'a' + decalage && ch[i] >= 'a') {
            ch[i] += -'a' + 'z' + 1;
        }
        if (ch[i] < 'A' + decalage && ch[i] >= 'A') {
            ch[i] += -'A' + 'Z' + 1;
        }
        ch[i] -= decalage;
    }
}


int main() {
    char test_str[50];
    AFFICHER("Entrez une chaine de caractere : ");
    SAISIR(test_str);

    AFFICHER("\n", longueur_chaine(test_str), "\n");

    AFFICHER(caractere_present(test_str, 'a'), "\n");

    AFFICHER(sequence_presente(test_str, "to"), "\n");
    AFFICHER(sequence_presente(test_str, "ta"), "\n");

    codage_cesar_3(test_str);
    AFFICHER(test_str, "\n");

    decodage_cesar_3(test_str);
    AFFICHER(test_str, "\n");

    codage_cesar_n(test_str, 3);
    AFFICHER(test_str, "\n");

    decodage_cesar_n(test_str, 3);
    AFFICHER(test_str, "\n");

    return 0;
}
