#ifndef _LIST_H_
#define _LIST_H_

/**
 * @brief Représente un élément de liste.
 * 
 * Chaque élément de liste contient des données génériques et des pointeurs vers les éléments précédent et suivant dans la liste.
 */
typedef struct lnode_ {
    void *data; /**< Pointeur vers les données stockées dans le nœud. */
    struct lnode_ *prev; /**< Pointeur vers le nœud précédent. */
    struct lnode_ *next; /**< Pointeur vers le nœud suivant. */
} lnode;

/**
 * @brief Représente une liste doublement chaînée.
 * 
 * Une liste contient un pointeur vers son premier et dernier nœud.
 */
typedef struct list_ {
    lnode *head; /**< Pointeur vers le premier nœud de la liste. */
    lnode *tail; /**< Pointeur vers le dernier nœud de la liste. */
} list;

/**
 * @brief Crée un nœud dans la liste.
 * 
 * Alloue de la mémoire pour un nœud et initialise ses valeurs.
 * 
 * @param dat Pointeur vers les données à stocker dans le nœud.
 * @return Pointeur vers le nœud créé.
 */
lnode *lst_create_lnode(void *dat);

/**
 * @brief Crée une nouvelle liste.
 * 
 * Alloue de la mémoire pour une liste et initialise ses pointeurs `head` et `tail` à `NULL`.
 * 
 * @return Pointeur vers la nouvelle liste créée.
 */
list *lst_create_list();

/**
 * @brief Supprime une liste.
 * 
 * Libère la mémoire allouée pour tous les éléments de la liste et pour la liste elle-même.
 * 
 * @param lst Pointeur vers la liste à supprimer.
 */
void lst_delete_list(list * lst);

/**
 * @brief Insère un nœud au début de la liste.
 * 
 * Insère un nœud dans la liste, juste avant le premier nœud actuel.
 * 
 * @param lst Pointeur vers la liste dans laquelle insérer le nœud.
 * @param pnew Pointeur vers le nœud à insérer.
 */
void lst_insert_head(list * lst, lnode * pnew);

/**
 * @brief Insère un nœud à la fin de la liste.
 * 
 * Insère un nœud dans la liste, juste après le dernier nœud actuel.
 * 
 * @param lst Pointeur vers la liste dans laquelle insérer le nœud.
 * @param pnew Pointeur vers le nœud à insérer.
 */
void lst_insert_tail(list * lst, lnode * pnew);

/**
 * @brief Insère un nœud juste après un autre nœud.
 * 
 * Insère un nœud juste après le nœud spécifié dans la liste.
 * 
 * @param lst Pointeur vers la liste dans laquelle insérer le nœud.
 * @param pnew Pointeur vers le nœud à insérer.
 * @param ptr Pointeur vers le nœud après lequel insérer le nouveau nœud.
 */
void lst_insert_after(list * lst, lnode * pnew, lnode * ptr);

/**
 * @brief Supprime le premier nœud de la liste.
 * 
 * Libère la mémoire du premier nœud et met à jour les pointeurs `head` et `tail` si nécessaire.
 * 
 * @param lst Pointeur vers la liste dont on veut supprimer le premier nœud.
 */
void lst_delete_head(list * lst);

/**
 * @brief Supprime le dernier nœud de la liste.
 * 
 * Libère la mémoire du dernier nœud et met à jour les pointeurs `head` et `tail` si nécessaire.
 * 
 * @param lst Pointeur vers la liste dont on veut supprimer le dernier nœud.
 */
void lst_delete_tail(list * lst);

/**
 * @brief Supprime un nœud spécifique de la liste.
 * 
 * Libère la mémoire du nœud spécifié et met à jour les pointeurs des nœuds voisins.
 * 
 * @param lst Pointeur vers la liste dont on veut supprimer le nœud.
 * @param ptr Pointeur vers le nœud à supprimer.
 */
void lst_delete_lnode(list * lst, lnode * ptr);

/**
 * @brief Supprime tous les nœuds de la liste.
 * 
 * Libère la mémoire de tous les nœuds dans la liste et réinitialise les pointeurs `head` et `tail`.
 * 
 * @param lst Pointeur vers la liste dont on veut supprimer tous les nœuds.
 */
void lst_erase(list * lst);

/**
 * @brief Retourne le premier nœud de la liste.
 * 
 * @param lst Pointeur vers la liste dont on veut obtenir le premier nœud.
 * @return Pointeur vers le premier nœud, ou `NULL` si la liste est vide.
 */
lnode *get_first_node(list * lst);

/**
 * @brief Retourne le dernier nœud de la liste.
 * 
 * @param lst Pointeur vers la liste dont on veut obtenir le dernier nœud.
 * @return Pointeur vers le dernier nœud, ou `NULL` si la liste est vide.
 */
lnode *get_last_node(list * lst);

/**
 * @brief Retourne le nœud suivant dans la liste.
 * 
 * @param lst Pointeur vers la liste.
 * @param lnode Pointeur vers le nœud actuel.
 * @return Pointeur vers le nœud suivant, ou `NULL` si le nœud actuel est le dernier.
 */
lnode *get_next_node(list * lst, lnode * lnode);

/**
 * @brief Retourne le nœud précédent dans la liste.
 * 
 * @param lst Pointeur vers la liste.
 * @param lnode Pointeur vers le nœud actuel.
 * @return Pointeur vers le nœud précédent, ou `NULL` si le nœud actuel est le premier.
 */
void *get_previous_elem(list * lst, lnode * lnode);

#endif /* _LIST_H_ */
