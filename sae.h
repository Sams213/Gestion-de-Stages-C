/**
∗ \file sae.h
∗ \brief Ce fichier regroupe toutes les fonctions du projet SAE_Algo_1.01
∗ \author Jabbour Ghassan et Halilou Sami
∗ \date 17/11/2024
∗
∗ Ce fichier contient l'initialisation et la liaison de l'intégralité des fonctions utilisés dans le projet
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 100

typedef enum
{
    false,
    true
} boolean;

/**
 * \brief Retourne l'indice du dernier élément non nul dans un tableau.
 * \param L Tableau d'entiers.
 * \param nb Nombre d'éléments dans le tableau.
 * \return L'indice du dernier élément non nul, ou -1 si tous les éléments sont nuls.
 */
int dernierIndice(int L[], int nb);

/**
 * \brief Recherche la première occurrence d'un élément dans un tableau.
 * \param L Tableau d'entiers.
 * \param nb Nombre d'éléments dans le tableau.
 * \param element Élément à rechercher.
 * \return L'indice de la première occurrence, ou -1 si l'élément n'est pas trouvé.
 */
int indecs(int L[], int nb, int element);

/**
 * \brief Identifie l'indice d'un étudiant dans les données.
 * \param L Tableau d'entiers (numéros d'étudiants).
 * \param nb Nombre d'éléments dans le tableau.
 * \param element Numéro de l'étudiant à rechercher.
 * \return L'indice de l'étudiant, ou -1 s'il n'est pas trouvé.
 */
int identifier(int L[], int nb, int element);

/**
 * \brief Incrémente le compteur de stages d'un étudiant.
 * \param numEtu Tableau des numéros d'étudiants.
 * \param compteur Tableau des compteurs de stages.
 * \param etu Numéro de l'étudiant.
 * \param nb Nombre total d'étudiants.
 */
void compteurStageEtu(int numEtu[], int compteur[], int etu, int nb);

/**
 * \brief Recherche l'indice du premier élément supérieur à une valeur dans un tableau.
 * \param L Tableau d'entiers.
 * \param element Valeur à comparer.
 * \param nb Nombre d'éléments dans le tableau.
 * \return L'indice du premier élément supérieur, ou le nombre total d'éléments.
 */
int rechercheL(int L[], int element, int nb);

/**
 * \brief Décale les éléments à gauche dans une colonne d'un tableau 2D à partir d'un indice.
 * \param L Tableau 2D d'entiers.
 * \param col Colonne concernée.
 * \param index Indice de départ pour le décalage.
 */
void decalerAGaucheLL(int (*L)[4], int col, int index);

/**
 * \brief Décale les éléments à droite dans un tableau et insère un élément.
 * \param L Tableau d'entiers.
 * \param nb Taille actuelle du tableau.
 * \param index Indice où insérer l'élément.
 * \param element Élément à insérer.
 */
void decalerADroite(boolean L[], int nb, int index, int element);

/**
 * \brief Affiche les éléments d'un tableau d'entiers.
 * \param L Tableau d'entiers.
 * \param nb Nombre d'éléments dans le tableau.
 */
void printListI(int L[], int nb);

/**
 * \brief Calcule la moyenne pondérée de trois notes.
 * \param n1 Première note.
 * \param n2 Deuxième note.
 * \param n3 Troisième note.
 * \return La moyenne pondérée.
 */
float moyenne(float n1, float n2, float n3);

/**
 * \brief Remplit les données des étudiants à partir d'un fichier.
 * \param numEtu Tableau des numéros d'étudiants.
 * \param refStageEtu Tableau des références de stages des étudiants.
 * \param notes Tableau des notes des étudiants.
 * \param tmax Taille maximale des tableaux.
 * \return Nombre d'étudiants lus, ou un code d'erreur.
 */
int rempliretu(int numEtu[], int refStageEtu[], float notes[], int tmax);

/**
 * \brief Décale les éléments à droite dans un tableau en insérant un élément.
 * \param L Tableau d'entiers.
 * \param nb Taille actuelle du tableau.
 * \param index Indice où insérer l'élément.
 * \param element Élément à insérer.
 */
void decalerADroiteI(int L[], int nb, int index, int element);

/**
 * \brief Décale les éléments à droite dans un tableau et met à jour sa taille.
 * \param L Tableau d'entiers.
 * \param nb Pointeur vers la taille actuelle du tableau.
 * \param index Indice où insérer l'élément.
 * \param element Élément à insérer.
 */
void decalerADroiteL(int L[], int *nb, int index, int element);

/**
 * \brief Décale les lignes d'un tableau 2D vers le bas à partir d'un indice.
 * \param stages Tableau 2D d'entiers.
 * \param index Indice de départ pour le décalage.
 * \param nb Taille actuelle du tableau.
 */
void decalerADroiteLL(int (*stages)[4], int index, int nb);

/**
 * \brief Affiche un tableau de flottants.
 * \param notes Tableau de notes.
 * \param nb Nombre d'éléments dans le tableau.
 */
void printListF(float notes[], int nb);

/**
 * \brief Affiche un tableau 2D d'entiers.
 * \param L Tableau 2D d'entiers.
 * \param nb Nombre de lignes dans le tableau.
 */
void printListLL(int (*L)[4], int nb);

/**
 * \brief Remplit les données des stages à partir d'un fichier.
 * \param refStage Tableau des références de stages.
 * \param stageNumEtuCandid Tableau des numéros d'étudiants candidats par stage.
 * \param stageEtu Tableau des stages affectés à chaque étudiant.
 * \param stagePourvu Tableau des états des stages (pourvus ou non).
 * \param dpt Tableau des départements.
 * \param tmax Taille maximale des tableaux.
 * \param numEtu Tableau des numéros d'étudiants.
 * \param nbEtu Nombre d'étudiants.
 * \param compteur Tableau des compteurs de stages par étudiant.
 * \param compteurStages Tableau des compteurs d'étudiants par stage.
 * \return Nombre de stages lus, ou un code d'erreur.
 */
int remplirstage(int refStage[], int (*stageNumEtuCandid)[4], int (*stageEtu)[3], boolean stagePourvu[], int dpt[], int tmax, int numEtu[], int nbEtu, int compteur[], int compteurStages[]);

/**
 * \brief Affiche les stages disponibles.
 * \param stagePourvu Tableau des états des stages (pourvus ou non).
 * \param refStages Tableau des références de stages.
 * \param stages Tableau des informations des stages.
 * \param nbstage Nombre de stages.
 */
void stageDispo(boolean stagePourvu[], int refStages[], int (*stages)[4], int nbstage);

/**
 * \brief Affecte un stage à un étudiant.
 * \param compteur Tableau des compteurs de stages par étudiant.
 * \param numEtuSelonStage Tableau des numéros d'étudiants affectés à chaque stage.
 * \param refstage Tableau des références de stages.
 * \param refStageFinalEtu Tableau des références finales des stages par étudiant.
 * \param numEtu Tableau des numéros d'étudiants.
 * \param nbEtu Nombre d'étudiants.
 * \param nbStage Nombre de stages.
 * \param stages Tableau des informations des stages.
 * \param stageEtu Tableau des stages affectés à chaque étudiant.
 * \param stagePourvu Tableau des états des stages (pourvus ou non).
 */
void affecterStage(int compteur[], int numEtuSelonStage[], int refstage[], int refStageFinalEtu[], int numEtu[], int nbEtu, int nbStage, int (*stages)[4], int (*stageEtu)[3], boolean stagePourvu[]);

/**
 * \brief Permet de noter un étudiant avec des notes d'entreprise, de rapport et de soutenance.
 * \param numEtu Tableau des numéros d'étudiants.
 * \param nb Nombre d'étudiants.
 * \param noteEtu Tableau des moyennes des notes des étudiants.
 */
void noteEtu(int numEtu[], int nb, float noteEtu[]);

/**
 * \brief Identifie le type de personne (étudiant ou responsable).
 * \return 1 si étudiant, 2 si responsable.
 */
int IdentifierPersonne(void);

/**
 * \brief Lit le mot de passe administrateur à partir d'un fichier.
 * \param mdpAdmin Chaîne pour stocker le mot de passe lu.
 */
void liremdpAdmin(char mdpAdmin[]);

/**
 * \brief Affiche les stages pourvus et les étudiants qui y sont affectés.
 * \param refStageFinal Tableau des références finales des stages par étudiant.
 * \param refEtu Tableau des numéros d'étudiants.
 * \param nbEtu Nombre d'étudiants.
 */
void AfficherStagePourvuEtEtudiant(int refStageFinal[], int refEtu[], int nbEtu);

/*
 * \brief Affiche les stages non pourvus avec leur référence.
 *
 * \param stagePourvu Tableau indiquant si chaque stage est pourvu (true/false).
 * \param refStage Tableau des références des stages.
 * \param nbStage Nombre total de stages.
 */
void AfficherStageNonPourvu(boolean stagePourvu[], int refStage[], int nbStage);

/*
 * \brief Affiche les étudiants n'ayant pas encore été affectés à un stage.
 *
 * \param refStageFinal Tableau des références finales des stages assignés aux étudiants (-1 si non assigné).
 * \param numEtu Tableau des numéros des étudiants.
 * \param nb Nombre total d'étudiants.
 */
void AfficherEtudiantSansStage(int refStageFinal[], int numEtu[], int nb);

/*
 * \brief Affiche les informations sur un stage spécifique en demandant son numéro à l'utilisateur.
 *
 * \param dpt Tableau des départements associés aux stages.
 * \param refStage Tableau des références des stages.
 * \param numEtu Tableau des numéros des étudiants.
 * \param stages Matrice représentant les candidats pour chaque stage.
 * \param stagePourvu Tableau indiquant si chaque stage est pourvu (true/false).
 * \param numEtuSelonStagePourvu Tableau des étudiants affectés à un stage.
 * \param nbStage Nombre total de stages.
 */
void AfficherInfoStageInput(int dpt[], int refStage[], int numEtu[], int (*stages)[4], boolean stagePourvu[], int numEtuSelonStagePourvu[], int nbStage);

/*
 * \brief Affiche les informations d'un stage spécifique sans demander d'entrée utilisateur.
 *
 * \param dpt Tableau des départements associés aux stages.
 * \param refStage Tableau des références des stages.
 * \param numEtu Tableau des numéros des étudiants.
 * \param stages Matrice représentant les candidats pour chaque stage.
 * \param stagePourvu Tableau indiquant si chaque stage est pourvu (true/false).
 * \param numEtuSelonStagePourvu Tableau des étudiants affectés à un stage.
 * \param nbStage Nombre total de stages.
 * \param s Index du stage à afficher.
 */
void AfficherInfoStageSansInput(int dpt[], int refStage[], int numEtu[], int (*stages)[4], boolean stagePourvu[], int numEtuSelonStagePourvu[], int nbStage, int s);

/*
 * \brief Trie les étudiants en fonction des stages pourvus.
 *
 * \param refStageFinal Tableau des références finales des stages assignés aux étudiants.
 * \param refStage Tableau des références des stages.
 * \param numEtu Tableau des numéros des étudiants.
 * \param numEtuSelonStagePourvu Tableau des étudiants affectés à un stage.
 * \param nbEtu Nombre total d'étudiants.
 * \param nbStage Nombre total de stages.
 */
void TriEtudiantSelonLeStagePourvu(int refStageFinal[], int refStage[], int numEtu[], int numEtuSelonStagePourvu[], int nbEtu, int nbStage);

/*
 * \brief Recherche des stages selon un numéro de département donné par l'utilisateur.
 *
 * \param refstage Tableau des références des stages.
 * \param dpt Tableau des départements associés aux stages.
 * \param numEtu Tableau des numéros des étudiants.
 * \param stages Matrice représentant les candidats pour chaque stage.
 * \param stagePourvu Tableau indiquant si chaque stage est pourvu (true/false).
 * \param numEtuSelonStagePourvu Tableau des étudiants affectés à un stage.
 * \param nbEtu Nombre total d'étudiants.
 * \param nbStage Nombre total de stages.
 */
void rechercheDPTStage(int refstage[], int dpt[], int numEtu[], int (*stages)[4], boolean stagePourvu[], int numEtuSelonStagePourvu[], int nbEtu, int nbStage);

/*
 * \brief Permet à un étudiant de candidater à un stage.
 *
 * \param stages Tableau des stages et de leurs candidats.
 * \param stagesEtu Tableau des stages auxquels chaque étudiant a candidaté.
 * \param refStage Références des stages.
 * \param nbStage Nombre total de stages.
 * \param etu Numéro de l'étudiant.
 * \param numEtu Tableau des numéros des étudiants.
 * \param nbEtu Nombre total d'étudiants.
 * \param compteur Compteur des candidatures des étudiants.
 * \param compteurStages Compteur des candidatures pour chaque stage.
 * \param stagePourvu Tableau indiquant si chaque stage est pourvu.
 */
void candidater(int (*stages)[4], int (*stagesEtu)[3], int refStage[], int nbStage, int etu, int numEtu[], int nbEtu, int compteur[], int compteurStages[], boolean stagePourvu[]);

/*
 * \brief Échange deux valeurs de type float.
 *
 * \param a Pointeur sur le premier float.
 * \param b Pointeur sur le second float.
 */
void echangerF(float *a, float *b);

/*
 * \brief Échange deux valeurs de type int.
 *
 * \param a Pointeur sur le premier int.
 * \param b Pointeur sur le second int.
 */
void echangerI(int *a, int *b);

/*
 * \brief Trie les notes des étudiants par ordre décroissant.
 *
 * \param notes Tableau des notes des étudiants.
 * \param numEtu Tableau des numéros des étudiants correspondant aux notes.
 * \param n Nombre d'étudiants.
 */
void trierNotesDecroissant(float notes[], int numEtu[], int n);

/*
 * \brief Copie un tableau de floats.
 *
 * \param destination Tableau de destination.
 * \param source Tableau source.
 * \param taille Taille du tableau.
 */
void copierListeF(float destination[], float source[], int taille);

/*
 * \brief Copie un tableau d'entiers.
 *
 * \param destination Tableau de destination.
 * \param source Tableau source.
 * \param taille Taille du tableau.
 */
void copierListeI(int destination[], int source[], int taille);

/*
 * \brief Affiche les notes des étudiants triées par ordre décroissant.
 *
 * \param notes Tableau des notes.
 * \param numEtu Tableau des numéros des étudiants.
 * \param nbEtu Nombre total d'étudiants.
 */
void AffichageNote(float notes[], int numEtu[], int nbEtu);

/*
 * \brief Affiche les informations d'affectation d'un étudiant.
 *
 * \param numEtu Tableau des numéros des étudiants.
 * \param stageFinal Tableau des stages finaux attribués.
 * \param etu Numéro de l'étudiant concerné.
 * \param dpt Tableau des départements des stages.
 * \param stageEtu Tableau des stages auxquels chaque étudiant a candidaté.
 * \param compteur Compteur des candidatures par étudiant.
 * \param nbStage Nombre total de stages.
 * \param nbEtu Nombre total d'étudiants.
 */
void AffichageStageEtudiant(int numEtu[], int stageFinal[], int etu, int dpt[], int (*stageEtu)[3], int compteur[], int nbStage, int nbEtu);

/*
 * \brief Menu principal pour les responsables des stages.
 *
 * \param compteur Compteur des candidatures des étudiants.
 * \param numEtuSelonStage Tableau des numéros des étudiants selon les stages.
 * \param notes Tableau des notes des étudiants.
 * \param refStageFinalEtutiant Tableau des références des stages finaux des étudiants.
 * \param numDesEtutiants_Trie Tableau des numéros d'étudiants triés.
 * \param stagePourvu Tableau indiquant si chaque stage est pourvu.
 * \param refStage_Trie Tableau des références des stages triés.
 * \param dpt Tableau des départements associés aux stages.
 * \param stages Tableau des stages et de leurs candidats.
 * \param stageEtu Tableau des stages auxquels chaque étudiant a candidaté.
 * \param nbEtu Nombre total d'étudiants.
 * \param nbStage Nombre total de stages.
 */
void menuResponsable(int compteur[], int numEtuSelonStage[], float notes[], int refStageFinalEtutiant[], int numDesEtutiants_Trie[], boolean stagePourvu[], int refStage_Trie[], int dpt[], int (*stages)[4], int (*stageEtu)[3], int nbEtu, int nbStage);

/*
 * \brief Efface l'écran de la console.
 */
void clear(void);

/*
 * \brief Menu principal pour les étudiants.
 *
 * \param refStage Tableau des références des stages.
 * \param numEtu Tableau des numéros des étudiants.
 * \param dpt Tableau des départements associés aux stages.
 * \param compteur Compteur des candidatures des étudiants.
 * \param refStageFinal Tableau des références des stages finaux des étudiants.
 * \param stagesEtu Tableau des stages auxquels chaque étudiant a candidaté.
 * \param stages Tableau des stages et de leurs candidats.
 * \param stagePourvu Tableau indiquant si chaque stage est pourvu.
 * \param numEtuSelonStageFinal Tableau des numéros des étudiants selon les stages finaux.
 * \param etu Numéro de l'étudiant concerné.
 * \param nbStage Nombre total de stages.
 * \param nbEtu Nombre total d'étudiants.
 */
void menuEtudiant(int refStage[], int numEtu[], int dpt[], int compteur[], int refStageFinal[], int (*stagesEtu)[3], int (*stages)[4], boolean stagePourvu[], int numEtuSelonStageFinal[], int etu, int nbStage, int nbEtu);

/*
 * \brief Point d'entrée principal pour afficher les menus en fonction du type d'utilisateur.
 *
 * \param noteEtu Tableau des notes des étudiants.
 * \param refStageFinalEtutiant Tableau des références des stages finaux attribués.
 * \param numDesEtutiants_Trie Tableau des numéros des étudiants triés.
 * \param stagePourvu Tableau indiquant si chaque stage est pourvu.
 * \param refStage_Trie Tableau des références des stages triés.
 * \param dpt Tableau des départements associés aux stages.
 * \param stages Tableau des stages et de leurs candidats.
 * \param numEtuSelonStageFinal Tableau des numéros des étudiants selon les stages finaux.
 * \param nbEtu Nombre total d'étudiants.
 * \param nbStage Nombre total de stages.
 * \param compteur Compteur des candidatures des étudiants.
 * \param stagesEtu Tableau des stages auxquels chaque étudiant a candidaté.
 */
void Affichage(float noteEtu[], int refStageFinalEtutiant[], int numDesEtutiants_Trie[], boolean stagePourvu[], int refStage_Trie[], int dpt[], int (*stages)[4], int numEtuSelonStageFinal[], int nbEtu, int nbStage, int compteur[], int (*stagesEtu)[3]);

/*
 * \brief Sauvegarde les données des étudiants et des stages dans des fichiers.
 *
 * \param noteEtu Tableau des notes des étudiants.
 * \param refStageFinalEtutiant Tableau des références des stages finaux attribués.
 * \param numDesEtutiants_Trie Tableau des numéros des étudiants triés.
 * \param stagePourvu Tableau indiquant si chaque stage est pourvu.
 * \param refStage_Trie Tableau des références des stages triés.
 * \param dpt Tableau des départements associés aux stages.
 * \param stages Tableau des stages et de leurs candidats.
 * \param nbEtu Nombre total d'étudiants.
 * \param nbStage Nombre total de stages.
 * \param compteur Compteur des candidatures des étudiants.
 */
void save(float noteEtu[], int refStageFinalEtutiant[], int numDesEtutiants_Trie[], boolean stagePourvu[], int refStage_Trie[], int dpt[], int (*stages)[4], int nbEtu, int nbStage, int compteur[]);
