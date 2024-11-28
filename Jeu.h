/**
* @file  Jeu.h
 * @brief Décris les fonction de jeu du démineur
*/

#pragma once // Jeu.h
#include "Terrain.h"

void viderBuffer();

/**
* @brief Affichage des toutes les cases du terrain de demineur
* @param[int] terrain Terrain de demineur
*/
void affichage_all(const Case terrain[TAILLE_TERRAIN][TAILLE_TERRAIN]);

/**
* @brief Affichage des cases du terrain de demineur en fonction de l'avancer du jeu
* @param[int] p terrain de la partie de demineur et nombre de bombe
*/
void affichage(const Partie *p);

/**
* @brief Permet de permuter deux elements du terrain de demineur
* @param[int] terrain Terrain de demineur
* @param[int] index1 indice de la premiere valeur a echanger
* @param[int] index2 indice de la seconde valeur a echanger
*/
void permut(Case terrain[TAILLE_TERRAIN][TAILLE_TERRAIN], int index1, int index2);

/**
* @brief Permet de choisir les deux cases a permiter pour melanger le terrain de demineur
* @param[int] p terrain de la partie de demineur et nombre de bombe
* @sa permut()
*/
void mix(Partie *p);

/**
* @brief Initialisation de toutes les cases du demineur par un nombre definie de bombe.
* @param[int] p terrain de la partie de demineur et nombre de bombe
* @sa mix()
*/
void initialisation(Partie *p);

/**
* @brief Permet d'afficher l'etat de la partie en fonction du terrain
* @param[int] p terrain de la partie de demineur et nombre de bombe
* @return la fonction retourne un entier en fonction de l'etat de la partie
*/
int statut(const Partie *p);

/**
* @brief La fonction permet de savoir le contenu d'une case du terrain
* @param[int] p terrain de la partie de demineur et nombre de bombe
* @param[in] i case du terrain a l'indice i
* @param[in] j case du terran a l'indice j
* @return la fonction retourne ce que contient la case de ce terrain
*/
int whats_that(const Partie *p, const int i, const int j);

/**
* @brief La fonction permet de connaite le nombre de bombe voisine a la case choisi
* @param[int] p terrain de la partie de demineur et nombre de bombe
* @param[in] i case du terrain a l'indice i
* @param[in] j case du terran a l'indice j
* @return la fonction retourne le nombre de bombe autour de la case choisi
* @sa whats_that()
*/
int nb_bombre_voisine(Partie *p, const int i, const int j);

/**
* @brief La fonction permet de jouer un coup dans le jeu de demineur sur le terrain
* @param[int] p terrain de la partie de demineur et nombre de bombe
* @param[in] i case du terrain a l'indice i
* @param[in] j case du terran a l'indice j
* @sa whats_that()
* @sa nb_bombre_voisine()
*/
void coup(Partie *p, const int i, const int j);

