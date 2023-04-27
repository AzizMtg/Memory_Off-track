#include "enemie.h"
#include "math.h"
#define SCREEN_WIDTH 976
#define SCREEN_HEIGHT 553
#define SPRITE_WIDTH 1053
#define SPRITE_HEIGHT 161
#define FRAME_COUNT 6
#define LEFT -1
#define FRAME_HEIGHT_LEFT 0
#define FRAME_HEIGHT_RIGHT 1

SDL_Surface* load_image(const char* filename) {
    SDL_Surface* image = IMG_Load(filename);
    if (!image) {
        fprintf(stderr, "Error loading image %s: %s\n", filename, IMG_GetError());
    }
    return image;
}

void initEnnemi(Ennemi *e, char* path, int x, int y) {
    e->sprite = load_image(path);
    e->frame.w = 596/6;
    e->frame.h = 126;
    e->frame.x = 0;
    e->frame.y = 0;
    e->position.x = x;
    e->position.y = y;
    e->position.w = e->frame.w;
    e->position.h = e->frame.h;
}



void afficherEnnemi(Ennemi e, SDL_Surface* screen) {
    SDL_Rect position;
    position.x = e.position.x;
    position.y = e.position.y;
    position.w = e.frame.w;
    position.h = e.frame.h;
    SDL_BlitSurface(e.sprite, &e.frame, screen, &position);
      
}

void animerEnnemi(Ennemi* en) {
      /*en->frame.x += en->frame.w;
    if (en->frame.x >= 1053) {
        en->frame.x = 0;
   
    }*/

    en->frame.x += en->frame.w;
    
    // Check if the animation has reached or exceeded the sprite width
    if (en->frame.x + en->frame.w > en->sprite->w) {
        // Adjust the frame position to wrap around to the beginning of the sprite
        en->frame.x = 0;
    }
}


void move(Ennemi *e) {
    e->position.x += e->direction * e->speed;
    if (e->position.x <= 0) {
        e->position.x = 0;
        e->direction = 6;
    } else if (e->position.x + e->position.w >= SCREEN_WIDTH) {
        e->position.x = SCREEN_WIDTH - e->position.w;
        e->direction = -6;
   
    }
  
}
int collisionBB(SDL_Rect posp, SDL_Rect pose) {
    if (posp.y + posp.h <= pose.y) {
        return 0;
    }
    if (posp.y >= pose.y + pose.h) {
        return 0;
    }
    if (posp.x + posp.w <= pose.x) {
        return 0;
    }
    if (posp.x >= pose.x + pose.w) {
        return 0;
    }
    return 1;
}


void moveIA(Ennemi *e,  Personnage
 joueur, int direction) {
    int collision;
   SDL_Rect ennemi_rect, joueur_rect;

    ennemi_rect.x = e->position.x;
    ennemi_rect.y = e->position.y;
    ennemi_rect.w = e->sprite->w;
    ennemi_rect.h = e->sprite->h;

    joueur_rect.x = joueur.x;
    joueur_rect.y = joueur.y;
    joueur_rect.w = joueur.w;
    joueur_rect.h = joueur.h;

    collision = collisionBB(joueur_rect, ennemi_rect);

    if (collision) {
        printf("Collision detected!\n");
        
    } else {
        e->position.x += direction;
    }
}


void cleanupEnnemi(Ennemi *e) {
    if (e->sprite) {
        SDL_FreeSurface(e->sprite);
        e->sprite = NULL;
    }
}

