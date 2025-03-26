#include <stdlib.h>
#include <stdio.h>
#include "layers.h"
#include "area.h"
#include "pixel.h"
/**
 * @file render.h
 * @brief Déclarations des fonctions et types pour le rendu d'une zone avec des couches et des formes.
 *
 * Ce fichier contient les déclarations des fonctions nécessaires pour gérer le rendu graphique d'une zone
 * avec des couches et des formes. Les fonctionnalités incluent l'effacement de la zone, l'affichage de la zone,
 * et le dessin des différentes couches et formes présentes dans la zone.
 */

 #ifndef _RENDER_H_
 #  define _RENDER_H_
 
 /**
  * @enum color_cell
  * @brief Enumération représentant les différents types de cellules de couleur.
  *
  * Cette énumération définit les trois types de cellules possibles : vide (EMPTY_CELL),
  * noire (BLACK_CELL), et rouge (RED_CELL).
  */
 typedef enum { EMPTY_CELL, BLACK_CELL, RED_CELL } color_cell;
 
 /** @def EMPTY_CHAR
  * @brief Caractère représentant une cellule vide.
  *
  * Ce caractère est utilisé pour afficher une cellule vide dans la zone.
  */
 #  define EMPTY_CHAR '.'
 
 /** @def FULL_CHAR
  * @brief Caractère représentant une cellule pleine.
  *
  * Ce caractère est utilisé pour afficher une cellule pleine dans la zone.
  */
 #  define FULL_CHAR  '#'
 
 /**
  * @brief Fonction principale pour rendre une zone.
  *
  * Cette fonction est responsable de l'affichage de la zone, y compris de l'effacement
  * et du dessin des différentes couches et formes qu'elle contient.
  *
  * @param area Pointeur vers la structure de la zone à rendre.
  */
 void render_area(Area * area);
 
 /**
  * @brief Dessine la zone spécifiée.
  *
  * Cette fonction affiche les caractères correspondant à chaque cellule de la zone
  * en fonction de son état (vide ou pleine). Elle utilise les caractères définis
  * par `EMPTY_CHAR` et `FULL_CHAR`.
  *
  * @param area Pointeur vers la zone à dessiner.
  */
 void draw_area(Area * area);
 
 /**
  * @brief Efface l'écran en fonction du système d'exploitation.
  *
  * Cette fonction utilise des séquences de commandes spécifiques à l'OS pour
  * effacer l'écran. Elle utilise des codes d'échappement pour les systèmes Unix/Linux
  * et la commande `cls` pour Windows.
  */
 void clear_screen();
 
 /**
  * @brief Dessine toutes les couches visibles sur la zone.
  *
  * Cette fonction commence par effacer la zone, puis parcourt toutes les couches
  * visibles dans la liste des couches et dessine les formes qu'elles contiennent.
  *
  * @param area Pointeur vers la zone sur laquelle les couches sont dessinées.
  */
 void draw_all_layers(Area * area);
 
 /**
  * @brief Dessine les formes d'une couche sur la zone.
  *
  * Cette fonction parcourt toutes les formes de la couche spécifiée et les dessine
  * dans la zone, en modifiant les cellules de la zone en fonction des pixels de chaque forme.
  *
  * @param area Pointeur vers la zone où les formes seront dessinées.
  * @param layer Pointeur vers la couche contenant les formes à dessiner.
  */
 void draw_layer_shapes(Area * area, Layer * layer);
 
 #endif
 