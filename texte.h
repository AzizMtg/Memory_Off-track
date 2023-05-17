#ifndef TEXTE_H
#define TEXTE_H

#include <SDL/SDL.h>
/*--------ETAPE 0 DECLARATION DU BIBLIOTHEQUE SDL ---------------*/
#include <SDL/SDL_ttf.h>    // pour manipuler des texte 
/*-------------------------------------------------------------------*/


//on a besoin de definir une structure texte :
typedef struct 
{
SDL_Surface *txt ; // un pointeur SDL_Surface pour manipuler le texte 
SDL_Rect pos_txt  ; // preciser sa position de l'image par rapport a l'ecran
SDL_Colour color_txt ; // couleur de texte en format (r,g,b) doit etre entre 0 et 255
TTF_Font *police ; // la police du texte se trouve sur un fichier de police (format.ttf)

}texte ; 



//definition pour la manipulation du texte
void initialiser_texte(texte *txte) ; 
void afficher_texte(SDL_Surface *screen , texte txte) ; 
void liberer_texte(texte txte) ; 


 
#endif 
