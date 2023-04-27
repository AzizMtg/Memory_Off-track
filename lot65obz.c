#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include "enigme.h"
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL_rotozoom.h>

#define NB_QUESTIONS 3

void initialisation_enigme(enigma *a,char *nom_fichier)
{
    a->image=NULL;
    a->pos.x=0;
    a->pos.y=0;

    srand(time(NULL));  

    
    int question_indices[NB_QUESTIONS] = {1, 2, 3};
    for (int i = 0; i < NB_QUESTIONS - 1; i++) {
        int j = i + (rand() % (NB_QUESTIONS - i));
        int temp = question_indices[i];
        question_indices[i] = question_indices[j];
        question_indices[j] = temp;
    }

    memset(a->reponses_correctes, 0, sizeof(a->reponses_correctes));

   
    for (int i = 0; i < NB_QUESTIONS; i++) {
        int question_index = question_indices[i] - 1;

        if (a->reponses_correctes[question_index]) {
            continue;
        }

        char chemin[50];
        int bonne_reponse;

        FILE *f = fopen(nom_fichier,"r");
        if(f != NULL) {
            int j;
            for (j = 1; j <= question_indices[i]; j++) {
                fscanf(f,"%s %d",chemin,&bonne_reponse);
            }
            a->image = IMG_Load(chemin);
            fclose(f);
        }

        if (a->image != NULL) {
            a->bonne_reponse = bonne_reponse;
            a->image_gagner = IMG_Load("/home/alpha/Downloads/ff/win.png");
            a->image_perdu = IMG_Load("/home/alpha/Downloads/ff/lose.png");
            a->reponses_correctes[question_index] = 1;
            break;
        }
    }
}




void affichage_enigme(enigma a, SDL_Surface *ecran)
{   
   
    SDL_BlitSurface(a.image, NULL, ecran, &(a.pos));
    SDL_Flip(ecran);
}

int reponse_utilisateur(enigma *a, SDL_Event event)
{
    while (a->affiche != 1) {
        SDL_WaitEvent(&event);

        switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_a:
                        a->votre_reponse = 1;
                        a->affiche = 1;
                        break;
                    case SDLK_b:
                        a->votre_reponse = 2;
                        a->affiche = 1;
                        break;
                    case SDLK_c:
                        a->votre_reponse = 3;
                        a->affiche = 1;
                        break;
                }
                break;
        }
    }
}
#include "SDL/SDL_gfxPrimitives.h"


void afficher_resultat(SDL_Surface *ecran ,enigma *a) {
    static int win_count = 0;  
    
  if (a->votre_reponse == a->bonne_reponse) {
    a->image = a->image_gagner;  
    win_count++;  
    if (win_count == 3) {
    
    double angle = 0.0;
    double zoom = 0.0;
    Uint32 start_time = SDL_GetTicks();  

    
    while (angle < 360.0 && zoom < 1.0) {
        
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

       
        angle += 5.0;
        zoom += 0.01;
        if (angle >= 360.0) {
            angle -= 360.0;
        }
        if (zoom >= 1.0) {
            zoom = 1.0;
        }

        
        SDL_Surface* rotated_image = rotozoomSurface(a->image_gagner, angle, zoom, 1);

        
        SDL_Rect dest_rect = {
            .x = (ecran->w - rotated_image->w) / 2,
            .y = (ecran->h - rotated_image->h) / 2
        };

        
        SDL_BlitSurface(rotated_image, NULL, ecran, &dest_rect);
        SDL_FreeSurface(rotated_image);
        SDL_Flip(ecran);

        
        SDL_Delay(10);
    }

    
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    SDL_Rect dest_rect = {
        .x = (ecran->w - a->image_gagner->w) / 2,
        .y = (ecran->h - a->image_gagner->h) / 2
    };
    SDL_BlitSurface(a->image_gagner, NULL, ecran, &dest_rect);
    SDL_Flip(ecran);
    SDL_Delay(2000);

    SDL_Quit();  
    exit(0);
}
} else {
    a->image = a->image_perdu;  
}


double angle = 0.0;
double zoom = 0.0;
Uint32 start_time = SDL_GetTicks();  


while (angle < 360.0 && zoom < 1.0) {
    
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

    
    angle += 5.0;
    zoom += 0.01;
    if (angle >= 360.0) {
        angle -= 360.0;
    }
    if (zoom >= 1.0) {
        zoom = 1.0;
    }

    
    SDL_Surface* rotated_image = NULL;
    if (a->bonne_reponse == a->votre_reponse) {
        rotated_image = rotozoomSurface(a->image_gagner, angle, zoom, 1);
    } else {
        rotated_image = rotozoomSurface(a->image_perdu, angle, zoom, 1);
    }

    
    SDL_Rect dest_rect = {
        .x = (ecran->w - rotated_image->w) / 2,
        .y = (ecran->h - rotated_image->h) / 2
    };

    
    SDL_BlitSurface(rotated_image, NULL, ecran, &dest_rect);
    SDL_FreeSurface(rotated_image);
    SDL_Flip(ecran);

    Uint32 elapsed_time = SDL_GetTicks() - start_time;
    if (elapsed_time >= 3000) { 
        break;
    }
}

    
    a->affiche = 0;
    initialisation_enigme(a, "fichier.txt");
}





