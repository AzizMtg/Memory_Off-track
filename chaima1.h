#ifndef LOT1_H
#define LOT1_H





#define SCREEN_H 744
#define SCREEN_W 800




typedef struct 
{
  char *url ; 
 SDL_Rect    pos_img_affiche; 
 SDL_Rect      pos_img_ecran ; 
 SDL_Surface    *img ;

}image; 


typedef struct 
{
char *url ; 

SDL_Rect  pos_Screen ; 
SDL_Rect  pos_Sprite  ; 

SDL_Surface *sprite  ; 

int direction  , d  ; 

int score , vie ; 
double vitesse,  acceleration;

int up ;

double dx ; 

}personne ; 

void initPerso(personne *p  ) 	;
void movePerso (personne *p , Uint32 dt )   ; 
void saut( personne *P,int dt, int posinit) ;
void drouj ( personne *p, int posx_absolu, int posy_absolu) ; 
void saut_personnage ( personne *P, Uint32 dt, int posx_absolu, int posy_absolu)  ; 

void afficherPerso(personne p, SDL_Surface * screen); 

void animerPerso (personne* p) ; 


void liberer_image(personne p) ; 


void init(personne * p, int numperso)  ;












typedef struct 
{
SDL_Surface *txt ; 
SDL_Rect pos_txt  ; 
SDL_Colour color_txt ; 
TTF_Font *police ; 

char ch[3] ; 
}texte ; 




void initialiser_texte(texte *txte ,int k ,int k2 ,int *score  ) ; 
void afficher_texte(SDL_Surface *screen , texte txte) ; 
void liberer_texte(texte txte) ; 





void initialiser_imageBACK(image *image) ; 
void afficher_imageBMP(SDL_Surface *screen , image image ) ;
void initialiser_feu(image *imgbtn)  ;
void afficher_feu(SDL_Surface *screen , image image ) ;
void liberer_imageb(image p) ;



void initialiser_coeur(personne *p ,int i ,int *vie) ;  
void initialiser_lost(personne *p );  



//----------------------------------------
void initialiser_audiobrefj1(Mix_Chunk *music) ;
void initialiser_audiobrefj2(Mix_Chunk *music) ;
void initialiser_audiobrefj3(Mix_Chunk *music) ;
void liberer_musiquebrefj(Mix_Chunk *music) ;





		
#endif 
