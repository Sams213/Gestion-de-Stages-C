#include "sae.h"

void printListI(int L[], int nb)
{
    int i;
    for(i=0; i<nb; i++)
    {
        printf("%d\t", L[i]);
    }
    printf("\n");
}

void printListF(float notes[], int nb)
{
    int i;
    for(i=0; i<nb; i++)
    {
        printf("%.2f\t",notes[i]);
    }
    printf("\n");
}

void printListLL(int (*L)[4], int nb)
{
    int i;
    for(i=0; i<nb; i++)
    {
        for(int j=1; j<=L[i][0]; j++)
        {
            printf("%d\t",L[i][j]);
        }
        printf("\n");
    }
}

void Affichage(void)
{

}

int rempliretu(int numEtu[], int refStageEtu[], float notes[], int tmax) 
{
    FILE *flot;
    int i=0, num, ref, nb=0;
    float note;
    flot=fopen("etudiants.txt", "r");
    if (flot==NULL)
    {
        printf("Probleme d'ouverture de fichier");
        fclose(flot);
        return -2;
    }
    fscanf(flot,"%d%d%f",&num,&ref,&note);
    while (!feof(flot))
    {
        if (nb==tmax) 
        {
            printf("Tableau trop petit.");
            fclose(flot); 
            return -1;
        }
        numEtu[i]=num;
        refStageEtu[i]=ref;
        notes[i]=note;
        nb+=1;
        i+=1;
        fscanf(flot,"%d%d%f",&num,&ref,&note);
    }
    fclose(flot);
    return nb;
}


int remplirstage(int refStage[], int (*stageNumEtuCandid)[4], int stagePourvu[], int dpt[],int tmax)
{
    int ref, i, dp, nb, inter, nbstage, stage1, stage2, stage3;
    FILE *stage;
    stage=fopen("stage.txt","r");
    if (stage==NULL)
    {
        printf("Probleme d'ouverture de fichier");
        fclose(stage);
        return -2;
    }
    fscanf(stage,"%d%d",&ref,&dp);
    while(!feof(stage)){
        if(nb==tmax) {
            printf("Tableau trop petit.\n");
            fclose(stage);
            return -2;
        }

        refStage[i]=ref;
        dpt[i]=dp;

        fscanf(stage,"%d", &inter);

        stagePourvu[i]=inter;

        if (inter==0) 
            {
                fscanf(stage, "%d", &nbstage);
            }

        else {
            
        }

        if (nbstage==1)
            fscanf(stage,"%d", &stage1);
            stageNumEtuCandid[i][0]=1;
            stageNumEtuCandid[i][1]=stage1;

        if (nbstage==2){
                fscanf(stage, "%d%d", &stage1, &stage2);
                stageNumEtuCandid[i][0]=2;
                stageNumEtuCandid[i][1]=stage1;
                stageNumEtuCandid[i][2]=stage2;
            }
        if (nbstage==3){
                fscanf(stage, "%d%d%d", &stage1, &stage2, &stage3);
                stageNumEtuCandid[i][0]=3;
                stageNumEtuCandid[i][1]=stage1;
                stageNumEtuCandid[i][2]=stage2;
                stageNumEtuCandid[i][3]=stage3;
            }
        refStage[i]=ref;
        dpt[i]=dp;
        }
        
        fscanf(stage,"%d",&ref);
        refStage[i]=ref;
        nb++;
        i++;
    fclose(stage);
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