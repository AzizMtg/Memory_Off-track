#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
/*--------ETAPE 0 DECLARATION DU BIBLIOTHEQUE SDL ---------------*/
#include <SDL/SDL_image.h>  // pour manipuler des image 
#include <SDL/SDL_mixer.h>  // pour manipuler des audio 
#include <SDL/SDL_ttf.h>    // pour manipuler des texte 
/*-------------------------------------------------------------------*/
#include "enigme.h" 



/******************************* TRAITEMENT DES IMAGES********************************************/

   /*------------------------1 initialisation image -------------------*/


// la foncion d'initialisation l'image du background 
//on affecte a l'atribut url l'adresse de l'mplacement de l'image on precise la position du background par rapport a l'ecran qui est toujours (0,0)
// on affiche ici la totalite de l'image du background
// on afficher la partie qui couvre tout l'ecran  
void initialiser_imageBACK(image *image)
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

void initialiser_imageBOUTON1(image *imgbtn) 
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

void initialiser_imageBOUTON2(image *imgbtn) 
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




//l'emplacement du fichier image bouton
//pour la fonction d'initialisation de l'image bouton on definit l'url de l'emplacement du fichier de l'image 


 


       /*-------------------- 2 affichage de l'image ----------------------*/
 // la fonction SDL_BlitSurface() permet de  coller et afficher l'image sur  screen


// ----------affichage du background ------------
void afficher_imageBMP(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du back sur  screen
}

void afficher_imageBTN1(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL   , screen ,&image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du bonton play dans le screen
 
}

void afficher_imageBTN2(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL   , screen ,&image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du bonton play dans le screen
 
}


   /*------------------------3 liberation image -------------------*/
// on utilise SDL_FreeSurface()
void liberer_image(image image) 
{
SDL_FreeSurface(image.img) ;
}


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
 music=Mix_LoadMUS("happy.mp3"); // chargement de la musique
 Mix_PlayMusic(music,-1)  ;//  jouer la musique 
 Mix_VolumeMusic(MIX_MAX_VOLUME/3.5) ; 
}


   /*------------------------3 liberation musique -------------------*/
void liberer_musique(Mix_Music *music)
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



void animate(SDL_Surface *screen, enigme *e) {
    int frame = 0;
    char *image_names[3] = {"fire1.png", "fire2.png", "fire3.png"};

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
        SDL_BlitSurface(e->images[frame].img, NULL, screen, &e->images[frame].pos_img_ecran);
        SDL_Flip(screen);

        // Wait for some time
        SDL_Delay(280);

        // Remove the current image from the screen

        // Free the memory allocated for the current image
        SDL_FreeSurface(e->images[frame].img);

        // Move to the next image

        frame++;
    }
}
