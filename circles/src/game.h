 /**
 *
 * game
 * 
 * @author Louis-Olivier Beaulieu
 * @description Ce module contient les fonctions et structure permettant la 
 * modelisation du jeu circles.
 */
 
#ifndef GAME_H
#define GAME_H

#include "chrono.h"
#include "text.h"
#include "shape.h"
#include "menu.h"
#include <time.h>

enum game_state {
   GAME_PLAYING,
   GAME_OVER,
   GAME_PAUSED,
   GAME_QUIT,
   GAME_TO_MENU
};

struct game {
   enum game_state state;
   enum menu_difficulty difficulty;
   struct spritesheet *earth;
   struct spritesheet *space_player;
   struct chrono *chrono;
   struct obstacle *obstacles;
   int obstacle_radius_update;
   int player_degree;
   int obstacles_size;
   bool space_mode;
   bool right_down;
   bool left_down;
   bool menu_selected;
   Uint32 obstacle_creation_interval;
   Uint32 start_time;
   Uint32 last_creation_time;
   Uint32 score;
   Mix_Music *game_music;
   Mix_Music *game_over_music;
   Mix_Chunk *select_sound;
   SDL_Renderer *renderer;
};

/**
 * Cette fonction permet d'allouer dynamiquement une nouvelle structure game et 
 * initialise ses attributs.
 *
 * @param SDL_Renderer *renderer : le renderer sur lequel seront affiche la scene de la partie
 */
struct game *game_initialize(SDL_Renderer *renderer);

/**
 * Cette fonction permet de mettre a jour les attributs difficulty et space_mode
 * selon les choix fais dans le menu.
 *
 * @param struct game *game : la partie de circles a mettre a jour
 *
 * @param enum menu_difficulty difficulty : la difficulte choisie dans le menu
 *
 * @param bool space_mode : la valeur du space_mode choisie dans le menu
 */
void game_set_difficulty(struct game *game, enum menu_difficulty difficulty, bool space_mode);

/**
 * Cette fonction permet d'executer la boucle de retroaction du jeu circles, et ainsi
 * jouer au jeu.
 *
 * @param struct game *game : la partie de circles
 */
void game_run(struct game *game);

/**
 * Cette fonction permet la desallocation de la memoire allouee pour une struct game.
 *
 * @param struct game *game : la partie de circles a desallouer
 */
void game_delete(struct game *game);

#endif
