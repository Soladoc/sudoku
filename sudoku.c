/**
 * \page Programme pour faire une partie de sudoku
 *
 * \author Grandchamp Romain 
 * \version 1.0
 * \date 25 Novembre 2023
 * 
 * Ce programme charge une grille de jeu de sudoku à partir d'un fichier préexistant et permet au joueur d'entrer des valeurs jusqu'à ce que la grille soit complétée
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * \def taille
 * \brief Permet de donner la taille de la grille de sudoku
*/
#define taille 9 
/**
 * \typedef tGrille
 * \brief type tableau de [taille][taille] entiers 
 * 
 * Permet de créer facilement une grille de sudoku
*/
typedef int tGrille[taille][taille];

void chargerGrille(tGrille g);
void afficherGrille(tGrille g);
void saisir(int val);
bool possible(tGrille g, int ligne, int col, int val);
bool verif(tGrille g);

/**
 * \fn main()
 * \brief Permet de faire une partie de sudoku
 * 
 * Permet de charger un fichier qui contient une grille de sudoku, puis de remplir cette grille 
*/
int main(){
    tGrille grille;
    /**
     * \var tGrille grille
     * \brief Ce sera la variable qui servira de grille de jeu pour le programme
    */
    int numLigne; 
    /**
     * \var int numLigne
     * \brief Cette variable permettra d'identifier une ligne dans la grille de jeu
    */
    int numColonne;
    /**
     * \var int numColonne
     * \brief Cette variable permettra d'identifier une colonne dans la grille du jeu
    */
    int valeur;
    /**
     * \var int valeur
     * \brief Cette variable permettra de savoir quelle valeur entrer dans la grille
    */
    bool grilleRemplie;
    /**
     * \var bool grilleRemplie
     * \brief Cette variable permettra de savoir quand la grille est remplie grâce à la fonction verif(tGrille g)
    */
    chargerGrille(grille);
    grilleRemplie=false;
    numLigne=0;
    numColonne=0;
    while (grilleRemplie==false){
        afficherGrille(grille);
        printf("Choisissez votre case (entrez son numéro de ligne puis de colonne).");
        saisir(numLigne);
        saisir(numColonne);
        if ((grille[numLigne-1][numColonne-1]==1)||(grille[numLigne-1][numColonne-1]==2)||(grille[numLigne-1][numColonne-1]==3)||(grille[numLigne-1][numColonne-1]==4)||(grille[numLigne-1][numColonne-1]==5)||(grille[numLigne-1][numColonne-1]==6)||(grille[numLigne-1][numColonne-1]==7)||(grille[numLigne-1][numColonne-1]==8)||(grille[numLigne-1][numColonne-1]==9)){
            printf("Erreur, case non libre.\n");
        }
        else {
            printf("Que voulez-vous mettre dans cette case?\n");
            scanf("%d", &valeur);
            if (possible(grille, numLigne, numColonne, valeur)==true)
            {
                grille[numLigne-1][numColonne-1]=valeur;
            }
            else {
                printf("Valeur impossible.\n");
            }    
        }
        grilleRemplie=verif(grille);
    }
    printf("Félicitations! La grille est complétée!");
    return EXIT_SUCCESS;
}

/**
 * \fn chargerGrille(tGrille g)
 * \brief Affecte les bonnes valeurs dans la grille pour le début de la partie
 * \param g: la grille dans laquelle les valeurs seront affectées
 * 
 * Utilise un fichier donné par l'utilisateur pour récupérer les valeurs à entrer dans la grille
*/
void chargerGrille(tGrille g){
    char nomFichier[30];
    FILE * f;
    printf("Nom du fichier ? ");
    scanf("%s", nomFichier);
    f = fopen(nomFichier, "rb");
    if (f==NULL){
        printf("\n ERREUR sur le fichier %s\n", nomFichier);
    } 
    else {
        fread(g, sizeof(int), taille*taille, f);
    }
    fclose(f);
}
/**
 * \fn afficherGrille(tGrille g)
 * \brief Affiche toutes les valeurs de la grille
 * \param g: la grille qui sera affichée
*/
void afficherGrille(tGrille g){
    int compteur=1;
    int compteur2=1;
    printf("     1  2  3   4  5  6   7  8  9\n");
    printf("   +---------+---------+---------+\n");
    while (compteur<4)
    {
        printf("%d  |", compteur);
        while (compteur2<4) {
            if (g[compteur-1][compteur2-1]!=0) {
                printf(" %d ", g[compteur-1][compteur2-1]);
            }
            else {
                printf(" . ");
            }
            compteur2=compteur2+1;
        }
        printf("|");
        while (compteur2<7) {
            if (g[compteur-1][compteur2-1]!=0) {
                printf(" %d ", g[compteur-1][compteur2-1]);
            }
            else {
                printf(" . ");
            }
            compteur2=compteur2+1;
        }
        printf("|");
        while (compteur2<10) {
            if (g[compteur-1][compteur2-1]!=0) {
                printf(" %d ", g[compteur-1][compteur2-1]);
            }
            else {
                printf(" . ");
            }
            compteur2=compteur2+1;
        }
        printf("|\n");
        compteur2=1;
        compteur=compteur+1;
    }
    printf("   +---------+---------+---------+\n");
    while (compteur<7)
    {
        printf("%d  |", compteur);
        while (compteur2<4) {
            if (g[compteur-1][compteur2-1]!=0) {
                printf(" %d ", g[compteur-1][compteur2-1]);
            }
            else {
                printf(" . ");
            }
            compteur2=compteur2+1;
        }
        printf("|");
        while (compteur2<7) {
            if (g[compteur-1][compteur2-1]!=0) {
                printf(" %d ", g[compteur-1][compteur2-1]);
            }
            else {
                printf(" . ");
            }
            compteur2=compteur2+1;
        }
        printf("|");
        while (compteur2<10) {
            if (g[compteur-1][compteur2-1]!=0) {
                printf(" %d ", g[compteur-1][compteur2-1]);
            }
            else {
                printf(" . ");
            }
            compteur2=compteur2+1;
        }
        printf("|\n");
        compteur2=1;
        compteur=compteur+1;
    }
    printf("   +---------+---------+---------+\n");
    while (compteur<10)
    {
        printf("%d  |", compteur);
        while (compteur2<4) {
            if (g[compteur-1][compteur2-1]!=0) {
                printf(" %d ", g[compteur-1][compteur2-1]);
            }
            else {
                printf(" . ");
            }
            compteur2=compteur2+1;
        }
        printf("|");
        while (compteur2<7) {
            if (g[compteur-1][compteur2-1]!=0) {
                printf(" %d ", g[compteur-1][compteur2-1]);
            }
            else {
                printf(" . ");
            }
            compteur2=compteur2+1;
        }
        printf("|");
        while (compteur2<10) {
            if (g[compteur-1][compteur2-1]!=0) {
                printf(" %d ", g[compteur-1][compteur2-1]);
            }
            else {
                printf(" . ");
            }
            compteur2=compteur2+1;
        }
        printf("|\n");
        compteur2=1;
        compteur=compteur+1;
    }
    printf("   +---------+---------+---------+\n");
}
/**
 * \fn saisir(int val)
 * \brief Permet d'entrer une valeur dans une variable de type int
 * \param val: variable dans laquelle sera sauvegardée la valeur entrée par le joueur
 * 
 * Permet d'entrer une valeur dans une variable en vérifiant qu'il s'agit bien d'un entier entre 1 et 9
*/
void saisir(int val){
    char saisie[10];
    scanf("%s", saisie);
    while((val<1)||(val>9)){
        if (sscanf(saisie, "%d", &val)!=0){
            if ((val<1)||(val>9)) {
                printf("Valeur non acceptée. Entrez un chiffre entre 1 et 9.\n");
                scanf("%s", saisie);
            }
            else {
                printf("Valeur acceptée.\n");
            }
        }
        else {
            printf("Valeur non acceptée. Entrez un chiffre entre 1 et 9.\n");
            scanf("%s", saisie);
        }
    }
}
/**
 * \fn possible(tGrille g, int ligne, int col, int val)
 * \brief Vérifie si la valeur entrée n'est pas déjà présente dans le carré, la ligne et la colonne de la case
 * \param g: grille qui servira à garder les valeurs tout au long de la partie
 * \param ligne: permet d'identifier la ligne de la case dans laquelle la valeur veut être entrée
 * \param col: permet d'identifier la colonne de la case dans laquelle la valeur veut être entrée
 * \param val: la valeur qui doit être entrée
 * \return true si la valeur peut être entrée dans la grille, false sinon.
*/
bool possible(tGrille g, int ligne, int col, int val) {
    bool retour;
    retour=true;
    int compteur;
    int compteur2;
    if (ligne<4) {
        if (col<4) {
            for (compteur=0;compteur<3;compteur++){
                for (compteur2=0;compteur2<3;compteur2++){
                    if (g[compteur][compteur2]==val){
                        retour=false;
                    }
                }
            }
        }
        else if (col<7) {
            for (compteur=0;compteur<3;compteur++){
                for (compteur2=3;compteur2<6;compteur2++){
                    if (g[compteur][compteur2]==val){
                        retour=false;
                    }
                }
            }
        }
        else {
            for (compteur=0;compteur<3;compteur++){
                for (compteur2=6;compteur2<taille;compteur2++){
                    if (g[compteur][compteur2]==val){
                        retour=false;
                    }
                }
            }
        }
    }
    else if (ligne<7) {
        if (col<4) {
            for (compteur=3;compteur<6;compteur++){
                for (compteur2=0;compteur2<3;compteur2++){
                    if (g[compteur][compteur2]==val){
                        retour=false;
                    }
                }
            }
        }
        else if (col<7) {
            for (compteur=3;compteur<6;compteur++){
                for (compteur2=3;compteur2<6;compteur2++){
                    if (g[compteur][compteur2]==val){
                        retour=false;
                    }
                }
            }
        }
        else {
            for (compteur=3;compteur<6;compteur++){
                for (compteur2=6;compteur2<taille;compteur2++){
                    if (g[compteur][compteur2]==val){
                        retour=false;
                    }
                }
            }
        }
    }
    else {
        if (col<4) {
            for (compteur=6;compteur<taille;compteur++){
                for (compteur2=0;compteur2<3;compteur2++){
                    if (g[compteur][compteur2]==val){
                        retour=false;
                    }
                }
            }
        }
        else if (col<7) {
            for (compteur=6;compteur<taille;compteur++){
                for (compteur2=3;compteur2<6;compteur2++){
                    if (g[compteur][compteur2]==val){
                        retour=false;
                    }
                }
            }
        }
        else {
            for (compteur=6;compteur<taille;compteur++){
                for (compteur2=6;compteur2<taille;compteur2++){
                    if (g[compteur][compteur2]==val){
                        retour=false;
                    }
                }
            }
        }
    }
    for (compteur2=0;compteur2<taille;compteur2++){
        if (g[ligne-1][compteur2]==val){
            retour=false;
        }
    }
    for (compteur=0;compteur<taille;compteur++){
        if (g[compteur][col-1]==val){
            retour=false;
        }
    }
    return retour;
}
/**
 * \fn verif(tGrille g)
 * \brief Vérifie si la grille est complète pour savoir quand arrêter le jeu
 * \param g: la grille à vérifier
 * \return true si la grille est complète, false sinon
*/
bool verif(tGrille g){
    int compteur;
    int compteur2;
    bool rempli;
    compteur=0;
    compteur2=0;
    rempli=true;
    while ((compteur<taille)&&(rempli==true)){
        while ((compteur2<taille)&&(rempli==true)){
            if (g[compteur][compteur2]==0){
                rempli=false;
            }
            compteur2=compteur2+1;
        }
        compteur=compteur+1;
    }
    return rempli;
}