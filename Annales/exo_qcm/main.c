#include "insaio.h"
#include <string.h>

#define NB_NOTES 5

int question3() {
    int tab_notes[NB_NOTES], i, somme_notes = 0; // initialisation
    float moyenne;
    printf("Saissez vos %i notes\n", NB_NOTES);
    for (i = 0; i < NB_NOTES; i++) { // Point virgule
        scanf("%i", &tab_notes[i]);
        somme_notes = somme_notes + tab_notes[i];
    }
    moyenne = (float)somme_notes / NB_NOTES; // int / int = int or on cherche float
    if (moyenne == 20) // 1 seul egale
        printf("BRAVO !\n");
    printf("Votre moyenne est %f", moyenne);
    return 0;
}

int maFonction(char ch1[], char ch2[]) {
    int i = 0;
    while (ch1[i] != '\0') {
        if (ch1[i] < ch2[i])
            return -1;
        else if (ch2[i] < ch1[i])
            return 1;
        i++;
    }
    if (ch2[i] == '\0')
        return 0;
    else
        return -1;
}

int question2() {
    int ligne, colonne;
    int nb_lignes, nb_colonnes;
    scanf("%i %i", &nb_lignes, &nb_colonnes);
    for (ligne = 0; ligne < nb_lignes; ligne++) {
        for (colonne = 0; colonne < nb_colonnes; colonne++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}

int maxi2 (int a, int b);
float maxf3 (float a, float b, float c);
int isPresentFloatIn (float tableau[], float a);

int saisirInts (int tableau[], int len);
//ou (pas sur de la reponse)
int saisirInts (int tableau[]);

void saisirStr (char str[], int len);
//ou (pas sur de la reponse)
void saisirStr (char str[]);


int main() {

    AFFICHER(maFonction("axxxx", "bxxxx"), "\n"); // -1 car a < b, si identique on regarde la lettre suivante
    AFFICHER(maFonction("bxxxx", "axxxx"), "\n"); // 1 car b < a, si identique on regarde la lettre suivante
    AFFICHER(maFonction("axxxx", "axxxx"), "\n"); // 0 car chaine identique et de meme longeur
    AFFICHER(maFonction("axxxx", "axxxxb"), "\n"); // 0 car chaine 2 plus longue

    return 0;
}
