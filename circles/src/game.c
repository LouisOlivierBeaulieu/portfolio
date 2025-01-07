#include "game.h"

/**
 * Cette fonction auxiliaire permet d'allouer dynamiquement une nouvelle structure chrono
 * etant attribut d'une struct game.
 *
 * @param struct game *game : la partie de circles ou creer le chrono
 */
struct chrono *game_initialize_chrono(struct game *game);

/**
 * Cette fonction auxiliaire permet de reset les attributs d'une partie de circles avant
 * de debuter celle-ci
 *
 * @param struct game *game : la partie dont certains attributs doivent etre reset 
 * avant le debut de la partie
 */
void game_reset(struct game *game);

/**
 * Cette fonction auxiliaire permet de mettre a jour les variables de jeu
 * affectes par des evenements (interrupts).
 *
 * @param struct game *game : la partie dont certains attributs doivent etre mis a jour apres un 
 * evenement
 */
void game_event_loop(struct game *game);

/**
 * Cette fonction auxiliaire permet de mettre a jour une frame du jeu circles et de l'afficher
 *
 * @param struct game *game : la partie dont la prochaine frame doit etre mis a jour et affichee
 */
void game_run_frame(struct game *game);

/**
 * Cette fonction auxiliaire permet de declancher la boucle de fin de partie, qui se termine lorsque 
 * l'utilisateur choisi un action.
 *
 * @param struct game *game : la partie de circles finie
 */
void game_over_loop(struct game *game);

/**
 * Cette fonction auxiliaire permet de declancher la boucle d'attente d'evenement
 * losrque la partie est finie.
 *
 * @param struct game *game : la partie de circles finie
 */
void game_over_event_loop(struct game *game);

/**
 * Cette fonction auxiliaire permet de selectionner ou deselectionner le menu en fin de partie.
 * 
 * @param struct game *game : la partie ou le menu est selectionne ou deselectionne
 *
 * @param bool menu_selected : l'ancienne valeur de selection du menu
 *
 * @return vrai si le menu est selectionne, faux sinon
 */
void game_select_menu(struct game *game);

/**
 * Cette fonction auxiliaire permet d'afficher la scene de fin de partie
 *
 * @param struct game *game : la partie de circles finie
 *
 * @param bool menu_selected : la valeur de verite de selection du texte de retour
 * au menu
 */
void game_draw_game_over_scene(struct game *game);

/**
 * Cette fonction auxiliaire permet d'afficher le texte de fin de partie et le score.
 *
 * @param struct game *game : la partie de circles finie
 */
void game_draw_game_over_title(struct game *game);

/**
 * Cette fonction auxiliaire permet d'afficher le texte de retour au menu
 *
 * @param struct game *game : la partie de circles finie
 *
 * @param bool selected : la valeur de verite de selection du texte de retour
 * au menu
 */
void game_draw_back_to_menu(struct game *game);

/**
 * Cette fonction auxiliaire permet d'afficher le texte de sortie du jeu
 *
 * @param struct game *game : la partie de circles finie
 *
 * @param bool selected : la valeur de verite de selection du texte de sortie du jeu
 */
void game_draw_quit(struct game *game);

/**
 * Cette fonction auxiliaire permet de creer un nouvel obstacle aleatoirement.
 *
 * @param struct game *game : la partie de circles ou creer un nouvel obstacle
 */
void game_create_obstacle(struct game *game);

/**
 * Cette fonction auxiliaire permet de creer et ajouter un nouvel obstacle dans le
 * tableau des obstacles de la partie passee en parametre.
 *
 * @param struct game *game : la partie de circles ou creer un nouvel obstacle
 *
 * @param struct Sint16 start : le degree de debut du rayon de l'obstacle
 *
 * @param struct Sint16 end : le degree de fin du rayon de l'obstacle
 *
 * @param struct  Uint8 bg_r : la valeur de rouge de la couleur qui couvre l'obstacle
 *
 * @param struct Uint8 bg_g : la valeur de vert de la couleur qui couvre l'obstacle
 *
 * @param struct Uint8 bg_b : la valeur de bleu de la couleur qui couvre l'obstacle
 *
 * @param struct Uint8 bg_a : la valeur d'opacite de la couleur qui couvre l'obstacle
 */
void game_append_obstacle(struct game *game, Sint16 start, Sint16 end, Uint8 bg_r, Uint8 bg_g,
   Uint8 bg_b, Uint8 bg_a);

/**
 * Cette fonction auxiliaire permet de trouver le temps ecoule depuis le lancement de la partie.
 *
 * @param struct game *game : la partie de circles ou creer un nouvel obstacle
 *
 * @return le temps ecoule depuis le lancement de la partie (Uint32, un entier non-signe de 32 bits)
 */
Uint32 game_get_time_elapsed(struct game *game);

/**
 * Cette fonction auxiliaire permet de mettre a jour le rayon des obstacles contenues dans
 * le tableau d'obstacles d'une partie.
 *
 * @param struct game *game : la partie de circles ou mettre a jour les obstacles
 */
void game_update_obstacles(struct game *game);

/**
 * Cette fonction auxiliaire permet de supprimer un obstacle contenue dans
 * le tableau d'obstacles d'une partie. Le tableau est reajuster pour ne pas laisser
 * d'espaces vide.
 *
 * @param struct game *game : la partie de circles ou supprimer un obstacle
 *
 * @param int obstacle_index : l'index de l'obstacle a retirer
 */
void game_remove_obstacle(struct game *game, int obstacle_index);

/**
 * Cette fonction auxiliaire permet de verifier si un collision a eu lieu entre un obstacle et
 * le joueur. Un collision est considéré si l'angle du joueur est compris dans l'arc de cercle<
 * de l'obstacle.
 *
 * @param struct game *game : la partie de circles ou supprimer un obstacle
 *
 * @param int obstacle_index : l'index de l'obstacle a verifier
 *
 * @return Vrai si le joueur est en collision avec l'obstacle, faux sinon
 */
bool game_collision(struct game *game, int obstacle_index);

/**
 * Cette fonction auxiliaire permet de normaliser un angle en degres entre -infini et +infini
 * en un angle en degres entre 0 et 359.
 *
 * @param int degree : l'angle a normaliser
 *
 * @return l'angle en degres normalise
 */
int get_normalised_degree(int degree);


/**
 * Cette fonction auxiliaire permet d'appeler la fonction de dessin de fond appropriee et affiche 
 * le resultat d'un tour de boucle de retroaction du jeu.
 *
 * @param struct game *game : la partie de circles ou afficher l'instance du jeu
 */
void game_draw_frame(struct game *game);

/**
 * Cette fonction auxiliaire permet de render l'image de jeu en mode normal.
 *
 * @param struct game *game : la partie de circles ou afficher l'image du jeu
 */
void game_draw_background(struct game *game);

/**
 * Cette fonction auxiliaire permet de render l'image de jeu en mode 
 * 'space' (space_mode).
 *
 * @param struct game *game : la partie de circles ou afficher l'image du jeu
 */
void game_draw_space_background(struct game *game);

/**
 * Cette fonction auxiliaire permet de render le joueur selon sa position.
 *
 * @param struct game *game : la partie de circles ou afficher le joueur
 */
void game_draw_player(struct game *game);

/**
 * Cette fonction auxiliaire permet de render plusieurs etoile pour l'image du 
 * jeu en mode 'space' (space_mode).
 *
 * @param struct game *game : la partie de circles ou afficher l'image du jeu
 */
void game_draw_stars(struct game *game);

/**
* Cette fonction auxiliaire permet de render les obstacles actifs dans le jeu.
 *
 * @param struct game *game : la partie de circles ou afficher les obstacles actifs
 */
void game_draw_obstacles(struct game *game);

/**
 * Cette fonction auxiliaire permet de render le cercle au centre de l'image du jeu.
 *
 * @param struct game *game : la partie de circles ou afficher les obstacles actifs
 */
void game_draw_center(struct game *game);

/**
 * Cette fonction auxiliaire permet la desallocation de la memoire allouee pour une struct chrono.
 *
 * @param struct game *game : la partie de circles ou desallouer l'attribut chrono
 */
void chrono_delete(struct chrono *chrono);

struct game *game_initialize(SDL_Renderer *renderer) {
   struct game *game = calloc(1, sizeof(struct game));
   if(game) {
      game->earth = spritesheet_create(EARTH_FILENAME, 1, 1, 1, renderer);
      game->space_player = spritesheet_create(PLAYER_FILENAME, 1, 1, 1, renderer);
      game->obstacles = calloc(MAX_OBSTACLES, sizeof(struct obstacle));
      if(!game->obstacles)
         return NULL;
      game->renderer = renderer;
      game->game_music = Mix_LoadMUS(GAME_MUSIC);
      game->game_over_music = Mix_LoadMUS(GAME_OVER_MUSIC);
      game->select_sound = Mix_LoadWAV(SELECT_SOUND);
      if(!game->game_music || !game->game_over_music || !game->select_sound) {
         printf("Music could not be loaded : %s\n", Mix_GetError());
         return NULL;
      }
      game->chrono = chrono_create(renderer);
      if(!game->chrono) {
         return NULL;
      }
   }
   return game;
}

void game_set_difficulty(struct game *game, enum menu_difficulty difficulty, bool space_mode) {
   game->difficulty = difficulty;
   game->space_mode = space_mode;
   game->obstacle_creation_interval = difficulty == EASY ? EASY_OBS_CREATION_INTERVAL :
      difficulty == MEDIUM ? MEDIUM_OBS_CREATION_INTERVAL : HARD_OBS_CREATION_INTERVAL;
   game->obstacle_radius_update = difficulty == EASY ? EASY_OBS_RADIUS_UPDATE :
      difficulty == MEDIUM ? MEDIUM_OBS_RADIUS_UPDATE : HARD_OBS_RADIUS_UPDATE;
}

void game_run(struct game *game) {
   game_reset(game);
   game->last_creation_time = 0;
   Mix_PlayMusic(game->game_music, -1);
   while(game->state != GAME_QUIT && game->state != GAME_TO_MENU) {
      game_event_loop(game);
      game_run_frame(game);
      if(game->state == GAME_OVER)
         game_over_loop(game);
   }
}

void game_event_loop(struct game *game) {
   SDL_Event e;
   while(SDL_PollEvent(&e) != 0) {
      if(e.type == SDL_QUIT) {
         game->state = GAME_QUIT;
      } else if(e.type == SDL_KEYDOWN) {
         switch(e.key.keysym.sym) {
            case SDLK_LEFT:
               game->left_down = true;
               break;
            case SDLK_RIGHT:
               game->right_down = true;
               break;
         }
      } else if(e.type == SDL_KEYUP) {
         switch(e.key.keysym.sym) {
            case SDLK_LEFT:
               game->left_down = false;
               break;
            case SDLK_RIGHT:
               game->right_down = false;
               break;
         }
      }
   }
}

void game_run_frame(struct game *game) {
   game->player_degree += game->left_down ? 
      -PLAYER_DEGREE_INCR : game->right_down ? PLAYER_DEGREE_INCR : 0;
   if(game_get_time_elapsed(game) - game->last_creation_time >= game->obstacle_creation_interval &&
      game->obstacles_size < MAX_OBSTACLES) {
      game_create_obstacle(game);
      game->last_creation_time = game_get_time_elapsed(game);
   }
   game_update_obstacles(game);
   game_draw_frame(game);
}

void game_reset(struct game *game) {
   srand(time(NULL));
   game->state = GAME_PLAYING;
   game->obstacles_size = 0;
   game->player_degree = 0;
   game->start_time = SDL_GetTicks();
   game->score = 0;
   game->menu_selected = true;
   game->right_down = false;
   game->left_down = false;
}

void game_over_loop(struct game *game) {
   Mix_FadeInMusicPos(game->game_over_music, -1, 5000, 55.0);
   game->score = game_get_time_elapsed(game);
   while(game->state != GAME_QUIT && game->state != GAME_TO_MENU) {
      game_over_event_loop(game);
      game_draw_game_over_scene(game);
   }
}

void game_over_event_loop(struct game *game) {
   SDL_Event e;
   while(SDL_PollEvent(&e) != 0) {
      if(e.type == SDL_QUIT) {
         game->state = GAME_QUIT;
      } else if(e.type == SDL_KEYDOWN) {
         switch(e.key.keysym.sym) {
            case SDLK_LEFT:
               game_select_menu(game);
               break;
            case SDLK_RIGHT:
               game_select_menu(game);
               break;
            case SDLK_RETURN:
               game->state = game->menu_selected ? GAME_TO_MENU : GAME_QUIT;
               Mix_PlayChannel(-1, game->select_sound, 0);
               break;
         }
      }
   }
}

void game_select_menu(struct game *game) {
   game->menu_selected = !game->menu_selected;
   Mix_PlayChannel(-1, game->select_sound, 0);
}

void game_draw_game_over_scene(struct game *game) {
   game_draw_back_to_menu(game);
   game_draw_quit(game);
   game_draw_game_over_title(game);
   SDL_RenderPresent(game->renderer);
}

void game_draw_game_over_title(struct game *game) {
   char score[16];
   sprintf(score, "SCORE : %d%d.%d%d.%d", game->chrono->decaminutes, game->chrono->minutes, 
      game->chrono->decaseconds,  game->chrono->seconds,  game->chrono->deciseconds);
   SDL_Color color = {TEXT_COLOR};
   SDL_Color space_color = {SPACE_TEXT_COLOR};
   struct text game_over_text = {GAME_FONT, GAME_OVER_TITLE, 50, CENTER_X, 100, 
      game->space_mode ? space_color : color};
   text_render(game->renderer, game_over_text);
   struct text score_text = {GAME_FONT, score, 30, CENTER_X, 200, 
      game->space_mode ? space_color : color};
   text_render(game->renderer, score_text);
}

void game_draw_back_to_menu(struct game *game) {
   SDL_Color selected_color = {TEXT_COLOR};
   SDL_Color unselected_color = {UNSELECTED_COLOR};
   SDL_Color space_selected_color = {SPACE_TEXT_COLOR};
   SDL_Color space_unselected_color = {SPACE_UNSELECTED_COLOR};
   struct text menu_text = {GAME_FONT, BACK_TO_MENU_TITLE, 50, CENTER_X - 200, CENTER_Y + 150, 
      game->space_mode ? 
      game->menu_selected ? space_selected_color : space_unselected_color :
      game->menu_selected ? selected_color : unselected_color};
   text_render(game->renderer, menu_text);
}

void game_draw_quit(struct game *game) {
   SDL_Color selected_color = {TEXT_COLOR};
   SDL_Color unselected_color = {UNSELECTED_COLOR};
   SDL_Color space_selected_color = {SPACE_TEXT_COLOR};
   SDL_Color space_unselected_color = {SPACE_UNSELECTED_COLOR};
   struct text quit_text = {GAME_FONT, QUIT_TITLE, 50, CENTER_X + 200, CENTER_Y + 150, 
      game->space_mode ? 
      !game->menu_selected ? space_selected_color : space_unselected_color :
      !game->menu_selected ? selected_color : unselected_color};
   text_render(game->renderer, quit_text);
}

void game_create_obstacle(struct game *game) {
   int random_number = rand() % 6;
   switch(random_number) {
      case 0:
         game->space_mode ? game_append_obstacle(game, TOP_LEFT_OBSTACLE, BG_SPACE_COLOR) :
            game_append_obstacle(game, TOP_LEFT_OBSTACLE, BG_WHITE_COLOR); break;
      case 1:
         game->space_mode ? game_append_obstacle(game, TOP_OBSTACLE, BG_SPACE_COLOR) :
            game_append_obstacle(game, TOP_OBSTACLE, BG_GREY_COLOR); break;
      case 2:
         game->space_mode ? game_append_obstacle(game, TOP_RIGHT_OBSTACLE, BG_SPACE_COLOR) :
            game_append_obstacle(game, TOP_RIGHT_OBSTACLE, BG_WHITE_COLOR); break;
      case 3:
         game->space_mode ? game_append_obstacle(game, BOTTOM_RIGHT_OBSTACLE, BG_SPACE_COLOR) :
            game_append_obstacle(game, BOTTOM_RIGHT_OBSTACLE, BG_GREY_COLOR); break;
      case 4:
         game->space_mode ? game_append_obstacle(game, BOTTOM_OBSTACLE, BG_SPACE_COLOR) :
            game_append_obstacle(game, BOTTOM_OBSTACLE, BG_WHITE_COLOR); break;
      case 5:
         game->space_mode ? game_append_obstacle(game, BOTTOM_LEFT_OBSTACLE, BG_SPACE_COLOR) :
            game_append_obstacle(game, BOTTOM_LEFT_OBSTACLE, BG_GREY_COLOR); break;
   }
}

void game_append_obstacle(struct game *game, Sint16 start, Sint16 end, Uint8 bg_r, Uint8 bg_g,
   Uint8 bg_b, Uint8 bg_a) {
   game->obstacles_size++;
   struct obstacle obstacle = {MAX_RADIUS, start, end, bg_r, bg_g, bg_b, bg_a};
   game->obstacles[game->obstacles_size - 1] = obstacle;
}

Uint32 game_get_time_elapsed(struct game *game) {
   return SDL_GetTicks() - game->start_time;
}

void game_update_obstacles(struct game *game) {
   for(int i = 0; i < game->obstacles_size; i++) {
      game->obstacles[i].radius -= game->obstacle_radius_update;
      if(game->obstacles[i].radius < MIN_RADIUS) {
         game_remove_obstacle(game, i);
         i--;
      } else if(game->obstacles[i].radius <= DEATH_RADIUS) {
         if(game_collision(game, i)) {
            game->state = GAME_OVER;
            return;
         }
      }
   }
}

void game_remove_obstacle(struct game *game, int obstacle_index) {
   for(int i = obstacle_index; i < game->obstacles_size - 1; i++) {
      game->obstacles[i] = game->obstacles[i + 1];
   }
   game->obstacles_size--;
}

bool game_collision(struct game *game, int obstacle_index) {
   int normalised_degree = get_normalised_degree(game->player_degree);
   return game->obstacles[obstacle_index].end == 55 ? 
      (normalised_degree >= game->obstacles[obstacle_index].start && 
      normalised_degree < 360) || (normalised_degree >= 0 &&
      normalised_degree <= game->obstacles[obstacle_index].end) :
      normalised_degree >= game->obstacles[obstacle_index].start && 
      normalised_degree <= game->obstacles[obstacle_index].end;
}


int get_normalised_degree(int degree) {
   return degree >= 360 ? degree - 360 * (degree / 360) : degree < 0 ? 
      degree + 360 * (1 + abs(degree / 360)) : degree;
}

void game_draw_frame(struct game *game) {
   game->space_mode ? game_draw_space_background(game) : game_draw_background(game);
   game_draw_obstacles(game);
   game_draw_center(game);
   game_draw_player(game);
   if(game->space_mode)
      game_draw_stars(game);
   if(game_get_time_elapsed(game) <= MAX_SCORE)
      chrono_update(game->chrono, game_get_time_elapsed(game));
   chrono_render(game->chrono);
   SDL_RenderPresent(game->renderer);
}

void game_draw_background(struct game *game) {
   SDL_SetRenderDrawColor(game->renderer, BG_SPACE_COLOR);
   SDL_RenderClear(game->renderer);
   filledPieRGBA(game->renderer, CENTER_X, CENTER_Y, 700, TOP_LEFT_OBSTACLE, BG_WHITE_COLOR);
   filledPieRGBA(game->renderer, CENTER_X, CENTER_Y, 500, TOP_OBSTACLE, BG_GREY_COLOR);
   filledPieRGBA(game->renderer, CENTER_X, CENTER_Y, 700, TOP_RIGHT_OBSTACLE, BG_WHITE_COLOR);
   filledPieRGBA(game->renderer, CENTER_X, CENTER_Y, 700, BOTTOM_RIGHT_OBSTACLE, BG_GREY_COLOR);
   filledPieRGBA(game->renderer, CENTER_X, CENTER_Y, 500, BOTTOM_OBSTACLE, BG_WHITE_COLOR);
   filledPieRGBA(game->renderer, CENTER_X, CENTER_Y, 700, BOTTOM_LEFT_OBSTACLE, BG_GREY_COLOR);
}

void game_draw_space_background(struct game *game) {
   SDL_SetRenderDrawColor(game->renderer, BG_SPACE_COLOR);
   SDL_RenderClear(game->renderer);
}

void game_draw_player(struct game *game) {
   if(game->space_mode) {
      SDL_Point center = {PLAYER_SPACE_ROT_X, PLAYER_SPACE_ROT_Y};
      spritesheet_render_rotation(game->space_player, PLAYER_SPACE_X, PLAYER_SPACE_Y,
         0xff, 0, game->player_degree, &center);
   }
   else
      render_player(game->renderer, game->player_degree);
}

void game_draw_stars(struct game *game) {
   render_star(game->renderer, 100, 100, 102, 102, SMALL_STAR);
   render_star(game->renderer, 900, 400, 902, 402, SMALL_STAR);
   render_star(game->renderer, 400, 700, 402, 702, SMALL_STAR);
   render_star(game->renderer, 170, 230, 176, 236, MEDIUM_STAR);
   render_star(game->renderer, 150, 650, 156, 656, MEDIUM_STAR);
   render_star(game->renderer, 800, 600, 806, 606, MEDIUM_STAR);
   render_star(game->renderer, 680, 330, 686, 336, MEDIUM_STAR);
   render_star(game->renderer, 850, 130, 856, 136, BIG_STAR);
   render_star(game->renderer, 240, 460, 246, 466, BIG_STAR);
   render_star(game->renderer, 350, 180, 356, 186, BIG_STAR);
   render_star(game->renderer, 500, 630, 506, 636, BIG_STAR);
}

void game_draw_obstacles(struct game *game) {
   for(int i = game->obstacles_size - 1; i >= 0; i--)
      render_obstacle(game->renderer, game->obstacles[i]);
}

void game_draw_center(struct game *game) {
   game->space_mode ?
      spritesheet_render(game->earth, CENTER_X - CENTER_RADIUS, CENTER_Y - CENTER_RADIUS, 0xff, 0) :
      filledCircleRGBA(game->renderer, CENTER_X, CENTER_Y, CENTER_RADIUS, CENTER_COLOR);
}

void game_delete(struct game *game) {
   if(game != NULL) {
      spritesheet_delete(game->earth);
      spritesheet_delete(game->space_player);
      chrono_delete(game->chrono);
      free(game->obstacles);
      Mix_FreeMusic(game->game_music);
      Mix_FreeMusic(game->game_over_music);
      Mix_FreeChunk(game->select_sound);
      free(game);
      game = NULL;
   }
}
