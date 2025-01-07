/**
 *
 * shape
 * 
 * @author Louis-Olivier Beaulieu
 * @description Ce module contient les fonctions et structure permettant le render
 * de differente formes utiles pour la modelisation du jeu circles.
 */

#ifndef SHAPE_H
#define SHAPE_H

#include "sdl2.h"
#include "constants.h"
#include <math.h>

struct obstacle {
   Sint16 radius;
   Sint16 start;
   Sint16 end;
   Uint8 bg_r;
   Uint8 bg_g;
   Uint8 bg_b;
   Uint8 bg_a;
};

/**
 * Cette fonction permet de render une etoile selon sa position et sa taille (largeur/hauteur).
 *
 * @param SDL_Renderer *renderer : le renderer ou render l'etoile
 *
 * @param int x1 : la position x du coin superieur gauche du corps de l'etoile
 *
 * @param int y1 : la position y du coin superieur gauche du corps de l'etoile
 *
 * @param int x2 : la position x du coin inferieur droit du corps de l'etoile
 *
 * @param int y2 : la position y du coin inferieur droit du corps de l'etoile
 *
 * @param int heigth : la hauteur d'un pointe verticale de l'etoile
 *
 * @param int width : la largeur d'une pointe horizontale de l'etoile
 */
void render_star(SDL_Renderer *renderer, int x1, int y1, int x2, int y2, int heigth, int width);

/**
* Cette fonction permet de render un obstacle du jeu circles.
*
* @param SDL_Renderer *renderer : le renderer ou render l'obstacle
*
* @param struct obstacle obstacle : l'obstacle a render
*/
void render_obstacle(SDL_Renderer *renderer, struct obstacle obstacle);

/**
* Cette fonction permet de render le joueur du jeu circles.
*
* @param SDL_Renderer *renderer : le renderer ou render le joueur
*
* @param double player_degree : la position du joueur
*/
void render_player(SDL_Renderer *renderer, double player_degree);

#endif
