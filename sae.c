#include "sae.h"

int rechercheL(int L[], int element, int nb)
{
    int i = 0;
    for (i; i < nb; i++)
    {
        if (L[i] > element)
            return i;
    }
    return -1;
}

void decalerADroiteL(int L[], int *nb, int index, int element)
{
    if (index != -1)
    {
        for (int i = nb; i > index; i--)
        {
            L[i + 1] = L[i];
        }
        L[index] = element;
        (*nb) += 1;
    }
    else
    {
        L[*nb] = element;
        (*nb) += 1;
    }
}

void decalerADroiteLL(int (*stages)[4], int index, int nb)
{
    if (index != -1)
    {
        for (int i = nb; i > index; i--)
        {
            memcpy(stages[i + 1], stages[i], 4 * sizeof(int));
        }
    }
    else
        ;
}

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

int remplirstage(int refStage[], int (*stageNumEtuCandid)[4], boolean stagePourvu[], int dpt[], int tmax, int numEtu[], int tmaxNumEtu, int compteur[])
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

        int pos = rechercheL(refStage, ref, nb);
        decalerADroiteL(refStage, &nb, pos, ref);
        decalerADroiteLL(stageNumEtuCandid, pos, nb);

        dpt[i] = dp;

        fscanf(stage, "%d", &inter);

        if (inter == 1)
        {
            stagePourvu[i] = true;
            stageNumEtuCandid[i][0] = -1;
        }

        if (inter == 0)
        {
            stagePourvu[i] = false;
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

int identifier(int L[], int nb, int element)
// identifier l'etudiant dans les donnes
{
    int i = 0;
    while (i < nb)
    {
        if (L[i] == element)
            return i;

        if (L[i + 1] > element)
        {
            return -1;
        }

        i++;
    }
    return -1;
}

void compteurStageEtu(int numEtu[], int compteur[], int etu, int tmax)
{
    int i;
    i = identifier(numEtu, tmax, etu);
    if (i != -1)
        compteur[i] += 1;
    else
        printf("L'étudiant n'est pas reconnu /// compteurStageEtu");
}

int checkEtu3(int numEtu[], int compteur[], int tmax, int etu)
{
    int i = 0;
    i = identifier(numEtu, tmax, etu);
    if (compteur[i] < 3)
    {
        return 0;
    }
    else
        return 1;
}

int stageDispo(boolean stagePourvu[], int refStages[], int (*stages)[4], int nbstage)
{
    int i = 0;
    while (i < nbstage)
    {
        if (stagePourvu[i] == false && stages[i][0] < 3)
            printf("%d\t", refStages[i]);
    }
}

void affecterStage(int refstage[], int refStageEtu[], int numEtu[], int nb, int (*stages)[4], boolean stagePourvu[]) // affecte un stage a un etudiant
{
    int etu, stage, i;
    printf("A quel étudiant voulez-vous affecter un stage : ");
    scanf("%d", &etu);
    i = identifier(numEtu, nb, etu);
    while (i = -1)
    {
        printf("L'étudiant n'est pas reconnu, veuillez réessayer avec un numéro d'étudiant correct.\nTapez -1 pour sortir.");
        scanf("%d", &etu);
        i = identifier(numEtu, nb, etu);
    }

    if (i == -1)
    {
        printf("L'étudiant n'est pas reconnu, veuillez réessayer avec un numéro d'étudiant correct. ");
        return;
    }
    printf("A quel stage voulez vous l'affecter : ");
    scanf("%d", &stage);
    int s = identifier(refstage, nb, stage);
    if (i == -1)
    {
        printf("Le stage n'est pas reconnu, veuillez réessayer avec un numéro de stage correct. ");
        return;
    }
    refStageEtu[i] = stage;
    stages[s][0] = -1;
    stagePourvu[s] = true;
}