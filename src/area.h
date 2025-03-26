#include <stdlib.h>
#include <stdio.h>
#include "layers.h"
/**
 * @file area.h
 * @brief Déclarations des structures et fonctions pour la gestion des zones et de leurs couches.
 *
 * Ce fichier définit les structures nécessaires à la gestion d'une "zone" (une matrice bidimensionnelle),
 * ainsi que les fonctions permettant de créer, supprimer et manipuler ces zones. Une zone peut contenir
 * plusieurs couches, et chaque cellule de la zone peut être vide ou pleine.
 */

 #ifndef _AREA_H_
 #  define _AREA_H_
 
 /**
  * @struct area
  * @brief Structure représentant une zone dans l'espace.
  *
  * Cette structure contient les informations relatives à une zone, telles que sa taille (largeur et hauteur),
  * son identifiant, son nom, ses couches, et les caractères utilisés pour représenter les cellules vides et pleines.
  */
 struct area {
     unsigned char id;          /**< Identifiant de la zone. */
     char name[255];            /**< Nom de la zone. */
     unsigned int width;        /**< Largeur de la zone (nombre de colonnes). */
     unsigned int height;       /**< Hauteur de la zone (nombre de lignes). */
     char **area;               /**< Pointeur vers une matrice représentant la zone. */
     LayersList *lst_layers;    /**< Liste des couches dans la zone. */
     char empty_char;           /**< Caractère utilisé pour représenter une cellule vide. */
     char full_char;            /**< Caractère utilisé pour représenter une cellule pleine. */
 };
 
 typedef struct area Area;          /**< Alias pour la structure area représentant une zone. */
 typedef list AreaList;             /**< Liste de zones. */
 
 /**
  * @brief Crée une nouvelle zone avec les dimensions et le nom spécifiés.
  *
  * Cette fonction alloue de la mémoire pour une nouvelle zone, initialise ses dimensions,
  * son nom, et crée une matrice vide représentant l'état de la zone.
  *
  * @param width Largeur de la zone.
  * @param height Hauteur de la zone.
  * @param id Identifiant de la zone.
  * @param name Nom de la zone.
  * @return Pointeur vers la zone nouvellement créée.
  */
 Area *create_area(unsigned int width, unsigned int height, unsigned char id, char *name);
 
 /**
  * @brief Supprime une zone et libère la mémoire associée.
  *
  * Cette fonction libère la mémoire allouée pour la matrice représentant la zone,
  * ainsi que pour la zone elle-même.
  *
  * @param area Pointeur vers la zone à supprimer.
  */
 void delete_area(Area * area);
 
 /**
  * @brief Crée une nouvelle liste de zones.
  *
  * Cette fonction alloue et initialise une liste vide qui pourra contenir des zones.
  *
  * @return Pointeur vers la nouvelle liste de zones.
  */
 AreaList *create_area_list();
 
 /**
  * @brief Supprime une liste de zones et libère la mémoire associée.
  *
  * Cette fonction libère la mémoire associée à la liste des zones, mais ne supprime pas les zones elles-mêmes.
  *
  * @param area_list Pointeur vers la liste de zones à supprimer.
  */
 void delete_area_list(AreaList * area_list);
 
 /**
  * @brief Ajoute une zone à une liste de zones.
  *
  * Cette fonction insère une nouvelle zone à la fin de la liste de zones.
  *
  * @param area_list Liste de zones dans laquelle ajouter la zone.
  * @param area Pointeur vers la zone à ajouter à la liste.
  */
 void add_area_to_list(AreaList * area_list, Area * area);
 
 /**
  * @brief Supprime une zone d'une liste de zones.
  *
  * Cette fonction est destinée à supprimer une zone spécifique de la liste.
  * Elle nécessite d'être complétée pour effectuer l'opération de suppression.
  *
  * @param area_list Liste de zones de laquelle retirer la zone.
  * @param area Pointeur vers la zone à retirer de la liste.
  */
 void remove_area_from_list(AreaList * area_list, Area * area);
 
 #endif
 