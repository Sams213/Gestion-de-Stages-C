#include "sae.h"

void test(void)
{
	int numDesEtutiants_Trie[100], refStageFinalEtutiant[100];
	int compteurNombreStagesParEtudiants[100];
	int refStage_Trie[100], stages[100][4], dpt[100];
	int nbEtu, nbStage;
	boolean stagePourvu[100];
	float notesfinal[100];
	nbEtu = rempliretu(numDesEtutiants_Trie, refStageFinalEtutiant, notes, 100);
	nbStage = remplirstage(refStage_Trie, stages, stagePourvu, dpt, 100, numDesEtutiants_Trie, nbEtu, compteurNombreStagesParEtudiants);

	printListI(numDesEtutiants_Trie, nbEtu);
	printListI(refStage_Trie, nbStage);
	printListF(notesfinal, nbEtu);
	printListLL(stages, nbStage);

}

int main(void)
{
	test();
	return 0;
}