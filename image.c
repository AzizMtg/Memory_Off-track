#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
/*--------ETAPE 0 DECLARATION DU BIBLIOTHEQUE SDL ---------------*/
#include <SDL/SDL_image.h>  // pour manipuler des image 

/*-------------------------------------------------------------------*/
#include "image.h" 

/******************************* TRAITEMENT DES IMAGES********************************************/

   /*------------------------1 initialisation image -------------------*/


// la foncion d'initialisation l'image du background 
//on affecte a l'atribut url l'adresse de l'mplacement de l'image on precise la position du background par rapport a l'ecran qui est toujours (0,0)
// on affiche ici la totalite de l'image du background
// on afficher la partie qui couvre tout l'ecran  
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


//l'emplacement du fichier image bouton
//pour la fonction d'initialisation de l'image bouton on definit l'url de l'emplacement du fichier de l'image 
void initialiser_imageBOUTON1(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="play.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}

imgbtn->pos_img_ecran .x=340; 
imgbtn->pos_img_ecran.y=300 ;
imgbtn->pos_img_ecran.w=200 ;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0;
imgbtn->pos_img_affiche.w=451;
imgbtn->pos_img_affiche.h=188 ; 

//on initialise la position du premier deux boutons au milieu de l'ecran su l'axe des x (a l'horizentale ) et au niveau de 1/3 de l'ecran sur l'axe y (a la verticale )
//imgbtn->pos_img_affiche.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/2) ;
//imgbtn->pos_img_affiche.y=((SCREEN_H-imgbtn->pos_img_affiche.h)/3) ;
}

 

void initialiser_imageBOUTON2(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="exit.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=340; 
imgbtn->pos_img_ecran.y=480 ;
imgbtn->pos_img_ecran.w=451 ;
imgbtn->pos_img_ecran.h=188;

 
imgbtn->pos_img_affiche.x=20 ; 
imgbtn->pos_img_affiche.y=25 ;
imgbtn->pos_img_affiche.w=250 ;
imgbtn->pos_img_affiche.h=250;



}

//initialisation nouveau bouton:
void initialiser_imageBOUTON3(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="load.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=340; 
imgbtn->pos_img_ecran.y=130 ;
imgbtn->pos_img_ecran.w=100 ;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=80 ; 
imgbtn->pos_img_affiche.y=100 ;
imgbtn->pos_img_affiche.w=500 ;
imgbtn->pos_img_affiche.h=500;
}
//el bouton li todhhor fog el play

void initialiser_imageBOUTON4(image *imgbtn) 
{

//chargement de l'image
imgbtn->url="play2.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img == NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=892; 
imgbtn->pos_img_ecran.y=0 ;
imgbtn->pos_img_ecran.w=100 ;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=80 ; 
imgbtn->pos_img_affiche.y=100 ;
imgbtn->pos_img_affiche.w=500 ;
imgbtn->pos_img_affiche.h=500;
}

//settings

void initialiser_imageSETTINGS(image *image)
     
{
image->url="set.png" ; 
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

image->pos_img_affiche.h=SCREEN_H ; 
image->pos_img_affiche.w=SCREEN_W ; 

}


//on initialise la position du 2 deuxieme boutons au milieu de l'ecran su l'axe des x (a l'horizentale ) et au niveau de 2/3 de l'ecran sur l'axe y (a la verticale )
//imgbtn->pos_img_affiche.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/2) ;
//imgbtn->pos_img_affiche.y=(3*(SCREEN_H-imgbtn->pos_img_affiche.h)/3) ;
//jai modifie le 2 en 3 car on a 3boutons now (idk)


void initialiser_imageK(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="k.jpg" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}

imgbtn->pos_img_ecran .x=892; 
imgbtn->pos_img_ecran.y=0 ;
imgbtn->pos_img_ecran.w=100 ;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=0; 
imgbtn->pos_img_affiche.y=0 ;
imgbtn->pos_img_affiche.w=100 ;
imgbtn->pos_img_affiche.h=100;

//on initialise la position du premier deux boutons au milieu de l'ecran su l'axe des x (a l'horizentale ) et au niveau de 1/3 de l'ecran sur l'axe y (a la verticale )
//imgbtn->pos_img_affiche.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/2) ;
//imgbtn->pos_img_affiche.y=((SCREEN_H-imgbtn->pos_img_affiche.h)/3) ;
}

//intitialisation bouton + volume

void initialiser_imageBOUTONP(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="dageza.jpg" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}

imgbtn->pos_img_ecran .x=740; 
imgbtn->pos_img_ecran.y=330 ;
imgbtn->pos_img_ecran.w=100 ;
imgbtn->pos_img_ecran.h=200 ;

 
imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0 ;
imgbtn->pos_img_affiche.w=200 ;
imgbtn->pos_img_affiche.h=200;
}

//intitialisation bouton - volume

void initialiser_imageBOUTONM(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="dagezahabta.jpg" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}

imgbtn->pos_img_ecran.x=630; 
imgbtn->pos_img_ecran.y=330 ;
imgbtn->pos_img_ecran.w=100 ;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=80 ; 
imgbtn->pos_img_affiche.y=100 ;
imgbtn->pos_img_affiche.w=500 ;
imgbtn->pos_img_affiche.h=500;

}


/*----------------initialiser bouton anime 1 fi wost il play-----------------------*/
void initialiser_imageanime1(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="anime1.jpeg" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=492; 
imgbtn->pos_img_ecran.y=250 ;
imgbtn->pos_img_ecran.w=100 ;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=20 ; 
imgbtn->pos_img_affiche.y=25 ;
imgbtn->pos_img_affiche.w=250 ;
imgbtn->pos_img_affiche.h=250;



}

//image 5 mte3 el volume

void initialiser_imageanime5(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="5v.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=492; 
imgbtn->pos_img_ecran.y=250 ;
imgbtn->pos_img_ecran.w=100 ;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=20 ; 
imgbtn->pos_img_affiche.y=25 ;
imgbtn->pos_img_affiche.w=250 ;
imgbtn->pos_img_affiche.h=250;


}

//image 4 mte3 el volume

void initialiser_imageanime4(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="4v.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=492; 
imgbtn->pos_img_ecran.y=250 ;
imgbtn->pos_img_ecran.w=100 ;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=20 ; 
imgbtn->pos_img_affiche.y=25 ;
imgbtn->pos_img_affiche.w=250 ;
imgbtn->pos_img_affiche.h=250;



}
//image 6 mte3 el volume

void initialiser_imageanime6(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="1v.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=492; 
imgbtn->pos_img_ecran.y=250 ;
imgbtn->pos_img_ecran.w=100 ;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=20 ; 
imgbtn->pos_img_affiche.y=25 ;
imgbtn->pos_img_affiche.w=250 ;
imgbtn->pos_img_affiche.h=250;



}


/*----------------initialiser bouton anime 2 fi wost il palay-----------------------*/
void initialiser_imageanime2(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="anime2.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=492; 
imgbtn->pos_img_ecran.y=250 ;
imgbtn->pos_img_ecran.w=100 ;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=20 ; 
imgbtn->pos_img_affiche.y=25 ;
imgbtn->pos_img_affiche.w=250 ;
imgbtn->pos_img_affiche.h=250;


}

/*----------------initialiser bouton anime 3 fi wost il play-----------------------*/
void initialiser_imageanime3(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="anime3.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=492; 
imgbtn->pos_img_ecran.y=250 ;
imgbtn->pos_img_ecran.w=100 ;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=20 ; 
imgbtn->pos_img_affiche.y=25 ;
imgbtn->pos_img_affiche.w=250 ;
imgbtn->pos_img_affiche.h=250;

}

//prot bouton full screen
void initialiser_imagefullscreen(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="fs.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=600; 
imgbtn->pos_img_ecran.y=490 ;
imgbtn->pos_img_ecran.w=100 ;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=20 ; 
imgbtn->pos_img_affiche.y=25 ;
imgbtn->pos_img_affiche.w=250 ;
imgbtn->pos_img_affiche.h=250;
}

//prot bouton windowed
void initialiser_imagewindowed(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="windowed.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=600; 
imgbtn->pos_img_ecran.y=600 ;
imgbtn->pos_img_ecran.w=100 ;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=20 ; 
imgbtn->pos_img_affiche.y=25 ;
imgbtn->pos_img_affiche.w=250 ;
imgbtn->pos_img_affiche.h=250;
}


       /*-------------------- 2 affichage de l'image ----------------------*/
 // la fonction SDL_BlitSurface() permet de  coller et afficher l'image sur  screen

//fonctions des annimations

void initialiser_annimation1(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="fire1.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}

imgbtn->pos_img_ecran.x=700; 
imgbtn->pos_img_ecran.y=100 ;
imgbtn->pos_img_ecran.w=200 ;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=40; 
imgbtn->pos_img_affiche.y=100;
imgbtn->pos_img_affiche.w=451;
imgbtn->pos_img_affiche.h=188 ; 

//on initialise la position du premier deux boutons au milieu de l'ecran su l'axe des x (a l'horizentale ) et au niveau de 1/3 de l'ecran sur l'axe y (a la verticale )
//imgbtn->pos_img_affiche.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/2) ;
//imgbtn->pos_img_affiche.y=((SCREEN_H-imgbtn->pos_img_affiche.h)/3) ;
}

void initialiser_annimation2(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="fire2.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}

imgbtn->pos_img_ecran.x=700; 
imgbtn->pos_img_ecran.y=300;
imgbtn->pos_img_ecran.w=200;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=40 ; 
imgbtn->pos_img_affiche.y=100;
imgbtn->pos_img_affiche.w=451;
imgbtn->pos_img_affiche.h=188 ; 

//on initialise la position du premier deux boutons au milieu de l'ecran su l'axe des x (a l'horizentale ) et au niveau de 1/3 de l'ecran sur l'axe y (a la verticale )
//imgbtn->pos_img_affiche.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/2) ;
//imgbtn->pos_img_affiche.y=((SCREEN_H-imgbtn->pos_img_affiche.h)/3) ;
}
void initialiser_annimation3(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="fire3.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}

imgbtn->pos_img_ecran.x=700; 
imgbtn->pos_img_ecran.y=500;
imgbtn->pos_img_ecran.w=200 ;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=60 ; 
imgbtn->pos_img_affiche.y=100;
imgbtn->pos_img_affiche.w=451;
imgbtn->pos_img_affiche.h=188 ; 

//on initialise la position du premier deux boutons au milieu de l'ecran su l'axe des x (a l'horizentale ) et au niveau de 1/3 de l'ecran sur l'axe y (a la verticale )
//imgbtn->pos_img_affiche.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/2) ;
//imgbtn->pos_img_affiche.y=((SCREEN_H-imgbtn->pos_img_affiche.h)/3) ;
}
//boutton side load back
void initialiser_imageloadb(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="loadb.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=340; 
imgbtn->pos_img_ecran.y=130 ;
imgbtn->pos_img_ecran.w=100 ;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=80 ; 
imgbtn->pos_img_affiche.y=100 ;
imgbtn->pos_img_affiche.w=500 ;
imgbtn->pos_img_affiche.h=500;



}

//button quit back
void initialiser_imagequitb(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="quitb.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran.x=340; 
imgbtn->pos_img_ecran.y=480 ;
imgbtn->pos_img_ecran.w=451 ;
imgbtn->pos_img_ecran.h=188;

 
imgbtn->pos_img_affiche.x=20 ; 
imgbtn->pos_img_affiche.y=25 ;
imgbtn->pos_img_affiche.w=250 ;
imgbtn->pos_img_affiche.h=250;



}

//bouton play back
void initialiser_imageplayb(image *imgbtn) 
{
//chargement de l'image
imgbtn->url="playb.png" ; //pour la fonction d'initialisation de l'image du bouton on definit l'url de l'emplacement du fichier de l'image  
imgbtn->img=IMG_Load(imgbtn->url); 
if (imgbtn->img ==NULL)
   {printf("unable to load background image %s ",SDL_GetError());
   return ;}
imgbtn->pos_img_ecran .x=340; 
imgbtn->pos_img_ecran.y=300 ;
imgbtn->pos_img_ecran.w=200 ;
imgbtn->pos_img_ecran.h=200;

 
imgbtn->pos_img_affiche.x=0 ; 
imgbtn->pos_img_affiche.y=0;
imgbtn->pos_img_affiche.w=451;
imgbtn->pos_img_affiche.h=188 ; 



}
///// extra 
void initialiser_EXTRAback(image *image)
{
image->url="extra_back.png" ; 
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

image->pos_img_affiche.h=1640 ; 
image->pos_img_affiche.w=1040 ; 

}


void initialiser_extra(image *image)
{
image->url="extra.png" ; 
image->img=IMG_Load(image->url) ; 
if (image->img == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
image->pos_img_ecran.x=892 ; 
image->pos_img_ecran.y=200 ; 

image->pos_img_affiche.x=0 ; 
image->pos_img_affiche.y=0; 

image->pos_img_affiche.h=1000 ; 
image->pos_img_affiche.w=800 ; 

}

void initialiser_EXTRA1(image *image)
{
image->url="extra1.png" ; 
image->img=IMG_Load(image->url) ; 
if (image->img == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
image->pos_img_ecran.x=0 ; 
image->pos_img_ecran.y=445 ; 

image->pos_img_affiche.x=0 ; 
image->pos_img_affiche.y=0; 

image->pos_img_affiche.h=1640 ; 
image->pos_img_affiche.w=140 ; 

}
void initialiser_EXTRA2(image *image)
{
image->url="extra2.png" ; 
image->img=IMG_Load(image->url) ; 
if (image->img == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
image->pos_img_ecran.x=350 ; 
image->pos_img_ecran.y=445 ; 

image->pos_img_affiche.x=200 ; 
image->pos_img_affiche.y=0; 

image->pos_img_affiche.h=1640 ; 
image->pos_img_affiche.w=1040 ; 

}
void initialiser_EXTRA3(image *image)
{
image->url="extra3.png" ; 
image->img=IMG_Load(image->url) ; 
if (image->img == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
image->pos_img_ecran.x=700 ; 
image->pos_img_ecran.y=445 ; 

image->pos_img_affiche.x=0 ; 
image->pos_img_affiche.y=0; 

image->pos_img_affiche.h=1640 ; 
image->pos_img_affiche.w=1040 ; 

}

//// ki tinzil 3al start 
void initialiser_START_BACK(image *image)
     
{
image->url="start.png" ; 
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

image->pos_img_affiche.h=SCREEN_H ; 
image->pos_img_affiche.w=SCREEN_W ; 

}

void initialiser_START_SINGLE_PLAYER(image *image)
{
image->url="play.png" ; 
image->img=IMG_Load(image->url) ; 
if (image->img == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
image->pos_img_ecran .x=340; 
image->pos_img_ecran.y=300 ;
image->pos_img_ecran.w=200 ;
image->pos_img_ecran.h=200;

 
image->pos_img_affiche.x=0 ; 
image->pos_img_affiche.y=0;
image->pos_img_affiche.w=451;
image->pos_img_affiche.h=188 ;
}

void initialiser_START_MULTIPLAYER(image *image)
{
image->url="playb.png" ; 
image->img=IMG_Load(image->url) ; 
if (image->img == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
image->pos_img_ecran.x=340; 
image->pos_img_ecran.y=130 ;
image->pos_img_ecran.w=100 ;
image->pos_img_ecran.h=200;

 
image->pos_img_affiche.x=80 ; 
image->pos_img_affiche.y=100 ;
image->pos_img_affiche.w=500 ;
image->pos_img_affiche.h=500;

}

void initialiser_START_RETURN(image *image)
{
image->url="play2.png" ; 
image->img=IMG_Load(image->url) ; 
if (image->img == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
 
image->pos_img_ecran.x=500; 
image->pos_img_ecran.y=480 ;
image->pos_img_ecran.w=100 ;
image->pos_img_ecran.h=200;

 
image->pos_img_affiche.x=80 ; 
image->pos_img_affiche.y=100 ;
image->pos_img_affiche.w=500 ;
image->pos_img_affiche.h=500;

}

/// credit
void initialiser_bouton_credit(image *image)
{
image->url="credit.png" ; 
image->img=IMG_Load(image->url) ; 
if (image->img == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
 
image->pos_img_ecran.x=790 ; 
image->pos_img_ecran.y=600 ; 

image->pos_img_affiche.x=0 ; 
image->pos_img_affiche.y=0; 

image->pos_img_affiche.h=1000 ; 
image->pos_img_affiche.w=800 ; 
}

void initialiser_credit_back(image *image)
{
image->url="creditsimage.png" ; 
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
void initialiser_bouton_credit_return(image *image)
{
image->url="play2.png" ; 
image->img=IMG_Load(image->url) ; 
if (image->img == NULL) 
{
printf("unable to load background image %s \n",SDL_GetError()) ;
 return ;  
}
 
image->pos_img_ecran.x=892 ; 
image->pos_img_ecran.y=500 ; 

image->pos_img_affiche.x=0 ; 
image->pos_img_affiche.y=0; 

image->pos_img_affiche.h=1000 ; 
image->pos_img_affiche.w=800 ; 
}


// ----------affichage du background ------------
void afficher_imageBMP(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du back sur  screen
}



// -------------affichage du image boutton 1 ---------------
void afficher_imageBTN1(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,&image.pos_img_affiche   , screen ,&image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du bonton play dans le screen
 
}

// -------------affichage du image boutton 2  ---------------
void afficher_imageBTN2(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img , NULL, screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du bonton 2 quit dans le screen
}

//affichage bouton jdida
void afficher_imageBTN3(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img , NULL, screen , &image.pos_img_ecran ) ; }

// -------------affichage du image boutton 4 ---------------
void afficher_imageBTN4(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du bonton play dans le screen
 
}

void afficher_imageSETTINGS(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du back sur  screen
}

// -------------affichage du image K ---------------
void afficher_imageK(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL  , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du bonton play dans le screen
 
}
// -------------affichage du image +vol ---------------
void afficher_imageP(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du bonton play dans le screen
 
}

// -------------affichage du image -vol ---------------
void afficher_imageM(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du bonton play dans le screen
 
}

// ----------affichage du full screen ------------
void afficher_imagefullscreen(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du back sur  screen
}

// ----------affichage du windowed ------------
void afficher_imagewindowed(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du back sur  screen
}

//animation
void afficher_annimation(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL  , screen ,&image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du bonton play dans le screen
 
}


   /*------------------------3 liberation image -------------------*/
// on utilise SDL_FreeSurface()
void liberer_image(image image) 
{
SDL_FreeSurface(image.img) ;
}
// ----------affichage du image anime 1 ------------
void afficher_imageANIME1(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface()
}

// ----------affichage du image anime 5 ------------
void afficher_imageANIME5(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface()
}

// ----------affichage du image anime 2 ------------
void afficher_imageANIME2(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface()
}

// ----------affichage du image anime 3 ------------
void afficher_imageANIME3(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface()
}
// ----------affichage du image anime 4 ------------
void afficher_imageANIME4(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface()
}

// ----------affichage du image anime 6 ------------
void afficher_imageANIME6(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface()
}

// -------------affichage du image play back ---------------
void afficher_imageplayb(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL  , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du bonton play dans le screen
 
}
// -------------affichage du image quit back ---------------
void afficher_imagequitb(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL  , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du bonton play dans le screen
 
}


// -------------affichage du image load back ---------------
void afficher_imageloadb(SDL_Surface *screen , image image )
{ 
SDL_BlitSurface(image.img ,NULL  , screen , &image.pos_img_ecran ) ; // la fonction SDL_BlitSurface() permet de  coller et afficher l'image du bonton play dans le screen
 
}

