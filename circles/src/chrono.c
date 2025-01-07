#include "chrono.h"

struct chrono *chrono_create(SDL_Renderer *renderer) {
   struct chrono *chrono = calloc(1, sizeof(struct chrono));
   if(chrono) {
      chrono->spritesheet = spritesheet_create(DIGITS_FILENAME, 1, 11, 11, renderer);
   }
   return chrono;
}

void chrono_update(struct chrono *chrono, Uint32 milliseconds) {
   chrono->decaminutes = (get_minutes(milliseconds)%100)/10;
   chrono->minutes = get_minutes(milliseconds)%10;
   chrono->decaseconds = get_seconds(milliseconds)/10;
   chrono->seconds = get_seconds(milliseconds)%10;
   chrono->deciseconds = get_deciseconds(milliseconds);
}
void chrono_render(struct chrono *chrono) {
   if(chrono->decaminutes != 0 || chrono->minutes != 0) {
      spritesheet_render(chrono->spritesheet, CHRONO_X, CHRONO_Y, 0xff, chrono->decaminutes);
      spritesheet_render(chrono->spritesheet, CHRONO_X + DIGIT_OFFSET, CHRONO_Y, 0xff, 
         chrono->minutes);
      spritesheet_render(chrono->spritesheet, CHRONO_X + DIGIT_OFFSET * 2, CHRONO_Y, 0xff, 10);
   }
   spritesheet_render(chrono->spritesheet, CHRONO_X + DIGIT_OFFSET * 3, CHRONO_Y, 0xff, 
      chrono->decaseconds);
   spritesheet_render(chrono->spritesheet, CHRONO_X + DIGIT_OFFSET * 4, CHRONO_Y, 0xff, 
      chrono->seconds);
      spritesheet_render(chrono->spritesheet, CHRONO_X + DIGIT_OFFSET * 5, CHRONO_Y, 0xff, 10);
   spritesheet_render(chrono->spritesheet, CHRONO_X + DIGIT_OFFSET * 6, CHRONO_Y, 0xff, 
      chrono->deciseconds);
}

int get_minutes(Uint32 milliseconds) {
   return (milliseconds/1000)/ 60;
}

int get_seconds(Uint32 milliseconds) {
   return milliseconds/1000 - 60 * get_minutes(milliseconds);
}

int get_deciseconds(Uint32 milliseconds) {
   return (milliseconds%1000)/100;
}

void chrono_delete(struct chrono *chrono) {
   if(chrono != NULL) {
      spritesheet_delete(chrono->spritesheet);   
      free(chrono);
   }
}
