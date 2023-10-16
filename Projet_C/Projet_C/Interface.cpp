//#include <QApplication>
//#include <QMainWindow>
//#include <QPushButton>
//
//int main(int argc, char* argv[]) {
//    QApplication app(argc, argv);
//
//    // Créez une fenêtre principale
//    QMainWindow window;
//    window.setWindowTitle("Exemple d'Interface Qt");
//    window.setGeometry(100, 100, 400, 200); // Position (x, y) et taille (largeur, hauteur)
//
//    // Créez un bouton
//    QPushButton* button = new QPushButton("Cliquez-moi !", &window);
//
//    // Connectez un slot (fonction) au signal (événement) de clic du bouton
//    QObject::connect(button, &QPushButton::clicked, [&]() {
//        button->setText("Clic !");
//        });
//
//    // Affichez la fenêtre
//    window.show();
//
//    return app.exec();
//}
