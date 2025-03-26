#ifndef _ID_H_
#define _ID_H_

#define ID_FILE "id.txt"

/**
 * @brief Génère et retourne un nouvel identifiant unique.
 * 
 * @return Un identifiant unique de type unsigned long long int.
 */
unsigned long long int get_next_id();

/**
 * @brief Définit manuellement l'identifiant global.
 * 
 * @param id L'identifiant à définir.
 */
void set_id(unsigned long long int id);

/**
 * @brief Sauvegarde l'identifiant actuel dans un fichier.
 */
void save_id();

/**
 * @brief Charge l'identifiant depuis un fichier.
 */
void load_id();

#endif /* _ID_H_ */
