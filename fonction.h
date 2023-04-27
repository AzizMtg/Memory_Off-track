#ifndef ENEMIE_H_INCLUDED
#define ENEMIE_H_INCLUDED
#define SCREEN_WIDTH 976
#define SCREEN_HEIGHT 553
#define SPRITE_WIDTH 1053
#define SPRITE_HEIGHT 161
#define LEFT -1
#define FRAME_HEIGHT_LEFT 0
#define FRAME_HEIGHT_RIGHT 1
#define FRAME_COUNT 6
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 


typedef struct Ennemi Ennemi;
typedef struct Ennemi {
    int speed;
    int direction;
    SDL_Surface *sprite;
    SDL_Rect position;
    SDL_Rect frame;
    int etat;
    int prev_direction; 
    SDL_Rect pos;

} Ennemi;
typedef struct {
    int x;
    int y;
    int w;
    int h;
} Personnage;
void initEnnemi(Ennemi *e, char* path, int x, int y) ;
void afficherEnnemi(Ennemi e,SDL_Surface* screen);
void animerEnnemi(Ennemi* e);
void move(Ennemi *e); 
int collisionBB(SDL_Rect posp, SDL_Rect pose);
SDL_Surface* load_image(const char* filename);
void cleanupEnnemi(Ennemi *e);

#endif // ENEMIE_H_INCLUDED
