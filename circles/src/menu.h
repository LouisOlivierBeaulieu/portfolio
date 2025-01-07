/**
 *
 * menu
 *
 * @author inconnu (modifications et ajouts par Louis-Olivier Beaulieu)
 * @description Ce module contient les fonctions et structure permettant la 
 * modelisation du menu du jeu circles.
 */

#ifndef MENU_H
#define MENU_H

#include <stdbool.h>
#include "spritesheet.h"
#include "constants.h"
#include "text.h"

enum menu_state {
   MENU_PLAY_FOCUS,
   MENU_QUIT_FOCUS,
   MENU_PLAY,
   MENU_QUIT
};

enum menu_difficulty {
   EASY,
   MEDIUM,
   HARD
};

struct menu {
   enum menu_state state;
   enum menu_difficulty difficulty;
   bool selecting_difficulty;
   bool space_mode;
   struct spritesheet *background;
   struct spritesheet *title;
   struct spritesheet *play;
   struct spritesheet *quit;
   struct spritesheet *difficulty_title;
   struct spritesheet *easy;
   struct spritesheet *medium;
   struct spritesheet *hard;
   Mix_Music *music;
   Mix_Chunk *select_sound;
   SDL_Renderer *renderer;
};


/**
 * Cette fonction permet la creation et l'initialization d'une struct menu.
 *
 * @param renderer le renderer de l'application qui s'occupera de l'affichage des sprites
 * @return Le pointeur vers la nouvelle struct menu, NULL si erreur
 */
struct menu *menu_initialize(SDL_Renderer *renderer);

/**
 * Cette fonction permet de demarrer le cycle d'attente d'evenement dans le menu.
 * Le menu est d'abord affiche, puis la boucle d'attente d'evenement est lancee.
 *
 * @param menu le menu a afficher
 */
void menu_run(struct menu *menu);

/**
 * Cette fonction permet de liberer l'espace memoire allouee dynamiquement pour
 * une struct menu et ses attributs.
 *
 * @param menu  The menu to delete
 */
void menu_delete(struct menu *menu);

#endif
