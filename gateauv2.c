 #include"gateauv2.h"


void saisir (gateau *g)
{
	int i;
	printf("Type du gateau (0 chocolat,1 nougatine,2pistache) ");
	scanf("%d",&g->type);
	printf("\n Nombre d'ingredients :" );
	scanf("%d",&g->nombre_ingredients);
	for(i=0;i<g->nombre_ingredients;i++)
	{

		printf("ingredient %d \n",i );
		printf("Designation : ");
		scanf("%s",g->tab_ingredient[i].designation);
		printf("\n Quantite : ");
		scanf("%d",&g->tab_ingredient[i].quantite);
		printf("\nPrix unitaire :");
		scanf("%f",&g->tab_ingredient[i].prix_unitaire);
	}

}


void ajouterGateau(gateau tabG[],gateau g,int *tg)
{
	tabG[*tg]=g;
		(*tg)++;
}




void afficher(gateau tabG[],int tg)
{
		int i,k;
		for(i=0;i<tg;i++)
		{
			  printf("Gateau %d \n",i+1);
        printf("Type %d\n",tabG[i].type);
        printf("Nombre ingredients : %d \n",tabG[i].nombre_ingredients);
        for(k=0;k<tabG[i].nombre_ingredients;k++)
        {
            printf("ingredient %d designation %s",k+1,tabG[i].tab_ingredient[k].designation);
            printf("\n quantite %d",tabG[i].tab_ingredient[k].quantite);
            printf("\n prix unitaire %f \n",tabG[i].tab_ingredient[k].prix_unitaire);
        }
        printf("*******\n");
		}
}


void trouver(gateau tabG[],int tg,int type,int *pos)
{
	int i;
	if (tg==0)
	{
		*pos=-1;
	}
		for (i=0;i<tg;i++)
		{
			if(type==tabG[i].type)
			{
				*pos=i;
				break;
			}
		}
}




float calculerPrix(gateau g)
{
	int i;
	float prix=0;
	float cout=0;
	cout=0;
		for(i=0;i<g.nombre_ingredients;i++)
		{
			cout+=(g.tab_ingredient[i].quantite*g.tab_ingredient[i].prix_unitaire);
			
		}
		switch(g.type)
		{
		case 0:
		prix=cout +((cout*10)/100);
		break;
		case 1:
		prix=cout + ((cout*15)/100);
		break;
		case 2:
		prix=cout + ((cout*20)/200);
		break;
		}
	return prix;
}




void initialiser(int MatV[][7],gateau tabG[],int type,int jour,int *tg,float tabP[])
{
	int i,k;
		for(i=0;i<3;i++)
		{
			tabP[i]=0;
			for(k=0;k<7;k++)
				MatV[i][k]=0;
		}
}


void vendre(int matV[][7], gateau tabG[], int type, int jour, int *tg, float tabP[])
{
	int i,pos,prix;
	trouver(tabG,*tg,type,&pos);
	prix=calculerPrix(tabG[pos]);
	tabP[jour]=(tabP[jour]+prix);
	matV[type][jour]++;
	for(i=pos;i<(*tg)-1;i++)
	{
		tabG[i]=tabG[i+1];
	}
	(*tg)--;
}
void afficherRecette(int matV[][7],int jour,float tabP[])
{
	printf("jour : %d chiffre d'affaire : %f\n",jour,tabP[jour]);
	printf("gateau vendue type chocolat : %d \n",matV[0][jour] );
	printf("gateau vendue type nougatine : %d \n",matV[1][jour] );
	printf("gateau vendue type pistache : %d \n",matV[2][jour] );
}
