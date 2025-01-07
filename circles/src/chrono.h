/**
 *
 * chrono
 * 
 * @author Louis-Olivier Beaulieu
 * @description Ce module contient les fonctions et structure permettant la 
 * modelisation d'un chronometre.
 */
 
#ifndef CHRONO_H
#define CHRONO_H

#include "spritesheet.h"
#include "constants.h"

struct chrono {
   struct spritesheet *spritesheet;
   int decaminutes;
   int minutes;
   int decaseconds;
   int seconds;
   int deciseconds;
};

/**
 * Cette fonction permet la creation d'une struct chrono. La struct cree doit etre
 * desallouer avec la fonction chrono_delete.
 *
 * @param SDL_renderer *renderer : le renderer qui sera affecte a la struct sprite sheet
 *
 * @return un struct chrono allouee dynamiquement
 */
struct chrono *chrono_create(SDL_Renderer *renderer);

/**
 * Cette fonction permet de mettre a jour les attributs de temps d'un chrono.
 *
 * @param struct chrono *chrono : le chrono a mettre a jour
 *
 * @param Uint32 milliseconds : le temps en milliseconds a appliquer au chrono
 */
void chrono_update(struct chrono *chrono, Uint32 milliseconds);

/**
 * Cette fonction permet de render un chrono.
 *
 * @param struct chrono *chrono : le chrono a render
 */
void chrono_render(struct chrono *chrono);

/**
 * Cette fonction retourne le chiffre des decaminutes (le chiffre a la position des 
 * dizaines des minutes) a afficher selon un temps en millisecondes.
 *
 * @param Uint32 milliseconds : le temps en millisecondes
 *
 * @retrun le chiffre des decaminutes a afficher
 */
int get_decaminutes(Uint32 milliseconds);

/**
 * Cette fonction retourne le chiffre des minutes (le chiffre a la position des 
 * unites des minutes) a afficher selon un temps en millisecondes.
 *
 * @param Uint32 milliseconds : le temps en millisecondes
 *
 * @retrun le chiffre des minutes a afficher
 */
int get_minutes(Uint32 milliseconds);

/**
 * Cette fonction retourne le chiffre des decasecondes (le chiffre a la position des 
 * dizaines des secondes) a afficher selon un temps en millisecondes.
 *
 * @param Uint32 milliseconds : le temps en millisecondes
 *
 * @retrun le chiffre des decasecondes a afficher
 */
int get_decaseconds(Uint32 milliseconds);

/**
 * Cette fonction retourne le chiffre des secondes (le chiffre a la position des 
 * unites des secondes) a afficher selon un temps en millisecondes.
 *
 * @param Uint32 milliseconds : le temps en millisecondes
 *
 * @retrun le chiffre des secondes a afficher
 */
int get_seconds(Uint32 milliseconds);

/**
 * Cette fonction retourne le chiffre des decisecondes a afficher selon un temps en millisecondes.
 *
 * @param Uint32 milliseconds : le temps en millisecondes
 *
 * @retrun le chiffre des decisecondes a afficher
 */
int get_deciseconds(Uint32 milliseconds);

/**
 * Cette fonction permet de desallouer un chrono.
 *
 * @param struct chrono *chrono : le chrono a desallouer
 */
void chrono_delete(struct chrono *chrono);

#endif
