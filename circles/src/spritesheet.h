/**
 *
 * spritesheet
 * 
 * @author inconnu (spritesheet_render_rotation fait par Louis-Olivier Beaulieu)
 * @description Ce module contient les fonctions et structure permettant la 
 * modelisation d'un sprite sheet.
 */

#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include "sdl2.h"

struct spritesheet {
   int num_rows;
   int num_columns;
   int num_sprites;
   int sprite_width;
   int sprite_height;
   float scale;
   SDL_Texture *texture;
   SDL_Renderer *renderer;
};

/**
 * Cette fonction permet la creation d'une struct spritesheet. La struct creee doit etre
 * desallouee avec la fonction delete_spritesheet.
 *
 * @param const char *filename : le chemin vers le fichier contenant le sprite sheet
 *
 * @param int num_rows : le nombre de lignes du sprite sheet
 *
 * @param int num_columns : le nombre de colonnes du sprite sheet
 *
 * @param int num_sprites : le nombre total de sprite dans le sprite sheet
 *
 * @param SDL_renderer *renderer : le renderer qui sera affecte a la struct sprite sheet
 *
 * @return la struct spritesheet allouee
 */
struct spritesheet *spritesheet_create(const char *filename, int num_rows, int num_columns,
   int num_sprites, SDL_Renderer* renderer);

/**
 * Cette fonction permet la desallocation d'une struct spritesheet.
 *
 * @param struct spritesheet *spritesheet : le spritesheet a desallouer
 */
void spritesheet_delete(struct spritesheet *spritesheet);

/**
 * Cette fonction permet de render un sprite.
 *
 * @param struct spritesheet *spritesheet : le spritesheet a render
 *
 * @param int x : la position x du coin superieur gauche du sprite a render
 *
 * @param int y : la position y du coin superieur gauche du sprite a render
 *
 * @param int alpha : la transparence du sprite a render
 *
 * @param int sprite : l'indice du sprite a render
 */
void spritesheet_render(struct spritesheet *spritesheet, int x, int y, int alpha, int sprite);

/**
 * Cette fonction permet de render un sprite avec une rotation.
 *
 * @param struct spritesheet *spritesheet : le spritesheet a render
 *
 * @param int x : la position x du coin superieur gauche du sprite a render
 *
 * @param int y : la position y du coin superieur gauche du sprite a render
 *
 * @param int alpha : la transparence du sprite a render
 *
 * @param int sprite : l'indice du sprite a render
 *
 * @param double angle : l'angle de rotation a appliquer au sprite a render
  *
 * @param SDL_Point *rot_point : le point de rotation relativement au coin superieur gauche du sprite
 */
void spritesheet_render_rotation(struct spritesheet *spritesheet, int x, int y, int alpha, int sprite, 
   double angle, SDL_Point *rot_point);
#endif
