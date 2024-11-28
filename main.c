#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jeu.h"


int main(void) {
    Partie p;
    p.Nb_Bombe = 11;
    initialisation(&p);
    while (1) {
        printf("Que veux tu faire : \n");
        char Commande[TailleMaxCommande]; // stockage de la commande
        if (fgets(Commande, TailleMaxCommande, stdin) != NULL) {
            int taille = strlen(Commande);
            if (taille < 2) {
                // verification que la commande n'est pas vide
                printf("La commande est vide, veuillez reesayer\n");
                viderBuffer();
                continue;
            }
            if (taille == TailleMaxCommande - 1 && Commande[taille - 1] != '\n') {
                // verification que la commande n'est pas trop grande
                printf("La commande est trop longue, veuillez reesayer\n");
                viderBuffer();
                continue;
            }
            if (taille < TailleMaxCommande && Commande[taille - 1] == '\n') {
                //on lit l'entrée et on enleve le retour a la ligne pour que l'entrée devienne une chaine de caractère
                Commande[taille - 1] = '\0';
                taille--;
            }
        } else {
            // la commande ne correspond pas
            printf("Il y a eu une erreur dans la lecture de la commande");
            viderBuffer();
            continue;
        }

        char *detailscommande = strtok(Commande, " ");
        char TabCommande[NBMaxCommande][TailleMaxCommande];
        int nbcommandes = 0;
        while (detailscommande != NULL) {
            strcpy(TabCommande[nbcommandes++], detailscommande);
            detailscommande = strtok(NULL, " ");
        }
        for (int i = 0; TabCommande[0][i]; i++) {
            // met la commande en minuscules
            TabCommande[0][i] = tolower((unsigned char) TabCommande[0][i]);
        }

        if (strcmp(TabCommande[0], "exit") == 0) {
            break;
        }
        if (strcmp(TabCommande[0], "statut") == 0) {
            statut(&p);
        }
        if (strcmp(TabCommande[0], "affall") == 0) {
            affichage_all((p.Terrain));
        }
        if (strcmp(TabCommande[0], "aff") == 0) {
            affichage(&p);
        }
        if (strcmp(TabCommande[0], "jouer") == 0) {
            coup(&p, atoi(TabCommande[1]), atoi(TabCommande[2]));
        }
        if (strcmp(TabCommande[0], "case") == 0) {
            printf("%d\n", whats_that(&p, atoi(TabCommande[1]), atoi(TabCommande[2])));
        }
    }
}


