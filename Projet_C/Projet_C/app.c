#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "machine.h"



int main() {
    int mise = 10; // Mise par tour
    int solde = 0; // Solde de départ
    int ajout = 0; // Ajout au solde
    int retrait = 0; // Retret du solde 

    //srand(time(0)); // Initialisation de la graine pour la génération aléatoire



    printf("Bienvenue à la machine à sous ! Mise par tour : %d\n", mise);
    int rejouer = 1;
    while (rejouer) {
        //Menu
        enum Jouer {
            Jouer = 1,
            VoirSolde,
            AjouterSolde,
            RetirerSolde,
            Quitter
        };

        //Affichage des choix
        printf("Jouer[1], VoirSolde[2], AjouterSolde[3], RetirerSolde[4], Quitter[5] \n");

        //Demande à l'utilisateur le choix et récupère le choix 
        int choix;
        printf("Faites un choix : ");
        scanf_s("%d", &choix);

        //Switch permettant d'effectuer une partie du code en fonction du choix de l'utilisateur
        switch (choix) {
            case Jouer:
                if (solde < mise) {
                    printf("Solde insuffisant.Veuillez ajouter de l'argent.\n");
                }
                else {
                    solde -= mise;

                    //Appel de la fonction qui permet le jeu 
                    int gain = Play(mise);

                    solde += gain; // Mettre à jour le solde

                    //Affiche le gain sinon un message 
                    if (gain > 0) {
                        printf("Félicitations, vous avez gagné ! +%d crédits.\n", gain);
                    }
                    else {
                        printf("Dommage, vous avez perdu.\n");
                    }

                    //Appel de la fonction qui permet de savoir si oui ou non l'utilisateur veut rejouer'
                    Replay();

                }
                break;
            case VoirSolde:
                printf("Solde actuel : %d crédits\n", solde);
                break;
            case AjouterSolde:
                solde += AjoutArgent();

                break;
            case RetirerSolde:
                solde -= RetraitArgent(solde);
            case Quitter:
                Exit();
            }
    }


    printf("Merci d'avoir joué !\n");

    return 0;
}
