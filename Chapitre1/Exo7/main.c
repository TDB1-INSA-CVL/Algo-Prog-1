#include "insaio.h"
#include "stdio.h"

#define USE_24_H_FORMAT 1 // 1 pour activer 0 pour desactiver

int main() {
    int heures, minutes, secondes;

    AFFICHER("Saisir une heure au format \"hh mm ss\" :\n");
    SAISIR(heures, minutes, secondes);
    AFFICHER("\nHeure : ", heures, ":", minutes, ":", secondes, "\n\n");

    if (heures >= 0 && minutes >= 0 && secondes >= 0 && minutes < 60 && secondes < 60 && (!USE_24_H_FORMAT || heures < 24)) // L'heure est valide
    {
        secondes++; // On augmente l'heure d'une seconde et on vérifie si l'heure est toujours valide
        if (secondes == 60) {
            secondes = 0;
            minutes++;

            if (minutes == 60)
            {
                minutes = 0;
                heures++;

                // Si on veut utiliser un format 24h :
                if (USE_24_H_FORMAT && heures == 24)
                {
                    heures = 0;
                }
            }
        }

        AFFICHER("Heure final : ", heures, ":", minutes, ":", secondes, "\n");
        printf("Avec printf : %0.2d:%0.2d:%0.2d", heures, minutes, secondes); // Pour afficher des 0 en plus
    } else {
        AFFICHER("Heure non valide");
    }

    return 0;
}
