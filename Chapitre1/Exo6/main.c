#include "insaio.h"
#include "stdio.h"

int main() {
    int jour, mois, annee;

    AFFICHER("Saisir une date au format \"jj mm aaaa\" :\n");
    SAISIR(jour, mois, annee);
    AFFICHER("\nDate : ", jour, "/", mois, "/", annee, "\n\n");

    //Validation de la date entree :
    if (jour >= 1 && jour <= 31 && mois >= 1 && mois <= 12) {
        if ((annee) % 4 == 0 && ((annee) % 100 != 0 || (annee) % 400 == 0)  // L'année est bissextile (peux etre remplacer par __isleap(annee) en incluant time.h)
            && mois == 2 && jour <= 28) // Et c'est le mois de février et Le nombre de jour ne depasse pas 28
        {
            AFFICHER("La date entrée est valide, il s'agit du mois de février, l'année est bissextile donc c'est un mois de 28");
        } else if (!((annee) % 4 == 0 && ((annee) % 100 != 0 || (annee) % 400 == 0))  // L'année n'est pas bissextile (peux etre remplacer par !__isleap(annee) en incluant time.h)
                   && mois == 2 && jour <= 29) // Et c'est le mois de février et le nombre de jour ne depasse pas 29
        {
            AFFICHER("La date entrée est valide, il s'agit du mois de février, l'année n'est pas bissextile donc c'est un mois de 29");
        } else if ((mois == 4 || mois == 6 || mois == 9 || mois == 11) &&
                   jour <= 30) { // C'est un mois de 30 jours et le nombre de jour ne depasse pas 30
            AFFICHER("La date entrée est valide, il s'agit d'un mois de 30 jours");
        } else if ((mois == 1 || mois == 3 || mois == 5 || mois == 7 || mois == 8 || mois == 10 ||
                    mois == 12)) // C'est un mois de 31 jours, on sait que le nombre de jour n'est pas superieur à 31
        {
            AFFICHER("La date entrée est valide, il s'agit d'un mois de 31 jours");
        } else { // Si on arrive la, la date n'est pas valide
            AFFICHER("La date entrée n'est pas valide");
        }

    } else { //La date est invalide
        AFFICHER("Merci d'entrer une date valide");
    }

    return 0;
}
