#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>
/*--------ETAPE 0 DECLARATION DU BIBLIOTHEQUE SDL ---------------*/
#include <SDL/SDL_ttf.h>    // pour manipuler des texte 
#include <SDL/SDL_image.h>  // pour manipuler des image 
#include <SDL/SDL_mixer.h>  // pour manipuler des audio 
/*-------------------------------------------------------------------*/ 
#include <math.h>

#include "level1.h"  

/*--------------------------manipulation de l'image ----------------------------------*/
       /*-----------------------initialisation -----------------------*/
void initPerso(personne *p  , int v  )  //  initialisation de la perosnnage principale
{
switch (v ) 
{case 1 : 
p->url="main.png" ; 
  break ; 
case 2 : 
p->url="joueur2.png" ; 
  break ;
case 3 : 
p->url="joueur3.png" ; 
  break ;}  

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


if (p->direction ==1  ) //i9adam 
{p->pos_Sprite.x=0 ; 
p->pos_Sprite.y=1092; 

p->pos_Sprite.w=260; 
p->pos_Sprite.h=273 ; }

else if (p->direction == 0  )  // iwa5ar 
{p->pos_Sprite.x=0 ; 
p->pos_Sprite.y=1365; 


p->pos_Sprite.w=260; 
p->pos_Sprite.h=273 ; }

/*else if (p->d ==-1  )  // attack imin 
{p->pos_Sprite.x=0 ; 
p->pos_Sprite.y=0; 


p->pos_Sprite.w=260 ; 
p->pos_Sprite.h=273 ;}*/

else 
{p->pos_Screen.x=0 ; 
p->pos_Screen.y=350; 
p->pos_Sprite.x=0 ; 
p->pos_Sprite.y=1092; 

p->pos_Sprite.w=260; 
p->pos_Sprite.h=273 ;}

p->vitesse=5;  // initialisation du vitessse a une valeur   
p->acceleration=0;   // acceleration constante 0 
 
p->up=0 ; // initialisation du champ  saut a 0 
}

void movePerso (personne *p , Uint32 dt)   
{
double dx ; 

/*-------------------------------------------------*/
if (p->acceleration == 0 ) 
{
  if (p->direction==1 )  
     {p->vitesse=0;// ha8oma il spritesheet il tsawer kifech yo8hrou
       if (p->pos_Sprite.x <=520 ) 
         {p->pos_Sprite.x=p->pos_Sprite.x+244 ; }
      else 
          { p->pos_Sprite.x=244 ; 
            p->pos_Sprite.y=1092; 
          }
         // ha8ouma i9adem bil position 
       if ( p->pos_Screen.x<1000) 
                  {  p->pos_Screen.x=p->pos_Screen.x+5 ;      
                     p->pos_Screen.y=p->pos_Screen.y ;
                  } 
     
 
      
     } 
 else if  (p->direction==0 )  //bich yerja3  
     { 
        // ha8ouma ili i7arkou il sprite sheet ili yirja3 fiha il personnage 
      if (p->pos_Sprite.x <=520)
         {p->pos_Sprite.x=p->pos_Sprite.x+244; }
      else 
          { p->pos_Sprite.x=260; 
            p->pos_Sprite.y=1365; 
          } 
       // ha8ouma iwa5ar bil position 
         if ( p->pos_Screen.x>0)  
                   p->pos_Screen.x=p->pos_Screen.x-5; 
    }
  
else if  (p->direction== 2  ) // wa9if 
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
else if  (p->direction== 3  )  // wa9if 
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
     {// ha8oma il spritesheet il tsawer kifech yo8hrou
      if (p->pos_Sprite.x <=520  ) 
         {p->pos_Sprite.x=p->pos_Sprite.x+260 ; }
      else 
          { p->pos_Sprite.x=260 ; 
            p->pos_Sprite.y=1092; 
          }
         // ha8ouma i9adem bil position 
       if ( p->pos_Screen.x<200) 
                  {  p->pos_Screen.x+=dx;      
                     p->pos_Screen.y=p->pos_Screen.y ;
                  }   
      
     } 
 else if  (p->direction==0 )  //bich yerja3  
     {
        // ha8ouma ili i7arkou il sprite sheet ili yirja3 fiha il personnage 
      if (p->pos_Sprite.x <=520)
         {p->pos_Sprite.x=p->pos_Sprite.x+260 ; }
      else 
          { p->pos_Sprite.x=260; 
            p->pos_Sprite.y=1365; 
          } 
       // ha8ouma iwa5ar bil position 
         if ( p->pos_Screen.x>0) 
                   p->pos_Screen.x-=dx; 
    }

else if  (p->direction== 2  ) // wa9if 
{p->pos_Sprite.x=0 ; 
 p->pos_Sprite.y=1092;}
else if  (p->direction== 3  )  // wa9if 
{p->pos_Sprite.x=0; 
 p->pos_Sprite.y=1365;}
else {return ; }

 p->vitesse = p->vitesse+ p->acceleration * dt; // mettre a jour la vitesse en fonction de l acceleration
   
 if (p->vitesse < 0)
    {
        p->vitesse = 0;
        p->acceleration = 0;
    }

     
   }

}

}












/*------------------------saut personne --------------------------------------*/
void saut( personne *p,int dt, int posinit)  // saut du personnage  ( posinit la position initiale du personnage ) saut normale du personnage 
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

       //bich  yitla3 il fou9 bil position 
       if ( posinit>400) 
         {p->pos_Screen.x =p->pos_Screen.x ;  
          p->pos_Screen.y=p->pos_Screen.y-5;
          }
 
      
     } 
   else if  (p->direction==0 ||p->direction== 3 )  //bich yerja3  
     { 
        p->pos_Sprite.x=0 ; 
        p->pos_Sprite.y=819; 

       if (p->pos_Sprite.x <=260 ) 
         {p->pos_Sprite.x=p->pos_Sprite.x+244 ; }
       else 
          { p->pos_Sprite.x=0; 
            p->pos_Sprite.y=1365; 
          }

       //bich  yitla3 il fou9 bil position 
       if ( posinit>400) 
           {p->pos_Screen.x =p->pos_Screen.x ;  
            p->pos_Screen.y=posinit-5;}
    }


}

 
}















void drouj ( personne *p, int posx_absolu, int posy_absolu) //  yitla3 il drouj 
{

if (p->up==5 || p->direction==1 || p->direction==3 )  
{ //bich  yitla3 il fou9 bil parabole  
if ( posy_absolu>0) 
    {p->pos_Screen.x =p->pos_Screen.x+50 ;  
     p->pos_Screen.y=posy_absolu-50;}
}
if (p->up==5 || p->direction==2 ||  p->direction==0 )  
{ //bich  yitla3 il fou9 bil parabole  
if ( posy_absolu>0) 
    {p->pos_Screen.x =p->pos_Screen.x-50 ;  
     p->pos_Screen.y=posy_absolu-50;}
}



}

void saut_personnage ( personne *p, Uint32 dt, int posx_absolu, int posy_absolu) // saut parabolique 
{

if (p->up==3 && p->direction==1 ) 
{ //bich  yitla3 il fou9 bil parabole  
if ( posy_absolu>0 ) 
    {p->pos_Screen.x =p->pos_Screen.x+100 ;  // 9otlou yimchi distance x 100 wa yitla3 50
     p->pos_Screen.y=posy_absolu-50;}

}
if (p->up==3 && p->direction==0 && p->pos_Screen.x>0 ) 
{ //bich  yitla3 il fou9 bil parabole  
if ( posy_absolu>0) 
    {p->pos_Screen.x =p->pos_Screen.x-100 ;  // 9otlou yimchi distance x 100 wa yitla3 50
     p->pos_Screen.y=posy_absolu-50;}

}

if (p->up==3 && p->direction==2)  // saut para wa9if imin
{ //bich  yitla3 il fou9 bil parabole  
if ( posy_absolu>0 ) 
    {p->pos_Screen.x =p->pos_Screen.x+100 ;  // 9otlou yimchi distance x 100 wa yitla3 50
     p->pos_Screen.y=posy_absolu-50;}

}
if (p->up==3 && p->direction==3 && p->pos_Screen.x>0 )  // saut paraboli wa9if isar 
{ //bich  yitla3 il fou9 bil parabole  
if ( posy_absolu>0) 
    {p->pos_Screen.x =p->pos_Screen.x-100 ;  // 9otlou yimchi distance x 100 wa yitla3 50
     p->pos_Screen.y=posy_absolu-50;}

}


}




/*----------------------------- animation du personnage */

 void animerPerso (personne* p) 
{  

 
     if (p->pos_Sprite.x <=520 ) 
         {p->pos_Sprite.x=p->pos_Sprite.x+244 ; }
      else 
          { p->pos_Sprite.x=244 ; 
            p->pos_Sprite.y=1092;}

     
}







       /*----------------------affichage -----------------------*/


void afficherPerso(personne p, SDL_Surface * screen)	// affichage du personnage principale  
{
SDL_BlitSurface(p.sprite ,&p.pos_Sprite   , screen , &p.pos_Screen ) ; 

}


    




       /*----------------------liberation  -----------------------*/
void liberer_perso_image(personne p)  
{
SDL_FreeSurface(p.sprite) ;
}





void initialiser_feu(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="feu.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
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

// -------------affichage du image boutton 1 ---------------
void afficher_feu(SDL_Surface *screen , image1 image )
{ 
SDL_BlitSurface(image.img ,NULL   , screen ,&image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du bonton play dans le screen
 
}

/***************** manipulation vie du joueur ********************/
// initialisation image  


void initialiser_coeur(personne *p ,int i ) 
{

p->url="coeur.png" ; 
p->sprite=IMG_Load(p->url) ; 
if (p->sprite == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
p->pos_Screen.x=150 ; 
p->pos_Screen.y=0; 
p->pos_Sprite.x=200 +i ; 
p->pos_Sprite.y=0; 

p->pos_Sprite.w=200; 
p->pos_Sprite.h=189 ;

}


/*****************manipulation du score ***************/ 


void initialiser_texte1(texte1 *txte , int k ,int k2 )
{ 
 TTF_Init; 

txte -> police = TTF_OpenFont("ubuntu-B.ttf",45) ;
txte -> color_txt.r =0 ; 
txte -> color_txt.g =0 ; 
txte -> color_txt.b = 0; 

txte -> pos_txt.x =100 ; 
txte -> pos_txt.y =0;

char ch1[] = {k,k2, '\0'};

strcpy(txte->ch, ch1);
 txte -> police = TTF_OpenFont("Dark-Graffiti.ttf",70) ;
}



void afficher_texte1(SDL_Surface *screen , texte1 txte) 
{

txte.txt= TTF_RenderText_Blended(txte.police,txte.ch ,txte.color_txt) ; 
SDL_BlitSurface(txte.txt ,NULL , screen ,& txte.pos_txt)  ; 

} 


void liberer_texte1(texte1 txte) 
{
SDL_FreeSurface(txte.txt) ;                                    
}
/*********************************************************/


void initialiser_lost(personne *p ) 
{

p->url="lost.png" ; 
p->sprite=IMG_Load(p->url) ; 
if (p->sprite == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
p->pos_Screen.x=0 ; 
p->pos_Screen.y=0; 
p->pos_Sprite.x=0 ; 
p->pos_Sprite.y=0; 

p->pos_Sprite.w=1200; 
p->pos_Sprite.h=600 ;

}

void liberer_imageb(image1 p) 
{
SDL_FreeSurface(p.img) ;
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



//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////   khalil   ///////////////////////////////////////////////////


void initBack(background *b)
{
b->url="level1.png"; 
b->img=IMG_Load(b->url) ; 
if (b->img == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
b->pos_img_ecran.x=0; 
b->pos_img_ecran.y=0; 
b->camera_pos.x=0; 
b->camera_pos.y=50; 
b->camera_pos.h=SCREEN_H ; 
b->camera_pos.w=SCREEN_W ;

}


void initanimation(background *b)
{
b->url="fire.png"; 
b->img=IMG_Load(b->url) ; 
if (b->img == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
b->pos_img_ecran.x=30; 
b->pos_img_ecran.y=30; 
b->camera_pos.x=0; 
b->camera_pos.y=0; 
b->camera_pos.h=SCREEN_H ; 
b->camera_pos.w=SCREEN_W ;

}
void afficherback(SDL_Surface *screen,background b )
{ 
SDL_BlitSurface(b.img ,&b.camera_pos , screen , &b.pos_img_ecran ) ; 
}

void scrolling(background *b, int direction,int pas) {
    switch (direction) {
        case 0:
            b->camera_pos.x += pas;
            break;
        case 1:
            b->camera_pos.x = b->camera_pos.x - pas;
            break;
        case 3:
            b->camera_pos.y = b->camera_pos.y + pas;
            break;
        case 2:
            b->camera_pos.y = b->camera_pos.y - pas;
            break;
    }

    
    if (b->camera_pos.x < 0) {
        b->camera_pos.x = 0;
    }
    if (b->camera_pos.x + b->camera_pos.w > 3200) {
        b->camera_pos.x = 3200 - b->camera_pos.w;
    }

  
    if (b->camera_pos.y < 0) {
        b->camera_pos.y = 0;
    }
    if (b->camera_pos.y + b->camera_pos.h > 700) {
        b->camera_pos.y =700 - b->camera_pos.h;
    }
}

void liberer_image1(background b) 
{
SDL_FreeSurface(b.img) ;
}

void saveScore(ScoreInfo s, char *fileName) {
char buffer[50];
    FILE *fichier = fopen(fileName, "a");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier %s.\n", fileName);
        exit(1);
    }

    
    sprintf(buffer, "%d %d %d\n", s.nomjoueur, s.score, s.temps);

    fputs(buffer, fichier);

    // Fermer le fichier
    fclose(fichier);
}



void bestScore(char *filename, ScoreInfo t[]) {
   
    FILE *fichier = fopen(filename, "r");

    
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier %s.\n", filename);
    }

    int i = 0;
    while (fscanf(fichier, "%d %d %d", &t[i].nomjoueur, &t[i].score, &t[i].temps) == 3) {
        i++;
    }

    fclose(fichier);

    int n = i;
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (t[i].score < t[j].score || (t[i].score == t[j].score && t[i].temps > t[j].temps)) {
                ScoreInfo tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
        }
    }

    printf("Les trois meilleurs scores:\n");
    int nbMeilleursScores = 0;
    for (i = 0; i < n; i++) {
        if (nbMeilleursScores < 3) {
            printf("%d. %d: %d points en %d secondes\n", nbMeilleursScores+1, t[i].nomjoueur, t[i].score, t[i].temps);
            nbMeilleursScores++;
        } else if (t[i].score == t[i-1].score && t[i].temps == t[i-1].temps) {
            printf("%d. %d: %d points en %d secondes\n", nbMeilleursScores, t[i].nomjoueur, t[i].score, t[i].temps);
        } else {
            break;
        }
    }
}

void animer_image(background *b) {
    // Variables pour stocker les informations sur la feuille de sprite
    int largeur_sprite = 642/7;
    int hauteur_sprite = 314;
   
    b->camera_pos.w = largeur_sprite;
    b->camera_pos.h = hauteur_sprite;
if(b->s==50)
b->s=0;
b->s=b->s+1;
    // Définir le temps de rafraîchissement de l'animation
    
       
        // Afficher la prochaine image
        SDL_BlitSurface(b->img,&b->camera_pos, b->sc, &b->pos_img_ecran);

       if(b->s%10==0){
        b->camera_pos.x += largeur_sprite;
        if (b->camera_pos.x >= 642) {
            b->camera_pos.x = 0;
        

        // Rafraîchir l'écran
        SDL_Flip(b->sc);
    }
  }
}


void animer_image_deux(background *b) {
    // Variables pour stocker les informations sur la feuille de sprite
    int largeur_sprite = 750/7;
    int hauteur_sprite = 143;
   
    b->camera_pos.w = largeur_sprite;
    b->camera_pos.h = hauteur_sprite;
if(b->s==50)
b->s=0;
b->s=b->s+1;
    // Définir le temps de rafraîchissement de l'animation
    
       
        // Afficher la prochaine image
        SDL_BlitSurface(b->img,&b->camera_pos, b->sc, &b->pos_img_ecran);

       if(b->s%10==0){
        b->camera_pos.x += largeur_sprite;
        if (b->camera_pos.x >= 750) {
            b->camera_pos.x = 0;
        

        // Rafraîchir l'écran
        SDL_Flip(b->sc);
    }
  }
}





void initanimation_deux(background *b)
{
b->url="hour.png"; 
b->img=IMG_Load(b->url) ; 
if (b->img == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
b->pos_img_ecran.x=800; 
b->pos_img_ecran.y=0; 
b->camera_pos.x=0; 
b->camera_pos.y=0; 
b->camera_pos.h=SCREEN_H ; 
b->camera_pos.w=SCREEN_W ;

}





void initialiser_texte_score(texte1 *txte )
{ 
 TTF_Init; //initialiser SDL_ttf 
txte -> police = TTF_OpenFont("Dark-Graffiti.ttf",30) ;

txte -> color_txt.r =0 ; 
txte -> color_txt.g =0 ; 
txte -> color_txt.b = 0; 

txte -> pos_txt.x =1200; 
txte -> pos_txt.y =700;


 
}







void afficher_texte_score(SDL_Surface *screen, ScoreInfo t[], texte1 txte) {
    char message[100];
    int x = 700;
    int y = 200;
    int w, h;

    

    for (int i = 0; i < 3; i++) {
        snprintf(message, 100, "%d. %d: %d points en %d secondes", i+1, t[i].nomjoueur, t[i].score, t[i].temps);
        txte.txt = TTF_RenderText_Blended(txte.police, message, txte.color_txt);
        txte.pos_txt.x = x;
        txte.pos_txt.y = y;
        SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);
        SDL_FreeSurface(txte.txt);
        TTF_SizeText(txte.police, message, &w, &h);
        y += h + 10;
    }

    SDL_Flip(screen);
}



   /*------------------------3 liberation du texte ------------------*/

// on utilise TTF_CloseFont pour fermer la police 
// puis TTF_Quit pour arreter le SDL_ttf
void liberer_texte_score(texte1 txte) 
{
//TTF_CloseFont(txte.police) ; //fermer la police
//TTF_Quit() ; // arreter la SDL_ttf 
SDL_FreeSurface(txte.txt) ;                                    
}

void initialiser_audio1(Mix_Music *music)
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

void liberer_musique1(Mix_Music *music)
{ Mix_FreeMusic(music) ; }

//aziz


void initialiser_BACK(image1 *image)
{
image->url="k.png" ; 
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

image->pos_img_affiche.h=521 ; 
image->pos_img_affiche.w=595 ; 

}

void initialiser_BOUTON1(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="head.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}

imgbtn->pos_img_ecran .x=100; 
imgbtn->pos_img_ecran.y=50 ;
imgbtn->pos_img_ecran.w=200 ;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0;
imgbtn->pos_img_affiche.w=0;
imgbtn->pos_img_affiche.h=0 ; 

//on initialise la position du premier deux boutons au milieu de l'ecran su l'axe des x (a l'horizentale ) et au niveau de 1/3 de l'ecran sur l'axe y (a la verticale )
//imgbtn->pos_img_affiche.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/2) ;
//imgbtn->pos_img_affiche.y=((SCREEN_H-imgbtn->pos_img_affiche.h)/3) ;
}

void initialiser_BOUTON2(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="hurts.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}

imgbtn->pos_img_ecran .x=100; 
imgbtn->pos_img_ecran.y=50 ;
imgbtn->pos_img_ecran.w=200 ;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0;
imgbtn->pos_img_affiche.w=0;
imgbtn->pos_img_affiche.h=0 ; 

//on initialise la position du premier deux boutons au milieu de l'ecran su l'axe des x (a l'horizentale ) et au niveau de 1/3 de l'ecran sur l'axe y (a la verticale )
//imgbtn->pos_img_affiche.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/2) ;
//imgbtn->pos_img_affiche.y=((SCREEN_H-imgbtn->pos_img_affiche.h)/3) ;
}

//initilaiserimagesousmenu fl game
void initialiser_imageloadsettings(image1 *image)
{
image->url="sousmenu.png" ; 
image->img=IMG_Load(image->url) ; 
if (image->img == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
image->pos_img_ecran.x=400 ; 
image->pos_img_ecran.y=100 ; 

image->pos_img_affiche.x=0 ; 
image->pos_img_affiche.y=0; 

image->pos_img_affiche.h=0 ; 
image->pos_img_affiche.w=0 ; 

}





//l'emplacement du fichier image bouton
//pour la fonction d'initialisation de l'image bouton on definit l'url de l'emplacement du fichier de l'image 


 


       /*-------------------- 2 affichage de l'image ----------------------*/
 // la fonction SDL_BlitSurface() permet de  coller et afficher l'image sur  screen


// ----------affichage du background ------------
void afficher_BMP(SDL_Surface *screen , image1 image )
{ 
SDL_BlitSurface(image.img ,NULL , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du back sur  screen
}

void afficher_BTN1(SDL_Surface *screen , image1 image )
{ 
SDL_BlitSurface(image.img ,NULL   , screen ,&image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du bonton play dans le screen
 
}

void afficher_BTN2(SDL_Surface *screen , image1 image )
{ 
SDL_BlitSurface(image.img ,NULL   , screen ,&image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du bonton play dans le screen
 
}


   /*------------------------3 liberation image -------------------*/
// on utilise SDL_FreeSurface()
void liberer_imagee(image1 image) 
{
SDL_FreeSurface(image.img) ;
}


/*-------------------------------------TRAITEMENT MUSIQUE ------------------------------------*/

   /*------------------------1 initialisation de l'audio  -------------------*/

// pour initialiser l'audio en utilse la fonction de SDL_mixer : :MixOpenAudio
 
void initialiser_audioe(Mix_Music *music)
{// initialiser les fonction audio de SDL_mixer
 if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS ,1024)==-1)
   {printf("%s",SDL_GetError()) ; }
//jouer le son
//pour charger la musique on utilise Mix_LoadMUS 
//pour jouer le son on utilise Mix_playMusic
//pour regler le volume en utilise Mix_VolumeMusic 
 music=Mix_LoadMUS("happy.mp3"); // chargement de la musique
 Mix_PlayMusic(music,-1)  ;//  jouer la musique 
 Mix_VolumeMusic(MIX_MAX_VOLUME/3.5) ; 
}


   /*------------------------3 liberation musique -------------------*/
void liberer_musiquee(Mix_Music *music)
{ Mix_FreeMusic(music) ; }





//enigme:

void afficherEnigme(SDL_Surface* screen, enigme e ) {
   
//declarations
    SDL_Colour text_color;
    SDL_Surface* questionsurface;
    SDL_Surface* r1surface;
    SDL_Surface* r2surface;
    SDL_Surface* r3surface;

    SDL_Rect questionpos;
    SDL_Rect r1pos;
    SDL_Rect r2pos;
    SDL_Rect r3pos;

    TTF_Font* font = NULL;
    int font_loaded = 0;

    // Load the font
    while (!font_loaded) {
        font = TTF_OpenFont("MontserratAlternates-Black.otf", 30);
        if (font == NULL) {
            printf("Could not load font. Retrying in 1 second...\n");
            SDL_Delay(1000); // Wait 1 second before retrying
        } else {
            font_loaded = 1;
        }
    }
    
    // Load text surfaces
    text_color.r=255;
    text_color.g=255;
    text_color.b=255;
    questionsurface = TTF_RenderText_Blended(font, e.question, text_color);
    r1surface = TTF_RenderText_Blended(font, e.r1, text_color);
    r2surface = TTF_RenderText_Blended(font, e.r2, text_color);
    r3surface = TTF_RenderText_Blended(font, e.r3, text_color);
    
    // Set text positions
    questionpos.x=5;
    questionpos.y=10;

    r1pos.x=70;
    r1pos.y=120;

    r2pos.x=70;
    r2pos.y=150;

    r3pos.x=70;
    r3pos.y=180;
    
    // Blit text surfaces onto screen surface
    SDL_BlitSurface(questionsurface, NULL, screen, &questionpos);
    SDL_BlitSurface(r1surface, NULL, screen, &r1pos);
    SDL_BlitSurface(r2surface, NULL, screen, &r2pos);
    SDL_BlitSurface(r3surface, NULL, screen, &r3pos);
    
   
    SDL_Flip(screen);

    // Clean up
    TTF_CloseFont(font);
    SDL_FreeSurface(questionsurface);
    SDL_FreeSurface(r1surface);
    SDL_FreeSurface(r2surface);
    SDL_FreeSurface(r3surface);
}




/* // Free surfaces and font
    SDL_FreeSurface(questionsurface);
    SDL_FreeSurface(r1surface);
    SDL_FreeSurface(r2surface);
    SDL_FreeSurface(r3surface);
    TTF_CloseFont(font); */



void genererEnigme(char* filename, enigme* e) {
  FILE* fp = fopen(filename, "r");

    // Generate a random number between 1 and 3 (the number of questions in the file)
    int random_question_index = rand() % 3 + 1;

    // Select the random question from the file
    int current_question_index = 0;
    char line[500];
    while (fgets(line, sizeof(line), fp)) {
        switch (current_question_index % 5) {
            case 0:
                strcpy(e->question, line);
                break;
            case 1:
                strcpy(e->r1, line);
                break;
            case 2:
                strcpy(e->r2, line);
                break;
            case 3:
                strcpy(e->r3, line);
                break;
            case 4:
                if (current_question_index / 5 == random_question_index - 1) {
                    e->numbr = atoi(line);
                    // Found the random question, stop reading the file
                    fclose(fp);
                    return;
                }
                break;
        }
        current_question_index++;
    }

    // Don't forget to close the file
    fclose(fp);
}



void animate(enigme *e) {
    int frame = 0;
    char *image_names[3] = {"alz1.png", "alz2.png", "alz3.png"};

    // Load the images into the Enigme struct
    for (int i = 0; i < 3; i++) {
        e->images[i].url = image_names[i];
        e->images[i].img = IMG_Load(image_names[i]);
        e->images[i].pos_img_affiche.x = 500;
        e->images[i].pos_img_affiche.y = 600;
        e->images[i].pos_img_ecran.x = 356;
        e->images[i].pos_img_ecran.y = 14;
    }

    while (frame < 3) {
        // Blit the current image onto the screen
        SDL_BlitSurface(e->images[frame].img, NULL, e->screen, &e->images[frame].pos_img_ecran);
        SDL_Flip(e->screen);

        // Wait for some time
        SDL_Delay(280);

        // Remove the current image from the screen

        // Free the memory allocated for the current image
        SDL_FreeSurface(e->images[frame].img);

        // Move to the next image

        frame++;
    }
}


//load w save


void save (personne p, background b, char* nomfich)
{

FILE * fp= fopen(nomfich, "w");
if (fp!= NULL){

fprintf(fp,"%d %d %hd %hd %hd %hd\n",p.vie,p.score,b.camera_pos.x,b.camera_pos.y,p.pos_Screen.x,p.pos_Screen.y);
fclose(fp);
}else{

printf("unable to write into file");

}



}


void load(personne* p, background* b, char* nomfich) {
    FILE * fp= fopen(nomfich, "r");
    if (fp != NULL) {
        fscanf(fp, "%d %d %hd %hd %hd %hd\n",&p->vie, &p->score, &b->camera_pos.x, &b->camera_pos.y, &p->pos_Screen.x, &p->pos_Screen.y);
printf("loada");
        fclose(fp);
    } else {
        printf("unable to read from file");
    }
}



























//end of aziz




///////////////////////////////////siwar//////////////////////////////////////////


//minimap


void initmap( minimap *m)
{
	m->position_mini.x=550;
	m->position_mini.y=0;
	m->sprite=NULL;
    m->sprite=IMG_Load("minimap1.png");
}

void afficherminimap (minimap m, SDL_Surface * screen)
{
	
    SDL_BlitSurface(m.sprite, NULL, screen, &m.position_mini);
   
}
void free_minimap (minimap *m)
{
    SDL_FreeSurface(m->sprite);
}


//chrono+countdown


 
void initialiser_temps(temps *t, int duree_totale, int countdown_en_cours)
{
    t->texte = NULL;
    t->position.x = 10;
    t->position.y = 500;
    t->police = NULL;
    t->police = TTF_OpenFont("avocado.ttf", 40);
    strcpy(t->entree, "");
    t->go = 1;

    // Initialiser en mode chrono
    t->secondes_restantes = 0;
    t->countdown_en_cours = 0;

    // Si le mode countdown est activé, initialiser en mode countdown
    if (countdown_en_cours) {
        t->countdown_en_cours = 1;
        t->secondes_restantes = duree_totale;
    }

    t->duree_totale = duree_totale;
  t->t1 = SDL_GetTicks();
}



void afficher_temps(temps *t, SDL_Surface *screen)
{
    SDL_Color couleurblanche = {255, 255, 255};

 if (t->countdown_en_cours)
{
   

    // Compte à rebours
    if (t->go  && t->secondes_restantes > 0)
    {
        Uint32 t2 = SDL_GetTicks();
        Uint32 millisecondesEcoulees = t2 - t->t1;
        Uint32 secondesEcoulees = millisecondesEcoulees / 1000;

        if (t->secondes_restantes != t->duree_totale - secondesEcoulees)
        {
            t->secondes_restantes = t->duree_totale - secondesEcoulees;
            if (t->secondes_restantes == 0) {
                t->go = 0; // arrêter le chrono à 00:00
                t->countdown_en_cours = 0; // arrêter le compte à rebours
            } else {
                t->min = t->secondes_restantes / 60;
                t->sec = t->secondes_restantes % 60;
                sprintf(t->entree, "%02d:%02d", t->min, t->sec);
            }
        }
    }
}

    else
    {
        // Chronomètre
        if (t->go== 1)
        {
            Uint32 t2 = SDL_GetTicks();
            Uint32 millisecondesEcoulees = t2 - t->t1;
            Uint32 secondesEcoulees = millisecondesEcoulees / 1000;

            if (t->secondes_restantes != secondesEcoulees)
            {
                t->secondes_restantes = secondesEcoulees;
                t->min = t->secondes_restantes / 60;
                t->sec = t->secondes_restantes % 60;
                sprintf(t->entree, "%02d:%02d", t->min, t->sec);
            }
        }
    }

    // Afficher le temps restant
    t->texte = TTF_RenderText_Blended(t->police, t->entree, couleurblanche);
    SDL_BlitSurface(t->texte, NULL, screen, &t->position);
   // SDL_FreeSurface(t->texte);
}

void free_temps(temps *t)
{
    SDL_FreeSurface(t->texte);
    if (t->police != NULL) // vérifier si la police est bien chargée avant de la libérer
    {
        TTF_CloseFont(t->police);
    }
}




//animation 2


//animation demande 
 
void initialiseMinimap(minimap1 *n, int nb_frames_right, int nb_frames_left, int screen_x, int screen_y) {
    n->direction = 0;
    n->posSprite = (SDL_Rect) { screen_x, screen_y, 100, 450};
    n->nb_frames[6] = nb_frames_right;
    n->nb_frames[4] = nb_frames_left;

    // Charger l'image du sprite
    n->sprite = IMG_Load("minimap_spritesheet.png");

    // Calculer la taille d'un frame
    int largeur_sprite = n->sprite->w;
    int hauteur_sprite = n->sprite->h;
    int NBC = (nb_frames_right > nb_frames_left) ? nb_frames_right : nb_frames_left;
    n->posSprite.w = largeur_sprite / NBC;
    n->posSprite.h = hauteur_sprite ;
 n->posSprite.x = screen_x;
    n->posSprite.y = screen_y;
}


void animerMinimap(minimap1 *n) { 
    static Uint32 temps_precedent = 0;
    Uint32 temps_actuel = SDL_GetTicks();
    int largeur_sprite = n->sprite->w;
    int hauteur_sprite = n->sprite->h;
    int NBC = (n->nb_frames[0] > n->nb_frames[1]) ? n->nb_frames[0] : n->nb_frames[1];
    int delai_frame = 350; // Durée souhaitée entre chaque frame en millisecondes

    if (temps_actuel - temps_precedent >= delai_frame) {
        // Changer la position du sprite
        if (n->posSprite.x == largeur_sprite - n->posSprite.w) {
            n->posSprite.x = 0;
        } else {
            n->posSprite.x += n->posSprite.w;
        }
        n->posSprite.y = n->direction * n->posSprite.h;

        // dernier frame de la direction actuelle
        int current_direction = n->direction * NBC;
        if (n->posSprite.x == 0 && n->posSprite.y == current_direction + (n->nb_frames[n->direction] - 1) * n->posSprite.h) {
            n->direction = (n->direction + 1) % 2;
        }
        
        temps_precedent = temps_actuel;
    }
}




void libererMinimap(minimap1 *n) {
    if (n->sprite != NULL) {
        SDL_FreeSurface(n->sprite);
        n->sprite = NULL;
    }
    n->direction = 0;
    n->posSprite = (SDL_Rect) { 0, 0, 0, 0 };
    n->nb_frames[0] = 0;
    n->nb_frames[1] = 0;
}



//animation fl minimap


//animation ajoute
void init_anim( anim *a)

{
	a->position_anim.x=950;
	a->position_anim.y=100;
	a->sprite=NULL;
    a->sprite=IMG_Load("what.png");
    
    
}

void afficher_anim(anim a, SDL_Surface *screen)
{
    static int visible = 1;  
    static int lastTime = 0; 
    
    int currentTime = SDL_GetTicks();
    
    // toggle the visibility of the image every 500 milliseconds (0.5 seconds
    if (currentTime - lastTime > 500) {
        visible = !visible;
        lastTime = currentTime;
    }
    
    if (visible) {
        SDL_BlitSurface(a.sprite, NULL, screen, &a.position_anim);
       
    }
    
   
    SDL_Delay(5);
}

void free_anim (anim *a)
{
    SDL_FreeSurface(a->sprite);
    
     
}



//collision 


SDL_Color GetPixel(SDL_Surface *Background, int x, int y)
{
        
        SDL_Color color;
        Uint32 col = 0;
        //Determine position

                char *pixelPosition = (char*)Background->pixels;
                //Offset by Y
                pixelPosition += (Background->pitch * y);
                //Offset by X
                pixelPosition += (Background->format->BytesPerPixel * x);
                //Copy pixel data
                memcpy(&col, pixelPosition, Background->format->BytesPerPixel);
                //Convert to color
                SDL_GetRGB(col, Background->format, &color.r, &color.g, &color.b);

                return (color);
}


int collisionPP( personne p, SDL_Surface * Masque)
{
    SDL_Color test ,couleurnoir= {255,0,0};

    SDL_Rect pos[8];
    pos[0].x=p.position_perso.x-100;
    pos[0].y=p.position_perso.y;
    pos[1].x=p.position_perso.x+p.position_perso.w/2-100;
    pos[1].y=p.position_perso.y;
    pos[2].x=p.position_perso.x+p.position_perso.w-100;
    pos[2].y=p.position_perso.y;
    pos[3].x=p.position_perso.x;
    pos[3].y=p.position_perso.y+p.position_perso.h/2;   
    pos[4].x=p.position_perso.x-100;
    pos[4].y=p.position_perso.y+p.position_perso.h;
    pos[5].x=p.position_perso.x+p.position_perso.w/2-100;
    pos[5].y=p.position_perso.y+p.position_perso.h;
    pos[6].x=p.position_perso.x+p.position_perso.w-100;
    pos[6].y=p.position_perso.y+p.position_perso.h;    
    pos[7].x=p.position_perso.x+p.position_perso.w-100;
    pos[7].y=p.position_perso.y+p.position_perso.h/2;


     int collision=0 , x ,y ;

     for(int i=0 ;i<8 && collision==0;i++)
     {
        x=pos[i].x;
        y=pos[i].y;
        test=GetPixel(Masque,x,y);
        if(test.r==255 && test.g==0 && test.b==0)
            collision=1;
     }
     return collision;

}






//tache blanche 



void quitgame(int * q, xo c) {
  Uint8 * keystate = SDL_GetKeyState(NULL);
  if (keystate[SDLK_ESCAPE])( * q) = 1;
  int count = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (c.i[i][j] != -1) count++;
  if (count == 9)( * q) = 1;
}
void initi(xo * c) {
  c -> table = IMG_Load("xo/xo.png");
  c -> t[0] = IMG_Load("xo/x.png");
  c -> t[1] = IMG_Load("xo/o.png");
  c -> bg = IMG_Load("xo/white.jpeg");
  if (c -> t[1] == NULL) printf("aa\n");
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      c -> i[i][j] = -1;
      c -> r[i][j].x = 217 * i + 40;
      c -> r[i][j].y = 217 * j + 40;
      c -> turn = rand() % 2;
      c -> choixx = 0;
      c -> choixy = 0;
    }
}
void show(xo c, SDL_Surface * screen) {
  SDL_BlitSurface(c.bg, NULL, screen, NULL);
  SDL_BlitSurface(c.table, NULL, screen, NULL);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (c.i[i][j] != -1) {
        SDL_BlitSurface(c.t[c.i[i][j]], NULL, screen, & c.r[i][j]);
      }
      if ((c.choixx == i) && (c.choixy == j)) {
        SDL_BlitSurface(c.t[c.turn], NULL, screen, & c.r[i][j]);
      }
    }
  }
  SDL_Flip(screen);
}

void turn_played(xo * c) {
  c -> turn++;
  if (c -> turn == 2) c -> turn = 0;
}
void change(xo * c) {
  SDL_Delay(100);
  Uint8 * keystate = SDL_GetKeyState(NULL);
  if (keystate[SDLK_RIGHT])
    if (c -> choixx < 2) c -> choixx++;
  if (keystate[SDLK_LEFT])
    if (c -> choixx > 0) c -> choixx--;
  if (keystate[SDLK_DOWN])
    if (c -> choixy < 2) c -> choixy++;
  if (keystate[SDLK_UP])
    if (c -> choixy > 0) c -> choixy--;
  if (keystate[SDLK_RETURN])
    if (c -> i[c -> choixx][c -> choixy] == -1) {
      c -> i[c -> choixx][c -> choixy] = c -> turn;
      turn_played( & ( * c));
    }
}
int winner_is(xo c) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      if ((c.i[j][0] == i) && (c.i[j][1] == i) && (c.i[j][2] == i)) return i;
      if ((c.i[0][j] == i) && (c.i[1][j] == i) && (c.i[2][j] == i)) return i;
    }
    if ((c.i[0][0] == i) && (c.i[1][1] == i) && (c.i[2][2] == i)) return i;
    if ((c.i[0][2] == i) && (c.i[1][1] == i) && (c.i[2][0] == i)) return i;
  }
  return -1;
}
void ia2(xo * c) {
  int count = 0;
  if (c -> turn == 1) {
    SDL_Delay(500);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        count = 0;
        for (int k = 0; k < 3; k++)
          if (c -> i[j][k] == i) count++;
        if (count == 2)
          for (int k = 0; k < 3; k++)
            if (c -> i[j][k] == -1) {
              c -> i[j][k] = 1;
              turn_played( & ( * c));
              return;
            }
        count = 0;
        for (int k = 0; k < 3; k++)
          if (c -> i[k][j] == i) count++;
        if (count == 2)
          for (int k = 0; k < 3; k++)
            if (c -> i[k][j] == -1) {
              c -> i[k][j] = 1;
              turn_played( & ( * c));
              return;
            }
        count = 0;
      }
      for (int k = 0; k < 3; k++)
        if (c -> i[k][k] == i) count++;
      if (count == 2)
        for (int k = 0; k < 3; k++)
          if (c -> i[k][k] == -1) {
            c -> i[k][k] = 1;
            turn_played( & ( * c));
            return;
          }
      count = 0;
      if (c -> i[0][2] == i) count++;
      if (c -> i[1][1] == i) count++;
      if (c -> i[2][0] == i) count++;
      if (count == 2) {
        if (c -> i[0][2] == -1) {
          c -> i[0][2] = 1;
          turn_played( & ( * c));
          return;
        }
        if (c -> i[2][0] == -1) {
          c -> i[2][0] = 1;
          turn_played( & ( * c));
          return;
        }
        if (c -> i[1][1] == -1) {
          c -> i[1][1] = 1;
          turn_played( & ( * c));
          return;
        }
      }
    }
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        if (c -> i[i][j] == -1) {
          c -> i[i][j] = 1;
          turn_played( & ( * c));
          return;
        }
  }
}
int game(SDL_Surface * screen) {
  int q = 0;
  xo c;
  initi( & c);
  screen = SDL_SetVideoMode(1200, 600, 32, SDL_SWSURFACE);
  while (q == 0) {
    SDL_PumpEvents();
    quitgame( & q, c);
    if (c.turn == 0) change( & c);
    ia2( & c);
    show(c, screen);
    if (winner_is(c) != -1) {
      if (winner_is(c) == 1) SDL_Flip(screen);
      SDL_Delay(1000);
      return winner_is(c);
    }
  }
  SDL_Delay(1000);
  return -1;
}

////////////enemy









void initEnnemi(Ennemi *e)
{

    e->pos_depart.x = 400;
    e->pos_depart.y = 350;


    e->direction = 0;
    e->vitesse = 0;
    e->alive = 1;

    e->spritesheet = IMG_Load("bat.png");
    if (e->spritesheet == NULL)
    {
        printf("Erreur lors du chargement de la spritesheet de l'ennemi : %s\n", SDL_GetError());
    }

    e->pos_sprites.x = 0;
    e->pos_sprites.y = 0;
    e->pos_sprites.w = 200; // à voir
    e->pos_sprites.h = 200;
    e->pos_actuelle = (SDL_Rect){e->pos_depart.x,e->pos_depart.y, e->pos_sprites.w ,  e->pos_sprites.h};

    e->soundChannel=-1;
}

void afficherEnnemi(Ennemi e, SDL_Surface *screen)
{

    if(e.pos_actuelle.x+e.pos_sprites.w<0){
        SDL_BlitSurface(e.locationIcon, NULL, screen, &(SDL_Rect){0,e.pos_actuelle.y<0?0:e.pos_actuelle.y,157,120});
    }else if (e.pos_actuelle.y+e.pos_sprites.h<0) {
        SDL_BlitSurface(e.locationIcon, NULL, screen, &(SDL_Rect){e.pos_actuelle.x<0?0:e.pos_actuelle.x,0,157,120});

    }
    else{
            SDL_BlitSurface(e.spritesheet, &e.pos_sprites, screen, &e.pos_actuelle);
        }

}
void animerEnemi(Ennemi *e)
{
    if (e->pos_sprites.x >= 2000)
        e->pos_sprites.x = 0;

    e->pos_sprites.x += 200;
}

void move(Ennemi *e, SDL_Rect camera)
{



    if (e->pos_actuelle.y < 12)
        e->direction = 1; // bas
    else if (e->pos_actuelle.y > 400)
        e->direction = 0; // haut

    if (e->direction == 1)
        e->pos_depart.y += 4;
    if (e->direction == 0)
        e->pos_depart.y -= 4;


    e->pos_actuelle.x  = e->pos_depart.x-camera.x;
    e->pos_actuelle.y  = e->pos_depart.y-camera.y;
}








































//////////////////////////////////////////////////FONCTION MTE3 EL MAIN///////////////////////////////////////////////////////









int level1(int val ){

TTF_Init();
SDL_Init(SDL_INIT_VIDEO);
/* ---------ETAPE 1 DECLARATION DES VARIABLE----------- */
SDL_Surface *screen ;  // screen variable pointeur sur surface de l'arriere plan
personne IMAGE_main ,coeur ,lost;
image1 IMAGE ,feu,sousmenu ; 
 temps chrono;
int countdown_en_cours = 0;
SDL_Event   event ;  // variable pour l'evenement de l'utillis  
int boucle =1 ;
temps t;
minimap1 n ;
int test = 0 ;
SDL_Surface *masked=NULL;
int indicate = 0 ;  // variable pour indiquer que le bouton still lef or write  
int pas=6;
 personne p;
Mix_Music  *music ,*music2; 
int indicates ;
ScoreInfo J;
ScoreInfo Tri[3];
Uint32 dt, t_prev ;  // pur calculer le  temp 
minimap m;
anim a;

int  pos , posxi,posyi ; // loula taba3 saut 3adi lo5rin x et y tab3in il parabple a3malthom bich in7afi8 3al valeur il asliya imta3 x et x ,y  fil saut normal et para
int i = -200 ,i2=48 ,i3=48 ,boucle2=1 ; 

texte1  txte1, texte_score ;

Mix_Chunk *mus1 ,*mus2 , *mus3; 
///////////////////////////// declaration khalil 
background B,A,A2 ;
int direction=-1;
int con=0;
const Uint8* keystates = SDL_GetKeyState(NULL);

//declaration aziz 
image1 IMG, IMAGE_BTN1, IMAGE_BTN2;
    enigme e;
    e.numbr=0;
    int input=0;
    int boucleinput=0;
    int bouclenigme=0;
	int boucleload=0;

int mapd ; 


//enemi

Ennemi E;

int testi = 0 ; // itesti il coueur 
/*------------ETAPE 2 initialisation -----------------*/

// initialisation de l sdl
if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)==-1)
{printf("could not initialize SDL : %s .\n " ,SDL_GetError()) ;
 return -1 ; }


// initialisation de la fenetre 
 screen= SDL_SetVideoMode(1200 ,600, 32 ,SDL_RESIZABLE | SDL_HWSURFACE) ; 
//aziz
	e.screen=screen;
    initialiser_BACK(&IMG);
	initialiser_BOUTON1(&IMAGE_BTN1) ; 
	initialiser_BOUTON2(&IMAGE_BTN2) ; 
    initialiser_audioe(music2);
e.f = fopen("enigme.txt", "r");
 if (e.f==NULL)
	{
	printf("error mte3 NULL");
	fclose(e.f);
	}	else {

fgets(e.question, sizeof(e.question), e.f);

    	fgets(e.r1, sizeof(e.r1), e.f);

    	fgets(e.r2, sizeof(e.r2), e.f);

    	fgets(e.r3, sizeof(e.r3), e.f);

    	fscanf(e.f, "%d", &e.numbr);
printf("\n correct response is : %d \n",e.numbr); //2 doesnt wrk fr sm reason

    	fgets(e.x, sizeof(e.x), e.f); // Consume newline character

}
///khalil
A.s=0;
A.sc=screen;
A2.s=0;
A2.sc=screen;
J.nomjoueur=1;
J.score=50;
J.temps=60;
// initialisation 

//azizboucleloadsave

initialiser_imageloadsettings(&sousmenu);

//
initialiser_feu(&feu)  ; // feu obstacle
initPerso(&IMAGE_main , val)  ;

//
initEnnemi(&E);
//
initialiser_coeur(&coeur ,i ) ; 
initialiser_lost(&lost ); 


initialiser_texte1(&txte1,i3,i2) ; 
initialiser_texte_score(&texte_score );

/// khalil 
initBack(&B) ;
initanimation(&A);
//initanimation_deux(&A2);
bestScore("Best.txt", Tri); 
initialiser_audio1(music) ; 



//siwar
   initialiseMinimap(&n, 2, 4,0,780) ;
       

 masked=IMG_Load("mask.png");

    p.sprite=IMG_Load("miniperson.png");
    p.position_perso.x=550;
    p.position_perso.y=90;





  initialiser_temps(&t, 150,0);
    initmap( &m);

 init_anim( &a);



        
/*-------------------------ETAPE 3 BOUCLE DE MENU ---------------  */
//aziz
 srand(time(NULL));
genererEnigme("enigme.txt", &e);
//end of aziz
while(boucle) 
{t_prev=SDL_GetTicks();// calculer la durer de chaque iteration avec  SDL_GetTicks() qui retourne le temps écoulé depuis l’initialisation de SDL:



//........... -A AFFICHAGE................ 






// khalil 
afficherback(screen,B) ;
//siwar
afficherminimap ( m,screen);
   SDL_BlitSurface(p.sprite, NULL, screen, &p.position_perso);


afficher_anim (a,  screen);

//khalil
//afficher_feu(screen ,feu ) ;
afficherPerso(IMAGE_main ,screen) ;
//
afficherEnnemi(E,screen);
animerEnemi(&E);
move(&E, B.camera_pos);
//
afficherPerso(coeur ,screen) ;
/////////////////////
if  (testi==1)  
{
initialiser_coeur(&coeur ,i) ;

}

// il vie 
if  (IMAGE_main.pos_Screen.x==200&& IMAGE_main.pos_Screen.y >=350&& IMAGE_main.pos_Screen.y <=355)  
{i= i+200 ;
initialiser_coeur(&coeur ,i) ;
 
}


/// il score 
if (IMAGE_main.pos_Screen.x ==200&&IMAGE_main.pos_Screen.y <=450&&IMAGE_main.pos_Screen.y >=350) 
{if (i2 <57 ) 
{i2=i2+1 ;
initialiser_texte1(&txte1,i3,i2) ;}
else
  {i2=48 ;
  i3 = i3 + 1 ;
  initialiser_texte1(&txte1,i3,i2) ;} 
 } 




 
if (i==1400)
   {while (boucle2)
       {afficherPerso(lost ,screen) ;
        initialiser_audiobrefj2(mus2) ;
afficher_texte_score(screen, Tri, texte_score);
        while(SDL_PollEvent(&event)) 
          { switch(event.type)
              {case  SDL_QUIT:  
                  boucle2=0 ;
                  boucle=0 ; 
                 break ;}
          } 
       SDL_Flip(screen) ;
        } 
   }

 
afficher_texte1(screen,txte1) ;

   if (IMAGE_main.pos_Screen.x==200)
 {animerPerso (&IMAGE_main)  ;}  
   
 	
 
	


//.......... -B L'INPUT................... 

 while(SDL_PollEvent(&event)) 
   {

  switch(event.type)
     { /*----------------------1er joueur -------------------------------*/
       case SDL_KEYDOWN :

              if (event.key.keysym.sym == SDLK_o) // vie du joueur 
              {  
                  i= i-200 ;
                  testi = 1 ; 
               }

            if (event.key.keysym.sym == SDLK_w) // attack imin et isar
              { IMAGE_main.d  =-1 ; IMAGE_main.acceleration=0; 
                 indicate = 1 ;
                initialiser_audiobrefj3(mus3) ;
               }
               
           if (event.key.keysym.sym == SDLK_RIGHT) // i9adem il 9odem 
              {  IMAGE_main.direction = 1 ; IMAGE_main.acceleration=0;
                 indicate = 1 ;
                 
                /// khalil 
                  direction = 0;
                        con=1;
                initialiser_audiobrefj1(mus1) ;
                
                mapd = 1 ; 
               
         
               
               }
             
          if (event.key.keysym.sym==SDLK_LEFT)  // yarja3  bil twali 
                {IMAGE_main.direction = 0;  IMAGE_main.acceleration=0;
                 indicate = 1 ; 


                 //// khalil 
                 direction = 1;
                        con=1;
                initialiser_audiobrefj1(mus1) ;
                mapd = 0 ; }

          if (event.key.keysym.sym == SDLK_f) // touch acceleration 
{ IMAGE_main.acceleration+=0.005;}
 if (event.key.keysym.sym==SDLK_n)



{
srand( time( NULL ) );//pour la random()
SDL_Init(SDL_INIT_EVERYTHING);
SDL_Surface *screen;
int game_result=-1;
game_result = game(screen);
printf("%d\n",game_result);


}





 
              

           if (event.key.keysym.sym == SDLK_g) // touch deceleration 
              {IMAGE_main.acceleration-=0.11;}

//level2

	 if (event.key.keysym.sym == SDLK_h) // touch deceleration 
              {level2(val);}

         //aziz

          if (event.key.keysym.sym == SDLK_p) // touch acceleration  
              { 



bouclenigme=1;
		while( bouclenigme ){
					 afficher_BMP(screen, IMG);
 
	
        afficherEnigme(screen,e);
   
animate(&e) ;
t.countdown_en_cours = 1; // démarrer le compte à rebours
                    t.go = 1; // lancer le chrono
//afficher_temps(&t, screen);
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
 case SDL_KEYDOWN :


if (event.key.keysym.sym<=SDLK_a){
input=1;
}

else if (event.key.keysym.sym<=SDLK_b){
input=2;
}

else if (event.key.keysym.sym<=SDLK_c){
input=3;	
}
break;

       case SDL_QUIT:
                    bouclenigme = 0;

                    break;
            }
        }

if (input!=0){   
 if(input==e.numbr){
	boucleinput=1;
	while (boucleinput){
	while (SDL_PollEvent(&event)){

switch (event.type)
            {

case SDL_QUIT:
                    boucleinput=0;
		    input=0;
bouclenigme = 0;
                    break;



}


}

	
	afficher_BTN1(screen,IMAGE_BTN1 ) ;
	SDL_Flip(screen);
}
	
}else{
	boucleinput=-1;
	while (boucleinput==-1){
while (SDL_PollEvent(&event)){

switch (event.type)
            {

case SDL_QUIT:
                    boucleinput=0;
		    input=0;
bouclenigme = 0;
                    break;



}


}
	afficher_BTN2(screen,IMAGE_BTN2 ) ;

	SDL_Flip(screen);


}
}

}SDL_Flip(screen);


				     }
	      }

//boucle mte3 load w save


 if (event.key.keysym.sym==SDLK_m)   // boucle mte3 menu load save 
                {
boucleload=1;
while(boucleload){

afficher_BTN2(screen,sousmenu) ;
while (SDL_PollEvent(&event)){
switch (event.type)
            {
 case SDL_KEYDOWN :

if (event.key.keysym.sym==SDLK_s){
save (IMAGE_main, B,"save.txt");
}
if (event.key.keysym.sym==SDLK_l){
load(&IMAGE_main,&B,"save.txt");
}
if (event.key.keysym.sym==SDLK_q){
boucleload=0;
}
if (event.key.keysym.sym==SDLK_e){
boucleload=0;
boucle=0;
}

break;




}}
SDL_Flip(screen);
}




}
















	//end of aziz
         if (event.key.keysym.sym==SDLK_DOWN)  // yahbat 
               {  if ( IMAGE_main.pos_Screen.y<=500) 
                    {IMAGE_main.pos_Screen.y=IMAGE_main.pos_Screen.y+20 ;  }
                  }
if (event.key.keysym.sym==SDLK_g) {                 
			direction = 3;
                        con=1;  }

           if (event.key.keysym.sym==SDLK_UP)   // sautt normale 
                {IMAGE_main.up=1; pos = IMAGE_main.pos_Screen.y ; indicates=1 ; 
                   IMAGE_main.pos_Screen.y =pos ;}

                  if (event.key.keysym.sym==SDLK_t){
                    direction = 2;
                        con=1; }  
 
             if (event.key.keysym.sym==SDLK_ESCAPE)   // fonctio yitla3 fil drouj !!!!! yizimha ta7sinet ki yirja3 7asb il direction 3al issar il x ton9os 7asilou ni5dimha ba3d lazy inchallah maninsach ;)  
                {IMAGE_main.up=5; //posxi =IMAGE_main.pos_Screen.x ;  //posyi =IMAGE_main.pos_Screen.y ; 
                 drouj ( &IMAGE_main , IMAGE_main.pos_Screen.x ,  IMAGE_main.pos_Screen.y)  ; }  


             if (event.key.keysym.sym==SDLK_v)   // saut parabolique  
                 {IMAGE_main.up=3;   posyi =IMAGE_main.pos_Screen.y ; 
                  saut_personnage ( &IMAGE_main,dt, IMAGE_main.pos_Screen.x,IMAGE_main.pos_Screen.y)  ; } 


          break ;  
                               
     case  SDL_QUIT:  
            boucle=0 ; 
         break ; 
     
      case SDL_KEYUP:   
          if (event.key.keysym.sym == SDLK_m) // vie du joueur 
              {  i= i-200 ;  
                 testi = 1 ; 
              }    
            if (event.key.keysym.sym == SDLK_w) {   //attack imin et isar
           indicate = 0 ;  IMAGE_main.d  =3; 
          }

        // wa9tlili il bouton yirja3 normale houwa bich ya9if 
          if (event.key.keysym.sym == SDLK_RIGHT) 
            {mapd = 3 ; 
           indicate = 0 ; IMAGE_main.direction = 2 ;

           ///khalil 
          if (direction == 0) 
                {con=0; }
              
            }


           if (event.key.keysym.sym == SDLK_LEFT)
           {mapd = 4 ; 
 t.countdown_en_cours = 0; // démarrer le compte à rebours
                    t.go = 1; // lancer le chrono
           indicate = 0 ;IMAGE_main.direction = 3 ;
           /// khalil  
             if (direction == 1)
                        {
                           con=0;
                        }
            }
           
         if (event.key.keysym.sym == SDLK_f) // touch acceleration  
              {IMAGE_main.acceleration-=0.005;}

          if (event.key.keysym.sym == SDLK_g) // touch deceleration 
              {IMAGE_main.acceleration+=0.11;}

          if (event.key.keysym.sym==SDLK_UP)   // sautt normale 
                { indicates=0 ; IMAGE_main.up=0;IMAGE_main.pos_Screen.y =pos ;
                  //// khalil 
                   if (direction == 2) 
                        {
                            con=0;
                        }
                        }
        if (event.key.keysym.sym==SDLK_DOWN) 
             { if (direction == 3) 
                         {con=0;}
             }
          
          
         if (event.key.keysym.sym==SDLK_v)  //saut parabolique 
              {  IMAGE_main.up=4;
                 if(IMAGE_main.direction==1 )  IMAGE_main.pos_Screen.x=IMAGE_main.pos_Screen.x+50  ;
                 if(IMAGE_main.direction==0 )  IMAGE_main.pos_Screen.x=IMAGE_main.pos_Screen.x-50  ;
                 IMAGE_main.pos_Screen.y=posyi  ;  }  

          break;
 
     

     }
  
  }

if (con==1) 
{scrolling(&B,direction,pas); }


if (indicate ) 
{movePerso(&IMAGE_main ,dt) ; 
if (mapd == 1 ) 
  p.position_perso.x =p.position_perso.x+2 ;
else if (mapd==0 && p.position_perso.x>=550)               
  p.position_perso.x =p.position_perso.x-2 ; 
else {} }
else if  (indicate == 0 && IMAGE_main.direction == 2 )//yerje3 wa9if normale ba3d man7arkouh right
{movePerso(&IMAGE_main ,dt) ;}
else if(indicate == 0 && IMAGE_main.direction == 3)//yerja3 wa9if normale ba3d man7arkouh left 
{movePerso(&IMAGE_main ,dt) ; }
else  {}



 saut( &IMAGE_main,dt,IMAGE_main.pos_Screen.y) ;


/*---------------------------------------------------------------------*/

dt=SDL_GetTicks()-t_prev; // ala fin de la boucle du jeu 

/// khalil 
animer_image(&A); 
//animer_image_deux(&A2); 
 afficher_temps(&t, screen);
//.............C-MISE A JOUR DE L'ECRAN ----------------







 animerMinimap(&n);
    SDL_BlitSurface(n.sprite, &n.posSprite, screen, NULL);  
                                
SDL_Flip(screen) ; // raffraichir l'ecran

}


// liberation
saveScore(J, "Best.txt");
liberer_imageb(feu) ; 
liberer_perso_image(IMAGE_main)  ; 

liberer_perso_image(coeur)  ; 
liberer_perso_image(lost)  ; 

liberer_texte1(txte1) ;
TTF_CloseFont(txte1.police) ;



/// khalil 
liberer_image1(B) ; 
liberer_image1(A) ; 
liberer_image1(A2);
liberer_musique1(music) ; 
//AZIZ
liberer_imagee(IMAGE);
liberer_imagee(IMAGE_BTN1);
liberer_imagee(IMAGE_BTN2);
liberer_musiquee(music2);

fclose(e.f);
TTF_Quit();
SDL_Quit();
//END OF AZIZ

liberer_musiquebrefj(mus1) ;
liberer_musiquebrefj(mus2) ;
liberer_musiquebrefj(mus3) ;

//siwar
libererMinimap(&n);
free_temps(&t);
free_minimap (&m);
free_anim (&a);

// quitter le SDL 
SDL_Quit() ;








return 0 ; 


}

     /////////////////   SCENNNNEEE 1
///////////////////////////////////////////////////////////////////
void initialiser_imageSTORY(image1 *image)
{
image->url="1.png" ; 
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


}


//l'emplacement du fichier image bouton
//pour la fonction d'initialisation de l'image bouton on definit l'url de l'emplacement du fichier de l'image 
void initialiser_imageSCENE1(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="2.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}

 
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 


//on initialise la position du premier deux boutons au milieu de l'ecran su l'axe des x (a l'horizentale ) et au niveau de 1/3 de l'ecran sur l'axe y (a la verticale )
//imgbtn->pos_img_affiche.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/2) ;
//imgbtn->pos_img_affiche.y=((SCREEN_H-imgbtn->pos_img_affiche.h)/3) ;
}

 

void initialiser_imageSCENE2(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="3.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//initialisation nouveau bouton:
void initialiser_imageSCENE3(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="4.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}
//el bouton li todhhor fog el play


//scene 5

void initialiser_s5(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="5.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//scene 6
void initialiser_s6(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="6.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//scene 7
void initialiser_s7(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="7.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//scene 8

void initialiser_s8(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="8.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}
//scene 9

void initialiser_s9(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="9.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//scene 10
void initialiser_s10(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="10.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}
//11

void initialiser_s11(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="11.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//12

void initialiser_s12(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="12.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//13

void initialiser_s13(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="13.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//14

void initialiser_s14(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="14.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//15

void initialiser_s15(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="15.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//16

void initialiser_s16(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="16.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//17

void initialiser_s17(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="17.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//18

void initialiser_s18(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="18.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//19

void initialiser_s19(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="19.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//20

void initialiser_s20(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="20.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//21

void initialiser_s21(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="21.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//22

void initialiser_s22(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="22.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//23

void initialiser_s23(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="23.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}


//24
void initialiser_s24(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="24.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//25

void initialiser_s25(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="25.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}
//26

void initialiser_s26(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="26.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}
//27
void initialiser_s27(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="27.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//28

void initialiser_s28(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="28.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//29
void initialiser_s29(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="29.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//30

void initialiser_s30(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="30.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//31
void initialiser_s31(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="31.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}
//32
void initialiser_s32(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="32.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}
//33
void initialiser_s33(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="33.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//34
void initialiser_s34(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="34.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}
//35
void initialiser_s35(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="35.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}
//36
void initialiser_s36(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="36.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}

//37
void initialiser_s37(image1 *imgbtn) 
{
//chargement de l'image
imgbtn->url="click.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=0 ; 
imgbtn->pos_img_ecran.y=0 ; 

imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0; 
}











       /*-------------------- 2 affichage de l'image ----------------------*/
 // la fonction SDL_BlitSurface() permet de  coller et afficher l'image sur  screen


// ----------affichage du background ------------
void afficher_imagestory(SDL_Surface *screen , image1 image )
{ 
SDL_BlitSurface(image.img ,NULL , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du back sur  screen
}


// -------------affichage du image boutton 1 ---------------
void afficher_SCENE1(SDL_Surface *screen , image1 image )
{ 
SDL_BlitSurface(image.img ,NULL  , screen ,&image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du bonton play dans le screen
 
}

// -------------affichage du image boutton 2  ---------------
void afficher_SCENE2(SDL_Surface *screen , image1 image )
{ 
SDL_BlitSurface(image.img , NULL, screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du bonton 2 quit dans le screen
}

//affichage bouton jdida
void afficher_SCENE3(SDL_Surface *screen , image1 image )
{ 
SDL_BlitSurface(image.img , NULL, screen , &image.pos_img_ecran ) ; }







   /*------------------------3 liberation image -------------------*/
// on utilise SDL_FreeSurface()
void liberer_imager(image1 image) 
{
SDL_FreeSurface(image.img) ;
}


     /////////////////  FONCTON SCENNNNEEE 1


int SCENE1(int val )
{
//initialisation texte ,video et son!!!!
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);
    /* ---------ETAPE 1 DECLARATION DES VARIABLE----------- */
    SDL_Surface *screen ;  // screen variable pointeur sur surface de l'arriere plan
    image1  IMAGE, IMAGE_BTN1, IMAGE_BTN2, IMAGE_BTN3, IMAGE_BTN4, IMAGE_SETTINGS, IMAGE_K, IMAGEP, IMAGEM ;     // variable de type image
    Mix_Music  *music ;   // variable pointeur sur les audios continue
    Mix_Chunk *mus ; // variable pointeur sur les audios bref
    texte1 txte  ;  // variable texte
    SDL_Event   event ;  // variable pour l'evenement de l'utillis
    int boucle =1,boucle1=0 ; //compteur sur la boucle de jeu
    int boucle2 =0  ; 
    int boucle3=0, boucle4=0, boucle5=0,boucle6=0,boucle7=0,boucle8=0,boucle9=0,boucle10=0,boucle11=0,boucle12=0,boucle13=0,boucle14=0,boucle15=0,boucle16=0,boucle17=0,boucle18=0,boucle19=0,boucle20=0,boucle21=0,boucle22=0,boucle23=0,boucle24=0,boucle25=0,boucle26=0,boucle27=0,boucle28=0,boucle29=0,boucle30=0,boucle31=0,boucle32=0,boucle33=0,boucle34=0,boucle35=0,boucle36=0,boucle37=0;

    int enter=0;
    float v=1;
	image1 S5, S6,S1,S7,S8,S9,S10,S11,S12,S13,S14,S15,S16,S17,S18,S19,S20,S21,S22,S23,S24,S25,S26,S27,S28,S29,S30,S31,S32,S33,S34,S35,S36,S37;

    /*.....................boucle du jeu ---------------------------*/
    /*------------ETAPE 2 initialisation -----------------*/

// initialisation de l sdl
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)==-1)
    {
        printf("could not initialize SDL : %s .\n ",SDL_GetError()) ;
        return -1 ;
    }

// initialisation de la fenetre
    screen= SDL_SetVideoMode(992,744, 32, SDL_RESIZABLE) ;

// initialisation des images son et texte
    initialiser_imageSTORY(&IMAGE) ;
    initialiser_imageSCENE1(&IMAGE_BTN1) ;
    initialiser_imageSCENE2(&IMAGE_BTN2) ;
    initialiser_imageSCENE3(&IMAGE_BTN3) ;





initialiser_s5(&S5) ;
initialiser_s6(&S6) ;
initialiser_s7(&S7) ;
initialiser_s9(&S9) ;
initialiser_s8(&S8) ;
initialiser_s9(&S9) ;
initialiser_s10(&S10) ;
initialiser_s11(&S11);
initialiser_s12(&S12);
initialiser_s13(&S13);
initialiser_s14(&S14);
initialiser_s15(&S15);
initialiser_s16(&S16);
initialiser_s17(&S17);
initialiser_s18(&S18);
initialiser_s19(&S19);
initialiser_s20(&S20);
initialiser_s21(&S21);
initialiser_s22(&S22);
initialiser_s23(&S23);
initialiser_s24(&S24);
initialiser_s25(&S25);
initialiser_s26(&S26);
initialiser_s27(&S27);
initialiser_s28(&S28);
initialiser_s29(&S29);
initialiser_s30(&S30);
initialiser_s31(&S31);
initialiser_s32(&S32);
initialiser_s33(&S33);
initialiser_s34(&S34);
initialiser_s35(&S35);
initialiser_s36(&S36);

initialiser_s37(&S1) ;

//---------------------------------------------boucle jeu
    while(boucle)
    {

        afficher_imagestory(screen,IMAGE) ;







        /*.......... -B L'INPUT................ */


        while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
            case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
                    enter++;

                break ;



            case  SDL_QUIT:
                boucle=0 ;
                break ;
            }

            switch(enter)
            {



case 0:
                boucle1=1;
                while(boucle1)
                {
                    afficher_SCENE1(screen,S1) ;
                    SDL_Flip(screen) ;
/////
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym==SDLK_RETURN)
boucle1=0;
enter++;

}

}

////
                }
                break;
///

            case 1:
                boucle2=1;
                while(boucle2)
                {
                    afficher_SCENE1(screen,IMAGE_BTN1 ) ;
                    SDL_Flip(screen) ;
/////
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym==SDLK_RETURN)
boucle2=0;
enter++;

}

}

////
                }
                break;
//
            case 2:
        
                boucle3=1;
                while(boucle3)
                {
                    afficher_SCENE2(screen,IMAGE_BTN2 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle3=0;
enter++;

}

}
//

                }

                break;

            case 3:
            
                boucle4=1;
                while(boucle4)
                {

                    afficher_SCENE3(screen,IMAGE_BTN3 ) ;
                    SDL_Flip(screen) ;

//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle4=0;
enter++;

}

}
//
                }
                break;
      case 4:
        
                boucle5=1;
                while(boucle5)
                {
                    afficher_imagestory(screen,S5) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle5=0;
enter++;

}

}
//


                }

                break;


///////////////
case 5:
        
                boucle6=1;
                while(boucle6)
                {
                    afficher_imagestory(screen,S6 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle6=0;
enter++;

}

}
//


                }

                break;
///////////////////////
case 6:
        
                boucle7=1;
                while(boucle7)
                {
                    afficher_imagestory(screen,S7) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle7=0;
enter++;

}

}
//


                }

                break;
///////////////////////
case 7:
        
                boucle8=1;
                while(boucle8)
                {
                    afficher_imagestory(screen,S8 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle8=0;
enter++;

}

}
//


                }

                break;
////////////////////////
case 8:
        
                boucle9=1;
                while(boucle9)
                {
                    afficher_imagestory(screen,S9 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle9=0;
enter++;

}

}
//


                }

                break;
//////////////////////////
case 9:
        
                boucle10=1;
                while(boucle10)
                {
                    afficher_imagestory(screen,S10 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle10=0;
enter++;

}

}
//


                }

                break;
/////////////////////////////
case 10:
        
                boucle11=1;
                while(boucle11)
                {
                    afficher_imagestory(screen,S11 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle11=0;
enter++;

}

}
//


                }

                break;
/////////////////////////
case 11:
        
                boucle12=1;
                while(boucle12)
                {
                    afficher_imagestory(screen,S12 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle12=0;
enter++;

}

}
//


                }

                break;
//////////////////////
case 12:
        
                boucle13=1;
                while(boucle13)
                {
                    afficher_imagestory(screen,S13 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle13=0;
enter++;

}

}
//


                }

                break;
////////////////////////
case 13:
        
                boucle14=1;
                while(boucle14)
                {
                    afficher_imagestory(screen,S14 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle14=0;
enter++;

}

}
//


                }

                break;
///////////////////////////////////
case 14:
        
                boucle15=1;
                while(boucle15)
                {
                    afficher_imagestory(screen,S15 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle15=0;
enter++;

}

}
//


                }

                break;
////////////////////////////////
case 15:
        
                boucle16=1;
                while(boucle16)
                {
                    afficher_imagestory(screen,S16 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle16=0;
enter++;

}

}
//


                }

                break;
////////////////////////
case 16:
        
                boucle17=1;
                while(boucle17)
                {
                    afficher_imagestory(screen,S17 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle17=0;
enter++;

}

}
//


                }

                break;
//////////////
case 17:
        
                boucle18=1;
                while(boucle18)
                {
                    afficher_imagestory(screen,S18 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle18=0;
enter++;

}

}
//


                }

                break;
///////////////
case 18:
        
                boucle19=1;
                while(boucle19)
                {
                    afficher_imagestory(screen,S19 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle19=0;
enter++;

}

}
//


                }

                break;
/////////////
case 19:
        
                boucle20=1;
                while(boucle20)
                {
                    afficher_imagestory(screen,S20 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle20=0;
enter++;

}

}
//


                }

                break;
///////////////
case 20:
        
                boucle21=1;
                while(boucle21)
                {
                    afficher_imagestory(screen,S21 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle21=0;
enter++;

}

}
//


                }

                break;
//////////////////////
case 21:
        
                boucle22=1;
                while(boucle22)
                {
                    afficher_imagestory(screen,S22 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle22=0;
enter++;

}

}
//


                }

                break;

////////
case 22:
        
                boucle23=1;
                while(boucle23)
                {
                   afficher_imagestory(screen,S23 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle23=0;
enter++;

}

}
//


                }

                break;

/////////////////

case 23:
        
                boucle24=1;
                while(boucle24)
                {
                    afficher_imagestory(screen,S24) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle24=0;
enter++;

}

}
//


                }

                break;

///////////
case 24:
        
                boucle25=1;
                while(boucle25)
                {
                    afficher_imagestory(screen,S25 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle25=0;
enter++;

}

}
//


                }

                break;

/////////////////

case 25:
        
                boucle26=1;
                while(boucle26)
                {
                    afficher_imagestory(screen,S26) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle26=0;
enter++;

}

}
//


                }

                break;

///////////
case 26:
        
                boucle27=1;
                while(boucle27)
                {
                   afficher_imagestory(screen,S27 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle27=0;
enter++;

}

}
//


                }

                break;

/////////////////

case 27:
        
                boucle28=1;
                while(boucle28)
                {
                    afficher_imagestory(screen,S28) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle28=0;
enter++;

}

}
//


                }

                break;

///////////
case 28:
        
                boucle29=1;
                while(boucle29)
                {
                    afficher_imagestory(screen,S29 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle29=0;
enter++;

}

}
//


                }

                break;

/////////////////

case 29:
        
                boucle30=1;
                while(boucle30)
                {
                    afficher_imagestory(screen,S30) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle30=0;
enter++;

}

}
//


                }

                break;

///////////
case 30:
        
                boucle31=1;
                while(boucle31)
                {
                    afficher_imagestory(screen,S31 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle31=0;
enter++;

}

}
//


                }

                break;

/////////////////

case 31:
        
                boucle32=1;
                while(boucle32)
                {
                    afficher_imagestory(screen,S32) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle32=0;
enter++;

}

}
//


                }

                break;

///////////
case 32:
        
                boucle33=1;
                while(boucle33)
                {
                    afficher_imagestory(screen,S33 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle33=0;
enter++;

}

}
//


                }

                break;

/////////////////

case 34:
        
                boucle35=1;
                while(boucle35)
                {
                    afficher_imagestory(screen,S35) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle35=0;
enter++;

}

}
//


                }

                break;

///////////
case 35:
        
                boucle36=1;
                while(boucle36)
                {
                    afficher_imagestory(screen,S36 ) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle36=0;
enter++;

}

}
//


                }

                break;

/////////////////

case 36:
        
                boucle37=1;
                while(boucle37)
                {
                    afficher_imagestory(screen,S37) ;
                    SDL_Flip(screen) ;
//
while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
 case SDL_KEYDOWN :
                if (event.key.keysym.sym<=SDLK_RETURN)
boucle37=0;
enter++;

}

}
//


                }

                break;

//
case 37:
        
                level1(val);
                break;

         






            }
        }


        SDL_Flip(screen) ;
 

    }

// liberation les surfaces

    liberer_imager(IMAGE) ;
    liberer_imager(IMAGE_BTN1) ;

    liberer_imager(IMAGE_BTN2) ;
    liberer_imager(IMAGE_BTN3) ;
    liberer_imager(IMAGE_BTN4) ;
    liberer_imager(IMAGE_SETTINGS) ;
    liberer_imager(IMAGE_K) ;
    liberer_imager(IMAGEP) ;
    liberer_imager(IMAGEM) ;
	liberer_imager(S5) ;
liberer_imager(S6);
liberer_imager(S7);
liberer_imager(S8);
liberer_imager(S9);
liberer_imager(S10);
liberer_imager(S11);
liberer_imager(S12);
liberer_imager(S13);
liberer_imager(S14);
liberer_imager(S15);
liberer_imager(S16);
liberer_imager(S17);
liberer_imager(S18);
liberer_imager(S19);
liberer_imager(S20);
liberer_imager(S21);
liberer_imager(S22);
// quitter le SDL

    SDL_Quit() ;



    return 0 ;
}


/////////////////////////////////////level 2  ////////////////////////////////////////////////////////////

void initmap2( minimap *m)
{
	m->position_mini.x=10;
	m->position_mini.y=0;
	m->sprite=NULL;
    m->sprite=IMG_Load("minimap2.png");
}

void scrolling2(background *b, int direction,int pas) {
    switch (direction) {
        case 0:
            b->camera_pos.x += pas;
            break;
        case 1:
            b->camera_pos.x = b->camera_pos.x - pas;
            break;
        case 3:
            b->camera_pos.y = b->camera_pos.y + pas;
            break;
        case 2:
            b->camera_pos.y = b->camera_pos.y - pas;
            break;
    }

    
    if (b->camera_pos.x < 0) {
        b->camera_pos.x = 0;
    }
    if (b->camera_pos.x + b->camera_pos.w > 11350) {
        b->camera_pos.x = 11350 - b->camera_pos.w;
    }

  
    if (b->camera_pos.y < 0) {
        b->camera_pos.y = 0;
    }
    if (b->camera_pos.y + b->camera_pos.h > 700) {
        b->camera_pos.y =700 - b->camera_pos.h;
    }
}

void initBack2(background *b)
{
b->url="level2.png"; 
b->img=IMG_Load(b->url) ; 
if (b->img == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
b->pos_img_ecran.x=0; 
b->pos_img_ecran.y=0; 
b->camera_pos.x=0; 
b->camera_pos.y=50; 
b->camera_pos.h=SCREEN_H ; 
b->camera_pos.w=SCREEN_W ;

}















/////////////////////////////////////level2 fonction



int level2(int val)
{

TTF_Init();
SDL_Init(SDL_INIT_VIDEO);
/* ---------ETAPE 1 DECLARATION DES VARIABLE----------- */
SDL_Surface *screen ;  // screen variable pointeur sur surface de l'arriere plan
personne IMAGE_main ,coeur ,lost;
image1 IMAGE ,feu ; 
 temps chrono;
int countdown_en_cours = 0;
SDL_Event   event ;  // variable pour l'evenement de l'utillis  
int boucle =1 ;
temps t;
minimap1 n ;
int test = 0 ;
SDL_Surface *masked=NULL;
int indicate = 0 ;  // variable pour indiquer que le bouton still lef or write  
int pas=6;
 personne p;
Mix_Music  *music ,*music2; 
int indicates ;
ScoreInfo J;
ScoreInfo Tri[3];
Uint32 dt, t_prev ;  // pur calculer le  temp 
minimap m;
anim a;

int  pos , posxi,posyi ; // loula taba3 saut 3adi lo5rin x et y tab3in il parabple a3malthom bich in7afi8 3al valeur il asliya imta3 x et x ,y  fil saut normal et para
int i = -200 ,i2=48 ,i3=48 ,boucle2=1 , testi ; 

texte1  txte, texte_score ;

Mix_Chunk *mus1 ,*mus2 , *mus3; 
///////////////////////////// declaration khalil 
background B,A,A2 ;
int direction=-1;
int con=0;
const Uint8* keystates = SDL_GetKeyState(NULL);

//declaration aziz 
image1 IMG, IMAGE_BTN1, IMAGE_BTN2;
    enigme e;
    e.numbr=0;
    int input=0;
    int boucleinput=0;
    int bouclenigme=0;

int mapd ; 

/*------------ETAPE 2 initialisation -----------------*/

// initialisation de l sdl
if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)==-1)
{printf("could not initialize SDL : %s .\n " ,SDL_GetError()) ;
 return -1 ; }


// initialisation de la fenetre 
 screen= SDL_SetVideoMode(1200 ,600, 32 ,SDL_RESIZABLE | SDL_HWSURFACE) ; 
//aziz
	e.screen=screen;
    initialiser_imageBACK(&IMG);
	initialiser_imageBOUTON1(&IMAGE_BTN1) ; 
	initialiser_imageBOUTON2(&IMAGE_BTN2) ; 
    initialiser_audioe(music2);
e.f = fopen("enigme.txt", "r");
 if (e.f==NULL)
	{
	printf("error mte3 NULL");
	fclose(e.f);
	}	else {

fgets(e.question, sizeof(e.question), e.f);

    	fgets(e.r1, sizeof(e.r1), e.f);

    	fgets(e.r2, sizeof(e.r2), e.f);

    	fgets(e.r3, sizeof(e.r3), e.f);

    	fscanf(e.f, "%d", &e.numbr);
printf("\n correct response is : %d \n",e.numbr); //2 doesnt wrk fr sm reason

    	fgets(e.x, sizeof(e.x), e.f); // Consume newline character

}
///khalil
A.s=0;
A.sc=screen;
A2.s=0;
A2.sc=screen;
J.nomjoueur=1;
J.score=50;
J.temps=60;
// initialisation 

initialiser_feu(&feu)  ; // feu obstacle
initPerso(&IMAGE_main,val )  ;



initialiser_coeur(&coeur ,i ) ; 
initialiser_lost(&lost ); 


initialiser_texte(&txte,i3,i2) ; 
initialiser_texte_score(&texte_score );

/// khalil 
initBack2(&B) ;

initanimation(&A);
//initanimation_deux(&A2);
bestScore("Best.txt", Tri); 
initialiser_audio(music) ; 



//siwar
   initialiseMinimap(&n, 2, 4,0,780) ;
       

 masked=IMG_Load("mask.png");

    p.sprite=IMG_Load("miniperson.png");
    p.position_perso.x=30;
    p.position_perso.y=80;





  initialiser_temps(&t, 150,0);
    initmap2( &m);

 //init_anim( &a);



        
/*-------------------------ETAPE 3 BOUCLE DE MENU ---------------  */
//aziz
 srand(time(NULL));
genererEnigme("enigme.txt", &e);
//end of aziz
while(boucle) 
{t_prev=SDL_GetTicks();// calculer la durer de chaque iteration avec  SDL_GetTicks() qui retourne le temps écoulé depuis l’initialisation de SDL:



//........... -A AFFICHAGE................ 







// khalil 
afficherback(screen,B) ;
//siwar
afficherminimap( m,screen);
   SDL_BlitSurface(p.sprite, NULL, screen, &p.position_perso);


//afficher_anim (a,  screen);

//khalil
afficher_feu(screen ,feu ) ;
afficherPerso(IMAGE_main ,screen) ;

afficherPerso(coeur ,screen) ;

///////////////////////
if  (testi==1)  
{
initialiser_coeur(&coeur ,i) ;

}

// il vie 
if  (IMAGE_main.pos_Screen.x==200&& IMAGE_main.pos_Screen.y >=350&& IMAGE_main.pos_Screen.y <=355)  
{i= i+200 ;
initialiser_coeur(&coeur ,i) ;
 
}


// il score 
if (IMAGE_main.pos_Screen.x ==200&&IMAGE_main.pos_Screen.y <=450&&IMAGE_main.pos_Screen.y >=350) 
{if (i2 <57 ) 
{i2=i2+1 ;
initialiser_texte(&txte,i3,i2) ;}
else
  {i2=48 ;
  i3 = i3 + 1 ;
  initialiser_texte(&txte,i3,i2) ;} 
 } 

 
if (i==200)
   {while (boucle2)
       {afficherPerso(lost ,screen) ;
        initialiser_audiobrefj2(mus2) ;
afficher_texte_score(screen, Tri, texte_score);
        while(SDL_PollEvent(&event)) 
          { switch(event.type)
              {case  SDL_QUIT:  
                  boucle2=0 ;
                  boucle=0 ; 
                 break ;}
          } 
       SDL_Flip(screen) ;
        } 
   }

 
afficher_texte(screen,txte) ;

   if (IMAGE_main.pos_Screen.x==200)
 {animerPerso (&IMAGE_main)  ;}  
   
 	
 
	


//.......... -B L'INPUT................... 

 while(SDL_PollEvent(&event)) 
   {

  switch(event.type)
     { /*----------------------1er joueur -------------------------------*/
       case SDL_KEYDOWN :
               if (event.key.keysym.sym == SDLK_m) // vie du joueur 
              {  
                  i= i-200 ;
                  testi = 1 ; 
               }

            if (event.key.keysym.sym == SDLK_w) // attack imin et isar
              { IMAGE_main.d  =-1 ; IMAGE_main.acceleration=0; 
                 indicate = 1 ;
                initialiser_audiobrefj3(mus3) ;
               }
               
           if (event.key.keysym.sym == SDLK_RIGHT) // i9adem il 9odem 
              {  IMAGE_main.direction = 1 ; IMAGE_main.acceleration=0;
                 indicate = 1 ;
                 
                /// khalil 
                  direction = 0;
                        con=1;
                initialiser_audiobrefj1(mus1) ;
                
                mapd = 1 ; 
               }
             
          if (event.key.keysym.sym==SDLK_LEFT)  // yarja3  bil twali 
                {IMAGE_main.direction = 0;  IMAGE_main.acceleration=0;
                 indicate = 1 ; 


                 //// khalil 
                 direction = 1;
                        con=1;
                initialiser_audiobrefj1(mus1) ;
                mapd = 0 ; }

          if (event.key.keysym.sym == SDLK_f) // touch acceleration 
{ IMAGE_main.acceleration+=0.005;}








 
              

           if (event.key.keysym.sym == SDLK_g) // touch deceleration 
              {IMAGE_main.acceleration-=0.11;}

         //aziz

          if (event.key.keysym.sym == SDLK_p) // touch acceleration  
              { 



bouclenigme=1;
		while( bouclenigme ){
					 afficher_imageBMP(screen, IMG);
 
	
        afficherEnigme(screen,e);
   
animate(&e) ;
t.countdown_en_cours = 1; // démarrer le compte à rebours
                    t.go = 1; // lancer le chrono
//afficher_temps(&t, screen);
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
 case SDL_KEYDOWN :


if (event.key.keysym.sym<=SDLK_a){
input=1;
}

else if (event.key.keysym.sym<=SDLK_b){
input=2;
}

else if (event.key.keysym.sym<=SDLK_c){
input=3;	
}
break;

       case SDL_QUIT:
                    bouclenigme = 0;

                    break;
            }
        }

if (input!=0){   
 if(input==e.numbr){
	boucleinput=1;
	while (boucleinput){
	while (SDL_PollEvent(&event)){

switch (event.type)
            {

case SDL_QUIT:
                    boucleinput=0;
		    input=0;
bouclenigme = 0;
                    break;



}


}

	
	afficher_imageBTN1(screen,IMAGE_BTN1 ) ;
	SDL_Flip(screen);
}
	
}else{
	boucleinput=-1;
	while (boucleinput==-1){
while (SDL_PollEvent(&event)){

switch (event.type)
            {

case SDL_QUIT:
                    boucleinput=0;
		    input=0;
bouclenigme = 0;
                    break;



}


}
	afficher_imageBTN2(screen,IMAGE_BTN2 ) ;

	SDL_Flip(screen);


}
}

}SDL_Flip(screen);


				     }
	      }

	//end of aziz
         if (event.key.keysym.sym==SDLK_DOWN)  // yahbat 
               {  if ( IMAGE_main.pos_Screen.y<=500) 
                    {IMAGE_main.pos_Screen.y=IMAGE_main.pos_Screen.y+20 ;  }
                  }
if (event.key.keysym.sym==SDLK_g) {                 
			direction = 3;
                        con=1;  }

           if (event.key.keysym.sym==SDLK_UP)   // sautt normale 
                {IMAGE_main.up=1; pos = IMAGE_main.pos_Screen.y ; indicates=1 ; 
                   IMAGE_main.pos_Screen.y =pos ;}

                  if (event.key.keysym.sym==SDLK_t){
                    direction = 2;
                        con=1; }  
 
             if (event.key.keysym.sym==SDLK_ESCAPE)   // fonctio yitla3 fil drouj !!!!! yizimha ta7sinet ki yirja3 7asb il direction 3al issar il x ton9os 7asilou ni5dimha ba3d lazy inchallah maninsach ;)  
                {IMAGE_main.up=5; //posxi =IMAGE_main.pos_Screen.x ;  //posyi =IMAGE_main.pos_Screen.y ; 
                 drouj ( &IMAGE_main , IMAGE_main.pos_Screen.x ,  IMAGE_main.pos_Screen.y)  ; }  


             if (event.key.keysym.sym==SDLK_v)   // saut parabolique  
                 {IMAGE_main.up=3;   posyi =IMAGE_main.pos_Screen.y ; 
                  saut_personnage ( &IMAGE_main,dt, IMAGE_main.pos_Screen.x,IMAGE_main.pos_Screen.y)  ; }  

          break ;  
                               
     case  SDL_QUIT:  
            boucle=0 ; 
         break ; 
     
      case SDL_KEYUP:      
if (event.key.keysym.sym == SDLK_m) // vie du joueur 
              {  i= i-200 ;  
                 testi = 1 ; 
              }    
 
            if (event.key.keysym.sym == SDLK_w) {   //attack imin et isar
           indicate = 0 ;  IMAGE_main.d  =3; 
          }

        // wa9tlili il bouton yirja3 normale houwa bich ya9if 
          if (event.key.keysym.sym == SDLK_RIGHT) 
            {mapd = 3 ; 
           indicate = 0 ; IMAGE_main.direction = 2 ;

           ///khalil 
          if (direction == 0) 
                {con=0; }
            }


           if (event.key.keysym.sym == SDLK_LEFT)
           {mapd = 4 ; 
 t.countdown_en_cours = 0; // démarrer le compte à rebours
                    t.go = 1; // lancer le chrono
           indicate = 0 ;IMAGE_main.direction = 3 ;
           /// khalil  
             if (direction == 1)
                        {
                           con=0;
                        }
            }
           
         if (event.key.keysym.sym == SDLK_f) // touch acceleration  
              {IMAGE_main.acceleration-=0.005;}

          if (event.key.keysym.sym == SDLK_g) // touch deceleration 
              {IMAGE_main.acceleration+=0.11;}

          if (event.key.keysym.sym==SDLK_UP)   // sautt normale 
                {indicates=0 ; IMAGE_main.up=0;IMAGE_main.pos_Screen.y =pos ;
                  //// khalil 
                   if (direction == 2) 
                        {
                            con=0;
                        }
                        }
        if (event.key.keysym.sym==SDLK_DOWN) 
             { if (direction == 3) 
                         {con=0;}
             }
          
          
         if (event.key.keysym.sym==SDLK_v)  //saut parabolique 
              {  IMAGE_main.up=4;
                 if(IMAGE_main.direction==1 )  IMAGE_main.pos_Screen.x=IMAGE_main.pos_Screen.x+50  ;
                 if(IMAGE_main.direction==0 )  IMAGE_main.pos_Screen.x=IMAGE_main.pos_Screen.x-50  ;
                 IMAGE_main.pos_Screen.y=posyi  ;  }  

          break;
 
     

     }
  
  }

if (con==1) 
{scrolling2(&B,direction,pas); }


if (indicate ) 
{movePerso(&IMAGE_main ,dt) ; 
if (mapd == 1 ) 
  p.position_perso.x =p.position_perso.x+1 ;
else if (mapd==0 ) //&& p.position_perso.x>=280              
  p.position_perso.x =p.position_perso.x-1 ; 
else {} }
else if  (indicate == 0 && IMAGE_main.direction == 2 )//yerje3 wa9if normale ba3d man7arkouh right
{movePerso(&IMAGE_main ,dt) ;}
else if(indicate == 0 && IMAGE_main.direction == 3)//yerja3 wa9if normale ba3d man7arkouh left 
{movePerso(&IMAGE_main ,dt) ; }
else  {}



 saut( &IMAGE_main,dt,IMAGE_main.pos_Screen.y) ;


/*---------------------------------------------------------------------*/

dt=SDL_GetTicks()-t_prev; // ala fin de la boucle du jeu 

/// khalil 
animer_image(&A); 
//animer_image_deux(&A2); 
 afficher_temps(&t, screen);
//.............C-MISE A JOUR DE L'ECRAN ----------------







 animerMinimap(&n);
    SDL_BlitSurface(n.sprite, &n.posSprite, screen, NULL);  
                                
SDL_Flip(screen) ; // raffraichir l'ecran

}

// liberation
saveScore(J, "Best.txt");
liberer_imageb(feu) ; 
liberer_perso_image(IMAGE_main)  ; 

liberer_perso_image(coeur)  ; 
liberer_perso_image(lost)  ; 

liberer_texte(txte) ;
TTF_CloseFont(txte.police) ;



/// khalil 
liberer_image(B) ; 
liberer_image(A) ; 
liberer_image(A2);
liberer_musique(music) ; 
//AZIZ
liberer_imagee(IMAGE);
liberer_imagee(IMAGE_BTN1);
liberer_imagee(IMAGE_BTN2);
liberer_musiquee(music2);

fclose(e.f);
TTF_Quit();
SDL_Quit();
//END OF AZIZ

liberer_musiquebrefj(mus1) ;
liberer_musiquebrefj(mus2) ;
liberer_musiquebrefj(mus3) ;

//siwar
libererMinimap(&n);
free_temps(&t);
free_minimap (&m);
free_anim (&a);
return 0 ; 
// quitter le SDL 
SDL_Quit() ;


}




