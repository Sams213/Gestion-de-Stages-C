/**
∗ \file test.c
∗ \brief Ce fichier est le noyau du projet, il contient les tests et le main
∗ \author Jabbour Ghassan et Halilou Sami
∗ \date 17/11/2024
∗
∗ Ce fichier contient la fonction main qui va executer l'application,
* il contient aussi les tests de toutes les fonctions du projet
*/

#include "sae.h"

void test(void)
{
	int numDesEtutiants_Trie[TAILLE_MAX] = {0}, refStageFinalEtudiant[TAILLE_MAX] = {0};
	int compteur[TAILLE_MAX] = {0};
	int refStage_Trie[TAILLE_MAX] = {0}, stages[TAILLE_MAX][4] = {0}, dpt[TAILLE_MAX] = {0};
	int numEtuSelonStageFinal[TAILLE_MAX] = {0}, stageEtu[TAILLE_MAX][3] = {0}, compteurStage[TAILLE_MAX] = {0};
	int nbEtu, nbStage;
	boolean stagePourvu[TAILLE_MAX] = {0};
	float notesfinal[TAILLE_MAX];
	nbEtu = rempliretu(numDesEtutiants_Trie, refStageFinalEtudiant, notesfinal, TAILLE_MAX);
	nbStage = remplirstage(refStage_Trie, stages, stageEtu, stagePourvu, dpt, TAILLE_MAX, numDesEtutiants_Trie, nbEtu, compteur, compteurStage);
	TriEtudiantSelonLeStagePourvu(refStageFinalEtudiant, refStage_Trie, numDesEtutiants_Trie, numEtuSelonStageFinal, nbEtu, nbStage);
	// printListLL(stages, nbStage);
	// affecterStage(compteur, numEtuSelonStageFinal, refStage_Trie, refStageFinalEtudiant, numDesEtutiants_Trie, nbEtu, nbStage, stages, stageEtu, stagePourvu);

	// menuEtudiant(refStage_Trie, numDesEtutiants_Trie, dpt, compteur, refStageFinalEtudiant, stageEtu, stages, stagePourvu, numEtuSelonStageFinal, 233, nbStage, nbEtu);
	// menuResponsable(refStageFinalEtudiant, numDesEtutiants_Trie, stagePourvu, refStage_Trie, dpt, stages, numEtuSelonStageFinal, nbEtu, nbStage);
	// AffichageStageEtudiant(numDesEtutiants_Trie, refStageFinalEtudiant, 958, dpt, stageEtu, compteur, nbStage, nbEtu);
	// candidater(stages, stageEtu, refStage_Trie, nbStage, 101, numDesEtutiants_Trie, nbEtu, compteur, compteurStage, stagePourvu);

	// Affichage(notesfinal, refStageFinalEtudiant, numDesEtutiants_Trie, stagePourvu, refStage_Trie, dpt, stages, numEtuSelonStageFinal, nbEtu, nbStage, compteur, stageEtu);

	// printListLL(stages, nbStage);

	// printListI(refStage_Trie, nbStage);
	// printListI(numEtuSelonStageFinal, nbStage);

	// AfficherInfoStageInput(dpt, refStage_Trie, numDesEtutiants_Trie, stages, stagePourvu, numEtuSelonStageFinal, nbStage);
	// rechercheDPTStage(refStage_Trie, dpt, numDesEtutiants_Trie, stages, stagePourvu, numEtuSelonStageFinal, nbEtu, nbStage);
	// stageDispo(stagePourvu, refStage_Trie, stages, nbStage);
	// printf("\n\n");
	// printListF(notesfinal, nbEtu);
	// printf("\n%d\n\n", nbStage);
	// printListLL(stages, nbStage);
	// printf("\n\n");
	// printListI(compteur, nbEtu);
	// printListI(numDesEtutiants_Trie, nbEtu);
	// printf("\n\n");
	// stageDispo(stagePourvu, refStage_Trie, stages, nbStage);
	// AfficherStagePourvuEtEtudiant(refStageFinalEtudiant, numDesEtutiants_Trie, nbEtu);
	// AfficherStageNonPourvu(stagePourvu, refStage_Trie, nbEtu);
	// AfficherEtudiantSansStage(refStageFinalEtudiant, numDesEtutiants_Trie, nbEtu);
}

void testMdpAdmin(void)
{
	char mdp[20];
	liremdpAdmin(mdp);
}

void globale(void)
{
	int numDesEtutiants_Trie[TAILLE_MAX] = {0}, refStageFinalEtudiant[TAILLE_MAX] = {0},
		compteur[TAILLE_MAX] = {0}, refStage_Trie[TAILLE_MAX] = {0},
		stages[TAILLE_MAX][4] = {0}, dpt[TAILLE_MAX] = {0},
		numEtuSelonStageFinal[TAILLE_MAX] = {0},
		stageEtu[TAILLE_MAX][3] = {0}, compteurStage[TAILLE_MAX] = {0};
	int nbEtu, nbStage;
	boolean stagePourvu[TAILLE_MAX] = {0};
	float notesfinal[TAILLE_MAX];

	nbEtu = rempliretu(numDesEtutiants_Trie, refStageFinalEtudiant, notesfinal, TAILLE_MAX);
	nbStage = remplirstage(refStage_Trie, stages, stageEtu, stagePourvu, dpt, TAILLE_MAX, numDesEtutiants_Trie, nbEtu, compteur, compteurStage);
	TriEtudiantSelonLeStagePourvu(refStageFinalEtudiant, refStage_Trie, numDesEtutiants_Trie, numEtuSelonStageFinal, nbEtu, nbStage);

	Affichage(notesfinal, refStageFinalEtudiant, numDesEtutiants_Trie, stagePourvu, refStage_Trie, dpt, stages, numEtuSelonStageFinal, nbEtu, nbStage, compteur, stageEtu);

	save(notesfinal, refStageFinalEtudiant, numDesEtutiants_Trie, stagePourvu, refStage_Trie, dpt, stages, nbEtu, nbStage, compteur);
}

int main(void)
{
	// test();
	globale();
	return 0;
}