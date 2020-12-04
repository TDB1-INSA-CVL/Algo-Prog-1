#include "insaio.h"
#include <stdio.h>

int main() {
    int size;
    AFFICHER("Entrer la taille du losange : ");
    SAISIR(size);

    AFFICHER("\nMethode 1 : \n");
    // VERSION 1
    for (int i = 0; i < (size - 1) / 2; ++i) {
        for (int j = i; j < ((size - 1) / 2); ++j) {
            AFFICHER(" ");
        }
        for (int j = 1; j <= i * 2 + 1; ++j) {
            AFFICHER("*");
        }

        AFFICHER("\n");
    }
    for (int i = (size - 1) / 2; i >= 0; --i) {
        for (int j = i; j < ((size - 1) / 2); ++j) {
            AFFICHER(" ");
        }
        for (int j = 1; j <= i * 2 + 1; ++j) {
            AFFICHER("*");
        }
        AFFICHER("\n");
    }


    AFFICHER("\nMethode 2 : \n");
    // VERSION 2

    int size_2 = (size - 1) / 2;
    for (int x = -size_2 ; x < size_2 + 1; ++x) {
        for (int y = -size_2; y < size_2 + 1; ++y)
        {
            if (x <= y + size_2 && x >= y - size_2 && x >= - y - size_2 && x <= - y + size_2)
            {
                AFFICHER("*");
            }
            else
            {
                AFFICHER(" ");
            }
        }
        AFFICHER("\n");
    }
    return 0;
}