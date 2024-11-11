#include "sae.h"

void test(void)
{
	int numEtu[100], refStageEtu[100], compteur[100];
	int refStage[100], stageNumEtuCandid[100][4], dpt[100];
	int nbEtu, nbStage;
	boolean stagePourvu[100];
	float notes[100];
	nbEtu = rempliretu(numEtu, refStageEtu, notes, 100);
	nbStage = remplirstage(refStage, stageNumEtuCandid, stagePourvu, dpt, 100, numEtu, nbEtu, compteur);
	/* printListI(numEtu, nb);
	printListI(refStageEtu, nb);
	printListF(notes, nb); */
	printListLL(stageNumEtuCandid, nbStage);
}

int main(void)
{
	// test();
	printf("%.2f", moyenne(15.5, 13.25, 14));
	return 0;
}