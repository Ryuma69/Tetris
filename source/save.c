#include"save.h"

void viderBuffer()
{
  int c = 0;
  while (c != '\n' && c != EOF)
  {
    c = getchar();
  }
}


void save_score(int *scoring){
    /*Charger et afficher les fichier sauvegarder*/
    int tab_score[10];
    int i;
    int j = 0;
    int k = 0;

    FILE* fichier = NULL;
    for(i=0;i<10;i++){
        tab_score[i]=0;
    }
    fichier = fopen("score.txt","r+");
    for(i=0; i < 10;i++){
        if(fscanf(fichier,"%d\n",&tab_score[i])!=1){
            printf("%d erreur\n",i);
        }
    }

    for(i=0; i < 10;i++){
        k = i;
        if(tab_score[i] < *scoring){
            j = tab_score[i];
            tab_score[i] = *scoring;
            break;
        }
    }

    for(i=k+1; i<10;i++){
        k = tab_score[i];
        tab_score[i] = j;
        j = k;
    }
  
    fclose(fichier);
    fichier = fopen("score.txt","r+");

    if(fichier==NULL){
        printf("ce slot n'existe pas");
        exit(-1);
    }

    if (fichier !=NULL){
        for(i = 0; i < 10; i++){
            fprintf(fichier, "%d\n",tab_score[i]);
        }
    }
    fclose(fichier);
}

int * lecture_score(int tab[]){
  int i,j;

  FILE* fichier = NULL;
  fichier = fopen("score.txt","r");

  if(fichier==NULL){
    printf("ce slot n'existe pas");
    exit(-1);
  }

  else {
    for(i=0; i < 10;i++){
      if(fscanf(fichier,"%d\n",&j)!=1){
        printf("%d erreur\n",i);
        i=10; /* au lieu du break */
      }
      else{
        tab[i]=j;
      }
      /*printf("%d : %d\n",i+1,j);*/

    }
  }

  fclose(fichier);
  return tab;
}


void save_partie(terrain * t,char * chemin,int * score,char * nom){
  int i,j;

  FILE * fichier=NULL;

  fichier=fopen(chemin,"w+");
  if(fichier==NULL){
    printf("YOU'RE OUT OF LUCK\n");
  }

  for(i=0;i<LONG;i++){
    for(j=0;j<LARG;j++){
      fprintf(fichier,"%d ",t->field[i][j]);
    }
    fprintf(fichier,"\n");
  }

  fprintf(fichier,"%s\n",nom);

  fprintf(fichier,"%d\n",*score);
  fclose(fichier);
}

void charger_partie(terrain * t,char * chemin,int * score,char * nom){
  int i,j;
  FILE * fichier=NULL;

  fichier=fopen(chemin,"r");

  if(fichier==NULL){
    printf("CE FICHIER N'EXISTE PAS\n");
  }

  for(i=0;i<LONG;i++){
    for(j=0;j<LARG;j++){
      if(fscanf(fichier,"%d ",&t->field[i][j])!=1){
        printf("ERREUR CHARGEMENT\n");
      }
    }
  }
  if(fscanf(fichier,"%s",nom)!=1){
      printf("ERREUR CHARGEMENT DU NOM\n");
  }
  if(fscanf(fichier,"%d",score)!=1){
      printf("ERREUR CHARGEMENT DE SCORE\n");
  }
 
  fclose(fichier);
}
