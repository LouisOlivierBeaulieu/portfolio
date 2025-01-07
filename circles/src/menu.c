#include "menu.h"

/**
 * Cette fonction auxiliaire permet de mettre a jour les variables du menu
 * affectes par des evenements (interrupts).
 *
 * @param struct menu *menu : le menu dont les attributs doivent etre modifie apres un evenement.
 */
void menu_event_loop(struct menu *menu);

/**
 * Cette fonction auxiliaire permet de mettre a jour les bonnes variables lorsque
 * la touche fleche gauche est appuyee.
 *
 * @param struct menu *menu : le menu dont les attributs doivent etre modifie apres un evenement.
 */
void menu_event_key_left(struct menu *menu);

/**
 * Cette fonction auxiliaire permet de mettre a jour les bonnes variables lorsque
 * la touche fleche droite est appuyee.
 *
 * @param struct menu *menu : le menu dont les attributs doivent etre modifie apres un evenement.
 */
void menu_event_key_right(struct menu *menu);

/**
 * Cette fonction auxiliaire permet de mettre a jour la valeur de la variable de 
 * selection de la difficulte.
 *
 * @param struct menu *menu : le menu dont la variable de selection de difficulte 
 * doit etre mis a jour
 */
void menu_select_difficulty(struct menu *menu);

/**
 * Cette fonction auxiliaire permet de mettre a jour les bonnes variables lorsque
 * la touche return (entree) est appuyee.
 *
 * @param struct menu *menu : le menu dont les attributs doivent etre modifie apres un evenement.
 */
void menu_event_key_return(struct menu *menu);

/**
 * Cette fonction auxiliaire retourne une valeur d'opacite d'un sprite selon la 
 * valeur de verite du booleen passe en parametre qui represente l'etat du sprite.
 *
 * @param bool chosen : le booleen qui represente l'etat d'un sprite
 *
 * @return l'opacite du sprite. 255 si chosen est vrai, 64 sinon
 */
int menu_alpha(bool chosen);

/**
 * Cette fonction auxiliaire permet d'afficher le menu.
 *
 * @param struct menu *menu : le menu contenant le renderer ou render le menu
 */
void menu_draw_frame(struct menu *menu);

/**
 * Cette fonction auxiliaire permet de render les sprites qui font partie du menu.
 *
 * @param struct menu *menu : le menu contenant le renderer ou render les sprites
 */
void menu_draw_sprites(struct menu *menu);

/**
 * Cette fonction auxiliaire permet de render le text correspondant a la selection
 * du mode espace (space mode).
 *
 * @param struct menu *menu : le menu contenant le renderer ou render le texte
 */
void menu_draw_space_mode(struct menu *menu);

struct menu *menu_initialize(SDL_Renderer *renderer) {
   struct menu *menu;
   menu = malloc(sizeof(struct menu));
   menu->renderer = renderer;
   menu->state = MENU_PLAY_FOCUS;
   menu->background = spritesheet_create(BACKGROUND_FILENAME, 1, 1, 1, renderer);
   menu->title = spritesheet_create(TITLE_FILENAME, 1, 1, 1, renderer);
   menu->play = spritesheet_create(PLAY_FILENAME, 1, 1, 1, renderer);
   menu->quit = spritesheet_create(QUIT_FILENAME, 1, 1, 1, renderer);
   menu->difficulty_title = spritesheet_create(DIFFICULTY_FILENAME, 1, 1, 1, renderer);
   menu->easy = spritesheet_create(EASY_FILENAME, 1, 1, 1, renderer);
   menu->medium = spritesheet_create(MEDIUM_FILENAME, 1, 1, 1, renderer);
   menu->hard = spritesheet_create(HARD_FILENAME, 1, 1, 1, renderer);
   menu->difficulty = EASY;
   menu->space_mode = false;
   menu->music = Mix_LoadMUS(MENU_MUSIC);
   menu->select_sound = Mix_LoadWAV(SELECT_SOUND);
   if(!menu->music || !menu->select_sound) {
      printf("Music could not be loaded : %s\n", Mix_GetError());
      return NULL;
   }
   return menu;
}

int menu_alpha(bool chosen) {
   return chosen ? 255 : 64;
}

void menu_run(struct menu *menu) {
   menu->state = MENU_PLAY_FOCUS;
   menu->selecting_difficulty = false;
   Mix_FadeInMusicPos(menu->music, -1, 5000, 35.0);
   while(menu->state != MENU_PLAY && menu->state != MENU_QUIT) {
      menu_event_loop(menu);
      menu_draw_frame(menu);
   }
   Mix_PauseMusic();
}

void menu_event_loop(struct menu *menu) {
   SDL_Event e;
   while(SDL_PollEvent(&e) != 0) {
      if(e.type == SDL_QUIT) {
         menu->state = MENU_QUIT;
      } else if(e.type == SDL_KEYDOWN) {
         switch(e.key.keysym.sym) {
            case SDLK_LEFT:
               menu_event_key_left(menu); break;
            case SDLK_RIGHT:
               menu_event_key_right(menu); break;
            case SDLK_DOWN:
               menu_select_difficulty(menu); break;
            case SDLK_UP:
               menu_select_difficulty(menu); break;
            case SDLK_e:
               menu->difficulty = EASY;
               Mix_PlayChannel(-1, menu->select_sound, 0);
               break;
            case SDLK_m:
               menu->difficulty = MEDIUM;
               Mix_PlayChannel(-1, menu->select_sound, 0);
               break;
            case SDLK_h:
               menu->difficulty = HARD;
               Mix_PlayChannel(-1, menu->select_sound, 0);
               break;
            case SDLK_s:
               menu->space_mode = !menu->space_mode;
               Mix_PlayChannel(-1, menu->select_sound, 0);
               break;
            case SDLK_RETURN:
               menu_event_key_return(menu); break;
         }
      }
   }   
}

void menu_event_key_left(struct menu *menu) {
   if(menu->selecting_difficulty)
      menu->difficulty = menu->difficulty == EASY ? HARD :
         menu->difficulty == HARD ? MEDIUM : EASY;
   else
      menu->state = menu->state == MENU_PLAY_FOCUS ? 
         MENU_QUIT_FOCUS : MENU_PLAY_FOCUS;
   Mix_PlayChannel(-1, menu->select_sound, 0);
}

void menu_event_key_right(struct menu *menu) {
   if(menu->selecting_difficulty)
      menu->difficulty = menu->difficulty == EASY ? MEDIUM :
         menu->difficulty == MEDIUM ? HARD : EASY;
   else
      menu->state = menu->state == MENU_PLAY_FOCUS ? 
         MENU_QUIT_FOCUS : MENU_PLAY_FOCUS;
   Mix_PlayChannel(-1, menu->select_sound, 0);
}

void menu_select_difficulty(struct menu *menu) {
   menu->selecting_difficulty = !menu->selecting_difficulty;
   Mix_PlayChannel(-1, menu->select_sound, 0);
}

void menu_event_key_return(struct menu *menu) {
   if(menu->state == MENU_PLAY_FOCUS)
      menu->state = MENU_PLAY;
   else if(menu->state == MENU_QUIT_FOCUS)
      menu->state = MENU_QUIT;
   Mix_PlayChannel(-1, menu->select_sound, 0);
}

void menu_draw_frame(struct menu *menu) {
   SDL_SetRenderDrawColor(menu->renderer, 0x00, 0x00, 0x00, 0x00 );
   SDL_RenderClear(menu->renderer);
   menu_draw_sprites(menu);
   menu_draw_space_mode(menu);
   SDL_RenderPresent(menu->renderer);
}

void menu_draw_sprites(struct menu *menu) {
   spritesheet_render(menu->background, BACKGROUND_X, BACKGROUND_Y, 255, 0);
   spritesheet_render(menu->title, TITLE_X, TITLE_Y, 255, 0);
   spritesheet_render(menu->play, PLAY_X, PLAY_Y, menu_alpha(menu->state == MENU_PLAY_FOCUS), 0);
   spritesheet_render(menu->quit, QUIT_X, QUIT_Y, menu_alpha(menu->state == MENU_QUIT_FOCUS), 0);
   spritesheet_render(menu->difficulty_title, DIFFICULTY_X, DIFFICULTY_Y, 
      menu_alpha(menu->selecting_difficulty), 0);
   spritesheet_render(menu->easy, EASY_X, EASY_Y, menu_alpha(menu->difficulty == EASY), 0);
   spritesheet_render(menu->medium, MEDIUM_X, MEDIUM_Y, menu_alpha(menu->difficulty == MEDIUM), 0);
   spritesheet_render(menu->hard, HARD_X, HARD_Y, menu_alpha(menu->difficulty == HARD), 0); 
}

void menu_draw_space_mode(struct menu *menu) {
   if(menu->space_mode) {
      struct text space_mode_text = {GAME_FONT, "SPACE MODE (s): ON", 20, 
         SPACE_MODE_X, SPACE_MODE_Y, {SPACE_MODE_ON_COLOR}};
      text_render(menu->renderer, space_mode_text);
   } else {
      struct text space_mode_text = {GAME_FONT, "SPACE MODE (s): OFF", 20, 
         SPACE_MODE_X, SPACE_MODE_Y, {SPACE_MODE_OFF_COLOR}};
      text_render(menu->renderer, space_mode_text);
   }
}

void menu_delete(struct menu *menu) {
   if(menu != NULL) {
      spritesheet_delete(menu->background);
      spritesheet_delete(menu->title);
      spritesheet_delete(menu->play);
      spritesheet_delete(menu->quit);
      spritesheet_delete(menu->difficulty_title);
      spritesheet_delete(menu->easy);
      spritesheet_delete(menu->medium);
      spritesheet_delete(menu->hard); 
      Mix_FreeMusic(menu->music);
      Mix_FreeChunk(menu->select_sound);        
      free(menu);
      menu = NULL;
   }
}
