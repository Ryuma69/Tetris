#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <time.h>
#include "structure.h"
#include "matrice.h"
#include "affichage.h"

void init_box(p_piece box)
{

  init_matrice(box->forme);
  box->posx = 6;
  box->posy = 1;
}

void init_terrain(terrain *f)
{
  int i, j;
  for (i = 0; i < LONG; i++)
  {
    for (j = 0; j < LARG; j++)
    {
      if (i == LONG - 1 || j == 0 || j == LARG - 1)
        f->field[i][j] = 3;
      else
        f->field[i][j] = 0;
    }
  }
}

void affiche_terrain(terrain f)
{
  int i, j;
  for (i = 0; i < LONG; i++)
  {
    for (j = 0; j < LARG; j++)
    {
      printf("%d ", f.field[i][j]);
    }
  }
}

void dessine_forme(piece *box, FORME l)
{
  switch (l)
  {
  case A:
    box->forme[0][2] = 1;
    box->forme[1][2] = 1;
    box->forme[2][2] = 1;
    box->forme[3][2] = 1;
    box->couleur = A; /*CYAN*/
    break;
  case B:
    box->forme[1][1] = 1;
    box->forme[2][1] = 1;
    box->forme[2][2] = 1;
    box->forme[2][3] = 1;
    box->couleur = B; /* ORANGE*/
    break;
  case C:
    box->forme[1][3] = 1;
    box->forme[2][1] = 1;
    box->forme[2][2] = 1;
    box->forme[2][3] = 1;
    box->couleur = C; /*BLEU*/
    break;
  case D:
    box->forme[1][1] = 1;
    box->forme[2][1] = 1;
    box->forme[1][2] = 1;
    box->forme[2][2] = 1;
    box->couleur = D; /*JAUNE*/
    break;
  case E:
    box->forme[1][1] = 1;
    box->forme[1][2] = 1;
    box->forme[2][2] = 1;
    box->forme[2][3] = 1;
    box->couleur = E; /*ROUGE*/
    break;
  case F:
    box->forme[2][1] = 1;
    box->forme[2][2] = 1;
    box->forme[1][2] = 1;
    box->forme[1][3] = 1;
    box->couleur = F; /*VERT*/
    break;
  case G:
    box->forme[2][1] = 1;
    box->forme[2][2] = 1;
    box->forme[1][2] = 1;
    box->forme[2][3] = 1;
    box->couleur = G; /*VIOLET*/
    break;
  }
}

void cree_piecealea(p_piece p)
{

  FORME f = rand() % 7;
  init_box(p);
  dessine_forme(p, f);
  p->couleur = f;
}

void tourne_piece(p_piece p)
{
  int r[T][T];
  init_matrice(r);
  rotat_matrice(p->forme, r);
}
void rotat_piece_terrain(p_piece p, terrain *t)
{
  int i, j;
  if (peut_tourner_piece(t, p))
  {
    tourne_piece(p);
    for (i = 0; i < LONG; i++)
    {
      for (j = 0; j < LARG; j++)
      {
        if (t->field[i][j] == 1)
          t->field[i][j] = 0;
      }
    }
  }
  charger_piece_terrain(p, t);
}

void charger_piece_terrain(p_piece p, terrain *t)
{
  int i, j;
  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 4; j++)
    {
      if (p->forme[i][j] == 1)
      {
        t->field[i + p->posy][j + p->posx] = 1;
      }
    }
  }
}

void tombe_piece(terrain *t, p_piece p)
{
  int i, j;
  if (peut_tomber_piece(t))
  {
    for (i = LONG - 1; i > 0; i--)
    {
      for (j = LARG - 1; j > 0; j--)
      {
        if (t->field[i][j] == 1)
        {
          t->field[i][j] = 0;
        }
      }
    }
    p->posy++;
    charger_piece_terrain(p, t);
  }
}
void accelere_piece(terrain *t, p_piece p)
{
  tombe_piece(t, p);
  charger_piece_terrain(p, t);
  MLV_actualise_window();
  tombe_piece(t, p);
  charger_piece_terrain(p, t);
  MLV_actualise_window();
}
int peut_tomber_piece(terrain *t)
{
  int i, j;
  for (i = LONG - 1; i >= 0; i--)
  {
    for (j = LARG - 1; j >= 0; j--)
    {
      if (t->field[i][j] == 1)
      {
        if (t->field[i + 1][j] == 3 || t->field[i + 1][j] == 2)
        {
          return 0;
        }
      }
    }
  }
  return 1;
}

void transforme_piece_block(terrain *t)
{
  int i, j;
  for (i = 0; i < LONG; i++)
  {
    for (j = 0; j < LARG; j++)
    {
      if (t->field[i][j] == 1)
        t->field[i][j] = 2;
    }
  }
}

int peut_decaler_gauche(terrain *t)
{
  int i, j;
  for (i = 0; i < LONG - 1; i++)
  {
    for (j = 1; j < LARG - 1; j++)
    {
      if (t->field[i][j] == 1)
      {
        if (t->field[i][j - 1] == 3)
        {
          return 0;
        }
        else
        {
          if (t->field[i][j - 1] == 2)
          {
            return 0;
          }
        }
      }
    }
  }
  return 1;
}
int peut_decaler_droite(terrain *t)
{
  int i, j;
  for (i = 0; i < LONG - 1; i++)
  {
    for (j = 1; j < LARG - 1; j++)
    {
      if (t->field[i][j] == 1)
      {
        if (t->field[i][j + 1] == 3)
        {
          return 0;
        }
        else
        {
          if (t->field[i][j + 1] == 2)
          {
            return 0;
          }
        }
      }
    }
  }
  return 1;
}

void decale_piece_gauche(terrain *t, p_piece p)
{
  int i, j;
  if (peut_decaler_gauche(t))
  {
    for (i = LONG - 1; i > 0; i--)
    {
      for (j = LARG - 1; j > 0; j--)
      {
        if (t->field[i][j] == 1)
        {
          t->field[i][j] = 0;
        }
      }
    }
    p->posx--;
    charger_piece_terrain(p, t);
  }
}

void decale_piece_droite(terrain *t, p_piece p)
{
  int i, j;
  if (peut_decaler_droite(t))
  {
    for (i = LONG - 1; i > 0; i--)
    {
      for (j = LARG - 1; j > 0; j--)
      {
        if (t->field[i][j] == 1)
        {
          t->field[i][j] = 0;
        }
      }
    }
    p->posx++;
    charger_piece_terrain(p, t);
  }
}

int est_ligne_de_bloc(terrain *t, int *p_score)
{
  int i, j, acc;
  acc = 0;
  for (i = 0; i < LONG; i++)
  {
    for (j = 0; j < LARG; j++)
    {
      if (t->field[i][j] == 2)
        acc++;
    }
    if (acc == 13)
    {
      *p_score += 100;
      return i;
    }
    else
      acc = 0;
  }

  return -1;
}

int supprimer_ligne(terrain *t, int *p_score)
{
  int n;
  int i, j;
  n = est_ligne_de_bloc(t, p_score);
  if (n == -1)
  {
    return 1;
  }
  else
  {
    for (j = 0; j < LARG - 1; j++)
    {
      if (t->field[n][j] == 2)
      {
        t->field[n][j] = 0;
      }
    }
    for (i = n - 1; i > 0; i--)
    {
      for (j = LARG - 1; j > 0; j--)
      {
        if (t->field[i][j] == 2)
        {
          t->field[i][j] = 0;
          t->field[i + 1][j] = 2;
        }
      }
    }
    supprimer_ligne(t, p_score);
  }
  return 0;
}

int peut_tourner_piece(terrain *t, p_piece p)
{
  int i, j;
  for (i = p->posy; i <= p->posy + 4; i++)
  {
    for (j = p->posx; j <= p->posx + 4; j++)
    {
      if (t->field[i][j] == 2 || t->field[i][j] == 3)
      {
        return 0;
      }
    }
  }
  return 1;
}
