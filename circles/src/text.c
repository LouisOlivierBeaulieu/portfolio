#include "text.h"

void text_render(SDL_Renderer * renderer, struct text text) {
   TTF_Font *font = TTF_OpenFont(text.font_file, text.size);
   int w, h;
   TTF_SizeUTF8(font, text.content, &w, &h);
   SDL_Rect destr = {text.x - w/2, text.y, w, h};
   SDL_Surface *text_surface = TTF_RenderUTF8_Solid(font, text.content, text.color);
   SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
   SDL_RenderCopy(renderer, text_texture, NULL, &destr);
   TTF_CloseFont(font);
   SDL_FreeSurface(text_surface);
   SDL_DestroyTexture(text_texture);
}
