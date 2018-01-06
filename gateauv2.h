#ifndef GATEAUV2_H_INCLUDED
#define GATEAUV2_H_INCLUDED

typedef struct ingredient
{
	char designation[10];
	int quantite;
	float prix_unitaire;

}ingredient;


typedef struct gateau 
{
	int type;
	int nombre_ingredients;
	ingredient tab_ingredient[10];

}gateau;





void saisir (gateau *g);
void ajouterGateau(gateau tabG[],gateau g,int *tg);
void afficher(gateau tabG[],int tg);
void trouver(gateau tabG[],int tg,int type,int *pos);
float calculerPrix(gateau g);
void initialiser(int MatV[][7],gateau tabG[],int type,int jour,int *tg,float tabP[]);
void vendre(int matV[][7], gateau tabG[], int type, int jour, int *tg, float tabP[]);
void afficherRecette(int matV[][7],int jour,float tabP[]);
#endif // GATEAUV2_H_INCLUDED
