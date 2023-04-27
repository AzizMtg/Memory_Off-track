#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enigme.h"


int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *ecran = SDL_SetVideoMode(1080, 900 , 32, SDL_HWSURFACE);
    SDL_Event event;
    enigma b;
    initialisation_enigme(&b, "fichier.txt");

    printf("%d", b.aleatoire);

    int cond = 1; 
    int scan_res = 0;
    int continuer = 1;
    while (continuer)
    {
        if (cond == 1) {
            initialisation_enigme(&b, "fichier.txt");
            affichage_enigme(b, ecran);
            cond = 0;
        }
        if (scan_res == 1) {
            afficher_resultat(ecran, &b);
            cond = 1; 
            scan_res = 0;
        }
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    continuer = 0;
                    break;
                case SDL_KEYDOWN:
                    if (cond == 0) { 
                        reponse_utilisateur(&a, event);
                        if (b.affiche == 1) {
                            scan_res = 1;
                        }
                    }
                    break;
            }
        }
    }
    SDL_FreeSurface(b.image);
    SDL_FreeSurface(b.image_gagner);
    SDL_FreeSurface(b.image_perdu);
    SDL_Quit();
    return 0;
}



