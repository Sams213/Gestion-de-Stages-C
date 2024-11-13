#include "sae.h"

void test(void)
{
	int numDesEtutiants_Trie[100], refStageFinalEtutiant[100];
	int compteurNombreStagesParEtudiants[100];
	int refStage_Trie[100]={0}, stages[100][4]={0}, dpt[100];
	int nbEtu, nbStage;
	boolean stagePourvu[100];
	float notesfinal[100];
	nbEtu = rempliretu(numDesEtutiants_Trie, refStageFinalEtutiant, notesfinal, 100);
	printListI(numDesEtutiants_Trie, nbEtu);
	printf("\n\n");
	nbStage = remplirstage(refStage_Trie, stages, stagePourvu, dpt, 100, numDesEtutiants_Trie, nbEtu, compteurNombreStagesParEtudiants);
	printListI(refStage_Trie, nbStage);
	printf("\n\n");
	printListF(notesfinal, nbEtu);
	printf("\n%d\n\n", nbStage);
	printListLL(stages, nbStage);
}

int main(void)
{
	test();
	printListLL({{0,12,15,16},
				{2,245,6548,541}},2);
	return 0;
}