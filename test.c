#include "sae.h"

void test(void)
{
	int numEtu[100], refStageEtu[100];
	int refStage[100], stageNumEtuCandid[100][4], stagePourvu[100], dpt[100];
	int nbEtu, nbStage;
	float notes[100];
	nbEtu = rempliretu(numEtu, refStageEtu, notes, 100);
	nbStage = remplirstage(refStage, stageNumEtuCandid, stagePourvu, dpt, 100);
	/* printListI(numEtu, nb);
	printListI(refStageEtu, nb);
	printListF(notes, nb); */
	printListLL(stageNumEtuCandid, nbStage);
	
}

int main(void)
{
	test();
    return 0;
}