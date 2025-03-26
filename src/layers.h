#ifndef _LAYERS_H_
#define _LAYERS_H_

#define LAYER_VISIBLE 1 /**< La couche est visible. */
#define LAYER_UNVISIBLE 0 /**< La couche est invisible. */

/**
 * @brief Représente une couche contenant des formes.
 * 
 * Chaque couche a un identifiant, un nom, et une visibilité. Elle contient également une liste de formes.
 */
struct layer {
    unsigned int id; /**< Identifiant unique de la couche. */
    char name[255]; /**< Nom de la couche. */
    unsigned char visible; /**< Visibilité de la couche (1 pour visible, 0 pour invisible). */
    list shapes; /**< Liste des formes dans la couche. */
};

typedef struct layer Layer; /**< Type de donnée représentant une couche. */
typedef list LayersList; /**< Type de donnée représentant une liste de couches. */

/**
 * @brief Crée une nouvelle couche.
 * 
 * Alloue de la mémoire pour une nouvelle couche et initialise ses propriétés.
 * 
 * @param id L'identifiant de la couche.
 * @param name Le nom de la couche.
 * @return Pointeur vers la nouvelle couche.
 */
Layer *create_layer(int id, char *name);

/**
 * @brief Supprime une couche.
 * 
 * Libère la mémoire allouée pour une couche et ses ressources associées.
 * 
 * @param layer La couche à supprimer.
 */
void delete_layer(Layer * layer);

/**
 * @brief Crée une nouvelle liste de couches.
 * 
 * Alloue et initialise une nouvelle liste de couches.
 * 
 * @return Pointeur vers la nouvelle liste de couches.
 */
LayersList *create_layers_list();

/**
 * @brief Supprime une liste de couches.
 * 
 * Libère la mémoire allouée pour une liste de couches.
 * 
 * @param layer_list La liste des couches à supprimer.
 */
void delete_layers_list(LayersList * layer_list);

/**
 * @brief Ajoute une couche à une liste de couches.
 * 
 * Insère une nouvelle couche à la fin de la liste des couches.
 * 
 * @param layer_list La liste de couches à laquelle ajouter la couche.
 * @param layer La couche à ajouter.
 */
void add_layer_to_list(LayersList * layer_list, Layer * layer);

/**
 * @brief Supprime une couche d'une liste de couches.
 * 
 * @param layer_list La liste de couches d'où supprimer la couche.
 * @param layer La couche à supprimer.
 */
void remove_layer_from_list(LayersList * layer_list, Layer * layer);

/**
 * @brief Rend une couche visible.
 * 
 * Change l'état de la visibilité de la couche pour la rendre visible.
 * 
 * @param layer La couche à rendre visible.
 */
void set_layer_visible(Layer * layer);

/**
 * @brief Rend une couche invisible.
 * 
 * Change l'état de la visibilité de la couche pour la rendre invisible.
 * 
 * @param layer La couche à rendre invisible.
 */
void set_layer_unvisible(Layer * layer);

/**
 * @brief Ajoute une forme à une couche.
 * 
 * Insère une forme à la fin de la liste des formes dans la couche.
 * 
 * @param layer La couche à laquelle ajouter la forme.
 * @param shape La forme à ajouter.
 */
void add_shape_to_layer(Layer * layer, Shape * shape);

/**
 * @brief Supprime une forme d'une couche.
 * 
 * @param layer La couche dont la forme doit être supprimée.
 * @param shape La forme à supprimer.
 */
void remove_shape_to_from(Layer * layer, Shape * shape);

#endif /* _LAYERS_H_ */
