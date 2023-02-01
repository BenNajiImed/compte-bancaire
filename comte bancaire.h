#ifndef COPMTE_BANCAIRE
#define COMPTE_BANCAIRE
typedef struct date
{
    int jj;
	int mois;
	int annee;
}date;
typedef struct client
{
    int num_compte;
    char titulaire[50];
    char Ncin[10];
    char adresse[50];
    date date_ouverture;
    float solde;
}client  ;
int chaine_alpha(char* chaine);
int chaine_numerique(char chaine[10]);
client saisir_client();
void affiche_client(client c);
void saisir_tab_client(client tab[],int* n);
void affiche_tab_client(client tab[],int n);
int unique(client tab[] , int n , int k);
int recherche_client(client tab[] , int n , int id);
void modifier_client(client tab[], int n, int id);
void supprimer_client(client tab[],int *n,int id);
void ajouter_client(client tab[], int *n);
#endif
