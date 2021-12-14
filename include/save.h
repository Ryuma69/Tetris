#ifndef _SAVE_H_
#define _SAVE_H_
#include"structure.h"
#include"matrice.h"

void save_score(int *score);
void save_partie(terrain * t,char * chemin,int * score,char * nom);
void charger_partie(terrain * t,char * chemin,int * score,char * nom);
int * lecture_score(int tab[]);
void viderBuffer();







#endif
