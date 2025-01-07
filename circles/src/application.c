#include "application.h"

/**
 * Cette fonction auxilaire permet l'initialisation du la lib sdl
 *
 * @return true si l'initialisation c'est deroulee sans erreur, false sinon
 */
bool sdl_init(void);

/**
 * Cette fonction auxilaire permet l'initialisation de la lib sdl_ttf
 *
 * @return true si l'initialisation c'est deroulee sans erreur, false sinon
 */
bool ttf_init(void);

/**
 * Cette fonction auxilaire permet l'initialisation de la lib sdl_image
 *
 * @return true si l'initialisation c'est deroulee sans erreur, false sinon
 */
bool image_init(void);

/**
 * Cette fonction auxilaire permet l'initialisation de la lib sdl_mixer
 *
 * @return true si l'initialisation c'est deroulee sans erreur, false sinon
 */
bool mixer_init(void);

/**
 * Cette fonction auxilaire permet l'initialisation des attributs window et 
 * renderer d'une application
 *
 * @param struct application *application : l'application a initialiser
 *
 * @return true si l'initialisation c'est deroulee sans erreur, false sinon
 */
bool application_init_graphics(struct application *application);

/**
 * Cette fonction auxilaire permet l'initialisation des attributs menu et game de l'application.
 *
 * @param struct application *application : l'application a initialiser
 *
 * @return true si l'initialisation c'est deroulee sans erreur, false sinon
 */
bool application_init_scenes(struct application *application);

struct application *application_initialize() {
   struct application *application;
   if(!sdl_init() || !ttf_init() || !image_init() || !mixer_init())
      return NULL;
   application = malloc(sizeof(struct application));
   if(!application_init_graphics(application))
      return NULL;
   if(!application_init_scenes(application))
      return NULL; 
   application->state = APPLICATION_STATE_MENU;
   return application;
}

void application_run(struct application *application) {
   while(application->state != APPLICATION_STATE_QUIT) {
      switch(application->state) {
         case APPLICATION_STATE_MENU:
            menu_run(application->menu);
            if(application->menu->state == MENU_QUIT)
               application->state = APPLICATION_STATE_QUIT;
            else if(application->menu->state == MENU_PLAY)
               application->state = APPLICATION_STATE_PLAY;
            break;
         case APPLICATION_STATE_PLAY:
            game_set_difficulty(application->game, application->menu->difficulty,
               application->menu->space_mode);
            game_run(application->game);
            if(application->game->state == GAME_QUIT)
               application->state = APPLICATION_STATE_QUIT;
            else if(application->game->state == GAME_TO_MENU)
               application->state = APPLICATION_STATE_MENU;
            break;
         case APPLICATION_STATE_QUIT:
            break;
      }
   }
}

bool sdl_init(void) {
   if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
      fprintf(stderr, "SDL failed to initialize: %s\n", SDL_GetError());
      return false;
   }
   if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
      fprintf(stderr, "Warning: Linear texture filtering not enabled!");
   }
   return true;
}

bool ttf_init(void) {
   if(TTF_Init()==-1) {
      fprintf(stderr, "TTF failed to initialize: %s\n", TTF_GetError());
      return false;
   }
   return true;
}

bool image_init(void) {
   int imgFlags = IMG_INIT_PNG;
   if(!(IMG_Init(imgFlags) & imgFlags)) {
      fprintf(stderr, "SDL_image failed to initialize: %s\n", IMG_GetError());
      return false;
   }
   return true;
}

bool mixer_init(void) {
   Mix_Init(MIX_INIT_MP3);
   if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 6, 1024)==-1) {
      printf("Mix_OpenAudio: %s\n", Mix_GetError());
      return false;
   }
   Mix_VolumeMusic(MIX_MAX_VOLUME/2);
   return true;
}

bool application_init_graphics(struct application *application) {
   application->window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED, 
      SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
   if(!application->window) {
       fprintf(stderr, "Window could not be created: %s\n", SDL_GetError());
       return false;
    }
    application->renderer = SDL_CreateRenderer(application->window, -1,
       SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!application->renderer) {
       fprintf(stderr, "Renderer could not be created: %s\n", SDL_GetError());
       return false;
    }
    return true;
}

bool application_init_scenes(struct application *application) {
   application->menu = menu_initialize(application->renderer);
   if(!application->menu) {
      fprintf(stderr, "Failed to initialize menu: %s\n", IMG_GetError());
      return false;
   }
   application->game = game_initialize(application->renderer);
   if(!application->game) {
      fprintf(stderr, "Failed to initialize game: %s\n", IMG_GetError());
      return false;
   }
   return true;
}

void application_shut_down(struct application *application) {
   menu_delete(application->menu);
   game_delete(application->game);
   SDL_DestroyRenderer(application->renderer);
   SDL_DestroyWindow(application->window);
   free(application);
   application = NULL;
   TTF_Quit();
   Mix_Quit();
   Mix_CloseAudio();
   IMG_Quit();
   SDL_Quit();
}
