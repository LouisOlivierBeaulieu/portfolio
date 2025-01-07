#include "shape.h"

/**
 * Cette fonction auxiliare permet de transformer un angle en degres en un angle en radians.
 *
 * @param int degree : l'angle en degres
 *
 * @return l'angle en radians (double)
 */
double degree_to_radians(int degree);

void render_star(SDL_Renderer *renderer, int x1, int y1, int x2, int y2, int width, int height) {
   boxRGBA(renderer, x1, y1, x2, y2, STAR_COLOR);
   filledTrigonRGBA(renderer, x1, y1, x2, y1, x1 + (x2 - x1) / 2,  y1 - height, STAR_COLOR);
   filledTrigonRGBA(renderer, x2, y1, x2, y2, x2 + width,  y1 + (y2 - y1) /2, STAR_COLOR);
   filledTrigonRGBA(renderer, x2, y2, x1, y2, x1 + (x2 - x1) / 2,  y2 + height, STAR_COLOR);
   filledTrigonRGBA(renderer, x1, y1, x1, y2, x1 - width,  y1 + (y2 - y1) /2, STAR_COLOR);
}

void render_obstacle(SDL_Renderer *renderer, struct obstacle obstacle) {
   filledPieRGBA(renderer, CENTER_X, CENTER_Y, obstacle.radius, 
      obstacle.start + 1, obstacle.end - 1, OBSTACLE_COLOR);
   filledPieRGBA(renderer, CENTER_X, CENTER_Y, obstacle.radius - OBSTACLE_THICKNESS, 
      obstacle.start, obstacle.end, obstacle.bg_r, obstacle.bg_g, obstacle.bg_b, obstacle.bg_a);
}

void render_player(SDL_Renderer *renderer, double player_degree) {
   double theta1 = degree_to_radians(player_degree);
   double theta2 = degree_to_radians(player_degree - PLAYER_RADIUS_OFFSET);
   double theta3 = degree_to_radians(player_degree + PLAYER_RADIUS_OFFSET);
   int x1 = CENTER_X + cos(theta1) * (CENTER_RADIUS + PLAYER_APEX_OFFSET);
   int y1 = CENTER_Y + sin(theta1) * (CENTER_RADIUS + PLAYER_APEX_OFFSET);
   int x2 = CENTER_X + cos(theta2) * (CENTER_RADIUS + PLAYER_BOTTOM_OFFSET);
   int y2 = CENTER_Y + sin(theta2) * (CENTER_RADIUS + PLAYER_BOTTOM_OFFSET);
   int x3 = CENTER_X + cos(theta3) * (CENTER_RADIUS + PLAYER_BOTTOM_OFFSET);
   int y3 = CENTER_Y + sin(theta3) * (CENTER_RADIUS + PLAYER_BOTTOM_OFFSET);
   filledTrigonRGBA(renderer, x1, y1, x2, y2, x3, y3, PLAYER_COLOR);
}

double degree_to_radians(int degree) {
   return degree * M_PI / 180.0;
}
