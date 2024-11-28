#include <stdio.h>
#include <stdlib.h>
#include "Terrain.h"

void viderBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void affichage_all(const Case terrain[TAILLE_TERRAIN][TAILLE_TERRAIN]) {
    printf("     ");
    for (int i = 0; i < TAILLE_TERRAIN; i++) {
        printf(" %d ", i);
    }
    printf("\n");
    for (int i = 0; i < TAILLE_TERRAIN; i++) {
        printf(" %3d ", i);
        for (int j = 0; j < TAILLE_TERRAIN; j++) {
            if (terrain[i][j].type == Vide) {
                printf(" . ");
            }
            if (terrain[i][j].type == Bombe) {
                printf(" B ");
            }
        }
        printf("\n");
    }
}

void affichage(const Partie *p) {
    printf("     ");
    for (int i = 0; i < TAILLE_TERRAIN; i++) {
        printf(" %d ", i);
    }
    printf("\n");
    for (int i = 0; i < TAILLE_TERRAIN; i++) {
        printf(" %3d ", i);
        for (int j = 0; j < TAILLE_TERRAIN; j++) {
            if (p->Terrain[i][j].etat == Vu) {
                if (p->Terrain[i][j].type == Bombe) {
                    printf(" B ");
                } else {
                    printf(" %d ", p->Terrain[i][j].valeur);
                }
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}


void permut(Case terrain[TAILLE_TERRAIN][TAILLE_TERRAIN], int index1, int index2) {
    int row1 = index1 / TAILLE_TERRAIN;
    int col1 = index1 % TAILLE_TERRAIN;
    int row2 = index2 / TAILLE_TERRAIN;
    int col2 = index2 % TAILLE_TERRAIN;

    Case temp = terrain[row1][col1];
    terrain[row1][col1] = terrain[row2][col2];
    terrain[row2][col2] = temp;
}

void mix(Partie *p) {
    int n = TAILLE_TERRAIN * TAILLE_TERRAIN;
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        permut(p->Terrain, i, j);
    }
}

void initialisation(Partie *p) {
    int count = 0;
    for (int i = 0; i < TAILLE_TERRAIN; i++) {
        for (int j = 0; j < TAILLE_TERRAIN; j++) {
            p->Terrain[i][j].etat = Masque;
            p->Terrain[i][j].valeur = 0;
            if (count < p->Nb_Bombe) {
                p->Terrain[i][j].type = Bombe;
                count++;
            } else {
                p->Terrain[i][j].type = Vide;
            }
        }
    }
    mix(p);
}



int statut(const Partie *p) {
    int count = 0;
    for (int i = 0; i < TAILLE_TERRAIN; i++) {
        for (int j = 0; j < TAILLE_TERRAIN; j++) {
            if (p->Terrain[i][j].etat == Vu
                && p->Terrain[i][j].type == Bombe) {
                printf("Partie Perdu\n");
                return 0;
            }
            if (p->Terrain[i][j].etat == Vu
                && p->Terrain[i][j].type == Vide) {
                count++;
            }
        }
    }
    if (count - p->Nb_Bombe == TAILLE_TERRAIN * TAILLE_TERRAIN) {
        printf("Partie Gagner\n");
        return 2;
    }
    printf("Partie En Cour\n");
    return 1;
}

int whats_that(const Partie *p, const int i, const int j) {
    if (i >= 0 && i < TAILLE_TERRAIN
        && j >= 0 && j < TAILLE_TERRAIN) {
        if (p->Terrain[i][j].type == Bombe) {
            return 1;
        } else {
            return 2;
        }
    }
    return 0;
}

int nb_bombre_voisine(Partie *p, const int i, const int j) {
    int nb_B = 0;
    for (int k = i - 1; k <= i + 1; k++) {
        for (int m = j - 1; m <= j + 1; m++) {
            int case_p;
            case_p = whats_that(p, k, m);
            if (case_p == 1) {
                nb_B++;
            }
        }
    }
    return nb_B;
}

void coup(Partie *p, const int i, const int j) {
    if (!whats_that(p, i, j))
        printf("Il n'est pas possible de jouer en dehors des limites du terrains\n");
    else {
        if (whats_that(p, i, j) == 2) {
            int val = nb_bombre_voisine(p, i, j);
            p->Terrain[i][j].etat = Vu;
            p->Terrain[i][j].type = Vide;
            p->Terrain[i][j].valeur = val;
        }
    }
}