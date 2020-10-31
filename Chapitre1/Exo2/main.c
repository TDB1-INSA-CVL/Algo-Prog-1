#include "insaio.h"
#include "stdio.h"

int main() {
    float taux = 1.10f, montant; // 1 euro = 1.10 dollar

    AFFICHER("Saisir le montant : \n");
    SAISIR(montant);
    AFFICHER("\nTaux : ", taux, "\nMontant : ", montant, "€");

    montant *= taux; // Equivalent à montant = montant * taux;

    AFFICHER("\n\nResultat : \nMontant : ", montant, "$\n");

    
    ///
    // On a ici utiliser des floats d'où les 0 après la virgule.
    // on pourra au second trimestre utiliser :
    printf("Avec printf : %.2f$", montant);
    // Pour afficher uniquement 2 chiffres après la virgule
    ///

    return 0;
}
