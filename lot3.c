
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>
#include <SDL/SDL_ttf.h> 
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h> 
#include"lot3.h"
//minimap


void initmap( minimap *m)
{
	m->position_mini.x=250;
	m->position_mini.y=0;
	m->sprite=NULL;
    m->sprite=IMG_Load("minimap.png");
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
    t->position.x = 45;
    t->position.y = 0;
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




//animation ajoute
void init_anim( anim *a)

{
	a->position_anim.x=1175;
	a->position_anim.y=140;
	a->sprite=NULL;
    a->sprite=IMG_Load("what.png");
    
    
}
void init_anim1( anim *a1)

{
	a1->position_anim.x=970;
	a1->position_anim.y=140;
	a1->sprite=NULL;
    a1->sprite=IMG_Load("what.png1");
    
    
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





//animation demande 
 
void initialiseMinimap(minimap1 *n, int nb_frames_right, int nb_frames_left) {
    n->direction = 0;
    n->posSprite = (SDL_Rect) { 0, 0, 0, 0 };
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
}


void animerMinimap(minimap1 *n) { 
    int largeur_sprite = n->sprite->w;
    int hauteur_sprite = n->sprite->h;
    int NBC = (n->nb_frames[0] > n->nb_frames[1]) ? n->nb_frames[0] : n->nb_frames[1];

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
SDL_Delay(200);
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


int collisionPP( Personne p, SDL_Surface * Masque)
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




//mouvement 

void mouvement(Personne *p ,Personne *pM ,Personne *pMprochaine, int distance, int longueur,int longueurM , SDL_Surface *masked , int sens)
{
    if(sens==1)
    {
                    pMprochaine->position_perso.x+=distance;
                    if(pMprochaine->position_perso.x >=longueurM)
                    {
                        pMprochaine->position_perso.x=longueurM;
                        pM->position_perso.x=longueurM;
                        p->position_perso.x=longueur+250;
                    }
                    else if(collisionPP( *pMprochaine, masked)==0)
                    {
                        pM->position_perso.x=pMprochaine->position_perso.x;
                        p->position_perso.x+=(distance*longueur/longueurM);
                    }
                    else{
                        pMprochaine->position_perso.x=pM->position_perso.x;
                    }
    }
    else if(sens==-1)
    {
        pMprochaine->position_perso.x-=distance;
                    if(pMprochaine->position_perso.x <=0)
                    {
                       pMprochaine->position_perso.x=0; 
                       pM->position_perso.x=0;
                       p->position_perso.x=250;
                    }
                    else if(collisionPP( *pMprochaine, masked)==0 )
                    {
                        pM->position_perso.x=pMprochaine->position_perso.x;
                        p->position_perso.x-=(distance*longueur/longueurM);
                       
                    }
                    else{
                        pMprochaine->position_perso.x=pM->position_perso.x;
                    }

    }
}




/*mAJ
//mise a jour de la position du personnage

void MAJMinimap(SDL_Rect posJoueur, minimap* v, SDL_Rect camera, int redimensionnement) {
    // 1-calculer la position absolue du joueur par rapport au background
    SDL_Rect posJoueurABS = { posJoueur.x + camera.x, posJoueur.y + camera.y, posJoueur.w, posJoueur.h };
//posjoueur= la position relative du joueur par rapport à l'écran
// camera est la position de la caméra :un outil de scrolling 
 //posJoueurABS est une nouvelle structure SDL_Rect qui contient les coordonnées absolues du joueur sur le fond d'écran, c'est-à-dire la position réelle du joueur dans le monde du jeu.  
    //  calcule la position du joueur sur la minimap en appliquant le redimensionnement sur les coordonnées absolues du joueur.
   


//2-calculer la position du joueur sur la minimap
 SDL_Rect posJoueurMini = {//La variable posJoueurMini de type SDL_Rect contient les informations nécessaires pour placer l'image du joueur sur la minimap
        v->pos.x + posJoueurABS.x * 3 / 100,//m->pos.x et m->pos.y : la position de la minimap sur l'écran
        v->pos.y + posJoueurABS.y * 3 / 100,
        v->joueur->w,//la largeur et la hauteur de l'image du joueur sur la minimap.
        v->joueur->h
    };
    
    // dessiner le joueur sur la minimap
    SDL_BlitSurface(v->joueur, NULL, v->surface, &posJoueurMini);
//la position du joueur sur la minimap est donnée par la variable pos_mini_Joueur.
}
*/
