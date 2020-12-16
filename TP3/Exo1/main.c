#include "insaio.h"
#include <math.h>
#include <stdio.h>
#include <assert.h>

#define precision 0.00001

/**
 * Verifie si un triangle est valide
 * @param a, b, c cotes du triangle
 * @return 1 si le triangle valide, 0 sinon
 */
int triangle_is_valide(float a, float b, float c) {
    return a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && c + a > b ? 1 : 0;
}

/**
 * Verifie si un triangle est rectangle
 * @param a, b, c cotes du triangle
 * @return 1 si le triangle est rectangle, 0 sinon
 */
int triangle_is_rectangle(float a, float b, float c) {
    if (!triangle_is_valide(a, b, c))
        return 0;

    float hyp = fmaxf(fmaxf(a, b), c);

    return fabsf(a * a + b * b + c * c - 2 * hyp * hyp) < precision ? 1 : 0;
}

/**
 * Verifie si un triangle est isocele
 * @param a, b, c cotes du triangle
 * @return 1 si le triangle est isocele, 0 sinon
 */
int triangle_is_isocele(float a, float b, float c) {
    if (!triangle_is_valide(a, b, c))
        return 0;

    return a == b || a == c || b == c ? 1 : 0;
}

/**
 * Verifie si un triangle est equilateral
 * @param a, b, c cotes du triangle
 * @return 1 si le triangle est equilateral, 0 sinon
 */
int triangle_is_equilateral(float a, float b, float c) {
    if (!triangle_is_valide(a, b, c))
        return 0;

    return a == b && a == c ? 1 : 0;
}

/**
 * Verifie si un triangle est equilateral
 * @param a, b, c cotes du triangle
 * @return le type de triangle
 */
int triangle_get_type(float a, float b, float c) {
    if (triangle_is_valide(a, b, c)) {

        if (triangle_is_equilateral(a, b, c))
            return 5;
        else if (triangle_is_isocele(a, b, c) && triangle_is_rectangle(a, b, c))
            return 4;
        else if (triangle_is_rectangle(a, b, c))
            return 3;
        else if (triangle_is_isocele(a, b, c))
            return 2;
        else
            return 1;
    } else {
        return -1;
    }
}

int main() {
    assert(triangle_is_valide(1, 2, 3) == 0);
    assert(triangle_is_valide(2, 2, 2) == 1);
    assert(triangle_is_valide(3, 4, 5) == 1);

    assert(triangle_is_rectangle(1, 2, 3) == 0);
    assert(triangle_is_rectangle(3, 5, 4) == 1);

    assert(triangle_is_isocele(1, 2, 3) == 0);
    assert(triangle_is_isocele(5, 5, 4) == 1);
    assert(triangle_is_isocele(4, 4, 4) == 1);

    assert(triangle_is_equilateral(1, 2, 3) == 0);
    assert(triangle_is_equilateral(5, 5, 5) == 1);

    assert(triangle_get_type(3, 4, 5) == 3);
    assert(triangle_get_type(3, 4, 4) == 2);
    assert(triangle_get_type(1, 1, sqrt(2)) == 4);

    float a, b, c;
    AFFICHER("Entrez un triangle (a b c) : ");
    SAISIR(a, b, c);
    switch (triangle_get_type(a, b, c)) {
        case 1:
            AFFICHER("Quelconque");
            break;
        case -1:
            AFFICHER("Impossible");
            break;
        case 2:
            AFFICHER("Isocèle");
            break;
        case 3:
            AFFICHER("Rectangle");
            break;
        case 4:
            AFFICHER("Isocèle/rectangle");
            break;
        case 5:
            AFFICHER("Equilateral");
            break;
    }

    return 0;
}
