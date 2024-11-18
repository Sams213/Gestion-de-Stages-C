/**
∗ \file sae.c
∗ \brief Ce fichier regroupe toutes les fonctions du projet SAE_Algo_1.01
∗ \author Jabbour Ghassan et Halilou Sami
∗ \date 17/11/2024
∗
∗ Ce fichier contient l'intégralité des fonctions du projet
*/

#include "sae.h"

int dernierIndice(int L[], int nb)
{
    for (int i = nb - 1; i >= 0; i--)
    {
        if (L[i] != 0)
        {
            return i; // Retourne l'indice du dernier élément non nul
        }
    }
    return -1; // Retourne -1 si tous les éléments sont nuls
}

int indecs(int L[], int nb, int element)
{
    for (int i = 0; i < nb; i++)
    {
        if (L[i] == element)
            return i;
    }
    return -1;
}

int identifier(int L[], int nb, int element)
// identifier l'etudiant dans les donnees
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
}

int rechercheL(int L[], int element, int nb)
{
    int i;
    for (i = 0; i < nb; i++)
    {
        if (L[i] > element)
            return i;
    }
    return i;
}

void decalerAGaucheLL(int (*L)[4], int col, int index)
{
    int i = index;
    if (index != -1)
    {
        for (i; i < L[col][0]; i++)
        {
            L[col][i] = L[col][i + 1];
        }
        L[col][L[col][0]] = 0;
        L[col][0] -= 1;
    }
}

void decalerADroite(boolean L[], int nb, int index, int element)
{
    if (index != -1)
    {
        for (int i = nb; i > index; i--)
        {
            L[i] = L[i - 1];
        }
        L[index] = element;
    }
    else
    {
        L[nb] = element;
    }
}

void decalerADroiteI(int L[], int nb, int index, int element)
{
    if (index != -1)
    {
        for (int i = nb; i > index; i--)
        {
            L[i] = L[i - 1];
        }
        L[index] = element;
    }
    else
    {
        L[nb] = element;
    }
}

void decalerADroiteL(int L[], int *nb, int index, int element)
{
    if (index != -1)
    {
        for (int i = *nb; i > index; i--)
        {
            L[i] = L[i - 1];
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
            memcpy(stages[i], stages[i - 1], 4 * sizeof(int));
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

        else
            for (int j = 0; j < L[i][0] + 1; j++)
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
        fclose(flot);
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

int remplirstage(int refStage[], int (*stageNumEtuCandid)[4], int (*stageEtu)[3], boolean stagePourvu[], int dpt[], int tmax, int numEtu[], int nbEtu, int compteur[], int compteurStages[])
{
    int ref, i = 0, dp, nb = 0, inter, nbstage, etu1, etu2, etu3;
    FILE *stage;
    stage = fopen("stage.txt", "r");
    if (stage == NULL)
    {
        printf("Probleme d'ouverture de fichier");
        fclose(stage);
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

        decalerADroiteI(dpt, nb, pos, dp);

        fscanf(stage, "%d", &inter);

        if (inter == 1)
        {
            decalerADroite(stagePourvu, nb, pos, true);
            stageNumEtuCandid[pos][0] = -1;
        }

        if (inter == 0)
        {
            decalerADroite(stagePourvu, nb, pos, false);
            fscanf(stage, "%d", &nbstage);
            if (nbstage == 1)
            {
                fscanf(stage, "%d", &etu1);
                int i1 = identifier(numEtu, nbEtu, etu1);

                stageNumEtuCandid[pos][0] = 1;

                stageNumEtuCandid[pos][1] = etu1;
                stageEtu[i1][compteur[i1]] = ref;
                compteurStageEtu(numEtu, compteur, etu1, nbEtu);
            }
            if (nbstage == 2)
            {
                fscanf(stage, "%d%d", &etu1, &etu2);
                int i1 = identifier(numEtu, nbEtu, etu1);
                int i2 = identifier(numEtu, nbEtu, etu2);

                stageNumEtuCandid[pos][0] = 2;

                stageNumEtuCandid[pos][1] = etu1;
                stageEtu[i1][compteur[i1]] = ref;
                compteurStageEtu(numEtu, compteur, etu1, nbEtu);

                stageNumEtuCandid[pos][2] = etu2;
                stageEtu[i2][compteur[i2]] = ref;
                compteurStageEtu(numEtu, compteur, etu2, nbEtu);
            }
            if (nbstage == 3)
            {
                fscanf(stage, "%d%d%d", &etu1, &etu2, &etu3);
                int i1 = identifier(numEtu, nbEtu, etu1);
                int i2 = identifier(numEtu, nbEtu, etu2);
                int i3 = identifier(numEtu, nbEtu, etu3);

                stageNumEtuCandid[pos][0] = 3;

                stageNumEtuCandid[pos][1] = etu1;
                stageEtu[i1][compteur[i1]] = ref;
                compteurStageEtu(numEtu, compteur, etu1, nbEtu);

                stageNumEtuCandid[pos][2] = etu2;
                stageEtu[i2][compteur[i2]] = ref;
                compteurStageEtu(numEtu, compteur, etu2, nbEtu);

                stageEtu[i3][compteur[i3]] = ref;
                stageNumEtuCandid[pos][3] = etu3;
                compteurStageEtu(numEtu, compteur, etu3, nbEtu);
            }
            compteurStages[pos] = nbstage;
        }
        fscanf(stage, "%d%d", &ref, &dp);
        i++;
    }
    fclose(stage);
    return nb;
}

void stageDispo(boolean stagePourvu[], int refStages[], int (*stages)[4], int nbstage)
{
    int i = 0;
    printf("\nListe des stages disponibles: \n\n");
    while (i < nbstage)
    {
        if (stagePourvu[i] == false && stages[i][0] < 3)
            printf("%d\t", refStages[i]);
        i++;
    }
}

void affecterStage(int compteur[], int numEtuSelonStage[], int refstage[], int refStageFinalEtu[], int numEtu[], int nbEtu, int nbStage, int (*stages)[4], int (*stageEtu)[3], boolean stagePourvu[]) // affecte un stage a un etudiant
{
    int etu, stage, i, p, s, m, x, z, r;
    printf("A quel etudiant voulez-vous affecter un stage : ");
    scanf("%d", &etu);
    i = identifier(numEtu, nbEtu, etu);
    while (i == -1)
    {
        printf("L'etudiant n'est pas reconnu, veuillez reessayer avec un numero d'etudiant correct.\nTapez -1 pour sortir.");
        scanf("%d", &etu);
        if (etu == -1)
        {
            return;
        }
        i = identifier(numEtu, nbEtu, etu);
    }

    printf("A quel stage voulez vous l'affecter : ");
    scanf("%d", &stage);
    s = identifier(refstage, nbEtu, stage);
    while (s == -1)
    {
        clear();
        printf("\nLe stage n'est pas reconnu, veuillez reessayer avec un numero de stage correct.\nTapez -1 pour sortir. Stage: ");
        scanf("%d", &stage);
        if (stage == -1)
        {
            return;
        }
        s = identifier(refstage, nbStage, stage);
    }
    // printf("%d", etu);
    // printf("index: %d\n", i);
    // printf("compteur: %d\n\n\n", compteur[i]);
    for (p = 0; p < compteur[i]; p++)
    {
        r = identifier(refstage, nbStage, stageEtu[i][p]);
        // printf("stage: %d\n", stageEtu[i][p]);
        // printf("r: %d\n", r);
        z = indecs(stages[r], 4, etu);
        printListI(stages[r], 4);
        // printf("z: %d\n", z);
        decalerAGaucheLL(stages, r, z);
        // printf("\n\n");
        // printListLL(stages, nbStage);
    }
    refStageFinalEtu[i] = stage;
    numEtuSelonStage[s] = etu;
    stages[s][0] = -1;
    stagePourvu[s] = true;
}

float moyenne(float n1, float n2, float n3)
{
    return (n1 * 2 + n2 + n3) / 4;
}

void noteEtu(int numEtu[], int nb, float noteEtu[])
{
    int etu, i;
    float note1, note2, note3, m;
    printf("Quel etudiant voulez vous noter: ");
    scanf("%d", &etu);
    i = identifier(numEtu, nb, etu);
    while (i == -1)
    {
        printf("L'etudiant n'est pas reconnu, veuillez reessayer avec un numero d'etudiant correct.\nTapez -1 pour sortir.");
        scanf("%d", &etu);
        if (etu == -1)
        {
            return;
        }
        i = identifier(numEtu, nb, etu);
    }

    printf("Quel est la note d'entreprise de l'etudiant:\t");
    scanf("%f", &note1);
    printf("Quel est la note du rapport de l'etudiant:\t");
    scanf("%f", &note2);
    printf("Quel est la note de soutenance de l'etudiant:\t");
    scanf("%f", &note3);

    m = moyenne(note1, note2, note3);
    noteEtu[i] = m;
}

int IdentifierPersonne(void)
{
    int m, i;
    char mdpA[20], mdp[20];
    liremdpAdmin(mdpA);
    printf("\t1. Etudiant\t\t2. Responsable\n\nChoix: \t");
    scanf("%d%*c", &m);
    while (m < 1 || m > 2)
    {
        printf("Erreur. Retapez 1 si vous etes etudiant et 2 si vous etes responsable:");
        scanf("%d", &m);
    }

    if (m == 2)
    {
        for (i = 0; i <= 3; i++)
        {
            printf("Entre le mot de passe responsable (0000 par defaut):\t");
            system("stty -echo");
            fgets(mdp, 18, stdin);
            system("stty echo");
            mdp[strlen(mdp) - 1] = '\0';
            if (strcmp(mdp, mdpA) == 0)
                return 2;
            else
            {
                printf("\nMot de passe erronne.\n");
            }
        }
        exit(1);
    }
    return 1;
}

void liremdpAdmin(char mdpAdmin[])
{
    FILE *flot;
    flot = fopen("mdpAdmin.txt", "r");
    if (flot == NULL)
    {
        printf("Error opening file.\n");
        fclose(flot);
        exit(1);
    }
    fgets(mdpAdmin, 18, flot);
    mdpAdmin[strlen(mdpAdmin) - 1] = '\0';
}

void AfficherStagePourvuEtEtudiant(int refStageFinal[], int refEtu[], int nbEtu)
{
    int i = 0;
    printf("Affichage des stages pourvus et des etudiants qui y sont affectes:\n\n");
    printf("Stage:\t\tEtudiant:\n");
    while (i < nbEtu)
    {
        if (refStageFinal[i] != -1)
        {
            printf("%d\t\t", refStageFinal[i]);
            printf("%d\n", refEtu[i]);
        }
        i++;
    }
    printf("\n");
}

void AfficherStageNonPourvu(boolean stagePourvu[], int refStage[], int nbStage)
{
    int i = 0;
    printf("Affichage des stages non-pourvus:\n\n");
    printf("Stage:\n");
    while (i < nbStage)
    {
        if (stagePourvu[i] == false)
        {
            printf("%d\n", refStage[i]);
        }
        i++;
    }
    printf("\n");
}

void AfficherEtudiantSansStage(int refStageFinal[], int numEtu[], int nb)
{
    int i = 0;
    printf("Voici la liste des Etudiants n'ayant pas de stages:\n");
    while (i < nb)
    {
        if (refStageFinal[i] == -1)
            printf("%d\t", numEtu[i]);
        i++;
    }
    printf("\n\n");
}

void AfficherInfoStageInput(int dpt[], int refStage[], int numEtu[], int (*stages)[4], boolean stagePourvu[], int numEtuSelonStagePourvu[], int nbStage)
{
    int stage, s;
    printf("De quel stage voulez vous voir les informations: ");
    scanf("%d", &stage);
    s = identifier(refStage, nbStage, stage);
    while (1)
    {
        while (s == -1)
        {
            clear();
            printf("Le stage n'est pas reconnu, veuillez reessayer avec un numero de stage correct.\n(Tapez -1 pour sortir. )\nStage: ");
            scanf("%d", &stage);
            if (stage == -1)
            {
                return;
            }
            s = identifier(refStage, nbStage, stage);
        }
        printf("\nDepartement:\t%d\n", dpt[s]);
        if (stagePourvu[s] == true)
        {
            {
                printf("Stage Pourvu:\t%s\n", "oui");
                printf("Etudiant affecte:\t%d\n", numEtuSelonStagePourvu[s]);
                printf("");
            }
        }
        else
        {
            printf("Stage Pourvu:\t%s\n", "non");
            printf("Candidats au stage: \t");
            for (int i = 1; i <= stages[s][0]; i++)
                printf("%d\t", stages[s][i]);
            printf("\n");
        }
        printf("\nDe quel stage voulez vous voir les informations (tapez -1 pour sortir) :\t");
        scanf("%d", &stage);
        if (stage == -1)
            return;
        s = identifier(refStage, nbStage, stage);
    }
}

void AfficherInfoStageSansInput(int dpt[], int refStage[], int numEtu[], int (*stages)[4], boolean stagePourvu[], int numEtuSelonStagePourvu[], int nbStage, int s)
{
    printf("Numero du stage: %d", refStage[s]);
    printf("\nDepartement:\t%d\n", dpt[s]);
    if (stagePourvu[s] == true)
    {
        {
            printf("Stage Pourvu:\t\t%s\n", "oui");
            printf("Etudiant affecte:\t%d\n", numEtuSelonStagePourvu[s]);
            printf("");
        }
    }
    else
    {
        printf("Stage Pourvu: \t%s\n", "non");
        printf("Candidats au stage:\t");
        for (int i = 1; i <= stages[s][0]; i++)
            printf("%d\t", stages[s][i]);
        printf("\n\n");
    }
}

void TriEtudiantSelonLeStagePourvu(int refStageFinal[], int refStage[], int numEtu[], int numEtuSelonStagePourvu[], int nbEtu, int nbStage)
{
    int a;
    for (int i = 0; i < nbEtu; i++)
    {
        a = refStageFinal[i];
        if (a != -1)
            numEtuSelonStagePourvu[identifier(refStage, nbStage, a)] = numEtu[i];
    }
}

void rechercheDPTStage(int refstage[], int dpt[], int numEtu[], int (*stages)[4], boolean stagePourvu[], int numEtuSelonStagePourvu[], int nbEtu, int nbStage)
{
    int departement, s, t;
    printf("\nEntrez un numero de departement: ");
    scanf("%d", &departement);
    while (departement != -1)
    {
        system("cls");
        t = 0;
        for (int i = 0; i < nbStage; i++)
        {
            if (dpt[i] == departement)
            {
                printf("\n");
                AfficherInfoStageSansInput(dpt, refstage, numEtu, stages, stagePourvu, numEtuSelonStagePourvu, nbStage, i);
                printf("\n");
                t = 1;
            }
        }
        if (t == 0)
        {
            printf("\nAucun stage n'a ete trouve avec les informations fournies.\n");
        }
        printf("Entrez un numero de departement (tapez -1 pour sortir):\t");
        scanf("%d", &departement);
    }
    printf("\n");
}

void candidater(int (*stages)[4], int (*stagesEtu)[3], int refStage[], int nbStage, int etu, int numEtu[], int nbEtu, int compteur[], int compteurStages[], boolean stagePourvu[], int stageFinale[])
{
    int stage, s, m;
    if (compteur[identifier(numEtu, nbEtu, etu)] >= 3)
    {
        printf("\nVous avez deja candidater a 3 stages, vous ne puvez plus candidater pour l'instant.\n");
        return;
    }
    printf("A quel stage voulez vous candidater:\t");
    scanf("%d%*c", &stage);
    s = identifier(refStage, nbStage, stage);
    while (s == -1)
    {
        printf("Le stage n'est pas reconnu, veuillez reessayer avec un numero de stage correct.\n(Tapez -1 pour sortir. )\nStage: ");
        scanf("%d%*c", &stage);
        if (stage == -1)
        {
            return;
        }
        s = identifier(refStage, nbStage, stage);
    }
    if (compteurStages[s] >= 3 || stagePourvu[s] == true)
    {
        printf("Ce stage possede 3 candidatures, il est complet.");
        return;
    }
    m = identifier(numEtu, nbEtu, etu);
    // printf("\n%d\n",);
    if (stageFinale{m} != -1)
    {
        printf("Vous etes deja affecter a un stage, vous ne pouvez plus candidater");
        return;
    }
    if (indecs(stages[s], stages[s][0] + 1, etu) != -1)
    {
        printf("Vous avez deja candidater a ce stage.\n");
        return;
    }
    (compteurStages[s])++;
    stages[s][stages[s][0]] = etu;

    stagesEtu[m][compteur[m]] = stage;
    (compteur[m])++;
    (stages[s][0])++;
    printf("Votre candidature a ete prise en compte.\n");
}

void echangerF(float *a, float *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void echangerI(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void trierNotesDecroissant(float notes[], int numEtu[], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (notes[j] < notes[j + 1])
            {
                echangerF(&notes[j], &notes[j + 1]);
                echangerI(&numEtu[j], &numEtu[j + 1]);
            }
        }
    }
}

void copierListeF(float destination[], float source[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        destination[i] = source[i];
    }
}

void copierListeI(int destination[], int source[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        destination[i] = source[i];
    }
}

void AffichageNote(float notes[], int numEtu[], int nbEtu)
{
    int numEtu_Trie[TAILLE_MAX], i;
    float note_Trie[TAILLE_MAX];
    copierListeF(note_Trie, notes, nbEtu);
    copierListeI(numEtu_Trie, numEtu, nbEtu);
    trierNotesDecroissant(note_Trie, numEtu_Trie, nbEtu);
    printf("Voici la liste des notes et des étudiants correspondants\nNote\tEtudiant\n");
    for (i = 0; i < nbEtu; i++)
    {
        if (note_Trie[i] == -1)
            printf("\n%d\tstage en cours...", numEtu_Trie[i]);
        else
            printf("\n%d\t%.2f", numEtu_Trie[i], note_Trie[i]);
    }
    printf("\n\n");
}

void AffichageStageEtudiant(int numEtu[], int stageFinal[], int etu, int dpt[], int (*stageEtu)[3], int compteur[], int nbStage, int nbEtu)
{
    int s, i;
    s = identifier(numEtu, nbEtu, etu);
    if (stageFinal[s] != -1)
    {
        printf("\nVous etes affecter a un stage.\n\n");
        printf("Stage: %d\n", stageFinal[s]);
        i = identifier(stageFinal, nbStage, stageFinal[s]);
        printf("Departement: %d\n\n", dpt[i]);
    }
    else
    {
        printf("\nVous avez candidater a %d stages: \n", compteur[s]);
        printListI(stageEtu[s], compteur[s]);
        printf("\n");
    }
}

void menuResponsable(int compteur[], int numEtuSelonStage[], float notes[], int refStageFinalEtutiant[], int numDesEtutiants_Trie[], boolean stagePourvu[], int refStage_Trie[], int dpt[], int (*stages)[4], int (*stageEtu)[3], int nbEtu, int nbStage)
{
    int choix;
    clear();
    while (1)
    {
        printf("\n==================================\n");
        printf("   Menu Responsable des Stages    ");
        printf("\n==================================\n");
        printf("\n1. Afficher les stages pourvus et les etudiants affectes\n");
        printf("2. Afficher les stages non pourvus\n");
        printf("3. Afficher la liste des etudiants sans stage\n");
        printf("4. Afficher les informations d'un stage donne\n");
        printf("5. Rechercher des stages par numero de departement\n");
        printf("6. Affecter un stage a un etudiant\n");
        printf("7. Saisir les notes d'un etudiant\n");
        printf("8. Afficher les notes.\n");
        printf("9. Quitter\n");
        printf("\nVotre choix : ");
        scanf("%d", &choix);

        while (getchar() != '\n')
            ;

#ifdef _WIN32
        system("cls"); // Pour Windows
#else
        system("clear"); // Pour Linux/macOS
#endif

        switch (choix)
        {
        case 1:
            // Fonction pour afficher les stages pourvus
            AfficherStagePourvuEtEtudiant(refStageFinalEtutiant, numDesEtutiants_Trie, nbEtu);
            printf("Appuyez sur une touche pour continuer...\n");
            getchar();
            clear();
            break;
        case 2:
            // Fonction pour afficher les stages non pourvus
            AfficherStageNonPourvu(stagePourvu, refStage_Trie, nbEtu);
            printf("Appuyez sur une touche pour continuer...\n");
            getchar();
            clear();
            break;
        case 3:
            // Fonction pour afficher les etudiants sans stage
            AfficherEtudiantSansStage(refStageFinalEtutiant, numDesEtutiants_Trie, nbEtu);
            printf("Appuyez sur une touche pour continuer...\n");
            getchar();
            clear();
            break;
        case 4:
            // Fonction pour afficher les informations d'un stage donne
            AfficherInfoStageInput(dpt, refStage_Trie, numDesEtutiants_Trie, stages, stagePourvu, numEtuSelonStage, nbStage);
            printf("Appuyez sur une touche pour continuer...\n");
            getchar();
            clear();
            break;
        case 5:
            // Fonction pour rechercher des stages par critère
            rechercheDPTStage(refStage_Trie, dpt, numDesEtutiants_Trie, stages, stagePourvu, numEtuSelonStage, nbEtu, nbStage);
            printf("Appuyez sur une touche pour continuer...\n");
            getchar();
            clear();
            break;
        case 6:
            affecterStage(compteur, numEtuSelonStage, refStage_Trie, refStageFinalEtutiant, numDesEtutiants_Trie, nbEtu, nbStage, stages, stageEtu, stagePourvu);
            printf("Appuyez sur une touche pour continuer...\n");
            getchar();
            clear();
            break;

        case 7:
            noteEtu(numDesEtutiants_Trie, nbEtu, notes);
            printf("Appuyez sur une touche pour continuer...\n");
            getchar();
            clear();
            break;

        case 8:
            AffichageNote(notes, numDesEtutiants_Trie, nbEtu);
            printf("Appuyez sur une touche pour continuer...\n");
            getchar();
            clear();
            break;

        case 9:
            printf("Au revoir !\n");
            clear();
            return; // Quitte la boucle
        default:
            printf("Choix invalide. Veuillez reessayer.\n");
            clear();
            break;
        }
    }
}

void clear(void)
{

#ifdef _WIN32
    system("cls"); // Pour Windows
#else
    system("clear"); // Pour Linux/macOS
#endif
}

void menuEtudiant(int refStage[], int numEtu[], int dpt[], int compteur[], int refStageFinal[], int (*stagesEtu)[3], int (*stages)[4], boolean stagePourvu[], int numEtuSelonStageFinal[], int etu, int nbStage, int nbEtu)
{
    int choix;
    clear();
    while (1)
    {
        printf("\n==================================\n");
        printf("          Menu Etudiant            ");
        printf("\n==================================\n");
        printf("\n1. Afficher les stages disponibles\n");
        printf("2. Voir mon statut.\n");
        printf("3. Rechercher des stages par numero ou departement\n");
        printf("4. Candidater\n");
        printf("5. Quitter\n");
        printf("\nVotre choix : ");
        scanf("%d", &choix);

        while (getchar() != '\n')
            ;

        clear();

        switch (choix)
        {
        case 1:
            // Fonction pour afficher les stages disponibles
            stageDispo(stagePourvu, refStage, stages, nbStage);
            printf("\n\nAppuyez sur une touche pour continuer...");
            getchar();
            clear();
            break;
        case 2:
            // Fonction pour afficher l'affectation de stage de l'etudiant
            AffichageStageEtudiant(numEtu, refStageFinal, etu, dpt, stagesEtu, compteur, nbStage, nbEtu);
            printf("Appuyez sur une touche pour continuer...");
            getchar();
            clear();
            break;
        case 3:
            // Fonction pour afficher la liste des etudiants sans stage
            rechercheDPTStage(refStage, dpt, numEtu, stages, stagePourvu, numEtuSelonStageFinal, nbEtu, nbStage);
            printf("\nAppuyez sur une touche pour continuer...");
            getchar();
            clear();
            break;
        case 4:
            candidater(stages, stagesEtu, refStage, nbStage, etu, numEtu, nbEtu, compteur, compteur, stagePourvu, refStageFinal);
            printf("\nAppuyez sur une touche pour continuer...");
            getchar();
            clear();
            break;
        case 5:
            printf("Au revoir");
            return;
        default:
            printf("Choix invalide. Veuillez reessayer.\n");
            clear();
            break;
        }
    }
}

void Affichage(float noteEtu[], int refStageFinalEtutiant[], int numDesEtutiants_Trie[], boolean stagePourvu[], int refStage_Trie[], int dpt[], int (*stages)[4], int numEtuSelonStageFinal[], int nbEtu, int nbStage, int compteur[], int (*stagesEtu)[3])
{
    int etu, m;
    clear();
    int p = IdentifierPersonne();
    // printf("%d", p);
    if (p == 1)
    {
        printf("\nEntrez votre numero d'etudiant:\t");
        scanf("%d", &etu);
        m = identifier(numDesEtutiants_Trie, nbEtu, etu);
        while (m == -1)
        {
            clear();
            printf("\nCe numero d'Etudiant ne figure pas dans nos fichiers. \nVeuillez Reesayer\nTapez -1 pour sortir:\t");
            scanf("%d", &etu);
            if (etu == -1)
                return;
            m = identifier(numDesEtutiants_Trie, nbEtu, etu);
            clear();
        }
        menuEtudiant(refStage_Trie, numDesEtutiants_Trie, dpt, compteur, refStageFinalEtutiant, stagesEtu, stages, stagePourvu, numEtuSelonStageFinal, etu, nbStage, nbEtu);
    }
    else if (p == 2)
        menuResponsable(compteur, numEtuSelonStageFinal, noteEtu, refStageFinalEtutiant, numDesEtutiants_Trie, stagePourvu, refStage_Trie, dpt, stages, stagesEtu, nbEtu, nbStage);
}

void save(float noteEtu[], int refStageFinalEtutiant[], int numDesEtutiants_Trie[], boolean stagePourvu[], int refStage_Trie[], int dpt[], int (*stages)[4], int nbEtu, int nbStage, int compteur[])
{
    FILE *etudiant, *stage;
    etudiant = fopen("etudiants.txt", "w");
    stage = fopen("stage.txt", "w");
    if (etudiant == NULL || stage == NULL)
    {
        printf("Erreur d'ouverture des fichiers");
        return;
    }
    for (int i = 0; i < nbEtu; i++)
    {
        fprintf(etudiant, "%d\t%d\t%.2f\n", numDesEtutiants_Trie[i], refStageFinalEtutiant[i], noteEtu[i]);
    }
    for (int i = 0; i < nbStage; i++)
    {
        fprintf(stage, "%d\t%d\n", refStage_Trie[i], dpt[i]);
        fprintf(stage, "%d\n", stagePourvu[i]);
        if (stagePourvu[i] != true)
        {
            fprintf(stage, "%d\n", stages[i][0]);
            for (int x = 1; x <= stages[i][0]; x++)
                fprintf(stage, "%d\n", stages[i][x]);
        }
    }
    fclose(etudiant);
    fclose(stage);
}
