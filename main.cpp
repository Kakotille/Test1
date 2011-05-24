// main.cpp

#include <QApplication>
#include <QPushButton>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

#include <QProgressBar>
#include <QVBoxLayout>
#include <QSlider>
#include <QTabWidget>
#include <QLabel>

#include "mafenetre.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&translator);


//    MaFenetre fenetre;
//    fenetre.show();

    QWidget fenetre;

        // 1 : Créer le QTabWidget
        QTabWidget *onglets = new QTabWidget(&fenetre);
        onglets->setGeometry(30, 20, 240, 160);

        // 2 : Créer les pages, en utilisant un widget parent pour contenir chacune des pages
        QWidget *page1 = new QWidget;
        QWidget *page2 = new QWidget;
        QLabel *page3 = new QLabel; // Comme un QLabel est aussi un QWidget (il en hérite), on peut aussi s'en servir de page


        // 3 : Créer le contenu des pages de widgets

            // Page 1

            QLineEdit *lineEdit = new QLineEdit("Entrez votre nom");
            QPushButton *bouton1 = new QPushButton("Cliquez ici");
            QPushButton *bouton2 = new QPushButton("Ou là...");

            QVBoxLayout *vbox1 = new QVBoxLayout;
            vbox1->addWidget(lineEdit);
            vbox1->addWidget(bouton1);
            vbox1->addWidget(bouton2);

            page1->setLayout(vbox1);


            // Page 2

            QProgressBar *progress = new QProgressBar;
            progress->setValue(50);
            QSlider *slider = new QSlider(Qt::Horizontal);
            QPushButton *bouton3 = new QPushButton("Valider");

            QVBoxLayout *vbox2 = new QVBoxLayout;
            vbox2->addWidget(progress);
            vbox2->addWidget(slider);
            vbox2->addWidget(bouton3);

            page2->setLayout(vbox2);


            // Page 3 (je ne vais afficher qu'une image ici, pas besoin de layout)

            page3->setPixmap(QPixmap("smile.png"));
            page3->setAlignment(Qt::AlignCenter);


        // 4 : ajouter les onglets au QTabWidget, en indiquant la page qu'ils contiennent
        onglets->addTab(page1, "Coordonnées");
        onglets->addTab(page2, "Progression");
        onglets->addTab(page3, "Image");


        fenetre.show();







    return app.exec();
}
