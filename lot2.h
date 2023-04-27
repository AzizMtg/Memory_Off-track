#ifndef LOT1_H
#define LOT1_H




#define SCREEN_H 600
#define SCREEN_W 1200










typedef struct 
{
SDL_Surface *txt ; 
SDL_Rect pos_txt  ; 
SDL_Colour color_txt ;
TTF_Font *police ; 

char ch[3] ; 
}texte ; 




/*-----------------------------------khalil --------------------------------------------*/

typedef struct 
{char *url ;
SDL_Surface *img; 
SDL_Surface *sc;
SDL_Rect pos_img_ecran; 
SDL_Rect camera_pos;
int s;
}background; 

typedef struct{
int nomjoueur;
int score;
int temps;
}ScoreInfo;


void initBack(background *b);
void afficherback(SDL_Surface* screen,background b);
void liberer_image(background b) ;

void scrolling(background *b,int direction,int pas);

void bestScore(char *filename, ScoreInfo t[]);
void saveScore(ScoreInfo s, char *fileName);

void initanimation(background *b);
void animer_image(background *b);

void initanimation_deux(background *b);
void animer_image_deux(background *b);

void initialiser_texte_score(texte *txte );
void bestScore(char *filename, ScoreInfo t[]);
void afficher_texte_score(SDL_Surface *screen, ScoreInfo t[], texte txte);
void liberer_texte_score(texte txte);

void initialiser_audio(Mix_Music *music) ; 
void liberer_musique(Mix_Music *music) ;
		
#endif 
