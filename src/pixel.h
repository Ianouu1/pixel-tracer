#ifndef _PIXEL_H_
#  define _PIXEL_H_

#  include <stdlib.h>
#  include "shape.h"
#  include "list.h"

/**
 * @brief Structure représentant un pixel.
 * 
 * Cette structure contient les coordonnées d'un pixel (`px`, `py`) et sa couleur (`color`).
 */
struct pixel {
    int px; /**< Coordonnée X du pixel. */
    int py; /**< Coordonnée Y du pixel. */
    int color; /**< Couleur du pixel. */
};

typedef struct pixel Pixel;

/**
 * @brief Crée un pixel avec des coordonnées et une couleur spécifiées.
 * 
 * Cette fonction alloue de la mémoire pour un nouveau pixel, puis initialise ses coordonnées
 * et sa couleur selon les paramètres fournis.
 * 
 * @param px Coordonnée X du pixel.
 * @param py Coordonnée Y du pixel.
 * @param color Couleur du pixel.
 * @return Pointeur vers le pixel créé.
 */
Pixel *create_pixel(int px, int py, int color);

/**
 * @brief Libère la mémoire allouée pour un pixel.
 * 
 * Cette fonction libère la mémoire associée à un pixel donné.
 * 
 * @param pixel Pointeur vers le pixel à libérer.
 */
void delete_pixel(Pixel * pixel);

/**
 * @brief Crée une liste de pixels à partir d'une forme.
 * 
 * Cette fonction génère une liste de pixels en fonction du type de forme (point, ligne, carré, etc.)
 * et ajoute les pixels correspondants à la liste spécifiée.
 * 
 * @param shape Pointeur vers la forme à convertir en pixels.
 * @return Liste des pixels générés.
 */
list *create_shape_to_pixel(Shape * shape);

/**
 * @brief Supprime les pixels associés à une forme.
 * 
 * Cette fonction supprime les pixels générés pour une forme donnée en libérant la mémoire associée
 * aux pixels dans la liste fournie.
 * 
 * @param pixel_lst Liste des pixels à supprimer.
 */
void remove_pixel_shape(list * pixel_lst);

/* Private functions */

/**
 * @brief Fonction privée pour dessiner un point en pixel.
 * 
 * Cette fonction convertit un point en pixel et l'ajoute à la liste de pixels.
 * 
 * @param shape Pointeur vers la forme de type point.
 * @param lst Liste des pixels à remplir.
 */
void pixel_point(Shape * shape, list * lst);

/**
 * @brief Fonction privée pour dessiner une ligne en pixels.
 * 
 * Cette fonction utilise l'algorithme de tracé de segment pour dessiner une ligne entre
 * deux points spécifiés dans la forme.
 * 
 * @param shape Pointeur vers la forme de type ligne.
 * @param lst Liste des pixels à remplir.
 */
void pixel_line(Shape * shape, list * lst);

/**
 * @brief Fonction privée pour dessiner un cercle en pixels.
 * 
 * Cette fonction utilise l'algorithme de tracé de cercle pour générer les pixels correspondant
 * à un cercle, puis les ajoute à la liste fournie.
 * 
 * @param shape Pointeur vers la forme de type cercle.
 * @param lst Liste des pixels à remplir.
 */
void pixel_cercle(Shape * shape, list * lst);

/**
 * @brief Fonction privée pour dessiner un rectangle en pixels.
 * 
 * Cette fonction utilise l'algorithme de tracé de segment pour dessiner un rectangle
 * à partir de la forme de type rectangle.
 * 
 * @param shape Pointeur vers la forme de type rectangle.
 * @param lst Liste des pixels à remplir.
 */
void pixel_rectangle(Shape * shape, list * lst);

/**
 * @brief Fonction privée pour dessiner un carré en pixels.
 * 
 * Cette fonction utilise l'algorithme de tracé de segment pour dessiner un carré
 * à partir de la forme de type carré.
 * 
 * @param shape Pointeur vers la forme de type carré.
 * @param lst Liste des pixels à remplir.
 */
void pixel_square(Shape * shape, list * lst);

/**
 * @brief Fonction privée pour dessiner un polygone en pixels.
 * 
 * Cette fonction utilise l'algorithme de tracé de segment pour dessiner un polygone
 * à partir des points de la forme.
 * 
 * @param shape Pointeur vers la forme de type polygone.
 * @param lst Liste des pixels à remplir.
 */
void pixel_polygon(Shape * shape, list * lst);

/**
 * @brief Fonction privée pour dessiner une courbe de Bézier en pixels.
 * 
 * Cette fonction utilise l'algorithme de Casteljau pour calculer les points de la courbe de Bézier
 * et ajoute les pixels correspondants à la liste fournie.
 * 
 * @param shape Pointeur vers la forme de type courbe de Bézier.
 * @param lst Liste des pixels à remplir.
 */
void pixel_curve(Shape * shape, list * lst);

/**
 * @brief Calcule un point médian entre deux points avec un paramètre t.
 * 
 * Cette fonction calcule un point médian entre deux points donnés, en fonction d'un paramètre t
 * qui permet d'interpoler entre les deux points.
 * 
 * @param p1 Premier point.
 * @param p2 Deuxième point.
 * @param t Paramètre d'interpolation.
 * @return Point médian calculé.
 */
Point calc_point_median(Point * p1, Point * p2, double t);

/**
 * @brief Calcule un point sur une courbe de Bézier à l'aide de l'algorithme de Casteljau.
 * 
 * Cette fonction applique l'algorithme de Casteljau pour calculer un point sur une courbe de Bézier
 * en fonction d'un paramètre t.
 * 
 * @param points Liste des points de contrôle de la courbe.
 * @param num_pt Nombre de points de contrôle.
 * @param t Paramètre de la courbe.
 * @return Point calculé sur la courbe de Bézier.
 */
Point cj_calc(Point ** points, int num_pt, double t);

#endif /* _PIXEL_H_ */
