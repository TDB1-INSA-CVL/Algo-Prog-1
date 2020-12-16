#include <stdio.h>


int verifier_ligne(int grille[9][9], int ligne) {
    int contained[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 9; ++i) {
        contained[grille[ligne][i] - 1] += 1;
    }
    for (int i = 0; i < 9; ++i) {
        if (contained[i] != 1)
            return i + 1;
    }
    return -1;
}

int verifier_colonne(int grille[9][9], int colonne) {
    int contained[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 9; ++i) {
        contained[grille[i][colonne] - 1] += 1;
    }
    for (int i = 0; i < 9; ++i) {
        if (contained[i] != 1)
            return i + 1;
    }
    return -1;
}

int verifier_bloc(int grille[9][9], int bloc) {
    int x, y;
    if (bloc - 6 >= 0) {
        x = 2;
        y = bloc - 6;
    } else if (bloc - 3 >= 0) {
        x = 1;
        y = bloc - 3;
    } else {
        x = 0;
        y = bloc;
    }

    int contained[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            contained[grille[x * 3 + i][y * 3 + j] - 1] += 1;
        }
    }
    for (int i = 0; i < 9; ++i) {
        if (contained[i] != 1)
            return i + 1;
    }
    return -1;
}

void verifier_grille(int grille[9][9]) {
    for (int i = 0; i < 9; ++i) {
        int r = verifier_ligne(grille, i);
        if (r != -1)
            printf("ligne %d incorrecte. Plusieurs fois %d \n", i, r);

        r = verifier_colonne(grille, i);
        if (r != -1)
            printf("colonne %d incorrecte. Plusieurs fois %d \n", i, r);

        r = verifier_bloc(grille, i);
        if (r != -1)
            printf("bloc %d incorrecte. Plusieurs fois %d \n", i, r);

    }
}


/* nom : init
 description : initalise la grille avec une solution
*/
void init(int g[][9]) {
    int gg[9][9] = {{1, 2, 3, 4, 5, 6, 7, 8, 9},
                    {4, 5, 6, 7, 8, 9, 1, 2, 3},
                    {7, 8, 9, 1, 2, 3, 4, 5, 6},
                    {2, 3, 1, 5, 6, 4, 8, 9, 7},
                    {5, 6, 4, 8, 9, 7, 2, 3, 1},
                    {8, 9, 7, 2, 3, 1, 5, 6, 4},
                    {3, 1, 2, 6, 4, 5, 9, 7, 8},
                    {6, 4, 5, 9, 7, 8, 3, 1, 2},
                    {9, 7, 8, 3, 1, 2, 6, 4, 5}};
    int i, j;
    for (i = 0; i < 9; i++) for (j = 0; j < 9; j++) g[i][j] = gg[i][j];
    return;
}

/* nom : afficher_grille
 description : affiche une grille � l'�cran
*/

void afficher_grille(int g[][9]) {
    printf("\n\t%d %d %d   %d %d %d   %d %d %d\n", g[0][0], g[0][1], g[0][2], g[0][3], g[0][4], g[0][5], g[0][6],
           g[0][7], g[0][8]);
    printf("\t%d %d %d   %d %d %d   %d %d %d\n", g[1][0], g[1][1], g[1][2], g[1][3], g[1][4], g[1][5], g[1][6], g[1][7],
           g[1][8]);
    printf("\t%d %d %d   %d %d %d   %d %d %d\n", g[2][0], g[2][1], g[2][2], g[2][3], g[2][4], g[2][5], g[2][6], g[2][7],
           g[2][8]);
    printf("\n\t%d %d %d   %d %d %d   %d %d %d\n", g[3][0], g[3][1], g[3][2], g[3][3], g[3][4], g[3][5], g[3][6],
           g[3][7], g[3][8]);
    printf("\t%d %d %d   %d %d %d   %d %d %d\n", g[4][0], g[4][1], g[4][2], g[4][3], g[4][4], g[4][5], g[4][6], g[4][7],
           g[4][8]);
    printf("\t%d %d %d   %d %d %d   %d %d %d\n", g[5][0], g[5][1], g[5][2], g[5][3], g[5][4], g[5][5], g[5][6], g[5][7],
           g[5][8]);
    printf("\n\t%d %d %d   %d %d %d   %d %d %d\n", g[6][0], g[6][1], g[6][2], g[6][3], g[6][4], g[6][5], g[6][6],
           g[6][7], g[6][8]);
    printf("\t%d %d %d   %d %d %d   %d %d %d\n", g[7][0], g[7][1], g[7][2], g[7][3], g[7][4], g[7][5], g[7][6], g[7][7],
           g[7][8]);
    printf("\t%d %d %d   %d %d %d   %d %d %d\n\n", g[8][0], g[8][1], g[8][2], g[8][3], g[8][4], g[8][5], g[8][6],
           g[8][7], g[8][8]);
    return;
}


int main() {
    int g1[9][9], g2[9][9];
    init(g1); // g1 est correcte
    init(g2);
    g2[6][1] = 5;
    g2[8][2] = 6; // g2 est incorrecte

    afficher_grille(g2);
    verifier_grille(g2);

    return 0;
}
