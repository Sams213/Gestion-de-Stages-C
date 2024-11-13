#include <stdio.h>
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