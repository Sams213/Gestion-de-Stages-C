#include "sae.h"

void Affichage(void)
{

}

int rempliretu(int numEtu[], int refStageEtu[], float notes[], int tmax) 
{
    int i=0, num, ref, nb=0;
    float note;
    FILE *flot;
    flot=fopen("etudiants.txt", "r");
    if (flot==NULL)
    {
        printf("Probleme d'ouverture de fichier");
        return -2;
    }
    fscanf(flot,"%d%d%f",&num,&ref,&note);
    while (!feof)
    {
        if (nb==tmax) {printf("Tableau trop petit."); return -1;}
        numEtu[i]=num;
        refStageEtu[i]=ref;
        notes[i]=note;
        nb+=1;
        i+=1;
    }
    return nb;
}


int remplirstage(int refStage[], int stageNumEtuCandid[], int stagePourvu[], int dpt[],int tmax)
{
    int ref, dpt, i, dp, nb, inter, nbstage, stage1, stage2, stage3;
    FILE *stage;
    stage=fopen("stage.txt","r");
    if (stage==NULL)
    {
        printf("Probleme d'ouverture de fichier");
        return -2;
    }
    fscanf(stage,"%d%d",&ref,&dpt);
    while(!feof){
        if(nb==tmax) {
            printf("Tableau trop petit.\n");
            return -2;
        }

        refStage[i]=ref;
        dpt[i]=dpt;

        fscanf(stage,"%d", &inter);

        stagePourvu[i]=inter;

        if (inter==0) fscanf(stage, "%d", &nbstage);

        if (nbstage==1)
            fscanf("%d", &stage1);

        if (nbstage==2){
                fscanf(stage, "%d%d", &stage1, &stage2);
                stageNumEtuCandid[i]=0;
            }
        if (nbstage==3){
                fscanf(stage, "%d%d%d", &stage1, &stage2, &stage3);
                stageNumEtuCandid[i]=0;
            }
        refStage[i]=ref;
        dpt[i]=dp;
        }
        
        fscanf(stage,"%d",&ref);
        refStage[i]=ref;
        nb++;
        i++;
        return nb;
}
    
int identifierEtudiant(int numEtu[],int tmax) //identifier l'etudiant 
{
    int etu,i;
    printf("numero etudiant: ");
    scanf("%d",&etu);
    for(i=0;i<tmax;i++){
        if(etu==numEtu[i])
        return i;
    else printf("L'etudiant n'est pas reconnu!");
    }
    return -1;
}

int checkstage(int stageNumEtuCandid[],int numEtu[], int tmax)
{
    int i,etu;
    etu = identifierEtudiant(numEtu,tmax);
}