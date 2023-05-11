#ifndef MUSIC_H
#define MUSIC_H


#include <SDL/SDL.h>
/*--------ETAPE 0 DECLARATION DU BIBLIOTHEQUE SDL ---------------*/

#include <SDL/SDL_mixer.h>  // pour manipuler des audio 

/*-------------------------------------------------------------------*/

//definition pour la manipulation de l'audio 
void initialiser_audio(Mix_Music *music) ; 
void liberer_musique(Mix_Music *music) ;

void initialiser_audiobref(Mix_Chunk *music) ;
void liberer_musiquebref(Mix_Chunk *music) ;




#endif 
