#include <stdio.h>
#include <stdlib.h>
#include"gateauv2.h"
#include <windows.h>



int menu()
{
	int choix;
	printf("                         ---------------------------------\n");
	printf("                        |    Tapez Le Numero D'option     |\n");
	printf("                         ---------------------------------\n\n");
	printf("						-1-Ajouter Gateau\n");
	printf("						-2-Afficher les Gateaux\n");
	printf("						-3-Position gateau \n" );
	printf("						-4-Initialiser matrice vente \n");
	printf("						-5-Vendre gateaux\n");
	printf("						-6-Affichage Recette\n");
	printf("						 7-EXIT\n" );

	printf("saisir votre choix : " );
	scanf("%d",&choix);
    return choix;

}
int main()
{
	gateau g;
	gateau tabG[20];
	int tg;
	tg=0;
	int type;
	int pos;
	pos=-1;
	int matV[3][7];
	float tabP[20];
	int jour;
	int choice;


do {

    	choice=menu();


    	switch(choice)

    	{
    		case 1 :
    		saisir (&g);
    		ajouterGateau(tabG,g,&tg);
    		  printf("\n\n\nTaper n'importe quelle key pour revenir au menu ");
			    system("pause > null");
			    system("clear||@cls");

    		break;


    			case 2 :
    			afficher(tabG,tg);
    			printf("\n\n\nTaper n'importe quelle key pour revenir au menu ");
			    system("pause > null");
			    system("clear||@cls");

    			break;

    					case 3:

    					printf("Tapez le type du gateaux a chercher \n");
    					scanf("%d",&type);
    					trouver (tabG,tg,type,&pos);
                        printf(" POS: %d \n",pos+1);

    					break;

    						case 4:
    						initialiser(matV,tabG,type,jour,&tg,tabP);

    						break;

    							case 5:
                                initialiser(matV,tabG,type,jour,&tg,tabP);
    							printf("tapez le type du gateau a vendre\n" );
    							scanf("%d",&type);
                                printf("donner le jour \n");
                                scanf("%d",&jour);
    							vendre(matV,tabG,type,jour,&tg,tabP);


    							break;

    								case 6:
    								printf("Jour de la recette a visionner : \n");
    								scanf("%d",&jour);
    								afficherRecette(matV,jour,tabP);

    								break;


    	}
    }while(choice !=7);



 

printf("\n\n\n\n                                                Developed By\n\n");
Sleep(1000);
printf("                                               M");
Sleep(300);
printf("e");
Sleep(300);
printf("h");
Sleep(300);
printf("d");
Sleep(300);
printf("i");

Sleep(300);
printf("  ");
Sleep(300);
printf("B");
Sleep(300);
printf("e");
Sleep(300);
printf("h");
Sleep(300);
printf("i");
Sleep(300);
printf("r");
Sleep(300);
printf("a\n\n\n");
Sleep(300);
printf("                                   appuyer sur une  toucher pour Quitter\n\n\n");
Sleep(1000);
printf("                                                    .");
Sleep(500);
printf(".");
Sleep(500);
printf(".");

system("pause>null");
system("@cls||clear");

return 0;
}
