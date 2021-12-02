#ifndef _AFFICHAGE_H
#define _AFFICHAGE_H

#include "structure.h"
#include <MLV/MLV_all.h>

void ouvrir_fenetre(char *nomfenetre);
void actualise_fenetre();

void dessine_carre(int posx, int posy, int largeur, int longueur);
void affiche_terrain_mlv(terrain *t, p_piece suivant, p_piece actuelle, int *score, MLV_Image *image);

void dessiner_triangle(int x, int y);
void dessiner_croix_one(int x, int y);
void afficher_menu(MLV_Font *font, MLV_Font *font2, MLV_Font *font3, int choix);
void dessin_score(MLV_Font *font, int *score);
void affichage_game_over(MLV_Font *font);
void animation_bouton_TA(MLV_Font *font);
void animation_bouton_MENU(MLV_Font *font);

int verif_click(int x, int y);
int verif_click_pause(int x, int y);

void affiche_piece_suivante(p_piece p);
void afficher_score();
void afficher_pause(MLV_Font *font);
void animation(MLV_Image *image, char *chemin, int frames, int layers, int nb_channels, MLV_Image *images[4]);
void afficher_menu_save(MLV_Font *font, int *x, int *y);

#endif
