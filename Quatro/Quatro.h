#ifndef QUATRO_H
#define QUATRO_H
#include <QGridLayout>
#include <QPushButton>

#include <QMainWindow>
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class Quatro; }
QT_END_NAMESPACE

class Quatro : public QMainWindow
{
    Q_OBJECT

public:
    Quatro(QWidget *parent = nullptr);
    ~Quatro();
public :
    void createQuadra();
    bool coloneEmpty(int col);
    int caseEmpty(int col);

    bool winPlayer(int col, int ligne);
    bool verifAlignement(int ligne, int col, int dl, int dc, const QString& couleur);

//    void buttonClick();
public slots:
    void buttonClick();
private:
    QGridLayout *gridLayout;
    QMap<QPushButton*, QPair<int, int>> buttonCoord;
private:
    Ui::Quatro *ui;

    class Joueur {
    public:
        Joueur(const QString& nom, const QString& couleur) : nom(nom), couleur(couleur) {}

        QString getNom() const { return nom; }
        QString getCouleur() const { return couleur; }

    private:
        QString nom;
        QString couleur;
    };

    private:
        Joueur *joueur1;
        Joueur *joueur2;
        Joueur *joueurActif;

};
#endif // QUATRO_H
