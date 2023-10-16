#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "machine.h"


// Fonction pour générer un symbole aléatoire
char generateSymbol() {
    const char symbols[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
    return symbols[rand() % 6];
}
int Play(int mise) {
    char rouleaux[3]; // Trois rouleaux
    int gain = 0; // Gain 

    for (int i = 0; i < 3; ++i) {
        rouleaux[i] = generateSymbol();
    }

    // Afficher les symboles
    printf("Rouleaux : %c %c %c\n", rouleaux[0], rouleaux[1], rouleaux[2]);

    // Vérifier les gains (exemple simplifié)
    if (rouleaux[0] == rouleaux[1] && rouleaux[1] == rouleaux[2]) {
        gain = mise * 100;        
    }
    else if (rouleaux[0] == rouleaux[1] && rouleaux[1] != rouleaux[2]) {
        gain = mise * 5;
    }
    else if (rouleaux[0] != rouleaux[1] && rouleaux[1] == rouleaux[2]) {
        gain = mise * 5;

    }if (rouleaux[0] == "A" && rouleaux[1] == "B" && rouleaux[2] == "C") {
        gain = mise * 30;
    }
    return gain;

}


//Fonction permettant d'ajouter de l'argent
int AjoutArgent() {
    int ajout;
    printf("Montant de l'ajout : ");
    scanf_s("%d", &ajout);

    if (ajout > 0) {
        printf("Solde mis à jour : %d crédits\n", ajout);
        return ajout;

    }
    else {
        printf("Montant invalide.Veuillez ajouter une somme positive.");
        return 0;
    }

}

//Fonction permettant de retirer de l'argent 
int RetraitArgent(int solde) {
    int retrait;
    printf("Montant du retrait : ");
    scanf_s("%d", &retrait);
    if (retrait > 0 && retrait <= solde) {
        //solde -= retrait;
        printf("Solde mis à jour : %d crédits\n", retrait);
        return retrait;
    }
    else if(retrait > solde){
        printf("Montant invalide. Montant de retrait supérieur au solde.");
        return 0;
    }
    else {
        printf("Montant invalide.Veuillez ajouter une somme positive.");
        return 0;
        
    }

}

//Fonction permettant de rejouer
char Replay() {
    // Demander à l'utilisateur s'il souhaite continuer à jouer
    char choice;
    int decision = 1; 

    printf("Voulez-vous jouer à nouveau ? (O/N) : ");
    scanf_s(" %c", &choice);
    while (decision == 1) {
        if (choice != 'O' && choice != 'o') {
            decision = 0;
            return 0;

        }
        else {
            Play(10);
            return 1;
        }
    }
}

//Fonction permettant de quitter
void Exit() {
    printf(" A la prochaine ! ");
    exit(0);
}


