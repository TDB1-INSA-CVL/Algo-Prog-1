#include "insaio.h"
#include <stdio.h>

#define MAX_SIZE 4

int main() {
    int tableau[MAX_SIZE] = {12, 5, 21, 8};
    int temp, max_index = 0;

    for (int i = 0; i < MAX_SIZE; ++i) {
        for (int j = i; j < MAX_SIZE; ++j) {
            if (tableau[j] > tableau[max_index])
            {
                max_index = j;
            }
        }
        temp = tableau[i];
        tableau[i] = tableau[max_index];
        tableau[max_index] = temp;
        max_index = i + 1;
    }

    for (int i = 0; i < MAX_SIZE; ++i) {
        AFFICHER(tableau[i], " ");
    }

    return 0;
}
