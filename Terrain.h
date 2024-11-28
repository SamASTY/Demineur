/**
* @file  Terrain.h
 * @brief Décris les types et constantes du terrain de démineur.
*/

#pragma once // Terrain.h
/**
 *@brief Constante du terrain de démineur, et des commandes de jeux.
* */
enum { TAILLE_TERRAIN = 11, TailleMaxCommande = 30, NBMaxCommande = 3, NB_VOISIN_COTE = 2 };

/**
* @brief Definition d'un type permetant de connaite l'etat d'avancement d'une partie de demineur.
*/
typedef enum { EN_COUR, GAGNGER, PERDU } Etat_Jeu;

/**
* @brief Definition d'un type permetant savoir le composant des cases.
*/
typedef enum { Vide, Bombe } Type;

/**
* @brief Definition d'un type permetant de suivre l'etat des case.
*/
typedef enum { Masque, Vu } Etat;

/**
* @brief Definition d'une structure permettant de stockers les cases un terrain de demineur avec leurs informations.
*/
typedef struct {
    Etat etat;
    Type type;
    int valeur;
} Case;

/**
* @brief Definition d'une structure conteannt le terrain de demineur en detail et son nombre de bombe.
*/
typedef struct {
    Case Terrain[TAILLE_TERRAIN][TAILLE_TERRAIN];
    int Nb_Bombe;
} Partie;