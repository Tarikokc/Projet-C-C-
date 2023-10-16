#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "machine.h"



int main() {
    int mise = 10; // Mise par tour
    int solde = 0; // Solde de d�part
    int ajout = 0; // Ajout au solde
    int retrait = 0; // Retret du solde 

    //srand(time(0)); // Initialisation de la graine pour la g�n�ration al�atoire



    printf("Bienvenue � la machine � sous ! Mise par tour : %d\n", mise);
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

        //Demande � l'utilisateur le choix et r�cup�re le choix 
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

                    solde += gain; // Mettre � jour le solde

                    //Affiche le gain sinon un message 
                    if (gain > 0) {
                        printf("F�licitations, vous avez gagn� ! +%d cr�dits.\n", gain);
                    }
                    else {
                        printf("Dommage, vous avez perdu.\n");
                    }

                    //Appel de la fonction qui permet de savoir si oui ou non l'utilisateur veut rejouer'
                    Replay();

                }
                break;
            case VoirSolde:
                printf("Solde actuel : %d cr�dits\n", solde);
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


    printf("Merci d'avoir jou� !\n");

    return 0;
}
