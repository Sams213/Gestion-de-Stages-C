#include "sae.h"

void rempliretu(int numetu[], int refetu[], float notes[])
//numetu: numero etudiant
//refetu: reference de stage
//notes: notes finale
{   
    int i,a,b;
    float n;
    FILE *flot;
    flot=fopen("etudiants.txt", "w");
    if (flot==NULL)
    {
        printf("Probleme d'ouverture de fichier");
        return -1;
    }
    fscanf(flot,"%d %d %f",&a,&b,&n);
    while (!feof)
    {
        printf("tableau rempli");
    }   
}

void remplirstage(int refstage[], int dp[])
{
    FILE *stage;
    stage=fopen("stage.txt","w");
    if (stage==NULL)
    {
        printf("Probleme d'ouverture de fichier");
        return -1;
    }

}