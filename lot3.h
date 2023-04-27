#ifndef lot3_H
#define lot3_H
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>
#include <SDL/SDL_ttf.h> 
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h> 
#include"lot3.h"

typedef struct 
{
	SDL_Rect position_play;
	SDL_Surface *sprite;
}play;



typedef struct 
{
	SDL_Rect position_perso;
 	SDL_Surface *sprite;
}Personne;



typedef struct 
{ SDL_Surface *joueur;

	SDL_Rect position_mini;
	SDL_Surface *sprite;
}minimap;


typedef struct  {
    
    SDL_Surface *sprite;
   
    SDL_Surface *surface;
SDL_Rect pos;
   
    int direction;
    int num;
  

    SDL_Rect posScreen;
    SDL_Rect posSprite;
   
    int nb_frames[4];         
} minimap1;






typedef struct temps {
    char entree[32];
    int countdown_en_cours; 
    int go; 
    int secondes_restantes;
    int duree_totale; 
    int min; 
    int sec; 
    Uint32 t1; 
    SDL_Surface *texte;
    TTF_Font *police;
    SDL_Rect position;
} temps;

typedef struct 
{
	SDL_Rect position_anim;
	SDL_Surface *sprite;
}anim;



void initmap( minimap *m);
void afficherminimap (minimap m, SDL_Surface * screen);
void free_minimap (minimap *m);

void init_play( play *j);
void afficher_play (play j, SDL_Surface * screen);
void free_play (play *j);

void init_anim( anim *a);
void init_anim1( anim *a1);
void afficher_anim (anim a, SDL_Surface * screen);
void free_anim (anim *a);





//temps siwar 
void initialiser_temps(temps *t, int duree_totale, int countdown);
void afficher_temps(temps *t, SDL_Surface *screen);
void free_temps(temps *t);




//animationsiwar
void initialiseMinimap(minimap1 *n, int nb_frames_right, int nb_frames_left) ;
void animerMinimap(minimap1 *n);
void libererMinimap(minimap1 *n);


void update_1_(SDL_Rect *prochain , SDL_Rect *principal, SDL_Rect *Pminimap, int distance, int longueur,int longueurM);
void update_2_(SDL_Rect *prochain , SDL_Rect *principal, SDL_Rect *Pminimap, int distance, int longueur,int longueurM);
void mouvement(Personne *p ,Personne *pM ,Personne *pMprochaine, int distance, int longueur,int longueurM , SDL_Surface *masked , int sens);
SDL_Color GetPixel(SDL_Surface *Background, int x, int y);
int collisionPP( Personne p, SDL_Surface * Masque);
void MAJMinimap(SDL_Rect posJoueur, minimap* v, SDL_Rect camera, int redimensionnement);

#endif
