//#include <QApplication>
//#include <QMainWindow>
//#include <QPushButton>
//
//int main(int argc, char* argv[]) {
//    QApplication app(argc, argv);
//
//    // Cr�ez une fen�tre principale
//    QMainWindow window;
//    window.setWindowTitle("Exemple d'Interface Qt");
//    window.setGeometry(100, 100, 400, 200); // Position (x, y) et taille (largeur, hauteur)
//
//    // Cr�ez un bouton
//    QPushButton* button = new QPushButton("Cliquez-moi !", &window);
//
//    // Connectez un slot (fonction) au signal (�v�nement) de clic du bouton
//    QObject::connect(button, &QPushButton::clicked, [&]() {
//        button->setText("Clic !");
//        });
//
//    // Affichez la fen�tre
//    window.show();
//
//    return app.exec();
//}
