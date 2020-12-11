#include "insaio.h"
#include <stdio.h>

int maFonction(int x);

/*
 * Affiche la valeur de x et retourne x
 */
int maFonction(int x) {
    AFFICHER("\nValeur de x dans la fonction : ", x);
    return x;
}

int main() {
    // 1) x n'est pas initialisé. Il aura donc une valeur inconnu
    int x;
    x = maFonction(x);

    // 2) Valide
    AFFICHER("\nValeur de x retourné par la fonction", maFonction(5));

    // 3) Valide mais la valeur retourné par la fonction dans la 1ere ligne n'est pas utilisé
    maFonction(5);
    AFFICHER("\nValeur de x retourné par la fonction", maFonction(5));

    // 4) Valide
    int x2, a = 5;
    x2 = maFonction(a);
    AFFICHER("\nValeur de x retourné par la fonction", x2);

    // 5) Erreur syntax : Pas possible de compiler (pas de 'int' dans l'appel d'une fonction)
    /*
     * int a2;
     * maFonction(int a2);
     * AFFICHER(maFonction(int a2);
     */

    // 6) Valide mais on ne se sert pas de la valeur retourné par maFonction
    maFonction(5);

    // 7) Ne compile pas car x non declaré
    /*
     * int a3 = 5;
     * x3 = maFonction(int a);
     */

    // 8) Ne compile pas : Error syntax (pas de 'int' dans l'appel d'une fonction)
    /*int x4, a4 = 5;
     * x4 = maFonction(int a4);
     * AFFICHER(x4)
     */

    return 0;
}
