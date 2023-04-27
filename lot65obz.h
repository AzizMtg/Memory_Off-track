#ifndef ENIGME_H
#define ENIGME_H

#define NB_QUESTIONS 3

typedef struct 
{

SDL_Surface *image,*image_gagner,*image_perdu;
SDL_Rect pos,posBG;
int aleatoire;
int votre_reponse;
int bonne_reponse;
int affiche; 
int answered_correctly;
int reponses_correctes[NB_QUESTIONS];
}enigma;


void initialisation_enigme(enigma *a,char *nom_fichier);
void affichage_enigme(enigma a, SDL_Surface *ecran);
int reponse_utilisateur(enigma *enig,SDL_Event event);
void afficher_resultat(SDL_Surface *ecran,enigma *a);

#endif



