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
    int list[3][4] = {
        {3, 10, 20, 30}, // 3 elements: 10, 20, 30
        {2, 40, 50},     // 2 elements: 40, 50
        {4, 60, 70, 80} // 4 elements: 60, 70, 80, 90
    };

    printListLL(list, 3); // Print 3 lists
    return 0;
}