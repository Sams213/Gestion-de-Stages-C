#include <stdio.h>
#include <string.h>

typedef enum
{
    false,
    true
} boolean;

void printListF(float L[], int nb);
void printListI(int L[], int nb);
void printListLL(int (*L)[4], int nb);
int rempliretu(int numEtu[], int refStageEtu[], float notes[], int tmax);
int remplirstage(int refStage[], int (*stageNumEtuCandid)[4], boolean stagePourvu[], int dpt[], int tmax, int numEtu[], int tmaxNumEtu, int compteur[]);
int identifierEtudiant(int numEtu[], int tmax, int etu);
int checkstage(int stageNumEtuCandid[], int numEtu[], int tmax, int etu);
float moyenne(float n1, float n2, float n3);