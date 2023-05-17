#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
/*--------ETAPE 0 DECLARATION DU BIBLIOTHEQUE SDL ---------------*/
#include <SDL/SDL_ttf.h>    // pour manipuler des texte 
#include <SDL/SDL_image.h>  // pour manipuler des image 
#include <SDL/SDL_mixer.h>  // pour manipuler des audio 
/*-------------------------------------------------------------------*/
#include "texte.h" 
#include "image.h"  
#include "music.h"  
#include "level1.h" 

#include <math.h>


#include <time.h>


int main()
{
//initialisation texte ,video et son!!!!
TTF_Init();
SDL_Init(SDL_INIT_VIDEO);
/* ---------ETAPE 1 DECLARATION DES VARIABLE----------- */
SDL_Surface *screen ;  // screen variable pointeur sur surface de l'arriere plan
image  IMAGE , IMAGE_BTN1  , IMAGE_BTN2, IMAGE_BTN3 , IMAGE_BTN4, IMAGE_SETTINGS, IMAGE_K, IMAGEP, IMAGEM ,IMAGE_ANIME1,IMAGE_ANIME2,IMAGE_ANIME3, IMAGE_ANIME5,IMAGE_ANIME4,IMAGE_ANIME6,IMAGE_fs,IMAGE_w,FIRE1,FIRE2,FIRE3,IMAGE_playb,IMAGE_loadb,IMAGE_quitb ,IMAGE_extra,IMAGE_extra1,IMAGE_extra2,IMAGE_extra3 , EXTRAback  , IMAGE_start  , IMAGE_single_player , IMAGE_multiplayer , IMAGE_return ,IMAGE_CREDIT ,IMAGE_CREDIT_back ,IMAGE_CREDIT_return ; // variable de type image 
Mix_Music  *music ;   // variable pointeur sur les audios continue 
Mix_Chunk *mus ; // variable pointeur sur les audios bref 
texte txte  ;  // variable texte 
SDL_Event   event ;  // variable pour l'evenement de l'utillis
int boucle =1 ; //compteur sur la boucle de jeu 
int boucle2 =1 , boucle3=1 , boucle4=1 , boucle5=1 ;
int v=1 ;
int k=0;
int frame=0;
 int couleurj=1  ; 
 /*.....................boucle du jeu ---------------------------*/
/*------------ETAPE 2 initialisation -----------------*/

// initialisation de l sdl
if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)==-1)
{printf("could not initialize SDL : %s .\n " ,SDL_GetError()) ;
 return -1 ; }

// initialisation de la fenetre 
 screen= SDL_SetVideoMode(992 ,744 , 32 , SDL_SWSURFACE | SDL_RESIZABLE) ; 

// initialisation des images son et texte 
initialiser_imageBACK(&IMAGE) ;
initialiser_imageBOUTON1(&IMAGE_BTN1) ; 
initialiser_imageBOUTON2(&IMAGE_BTN2) ; 
initialiser_imageBOUTON3(&IMAGE_BTN3) ; 
initialiser_imageBOUTON4(&IMAGE_BTN4) ; 
initialiser_imageSETTINGS(&IMAGE_SETTINGS) ;
initialiser_imageK(&IMAGE_K) ;
initialiser_imageBOUTONP(&IMAGEP) ;
initialiser_imageBOUTONM(&IMAGEM) ;
initialiser_imagewindowed(&IMAGE_w) ;
initialiser_imageloadb(&IMAGE_loadb) ; 
initialiser_imageplayb(&IMAGE_playb) ;
initialiser_imagequitb(&IMAGE_quitb) ; 

initialiser_imagefullscreen(&IMAGE_fs);
initialiser_imageanime1(&IMAGE_ANIME1) ;
initialiser_imageanime2(&IMAGE_ANIME2) ;
initialiser_imageanime3(&IMAGE_ANIME3) ;
initialiser_imageanime5(&IMAGE_ANIME5) ;
initialiser_imageanime4(&IMAGE_ANIME4) ;
initialiser_imageanime6(&IMAGE_ANIME6) ;


initialiser_annimation1(&FIRE1) ;
initialiser_annimation2(&FIRE2) ;
initialiser_annimation3(&FIRE3) ;

initialiser_EXTRAback(&EXTRAback) ; 
initialiser_extra(&IMAGE_extra ) ; 
initialiser_EXTRA1(&IMAGE_extra1) ;
initialiser_EXTRA2(&IMAGE_extra2) ; 
initialiser_EXTRA3(&IMAGE_extra3) ; 

initialiser_START_BACK(&IMAGE_start) ; 
initialiser_START_SINGLE_PLAYER(&IMAGE_single_player ) ; 
initialiser_START_MULTIPLAYER(&IMAGE_multiplayer) ;
initialiser_START_RETURN(&IMAGE_return) ; 

// credit 
initialiser_bouton_credit(&IMAGE_CREDIT) ;
initialiser_credit_back(&IMAGE_CREDIT_back) ; 
initialiser_bouton_credit_return(&IMAGE_CREDIT_return) ; 

initialiser_audio(music) ; 
initialiser_texte(&txte) ; 



/*-------------------------ETAPE 3 BOUCLE DE MENU --------------- (A..C) */
while(boucle) 
{
//........... -A AFFICHAGE.......... 
afficher_imageBMP(screen,IMAGE) ;//pour afficher l'image du background  
afficher_imageBTN1(screen,IMAGE_BTN1 ) ; //pour afficher le bouton play
afficher_imageBTN2(screen,IMAGE_BTN2 ) ;
afficher_imageBTN3(screen,IMAGE_BTN3 ) ; //pour afficher le bouton 3
afficher_imageBTN4(screen,IMAGE_BTN4 ) ;

afficher_imageBTN4(screen,IMAGE_extra ) ;
// credit
afficher_imageBTN4(screen,IMAGE_CREDIT ) ;

afficher_texte(screen,txte) ;
//SDL_Flip(screen);  

/*
//animation feu
if(frame==0){

SDL_Flip(screen);
SDL_Delay(500);
 
afficher_annimation(screen,FIRE1) ;

frame++;

SDL_Flip(screen);
 
}
if(frame==1){
SDL_Delay(500);
afficher_annimation(screen,FIRE2) ;
SDL_Flip(screen);  
frame++;
}
if(frame==2){
SDL_Delay(500);
afficher_annimation(screen,FIRE3) ;
SDL_Flip(screen);  
frame=0;
SDL_Delay(500);
}
*/
/*.......... -B L'INPUT................ */

   //lecture des evenements 
  //utiliser while pour tester l'input de SDL_PollEvent  
  // SDL_PollEvent permet de lire l'evenement sans bloquer la boucle du jeu 
   while(SDL_PollEvent(&event)) 
   {  
 //determination du type de l'evennement selon le type de l'eve donner par event.type on   peur mettre a jour la boucle de jeu l'evenement peut etre : 
         switch(event.type)
     { //event.type==SDL_KEYDOWN :apuis sur une touche de clavier
        case SDL_KEYDOWN :
           if (event.key.keysym.sym<=SDLK_ESCAPE) 
               boucle=0 ; 

/*if (event.key.keysym.sym==SDLK_z){
SCENE1(couleurj) ;
 

}*/



      //event.type ==SDL_MOUSEMOTION :un mouvement de la souris 
      case SDL_MOUSEMOTION :
          if (event.motion.y<=488 && event.motion.y>=300 && (event.motion.x<=1051 && event.motion.x>=340)) //il bouton play il 2 sout wa animation 
     {initialiser_audiobref(mus) ;
afficher_imageplayb( screen , IMAGE_playb) ; 
SDL_Flip(screen);//initialiser un son bref
        }
 if (event.motion.y<=668 && event.motion.y>=480 && (event.motion.x<=971 && event.motion.x>=340)) //il bouton play il 2 sout wa animation 
     {afficher_imagequitb( screen , IMAGE_quitb) ; 

        }
if (event.motion.y<=328 && event.motion.y>=130 && (event.motion.x<=791 && event.motion.x>=340)) //il bouton play il 2 sout wa animation 
     {afficher_imageloadb( screen , IMAGE_loadb) ; 

        }
           break ;

 
      //event.type == SDL_MOUSEBUTTONUP :un clic de sla souris
      
case SDL_MOUSEBUTTONDOWN : 
if (event.button.button==SDL_BUTTON_LEFT && event.motion.y<=328 && event.motion.y>=130 && (event.motion.x<=791 && event.motion.x>=340))
//SCENE2(couleurj);
level1_2(couleurj);

        if (event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=668&&event.motion.y>= 480&& event.motion.x<=791 && event.motion.x>=340))//bouton quitter trophis derniere bouton pour quitter le jeu  
       boucle=0  ;  
///////////////////////////////////////// il credit /////////////////////////////////////////////////
  if(event.motion.y<=700 && event.motion.y>=600 && (event.motion.x<=990 && event.motion.x>=790 )) // he8i taba3 il bouton extra injarbou feha 
              {  while(boucle5)  
    {afficher_imageSETTINGS(screen,IMAGE_CREDIT_back) ;  
      afficher_imageBTN4(screen,IMAGE_CREDIT_return ) ;
     

        while(SDL_PollEvent(&event)) 
       {  switch(event.type)
            {
          case  SDL_QUIT: 
	    boucle5=0;
            boucle=0 ; 

            break ;
          case SDL_MOUSEBUTTONDOWN : 
             if(event.motion.y<=600 && event.motion.y>=500 && (event.motion.x<=992 && event.motion.x>=892 ))
               boucle5=0;
                    
             break ; 


           }
       }
        SDL_Flip(screen) ;

}
                  
  }
boucle5 = 1 ;
/////////////////////////// il start ki bich  tod5ol lil lo3ba ma3ach z ///////////
 if (event.motion.y<=488 && event.motion.y>=300 && (event.motion.x<=1051 && event.motion.x>=340))

            
              {  while(boucle4)  
    {afficher_imageSETTINGS(screen,IMAGE_start) ;  
      afficher_imageBTN4(screen,IMAGE_single_player ) ;
     afficher_imageBTN4(screen,IMAGE_multiplayer) ;
    afficher_imageBTN4(screen,IMAGE_return) ;
  
        while(SDL_PollEvent(&event)) 
       {  switch(event.type)
            {
          case  SDL_QUIT: 
	    boucle4=0;
            boucle=0 ; 

            break ;
          case SDL_MOUSEBUTTONDOWN : 
            if(event.motion.y<=630 && event.motion.y>=480 && (event.motion.x<=600 && event.motion.x>=500 ))
               boucle4=0;

        if(event.motion.y<=281 && event.motion.y>=130 && (event.motion.x<=791 && event.motion.x>=340 )) /// single player
           SCENE1(couleurj) ;
    
        if(event.motion.y<=488 && event.motion.y>=300 && (event.motion.x<=791 && event.motion.x>=340 ))  // multiplayer
          multiplayer() ; 
             

               
 
              break ; 


           }
       }
        SDL_Flip(screen) ;

}
                  
  }
boucle4 = 1 ;

 /////////////////////////extra /////////////////////////////////////////     
               if(event.motion.y<=350 && event.motion.y>=200 && (event.motion.x<=992 && event.motion.x>=892 )) // he8i taba3 il bouton extra injarbou feha 
              {  while(boucle3)  
    {afficher_imageSETTINGS(screen,EXTRAback) ;  
      afficher_imageBTN4(screen,IMAGE_extra ) ;
     afficher_imageBTN4(screen,IMAGE_extra1 ) ;
    afficher_imageBTN4(screen,IMAGE_extra2 ) ;
    afficher_imageBTN4(screen,IMAGE_extra3 ) ;
        while(SDL_PollEvent(&event)) 
       {  switch(event.type)
            {
          case  SDL_QUIT: 
	    boucle3=0;
            boucle=0 ; 

            break ;
          case SDL_MOUSEBUTTONDOWN : 
             if(event.motion.y<=320 && event.motion.y>=280 && (event.motion.x<=992 && event.motion.x>=892 ))
               boucle3=0;
/////////////////////////
        if(event.motion.y<=745 && event.motion.y>=445 && (event.motion.x<=300 && event.motion.x>=0 ))
               couleurj=1;

        if(event.motion.y<=745 && event.motion.y>=445 && (event.motion.x<=650 && event.motion.x>=350 ))
               couleurj=2;

if(event.motion.y<=745 && event.motion.y>=445 && (event.motion.x<=1300 && event.motion.x>=700 ))
               couleurj=3;

 
              break ; 


           }
       }
        SDL_Flip(screen) ;

}
                  
  }
boucle3 = 1 ;
///////////////////////////menu settings/////////////////////////////////

 if(event.motion.y<=120 && event.motion.y>=80 && (event.motion.x<=992 && event.motion.x>=892 ))//bouton il setting 
{ while(boucle2) //tit5dim 3adi kima a3malna lil background bil 8abt bich tod5ol fi boucle ya3ti il taswinra imta3 il setting bich to93od 8ahra ila ma to5rig mil boucle haki ba3d qui in7ottou quitter lil setting 
    {afficher_imageSETTINGS(screen,IMAGE_SETTINGS) ;  
afficher_imageK(screen,IMAGE_K ) ;
afficher_imageM(screen,IMAGEM ) ;
afficher_imageP(screen,IMAGEP ) ;
afficher_imagefullscreen(screen,IMAGE_fs);
afficher_imagewindowed(screen,IMAGE_w );
	 afficher_imageANIME1(screen ,  IMAGE_ANIME1 ) ;


if(v==1)
     {
afficher_imageANIME3(screen ,  IMAGE_ANIME3 ) ; }
 else if(v==21)
{
 afficher_imageANIME6(screen ,  IMAGE_ANIME6 ) ;  }
  else if(v==41)
{
 afficher_imageANIME2(screen ,  IMAGE_ANIME2 ) ;  }
    else if (v==61)
{  ;afficher_imageANIME4(screen ,  IMAGE_ANIME4) ; 
 ;}
     else if (v==81)
 { ; afficher_imageANIME5(screen ,  IMAGE_ANIME5 ) ;
 ;}
        else if (v==101){   
 afficher_imageANIME1(screen ,  IMAGE_ANIME1 ) ;
	}
 SDL_Flip(screen) ; 

        while(SDL_PollEvent(&event)) 
       {  switch(event.type)
            {
  case  SDL_QUIT: 
	    boucle2=0;
            boucle=0 ; 
            break ;

case SDL_MOUSEBUTTONDOWN :
        if (event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=150&&event.motion.y>=0 && event.motion.x<=992 && event.motion.x>=892))
boucle2=0;



//if el thenya:

case SDL_KEYDOWN :
	switch(event.key.keysym.sym)
	{
	case SDLK_UP:
	 
	 do {v=v-20; Mix_VolumeMusic(MIX_MAX_VOLUME/v ) ;}while(v<0);  //bouton up
	break;
	
	case SDLK_DOWN :
	v=v+20; Mix_VolumeMusic(MIX_MAX_VOLUME/v ) ;  //bouton up
	
	break;
	}


 if (event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=399&&event.motion.y>=330 && event.motion.x<=844 && event.motion.x>=740))
  {{v=v-20; Mix_VolumeMusic(MIX_MAX_VOLUME/v ) ; }} //bouton up

 if (event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=399&&event.motion.y>=330 && event.motion.x<=699 && event.motion.x>=630))
{ v=v+20 ; Mix_VolumeMusic(MIX_MAX_VOLUME/v ) ; 
} //bouton down

//full screen
 if (event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=609&&event.motion.y>=490 && event.motion.x<=880 && event.motion.x>=600 && k==0))
{  SDL_Flip(screen) ;
	screen= SDL_SetVideoMode(2000 ,2000 , 32 ,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE) ;
k==1;}

else{ k==0;
  SDL_Flip(screen) ;
	screen= SDL_SetVideoMode(992 ,744 , 32 ,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE) ;}

  

break;



            }
       }



   }
}
boucle2=1;

          break ; 



         //event.type==SDL_QUIT:apuit sur le bouton fermer de la fenetre utiliser SDL_QUIT signifie arreter tous le systeme SDL et liberer les sources qui ont ete allouees 
        case  SDL_QUIT:  // akil x imta3 il fenetre 
            boucle=0 ; 
         break ; 
       }

 }

//............. C-MISE A JOUR DE L'ECRAN ----------------
   // la mise a jour de l'ecran consiste a le rafraichir a l'aide de SDL_FLIP() a la fin de la boucle du jeu 
SDL_Flip(screen) ; // raffraichir l'ecran

}
// liberation des ressources utilisees puis quitter : on utilise des fonctiions et on n'oublie pas de mettre SDL_QUIT a la fin 

// liberation les surfaces 

liberer_image(IMAGE) ; 
liberer_image(IMAGE_BTN1) ;

liberer_image(IMAGE_BTN2) ;
liberer_image(IMAGE_BTN3) ;
liberer_image(IMAGE_BTN4) ;
liberer_image(IMAGE_SETTINGS) ; 
liberer_image(IMAGE_K) ; 
liberer_image(IMAGEP) ;
liberer_image(IMAGEM) ;

liberer_image(IMAGE_fs);
liberer_image(IMAGE_ANIME1 ) ; 
liberer_image(IMAGE_ANIME2 ) ; 
liberer_image(IMAGE_ANIME3 ) ; 
liberer_image(IMAGE_ANIME5 ) ; 
liberer_image(IMAGE_ANIME4 ) ; 
// liberer la musique  
liberer_musique(music) ; 
liberer_musiquebref(mus) ; 

//liberer texte
liberer_texte(txte) ;
TTF_CloseFont(txte.police) ; 
//liberer animation
liberer_image(FIRE2) ;
liberer_image(FIRE1) ;
liberer_image(FIRE3) ;

liberer_image(IMAGE_loadb ) ; 
liberer_image(IMAGE_playb ) ;
liberer_image(IMAGE_quitb ) ; 

liberer_image(IMAGE_CREDIT ) ; 
liberer_image(IMAGE_CREDIT_back ) ;
liberer_image(IMAGE_CREDIT_return ) ;

// quitter le SDL 
SDL_Quit() ;  



return 0 ; 
}
