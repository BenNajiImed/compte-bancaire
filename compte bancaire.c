#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comte bancaire.h"

int chaine_alpha (char chaine[50])
{
    int i=0;
    while(chaine[i]!='\0')
    {
        if((chaine[i]>='A' && chaine[i]<='Z') || (chaine[i]>='a' && chaine[i]<='z') || (chaine[i]=='\n') || (chaine[i]==' '))
            i++;
        else return 0;
    }
    return 1;
}

int chaine_numerique(char chaine[10])
{
    int i=0;
    while(chaine[i]!='\0')
    {
        if((chaine[i]>='0' && chaine[i]<='9') || (chaine[i]=='\n'))
            i++;
        else return 0;
    }
    return 1;
}

client saisir_client()
{
    client c ;
    do
    {
        printf("\n Taper le numero du compte \n");
        scanf("%d",&c.num_compte);
        if(c.num_compte<0)
            printf("\n il y a eu une erreur dans la saisie \n");
    }while(c.num_compte<0);

    do
      {
       printf("\n Taper le nom et le prenom du titulaire du compte \n");
       fflush(stdin);
       fgets(c.titulaire,50,stdin);
       if(chaine_alpha(c.titulaire)==0)
        printf("\n il y a eu une erreur dans la saisie \n");
      }while(chaine_alpha(c.titulaire)==0);

   do
    {
        printf("\n Taper le Ncin \n");
        fflush(stdin);
        fgets(c.Ncin,10,stdin);
        if(chaine_numerique(c.Ncin)==0)
        printf("\n il y a eu une erreur dans la saisie \n");
    }while(chaine_numerique(c.Ncin)==0);

    printf("\n Taper l'adresse du titulaire \n");
    scanf("%s",c.adresse);
    printf("\n Taper la date d'ouverture du compte \n");
    do
     {
         printf("\n Taper le jour \n");
         scanf("%d",&(c.date_ouverture.jj));
         if(c.date_ouverture.jj>31 || c.date_ouverture.jj<1)
            printf("il y a eu une erreur de saisie");
     }while(c.date_ouverture.jj>31 || c.date_ouverture.jj<1 );

   do
    {    printf(" \n Taper le mois \n");
         scanf("%d",&((c.date_ouverture).mois));
         if(c.date_ouverture.mois>12 || c.date_ouverture.mois<1)
            printf("il y a eu une erreur de saisie");
    }while(c.date_ouverture.mois>12 || c.date_ouverture.mois<1);

   do
    {
        printf(" \n Taper l'annee \n");
        scanf("%d",&((c.date_ouverture).annee));
        if(c.date_ouverture.annee>2021 || c.date_ouverture.annee<2000)
            printf("il y a eu une erreur de saisie");
    }while(c.date_ouverture.annee>2021 || c.date_ouverture.annee<2000);

    printf("\n Taper le solde du compte en dt \n");
    scanf("%f",&c.solde);

  return c;
}


void affiche_client(client c)
{

    printf("\n ************ \n Numero du compte %d ",c.num_compte);
    printf("\n Titulaire du compte %s",c.titulaire);
    printf("\n Ncin %s",c.Ncin);
    printf("\n Adresse %s",c.adresse);
    printf("\n Date d'ouverture du compte %d/%d/%d ",(c.date_ouverture.jj),(c.date_ouverture.mois),(c.date_ouverture.annee));
    printf("\n Solde %f",c.solde);

}


int unique(client tab[],int n,int k)
{ int i=0, test=0;
    while((i<n) && (test==0))
    {
       if((tab[i].num_compte==k))
        test=1;
      else i++;
    }

  return test;
}


void saisir_tab_client(client tab[],int* n)
{
     client c; int i=*n;
  char rep[3]; int test;
  do
  { test=0;
         do
          {
            c=saisir_client();
            test = unique(tab,i,c.num_compte);
            if (test==1) printf("\n le compte est deja existant .. entez un nouveau compte\n");
          }while(test==1);
      tab[i]=c;
      i++;
      printf("voulez vous ajouter un compte bancaire oui/non\n");
      scanf("%s",rep);
  }while(!strcmp(rep,"oui"));
  *n=i;
}

void affiche_tab_client(client tab[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        affiche_client(tab[i]);
    }
}

int recherche_client(client tab[] , int n , int id)
{
    int i;
    for (i=0;i<n;i++)
    {
        if (tab[i].num_compte==id)
            return i;
    }
    return -1 ;
}

void modifier_client(client tab[], int n, int id)
{
    int test,choix ,nvnum,nj,nm,na; char nvtit[50],nvad[50],nn[10];
    int rech=recherche_client(tab,n,id);
    float nvsol=0;
    if(rech==-1)
        printf("le client que vous voulez modifier n'existe pas!");
    else
    {
        printf("que vouleez-vous modifier ?\n");
        printf("1. le numero du compte \n");
        printf("2. le titulaire du compte \n");
        printf("3. le Ncin \n");
        printf("4. l'adresse \n");
        printf("5. la date d'ouverture \n");
        printf("6. le solde \n");
        printf("0. annuler \n");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1 :
            { do
                {printf ("taper le nouveau numero du compte");
                 scanf("%d",&nvnum);
                 test = unique(tab,n,nvnum);
                 if (test==1) printf("\n le compte est deja existant .. entez un nouveau compte\n");
            }while(test==1);
                tab[rech].num_compte=nvnum;
            }break ;
        case 2 :
            {do
                {printf("taper le nouveau titulaire du compte");
                fflush(stdin);
                fgets(nvtit,50,stdin);
                if(chaine_alpha(nvtit)==0)
                    printf("\n il y a eu une erreur dans la saisie \n");
                }while(chaine_alpha(nvtit)==0);
                strcpy(tab[rech].titulaire,nvtit);
            }break;
        case 3:
            {do
                {printf("taper le nouveau Ncin");
                 fgets(nn,10,stdin);
                 if(chaine_numerique(nn)==0)
                   printf("\n il y a eu une erreur dans la saisie \n");
            }while(chaine_numerique(nn)==0);
                 strcpy(tab[rech].Ncin,nn);
            }break;
        case 4:
            {
                printf("taper la nouvelle adresse");
                scanf("%s",nvad);
                strcpy(tab[rech].adresse,nvad);
            }break;
        case 5:
            {
                printf("taper la nouvelle date d'ouverture");
                do
                  {printf("\n Taper le nouveau jour \n");
                   scanf("%d",&nj);
                   if(nj>31 || nj<1)
                      printf("il y a eu une erreur de saisie");
                  }while(nj>31 || nj<1);
                do
                  {printf(" \n Taper le nouveau mois \n");
                   scanf("%d",&nm);
                   if(nm>12 || nm<1)
                       printf("il y a eu une erreur de saisie");
                  }while(nm>12 ||nm<1);
                 do
                   {printf(" \n Taper la nouvelle annee \n");
                    scanf("%d",&na);
                    if(na>2021 || na<2000)
                        printf("il y a eu une erreur de saisie");
                   }while(na>2021 ||na<2000);
                tab[rech].date_ouverture.jj=nj;
                tab[rech].date_ouverture.mois=nm;
                tab[rech].date_ouverture.annee=na;
            }break;
        case 6:
            {
                printf("taper le nouveau solde");
                scanf("%f",&nvsol);
                tab[rech].solde=nvsol;
            }break;

            default:printf("choix invalid !");


        }
    }
}

void supprimer_client(client tab[],int *n,int id)
{
    int i;
    int rech=recherche_client(tab,*n,id);
    if(rech==-1)
        printf("le client que vous voulez supprimer n'existe pas !");
    else
    {
        for(i=rech;i<*n;i++)
        {
            tab[i]=tab[i+1];
        }
        (*n)--;
    }
}

void ajouter_client(client tab[], int *n)

{int test;
 client e;
  do
    { e=saisir_client();
      test=unique(tab,*n,e.num_compte);
      if(test==1)
        printf("\n le compte est deja existant .. entez un nouveau compte\n");
    }while(test==1);
    tab[*n]=e;
    (*n)++;
}
