#include "Quatro.h"
#include "./ui_Quatro.h"

#include <QGridLayout>
#include <QPushButton>
#include <QWidget>
#include <QObject>
#include <QPalette>
#include <QMessageBox>
Quatro::Quatro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Quatro)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: gray;");

    // Création des joueurs
    joueur1 = new Joueur("Joueur 1", "yellow");
    joueur2 = new Joueur("Joueur 2", "red");

    // Le joueur 1 commence, donc définissez-le comme joueur actif
    joueurActif = joueur1;
    createQuadra();


}

Quatro::~Quatro()
{
    delete ui;
}

//////////////////////////////////////////////////////////////////////////////// DEBUT DES FONCTIONS

//Créer une grille de puissance 4
void Quatro::createQuadra() {
    gridLayout = new QGridLayout;

    for (int ligne = 0; ligne < 6; ++ligne) {
        for (int col = 0; col < 7; ++col) {
            QPushButton *button = new QPushButton(QString("%1, %2").arg(ligne).arg(col));
            button->setFlat(true);
            button->setFixedSize(50, 50);  // Ajustez la taille à votre préférence
            button->setStyleSheet("border-radius: 25px; background-color: lightgray; color: white;");

            gridLayout->addWidget(button, ligne, col);

            buttonCoord[button] = QPair<int, int>(ligne, col);

            connect(button, &QPushButton::clicked, this, &Quatro::buttonClick);

        }
    }

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(gridLayout);


    setCentralWidget(centralWidget);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//Fonction permettant de tracker les cliques sur les boutons
void Quatro::buttonClick() {
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());

    // Récupérez la colonne du bouton qui a été cliqué (vous avez stocké les coordonnées dans le texte du bouton).
    QString buttonText = clickedButton->text();
    int col = buttonText.split(", ")[1].toInt();

    qDebug() << "Colonne cliquée : " << col;


    if (coloneEmpty(col)) {
        int lastCase = caseEmpty(col);
        if (lastCase != -1) {
            if (winPlayer(col, lastCase)) {
                // Affichez un message de victoire.
                QString message = joueurActif->getNom() + " a gagné!";
                QMessageBox::information(this, "Victoire", message);

                // Arrêtez le jeu (vous pouvez ajouter du code pour réinitialiser le jeu si nécessaire).
                return;
            }
            QString couleurJoueurActif = joueurActif->getCouleur();

            // Mettre à jour la couleur de la case vide la plus basse dans la colonne.
            QPushButton *emptyButton = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(lastCase, col)->widget());
//            emptyButton->setStyleSheet("border-radius: 25px; background-color: yellow; color: white;");
            emptyButton->setStyleSheet("border-radius: 25px; background-color: " + couleurJoueurActif + "; color: white;");

            qDebug() << "Joueur actif : " << joueurActif->getNom();

            if(joueurActif==joueur1){
                joueurActif = joueur2;
            }else{
                joueurActif = joueur1;
            }


        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////


bool Quatro::coloneEmpty(int col) {
    // Vérifiez si la colonne est pleine en vérifiant la ligne supérieure (ligne = 0).
    QPushButton *button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(0, col)->widget());
    // Si la couleur de fond du bouton supérieur est "lightgray", cela signifie que la colonne n'est pas pleine.
    return button->styleSheet().contains("background-color: lightgray");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int Quatro::caseEmpty(int col) {
    // Parcourez les lignes de la colonne de bas en haut.
    for (int ligne = 5; ligne >= 0; --ligne) {
        QPushButton *button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(ligne, col)->widget());

        // Si la couleur de fond du bouton est "lightgray", cela signifie que la case est vide.
        if (button->styleSheet().contains("background-color: lightgray")) {
            return ligne;
        }
    }
    // Si la colonne est pleine, retournez -1.
    return -1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
bool Quatro::winPlayer(int col, int ligne){
    QString couleur = joueurActif->getCouleur();

    // Vérification des alignements horizontaux
    if (verifAlignement(ligne, col, 0, 1, couleur)) {
        qDebug() << "Victoire horizontale";

        return true;
    }

    // Vérification des alignements verticaux
    if (verifAlignement(ligne, col, 1, 0, couleur)) {
        qDebug() << "Victoire verticale";

        return true;
    }

    //    // Vérification des alignements diagonaux descendants
    //    if (checkAlignment(ligne, col, 1, 1, couleur)) {
    //            return true;
    //    }

    //    // Vérification des alignements diagonaux ascendants
    //    if (checkAlignment(ligne, col, -1, 1, couleur)) {
    //            return true;
    //    }

    return false;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////

bool Quatro::verifAlignement(int ligne, int col, int dl, int dc, const QString& couleur){

    int jeton = 0;
    for (int step =-3;step <=3;++step){
        int l = ligne + step * dl;
        int c = col + step * dc;

        if(l >= 0 && l < 6 && c >= 0 && c < 7 ){
            QPushButton *button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(l, col)->widget());
            if(button->palette().window().color() == QColor(couleur)){
                jeton ++;
                if(jeton == 4){
                    qDebug() << "Alignement détecté";

                    return true;
                }else{
                    jeton = 0;
                }
            }
        }
    }

    return false;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////




