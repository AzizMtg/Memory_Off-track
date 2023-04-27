#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include <SDL/SDL_ttf.h>    
#include <SDL/SDL_image.h>  
#include <SDL/SDL_mixer.h>  


#include "lot2.h"  

int main()
{
TTF_Init();
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen ;  

SDL_Event   event ;   
int boucle =1 ;
int test = 0 ; 
Mix_Music  *music ; 
int pas=6;



ScoreInfo J;
ScoreInfo Tri[3];




int i = 0 ,i2=48 ,i3=48 ,boucle2=1 ; 

texte   texte_score ;
background B,A,A2 ;
int direction=-1;
int con=0;








if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)==-1)
{printf("could not initialize SDL : %s .\n " ,SDL_GetError()) ;
 return -1 ; }



 screen= SDL_SetVideoMode(1200 ,600, 32 ,SDL_RESIZABLE | SDL_HWSURFACE) ; 


A.s=0;
A.sc=screen;
A2.s=0;
A2.sc=screen;
J.nomjoueur=1;
J.score=50;
J.temps=60;





initialiser_texte_score(&texte_score );


initBack(&B) ;
initanimation(&A);
initanimation_deux(&A2);
bestScore("Best.txt", Tri); 
initialiser_audio(music) ; 

while(boucle) 
{


afficherback(screen,B) ;


if(B.camera_pos.x>1500){
afficher_texte_score(screen, Tri, texte_score);}






 
 while(SDL_PollEvent(&event)) 
   {

  switch(event.type){
   
       case SDL_KEYDOWN :
           if (event.key.keysym.sym == SDLK_RIGHT) 
              {  
                
                  direction = 0;
                        con=1;
               }
             
          if (event.key.keysym.sym==SDLK_LEFT)  
                {

                 
                 direction = 1;
                        con=1;
                }

     

           

         
         if (event.key.keysym.sym==SDLK_DOWN)  
               {  
                  
                  direction = 3;
                        con=1;  }

           if (event.key.keysym.sym==SDLK_UP)   
                {
                  
                    direction = 2;
                        con=1; }  

		

 

          break ;  
                               
     case  SDL_QUIT:  
            boucle=0 ; 
         break ; 
     
      case SDL_KEYUP:       
           
        
          if (event.key.keysym.sym == SDLK_RIGHT) 
            {
           
           
          if (direction == 0) 
                {con=0; }
            }


           if (event.key.keysym.sym == SDLK_LEFT)
           {
           
            
             if (direction == 1)
                        {
                           con=0;
                        }
            }
           
         



          if (event.key.keysym.sym==SDLK_UP)   
                {
                  
                   if (direction == 2) 
                        {
                            con=0;
                        }
                        }
        if (event.key.keysym.sym==SDLK_DOWN) 
             { if (direction == 3) 
                         {con=0;}
             }
          
          
  

          break;
 
     

     }
  
  }

if (con==1) 
{scrolling(&B,direction,pas); }








animer_image(&A); 
animer_image_deux(&A2); 


SDL_Flip(screen) ; 

}


saveScore(J, "Best.txt");




liberer_musique(music) ; 
liberer_image(B) ; 
liberer_image(A) ; 
liberer_image(A2);
return 0 ; 

SDL_Quit() ;


}





























