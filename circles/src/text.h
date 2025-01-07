/**
 *
 * text
 * 
 * @author Louis-Olivier Beaulieu
 * @description Ce module contient les fonctions et structure permettant
 * la modelisation et l'affichage de texte avec SDL_ttf.
 */

#ifndef TEXT_H
#define TEXT_H

#include "sdl2.h"

struct text {
   const char *font_file;
   const char *content;
   int size;
   int x;
   int y;
   SDL_Color color;
};

/**
 * Cette fonction permet de render du texte sur un renderer a partir d'une struct text.
 *
 * @param SDL_Renderer * renderer : le renderer a utiliser
 *
 * @param struct text : le text a render
 */
void text_render(SDL_Renderer * renderer, struct text);

#endif
