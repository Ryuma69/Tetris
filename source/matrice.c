#include <stdio.h>
#include <stdlib.h>
#define N 4




void rempli_matrice(short t[][N]){
    int i, j;
     for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            t[i][j]=rand()%10;
        }
    }
}
void affiche_matrice(int t[][N]){
    int i, j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%d ",t[i][j]);
        }printf("\n");
    }   
}

void mult_matrice(int t[][N], int m[][N], int r[][N]){

    int i, j, k;
    for(i=0; i<N; i++){
        for(j=0;j<N; j++){
            for(k=0; k<N; k++){
                r[i][j] += t[i][k] * m[k][j];
            }
        }
    }

}

void rotat_matrice(int t[][N], int r[][N]){
    int i, j;
    for(i=0;i<N; i++){
        for(j=0; j<N; j++){
            r[i][j]= t[j][(N-1)-i];
        }
    }
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            t[i][j]=r[i][j];
        }
    }
}

void init_matrice(int t[N][N]){
    int i, j;
     for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            t[i][j]=0;
        }
    }
}