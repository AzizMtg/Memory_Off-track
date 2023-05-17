#ifndef IMAGE_H
#define IMAGE_H


#include <SDL/SDL.h>
/*--------ETAPE 0 DECLARATION DU BIBLIOTHEQUE SDL ---------------*/
#include <SDL/SDL_image.h>  // pour manipuler des image 

/*-------------------------------------------------------------------*/
#include "image.h" 
#define SCREEN_H 410
#define SCREEN_W 640




// on qa besoin de definir une structure image :
typedef struct 
{ // url une chaine de caractere conenant l'emplacement du fichier image
  char *url ; 

 //partie de l'image doit etre afficher 
 SDL_Rect    pos_img_affiche; // son type est SDL_Rect qui definit la position de l'image par rapport a l'ecran
 
 // position de l'image par rapport a l'ecran 
 SDL_Rect      pos_img_ecran ; // son type est SDL_Rect qui precise quelle partie de l'image doit etre afficher 
 
 SDL_Surface    *img ;   // declaration d'un pointeur de surface pour manipuler l'image

}image; 


  
// definition des fenetre des fonction 

//definition pour la manipulation de l'image 
void initialiser_imageBACK(image *image)     ; 
void initialiser_imageBOUTON1(image *imgbtn) ; 
void initialiser_imageBOUTON2(image *imgbtn) ; 
void initialiser_imageBOUTON3(image *imgbtn) ; 
void initialiser_imageBOUTON4(image *imgbtn) ; 
void initialiser_imageSETTINGS(image *image) ;
void initialiser_imageK(image *image) ;
void initialiser_imageBOUTONP(image *imgbtn) ;
void initialiser_imageBOUTONM(image *imgbtn) ;

void initialiser_imageanime1(image *imgbtn) ;
void initialiser_imageanime2(image *imgbtn) ;
void initialiser_imageanime3(image *imgbtn) ; 
void initialiser_imageanime5(image *imgbtn) ;
void initialiser_imageanime4(image *imgbtn) ;
void initialiser_imageanime6(image *imgbtn) ;
void initialiser_imagefullscreen(image *imgbtn) ;
void initialiser_imagewindowed(image *imgbtn) ;

void initialiser_annimation1(image *imgbtn) ; 
void initialiser_annimation2(image *imgbtn) ; 
void initialiser_annimation3(image *imgbtn) ; 

void initialiser_imageloadb(image *imgbtn) ;
void initialiser_imagequitb(image *imgbtn) ;
void initialiser_imageplayb(image *imgbtn) ;


void initialiser_EXTRAback(image *image) ; 
void initialiser_extra(image *image);
void initialiser_EXTRA1(image *image) ;
void initialiser_EXTRA2(image *image) ; 
void initialiser_EXTRA3(image *image) ; 

void initialiser_START_BACK(image *image) ; 
void initialiser_START_SINGLE_PLAYER(image *image) ; 
void initialiser_START_MULTIPLAYER(image *image) ; 
void initialiser_START_RETURN(image *image)  ; 

void afficher_imageBMP(SDL_Surface *screen , image image) ; 
void afficher_imageBTN1(SDL_Surface *screen , image image ) ; 
void afficher_imageBTN2(SDL_Surface *screen , image image ) ; 
void afficher_imageBTN3(SDL_Surface *screen , image image ) ;
void afficher_imageBTN4(SDL_Surface *screen , image image ) ;
void afficher_imageSETTINGS(SDL_Surface *screen , image image) ;
void afficher_imageK(SDL_Surface *screen , image image) ;
void afficher_imageP(SDL_Surface *screen , image image );
void afficher_imageM(SDL_Surface *screen , image image );
void afficher_imagefullscreen(SDL_Surface *screen , image image );
void afficher_annimation(SDL_Surface *screen , image image );

void afficher_imageloadb(SDL_Surface *screen , image image) ; 
void afficher_imageplayb(SDL_Surface *screen , image image) ; 
void afficher_imagequitb(SDL_Surface *screen , image image) ; 

void afficher_imageANIME1(SDL_Surface *screen , image image ) ;
void afficher_imagewindowed(SDL_Surface *screen , image image );
void afficher_imageANIME2(SDL_Surface *screen , image image ) ;
void afficher_imageANIME3(SDL_Surface *screen , image image ) ;
void afficher_imageANIME5(SDL_Surface *screen , image image );
void afficher_imageANIME4(SDL_Surface *screen , image image );
void afficher_imageANIME6(SDL_Surface *screen , image image );
void liberer_image(image image) ; 




#endif 











