#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include <SDL/SDL_ttf.h>    
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>  
/*-------------------------------------------------------------------*/ 
#include <math.h>
#include "lot1.h"  

/*--------------------------------------------------------------------------------------------*/
void initPerso(personne *p  ) 
{
p->url="main.png" ; 
p->sprite=IMG_Load(p->url) ; 
if (p->sprite == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
p->pos_Screen.x=0 ; 
p->pos_Screen.y=350; 
p->pos_Sprite.x=0 ; 
p->pos_Sprite.y=1092; 

p->pos_Sprite.w=260; 
p->pos_Sprite.h=273 ;


if (p->direction ==1  ) 
{p->pos_Sprite.x=0 ; 
p->pos_Sprite.y=1092; 

p->pos_Sprite.w=260; 
p->pos_Sprite.h=273 ; }

else 
{p->pos_Sprite.x=0 ; 
p->pos_Sprite.y=1365; 


p->pos_Sprite.w=260; 
p->pos_Sprite.h=273 ; }

p->vitesse=5;   
p->acceleration=0;   
 
p->up=0 ; 
}

void movePerso (personne *p , Uint32 dt)   
{
double dx ; 


if (p->acceleration == 0 ) 
{
  if (p->direction==1 )  
     {p->vitesse=0;
       if (p->pos_Sprite.x <=520 ) 
         {p->pos_Sprite.x=p->pos_Sprite.x+244 ; }
      else 
          { p->pos_Sprite.x=244 ; 
            p->pos_Sprite.y=1092; 
          }
       
       if ( p->pos_Screen.x<=500) 
                  {  p->pos_Screen.x=p->pos_Screen.x+5 ;      
                     p->pos_Screen.y=p->pos_Screen.y ;
                  } 
     
 
      
     } 
 else if  (p->direction==0 )   
     { 

      if (p->pos_Sprite.x <=520)
         {p->pos_Sprite.x=p->pos_Sprite.x+244; }
      else 
          { p->pos_Sprite.x=260; 
            p->pos_Sprite.y=1365; 
          } 
       
         if ( p->pos_Screen.x>0)  
                   p->pos_Screen.x=p->pos_Screen.x-5; 
    }
  
else if  (p->direction== 2  ) 
{p->pos_Sprite.x=0 ; 
 p->pos_Sprite.y=1092;
if (p->d == -1 ) 
{if (p->pos_Sprite.x ==260 ) 
         {p->pos_Sprite.x=p->pos_Sprite.x+260 ; }
      else 
          { p->pos_Sprite.x=0 ; 
            p->pos_Sprite.y=0; 
          } 
}}
else if  (p->direction== 3  )   
{p->pos_Sprite.x=0; 
 p->pos_Sprite.y=1365;
if (p->d == -1 ) 
{if (p->pos_Sprite.x ==260 ) 
         {p->pos_Sprite.x=p->pos_Sprite.x+260 ; }
      else 
          { p->pos_Sprite.x=0 ; 
            p->pos_Sprite.y=273; 
          } 
}}
else {return ; }

}

else 
{ if (p->vitesse <5 )
   { dx = 0.5 * p->acceleration * dt * dt + p->vitesse * dt;
     if (p->direction==1 )  
     {
      if (p->pos_Sprite.x <=520  ) 
         {p->pos_Sprite.x=p->pos_Sprite.x+260 ; }
      else 
          { p->pos_Sprite.x=260 ; 
            p->pos_Sprite.y=1092; 
          }
        
       if ( p->pos_Screen.x<200) 
                  {  p->pos_Screen.x+=dx;      
                     p->pos_Screen.y=p->pos_Screen.y ;
                  }   
      
     } 
 else if  (p->direction==0 )  
     {
 
      if (p->pos_Sprite.x <=520)
         {p->pos_Sprite.x=p->pos_Sprite.x+260 ; }
      else 
          { p->pos_Sprite.x=260; 
            p->pos_Sprite.y=1365; 
          } 
        
         if ( p->pos_Screen.x>0) 
                   p->pos_Screen.x-=dx; 
    }

else if  (p->direction== 2  )  
{p->pos_Sprite.x=0 ; 
 p->pos_Sprite.y=1092;}
else if  (p->direction== 3  )  
{p->pos_Sprite.x=0; 
 p->pos_Sprite.y=1365;}
else {return ; }

 p->vitesse = p->vitesse+ p->acceleration * dt; 
   
 if (p->vitesse < 0)
    {
        p->vitesse = 0;
        p->acceleration = 0;
    }

     
   }

}

}








void saut( personne *p,int dt, int posinit)  
{     
if (p->up == 1  ) 
{
  if (p->direction==1 || p->direction== 2  )  
    { 
       p->pos_Sprite.x=0 ; 
       p->pos_Sprite.y=548; 

      if (p->pos_Sprite.x <=260 ) 
         {p->pos_Sprite.x=p->pos_Sprite.x+244 ; }
      else 
          { p->pos_Sprite.x=0; 
            p->pos_Sprite.y=1092; 
          }

       
       if ( posinit>400) 
         {p->pos_Screen.x =p->pos_Screen.x ;  
          p->pos_Screen.y=p->pos_Screen.y-5;
          }
 
      
     } 
   else if  (p->direction==0 ||p->direction== 3 )  
     { 
        p->pos_Sprite.x=0 ; 
        p->pos_Sprite.y=819; 

       if (p->pos_Sprite.x <=260 ) 
         {p->pos_Sprite.x=p->pos_Sprite.x+244 ; }
       else 
          { p->pos_Sprite.x=0; 
            p->pos_Sprite.y=1365; 
          }

      
       if ( posinit>400) 
           {p->pos_Screen.x =p->pos_Screen.x ;  
            p->pos_Screen.y=posinit-5;}
    }


}

 
}


void saut_personnage ( personne *p, Uint32 dt, int posx_absolu, int posy_absolu) 
{

if (p->up==3 && p->direction==1 || (p->up==3 && p->direction==2) ) 
{ 

if ( posy_absolu>0 ) 
    {p->pos_Screen.x =p->pos_Screen.x+100 ;  
     p->pos_Screen.y=posy_absolu-50;}

}


if (p->up==3 && p->direction==0 && p->pos_Screen.x>0 || (p->up==3 && p->direction==3 && p->pos_Screen.x>0 )  ) 
{ 

if ( posy_absolu>0) 
    {p->pos_Screen.x =p->pos_Screen.x-100 ;  
     p->pos_Screen.y=posy_absolu-50;}

}
}



void drouj ( personne *p, int posx_absolu, int posy_absolu) 
{

if (p->up==5 || p->direction==1 || p->direction==3 )  
{ 
if ( posy_absolu>0) 
    {p->pos_Screen.x =p->pos_Screen.x+50 ;  
     p->pos_Screen.y=posy_absolu-50;}
}
if (p->up==5 || p->direction==2 ||  p->direction==0 )  
{
if ( posy_absolu>0) 
    {p->pos_Screen.x =p->pos_Screen.x-50 ;  
     p->pos_Screen.y=posy_absolu-50;}
}
}



 void animerPerso (personne* p) 
{  

 
     if (p->pos_Sprite.x <=520 ) 
         {p->pos_Sprite.x=p->pos_Sprite.x+244 ; }
      else 
          { p->pos_Sprite.x=244 ; 
            p->pos_Sprite.y=1092;}

     
}





void initialiser_coeur(personne *p ,int i ,int *vie) 
{

p->url="coeur.png" ; 
p->sprite=IMG_Load(p->url) ; 
if (p->sprite == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
p->pos_Screen.x=500 ; 
p->pos_Screen.y=0; 
p->pos_Sprite.x=0 ; 
p->pos_Sprite.y=0; 

p->pos_Sprite.w=200-i; 
p->pos_Sprite.h=42 ;

*vie =*vie-1 ; 

}





void initialiser_texte(texte *txte , int k ,int k2 ,int *score )
{ 
 TTF_Init; 

txte -> police = TTF_OpenFont("ubuntu-B.ttf",45) ;
txte -> color_txt.r =0 ; 
txte -> color_txt.g =0 ; 
txte -> color_txt.b = 0; 

txte -> pos_txt.x =200 ; 
txte -> pos_txt.y =0;

char ch1[] = {k,k2, '\0'};

strcpy(txte->ch, ch1);
 txte -> police = TTF_OpenFont("Dark-Graffiti.ttf",70) ;

*score = *score +1 ; 
}



void afficher_texte(SDL_Surface *screen , texte txte) 
{

txte.txt= TTF_RenderText_Blended(txte.police,txte.ch ,txte.color_txt) ; 
SDL_BlitSurface(txte.txt ,NULL , screen ,& txte.pos_txt)  ; 

} 


void liberer_texte(texte txte) 
{
SDL_FreeSurface(txte.txt) ;                                    
}




void afficherPerso(personne p, SDL_Surface * screen)	
{
SDL_BlitSurface(p.sprite ,&p.pos_Sprite   , screen , &p.pos_Screen ) ; 

}


void liberer_image(personne p) 
{
SDL_FreeSurface(p.sprite) ;
}


void initialiser_imageBACK(image *image)
{

image->url="enemy.png" ; 
image->img=IMG_Load(image->url) ; 
if (image->img == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
image->pos_img_ecran.x=0 ; 
image->pos_img_ecran.y=0 ; 

image->pos_img_affiche.x=0 ; 
image->pos_img_affiche.y=0; 

image->pos_img_affiche.h=1000 ; 
image->pos_img_affiche.w=800 ; 

}

void afficher_imageBMP(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL , screen , &image.pos_img_ecran ) ; 
}


void liberer_imageb(image p) 
{
SDL_FreeSurface(p.img) ;
}



void initialiser_feu(image *imgbtn) 
{

imgbtn->url="feu.png" ; 
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}

imgbtn->pos_img_ecran .x=300; 
imgbtn->pos_img_ecran.y=450 ;

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0;

imgbtn->pos_img_affiche.w=100;
imgbtn->pos_img_affiche.h=100 ; 


}


void afficher_feu(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL   , screen ,&image.pos_img_ecran ) ; 
 
}



void initialiser_lost(personne *p ) 
{

p->url="lost.jpg" ; 
p->sprite=IMG_Load(p->url) ; 
if (p->sprite == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
p->pos_Screen.x=400 ; 
p->pos_Screen.y=200; 
p->pos_Sprite.x=0 ; 
p->pos_Sprite.y=0; 

p->pos_Sprite.w=196; 
p->pos_Sprite.h=293 ;

}












void initialiser_audiobrefj1(Mix_Chunk *music) 
{Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) ; 
 music =Mix_LoadWAV("simple.wav") ; 
 Mix_PlayChannel(-1,music,0) ; 

if (music==NULL) printf("%s",SDL_GetError()) ; 
}
void initialiser_audiobrefj2(Mix_Chunk *music) 
{Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) ; 
 music =Mix_LoadWAV("song.wav") ; 
 Mix_PlayChannel(-1,music,0) ; 

if (music==NULL) printf("%s",SDL_GetError()) ; 
}
void initialiser_audiobrefj3(Mix_Chunk *music) 
{Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) ; 
 music =Mix_LoadWAV("song3.wav") ; 
 Mix_PlayChannel(-1,music,0) ; 

if (music==NULL) printf("%s",SDL_GetError()) ; 
}


   
void liberer_musiquebrefj(Mix_Chunk *music) 
{ Mix_FreeChunk(music) ; }



/*-------------------------joueur 2 -------------------*/

void init(personne * p, int numperso)   //  initialisation de la perosnnage principale
{
p->url="joueur2.png" ; 
p->sprite=IMG_Load(p->url) ; 
if (p->sprite == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
p->pos_Screen.x=0 ; 
p->pos_Screen.y=200; 
p->pos_Sprite.x=0 ; 
p->pos_Sprite.y=1092; 

p->pos_Sprite.w=260; 
p->pos_Sprite.h=273 ;


if (p->direction ==1  ) //i9adam 
{p->pos_Sprite.x=0 ; 
p->pos_Sprite.y=1092; 

p->pos_Sprite.w=260; 
p->pos_Sprite.h=273 ; }

else  // iwa5ar 
{p->pos_Sprite.x=0 ; 
p->pos_Sprite.y=1365; 


p->pos_Sprite.w=260; 
p->pos_Sprite.h=273 ; }

p->vitesse=5;  // initialisation du vitessse a une valeur   
p->acceleration=0;   // acceleration constante 0 
 
p->up=0 ; // initialisation du champ  saut a 0 
}






