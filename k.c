#include <SDL/SDL.h>
#include "enemie.h"
#include <SDL/SDL_image.h> 
#include "math.h"
#define FRAMES_PER_SECOND 6000


const int SCREEN_BPP = 32;


int main()
{
    SDL_Event event;
    int quit = 0;
    SDL_Surface* obstacle = NULL;
    SDL_Rect obstacle_pos;
    SDL_Surface* image;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Surface *screen = SDL_SetVideoMode(976, 553, 32, SDL_SWSURFACE);
SDL_Surface* backbuffer = SDL_CreateRGBSurface(SDL_SWSURFACE, 976, 553, 32, 0, 0, 0, 0);
    Ennemi ennemi;
    SDL_Surface* background = IMG_Load("background.jpg");
if (!background) {
    printf("Failed to load background image: %s\n", IMG_GetError());
    return 0;
} else {
    printf("Background image loaded successfully!\n");
}
if (SDL_GetError()[0] != '\0') {
    printf("SDL error: %s\n", SDL_GetError());
}

SDL_BlitSurface(background, NULL, screen, NULL);
SDL_Surface* SCREEN = IMG_Load("enemie.png");
initEnnemi(&ennemi,"enemie.png",0,400);
    obstacle_pos.x = 150;
    obstacle_pos.y = 400;
   obstacle = IMG_Load("ob.jpg");

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        } 
        SDL_BlitSurface(background, NULL, screen, NULL);
        afficherEnnemi(ennemi,screen);
        animerEnnemi(&ennemi);
        move(&ennemi);
SDL_BlitSurface(obstacle, NULL, screen, &obstacle_pos);
SDL_BlitSurface(background, NULL, backbuffer, NULL);
    afficherEnnemi(ennemi, backbuffer);
    
    SDL_BlitSurface(backbuffer, NULL, screen, NULL);
   
SDL_Flip(screen);
    }
   
 SDL_Delay(10);
    cleanupEnnemi(&ennemi);
    SDL_FreeSurface(background);
    SDL_Quit();

    return 0;

}

