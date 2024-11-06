#include "sae.h"

void printListI(int L[], int nb)
{
    int i;
    for (i = 0; i < nb; i++)
    {
        printf("%d\t", L[i]);
    }
    printf("\n");
}

void printListF(float notes[], int nb)
{
    int i;
    for (i = 0; i < nb; i++)
    {
        printf("%.2f\t", notes[i]);
    }
    printf("\n");
}

void printListLL(int (*L)[4], int nb)
{
    int i;
    for (i = 0; i < nb; i++)
    {
        if (L[i][0] == -1)
            printf("%d Pourvu", L[i][1]);

        for (int j = 1; j <= L[i][0]; j++)
        {
            printf("%d\t", L[i][j]);
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
    int i = 0, num, ref, nb = 0;
    float note;
    flot = fopen("etudiants.txt", "r");
    if (flot == NULL)
    {
        printf("Probleme d'ouverture de fichier");
        return -2;
    }
    fscanf(flot, "%d%d%f", &num, &ref, &note);
    while (!feof(flot))
    {
        if (nb == tmax)
        {
            printf("Tableau trop petit.");
            fclose(flot);
            return -1;
        }
        numEtu[i] = num;
        refStageEtu[i] = ref;
        notes[i] = note;
        nb += 1;
        i += 1;
        fscanf(flot, "%d%d%f", &num, &ref, &note);
    }
    fclose(flot);
    return nb;
}

int remplirstage(int refStage[], int (*stageNumEtuCandid)[4], int stagePourvu[], int dpt[], int tmax, int numEtu[], int tmaxNumEtu, int compteur[])
{
    int ref, i = 0, dp, nb = 0, inter, nbstage, stage1, stage2, stage3;
    FILE *stage;
    stage = fopen("stage.txt", "r");
    if (stage == NULL)
    {
        printf("Probleme d'ouverture de fichier");
        return -2;
    }
    fscanf(stage, "%d%d", &ref, &dp);
    while (!feof(stage))
    {
        if (nb == tmax)
        {
            printf("Tableau trop petit.\n");
            fclose(stage);
            return -2;
        }

        refStage[i] = ref;
        dpt[i] = dp;

        fscanf(stage, "%d", &inter);

        stagePourvu[i] = inter;

        if (inter == 0)
        {
            fscanf(stage, "%d", &nbstage);
            if (nbstage == 1)
            {
                fscanf(stage, "%d", &stage1);
                stageNumEtuCandid[i][0] = 1;
                stageNumEtuCandid[i][1] = stage1;
                compteurStageEtu(numEtu, compteur, stage1, tmaxNumEtu);
            }
            if (nbstage == 2)
            {
                fscanf(stage, "%d%d", &stage1, &stage2);
                stageNumEtuCandid[i][0] = 2;
                stageNumEtuCandid[i][1] = stage1;
                compteurStageEtu(numEtu, compteur, stage1, tmaxNumEtu);
                stageNumEtuCandid[i][2] = stage2;
                compteurStageEtu(numEtu, compteur, stage2, tmaxNumEtu);
            }
            if (nbstage == 3)
            {
                fscanf(stage, "%d%d%d", &stage1, &stage2, &stage3);
                stageNumEtuCandid[i][0] = 3;
                stageNumEtuCandid[i][1] = stage1;
                compteurStageEtu(numEtu, compteur, stage1, tmaxNumEtu);
                stageNumEtuCandid[i][2] = stage2;
                compteurStageEtu(numEtu, compteur, stage2, tmaxNumEtu);
                stageNumEtuCandid[i][3] = stage3;
                compteurStageEtu(numEtu, compteur, stage3, tmaxNumEtu);
            }
        }

        else /* inter=1 */
        {
            stageNumEtuCandid[i][0] = -1;
        }
        fscanf(stage, "%d%d", &ref, &dp);
        i++;
        nb++;
    }
    fclose(stage);
    return nb;
}

int saisirEtu(void)
{
    int etu;
    printf("numero etudiant: ");
    scanf("%d", &etu);
    return etu;
}

int identifierEtudiant(int numEtu[], int tmax, int etu)
// identifier l'etudiant dans les donnes
{
    int i = 0;
    while (i < tmax)
    {
        if (numEtu[i] == etu)
            return i;

        if (numEtu[i + 1] > etu)
        {
            printf("L'etudiant n'est pas reconnu!");
            return -1;
        }

        i++;
    }
    printf("L'etudiant n'est pas reconnu!");
    return -1;
}

void compteurStageEtu(int numEtu[], int compteur[], int etu, int tmax)
{
    int i;
    i = identifierEtudiant(numEtu, tmax, etu);
    if (i != -1)
        compteur[i] += 1;
    else
        printf("L'étudiant n'est pas reconnu //// compteurStageEtu");
}

int checkEtu3(int numEtu[], int compteur[], int tmax, int etu)
{
    int i = 0;
    i = identifierEtudiant(numEtu, tmax, etu);
    if (compteur[i] < 3)
    {
        return 0;
    }
    else
        return 1;
}

int stageDispo(int stagePourvu[], int refStages[], int (*stages)[4], int nbstage)
{
    int i = 0;
    while (i < nbstage)
    {
        if (stagePourvu[i] == 0)
            printf("%d", stages[i]);
        if (stages[i][0]!=3)
            printf(refStages[i]);
    }
}

void afecterStage(int etu) //affecte un stage a un etudiant
{

}

void effacerStage(int refStage[], int stagePourvu[]) //va mettre 1 parce stage devient pourvu et efface les etudiants
{
    
}

void effacerEtudiant(int etu) //efface les candidatures de l'etu qui a recu un stage
{

}