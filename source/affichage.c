#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "affichage.h"
#include "save.h"
#define LONG 26
#define LARG 15

void ouvrir_fenetre(char *nomfenetre){
  MLV_create_window(nomfenetre, nomfenetre, 1280, 720);
}

void actualise_fenetre(){
  MLV_actualise_window();
}

void affiche_terrain_mlv(terrain *t, p_piece suivant, p_piece actuelle, int *score, MLV_Image *image){
  int i, j, r, g, b;
  int coordonnee1_x[3];
  int coordonnee1_y[3];
  int coordonnee2_x[3];
  int coordonnee2_y[3];
  r = rand() % 256;
  g = rand() % 256;
  b = rand() % 256;
  MLV_draw_filled_rectangle(0, 0, 1280, 720, MLV_COLOR_BLACK);
  MLV_draw_image(image, 0, 0);

  affiche_piece_suivante(suivant);
  for (i = 0; i < LONG; i++){
    for (j = 0; j < LARG; j++){
      if (t->field[i][j] == 0)
      {
        MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
      }
      if (t->field[i][j] == 3)
      {
        MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
        MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_GREY);
        MLV_draw_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
        coordonnee1_x[0] = j * 25 + 454 + 12;
        coordonnee1_x[1] = j * 25 + 454 + 25;
        coordonnee1_x[2] = j * 25 + 454 + 25;

        coordonnee1_y[0] = i * 25 + 46 + 12;
        coordonnee1_y[1] = i * 25 + 46;
        coordonnee1_y[2] = i * 25 + 46 + 25;

        MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
        coordonnee2_x[0] = j * 25 + 454;
        coordonnee2_x[1] = j * 25 + 454;
        coordonnee2_x[2] = j * 25 + 454 + 13;

        coordonnee2_y[0] = i * 25 + 46;
        coordonnee2_y[1] = i * 25 + 46 + 25;
        coordonnee2_y[2] = i * 25 + 46 + 13;

        MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
        MLV_draw_filled_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_GREY);
        MLV_draw_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_BLACK);
      }
      if (t->field[i][j] == 1)
      {
        if (*score >= 200)
        {
          switch (actuelle->couleur)
          {
          case A:
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_rgba(r, g, b, 255));
            MLV_draw_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            coordonnee1_x[0] = j * 25 + 454 + 12;
            coordonnee1_x[1] = j * 25 + 454 + 25;
            coordonnee1_x[2] = j * 25 + 454 + 25;

            coordonnee1_y[0] = i * 25 + 46 + 12;
            coordonnee1_y[1] = i * 25 + 46;
            coordonnee1_y[2] = i * 25 + 46 + 25;

            MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
            coordonnee2_x[0] = j * 25 + 454;
            coordonnee2_x[1] = j * 25 + 454;
            coordonnee2_x[2] = j * 25 + 454 + 13;

            coordonnee2_y[0] = i * 25 + 46;
            coordonnee2_y[1] = i * 25 + 46 + 25;
            coordonnee2_y[2] = i * 25 + 46 + 13;

            MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_rgba(r, g, b, 255));
            MLV_draw_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_BLACK);
            break;
          case B:
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_rgba(r, g, b, 255));
            MLV_draw_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            coordonnee1_x[0] = j * 25 + 454 + 12;
            coordonnee1_x[1] = j * 25 + 454 + 25;
            coordonnee1_x[2] = j * 25 + 454 + 25;

            coordonnee1_y[0] = i * 25 + 46 + 12;
            coordonnee1_y[1] = i * 25 + 46;
            coordonnee1_y[2] = i * 25 + 46 + 25;

            MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
            coordonnee2_x[0] = j * 25 + 454;
            coordonnee2_x[1] = j * 25 + 454;
            coordonnee2_x[2] = j * 25 + 454 + 13;

            coordonnee2_y[0] = i * 25 + 46;
            coordonnee2_y[1] = i * 25 + 46 + 25;
            coordonnee2_y[2] = i * 25 + 46 + 13;

            MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_rgba(r, g, b, 255));
            MLV_draw_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_BLACK);
            break;
          case C:
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_rgba(r, g, b, 255));
            MLV_draw_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            coordonnee1_x[0] = j * 25 + 454 + 12;
            coordonnee1_x[1] = j * 25 + 454 + 25;
            coordonnee1_x[2] = j * 25 + 454 + 25;

            coordonnee1_y[0] = i * 25 + 46 + 12;
            coordonnee1_y[1] = i * 25 + 46;
            coordonnee1_y[2] = i * 25 + 46 + 25;

            MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
            coordonnee2_x[0] = j * 25 + 454;
            coordonnee2_x[1] = j * 25 + 454;
            coordonnee2_x[2] = j * 25 + 454 + 13;

            coordonnee2_y[0] = i * 25 + 46;
            coordonnee2_y[1] = i * 25 + 46 + 25;
            coordonnee2_y[2] = i * 25 + 46 + 13;

            MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_rgba(r, g, b, 255));
            MLV_draw_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_BLACK);
            break;
          case D:
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_rgba(r, g, b, 255));
            MLV_draw_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            coordonnee1_x[0] = j * 25 + 454 + 12;
            coordonnee1_x[1] = j * 25 + 454 + 25;
            coordonnee1_x[2] = j * 25 + 454 + 25;

            coordonnee1_y[0] = i * 25 + 46 + 12;
            coordonnee1_y[1] = i * 25 + 46;
            coordonnee1_y[2] = i * 25 + 46 + 25;

            MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
            coordonnee2_x[0] = j * 25 + 454;
            coordonnee2_x[1] = j * 25 + 454;
            coordonnee2_x[2] = j * 25 + 454 + 13;

            coordonnee2_y[0] = i * 25 + 46;
            coordonnee2_y[1] = i * 25 + 46 + 25;
            coordonnee2_y[2] = i * 25 + 46 + 13;

            MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_rgba(r, g, b, 255));
            MLV_draw_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_BLACK);
            break;
          case E:
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_rgba(r, g, b, 255));
            MLV_draw_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            coordonnee1_x[0] = j * 25 + 454 + 12;
            coordonnee1_x[1] = j * 25 + 454 + 25;
            coordonnee1_x[2] = j * 25 + 454 + 25;

            coordonnee1_y[0] = i * 25 + 46 + 12;
            coordonnee1_y[1] = i * 25 + 46;
            coordonnee1_y[2] = i * 25 + 46 + 25;

            MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
            coordonnee2_x[0] = j * 25 + 454;
            coordonnee2_x[1] = j * 25 + 454;
            coordonnee2_x[2] = j * 25 + 454 + 13;

            coordonnee2_y[0] = i * 25 + 46;
            coordonnee2_y[1] = i * 25 + 46 + 25;
            coordonnee2_y[2] = i * 25 + 46 + 13;

            MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_rgba(r, g, b, 255));
            MLV_draw_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_BLACK);
            break;
          case F:
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_rgba(r, g, b, 255));
            MLV_draw_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            coordonnee1_x[0] = j * 25 + 454 + 12;
            coordonnee1_x[1] = j * 25 + 454 + 25;
            coordonnee1_x[2] = j * 25 + 454 + 25;

            coordonnee1_y[0] = i * 25 + 46 + 12;
            coordonnee1_y[1] = i * 25 + 46;
            coordonnee1_y[2] = i * 25 + 46 + 25;

            MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
            coordonnee2_x[0] = j * 25 + 454;
            coordonnee2_x[1] = j * 25 + 454;
            coordonnee2_x[2] = j * 25 + 454 + 13;

            coordonnee2_y[0] = i * 25 + 46;
            coordonnee2_y[1] = i * 25 + 46 + 25;
            coordonnee2_y[2] = i * 25 + 46 + 13;

            MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_rgba(r, g, b, 255));
            MLV_draw_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_BLACK);
            break;
          case G:
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_rgba(r, g, b, 255));
            MLV_draw_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            coordonnee1_x[0] = j * 25 + 454 + 12;
            coordonnee1_x[1] = j * 25 + 454 + 25;
            coordonnee1_x[2] = j * 25 + 454 + 25;

            coordonnee1_y[0] = i * 25 + 46 + 12;
            coordonnee1_y[1] = i * 25 + 46;
            coordonnee1_y[2] = i * 25 + 46 + 25;

            MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
            coordonnee2_x[0] = j * 25 + 454;
            coordonnee2_x[1] = j * 25 + 454;
            coordonnee2_x[2] = j * 25 + 454 + 13;

            coordonnee2_y[0] = i * 25 + 46;
            coordonnee2_y[1] = i * 25 + 46 + 25;
            coordonnee2_y[2] = i * 25 + 46 + 13;

            MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_rgba(r, g, b, 255));
            MLV_draw_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_BLACK);
            break;
          default:
            break;
          }
        }
        else
        {
          switch (actuelle->couleur)
          {
          case A:
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_CYAN);
            MLV_draw_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            coordonnee1_x[0] = j * 25 + 454 + 12;
            coordonnee1_x[1] = j * 25 + 454 + 25;
            coordonnee1_x[2] = j * 25 + 454 + 25;

            coordonnee1_y[0] = i * 25 + 46 + 12;
            coordonnee1_y[1] = i * 25 + 46;
            coordonnee1_y[2] = i * 25 + 46 + 25;

            MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
            coordonnee2_x[0] = j * 25 + 454;
            coordonnee2_x[1] = j * 25 + 454;
            coordonnee2_x[2] = j * 25 + 454 + 13;

            coordonnee2_y[0] = i * 25 + 46;
            coordonnee2_y[1] = i * 25 + 46 + 25;
            coordonnee2_y[2] = i * 25 + 46 + 13;

            MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_CYAN);
            MLV_draw_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_BLACK);
            break;
          case B:
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_ORANGE);
            MLV_draw_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            coordonnee1_x[0] = j * 25 + 454 + 12;
            coordonnee1_x[1] = j * 25 + 454 + 25;
            coordonnee1_x[2] = j * 25 + 454 + 25;

            coordonnee1_y[0] = i * 25 + 46 + 12;
            coordonnee1_y[1] = i * 25 + 46;
            coordonnee1_y[2] = i * 25 + 46 + 25;

            MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
            coordonnee2_x[0] = j * 25 + 454;
            coordonnee2_x[1] = j * 25 + 454;
            coordonnee2_x[2] = j * 25 + 454 + 13;

            coordonnee2_y[0] = i * 25 + 46;
            coordonnee2_y[1] = i * 25 + 46 + 25;
            coordonnee2_y[2] = i * 25 + 46 + 13;

            MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_ORANGE);
            MLV_draw_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_BLACK);
            break;
          case C:
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLUE);
            MLV_draw_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            coordonnee1_x[0] = j * 25 + 454 + 12;
            coordonnee1_x[1] = j * 25 + 454 + 25;
            coordonnee1_x[2] = j * 25 + 454 + 25;

            coordonnee1_y[0] = i * 25 + 46 + 12;
            coordonnee1_y[1] = i * 25 + 46;
            coordonnee1_y[2] = i * 25 + 46 + 25;

            MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
            coordonnee2_x[0] = j * 25 + 454;
            coordonnee2_x[1] = j * 25 + 454;
            coordonnee2_x[2] = j * 25 + 454 + 13;

            coordonnee2_y[0] = i * 25 + 46;
            coordonnee2_y[1] = i * 25 + 46 + 25;
            coordonnee2_y[2] = i * 25 + 46 + 13;

            MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_BLUE);
            MLV_draw_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_BLACK);
            break;
          case D:
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_YELLOW);
            MLV_draw_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            coordonnee1_x[0] = j * 25 + 454 + 12;
            coordonnee1_x[1] = j * 25 + 454 + 25;
            coordonnee1_x[2] = j * 25 + 454 + 25;

            coordonnee1_y[0] = i * 25 + 46 + 12;
            coordonnee1_y[1] = i * 25 + 46;
            coordonnee1_y[2] = i * 25 + 46 + 25;

            MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
            coordonnee2_x[0] = j * 25 + 454;
            coordonnee2_x[1] = j * 25 + 454;
            coordonnee2_x[2] = j * 25 + 454 + 13;

            coordonnee2_y[0] = i * 25 + 46;
            coordonnee2_y[1] = i * 25 + 46 + 25;
            coordonnee2_y[2] = i * 25 + 46 + 13;

            MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_YELLOW);
            MLV_draw_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_BLACK);
            break;
          case E:
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_RED);
            MLV_draw_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            coordonnee1_x[0] = j * 25 + 454 + 12;
            coordonnee1_x[1] = j * 25 + 454 + 25;
            coordonnee1_x[2] = j * 25 + 454 + 25;

            coordonnee1_y[0] = i * 25 + 46 + 12;
            coordonnee1_y[1] = i * 25 + 46;
            coordonnee1_y[2] = i * 25 + 46 + 25;

            MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
            coordonnee2_x[0] = j * 25 + 454;
            coordonnee2_x[1] = j * 25 + 454;
            coordonnee2_x[2] = j * 25 + 454 + 13;

            coordonnee2_y[0] = i * 25 + 46;
            coordonnee2_y[1] = i * 25 + 46 + 25;
            coordonnee2_y[2] = i * 25 + 46 + 13;

            MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_RED);
            MLV_draw_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_BLACK);
            break;
          case F:
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_GREEN);
            MLV_draw_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            coordonnee1_x[0] = j * 25 + 454 + 12;
            coordonnee1_x[1] = j * 25 + 454 + 25;
            coordonnee1_x[2] = j * 25 + 454 + 25;

            coordonnee1_y[0] = i * 25 + 46 + 12;
            coordonnee1_y[1] = i * 25 + 46;
            coordonnee1_y[2] = i * 25 + 46 + 25;

            MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
            coordonnee2_x[0] = j * 25 + 454;
            coordonnee2_x[1] = j * 25 + 454;
            coordonnee2_x[2] = j * 25 + 454 + 13;

            coordonnee2_y[0] = i * 25 + 46;
            coordonnee2_y[1] = i * 25 + 46 + 25;
            coordonnee2_y[2] = i * 25 + 46 + 13;

            MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_GREEN);
            MLV_draw_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_BLACK);
            break;
          case G:
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_VIOLET);
            MLV_draw_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
            coordonnee1_x[0] = j * 25 + 454 + 12;
            coordonnee1_x[1] = j * 25 + 454 + 25;
            coordonnee1_x[2] = j * 25 + 454 + 25;

            coordonnee1_y[0] = i * 25 + 46 + 12;
            coordonnee1_y[1] = i * 25 + 46;
            coordonnee1_y[2] = i * 25 + 46 + 25;

            MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
            coordonnee2_x[0] = j * 25 + 454;
            coordonnee2_x[1] = j * 25 + 454;
            coordonnee2_x[2] = j * 25 + 454 + 13;

            coordonnee2_y[0] = i * 25 + 46;
            coordonnee2_y[1] = i * 25 + 46 + 25;
            coordonnee2_y[2] = i * 25 + 46 + 13;

            MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
            MLV_draw_filled_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_VIOLET);
            MLV_draw_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_BLACK);
            break;
          default:
            break;
          }
        }
      }
      if (t->field[i][j] == 2)
      {
        MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
        MLV_draw_filled_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_WHITE);
        MLV_draw_rectangle(j * 25 + 454, i * 25 + 46, 25, 25, MLV_COLOR_BLACK);
        coordonnee1_x[0] = j * 25 + 454 + 12;
        coordonnee1_x[1] = j * 25 + 454 + 25;
        coordonnee1_x[2] = j * 25 + 454 + 25;

        coordonnee1_y[0] = i * 25 + 46 + 12;
        coordonnee1_y[1] = i * 25 + 46;
        coordonnee1_y[2] = i * 25 + 46 + 25;

        MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
        coordonnee2_x[0] = j * 25 + 454;
        coordonnee2_x[1] = j * 25 + 454;
        coordonnee2_x[2] = j * 25 + 454 + 13;

        coordonnee2_y[0] = i * 25 + 46;
        coordonnee2_y[1] = i * 25 + 46 + 25;
        coordonnee2_y[2] = i * 25 + 46 + 13;

        MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
        MLV_draw_filled_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_WHITE);
        MLV_draw_rectangle(j * 25 + 458, i * 25 + 50, 18, 18, MLV_COLOR_BLACK);
      }
    }
  }
}

void dessiner_triangle(int x, int y)
{
  int cx[3]; /* coordonnees x */
  int cy[3]; /* coordonnees y */
  cx[0] = x - 35;
  cx[1] = x - 35;
  cx[2] = x - 15;

  cy[0] = y + 5;
  cy[1] = y + 45;
  cy[2] = y + 25;
  MLV_draw_filled_polygon(cx, cy, 3, MLV_rgba(200, 0, 0, 255));
}

void dessiner_croix_one(int x, int y)
{
  int cx[16];
  int cy[16];
  cx[0] = 3 * (x - 4);
  cx[1] = 3 * (x - 3);
  cx[2] = 3 * (x);
  cx[3] = 3 * (x + 3);
  cx[4] = 3 * (x + 4);
  cx[5] = 3 * (x + 4);
  cx[6] = 3 * (x + 1);
  cx[7] = 3 * (x + 4);
  cx[8] = 3 * (x + 4);
  cx[9] = 3 * (x + 3);
  cx[10] = 3 * x;
  cx[11] = 3 * (x - 3);
  cx[12] = 3 * (x - 4);
  cx[13] = 3 * (x - 4);
  cx[14] = 3 * (x - 1);
  cx[15] = 3 * (x - 4);

  cy[0] = 3 * (y - 4);
  cy[1] = 3 * (y - 4);
  cy[2] = 3 * (y - 1);
  cy[3] = 3 * (y - 4);
  cy[4] = 3 * (y - 4);
  cy[5] = 3 * (y - 3);
  cy[6] = 3 * y;
  cy[7] = 3 * (y + 3);
  cy[8] = 3 * (y + 4);
  cy[9] = 3 * (y + 4);
  cy[10] = 3 * (y + 1);
  cy[11] = 3 * (y + 4);
  cy[12] = 3 * (y + 4);
  cy[13] = 3 * (y + 3);
  cy[14] = 3 * y;
  cy[15] = 3 * (y - 3);

  MLV_draw_filled_polygon(cx, cy, 16, MLV_rgba(255, 255, 255, 100));
}

void afficher_menu(MLV_Font *font, MLV_Font *font2, MLV_Font *font3, int choix)
{
  /*MLV_draw_line(640,0,640,720,MLV_COLOR_WHITE); pour avoir si le texte est centré*/
  MLV_draw_text_with_font(543, 40, "T", font, MLV_rgba(219, 36, 0, 100));
  MLV_draw_text_with_font(583, 40, "E", font, MLV_rgba(255, 96, 0, 100));
  MLV_draw_text_with_font(623, 40, "T", font, MLV_rgba(255, 192, 0, 100));
  MLV_draw_text_with_font(663, 40, "R", font, MLV_rgba(95, 197, 0, 100));
  MLV_draw_text_with_font(703, 40, "I", font, MLV_rgba(50, 205, 255, 100));
  MLV_draw_text_with_font(723, 40, "S", font, MLV_rgba(235, 78, 179, 100));

  MLV_draw_line(530, 45, 530, 120, MLV_rgba(235, 78, 179, 100));
  MLV_draw_line(530, 120, 620, 120, MLV_rgba(50, 205, 255, 100));
  MLV_draw_line(620, 120, 620, 195, MLV_rgba(95, 197, 0, 100));
  MLV_draw_line(620, 195, 670, 195, MLV_rgba(255, 192, 0, 100));
  MLV_draw_line(670, 195, 670, 120, MLV_rgba(255, 96, 0, 100));
  MLV_draw_line(670, 120, 765, 120, MLV_rgba(219, 36, 0, 100));
  MLV_draw_line(765, 120, 765, 45, MLV_rgba(235, 78, 179, 100));
  MLV_draw_line(765, 45, 530, 45, MLV_rgba(50, 205, 255, 100));

  if (choix == 0)
  {
    MLV_draw_text_with_font(490, 300, "Nouvelle Partie", font3, MLV_rgba(255, 96, 0, 100));
    dessiner_triangle(490, 300);
  }
  else
  {
    MLV_draw_text_with_font(490, 300, "Nouvelle Partie", font2, MLV_rgba(81, 81, 81, 100));
  }
  if (choix == 1)
  {
    MLV_draw_text_with_font(492, 400, "Charger Partie", font3, MLV_rgba(255, 192, 0, 100));
    dessiner_triangle(492, 400);
  }
  else
  {
    MLV_draw_text_with_font(492, 400, "Charger Partie", font2, MLV_rgba(81, 81, 81, 100));
  }

  if (choix == 2)
  {
    MLV_draw_text_with_font(580, 500, "Score", font3, MLV_rgba(95, 197, 0, 100));
    dessiner_triangle(580, 500);
  }
  else
  {
    MLV_draw_text_with_font(580, 500, "Score", font2, MLV_rgba(81, 81, 81, 100));
  }
  if (choix == 3)
  {
    MLV_draw_text_with_font(567, 600, "Quitter", font3, MLV_rgba(50, 205, 255, 100));
    dessiner_triangle(567, 600);
  }
  else
  {
    MLV_draw_text_with_font(567, 600, "Quitter", font2, MLV_rgba(81, 81, 81, 100));
  }
}

void dessin_score(MLV_Font *font, int *score,char * nom)
{
  MLV_draw_rectangle(235, 60, 200, 200, MLV_rgba(150, 215, 0, 255));
  MLV_draw_text_with_font(275, 100, "SCORE", font, MLV_rgba(150, 215, 0, 255));
  MLV_draw_text_with_font(280, 160, "%d", font, MLV_rgba(150, 215, 0, 255), *score);
  MLV_draw_text_with_font(240, 220, "%s", font, MLV_rgba(150, 215, 0, 255), nom);
}

void affichage_game_over(MLV_Font *font)
{
  MLV_draw_filled_rectangle(300, 200, 700, 300, MLV_rgba(95, 19, 120, 235));
  MLV_draw_filled_rectangle(325, 400, 245, 80, MLV_rgba(228, 105, 18, 235));
  MLV_draw_filled_rectangle(750, 400, 245, 80, MLV_rgba(171, 14, 14, 235));

  MLV_draw_text_with_font(515, 275, "GAME OVER", font, MLV_rgba(175, 215, 0, 255));
  MLV_draw_text_with_font(335, 425, "TRY AGAIN", font, MLV_rgba(200, 175, 0, 255));
  MLV_draw_text_with_font(810, 425, "MENU", font, MLV_rgba(150, 215, 0, 255));
}

void animation_bouton_TA(MLV_Font *font)
{
  MLV_draw_filled_rectangle(325, 400, 245, 80, MLV_COLOR_PINK);

  MLV_draw_text_with_font(335, 425, "TRY AGAIN", font, MLV_rgba(200, 175, 0, 255));

  MLV_actualise_window();
  MLV_wait_milliseconds(70);

  MLV_draw_filled_rectangle(325, 400, 245, 80, MLV_COLOR_BLUE);

  MLV_draw_text_with_font(335, 425, "TRY AGAIN", font, MLV_rgba(200, 175, 0, 255));

  MLV_actualise_window();
}
void animation_bouton_MENU(MLV_Font *font)
{
  MLV_draw_filled_rectangle(750, 400, 245, 80, MLV_COLOR_GREEN);
  MLV_draw_text_with_font(810, 425, "MENU", font, MLV_rgba(150, 215, 0, 255));

  MLV_actualise_window();
  MLV_wait_milliseconds(70);

  MLV_draw_filled_rectangle(750, 400, 245, 80, MLV_COLOR_CYAN);
  MLV_draw_text_with_font(810, 425, "MENU", font, MLV_rgba(150, 215, 0, 255));
  MLV_actualise_window();
}

int verif_click(int x, int y)
{
  if ((x >= 325 && x <= 570) && (y >= 400 && y <= 480))
  {
    return 1;
  }
  if ((x >= 750 && x <= 995) && (y >= 400 && y <= 480))
  {
    return 2;
  }
  return 0;
}

void affiche_piece_suivante(p_piece p)
{
  int i, j;
  int coordonnee1_x[3];
  int coordonnee1_y[3];
  int coordonnee2_x[3];
  int coordonnee2_y[3];

  MLV_draw_rectangle(854, 46, 200, 200, MLV_COLOR_BLUE);
  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 4; j++)
    {
      if (p->forme[i][j] == 1)
      {
        switch (p->couleur)
        {
        case A /* constant-expression */:
          MLV_draw_filled_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_BLACK);
          MLV_draw_filled_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_CYAN);
          MLV_draw_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_BLACK);
          coordonnee1_x[0] = j * 25 + 889 + 12;
          coordonnee1_x[1] = j * 25 + 889 + 25;
          coordonnee1_x[2] = j * 25 + 889 + 25;

          coordonnee1_y[0] = i * 25 + 70 + 12;
          coordonnee1_y[1] = i * 25 + 70;
          coordonnee1_y[2] = i * 25 + 70 + 25;

          MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
          coordonnee2_x[0] = j * 25 + 889;
          coordonnee2_x[1] = j * 25 + 889;
          coordonnee2_x[2] = j * 25 + 889 + 13;

          coordonnee2_y[0] = i * 25 + 70;
          coordonnee2_y[1] = i * 25 + 70 + 25;
          coordonnee2_y[2] = i * 25 + 70 + 13;

          MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
          MLV_draw_filled_rectangle(j * 25 + 893, i * 25 + 74, 18, 18, MLV_COLOR_CYAN);
          MLV_draw_rectangle(j * 25 + 893, i * 25 + 74, 18, 18, MLV_COLOR_BLACK);
          break;
        case B /* constant-expression */:
          MLV_draw_filled_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_BLACK);
          MLV_draw_filled_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_ORANGE);
          MLV_draw_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_BLACK);
          coordonnee1_x[0] = j * 25 + 889 + 12;
          coordonnee1_x[1] = j * 25 + 889 + 25;
          coordonnee1_x[2] = j * 25 + 889 + 25;

          coordonnee1_y[0] = i * 25 + 70 + 12;
          coordonnee1_y[1] = i * 25 + 70;
          coordonnee1_y[2] = i * 25 + 70 + 25;

          MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
          coordonnee2_x[0] = j * 25 + 889;
          coordonnee2_x[1] = j * 25 + 889;
          coordonnee2_x[2] = j * 25 + 889 + 13;

          coordonnee2_y[0] = i * 25 + 70;
          coordonnee2_y[1] = i * 25 + 70 + 25;
          coordonnee2_y[2] = i * 25 + 70 + 13;

          MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
          MLV_draw_filled_rectangle(j * 25 + 893, i * 25 + 74, 18, 18, MLV_COLOR_ORANGE);
          MLV_draw_rectangle(j * 25 + 893, i * 25 + 74, 18, 18, MLV_COLOR_BLACK);
          break;
        case C /* constant-expression */:
          MLV_draw_filled_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_BLACK);
          MLV_draw_filled_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_BLUE);
          MLV_draw_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_BLACK);
          coordonnee1_x[0] = j * 25 + 889 + 12;
          coordonnee1_x[1] = j * 25 + 889 + 25;
          coordonnee1_x[2] = j * 25 + 889 + 25;

          coordonnee1_y[0] = i * 25 + 70 + 12;
          coordonnee1_y[1] = i * 25 + 70;
          coordonnee1_y[2] = i * 25 + 70 + 25;

          MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
          coordonnee2_x[0] = j * 25 + 889;
          coordonnee2_x[1] = j * 25 + 889;
          coordonnee2_x[2] = j * 25 + 889 + 13;

          coordonnee2_y[0] = i * 25 + 70;
          coordonnee2_y[1] = i * 25 + 70 + 25;
          coordonnee2_y[2] = i * 25 + 70 + 13;

          MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
          MLV_draw_filled_rectangle(j * 25 + 893, i * 25 + 74, 18, 18, MLV_COLOR_BLUE);
          MLV_draw_rectangle(j * 25 + 893, i * 25 + 74, 18, 18, MLV_COLOR_BLACK);
          break;
        case D /* constant-expression */:
          MLV_draw_filled_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_BLACK);
          MLV_draw_filled_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_YELLOW);
          MLV_draw_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_BLACK);
          coordonnee1_x[0] = j * 25 + 889 + 12;
          coordonnee1_x[1] = j * 25 + 889 + 25;
          coordonnee1_x[2] = j * 25 + 889 + 25;

          coordonnee1_y[0] = i * 25 + 70 + 12;
          coordonnee1_y[1] = i * 25 + 70;
          coordonnee1_y[2] = i * 25 + 70 + 25;

          MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
          coordonnee2_x[0] = j * 25 + 889;
          coordonnee2_x[1] = j * 25 + 889;
          coordonnee2_x[2] = j * 25 + 889 + 13;

          coordonnee2_y[0] = i * 25 + 70;
          coordonnee2_y[1] = i * 25 + 70 + 25;
          coordonnee2_y[2] = i * 25 + 70 + 13;

          MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
          MLV_draw_filled_rectangle(j * 25 + 893, i * 25 + 74, 18, 18, MLV_COLOR_YELLOW);
          MLV_draw_rectangle(j * 25 + 893, i * 25 + 74, 18, 18, MLV_COLOR_BLACK);
          break;
        case E /* constant-expression */:
          MLV_draw_filled_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_BLACK);
          MLV_draw_filled_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_RED);
          MLV_draw_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_BLACK);
          coordonnee1_x[0] = j * 25 + 889 + 12;
          coordonnee1_x[1] = j * 25 + 889 + 25;
          coordonnee1_x[2] = j * 25 + 889 + 25;

          coordonnee1_y[0] = i * 25 + 70 + 12;
          coordonnee1_y[1] = i * 25 + 70;
          coordonnee1_y[2] = i * 25 + 70 + 25;

          MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
          coordonnee2_x[0] = j * 25 + 889;
          coordonnee2_x[1] = j * 25 + 889;
          coordonnee2_x[2] = j * 25 + 889 + 13;

          coordonnee2_y[0] = i * 25 + 70;
          coordonnee2_y[1] = i * 25 + 70 + 25;
          coordonnee2_y[2] = i * 25 + 70 + 13;

          MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
          MLV_draw_filled_rectangle(j * 25 + 893, i * 25 + 74, 18, 18, MLV_COLOR_RED);
          MLV_draw_rectangle(j * 25 + 893, i * 25 + 74, 18, 18, MLV_COLOR_BLACK);
          break;
        case F /* constant-expression */:
          MLV_draw_filled_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_BLACK);
          MLV_draw_filled_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_GREEN);
          MLV_draw_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_BLACK);
          coordonnee1_x[0] = j * 25 + 889 + 12;
          coordonnee1_x[1] = j * 25 + 889 + 25;
          coordonnee1_x[2] = j * 25 + 889 + 25;

          coordonnee1_y[0] = i * 25 + 70 + 12;
          coordonnee1_y[1] = i * 25 + 70;
          coordonnee1_y[2] = i * 25 + 70 + 25;

          MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
          coordonnee2_x[0] = j * 25 + 889;
          coordonnee2_x[1] = j * 25 + 889;
          coordonnee2_x[2] = j * 25 + 889 + 13;

          coordonnee2_y[0] = i * 25 + 70;
          coordonnee2_y[1] = i * 25 + 70 + 25;
          coordonnee2_y[2] = i * 25 + 70 + 13;

          MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
          MLV_draw_filled_rectangle(j * 25 + 893, i * 25 + 74, 18, 18, MLV_COLOR_GREEN);
          MLV_draw_rectangle(j * 25 + 893, i * 25 + 74, 18, 18, MLV_COLOR_BLACK);
          break;
        case G /* constant-expression */:
          MLV_draw_filled_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_BLACK);
          MLV_draw_filled_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_VIOLET);
          MLV_draw_rectangle(j * 25 + 889, i * 25 + 70, 25, 25, MLV_COLOR_BLACK);
          coordonnee1_x[0] = j * 25 + 889 + 12;
          coordonnee1_x[1] = j * 25 + 889 + 25;
          coordonnee1_x[2] = j * 25 + 889 + 25;

          coordonnee1_y[0] = i * 25 + 70 + 12;
          coordonnee1_y[1] = i * 25 + 70;
          coordonnee1_y[2] = i * 25 + 70 + 25;

          MLV_draw_filled_polygon(coordonnee1_x, coordonnee1_y, 3, MLV_COLOR_BLACK);
          coordonnee2_x[0] = j * 25 + 889;
          coordonnee2_x[1] = j * 25 + 889;
          coordonnee2_x[2] = j * 25 + 889 + 13;

          coordonnee2_y[0] = i * 25 + 70;
          coordonnee2_y[1] = i * 25 + 70 + 25;
          coordonnee2_y[2] = i * 25 + 70 + 13;

          MLV_draw_polygon(coordonnee2_x, coordonnee2_y, 3, MLV_COLOR_BLACK);
          MLV_draw_filled_rectangle(j * 25 + 893, i * 25 + 74, 18, 18, MLV_COLOR_VIOLET);
          MLV_draw_rectangle(j * 25 + 893, i * 25 + 74, 18, 18, MLV_COLOR_BLACK);
          break;

        default:
          break;
        }
      }
    }
  }
}

void afficher_score(){
  int tab[10];
  int i;
  MLV_Font *font;
  MLV_Font *font2;
  MLV_Font *font3;
  MLV_Font *font4;
  MLV_Font *font5;

  font = MLV_load_font("./Fonts/kung_fu_master/kungfumaster.ttf", 20);
  font2 = MLV_load_font("./Fonts/minecrafter/Minecrafter.Reg.ttf", 38);
  font3 = MLV_load_font("./Fonts/minecrafter/Minecrafter.Reg.ttf", 30);
  font4 = MLV_load_font("./Fonts/minecrafter/Minecrafter.Reg.ttf", 25);
  font5 = MLV_load_font("./Fonts/minecrafter/Minecrafter.Reg.ttf", 20);

  dessiner_croix_one(405, 13);
  MLV_draw_rectangle(1200, 24, 30, 30, MLV_rgba(200, 0, 0, 255));
  lecture_score(tab);
  MLV_draw_text_with_font(150, 20, "1. %d", font2, MLV_rgba(255, 215, 0, 255), tab[0]);
  MLV_draw_text_with_font(150, 80, "2. %d", font3, MLV_rgba(192, 192, 192, 255), tab[1]);
  MLV_draw_text_with_font(150, 140, "3. %d", font4, MLV_rgba(205, 127, 50, 255), tab[2]);

  for (i = 3; i < 10; i++)
  {
    MLV_draw_text_with_font(150, 20 + (i * 60), "%d. %d", font5, MLV_rgba(200, 0, 0, 255), i + 1, tab[i]);
  }
  MLV_free_font(font);
  MLV_free_font(font2);
  MLV_free_font(font3);
  MLV_free_font(font4);
  MLV_free_font(font5);
}

void afficher_pause(MLV_Font *font){

  MLV_draw_filled_rectangle(300, 200, 900, 300, MLV_rgba(0, 0, 45, 235));
  MLV_draw_filled_rectangle(325, 400, 245, 80, MLV_rgba(40, 20, 18, 235));
  MLV_draw_filled_rectangle(640, 400, 245, 80, MLV_rgba(171, 14, 14, 235));
  MLV_draw_filled_rectangle(950, 400, 245, 80, MLV_rgba(137, 69, 186, 235));

  MLV_draw_text_with_font(670, 275, "PAUSE", font, MLV_rgba(255, 255, 255, 255));
  MLV_draw_text_with_font(365, 425, "RESUME", font, MLV_rgba(200, 175, 0, 255));
  MLV_draw_text_with_font(700, 425, "MENU", font, MLV_rgba(150, 215, 0, 255));
  MLV_draw_text_with_font(1015, 425, "SAVE", font, MLV_rgba(150, 215, 0, 255));
}

int verif_click_pause(int x, int y)
{
  if ((x >= 325 && x <= 570) && (y >= 400 && y <= 480))
  {
    return 1;
  }

  if ((x >= 640 && x <= 885) && (y >= 400 && y <= 480))
  {
    return 2;
  }

  if ((x >= 950 && x <= 1195) && (y >= 400 && y <= 480))
  {
    return 3;
  }

  return 0;
}

void animation(MLV_Image *image, char *chemin, int frames, int layers, int nb_channels, MLV_Image *images[5]){
  char *file_path_of_sound = "./sound/kameffect.wav";
  MLV_Sound *sound;
  MLV_Animation *animation;
  int position_y = 610, compteur = 12;
  MLV_Animation_player *animation_player;
  MLV_init_audio();

  image = MLV_load_image(chemin);
  animation = MLV_create_animation(frames, layers, nb_channels);
  animation_player = MLV_create_animation_player(animation);
  if (!image){
    fprintf(stderr, "Impossible de lire l'image depuis le chemin %s.\n", chemin);
    exit(-1);
  }
  
  sound = MLV_load_sound(file_path_of_sound);
  if (!sound){
    fprintf(stderr, "It was impossible to load the file %s.\n",file_path_of_sound);
    exit(1);
  }

  images[0] = MLV_copy_partial_image(image, 7, 50, 40, 73);
  images[1] = MLV_copy_partial_image(image, 58, 50, 40, 73);
  images[2] = MLV_copy_partial_image(image, 110, 50, 40, 73);
  images[3] = MLV_copy_partial_image(image, 470, 30, 490, 350);

  MLV_add_frame_in_animation(images + 0, &sound, 4, animation);
  MLV_add_frame_in_animation(images + 1, &sound, 4, animation);
  MLV_add_frame_in_animation(images + 2, &sound, 4, animation);
  MLV_add_frame_in_animation(images + 3, &sound, 4, animation);
  MLV_play_animation_player(animation_player);
  MLV_turn_on_sound_of_animation_player(animation_player, 0);
  MLV_change_sound_volume_of_animation_player(animation_player, 0, 10.0);
  MLV_change_frame_rate(20);
  MLV_play_sound_from_animation_player(animation_player, 0);

  while (compteur > 0){
    compteur--;
    MLV_update_animation_player(animation_player);
    MLV_play_animation_player(animation_player);
    MLV_draw_image_from_animation_player(animation_player, 0, 400, position_y);
    MLV_actualise_window();
    MLV_delay_according_to_frame_rate();
  }
  MLV_free_animation_player(animation_player);
  MLV_free_animation(animation);
  MLV_free_image(images[0]);
  MLV_free_image(images[1]);
  MLV_free_image(images[2]);
  MLV_free_image(images[3]);
  MLV_free_image(image);
}

int verif_click_save(int x, int y){
    
    if ((x >= 355 && x <= 900) && (y >= 49 && y <= 159)){
        return 1;
    }
    
    if ((x >= 355 && x <= 900) && (y >= 199 && y <= 309)){
        return 2;
    }
  
    if ((x >= 355 && x <= 900) && (y >= 349 && y <= 459)){
        return 3;
    }
    
    if ((x >= 355 && x <= 900) && (y >= 499 && y <= 609)){
        return 4;
    }
    return 0;
}


void afficher_menu_save(MLV_Font *font, int *x, int *y){
    
    int coordonnee_x_polygone_1[6] = {360, 400, 860, 900, 860, 400};
    int coordonnee_y_polygone_1[6] = {110, 160, 160, 110, 50, 50};

    int coordonnee_x_polygone_2[6] = {360, 400, 860, 900, 860, 400};
    int coordonnee_y_polygone_2[6] = {260, 310, 310, 260, 200, 200};

    int coordonnee_x_polygone_3[6] = {360, 400, 860, 900, 860, 400};
    int coordonnee_y_polygone_3[6] = {410, 460, 460, 410, 350, 350};

    int coordonnee_x_polygone_4[6] = {360, 400, 860, 900, 860, 400};
    int coordonnee_y_polygone_4[6] = {560, 610, 610, 560, 500, 500};
    MLV_clear_window(MLV_COLOR_BLACK);
    MLV_draw_polygon(coordonnee_x_polygone_1, coordonnee_y_polygone_1, 6, MLV_COLOR_RED);
    MLV_draw_polygon(coordonnee_x_polygone_2, coordonnee_y_polygone_2, 6, MLV_COLOR_CYAN);
    MLV_draw_polygon(coordonnee_x_polygone_3, coordonnee_y_polygone_3, 6, MLV_COLOR_BLUE);
    MLV_draw_polygon(coordonnee_x_polygone_4, coordonnee_y_polygone_4, 6, MLV_COLOR_YELLOW);

    MLV_draw_text_with_font(570, 85, "SLOT 1", font, MLV_rgba(255, 255, 255, 255));
    MLV_draw_text_with_font(570, 235, "SLOT 2", font, MLV_rgba(255, 255, 255, 255));
    MLV_draw_text_with_font(570, 385, "SLOT 3", font, MLV_rgba(255, 255, 255, 255));
    MLV_draw_text_with_font(570, 535, "RETOUR", font, MLV_rgba(255, 255, 255, 255));

    MLV_actualise_window();
  
    MLV_get_mouse_position(x,y);
    
    while ((*x >= 355 && *x <= 900) && (*y >= 49 && *y <= 159)){
        MLV_get_mouse_position(x,y);
        
        MLV_draw_filled_polygon(coordonnee_x_polygone_1, coordonnee_y_polygone_1, 6, MLV_rgba(162, 25, 42, 2));
        MLV_actualise_window();
    }
    MLV_draw_polygon(coordonnee_x_polygone_1, coordonnee_y_polygone_1, 6, MLV_COLOR_RED);
    

    while ((*x >= 355 && *x <= 900) && (*y >= 199 && *y <= 309)){
        MLV_get_mouse_position(x,y);
        MLV_draw_filled_polygon(coordonnee_x_polygone_2, coordonnee_y_polygone_2, 6, MLV_rgba(55, 179, 166, 2));
        MLV_actualise_window();
    }
    MLV_draw_polygon(coordonnee_x_polygone_2, coordonnee_y_polygone_2, 6, MLV_COLOR_CYAN);
    
    while ((*x >= 355 && *x <= 900) && (*y >= 349 && *y <= 459)){
        MLV_get_mouse_position(x,y);
        MLV_draw_filled_polygon(coordonnee_x_polygone_3, coordonnee_y_polygone_3, 6, MLV_rgba(42, 62, 236, 2));
        MLV_actualise_window();
    }
    MLV_draw_polygon(coordonnee_x_polygone_3, coordonnee_y_polygone_3, 6, MLV_COLOR_BLUE);

    while ((*x >= 355 && *x <= 900) && (*y >= 499 && *y <= 609)){
        MLV_get_mouse_position(x,y);
        MLV_draw_filled_polygon(coordonnee_x_polygone_4, coordonnee_y_polygone_4, 6, MLV_rgba(206, 181, 29, 2));
        MLV_actualise_window();
    }
    MLV_draw_polygon(coordonnee_x_polygone_4, coordonnee_y_polygone_4, 6, MLV_COLOR_YELLOW);
}



void save_success(MLV_Font * font){

    MLV_clear_window(MLV_COLOR_BLACK);
    MLV_draw_text_with_font(400, 320, "Sauvegarde reussie !", font, MLV_rgba(255, 255, 255, 255));
    MLV_actualise_window();

}


void input_nom(){

    MLV_draw_all_input_boxes();
    MLV_actualise_window();
}