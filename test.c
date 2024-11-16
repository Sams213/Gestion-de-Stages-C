#include "sae.h"

void test(void)
{
	int numDesEtutiants_Trie[100], refStageFinalEtutiant[100];
	int compteurNombreStagesParEtudiants[100] = {0};
	int refStage_Trie[100] = {0}, stages[100][4] = {0}, dpt[100];
	int numEtuSelonStageFinal[100] = {0};
	int nbEtu, nbStage;
	boolean stagePourvu[100] = {
		false,
		false,
		false,
		false,
		false,
		false,
		false,
	};
	float notesfinal[100];
	nbEtu = rempliretu(numDesEtutiants_Trie, refStageFinalEtutiant, notesfinal, 100);
	// printf("\n\n");
	nbStage = remplirstage(refStage_Trie, stages, stagePourvu, dpt, 100, numDesEtutiants_Trie, nbEtu, compteurNombreStagesParEtudiants);
	TriEtudiantSelonLeStagePourvu(refStageFinalEtutiant, refStage_Trie, numDesEtutiants_Trie, numEtuSelonStageFinal, nbEtu, nbStage);

	// printListI(refStage_Trie, nbStage);
	// printListI(numEtuSelonStageFinal, nbStage);

	AfficherInfoStage(dpt, refStage_Trie, numDesEtutiants_Trie, stages, stagePourvu, numEtuSelonStageFinal, nbStage);

	// printf("\n\n");
	// printListF(notesfinal, nbEtu);
	// printf("\n%d\n\n", nbStage);
	// printListLL(stages, nbStage);
	// printf("\n\n");
	// printListI(compteurNombreStagesParEtudiants, nbEtu);
	// printListI(numDesEtutiants_Trie, nbEtu);
	// printf("\n\n");
	// stageDispo(stagePourvu, refStage_Trie, stages, nbStage);
	// AfficherStagePourvuEtEtudiant(refStageFinalEtutiant, numDesEtutiants_Trie, nbEtu);
	// AfficherStageNonPourvu(stagePourvu, refStage_Trie, nbEtu);
	// AfficherEtudiantSansStage(refStageFinalEtutiant, numDesEtutiants_Trie, nbEtu);
}

void testMdpAdmin(void)
{
	char mdp[20];
	mdpAdmin(mdp);
}

int main(void)
{
	test();
	// testMdpAdmin();
	return 0;
}