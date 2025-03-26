#ifndef _COMMAND_H_
#define _COMMAND_H_

#define MAX_PARAM 30

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <readline/readline.h>
#include <readline/history.h>
#include "pixel_tracer.h"

/**
 * @struct command
 * @brief Structure représentant une commande avec des paramètres de différents types.
 */
struct command {
    char name[50];            /**< Nom de la commande */
    int int_size;             /**< Nombre de paramètres entiers */
    int int_params[MAX_PARAM]; /**< Tableau des paramètres entiers */
    int str_size;             /**< Nombre de paramètres chaîne de caractères */
    char *str_params[MAX_PARAM]; /**< Tableau des paramètres chaîne */
    int flt_size;             /**< Nombre de paramètres flottants */
    float flt_params[MAX_PARAM]; /**< Tableau des paramètres flottants */
};

typedef struct command Command;

/**
 * @brief Crée une nouvelle commande vide.
 * 
 * @return Un pointeur vers une structure Command initialisée.
 */
Command *create_commande();

/**
 * @brief Ajoute un paramètre entier à une commande.
 * 
 * @param cmd Pointeur vers la commande.
 * @param p Valeur entière à ajouter.
 */
void add_int_param(Command * cmd, int p);

/**
 * @brief Ajoute un paramètre flottant à une commande.
 * 
 * @param cmd Pointeur vers la commande.
 * @param p Valeur flottante à ajouter.
 */
void add_float_param(Command * cmd, float p);

/**
 * @brief Ajoute un paramètre chaîne à une commande.
 * 
 * @param cmd Pointeur vers la commande.
 * @param p Chaîne de caractères à ajouter (copie du pointeur fourni).
 */
void add_str_param(Command * cmd, char *p);

/**
 * @brief Libère la mémoire allouée pour une commande.
 * 
 * @param cmd Pointeur vers la commande à libérer.
 */
void free_cmd(Command * cmd);

/**
 * @brief Lit et exécute une commande saisie par l'utilisateur.
 * 
 * @param app Pointeur vers l'application Pixel Tracer.
 * @return 0 en cas de succès, ou un code d'erreur.
 */
int read_exec_command(Pixel_tracer_app * app);

/**
 * @brief Lit une commande depuis l'entrée standard.
 * 
 * @param cmd Pointeur vers la commande à remplir.
 */
void read_from_stdin(Command * cmd);

#endif /* _COMMAND_H_ */
