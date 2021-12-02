#ifndef _STRUCTETRIS_
#define _STRUCTETRIS_
#define T 4
#define LONG 26
#define LARG 15
#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

typedef enum
{
  A,
  B,
  C,
  D,
  E,
  F,
  G
} FORME;

typedef struct
{
  int forme[T][T];
  int posx;
  int posy;
  FORME couleur;
} piece;

typedef piece *p_piece;

typedef struct terrain
{
  int field[LONG][LARG];
} terrain;

void init_box(p_piece box);
void init_terrain(terrain *f);
void dessine_forme(piece *box, FORME l);
void cree_piecealea(p_piece p);
void tourne_piece(p_piece p);
void affiche_terrain(terrain f);
void charger_piece_terrain(p_piece p, terrain *t);
int peut_tomber_piece(terrain *t);
void tombe_piece(terrain *t, p_piece p);
void rotat_piece_terrain(p_piece p, terrain *t);
void transforme_piece_block(terrain *t);
int peut_decaler_gauche(terrain *t);
int peut_decaler_droite(terrain *t);
void decale_piece_gauche(terrain *t, p_piece p);
void decale_piece_droite(terrain *t, p_piece p);
int est_ligne_de_bloc(terrain *t, int *p_score);
int supprimer_ligne(terrain *t, int *p_score);
int peut_tourner_piece(terrain *t, p_piece p);
void accelere_piece(terrain *t, p_piece p);

#endif
