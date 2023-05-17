
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
/*--------ETAPE 0 DECLARATION DU BIBLIOTHEQUE SDL ---------------*/

#include <SDL/SDL_mixer.h>  // pour manipuler des audio 

/*-------------------------------------------------------------------*/
#include "music.h" 
/*-------------------------------------TRAITEMENT MUSIQUE ------------------------------------*/

   /*------------------------1 initialisation de l'audio  -------------------*/

// pour initialiser l'audio en utilse la fonction de SDL_mixer : :MixOpenAudio
 
void initialiser_audio(Mix_Music *music)
{// initialiser les fonction audio de SDL_mixer
 if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS ,1024)==-1)
   {printf("%s",SDL_GetError()) ; }
//jouer le son
//pour charger la musique on utilise Mix_LoadMUS 
//pour jouer le son on utilise Mix_playMusic
//pour regler le volume en utilise Mix_VolumeMusic 
 music=Mix_LoadMUS("song.mp3"); // chargement de la musique
 Mix_PlayMusic(music,-1) ; //  jouer la musique 
 Mix_VolumeMusic(MIX_MAX_VOLUME/1) ; 
}


   /*------------------------3 liberation musique -------------------*/
void liberer_musique(Mix_Music *music)
{ Mix_FreeMusic(music) ; }




/*------------------------1 initialisation de l'audio bref -----------------*/

void initialiser_audiobref(Mix_Chunk *music) 
{Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) ; 
 music =Mix_LoadWAV("simple.wav") ; 
 Mix_PlayChannel(-1,music,0) ; 

if (music==NULL) printf("%s",SDL_GetError()) ; 
}

   /*------------------------3 liberation musique bref -----------------*/
// on utilise la fonction Mix_FreeChunk() pour la liberation de l audio
void liberer_musiquebref(Mix_Chunk *music) 
{ Mix_FreeChunk(music) ; }


