#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>   
#include <SDL/SDL_image.h>   
#include <SDL/SDL_mixer.h> 

#include <math.h>
#include "lot2.h"  




void initBack(background *b)
{
b->url="enemy.png"; 
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
b->pos_img_ecran.x=50; 
b->pos_img_ecran.y=0; 
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

void liberer_image(background b) 
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
    
    int largeur_sprite = 642/7;
    int hauteur_sprite = 314;
   
    b->camera_pos.w = largeur_sprite;
    b->camera_pos.h = hauteur_sprite;
if(b->s==50)
b->s=0;
b->s=b->s+1;

        SDL_BlitSurface(b->img,&b->camera_pos, b->sc, &b->pos_img_ecran);

       if(b->s%10==0){
        b->camera_pos.x += largeur_sprite;
        if (b->camera_pos.x >= 642) {
            b->camera_pos.x = 0;
        

       
        SDL_Flip(b->sc);
    }
  }
}


void animer_image_deux(background *b) {

    int largeur_sprite = 750/7;
    int hauteur_sprite = 143;
   
    b->camera_pos.w = largeur_sprite;
    b->camera_pos.h = hauteur_sprite;
if(b->s==50)
b->s=0;
b->s=b->s+1;

        SDL_BlitSurface(b->img,&b->camera_pos, b->sc, &b->pos_img_ecran);

       if(b->s%10==0){
        b->camera_pos.x += largeur_sprite;
        if (b->camera_pos.x >= 750) {
            b->camera_pos.x = 0;
        

        
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
b->pos_img_ecran.x=400; 
b->pos_img_ecran.y=0; 
b->camera_pos.x=0; 
b->camera_pos.y=0; 
b->camera_pos.h=SCREEN_H ; 
b->camera_pos.w=SCREEN_W ;

}





void initialiser_texte_score(texte *txte )
{ 
 TTF_Init; 
txte -> police = TTF_OpenFont("Dark-Graffiti.ttf",30) ;

txte -> color_txt.r =0 ; 
txte -> color_txt.g =0 ; 
txte -> color_txt.b = 0; 

txte -> pos_txt.x =1200; 
txte -> pos_txt.y =700;


 
}







void afficher_texte_score(SDL_Surface *screen, ScoreInfo t[], texte txte) {
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



   

void liberer_texte_score(texte txte) 
{

SDL_FreeSurface(txte.txt) ;                                    
}


void initialiser_audio(Mix_Music *music)
{
 if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS ,1024)==-1)
   {printf("%s",SDL_GetError()) ; }


 music=Mix_LoadMUS("song.mp3"); 
 Mix_PlayMusic(music,-1) ; 
 Mix_VolumeMusic(MIX_MAX_VOLUME/1) ; 
}

void liberer_musique(Mix_Music *music)
{ Mix_FreeMusic(music) ; }






















