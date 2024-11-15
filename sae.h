#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    false,
    true
} boolean;

int identifier(int L[], int nb, int element);
void compteurStageEtu(int numEtu[], int compteur[], int etu, int nb);
int rechercheL(int L[], int element, int nb);
void decalerAGaucheLL(int (*L)[4], int col, int index);
void decalerADroite(boolean L[], int nb, int index, int element);
void decalerADroiteI(int L[], int nb, int index, int element);
void decalerADroiteL(int L[], int *nb, int index, int element);
void decalerADroiteLL(int (*stages)[4], int index, int nb);
void printListI(int L[], int nb);
void printListF(float notes[], int nb);
void printListLL(int (*L)[4], int nb);
int rempliretu(int numEtu[], int refStageEtu[], float notes[], int tmax);
int remplirstage(int refStage[], int (*stageNumEtuCandid)[4], boolean stagePourvu[], int dpt[], int tmax, int numEtu[], int nbEtu, int compteur[]);
int saisirEtu(void);
int checkEtu3(int numEtu[], int compteur[], int tmax, int etu);
void stageDispo(boolean stagePourvu[], int refStages[], int (*stages)[4], int nbstage);
void affecterStage(int refstage[], int refStageEtu[], int numEtu[], int nb, int (*stages)[4], boolean stagePourvu[]);
float moyenne(float n1, float n2, float n3);
void noteEtu(int numEtu[], int nb, float noteEtu[]);
int IdentifierPersonne(void);
void mdpAdmin(char mdpAdmin[]);
void AfficherStagePourvuEtEtudiant(int refStageFinal[], int refEtu[], int nbEtu);
void AfficherStageNonPourvu(boolean stagePourvu[], int refStage[], int nbStage);
void affecterStage(int refstage[], int refStageFinalEtu[], int numEtu[], int nb, int (*stages)[4], boolean stagePourvu[]);
void AfficherEtudiantSansStage(int refStageFinal[], int numEtu[], int nb);
void TriEtudiantSelonLeStagePourvu(int refStageFinal[], int refStage[], int numEtu[], int numEtuSelonStagePourvu[], int nbEtu, int nbStage);
void AfficherInfoStage(int refStage[], int numEtu[], int (*stages)[4], boolean stagePourvu[], int numEtuSelonStagePourvu[], int nbStage);
