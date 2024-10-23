#include <stdio.h>

void printListF(float L[], int nb);
void printListI(int L[], int nb);
int rempliretu(int numEtu[], int refStageEtu[], float notes[], int tmax);
int remplirstage(int refStage[], int (*stageNumEtuCandid)[4], int stagePourvu[], int dpt[],int tmax);
int identifierEtudiant(int numEtu[],int tmax);
int checkstage(int stageNumEtuCandid[],int numEtu[], int tmax);
void Affichage(void);
void printListLL(int (*L)[4], int nb);