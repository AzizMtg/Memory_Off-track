#ifndef LOT1_H
#define LOT1_H
#define SCREEN_H 600
#define SCREEN_W 1200

 
/*--------------------------------------manipulerl"image du personnage ------------------------*/ 



//enemys

typedef struct
{
    SDL_Rect pos_depart;
    SDL_Rect pos_actuelle;
    int direction;
    float vitesse;
    SDL_Surface *spritesheet;
    SDL_Rect pos_sprites;
    SDL_Surface *locationIcon;
    int frame;
    int frameCount;
    int frameWidth;
    int frameHeight;

    int alive;
    int soundChannel;
} Ennemi;

typedef struct
{
    char *url;
    SDL_Rect pos_img_affiche;
    SDL_Rect pos_img_ecran;
    SDL_Surface *img;

} E_image;


void initialiser_imageBACKEnemy(E_image *image);

void initEnnemi(Ennemi *e);
void initEnnemi2(Ennemi *e);
void afficherEnnemi(Ennemi e, SDL_Surface *screen);
void animerEnemi(Ennemi *e);
void move(Ennemi *e,SDL_Rect camera);
void liberer_ennemi(Ennemi e); 




//enemy level 2 big
void initEnnemibig(Ennemi *e);
void afficherEnnemibig(Ennemi e, SDL_Surface *screen);
void animerEnemibig(Ennemi *e);
void movebig(Ennemi *e, SDL_Rect camera);
void initEnnemibig2(Ennemi *e);
void initEnnemibig3(Ennemi *e);
void liberer_ennemibig(Ennemi e);
























////siwar//////////////////



typedef struct
{
SDL_Surface *table;
SDL_Surface *bg;
SDL_Surface *t[2];
int i[3][3];       
SDL_Rect r[3][3];
int turn;
int choixx;
int choixy;
}xo;

int game(SDL_Surface *screen);








typedef struct 
{ SDL_Surface *joueur;

	SDL_Rect position_mini;
	SDL_Surface *sprite;
}minimap;


typedef struct  {
    
    SDL_Surface *sprite;
   
    SDL_Surface *surface;
SDL_Rect pos;
   
    int direction;
    int num;
  

    SDL_Rect posScreen;
    SDL_Rect posSprite;
   
    int nb_frames[4];         
} minimap1;






typedef struct temps {
    char entree[32];
    int countdown_en_cours; 
    int go; 
    int secondes_restantes;
    int duree_totale; 
    int min; 
    int sec; 
    Uint32 t1; 
    SDL_Surface *texte;
    TTF_Font *police;
    SDL_Rect position;
} temps;

typedef struct 
{
	SDL_Rect position_anim;
	SDL_Surface *sprite;
}anim;





typedef struct 
{ // url une chaine de caractere conenant l'emplacement du fichier image
  char *url ; 

 //partie de l'image doit etre afficher 
 SDL_Rect    pos_img_affiche; // son type est SDL_Rect qui definit la position de l'image par rapport a l'ecran
 
 // position de l'image par rapport a l'ecran 
 SDL_Rect      pos_img_ecran ; // son type est SDL_Rect qui precise quelle partie de l'image doit etre afficher 
 
 SDL_Surface    *img ;   // declaration d'un pointeur de surface pour manipuler l'image

}image1; 

typedef struct 
{


	SDL_Rect position_perso;
 	
char *url ; // url une chaine de caractere conenant l'emplacement du fichier image

SDL_Rect  pos_Screen ;  // position de l'image par rapport de l"ecran 
SDL_Rect  pos_Sprite  ;  // positon  de l"image par rapport du sprite

SDL_Surface *sprite  ;  //declaration d un pointeur image du sprite sheet pour manipuler l image 

int direction  ,d  ;  // direction  de deplacement 


int score , vie ; 
double vitesse,  acceleration;

int up ; // stocker l etat du personnage 1 MVT saut sinon 0 

double dx ; 

}personne ; 


// initialisation
void initPerso(personne *p  , int v  ); 	  // initialiser personnage principale 	
void movePerso (personne *p , Uint32 dt )   ; //deplacer personnage avec acceleration  !! 
void saut( personne *P,int dt, int posinit) ; // saut du personnage principale avec  posinit la position initiale du personnage saut normale du personnage 
void drouj ( personne *p, int posx_absolu, int posy_absolu) ; // yitla3 ill drouj 
void saut_personnage ( personne *P, Uint32 dt, int posx_absolu, int posy_absolu)  ; // saut parabolique du personnage 

void init(personne * p, int numperso)  ; // initialisation 2 joueur 

//affichage 
void afficherPerso(personne p, SDL_Surface * screen); // affichage du personnage principale 
 
// animation personnage 
void animerPerso (personne* p) ; 

// liberation 
void liberer_perso_image(personne p) ; 



////////////////////////////////////////////////////siwar////////////////////////////////////////
//lminimap 


void initmap( minimap *m);
void afficherminimap (minimap m, SDL_Surface * screen);
void free_minimap (minimap *m);


//temps siwar 
void initialiser_temps(temps *t, int duree_totale, int countdown);
void afficher_temps(temps *t, SDL_Surface *screen);
void free_temps(temps *t);

//mta3 !
void init_anim( anim *a);
void afficher_anim (anim a, SDL_Surface * screen);
void free_anim (anim *a);


//animationsiwar hourglass
void initialiseMinimap(minimap1 *n, int nb_frames_right, int nb_frames_left, int screen_x, int screen_y) ;
void animerMinimap(minimap1 *n);
void libererMinimap(minimap1 *n);

//collision 

SDL_Color GetPixel(SDL_Surface *Background, int x, int y);
int collisionPP( personne p, SDL_Surface * Masque);








/*--------------------------------------manipuler le song  ------------------------
//song continue 
void initialiser_audio(Mix_Music *music) ; 
void liberer_musique(Mix_Music *music) ;

//song bref 
void initialiser_audiobref(Mix_Chunk *music) ;
void liberer_musiquebref(Mix_Chunk *music) ;


  


--------------------------------------manipuler du texte   ------------------------*/

//on a besoin de definir une structure texte :

typedef struct 
{
SDL_Surface *txt ; // un pointeur SDL_Surface pour manipuler le texte 
SDL_Rect pos_txt  ; // preciser sa position de l'image par rapport a l'ecran
SDL_Colour color_txt ; // couleur de texte en format (r,g,b) doit etre entre 0 et 255
TTF_Font *police ; // la police du texte se trouve sur un fichier de police (format.ttf)

char ch[3] ; 
}texte1 ; 



//definition pour la manipulation du texte
void initialiser_texte1(texte1 *txte ,int k ,int k2 ) ; 
void afficher_texte1(SDL_Surface *screen , texte1 txte) ; 
void liberer_texte1(texte1 txte) ; 

/*----------------------------------------------------------------------------------------*/




void initialiser_feu(image1 *imgbtn)  ;
void afficher_feu(SDL_Surface *screen , image1 image ) ;
void liberer_imageb(image1 p) ;



void initialiser_coeur(personne *p ,int i   );  // initialisation image coeur 
void initialiser_lost(personne *p );  

              //------------

void initialiser_audiobrefj1(Mix_Chunk *music) ;
void initialiser_audiobrefj2(Mix_Chunk *music) ;
void initialiser_audiobrefj3(Mix_Chunk *music) ;
void liberer_musiquebrefj(Mix_Chunk *music) ;

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
void liberer_image1(background b) ;

void scrolling(background *b,int direction,int pas);

void bestScore(char *filename, ScoreInfo t[]);
void saveScore(ScoreInfo s, char *fileName);

void initanimation(background *b);
void animer_image(background *b);

void initanimation_deux(background *b);
void animer_image_deux(background *b);

void initialiser_texte_score(texte1 *txte );
void bestScore(char *filename, ScoreInfo t[]);
void afficher_texte_score(SDL_Surface *screen, ScoreInfo t[], texte1 txte);
void liberer_texte_score(texte1 txte);

void initialiser_audio1(Mix_Music *music) ; 
void liberer_musique1(Mix_Music *music) ;
	//AZIZ
typedef struct {
    FILE* f;
    char question[400];
    char r1[50];
    char r2[50];
    char r3[50];
    int numbr;
    char x[50];
    image1 images[3];
SDL_Surface *screen;
} enigme;


void afficherEnigme(SDL_Surface *screen, enigme e);

// definition des fenetre des fonction 

//definition pour la manipulation de l'image 
void initialiser_BACK(image1 *image) ; 
void initialiser_BOUTON1(image1 *image) ; 
void initialiser_BOUTON2(image1 *image) ; 

void afficher_BTN1(SDL_Surface *screen , image1 image ) ;
void afficher_BTN2(SDL_Surface *screen , image1 image) ;

void afficher_BMP(SDL_Surface *screen , image1 image) ; 
void genererEnigme(char* filename, enigme* e);

void animate(enigme *e);

void liberer_imagee(image1 image) ; 


//definition pour la manipulation de l'audio 
void initialiser_audioe(Mix_Music *music) ; 
void liberer_musiquee(Mix_Music *music) ;
//END OF AZIZ	


//fonction sous menu
void initialiser_imageloadsettings(image1 *image);





//fonction level1

int level1(int val );


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////SCENE 1 

int SCENE1(int val ) ; 


// definition des fenetre des fonction 

//definition pour la manipulation de l'image 
void initialiser_imageSTORY(image1 *image)     ; 
void initialiser_imageSCENE1(image1 *imgbtn) ; 
void initialiser_imageSCENE2(image1 *imgbtn) ; 
void initialiser_imageSCENE3(image1 *imgbtn) ; 

void initialiser_s5(image1 *imgbtn)  ;
void initialiser_s6(image1 *imgbtn)  ;
void initialiser_s7(image1 *imgbtn) ;
void initialiser_s8(image1 *imgbtn) ;
void initialiser_s9(image1 *imgbtn) ;
void initialiser_s10(image1 *imgbtn) ;
void initialiser_s11(image1 *imgbtn) ;
void initialiser_s12(image1 *imgbtn) ;
void initialiser_s13(image1 *imgbtn) ;
void initialiser_s14(image1 *imgbtn) ;
void initialiser_s15(image1 *imgbtn) ;
void initialiser_s16(image1 *imgbtn) ;
void initialiser_s17(image1 *imgbtn) ;
void initialiser_s18(image1 *imgbtn) ;
void initialiser_s19(image1 *imgbtn) ;
void initialiser_s20(image1 *imgbtn) ;
void initialiser_s21(image1 *imgbtn) ;
void initialiser_s22(image1 *imgbtn) ;
void initialiser_s23(image1 *imgbtn) ;
void initialiser_s24(image1 *imgbtn) ;
void initialiser_s25(image1 *imgbtn) ;
void initialiser_s26(image1 *imgbtn) ;
void initialiser_s27(image1 *imgbtn) ;
void initialiser_s28(image1 *imgbtn) ;
void initialiser_s29(image1 *imgbtn) ;
void initialiser_s30(image1 *imgbtn) ;
void initialiser_s31(image1 *imgbtn) ;
void initialiser_s32(image1 *imgbtn) ;
void initialiser_s33(image1 *imgbtn) ;
void initialiser_s34(image1 *imgbtn) ;
void initialiser_s35(image1 *imgbtn) ;
void initialiser_s36(image1 *imgbtn) ;
void initialiser_s37(image1 *imgbtn) ;



void afficher_imagestory(SDL_Surface *screen , image1 image) ; 
void afficher_SCENE1(SDL_Surface *screen , image1 image ) ; 
void afficher_SCENE2(SDL_Surface *screen , image1 image ) ; 
void afficher_SCENE3(SDL_Surface *screen , image1 image ) ;



void liberer_imager(image1 image) ; 


////////////////////////////////////////////////level2


void initmap2( minimap *m);
int level2(int val);

void initBack2(background *b);
void initialiser_image_level2(image1 *image) ; 
void initialiser_imageBOUTON1_level2(image1 *imgbtn) ;
void initialiser_imageBOUTON2_level2(image1 *imgbtn) ; 

///////////////////////////////////////////////////////////// multiplayer
/////////////////////////////////////////////

int multiplayer() ; 


void initPerso2(personne *p , int v   ) 	;
void movePerso2 (personne *p , Uint32 dt ,int d )    ; 
void saut2( personne *P,int dt, int posinit) ;
void drouj2 ( personne *p, int posx_absolu, int posy_absolu) ; 
void saut_personnage2 ( personne *P, Uint32 dt, int posx_absolu, int posy_absolu ) ; 
void afficherPerso2(personne p, SDL_Surface * screen); 

void animerPerso2 (personne* p) ; 


void liberer_imagep2(personne p) ; 


void init2(personne * p, int numperso)  ;






void initialiser_texte2(texte1 *txte ,int k ,int k2 ,int *score  ) ; 
void afficher_texte2(SDL_Surface *screen , texte1 txte) ; 
void liberer_texte2(texte1 txte) ; 





void initialiser_imageBACK2(image1 *image) ; 
void afficher_imageBMP2(SDL_Surface *screen , image1 image ) ;
void initialiser_feu2(image1 *imgbtn)  ;
void afficher_feu2(SDL_Surface *screen , image1 image ) ;
void liberer_imageb2(image1 p) ;



void initialiser_coeur2(personne *p ,int i ,int *vie) ;  
void initialiser_lost2(personne *p );  






////////////////////////////////////// khalil ////////////////////////////////////////
/*-----------------------------------khalil --------------------------------------------*/




typedef struct 
{char *url ;
SDL_Surface *img; 
SDL_Surface *sc;
SDL_Rect pos_img_ecran1; 
SDL_Rect camera_pos1;
SDL_Rect pos_img_ecran2; 
SDL_Rect camera_pos2;
int s;
}backgroundtwo; 




void initanimation_two(background *b);
void animer_image_two(background *b);


// double ecran


void initBacktwo(backgroundtwo *b);
void afficherbacktwo(SDL_Surface *screen,backgroundtwo b );
void liberer_imagetwo(backgroundtwo b);
void scrollingone(backgroundtwo *b, int direction_one,int pas);
void scrollingtwo(backgroundtwo *b, int direction_two,int pas);


		

#endif 



















int level1_2(int val );




//////////////////////////////////////////////





void SCENE2();
void initialiser_imageSCENEE1(image1 *imgbtn) ;

void initialiser_imageSCENEE2(image1 *imgbtn) ;

void initialiser_imageSCENEE3(image1 *imgbtn) ;

void initialiser_ss5(image1 *imgbtn) ;

void initialiser_ss6(image1 *imgbtn) ;

void initialiser_ss7(image1 *imgbtn) ;

void initialiser_ss8(image1 *imgbtn) ;

void initialiser_ss9(image1 *imgbtn) ;








