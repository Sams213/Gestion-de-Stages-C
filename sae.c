#include "sae.h"

int identifier(int L[], int nb, int element)
// identifier l'etudiant dans les données
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

void compteurStageEtu(int numEtu[], int compteur[], int etu, int nb)
{
    int i;
    i = identifier(numEtu, nb, etu);
    if (i != -1)
        compteur[i] += 1;
    else
        printf("L'étudiant n'est pas reconnu /// compteurStageEtu");
}

int rechercheL(int L[], int element, int nb)
{
    int i;
    for (i=0; i < nb; i++)
    {
        if (L[i] > element)
            return i;
    }
    return i;
}

void decalerAGaucheLL(int (*L)[4], int col, int index)
{
    if (index != -1)
    {
        for (int i = index; i < L[col][0]; i++)
        {
            L[col][i] = L[col][i + 1];
        }
        L[col][0] -= 1;
        L[col][L[col][0]] = 0;
    }
}

void decalerADroiteL(int L[], int *nb, int index, int element)
{
    if (index != -1)
    {
        for (int i = *nb; i > index; i--)
        {
            L[i] = L[i-1];
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
            memcpy(stages[i], stages[i-1], 4 * sizeof(int));
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

int remplirstage(int refStage[], int (*stageNumEtuCandid)[4], boolean stagePourvu[], int dpt[], int tmax, int numEtu[], int nbEtu, int compteur[])
{
    int ref, i = 0, dp, nb = 0, inter, nbstage, etu1, etu2, etu3;
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
                fscanf(stage, "%d", &etu1);
                stageNumEtuCandid[i][0] = 1;
                stageNumEtuCandid[i][1] = etu1;
                compteurStageEtu(numEtu, compteur, etu1, nbEtu);
            }
            if (nbstage == 2)
            {
                fscanf(stage, "%d%d", &etu1, &etu2);
                stageNumEtuCandid[i][0] = 2;
                stageNumEtuCandid[i][1] = etu1;
                compteurStageEtu(numEtu, compteur, etu1, nbEtu);
                stageNumEtuCandid[i][2] = etu2;
                compteurStageEtu(numEtu, compteur, etu2, nbEtu);
            }
            if (nbstage == 3)
            {
                fscanf(stage, "%d%d%d", &etu1, &etu2, &etu3);
                stageNumEtuCandid[i][0] = 3;
                stageNumEtuCandid[i][1] = etu1;
                compteurStageEtu(numEtu, compteur, etu1, nbEtu);
                stageNumEtuCandid[i][2] = etu2;
                compteurStageEtu(numEtu, compteur, etu2, nbEtu);
                stageNumEtuCandid[i][3] = etu3;
                compteurStageEtu(numEtu, compteur, etu3, nbEtu);
            }
        }
        fscanf(stage, "%d%d", &ref, &dp);
        i++;
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

void stageDispo(boolean stagePourvu[], int refStages[], int (*stages)[4], int nbstage)
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
    while (i == -1)
    {
        printf("L'étudiant n'est pas reconnu, veuillez réessayer avec un numéro d'étudiant correct.\nTapez -2 pour sortir.");
        scanf("%d", &etu);
        i = identifier(numEtu, nb, etu);
    }

    if (i == -2)
    {
        return;
    }
    printf("A quel stage voulez vous l'affecter : ");
    scanf("%d", &stage);
    int s;
    s = identifier(refstage, nb, stage);
    while (s == -1)
    {
        printf("Le stage n'est pas reconnu, veuillez réessayer avec un numéro de stage correct.\nTapez -2 pour sortir. Stage: ");
        scanf("%d",&stage);
        s = identifier(refstage, nb, stage);
    }
    if (i == -2)
    {
        return;
    }
    refStageEtu[i] = stage;
    stages[s][0] = -1;
    stagePourvu[s] = true;
    for (int j = 0; j < nb; j++)
    {
        int pos = identifier(stages[j], stages[j][0], etu);
        if (pos != -1)
        {
            decalerAGaucheLL(stages, j, pos);
        }
    }
}

float moyenne(float n1, float n2, float n3)
{
    return (n1 * 2 + n2 + n3) / 4;
}

void noteEtu(int numEtu[], int nb, float noteEtu[])
{
    int etu, i;
    float note1, note2, note3, m;
    printf("A quel étudiant voulez-vous affecter un stage : ");
    scanf("%d", &etu);
    i = identifier(numEtu, nb, etu);
    while (i == -1)
    {
        printf("L'étudiant n'est pas reconnu, veuillez réessayer avec un numéro d'étudiant correct.\nTapez -2 pour sortir.");
        scanf("%d", &etu);
        i = identifier(numEtu, nb, etu);
    }
    if (i == -2)
    {
        return;
    }
    printf("Quel est la note d'entreprise de l'étudiant ?");
    scanf("%f", &note1);
    printf("Quel est la note du rapport de l'étudiant ?");
    scanf("%f", &note2);
    printf("Quel est la note de soutenance de l'étudiant?");
    scanf("%f", &note3);

    m = moyenne(note1, note2, note3);
    noteEtu[i]=m;
}

int IdentifierPersonne(void){
    int m;
    printf("Tapez 1 si vous etes etudiant et 2 si vous etes responsable");
    scanf("%d",&m);
    while(m<1 || m>2){
        printf("Erreur. Retapez 1 si vous etes etudiant et 2 si vous etes responsable.");
        scanf("%d",&m);
    }
    return m;
}

/*
int DemandeAffichageRespo(void){
    int c,m,etu;
    m=IdentifierPersonne;
    if(m==2){
        printf("Que voulez vous afficher? \n");
        printf("1. Tous les stages pourvus\n");
        printf("2. tous les stages non pouvus\n");
        printf("3. Liste des etudiants n'ayant pas de stage\n");
        printf("4. Informations concernant le stage donne\n");
        printf("5. Rechercher un stage\n");
        scanf("%d",&c);
        while(c>5 || c<1){
            printf("Choix incorrecte. Retapez votre choix");
            scanf("%d",&c);
        }
        return c;
    }
}

int DemandeAffichageEtudiant(void){
    int c,m,etu;
    m=IdentifierPersonne();
    if(m==1){
        printf("Tapez votre numero etudiant: ");
        scanf("%d",&etu);
        printf("Que voulez vous afficher? \n");
        printf("1. Tous les stags non pourvus\n");
        printf("2. Toutes vos candidatures ou votre stage affecter si vous avez un stage\n");
        printf("3. Afficher des stages selon un nombre de departement");
        scanf("%d", &c);
        while(c>3){
            printf("Choix incorrecte. Retapez votre choix");
            scanf("%d",&c);
        }
        return c;
    }
}

void affichage(void){
    int c;
    c=DemandeAffichage();

}
*/