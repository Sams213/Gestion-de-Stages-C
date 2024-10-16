#include "sae.h"

void remplirtableau(int etu[], int stage[])
{   
    int i;
    FILE *flot, *stage;
    flot=fopen("etudiants.txt", "r");
    if (flot==NULL)
    {
        printf("Probleme d'ouverture de fichier");
        return -1;
    }
    stage=fopen("stage.txt","w");
    if (stage==NULL)
    {
        printf("Probleme d'ouverture de fichier");
        return -1;
    }
    while ()
    {
        
    }
    
}