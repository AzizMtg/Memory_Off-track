#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>
/*--------ETAPE 0 DECLARATION DU BIBLIOTHEQUE SDL ---------------*/
#include <SDL/SDL_ttf.h>    // pour manipuler des texte 
#include <SDL/SDL_image.h>  // pour manipuler des image 
#include <SDL/SDL_mixer.h>  // pour manipuler des audio 
/*-------------------------------------------------------------------*/ 

#include "lot1.h"  


int main()
{
TTF_Init();
SDL_Init(SDL_INIT_VIDEO);
/* ---------ETAPE 1 DECLARATION DES VARIABLE----------- */
SDL_Surface *screen ;  // screen variable pointeur sur surface de l'arriere plan
personne IMAGE_main ,coeur ,lost;
image IMAGE ,feu ; 
 temps chrono;
int countdown_en_cours = 0;
SDL_Event   event ;  // variable pour l'evenement de l'utillis  
int boucle =1 ;
temps t;
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
int i = 0 ,i2=48 ,i3=48 ,boucle2=1 ; 

texte  txte, texte_score ;

Mix_Chunk *mus1 ,*mus2 , *mus3; 
///////////////////////////// declaration khalil 
background B,A,A2 ;
int direction=-1;
int con=0;
const Uint8* keystates = SDL_GetKeyState(NULL);

//declaration aziz 
image IMG, IMAGE_BTN1, IMAGE_BTN2;
    enigme e;
    e.numbr=0;
    int input=0;
    int boucleinput=0;
    int bouclenigme=0;



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
initPerso(&IMAGE_main)  ;



initialiser_coeur(&coeur ,i ) ; 
initialiser_lost(&lost ); 


initialiser_texte(&txte,i3,i2) ; 
initialiser_texte_score(&texte_score );

/// khalil 
initBack(&B) ;
initanimation(&A);
initanimation_deux(&A2);
bestScore("Best.txt", Tri); 
initialiser_audio(music) ; 



//siwar

 masked=IMG_Load("mask.png");

    p.sprite=IMG_Load("miniperson.png");
    p.position_perso.x=260;
    p.position_perso.y=120;





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


// il vie 
if (IMAGE_main.pos_Screen.x ==200&&IMAGE_main.pos_Screen.y <=450&&IMAGE_main.pos_Screen.y >=350) 
{i= i+25 ;
initialiser_coeur(&coeur ,i ) ;
 
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

//........... -A AFFICHAGE................ 






// khalil 
afficherback(screen,B) ;
//siwar
afficherminimap ( m,screen);
   SDL_BlitSurface(p.sprite, NULL, screen, &p.position_perso);


afficher_anim (a,  screen);

//khalil
afficher_feu(screen ,feu ) ;
afficherPerso(IMAGE_main ,screen) ;

afficherPerso(coeur ,screen) ;




 
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
               }
             
          if (event.key.keysym.sym==SDLK_LEFT)  // yarja3  bil twali 
                {IMAGE_main.direction = 0;  IMAGE_main.acceleration=0;
                 indicate = 1 ; 


                 //// khalil 
                 direction = 1;
                        con=1;
                initialiser_audiobrefj1(mus1) ;
                }

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
            if (event.key.keysym.sym == SDLK_w) {   //attack imin et isar
           indicate = 0 ;  IMAGE_main.d  =3; 
          }

        // wa9tlili il bouton yirja3 normale houwa bich ya9if 
          if (event.key.keysym.sym == SDLK_RIGHT) 
            {
           indicate = 0 ; IMAGE_main.direction = 2 ;
           ///khalil 
          if (direction == 0) 
                {con=0; }
            }


           if (event.key.keysym.sym == SDLK_LEFT)
           {
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
{scrolling(&B,direction,pas); }


if (indicate ) 
{movePerso(&IMAGE_main ,dt) ;   }
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
animer_image_deux(&A2); 
 afficher_temps(&t, screen);
//.............C-MISE A JOUR DE L'ECRAN ----------------

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
free_temps(&t);
free_minimap (&m);
free_anim (&a);
return 0 ; 
// quitter le SDL 
SDL_Quit() ;


}





























