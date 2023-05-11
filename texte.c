#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
/*--------ETAPE 0 DECLARATION DU BIBLIOTHEQUE SDL ---------------*/


#include <SDL/SDL_ttf.h>    // pour manipuler des texte 
/*-------------------------------------------------------------------*/
#include "texte.h" 






/******************************* TRAITEMENT texte  ********************************************/

      /*------------------------1 initialisation du texte -------------------*/


//pour initialiser le texte on utilise TTF_init() de SDL_ttf 
//on charge la police ubuntu-B et on initialise la taille 45
//on initialise la couleur du texte a (0,0,0) puis on initialise la position du texte 
void initialiser_texte(texte *txte )
{ 
 TTF_Init; //initialiser SDL_ttf 

txte -> police = TTF_OpenFont("ubuntu-B.ttf",45) ; //chargement dune police et initialiser la taille 
txte -> color_txt.r =0 ; 
txte -> color_txt.g =0 ; 
txte -> color_txt.b = 0; 

txte -> pos_txt.x =0 ; 
txte -> pos_txt.y =650;


 txte -> police = TTF_OpenFont("Dark-Graffiti.ttf",70) ;
}







  /* ------------- affichage du texte ---------------*/

// pour ecrire le texte sur l'image du background (blitter sur un fond non uni) on utilise ici TTF_RenderText_Blended puis SDL_BlitSurface
void afficher_texte(SDL_Surface *screen , texte txte) 
{
txte.txt= TTF_RenderText_Blended(txte.police,"Main Menu" ,txte.color_txt) ; //ecrire le message bienvenue
SDL_BlitSurface(txte.txt ,NULL , screen ,& txte.pos_txt)  ; //coller la surface


} 






   /*------------------------3 liberation du texte ------------------*/

// on utilise TTF_CloseFont pour fermer la police 
// puis TTF_Quit pour arreter le SDL_ttf
void liberer_texte(texte txte) 
{
//TTF_CloseFont(txte.police) ; //fermer la police
//TTF_Quit() ; // arreter la SDL_ttf 
SDL_FreeSurface(txte.txt) ;                                    
}
