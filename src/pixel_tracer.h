#ifndef _PIXEL_TRACER_H_
#  define _PIXEL_TRACER_H_

#  include "list.h"
#  include "id.h"
#  include "area.h"
#  include "layers.h"
#  include "shape.h"
#  include "pixel.h"
#  include "render.h"

/**
 * @brief Structure représentant l'application Pixel Tracer.
 * 
 * Cette structure contient les différentes entités manipulées dans l'application : 
 * la liste des zones (`list_area`), la zone actuelle (`current_area`), 
 * la couche actuelle (`current_layer`), et la forme actuellement sélectionnée (`current_shape`).
 */
struct pixel_tracer {
    AreaList *list_area; /**< Liste des zones de l'application. */
    Area *current_area; /**< Zone actuelle sélectionnée. */
    Layer *current_layer; /**< Couche actuelle sélectionnée. */
    Shape *current_shape; /**< Forme actuelle sélectionnée (si applicable). */
};

typedef struct pixel_tracer Pixel_tracer_app;

/**
 * @brief Initialisation de l'application Pixel Tracer.
 * 
 * Cette fonction initialise les différentes structures de l'application, en créant une zone 
 * par défaut avec une couche associée. Elle initialise également les pointeurs vers la zone,
 * la couche et la forme actuelles.
 * 
 * @param app Pointeur vers l'application à initialiser.
 */
void init_app(Pixel_tracer_app * app);

/**
 * @brief Destruction de l'application Pixel Tracer.
 * 
 * Cette fonction libère la mémoire utilisée par l'application, notamment la liste des zones
 * et les objets associés. Elle réinitialise également les pointeurs de la structure `Pixel_tracer_app`.
 * 
 * @param app Pointeur vers l'application à détruire.
 */
void destry_app(Pixel_tracer_app * app);

#endif /* _PIXEL_TRACER_H_ */
