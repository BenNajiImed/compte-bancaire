#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 100
#include "comte bancaire.h"
int main()
{
     int choix;
    client tab_client[Max];
    int taille_tab=0;
    int id;
    int recherche=-1;

    FILE *FICHIER;

    FICHIER=fopen("comptes","r");
    if (!FICHIER)
    {
        printf("\nERREUR: impossible d'ouvrir le fichier \n");
        exit(-1);
    }
    while(!feof(FICHIER))
     {
        client c;
            fscanf(FICHIER,"%d %s %s %s %d %d %d %f ", &c.num_compte,c.titulaire,c.Ncin,c.adresse,&c.date_ouverture.jj,&c.date_ouverture.mois,&c.date_ouverture.annee,&c.solde);
            tab_client[taille_tab]=c;
            taille_tab++;
     }
    fclose(FICHIER);


    while (1)
    {
        printf ("\n\n");
        printf("1. saisir des clients \n");
        printf("2. afficher un client \n");
        printf("3. lister les clients \n");
        printf("4. rechercher un client \n");
        printf("5. modifier un client \n");
        printf("6. supprimer un client \n");
        printf("7. ajouter un client \n");
        printf("0. quitter \n");
        printf("\n\n");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1:
            saisir_tab_client(tab_client,&taille_tab);
            break;
        case 2:
            {
              printf("taper le client que vous voulez afficher");
              scanf("%d",&id);
              recherche=recherche_client(tab_client,taille_tab,id);
              if(recherche==-1)
              printf("client inexistant");
              else
                 affiche_client(tab_client[recherche]);
            }break;
        case 3:
            {
              affiche_tab_client(tab_client,taille_tab);
              printf("\n");
            }break;
        case 4:
            {
                printf("taper le client que vous voulez rechercher");
                scanf("%d",&id);
                recherche=recherche_client(tab_client,taille_tab,id);
                if (recherche==-1)
                    printf("client inexistant");
                else
                    printf("ce client existe a l'indice : %d", recherche+1);

            }break;
        case 5:
            {
                printf("taper le client que vous voulez modifier");
                scanf("%d",&id);
                modifier_client(tab_client,taille_tab,id);
            }break;
        case 6:
            {
                printf("taper le client que vous voulez supprimer");
                scanf("%d",&id);
                supprimer_client(tab_client,&taille_tab,id);
            }break;
        case 7:
            {
                ajouter_client(tab_client,&taille_tab);
            }break;

        case 0:
            FICHIER=fopen("comptes","w");
            if (!FICHIER)
            {
                printf("\nERREUR: impossible d'ouvrir le fichier \n");
                exit(-1);
            }
            int j;
            for(j=0;j<taille_tab;j++)
            {
                fprintf(FICHIER,"%d %s %s %s %d %d %d %f \n", tab_client[j].num_compte,tab_client[j].titulaire,tab_client[j].Ncin,tab_client[j].adresse,tab_client[j].date_ouverture.jj,tab_client[j].date_ouverture.mois,tab_client[j].date_ouverture.annee,tab_client[j].solde);
            }
            fclose(FICHIER);
            exit(0);
            default: printf("erreur de saisie\n\n");
        }

    }
}



