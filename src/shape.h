#ifndef _SHAPE_H_
#  define _SHAPE_H_

/**
 * @file shape.h
 * @brief Définition des structures de formes géométriques et des fonctions associées.
 * Ce fichier contient des structures pour représenter différentes formes géométriques, ainsi que des fonctions
 * pour créer, supprimer et manipuler ces formes.
 */

/**
 * @enum Shape_type
 * @brief Enumération des types de formes géométriques.
 * 
 * Cette énumération définit les différents types de formes géométriques disponibles.
 */
typedef enum shape_type { 
    POINT,      /**< Représente un point */
    LINE,       /**< Représente une ligne */
    SQUAR,      /**< Représente un carré */
    RECTANGLE,  /**< Représente un rectangle */
    CERCLE,     /**< Représente un cercle */
    POLYGON,    /**< Représente un polygone */
    CURVE       /**< Représente une courbe */
} Shape_type;

/**
 * @enum Color
 * @brief Enumération des couleurs disponibles.
 * 
 * Cette énumération définit les couleurs disponibles pour les formes.
 */
typedef enum color { 
    BLACK,      /**< Couleur noire */
    WIGHT,      /**< Couleur blanche */
    RED,        /**< Couleur rouge */
    GREEN       /**< Couleur verte */
} Color;

/**
 * @struct point
 * @brief Structure représentant un point dans un espace 2D.
 * 
 * Cette structure contient les coordonnées d'un point dans un plan 2D.
 */
struct point {
    int pos_x; /**< Coordonnée X du point */
    int pos_y; /**< Coordonnée Y du point */
};
typedef struct point Point;

/**
 * @struct line
 * @brief Structure représentant une ligne définie par deux points.
 * 
 * Cette structure contient deux pointeurs vers des points pour définir une ligne.
 */
struct line {
    Point *p1; /**< Premier point de la ligne */
    Point *p2; /**< Deuxième point de la ligne */
};
typedef struct line Line;

/**
 * @struct squar
 * @brief Structure représentant un carré.
 * 
 * Cette structure contient un point et la longueur du côté du carré.
 */
struct squar {
    Point *p1; /**< Premier point du carré */
    int length; /**< Longueur du côté du carré */
};
typedef struct squar Squar;

/**
 * @struct rectangle
 * @brief Structure représentant un rectangle.
 * 
 * Cette structure contient un point, la largeur et la hauteur du rectangle.
 */
struct rectangle {
    Point *p1; /**< Premier point du rectangle */
    int width; /**< Largeur du rectangle */
    int height; /**< Hauteur du rectangle */
};
typedef struct rectangle Rectangle;

/**
 * @struct cercle
 * @brief Structure représentant un cercle.
 * 
 * Cette structure contient un point représentant le centre du cercle et son rayon.
 */
struct cercle {
    Point *center; /**< Point représentant le centre du cercle */
    int radus; /**< Rayon du cercle */
};
typedef struct cercle Cercle;

/**
 * @struct polygon
 * @brief Structure représentant un polygone.
 * 
 * Cette structure contient un nombre de sommets et un tableau de pointeurs vers les points représentant les sommets.
 */
struct polygon {
    int n; /**< Nombre de sommets du polygone */
    Point **points; /**< Tableau de pointeurs vers les points représentant les sommets */
};
typedef struct polygon Polygon;

/**
 * @struct curve
 * @brief Structure représentant une courbe définie par quatre points.
 * 
 * Cette structure contient quatre points qui définissent une courbe.
 */
struct curve {
    Point *p1; /**< Premier point de la courbe */
    Point *p2; /**< Deuxième point de la courbe */
    Point *p3; /**< Troisième point de la courbe */
    Point *p4; /**< Quatrième point de la courbe */
};
typedef struct curve Curve;

/**
 * @struct shape
 * @brief Structure représentant une forme géométrique.
 * 
 * Cette structure contient un identifiant, un type de forme, un pointeur vers la forme spécifique, 
 * des informations sur le remplissage, l'épaisseur, la couleur et la rotation.
 */
struct shape {
    unsigned long long int id; /**< Identifiant unique de la forme */
    Shape_type shape_type; /**< Type de la forme */
    void *ptrShape; /**< Pointeur vers la forme spécifique */
    unsigned char fill; /**< Indicateur de remplissage de la forme */
    float thickness; /**< Épaisseur de la forme */
    Color color; /**< Couleur de la forme */
    double rotation; /**< Angle de rotation de la forme */
};
typedef struct shape Shape;

/**
 * @brief Crée un point avec les coordonnées spécifiées.
 * @param px Coordonnée X du point.
 * @param py Coordonnée Y du point.
 * @return Un pointeur vers le point créé.
 */
Point *create_point(int px, int py);

/**
 * @brief Supprime un point.
 * @param point Le pointeur vers le point à supprimer.
 */
void delete_point(Point * point);

/**
 * @brief Crée une ligne définie par deux points.
 * @param p1 Premier point de la ligne.
 * @param p2 Deuxième point de la ligne.
 * @return Un pointeur vers la ligne créée.
 */
Line *create_line(Point * p1, Point * p2);

/**
 * @brief Supprime une ligne.
 * @param line Le pointeur vers la ligne à supprimer.
 */
void delete_line(Line * line);

/**
 * @brief Crée un carré à partir d'un point et de la longueur de son côté.
 * @param point Le point représentant un coin du carré.
 * @param length La longueur du côté du carré.
 * @return Un pointeur vers le carré créé.
 */
Squar *create_squar(Point * point, int length);

/**
 * @brief Supprime un carré.
 * @param squar Le pointeur vers le carré à supprimer.
 */
void delete_squar(Squar * squar);

/**
 * @brief Crée un rectangle à partir d'un point, de la largeur et de la hauteur.
 * @param point Le point représentant un coin du rectangle.
 * @param width La largeur du rectangle.
 * @param height La hauteur du rectangle.
 * @return Un pointeur vers le rectangle créé.
 */
Rectangle *create_rectangle(Point * point, int width, int height);

/**
 * @brief Supprime un rectangle.
 * @param rectangle Le pointeur vers le rectangle à supprimer.
 */
void delete_rectangle(Rectangle * rectangle);

/**
 * @brief Crée un cercle à partir d'un centre et du rayon.
 * @param center Le point représentant le centre du cercle.
 * @param radus Le rayon du cercle.
 * @return Un pointeur vers le cercle créé.
 */
Cercle *create_cercle(Point * center, int radus);

/**
 * @brief Supprime un cercle.
 * @param cercle Le pointeur vers le cercle à supprimer.
 */
void delete_cercle(Cercle * cercle);

/**
 * @brief Crée un polygone avec un nombre de sommets spécifié.
 * @param n Le nombre de sommets du polygone.
 * @return Un pointeur vers le polygone créé.
 */
Polygon *create_polygon(int n);

/**
 * @brief Supprime un polygone.
 * @param polygon Le pointeur vers le polygone à supprimer.
 */
void delete_polygon(Polygon * polygon);

/**
 * @brief Crée une courbe définie par quatre points.
 * @param p1 Premier point de la courbe.
 * @param p2 Deuxième point de la courbe.
 * @param p3 Troisième point de la courbe.
 * @param p4 Quatrième point de la courbe.
 * @return Un pointeur vers la courbe créée.
 */
Curve *create_curve(Point * p1, Point * p2, Point * p3, Point * p4);

/**
 * @brief Supprime une courbe.
 * @param curve Le pointeur vers la courbe à supprimer.
 */
void delete_curve(Curve * curve);

/**
 * @brief Crée une forme vide en fonction du type spécifié.
 * @param shape_type Le type de la forme à créer.
 * @return Un pointeur vers la forme créée.
 */
Shape *create_empty_shape(Shape_type shape_type);

/**
 * @brief Convertit un point en chaîne de caractères.
 * @param p Le point à convertir.
 * @param str La chaîne de caractères où la représentation du point sera stockée.
 */
void sprint_point(Point * p, char *str);

/**
 * @brief Convertit une ligne en chaîne de caractères.
 * @param line La ligne à convertir.
 * @param str La chaîne de caractères où la représentation de la ligne sera stockée.
 */
void sprint_line(Line * line, char *str);

/**
 * @brief Convertit un carré en chaîne de caractères.
 * @param squar Le carré à convertir.
 * @param str La chaîne de caractères où la représentation du carré sera stockée.
 */
void sprint_squar(Squar * squar, char *str);

/**
 * @brief Convertit un rectangle en chaîne de caractères.
 * @param rectangle Le rectangle à convertir.
 * @param str La chaîne de caractères où la représentation du rectangle sera stockée.
 */
void sprint_rectangle(Rectangle * rectangle, char *str);

/**
 * @brief Convertit un cercle en chaîne de caractères.
 * @param cercle Le cercle à convertir.
 * @param str La chaîne de caractères où la représentation du cercle sera stockée.
 */
void sprint_cercle(Cercle * cercle, char *str);

/**
 * @brief Convertit un polygone en chaîne de caractères.
 * @param polygon Le polygone à convertir.
 * @param str La chaîne de caractères où la représentation du polygone sera stockée.
 */
void sprint_polygon(Polygon * polygon, char *str);

/**
 * @brief Convertit une courbe en chaîne de caractères.
 * @param curve La courbe à convertir.
 * @param str La chaîne de caractères où la représentation de la courbe sera stockée.
 */
void sprint_curve(Curve * curve, char *str);

/**
 * @brief Crée une forme de type point.
 * @param px Coordonnée X du point.
 * @param py Coordonnée Y du point.
 * @return Un pointeur vers la forme créée.
 */
Shape *create_point_shape(int px, int py);

/**
 * @brief Crée une forme de type ligne.
 * @param px1 Coordonnée X du premier point.
 * @param py1 Coordonnée Y du premier point.
 * @param px2 Coordonnée X du deuxième point.
 * @param py2 Coordonnée Y du deuxième point.
 * @return Un pointeur vers la forme créée.
 */
Shape *create_line_shape(int px1, int py1, int px2, int py2);

/**
 * @brief Crée une forme de type carré.
 * @param px Coordonnée X du coin du carré.
 * @param py Coordonnée Y du coin du carré.
 * @param length Longueur du côté du carré.
 * @return Un pointeur vers la forme créée.
 */
Shape *create_square_shape(int px, int py, int length);

/**
 * @brief Crée une forme de type rectangle.
 * @param px Coordonnée X du coin du rectangle.
 * @param py Coordonnée Y du coin du rectangle.
 * @param width Largeur du rectangle.
 * @param height Hauteur du rectangle.
 * @return Un pointeur vers la forme créée.
 */
Shape *create_rectangle_shape(int px, int py, int width, int height);

/**
 * @brief Crée une forme de type cercle.
 * @param px Coordonnée X du centre du cercle.
 * @param py Coordonnée Y du centre du cercle.
 * @param radus Rayon du cercle.
 * @return Un pointeur vers la forme créée.
 */
Shape *create_cercle_shape(int px, int py, int radus);

/**
 * @brief Crée une forme de type polygone.
 * @param n Nombre de sommets du polygone.
 * @param tab Tableau des coordonnées des sommets du polygone.
 * @return Un pointeur vers la forme créée.
 */
Shape *create_polygon_shape(int n, int *tab);

/**
 * @brief Crée une forme de type courbe.
 * @param px1 Coordonnée X du premier point.
 * @param py1 Coordonnée Y du premier point.
 * @param px2 Coordonnée X du deuxième point.
 * @param py2 Coordonnée Y du deuxième point.
 * @param px3 Coordonnée X du troisième point.
 * @param py3 Coordonnée Y du troisième point.
 * @param px4 Coordonnée X du quatrième point.
 * @param py4 Coordonnée Y du quatrième point.
 * @return Un pointeur vers la forme créée.
 */
Shape *create_curve_shape(int px1, int py1, int px2, int py2, int px3,
                          int py3, int px4, int py4);

/**
 * @brief Supprime une forme.
 * @param shape Le pointeur vers la forme à supprimer.
 */
void delete_shape(Shape * shape);

/**
 * @brief Convertit une forme en chaîne de caractères.
 * @param shape La forme à convertir.
 * @param str La chaîne de caractères où la représentation de la forme sera stockée.
 */
void sprint_shape(Shape * shape, char *str);

#endif
